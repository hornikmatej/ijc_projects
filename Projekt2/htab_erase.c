// htab_erase.c
// Řešení IJC-DU2, příklad b), 21.4.2020
// Autor: Matej Hornik (xhorni20), FIT
// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
//


#include <stdlib.h> //free

#include "htab.h"
#include "htab_private.h"

//ak nenajde zadany zaznam tak sa ziadny zaznam nevymaze
void htab_erase(htab_t * t, htab_iterator_t it){
    htab_iterator_t to_connect;
    htab_iterator_t erase;
    erase.idx = it.idx;
    erase.t = t;
    erase.ptr = t->array[erase.idx];
    to_connect.ptr = t->array[erase.idx];
    while (erase.ptr != NULL){
        //ak je iterator v riadku so zaznanmi
        if (htab_iterator_equal(erase, it)){
            // potrebujem spojit predchodzi zaznam s nasledujicim
            t->size--;
            to_connect.ptr->next = erase.ptr->next;
            free(it.ptr->key);
            free(it.ptr);
            return;
        }
        to_connect.ptr = erase.ptr;
        erase.ptr = erase.ptr->next;
    }
}
