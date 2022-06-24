// htab_iterator_next.c
// Řešení IJC-DU2, příklad b), 21.4.2020
// Autor: Matej Hornik (xhorni20), FIT
// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
//


#include "htab.h"
#include "htab_private.h"

htab_iterator_t htab_iterator_next(htab_iterator_t it){
    //ak iterator neukazuje na zaznam vrati pobodni iterator
    if (!htab_iterator_valid(it)){
        return it;
    }
    //ak je to posledny zaznam v riadku
    if (it.ptr->next == NULL){
        //ak je to posledny riadok tak vratim dalsi zaznam coz je htab_end(it.t)
        if (it.idx >= it.t->arr_size-1)
            return htab_end(it.t);
        for (size_t i = it.idx + 1; i < it.t->arr_size ; i++){
            if (it.t->array[i] != NULL){
                it.ptr = it.t->array[i];
                it.idx = i;
                return it;
            }
        }
        //ak pride nakoniec arrayu tak htab_end
        return htab_end(it.t);
        
    }
    else 
        it.ptr = it.ptr->next;
    return it;
}