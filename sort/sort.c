#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <errno.h>

DIR* Open_Folder(char *PATH_TO_FOLDER){
    
    DIR* FOLDER = opendir(PATH_TO_FOLDER);

    if(!FOLDER){

        puts("Folder ne moze da se otvori");
        return;
    }
    else if (ENOENT == errno){
        
        puts("Folder ne postoji");
        return;
    }

    return FOLDER;
}

char **List_Files(char *PATH_TO_FOLDER){

    DIR *FOLDER = Open_Folder(PATH_TO_FOLDER);

    struct dirent *DIR_STRUCT;

    char FILES_IN_FOLDER[128][256];

    int i = 0;

    while((DIR_STRUCT = readdir(FOLDER)) != NULL){

        if(DIR_STRUCT->d_namlen > 256){
            
            puts("Ime fajla ne sme biti duze od 256 karaktera");
            return;
        }

        strcpy(FILES_IN_FOLDER[i], DIR_STRUCT->d_name);
    }

    return FILES_IN_FOLDER;
}


bool Compare(const void *a, const void *b) {
    
        return strcmp(*(const char **)a, *(const char **)b);
 }

int File_Count(char **FILES_IN_FOLDER) {
        int count = 0;
        while (FILES_IN_FOLDER[count] != NULL) {
            count++;
        }
        return count;
}

void Sort_Alpha(char *PATH_TO_FOLDER){

    char **FILES_IN_FOLDER;
    FILES_IN_FOLDER = List_Files(PATH_TO_FOLDER);



    qsort(FILES_IN_FOLDER, file_count(FILES_IN_FOLDER), sizeof(char *), Compare);

    for (int i = 0; FILES_IN_FOLDER[i] != NULL; i++) {
        printf("%s\n", FILES_IN_FOLDER[i]);
    }
}