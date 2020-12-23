#include "file.h"



void saveToFile(int *arr, int size, char *f_name){
    FILE *file = fopen(f_name, "ab");
    fprintf(file, "%d", size);
    fwrite(arr, sizeof(int), size, file);
    fclose(file);
    ++saveCount;
}

void loadFromFile(int **arr, int *new_size, char *f_name){
    FILE *file = fopen(f_name, "rb+");
    int size;
    fscanf(file, "%d", &size);
    *new_size = size;
    *arr = malloc(sizeof(int) * size);
    fread(*arr, sizeof(int), size, file);
    ++loadCount;
}