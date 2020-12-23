/*
 *  UŽDUOTIS 6. Vartotojas įveda teigiamų skaičių seką, kurios pabaigą žymi pirma įvesta neteigiama reikšmė. Programa turi
 *  rasti, kuris skaičius tarp įvestųjų turi daugiausiai skaitmenų
*/

#include <stdio.h>

#define SIZE 1000

int isValid(char ch)
{
    if (ch == '\n')
        return 1;
    else if (ch == ' ')
        while (ch = getchar())
        {
            if (ch == ' ')
                ;
            else if (ch == '\n')
                return 1;
            else
            {
                while (getchar() != '\n')
                    ;
                return 0;
            }
        }
    while (getchar() != '\n')
        ;
    return 0;
}

int myScan(int *num){

    int isScanned = 0;
    char ch;

    while (!isScanned){
        if (scanf("%d", num))
            isScanned = 1;
        else{
            ch = getchar();
            printf("Įvestis buvo neteisinga. Simbolis \'%c\' nėra galima. Įveskite tik likusius realųjį(iuosius) skaičių(ius) nuo to simbolio.\n", ch);
            isValid(ch);
        }
    }
    return 1;

}

int numeralCount(int num){
    int i = 1;
    for(; num > 0; num /= 10)
        ++i;
    return i;
}

int main(){
    int nums[SIZE], num;
    printf("Įveskite teigiamų skaičių seką. Neigiamas skaičius žymės jos pabaigą.\n");
    myScan(&num);

    if (num < 0)
        printf("Seka tuščia.");
    else{
        nums[0] = num;
        int count = numeralCount(num), i = 0;

        while (myScan(&num) && num > 0){

            if (numeralCount(num) == count)
                nums[++i] = num;
                
            else if (numeralCount(num) > count){
                i = 0;
                nums[i] = num;
                count = numeralCount(num);
            }
        }
        printf("Daugiausiai skaitmenų turintys skaičiai:\n");
        for (; i >= 0; --i)
            printf("%d\t", nums[i]);
        printf("\n");
    }

    
    

    return 0;
}