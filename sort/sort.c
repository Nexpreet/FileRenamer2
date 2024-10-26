#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

#define MAX_FILENAME_LEN 256
#define MAX_FILES_IN_FOLDER 128

DIR* Open_Folder(char *PATH_TO_FOLDER){
    
    DIR* FOLDER = opendir(PATH_TO_FOLDER);

    if(!FOLDER){

        puts("Folder ne moze da se otvori");
        return NULL;
    }
    else if (ENOENT == errno){
        
        puts("Folder ne postoji");
        return NULL;
    }

    return FOLDER;
}

char **List_Files(char *PATH_TO_FOLDER){

    DIR *FOLDER = Open_Folder(PATH_TO_FOLDER);

    struct dirent *DIR_STRUCT;

    char **FILES_IN_FOLDER = malloc(MAX_FILES_IN_FOLDER * sizeof(char *)); //Valjda nisam napravio neki masni vuln ovde

    for (int i = 0; i < MAX_FILES_IN_FOLDER; i++) {
        FILES_IN_FOLDER[i] = malloc(MAX_FILENAME_LEN * sizeof(char));
    }

    int i = 0;  //Nmp zasto pravim ovaj brojac cak i ako imam count funkciju ali ok

    while((DIR_STRUCT = readdir(FOLDER)) != NULL){

        if(DIR_STRUCT->d_namlen > MAX_FILENAME_LEN){
            
            puts("Ime fajla ne sme biti duze od 256 karaktera");
            return;
        }

        strcpy(FILES_IN_FOLDER[i], DIR_STRUCT->d_name); //Zameniti sa strcpy_s kad me ne bude mrzelo (nikada)
        i++;
    }
    FILES_IN_FOLDER[i] = NULL;

    closedir(FOLDER);

    return FILES_IN_FOLDER;
}


int Compare(const void *a, const void *b) {

        return strcmp(*(const char **)a, *(const char **)b);
 }

int File_Count(char **FILES_IN_FOLDER) { //Zbog onog brojaca u List_Files ova funkcija je rekurzivna ali nema veze;

        int count = 0;
        while (FILES_IN_FOLDER[count] != NULL) {
            count++;
        }
        return count;
}

void Sort_Alpha(char *PATH_TO_FOLDER){

    char **FILES_IN_FOLDER;

    FILES_IN_FOLDER = List_Files(PATH_TO_FOLDER);

    qsort(FILES_IN_FOLDER, File_Count(FILES_IN_FOLDER), sizeof(char *), Compare);

    //Sad treba izmisliti neku logiku za sta uraditi sa ovim sortiranim arrejem


}