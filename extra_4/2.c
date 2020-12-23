/*
 * UŽDUOTIS 2. Vartotojas įveda tris sveikus skaičius (a, b, c). Programa turi atspausdinti visus teigiamus sveikus skaičius iš
 * intervalo (a; b], kurie dalijasi iš skaičiaus c su liekana 1.
 * 
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

    printf("Įveskite 3 sveikus skaičius: a, b ir c. Bus atspausdinti visi teigiami sveiki skaičiai iš"
           " intervalo (a; b], kurie dalijasi iš skaičiaus c su liekana 1.\n");
    
    int a, b, c, isScanned = 0;
    char ch;
    while (!isScanned){
        if (scanf("%d%d%d%c", &a, &b, &c, &ch) && isValid(ch) && (b > 0) && a < b)
            isScanned = 1;
        else{
            isValid(ch);
            printf("Įvestis buvo neteisinga. Įveskite iš naujo tik 3 sveikus skaičius; skaičius b privalo būti teigiamas ir didesnis už a.\n");
            }
    }
    printf("Skaičiai, esantys intervale (%d; %d] ir besidalijantys iš %d su liekana 1:\n", a, b, c);
    int count = 0;
    for(; a <= b; ++a){
        if (a % c == 1)
            printf("%d\t", a), ++count;
    }
    if (count == 0)
        printf("Nėra tokių skaičių.\n");
    else
        printf("\n");

    return 0;
}