/* 
 * Armintas Pakenis, 4 grupė, 13 užduotis.
 * Parašyti funkciją, kuri iš duoto teksto išmeta žodžius, kurių vidurinis simbolis
 * yra skaitmuo (tarpų skaičius turi likti nepakitęs). 
 * 
 * Pastaba: pasirinkta nuskaityti 255 simbolius ir likusius eilutėje ignoruoti, jei tokių yra.
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 256
#define SPACE 32

void filterWords(char[], char[]);
void fixWord(char *, char *, int *, int , int);
char isDigit(char);
int findLength(char []);
void fixWord2(char *, char *, int *, int, int);

int main(int argc, char *argv[]){

    if(argc != 3){
        printf("Nenurodyti failų pavadinimai. Programa terminuojama.\n");
        return 1;
    }
    FILE *input = fopen(argv[1], "r");
    if (input == NULL){
        printf("Nurodyto duomenų failo nerasta. Programa terminuojama.\n");
        return 2;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL){
        printf("Rezultato failo tokiu pavadinimu negalima sukurti. Programa terminuojama.\n");
        return 3;
    }


    char *i_buff = malloc(sizeof(char) * SIZE);
    printf("%ld\n", sizeof(i_buff));
    char *o_buff = malloc(sizeof(char) * SIZE);
    
    while (fgets(i_buff, SIZE, input)){
        filterWords(i_buff, o_buff);
        fputs(o_buff, output);
    }

    printf("Programa sutvarkė tekstą ir pašalino iš vidury esančių žodžių skaitmenį, jei tokių žodžių buvo.\n");

    free(i_buff);
    free(o_buff);
    fclose(input);
    fclose(output);

    return 0;
}

void filterWords(char *i_buff, char *o_buff){
    
    int i = 0, j = 0, was_word = 0, pos_0 = 0, pos_1 = 0, length = findLength(i_buff);
    
    for (i = 0; i <= length; ++i){
        if(i_buff[i] == SPACE || i_buff[i] == '\r' || i_buff[i] == '\n' || i_buff[i] == '\0'){ 
            if(was_word){  
                fixWord2(i_buff, o_buff, &j, pos_0, pos_1);   
                was_word = 0;
            }
            o_buff[j++] = i_buff[i];
        }
        else if(was_word)
                pos_1 = i;
        else{
                pos_0 = i;
                pos_1 = pos_0;
                was_word = 1;
        }
    }
           
}

void fixWord(char *i_buff, char *o_buff, int *j, int pos_0, int pos_1){

     /* Surandamas žodžio vidurys */
    int middle = -1, z, is_digit = 0;
    if ((pos_1 - pos_0) % 2 == 0){
        middle = pos_0 + ((pos_1 - pos_0) / 2);
        is_digit = isDigit(i_buff[middle]);
    }

    /* Neprintint vidurinio skaitmens, jei vidurinis skaičius - skaitmuo */
    for (z = pos_0; z <= pos_1; ++z)
        if (z != middle  || !is_digit)
            o_buff[(*j)++] = i_buff[z];
}

    /* Ketvirtai uždučiai */
void fixWord2(char *i_buff, char *o_buff, int *j, int pos_0, int pos_1){
    int z;
    for(z = pos_1; z >= pos_0; --z)
        o_buff[(*j)++] = i_buff[z];
}

char isDigit(char ch){
    if (ch >= '0' && ch <= '9')
        return 1;
    return 0;
}

int findLength(char str[]){
    int i;
    for (i = 0; str[i] != '\0'; ++i)
        ;
    return i;
}