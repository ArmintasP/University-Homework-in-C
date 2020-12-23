
/*
Parašykite programą, kuri paprašo duomenų faile „in.txt“ pateikti realų skaičių, ne mažesnį už 10 ir nedidesnį už 1000,
su ne daugiau kaip 3 skaičiais po kablelio. Laikykite, kad įvestyje trupmeninę dalį nuo sveikosios skiria kablelis. 
Programa turi atspausdinti įvesto skaičiaus ilgį. Jei duomenys pateikti nekorektiškai,
programa turi prašyti įvesti (tikėtina, kito) duomenų failo vardą, su galimai jau korektiškais duomenimis.

*/
#include <stdio.h>

#define LENGTH 80

char didOpenFile(FILE *, char []);
void ScanFile(FILE *db, char fname[], int *num, char *d_part);
char isDigit(char);

int main(){
    char fname[LENGTH] = "in.txt";
    FILE *db = fopen(fname, "r");
    if(db == NULL){
        printf("File %s was nout found. The program will be terminated. \n", fname);
        return 1;
    }
    int num;
    char d_part[10] = {0};
    ScanFile(db, fname, &num, d_part);

   
    int has_read = 0, count = 0;
    
    while(!has_read){
        int decimal_error = 0, whole_error = 0;
        count = 0;
        if(num > 10 && num < 100)
            count += 2;
        else if(num >= 100 && num < 1000)
            count += 3;
        else
            whole_error = 1;

        for(int i = 0; d_part[i] != '\0' && d_part[i] != '\r' && d_part[i] != '\n'; ++i){
            if (isDigit(d_part[i]) && i <= 2){
                count++;
            }
            else{
                decimal_error = 1;
                break;
            }
        }
        
        if(decimal_error == 0 && whole_error == 0)
            has_read = 1;
        else{
            printf("The number must be entered between 10 and 1000 with minimum 1 and maximum 3 digits after decimal point.\n"
                   "Plese enter another file name with correct data.\n");
            while(!didOpenFile(db, fname))
                ;
            ScanFile(db, fname, &num, d_part);
        }
        
    }
    printf("%d,%s has %d digits.\n", num, d_part, count);

    return 0;
}

char didOpenFile(FILE *db, char fname[]){
    fclose(db);
    scanf("%s", fname);
    db = fopen(fname, "r");

    if(db == NULL){
        printf("File %s was nout found. Please enter anothher file name.\n", fname); 
        return 0;
    }
    return 1;
}

void ScanFile(FILE *db, char fname[], int *num, char *d_part){
    
    while (fscanf(db, "%d,%s", num, d_part) != 2 && EOF){
        printf("Other symbols than numbers and comma were detected (or none) in %s Please enter another file name.\n", fname);
        fclose(db);
        while (!didOpenFile(db, fname))
            ;
    }
}

char isDigit(char ch){
    if (ch >= '0' && ch <= '9')
        return 1;
    return 0;
}
