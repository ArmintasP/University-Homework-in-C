#include <stdio.h>
#include <stdlib.h>

int main(){
    int s, n;
    printf("Įveskite du skaičius, s ir n. N privalo būti teigiamas:\n");
    while(!scanf("%d%d", &s, &n) || n < 1){
        printf("Netinkama įvestis. Veskite iš naujo\n");
        while(getchar() != '\n')
            ;
    }
    // Atsikratom perteklinių įvesčių.        
    while(getchar() != '\n')
        ;    
    int *x = malloc(sizeof(int) * n), i;
    for(i = 0; i < n; ++i){
        int y;
        while(!scanf("%d", &y))
            getchar() != '\n';
        x[i] = y;
    }
    int j, c = 1;
    printf("Elementų poros, kurias sudauginus, gaunama %d:\n", s);
    for(i = 0; i < n - 1; ++i)
        for (j = i + 1; j < n; ++j)
            if (x[j] * x[i] == s){
                printf("%d ir %d\t", x[i], x[j]);
                if (c % 5 == 0)
                    printf("\n");
                ++c;
            }
    putchar('\n');

    return 0;
}