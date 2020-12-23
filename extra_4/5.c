/*
 * UŽDUOTIS 5. Vartotojas įveda skaičių n, o po to – n realiųjų skaičių. Programa turi suskaičiuoti šių skaičių sumą ir vidurkį,
 * o taip pat mažiausią (minimumą) ir didžiausią (maksimumą) reikšmes.
*/

#include <stdio.h>

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

void myScan(int *num){

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

}

int main()
{

    printf("Įveskite natūralujį skaičių n, kuris nurodys sekos dydį.\n");
    int n, isScanned = 0;
    char ch;
    while (!isScanned)
    {
        if (scanf("%d%c", &n, &ch) && isValid(ch) && n > 0)
            isScanned = 1;
        else
        {
            printf("Įvestis buvo neteisinga. Įveskite natūralųjį skaičių n (n > 0) iš naujo.\n");
            isValid(ch);
        }
    }


    int num;
    myScan(&num);

    int i = 1, sum = num, max = num, min = num;
    do{
        myScan(&num);
        min = (min < num) ? min : num;
        max = (max > num) ? max : num;
        sum += num;
    } while(++i < n);

    float average = sum * 1.00 / n;
    printf("Įvestų skaičių suma yra %d, o vidurkis: %.2f.\n", sum, average);
    printf("Didžiausias skaičius yra %d, o mažiausias: %d.\n", max, min);

    return 0;
}