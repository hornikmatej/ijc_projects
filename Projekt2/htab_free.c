// htab_free.c
// Řešení IJC-DU2, příklad b), 21.4.2020
// Autor: Matej Hornik (xhorni20), FIT
// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
//



#include <stdlib.h> //free
#include "htab.h"

//uzivatel si musi byt isty ze posiela ukazatel na platny hash table inac nastane chyba
void htab_free(htab_t * t){
    htab_clear(t);
    free(t);
}