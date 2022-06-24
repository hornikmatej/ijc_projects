// htab_begin.c
// Řešení IJC-DU2, příklad b), 21.4.2020
// Autor: Matej Hornik (xhorni20), FIT
// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
//

#include "htab.h"
#include "htab_private.h"

// tu treba tiez byt isty ze posielame funkcii odkaz na spravny hashtable
//inac vyhodi chybu
htab_iterator_t htab_begin(const htab_t * t){
    htab_iterator_t begin;
    begin.t = t;
    for (size_t i = 0; i < t->arr_size; i++){
        if (t->array[i] != NULL){
            begin.idx = i;
            begin.ptr = t->array[i];
            break;
        }
    }
    return begin;
}