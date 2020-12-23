#include <stdio.h>
#include <stdlib.h>
#include <math.h>


unsigned char isPrime(unsigned number){
   if (number > 1){
      for(int i = 2; i <= sqrt(number)+0.0001; ++i)    
         if (!(number % i))         
            return 0;           
      return 1;
   } 
   return 0;    
}

unsigned char isIncluded(int *arr, int *size, int num){

    int i;
    for(i = 0; i < *size; ++i)
        if (arr[i] == num)
            return 1;
    *size += 1;
    arr = realloc(arr, sizeof(int) * (*size));
    arr[*size-1] = num;
    return 0;
}


int main(){

    int n = 0, num = 1;
    int *arr = malloc(sizeof(int) * 1);
    printf("Įveskite skaičių seką, jos pabaigą žymėkyte neigiamu skaičiu.\n");
    
    while(num > 0){
        while (!scanf("%d", &num)){
            printf("Dalis įvesties nebuvo skaičiai. Buvo nuskaityta seka iki parašytos klaidos. Įveskite likusią sekos dalį iš naujo, be klaidų:\n");
            while(getchar() != '\n')
                ;
        }
        ++n;
        arr = realloc(arr, sizeof(int) * n);
        arr[n - 1] = num;
    }

    int *reps = malloc(sizeof(int) * 1);
    int repsSize = 0;

    int i;
    printf("Priminiai skaičiai, buvę sekoje:\n");
    for(i = 0; i < n - 1; ++i)
        if (isPrime(arr[i])){
            ;
            if (isIncluded(reps, &repsSize, arr[i]))
                ;
            else{
                printf("%d\t", arr[i]);
            }
        }
    putchar('\n');
    return 0;
}