// htab_iterator_get_value.c
// Řešení IJC-DU2, příklad b), 21.4.2020
// Autor: Matej Hornik (xhorni20), FIT
// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
//


#include "htab.h"
#include "htab_private.h"

htab_value_t htab_iterator_get_value(htab_iterator_t it){
    return it.ptr->data;
}