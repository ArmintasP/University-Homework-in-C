#include <stdio.h>
#include <stdlib.h>


void getLargestFile(int argc, char *argv[]){

    if (argc == 1)
    {
        printf("There are no file names used in command line!\n");
        return ;
    }

    long int max_size = -1, f_size;
    char ***pp_name;
    int ptr_size = 1;
    pp_name = (char ***)malloc(sizeof(char **) * ptr_size);
    if (pp_name == NULL)
    {
        printf("Program needs more memory to finish computing!\n");
        return;
    }
    for (int i = 1; i < argc; ++i)
    {
        FILE *file = fopen(*(argv + i), "rb");
        if (file == NULL)
        {
            printf("There is no file named %s!\n", *(argv + i));
            return ;
        }
        fseek(file, 0, SEEK_END);
        f_size = ftell(file);
        if (f_size == max_size)
        {
            pp_name = realloc(pp_name, ptr_size + 1);
            if (pp_name == NULL){
                printf("Program needs more memory to finish computing!\n");
                return ;
            }
            *(pp_name + ptr_size++) = argv + i;
        }

        if (f_size > max_size)
        {
            ptr_size = 1;
            pp_name = realloc(pp_name, ptr_size);
            if (pp_name == NULL)
            {
                printf("Program needs more memory to finish computing!\n");
                return;
            }
            max_size = f_size;
            *pp_name = argv + i;
        }
        fclose(file);
    }
    if (ptr_size == 1)
    {
        printf("Largest file is %s (%ld bytes).\n", **pp_name, max_size);
    }
    else
    {
        printf("Largest files (%ld bytes) are:\n", max_size);
        for (int i = 0; i < ptr_size; ++i)
        {
            printf("%s\n", **(pp_name + i));
        }
    }

    free(pp_name);
}

int main(int argc, char * argv[]){

    getLargestFile(argc, argv);

    return 0;
}