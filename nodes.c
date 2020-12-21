#include "nodes.h"

void createList(struct Node **pp_root){
        *pp_root = NULL;
}



void insertAtEnd(struct Node **pp_root, int val){
    if (*pp_root == NULL){
        *pp_root = (struct Node *)malloc(sizeof(struct Node *));
        (*pp_root)->value = val;
        (*pp_root)->p_previous = *pp_root;
        (*pp_root)->p_next = *pp_root;
        return ;
    }

    struct Node *p_new_element = (struct Node *)malloc(sizeof(struct Node *));
    p_new_element->value = val;

    p_new_element->p_next = *pp_root;
    p_new_element->p_previous = (*pp_root)->p_previous;

    ((*pp_root)->p_previous)->p_next = p_new_element;
    (*pp_root)->p_previous = p_new_element;
}



void insertAtStart(struct Node **pp_root, int val){
    insertAtEnd(pp_root, val);
    *pp_root = (*pp_root)->p_previous;
}



struct Node *findLargest(struct Node *p_root){
    if (p_root == NULL){
        return NULL;
    }
    int max = p_root->value;
    struct Node *p_largest = p_root;

    struct Node *p_temp = p_root->p_next;
    
    while (p_temp != p_root){
        if (p_temp->value > max){
            max = p_temp->value;
            p_largest = p_temp;
        }
        p_temp = p_temp->p_next;
    }
    return p_largest;
}



void deleteLargest(struct Node **pp_root){
    if (*pp_root == NULL){
        return ;
    }

    struct Node *p_target = findLargest(*pp_root);
    int largest_value = p_target->value;
    
    printf("\nDidžiausias reikšmė sąraše: %d. "
           "Ji iš sąrašo bus pašalinta.\n\n", largest_value);
    
    while (p_target->value == largest_value){
        if (*pp_root == p_target){
            *pp_root = (*pp_root)->p_next;
            if (*pp_root == (*pp_root)->p_next){
                *pp_root = NULL;
            }
        }

        (p_target->p_previous)->p_next = p_target->p_next;
        (p_target->p_next)->p_previous = p_target->p_previous;
        free(p_target);

        
        if (*pp_root == NULL){
            return ;
        }
        p_target = findLargest(*pp_root);
    }
}




void printListForwards(struct Node *p_root){
    printf("Sąrašas iš kairės į dešinę:\n");
    if (p_root == NULL){
        printf("Sąraše elementų nėra!\n");
        return ;
    }

    struct Node *p_current = p_root;

    while (p_current != p_root->p_previous){
        printf("%d ", p_current->value);
        p_current = p_current->p_next;
    }
    printf("%d\n", p_current->value);
}



void printListBackwards(struct Node *p_root){
    printf("Sąrašas iš dešinės į kairę:\n");
    if (p_root == NULL){
        printf("Sąraše elementų nėra!\n");
        return ;
    }

    struct Node *p_current = p_root->p_previous;

    while (p_current != p_root){
        printf("%d ", p_current->value);
        p_current = p_current->p_previous;
    }
    printf("%d\n", p_current->value);  
}



void destroyList(struct Node **pp_root){
    if (*pp_root == NULL){
        return ;
    }

    struct Node *p_temp;
    struct Node *p_current = (*pp_root)->p_next;

    while (*pp_root != p_current){
        p_temp = p_current->p_next;
        free(p_current);
        p_current = p_temp;
    }
    free(*pp_root);
    *pp_root = NULL;
}