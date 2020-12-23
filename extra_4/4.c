/*
 * UŽDUOTIS 4. Vartotojas įveda tris natūraliuosius skaičius (a, b, c). Programa turi atspausdinti du skaičius – šių trijų skaičių
 * didžiausią bendrąjį daliklį (DBD) bei mažiausiąjį bendrą kartotinį (MBK).
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

int findGCD(int a, int b){
    if (b == 0)
        return a;
    else   
        return findGCD(b, a % b);
}

int findLCM(int a, int b){
    return a * b / findGCD(a, b);
}


int main(){

    printf("Įveskite 3 natūraliuosius skaičius: a, b ir c. Bus atspausdintas šių skaičių MBK ir DBD.\n");
    
    int a, b, c, isScanned = 0;
    char ch;
    while (!isScanned){
        if (scanf("%d%d%d%c", &a, &b, &c, &ch) && isValid(ch)){
            if (!(a > 0 && b > 0 && c > 0)){
                printf("Galima įvesti tik natūraliuosius skaičius. Įveskite juos iš naujo.\n");
                continue;
                }
            isScanned = 1;
        }
        else{
            isValid(ch);      
            printf("Įvestis buvo neteisinga. Įveskite iš naujo tik 3 natūraliuosius skaičius.\n");     
        }
    }

    int gcd = findGCD(findGCD(a, b), c), lcm = findLCM(findLCM(a, b), c);

    printf("DBD = %d, MBK = %d\n", gcd, lcm);

    return 0;
}