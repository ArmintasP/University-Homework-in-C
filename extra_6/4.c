 /*
Parašykite programą, kuri patikrina, ar eilutėje yra korektiškai įvestas el.pašto adresas. 
Laikykite, kad jis korektiškas, jei eilutėje yra vienas simbolis @ ir (po jo) bent vienas taškas,
o prieš @, po taško ir tarp šių dviejų simbolių – ne mažiau nei vienas kitoks simbolis.
Jei įvestis korektiška, programa turi atspausdinti domeną, t.y. el.pašto dalį po simbolio @.
Visi kada nors pateikti korektiški elektroninio pašto adresai turi būti kaupiami (append) tekstiniame faile “emails.txt”.
*/

#include <stdio.h>


int main(){
    printf("Please enter your e-mail address:\n");
    char name[50], domain[50], domain_end[50];
    if (scanf("%[^@\t\n ]@%[^.\t@ ].%3[^ @\t\n]", name, domain, domain_end) != 3){
        printf("Entered email was not valid. Program will be terminated.\n");
        return 2;
    }
    FILE *emails = fopen("emails.txt", "a");
    fprintf(emails, "%s@%s.%s\n", name, domain, domain_end);

    printf("Email domain is: %s.\n", domain);
    return 0;
}
 