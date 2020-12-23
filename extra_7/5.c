#include <stdio.h>


long getFileSize(char *filename){

    FILE *db = fopen(filename, "rb");
    if (db == NULL){
        printf("Error! Could not find/open the file.\n");
        return -1;
    }
    if (fseek(db, 0, SEEK_END) != 0)
        return -1;

    if (ftell(db) < 0)
        return -1;
    
    return ftell(db);
    
}

int main(){

    char *fname = "testukas.txt";
    printf("%ld\n", getFileSize(fname));

    return 0;
}