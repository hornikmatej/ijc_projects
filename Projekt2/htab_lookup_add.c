// htab_lookup_add.c
// Řešení IJC-DU2, příklad b), 21.4.2020
// Autor: Matej Hornik (xhorni20), FIT
// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
//


#include <stdio.h> //fprintf
#include <stdlib.h> //malloc
#include <string.h> //strncpy

#include "htab.h"
#include "htab_private.h"

htab_iterator_t htab_lookup_add(htab_t * t, htab_key_t key){
    size_t index = htab_hash_fun(key) % t->arr_size;
    htab_iterator_t it;
    it.t = t;
    it.idx = index;
    it.ptr = t->array[index];
    //riadok v ktorom sa ma kluc nachadzat prejdeme
    while (htab_iterator_valid(it) && it.idx == index){
        if (!strcmp(htab_iterator_get_key(it), key)){
            return it;
        }
        it.ptr = it.ptr->next;
    }
    //neobsahovalo dany kluc tak vytvorim novy zaznam
    it.ptr = malloc(sizeof(struct htab_item));
    //ak sa nepodarilo allokovat tak vrati htab_end
    if (it.ptr == NULL){
        fprintf(stderr,"Nepodarilo sa allokovat pamat pre novy zaznam\n");
        return htab_end(t);
    }
    //skopiruje kluc do struktury htab_item
    const size_t len_my_str = strlen(key) + 1;
    it.ptr->key = malloc(len_my_str);
    if (it.ptr->key == NULL){
        fprintf(stderr,"Nepodarilo sa allokovat pamat pre kluc v strukture\n");
        free(it.ptr);
        return htab_end(t);
    }
    //nakopiruj kluc do htab_item
    strncpy(it.ptr->key, key, len_my_str);
    //nastavim value v htab_item na 0
    htab_iterator_set_value(it,0);
    //novy zaznam pridam na zaciatok arrayu[index]
    it.ptr->next = t->array[index];
    t->array[index] = it.ptr;
    t->size++;
    return it;
}