#include <stdio.h>
#define MSIZE 9

int showMenu(char *menuTitle, char *meniuOptions[], int menuSize, char *inputMsg){
    int option, temp = 0;
    char ch;
    do{
        printf("%s", menuTitle);
    
        for(int i = 0; i < menuSize; ++i)
            printf("\t%d  %s\n", i + 1 ,meniuOptions[i]);

        printf("%s", inputMsg);
       

        while (temp && getchar() != '\n')
            ;
        temp = 1;     
    }while (scanf("%d", &option) != 1 || option > menuSize || option < 1);

    return option-1;
}

int main(){
    char *mtitle = "Schools of Philosophy:\n";
    int msize = MSIZE;
    char *moptions[MSIZE] ={ "Nihilism", "Existentialism", "Stoicism",
                        "Hedonism", "Structuralism", "Idealism", 
                        "Relativism", "Empiricism", "Rationalism"};
    char *imsg = "Please choose which school you'd like to belong to.\n";
    printf("%s was a wise choice, my dear fellow. \n", moptions[showMenu(mtitle, moptions, msize, imsg)]);

    return 0;
}