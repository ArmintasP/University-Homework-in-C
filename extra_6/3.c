/*
Parašykite programą, kuri patikrina, ar eilutėje yra korektiškai įvesta data, formatu YYYY-MM-DD. 
Jei taip, programa turi atspausdinti, kokia tai savaitės diena. Savaitės dienų pavadinimai turi
būti skaitomi iš tekstinio failo „week.txt“, kuriame yra iš anksto įrašytos septynios eilutės su atitinkamų dienų pavadinimais. 
Pakeitus pavadinimus faile (pvz. iš lietuvių kalbos į anglų), programoje spausdinamos reikšmės irgi turi pasikeisti (automatiškai).

*/


#include <stdio.h>

#define LENGTH 50

int isCorrectDate(int year, int month, int day){
    int bad_day = 0;

    if (month == 2 && ((year % 4 == 0 && (day > 29 || day < 1))))
        bad_day = 1;
    else if(month == 2 && (day > 28 || day < 1) && !(year % 4 == 0))
        bad_day = 1;
    else if (month % 2 == 1 && month <= 7 && (day > 31 || day < 1))
        bad_day = 1;
    else if(month % 2 == 0 && month >= 8 && (day > 31 || day < 1))
        bad_day = 1;
    else if (month % 2 == 0 && month <= 6 && (day > 30 || day < 1))
        bad_day = 1;
    else if(month % 2 == 1 && month >= 9 && (day > 30 || day < 1))
        bad_day = 1;
    
    return bad_day;
}

int main(){
    int year, month, day;
    printf("Enter date in format YYYY-MM-DD.\n");
    if (scanf("%d-%d-%d", &year, &month, &day) != 3){
        printf("Input is not correct. Program will be terminated!\n");
        return 1;
    }

    if (month <= 0 || month > 12){
        printf("Month number was entered incorrectly. Program will be terminated.\n");
        return 2;
    }

    if (!isCorrectDate){
        printf("Day number was entered incorrectly.\n");
        return 3;
    } 

    int week_day =  (day += month < 3 ? year-- : year - 2, 23*month/9 + day + 4 + year/4- year/100 + year/400) % 7;
    
    FILE *names = fopen("week.txt", "r");
    if (names == NULL){
        printf("Error detected while opening the file.\n");
        return 4;
    }
    char dayname[LENGTH];
    for (int i = 0; i <= week_day; ++i)
        fscanf(names, "%s", dayname);
    printf("Name of the given date: %s\n", dayname);
    return 0;
}