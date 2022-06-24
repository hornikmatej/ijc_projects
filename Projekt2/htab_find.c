// htab_find.c
// Řešení IJC-DU2, příklad b), 21.4.2020
// Autor: Matej Hornik (xhorni20), FIT
// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
//


#include "htab.h"
#include "htab_private.h"


htab_iterator_t htab_find(htab_t * t, htab_key_t key){
    size_t index = htab_hash_fun(key) % t->arr_size;
    htab_iterator_t it;
    it.t = t;
    it.idx = index;
    it.ptr = t->array[index];
    //riadok v ktorom sa ma kluc nachadzat prejdeme
    while (htab_iterator_valid(it)){
        //ak sa rovnaju kluce vratim iterator
        if (!strcmp(htab_iterator_get_key(it), key)){
            return it;
        }

        it.ptr = it.ptr->next;
    }
    return htab_end(t);

}