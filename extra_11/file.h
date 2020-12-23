#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
int loadCount;
int saveCount;

void saveToFile(int *arr, int size, char *f_name);
void loadFromFile(int **arr, int * new_size, char *f_name);

#endif