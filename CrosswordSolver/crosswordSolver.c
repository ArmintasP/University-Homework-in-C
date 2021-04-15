#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STR_LENGTH 128
#define FAILURE 7
#define CHECK_FOR_ERROR(condition, message, error_num, ...)                         \
            if(condition){                                                          \
                printf(message "\nProgram will be terminated.\n", ##__VA_ARGS__);   \
                exit(error_num);                                                    \
            }                                                                       \



struct Cell{
    int row;
    int col;
    int direction;
    int state;
    int length;
};

typedef struct Cell Cell;
void openFiles(FILE **wordlist, FILE **matrix);
char isEmptyFile(FILE *file);
void checkForWhitespaces(char *string, int size);
char **getWords(FILE *file, int *count);
void validateCrossword(char **lines, int ver_count, int *hor_count, int *zero_count, Cell **cells, int *c_size);
void validateWords(char **words, int *size);
char **copyArray(char **array, int heigth, int width);
void freeArray(char **ptr, int heigth);
char areCellsFull(Cell *cells, int cell_size);
void printSolution(char **crossword, int heigth, FILE *result, char state);
int fillLine(char **crossword, Cell cell, char *word, char direction, int zero_c);
void findSolutions(Cell *cells, int cell_size, char **crossword, int ver_c, int hor_c, char **words, int words_c, int words_id, int free_spaces, FILE *result);
char *pop(char **array, int *size, int id);

// Count of solutions will be accessible by all functions.
int solutions = 0;

// Keywords used in a program.
enum {FIND_SINGLE_SOLUTION, FIND_MULTIPLE_SOLUTIONS};
enum {VERTICAL, HORIZONTAL, RIGHT, DOWN, FULL, NOT_FULL};



int main(){

    FILE *wordlist_f, *matrix_f;
    openFiles(&wordlist_f, &matrix_f);
    

    int word_count;
    char **words = getWords(wordlist_f, &word_count);


    int ver_count, hor_count, corridor_count;
    char **crossword = getWords(matrix_f, &ver_count);

    // Checks if matrix is only of '1's or '0's.
    Cell *cells;
    int cells_size;

    validateCrossword(crossword, ver_count, &hor_count, &corridor_count, &cells, &cells_size);
    if (corridor_count == -1){
        printf("No solutions were found to the given crossword.\n");
    }
    
    
    // Checks for digits in words, duplicates and shorter than 2 letter words.
    validateWords(words, &word_count);


    FILE *result = fopen("result.txt", "w");
    CHECK_FOR_ERROR((result == NULL), "Error creating file: result.txt.", 1);

    printf("Calculating...\n");
    findSolutions(cells, cells_size, crossword, ver_count, hor_count, words, word_count, 0, corridor_count, result);


    if (solutions == 0){
        printf("No solutions were found to the given crossword.\n");
    }
    else{
        printf("Solutions (%d) were saved to a file called result.txt.\n", solutions);
    }

    freeArray(words, word_count);
    freeArray(crossword, ver_count);
    fclose(result);
    fclose(wordlist_f);
    fclose(matrix_f);

    return 0;
}



void findSolutions(Cell *cells, int cell_size, char **crossword, int ver_c, int hor_c, char **words, int words_c, int words_id, int free_spaces, FILE *result){

    if (!areCellsFull(cells, cell_size) && words_c > words_id){
        char *string = words[words_id];
        int str_len = strlen(string);
        // Vertical check.
        for (int i = 0; i < cell_size; ++i){
            if ((cells[i].length != str_len) || (cells[i].direction == HORIZONTAL) || (cells[i].state == FULL)){

                continue;
            }
            else{
                /* Making an extra copy of current crossword matrix,
                 * in case we the word won't fit in the crossword.
                 */
                char **temp_crossword = copyArray(crossword, ver_c, hor_c);

                int remaining_spaces = fillLine(temp_crossword, cells[i], string, VERTICAL, free_spaces);

                if (temp_crossword[0][0] != FAILURE){
                    cells[i].state = FULL;
                    findSolutions(cells, cell_size, temp_crossword, ver_c, hor_c, words, words_c, words_id + 1, remaining_spaces, result);
                    cells[i].state = NOT_FULL;
                }
                freeArray(temp_crossword, ver_c);
            }
        }
        // Horizontal check.
        for (int i = 0; i < cell_size; ++i){
            if (cells[i].length != str_len || cells[i].direction == VERTICAL || cells[i].state == FULL){
                
                continue;
            }
            else{
                /* Making an extra copy of current crossword matrix,
                 * in case we the word won't fit in the crossword.
                 */
                char **temp_crossword = copyArray(crossword, ver_c, hor_c);

                int remaining_spaces = fillLine(temp_crossword, cells[i], string, HORIZONTAL, free_spaces);

                if (temp_crossword[0][0] != FAILURE){
                    cells[i].state = FULL;
                    findSolutions(cells, cell_size, temp_crossword, ver_c, hor_c, words, words_c, words_id + 1, remaining_spaces, result);
                    cells[i].state = NOT_FULL;
                }
                freeArray(temp_crossword, ver_c);
            }
        }
        /* 
         * If the string cannot fit neither horizontally or
         * vertically for the given crossword, then the following
         * string from wordlist is sent to findSolutions().
         */
        findSolutions(cells, cell_size, crossword, ver_c, hor_c, words, words_c, words_id + 1, free_spaces, result);
    }
    else if (areCellsFull(cells, cell_size)){
        ++solutions;
        /* FIND_SINGLE_SOLUTION can be changed to find multiple 
         * solutions if needed (FIND_MULTIPLE_SOLUTIONS).
         */
        printSolution(crossword, ver_c, result, FIND_SINGLE_SOLUTION);
    }
}

char areCellsFull(Cell *cells, int cell_size){
    for (int i = 0; i < cell_size; ++i){
        if (cells[i].state == NOT_FULL){
            return 0;
        }
    }
    return 1;
}


int fillLine(char **crossword, Cell cell, char *word, char direction, int zero_c){
    int zeros = zero_c;
    int length = cell.length;
    int i = 0, j = 0;


    while(i < length && j < length){
        char sym = crossword[cell.row + i][cell.col + j];

        /* i + j because program checks either vertically or horizontally, not both. */
        if (sym == '0' || sym == word[i + j]){
            crossword[cell.row + i][cell.col + j] = word[i + j];
            if (sym == '0'){
                --zeros;
            }
        }
        else{
            /* Every crossword has [0][0]th element, which will get value of FAILURE if a word cannot fit in. */
            crossword[0][0] = FAILURE;
            return zero_c;
        }


        if (direction == VERTICAL){
            ++i;
        }
        else if(direction == HORIZONTAL){
            ++j;
        }
        else{
            CHECK_FOR_ERROR(1, "Function's fillLine paramater 'direction' was entered incorrectly.", 8);
        }

    }

    return zeros;
}



void printSolution(char **crossword, int heigth, FILE *result, char state){
    for (int i = 0; i < heigth; ++i){
        fprintf(result, "%s\n", crossword[i]);
    }

    if (state == FIND_SINGLE_SOLUTION){
        // There is no reason for program to continue other doing other functions, as a solution was already found.
        fclose(result);
        printf("A solution was found and saved to a file 'result.txt', program will be closed!\n");
        exit(0);
    }
    fputc('\n', result);
}


char **copyArray(char **array, int heigth, int width){
    char **newarr = malloc(sizeof(char *) * heigth);
    CHECK_FOR_ERROR((newarr == NULL), "Couldn't allocate memory.", 4);

    for (int i = 0; i < heigth; ++i){
        /* Adding extra one, so '\0' could be copied as well */
        int size = sizeof(char) * width + 1;
        newarr[i] = malloc(size);
        CHECK_FOR_ERROR((newarr[i] == NULL), "Couldn't allocate memory.", 4);

        memcpy(newarr[i], array[i], size);
    }
    return newarr;
}

void freeArray(char **ptr, int heigth){
    for (int i = 0; i < heigth; ++i){
        free(ptr[i]);
    }
    free(ptr);
}


void validateCrossword(char **lines, int ver_count, int *hor_count, int *zero_count, Cell **cells, int *c_size){
    *zero_count = 0;
    *hor_count = strlen(lines[0]);
   


    for (int i = 0; i < ver_count; ++i){

        int length = strlen(lines[i]);
        CHECK_FOR_ERROR((length != *hor_count),
                        "Each line should have the same amount of symbols.", 6);

        for(int j = 0; j < length; ++j){
            CHECK_FOR_ERROR((lines[i][j] != '0' && lines[i][j] != '1'),
                        "Symbols in matrix can only be either '1' or '0'.", 7);
            if (lines[i][j] == '0'){
                ++*zero_count;
            }
        }
    }
    int cells_size = 50;
    int cell_id = 0;
    *cells = malloc(sizeof(Cell) * cells_size);

    // Horizontal cell assignment.
    for (int i = 0; i < ver_count; ++i){
        if (cell_id >= cells_size){
            cells_size += 50;
            *cells = realloc(*cells, sizeof(Cell) * cells_size);
        }

        for (int j = 0; j < *hor_count - 1; ++j){
            if (lines[i][j] == '0' && lines[i][j + 1] == '0'){
                (*cells)[cell_id].row = i;
                (*cells)[cell_id].col = j;
                (*cells)[cell_id].direction = HORIZONTAL;
                int size = 2;
                for (; j + size < *hor_count && (lines[i][j + size] == '0'); ++size)
                    ;
                (*cells)[cell_id].length = size;
                (*cells)[cell_id].state = NOT_FULL;
                j += size;
                ++cell_id;
            }
        }
    }

    // Vertical cell assignment.

    for (int j = 0; j < *hor_count; ++j){
        if (cell_id >= cells_size){
            cells_size += 50;
            *cells = realloc(*cells, sizeof(Cell) * cells_size);
        }

        for (int i = 0; i < ver_count - 1; ++i){

            if (lines[i][j] == '0' && lines[i + 1][j] == '0'){
                (*cells)[cell_id].row = i;
                (*cells)[cell_id].col = j;
                (*cells)[cell_id].direction = VERTICAL;
                int size = 2;
                for (; i + size < ver_count && (lines[i + size][j] == '0'); ++size)
                    ;
                (*cells)[cell_id].length = size;
                (*cells)[cell_id].state = NOT_FULL;
                i += size;
                ++cell_id;
            }
        }
    }


    *cells = realloc(*cells, cell_id * sizeof(Cell));
    *c_size = cell_id;




    // If unfillable matrix was given, zero_count is set to -1.
    if (*zero_count == 0){
        *zero_count = -1;
    }
}
void validateWords(char **words, int *size){

    int state = 0;

    // Remove duplicates and free unused memory.
    for (int i = 0; i < *size - 1; ++i){
        for (int j = i + 1; j < *size; ++j){
            if (strcmp(words[i], words[j]) == 0){
                pop(words, size, j);
                state = 1;
                --j;
            }
        }
    }
    if (state){
        printf("\nDuplicates in the wordlist were detected and won't be counted!\n");
    }
    int min_cond = 2; // Minimal amount of letters a word must have to be considered as a word.

    for (int i = 0; i < *size; ++i){

        if (strlen(words[i]) < min_cond){
            pop(words, size, i);
            --i;
            continue;
        }
        for (int j = 0; words[i][j] != '\0'; ++j){
            CHECK_FOR_ERROR(!isalpha(words[i][j]), "Words can only contain letters, no digits.", 3);
        }
    }

    printf("\nWords that are shorter than %d letters will be ignored.\n\n", min_cond);
}


char *pop(char **array, int *size, int id){
    
    char *ret = array[id];
    memmove((array + id), (array + id + 1), sizeof(char *) * ((*size) - 1 - id));
    --(*size);
    array = realloc(array, sizeof(char *) * (*size));
    return ret;
}



char **getWords(FILE *file, int *count){
    char **words;
    
    int limit = 10;
    words = malloc(limit * sizeof(char *));
    CHECK_FOR_ERROR((words == NULL), "Couldn't allocate memory.", 4);

    char string[STR_LENGTH];
    *count = 0;

    while (fgets(string, STR_LENGTH, file)){
        int length = strlen(string);

        // STR_LENGTH - 3 to exclude \n, \r and \0
        CHECK_FOR_ERROR((length > STR_LENGTH - 3), "Any word cannot be longer than %d characters.", 5, STR_LENGTH - 3);


        // Discarding \r and \n, as fgets puts those symbols in the string.
        if (string[length - 1] == '\n'){
            string[--length] = '\0';
        }
        if (string[length - 1] == '\r'){
            string[--length] = '\0';
        }

        // Throw an error if it has any type of whitespace. 
        checkForWhitespaces(string, length);


        // Allocate extra memory if wordlist is big. 
        if (*count + 1 > limit){
            limit += 10;
            words = realloc(words, limit * sizeof(char *));
            CHECK_FOR_ERROR((words == NULL), "Couldn't allocate memory.", 4);
        }


        // Copyig input to a dynamic array.
        words[(*count)] = malloc(length + 1);
        CHECK_FOR_ERROR((words[(*count)] == NULL), "Couldn't allocate memory.", 4);

        strcpy(words[(*count)++], string);
    }

    return words;
}


void openFiles(FILE **wordlist, FILE **matrix){

    printf("Enter a file name that has listed words in it. Example: words.txt\n");
    char filename[512];
    scanf("%s", filename);

    *wordlist = fopen(filename, "r");
    CHECK_FOR_ERROR((*wordlist == NULL), "Error: %s was not found.", 1, filename);
    CHECK_FOR_ERROR((isEmptyFile(*wordlist)), "Error: %s is an empty file.", 2, filename);


    printf("Enter a file name that has listed crossword's matrix in it. Example: matrix.txt\n");
    scanf("%s", filename);
    
    *matrix = fopen(filename, "r");
    CHECK_FOR_ERROR((*matrix == NULL), "Error: %s was not found.", 1, filename);
    CHECK_FOR_ERROR((isEmptyFile(*matrix)), "Error: %s is an empty file.", 2, filename);
}

char isEmptyFile(FILE *file){
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    if (0 == size){
        fclose(file);
        return 1;
    }
    fseek(file, 0, SEEK_SET);
    return 0;
}

void checkForWhitespaces(char *string, int size){
    for (int i = 0; i < size; ++i){
        CHECK_FOR_ERROR(isspace(string[i]), "Words must be listed in columns with no whitespaces,"
        " only one word per line.", 3);
    }
}