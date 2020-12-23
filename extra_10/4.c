#include <stdio.h>
#include <assert.h>
#include <string.h>

char *s_strch(char *str, char ch){
    int i;
    for (i = 0; str[i] != '\0'; ++i){
        if (str[i] == ch){
            return str + i;
        }
    }
    return NULL;
}

int main(){
    char *str = "Brave the New World!\0";
    assert(*s_strch(str, '!') == *(str + 19));
    assert(s_strch(str, '?') == NULL);
    assert(s_strch(str, 'a') == (str + 2));

    return 0;
}