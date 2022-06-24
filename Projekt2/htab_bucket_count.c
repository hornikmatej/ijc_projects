// htab_bucket_count.c
// Řešení IJC-DU2, příklad b), 21.4.2020
// Autor: Matej Hornik (xhorni20), FIT
// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
//


#include "htab.h"
#include "htab_private.h"

//takisto ako v htab_size si uzivatel musi skontrolovat ci posiela ukaztel na strukturu inac strelba do nohy
size_t htab_bucket_count(const htab_t * t){
    return t->arr_size;
}