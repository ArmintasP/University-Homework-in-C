#include <stdio.h>
#define SIZE 10
int main(){

    // a, b, c veiksmai.
    int arr[SIZE] = {0};
    int i;
    printf("Masyvo elementai:\n");
    for(i = 0; i < SIZE; ++i)
        printf("%d\t", arr[i]);
    putchar('\n');

    arr[0] = 1, arr[4-1] = 2, arr[10-1] = 3;

    // d
    for(i = 3-1; i < SIZE - 1; ++i)
        arr[i] = arr[i+1];
    // e
    for(i = SIZE-1; i >= 7 - 1; --i)
        arr[i] = arr[i-1];
    arr[7-1] = 4;
    // f
    printf("Redaguoto masyvo elementai:\n");
    for(i = 0; i < SIZE; ++i)
        printf("%d\t", arr[i]);
    putchar('\n');

    // g
    printf("Įveskite du skaičius formatu (x, y). X - masyvo indeksas, "
           "y - reikšmė suteikiamam elementui.\n");
    int x, y;
    while(!scanf("(%d, %d)", &x, &y) || x > 10 || x < 0){
        printf("Netinkamas skaičių formatas. Maksimali neneigiamo x reikšmė - 10.\n");
        while(getchar() != '\n')
            ;
    }
    // h
    arr[x] = y;
    int del_id;
    printf("Įveskite masyvo elemento indeksą rėžiuose [0, %d), kurį norite ištrinti.\n", SIZE);
        while(!scanf("%d", &del_id) || del_id > 10 || del_id < 0){
        printf("Netinkama įvestis. Maksimali neneigiamo x reikšmė - 10. Minimali - 0.\n");
        while(getchar() != '\n')
            ;
    }
    for(i = del_id; i < SIZE - 1; ++i)
        arr[i] = arr[i+1];
    // i 
    x = 0;
     while(getchar() != '\n')
        ;
    printf("Įveskite du skaičius formatu (x, y). X - masyvo indeksas,  "
           "y - reikšmė suteikiamam elementui. Į x vietą bus įterptas naujas elementas.\n");
    while(!scanf("(%d, %d)", &x, &y) || x > 10 || x < 0){
        printf("Netinkamas skaičių formatas. Maksimali neneigiamo x reikšmė - 10.\n");
        while(getchar() != '\n')
            ;
    }

    for(i = SIZE-1; i >= x - 1; --i)
        arr[i] = arr[i-1];
    arr[x] = y;

    printf("Naujausio masyvo elementai:\n");
    for(i = 0; i < SIZE; ++i)
        printf("%d\t", arr[i]);
    putchar('\n');

    return 0;
}