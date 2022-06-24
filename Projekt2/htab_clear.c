// htab_clear.c
// Řešení IJC-DU2, příklad b), 21.4.2020
// Autor: Matej Hornik (xhorni20), FIT
// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
//


#include <stdlib.h> //free
#include "htab.h"
#include "htab_private.h"

//uzivatel si musi byt isty ze posiela ukazatel na platny hash table inac nastane chyba
void htab_clear(htab_t * t){
    struct htab_item *next;
    for (size_t i = 0; i < t->arr_size; i++){
        while (t->array[i] != NULL){
            next = t->array[i]->next;
            free(t->array[i]->key);
            free(t->array[i]);
            t->array[i] = next;
        }
    }
    t->size = 0;
}