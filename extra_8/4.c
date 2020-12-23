#include <stdio.h>
#include <stdlib.h>

void splitData(int *array, int size, int split_pos, int **array1, int **array2){
    if (size == 0){
        printf("Size can't be zero!\n");
        return;
    }
    if (*array1 != NULL || *array2 != NULL)
    {
        printf("New arrays/pointers should be NULL!\n");
        return;
    }

    *array1 = malloc(sizeof(array[0]) * split_pos);
    for (int i = 0; i <= split_pos; ++i){
        *((*array1)+i) = array[i];
    }
    *array2 = malloc(sizeof(array[0]) * (size - split_pos));
    for (int i = split_pos; i < size; ++i){
        *((*array2) + i) = array[i];
    }
}


int main(){
    int ch_size = 5, split_point = 2;
    int ch_arr[5] = {1, 2, 3, 4, 5};
    int *p1 = NULL, *p2 = NULL;
    splitData(ch_arr, ch_size, split_point, &p1, &p2);

    for (int i = 0; i <= split_point; ++i)
        printf("%d\n", *(p1+i));

    printf("Second array:\n");
    for (int i = split_point + 1; i < ch_size; ++i)
        printf("%d\n", *(p2 + i));
    return 0;
}