/*
 *  UŽDUOTIS 3. Vartotojas įveda tris neneigiamus sveikuosius skaičius (a, b, c). Programa turi atspausdinti c-ąjį skaičių f_c, kur
 *  f_c=f_(c-1)+f_(c-2), o f_0 = a ir f_1 = b. Jei a=0 ir b=1, f_c yra c-asis garsiosios Fibonačio sekos skaičius.  s
 *
 */
#include <stdio.h>

int isValid(char ch){
    if (ch == '\n')
        return 1;
    else if (ch == ' ')
        while (ch = getchar()){
            if (ch == ' ')
                ;
            else if (ch == '\n')
                return 1;
            else{
                while (getchar() != '\n')
                    ;
                return 0;
                }
        }
    while (getchar() != '\n')
        ;
    return 0;
}

int calcFibo(int a, int b, int c){
    if (c == 0) return a;
    if (c == 1) return b;

    return calcFibo(a, b, c - 1) + calcFibo(a, b, c - 2);

}
int main(){

    printf("Įveskite 3 neneigiamus skaičius: a, b ir c. Bus atspausdintas c-asis skaičius f_c, kur f_c=f_(c-1)+f_(c-2), o f_0 = a ir f_1 = b.\n");
    
    int a, b, c, isScanned = 0;
    char ch = 0;
    while (!isScanned){
        if (scanf("%d%d%d", &a, &b, &c) && isValid(ch)){
            if (!(a >= 0 && b >= 0 && c >= 0)){
                printf("Galima įvesti tik neneigiamus skaičius. Įveskite juos iš naujo.\n");
                continue;
                }
            isScanned = 1;
        }
        else{
            isValid(ch);
            printf("Įvestis buvo neteisinga. Įveskite iš naujo tik 3 neneigiaamus skaičius.\n");
        }
    }

    printf("f_%d = %d\n", c, calcFibo(a, b, c));
    return 0;
}