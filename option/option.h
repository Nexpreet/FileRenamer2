#ifndef OPTION_H
#define OPTION_H


typedef enum {

    /*
    Manipulisanje imenima
    */
    DELETE,
    INSERT,

    /*
    Manipulisanje sa sortiranjem
    */
    SORT,
    INVSORT,

    /*
    Pojavljivalnja
    */
    ALL,
    LEFT,
    RIGHT
}Opcija_Enum;

void Izabrana_Opcija(Opcija_Enum Opcija);


#endif
