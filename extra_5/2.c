#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000
#define MY_MAX 6000

int main(){

    int arr[SIZE];

    printf("Įveskite tris skaičius: a, b ir c. Į masyvą "
            "bus įrašyta c atsitiktinių skaiči. Jos bus "
            "atspausdintos į ekraną intervale [a; b].\n"
            "Didžiausia galima b ir c reikšmė - 999. Intervale esančių skaičių kiekis negali būt didesnis už c.\n");
    int a, b, c;
    while(!scanf("%d%d%d", &a, &b, &c) || !(a <= b) || (b >= SIZE) || (c >= SIZE) || ((b-a) > c)){
        printf("Netinkama įvestis. Veskite iš naujo.\n");
        while(getchar() != '\n')
            ;
    }
    int i;
    srand(time(NULL));

    for(i = a; c > 0; --c, ++i)
        arr[i%SIZE] = rand() % MY_MAX;
    
    printf("Masyvas rėžiuose [%d; %d]:\n", a, b);
    for(i = a, c = 1; i <= b; ++i, ++c){
        printf("%d\t", arr[i]);
        if (c % 10 == 0 && c != 0)
            putchar('\n');
    }
    putchar('\n');

    return 0;
}