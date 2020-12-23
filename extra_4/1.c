/*
 *  UŽDUOTIS 1. Vartotojas įveda tris sveikus skaičius (a, b, c). Programa turi atspausdinti kvadratinės lygties ax2+bx+c=0
 *  sprendinių skaičių ir, jei sprendinių yra, jų reikšmes.
*/

#include <stdio.h>
#include <math.h>

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


int main(){

    printf("Įveskite 3 sveikus skaičius: a, b ir c. Jie bus kvadratines lygties"
           " koeficientai (ax^2 + bx+ c = 0).\n");
    
    int a, b, c, isScanned = 0;
    char ch;
    while (!isScanned){
        if (scanf("%d%d%d%c", &a, &b, &c, &ch) && isValid(ch))
            isScanned = 1;
        else{
            isValid(ch);
            printf("Įvestis buvo neteisinga. Įveskite tik 3 sveikus skaičius.\n");
        }
    }

    int discriminant = b * b  -  4 * a * c;

    if (discriminant < 0 || (a == 0 && b == 0))
        printf("Lygtis neturi sprendinių.\n");
    else if (discriminant == 0){
        float x1 = (-b + sqrt(discriminant)) / (2 * a);
        
        printf("Lygties vienintelis sprendinys yra: %.2f.\n", x1);
    }
    else{
        float x1 = (-b + sqrt(discriminant)) / (2 * a);
        float x2 = (-b - sqrt(discriminant)) / (2 * a);

        printf("Lygties sprendiniai yra: %.2f ir %.2f.\n", x1, x2);
    }
    



    return 0;
}