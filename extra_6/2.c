/*
Užduotis 2.
Parašykite programą, kuri paprašo įvesti tris skaičius vienoje eilutėje, be tarpų, teigiamus arba neigiamus,
kuriuos vieną nuo kito skiria kabliataškiai, ir raskite vidurinį (pagal reikšmę) skaičių. 
Jei įvestis korektiška, rezultatą (reikšmę) programa turi atspausdinti rezultatų faile,
kurio vardas įvedamas ir privalo baigtis simboliais „.txt“ (jei taip nėra, prašoma failo vardą įvesti iš naujo).
*/

#include <stdio.h>
int length(char *str){
    int i = 0;
    for (i = 0; str[i] != '\0'; ++i)
        ;
    return i;
}

int main(){

    printf("Enter 3 numbers in this format: x;y;z\n{x, y, z} are whole numbers.\n");
    int x, y, z;
    if (scanf("%d;%d;%d", &x, &y, &z) != 3){
        printf("Input is not correct. Program will be terminated!\n");
        return 1;
    }
    printf("Input was correct, please enter result file name in which not the largest & not the smallest number will be saved.\n");
    int is_scanned = 0;
    char fname[100];
    while(!is_scanned){
        scanf("%s", fname);
        if (length(fname) <= 4)
            printf("Result file must be a .txt file. Enter its name again.\n"); 
        else if (fname[length(fname)-1] == 't' && fname[length(fname)-2] == 'x' && fname[length(fname)-3] == 't' && fname[length(fname)-4] == '.')
            is_scanned = 1;
        else
            printf("Result file must be a .txt file. Enter its name again.\n");   
    }

    FILE *db = fopen(fname, "w");
    
    int max = x, min = x;
    max = (y > max) ? y : max;
    max = (z > max) ? z : max;
    min = (y < min) ? y : min;
    min = (z < min) ? z : min;

    if(x != min && x != max)
        fprintf(db, "%d", x);
    else if(y != min && y != max)
        fprintf(db, "%d", y);
    else
        fprintf(db, "%d", z);
    fclose(db);

    return 0;
}