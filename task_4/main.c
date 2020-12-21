/*
 * Darbo autorius - Armintas Pakenis, 4 grupė. 23 užduotis.
 * Programa sudaro dvipusį ciklinį sąrašą. Po to išmeta
 * iš sąrašo didžiausią elementą.
 */


#include "nodes.h"

#define BACKWARDS 'p'


int main(){

    struct Node *p_list;
    createList(&p_list);


    char mode;
    printf("Įrašykite \'%c\', jei norėsite vesti reikšmes į priekį. "
           "Bet kokį kitą simbolį, jei norėsite vesti elementą į galą.\n", BACKWARDS);
    scanf("%c", &mode);

    printf("Įrašykite sąrašo elementus. Norėdami užbaigti seką, parašykite \'0\'\n");
    int num;
    while (scanf("%d", &num) && num != 0){
        if (mode == BACKWARDS){
            insertAtStart(&p_list, num);
        }
        else{
            insertAtEnd(&p_list, num);
        }
    }



    printListForwards(p_list);
    printListBackwards(p_list);


    deleteLargest(&p_list);
    deleteLargest(&p_list);
    deleteLargest(&p_list);
    insertAtStart(&p_list, 5);

    printListForwards(p_list);
    printListBackwards(p_list);

    destroyList(&p_list);

    return 0;
}