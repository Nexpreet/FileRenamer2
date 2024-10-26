#include <stdio.h>
#include <stdlib.h>
#include "opener/opener.h"


int main(int argc, char *argv[]){

    display_Opener_Text();


    
    
    getchar();
    system("pause"); //Flashback na nedine katabaze posto izgleda da CMD samo umre ako ne stavim ova 2 (uzeto iz proslog)
    return EXIT_SUCCESS;
}

/*#####################################################################################################
* Funckije za option
* Za removeContent: string koji treba da se obrise, svako pojavljivanje u 1 fajlu/prvo sa leve/prvo sa desne
* Za addContent: String koji treba da se doda, da li na pocetak ili kraj
* Za enumAlpha: Alpha ili InverseAlpha order
*
#####################################################################################################*/

/*
Za enumerator u option.h
bolje ga je razdvojiti u dva razlicita, jedan za prvi meni, drugi za drugi meni itd.
za sada neka ostane ovako.

*/