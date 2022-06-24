// htab_size.c
// Řešení IJC-DU2, příklad b), 21.4.2020
// Autor: Matej Hornik (xhorni20), FIT
// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
//

#include "htab.h"
#include "htab_private.h"

//uzivatel si musi byt isty ze posiela ukazatel na danu strukturu inac vyskoci chyba
size_t htab_size(const htab_t * t){
    return t->size;
}