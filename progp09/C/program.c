#include <stdlib.h>
#include <stdio.h>
#include "nod.h"

void skrivMeny() {
    printf("\n*******************  MENY *********************\n\n");
    printf("\t 1 Ladda namn fr�n fil\n");
    printf("\t 2 Ny person\n");
    printf("\t 3 S�k namn\n");
    printf("\t 4 S�k personer med bmi\n");
    printf("\t 5 Skriv ut hela listan\n");
    printf("\t 6 Ta bort person\n");
    printf("\t 0 Avsluta\n\n");
    printf("\t Vad vill du g�ra? ");
}

int main(int argc, char * argv[]) {

    Post * lista = NULL;
    int menyval = 1;
    Post tmp;
    Post * tmp_pek;

    printf("Hej och v�lkommen till Viktm�starnas meny\n");
    while (menyval > 0 && menyval <= 6) {
        skrivMeny();
        scanf("%d", &menyval);
        printf("\n");

        switch (menyval) {
        case 1:
            load_names("bmi_namn.txt", & lista);
            break;
        case 2:
            insert(& lista);
            break;
        case 3:
            printf("Vem s�ker du? ");
            fscanf(stdin, "%s", tmp.name);
            tmp_pek = find((*compare_names), tmp, lista);
            if (tmp_pek != NULL) writePost(tmp_pek);
            else printf("Hittade inte namnet '%s'\n", tmp.name);
            break;
        case 4:
            printf("Vilken BMI s�ker du? ");
            fscanf(stdin, "%f", &tmp.bmi);
            tmp_pek = find((*compare_bmi), tmp, lista);
            if (tmp_pek != NULL) writePost(tmp_pek);
            else printf("Hittade inte n�gon med BMI '%s'\n", tmp.name);
            break;
        case 5:
            writeList(lista);
            break;
        case 6:
            /* Ta bort person implementeras fritt.
               L�gg till l�mplid metod i nod */
            printf("Vem vill du ta bort? ");
            fscanf(stdin, "%s", tmp.name);
            if(remove_person(&lista,tmp.name))
		    printf("'%s' borttagen.\n", tmp.name);
            else printf("Hittade inte namnet '%s'\n", tmp.name);
            break;
        }
        
    }

    printf("\n\nHej d�!\n");
    return 0;
}


