#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *createArray(int size, int low, int high){
    int *p_array = (int *) malloc(sizeof(int) * size);
    if (p_array == NULL){
        return NULL;
    }

    if (low > high){
        int temp = low;
        low = high;
        high = temp;
    }
        
    srand(time(NULL));
    for (int i = 0; i < size; ++i){
        *(p_array + i) = rand() % (high - low + 1) + low;
        }
    
    return p_array;
}


int main(){
    int size = 10;
    int * p_list = createArray(size, 4, 8);

    for (int i = 0; i < size; ++i){
        printf("%d\n", *(p_list + i));
    }

    free(p_list);

    return 0;
}