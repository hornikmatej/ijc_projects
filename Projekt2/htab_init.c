// htab_init.c
// Řešení IJC-DU2, příklad b), 21.4.2020
// Autor: Matej Hornik (xhorni20), FIT
// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
//



#include <stdio.h> //fprintf
#include <stdlib.h> //malloc

#include "htab.h"
#include "htab_private.h"

htab_t *htab_init(size_t n){
    htab_t *htable = malloc(sizeof(htab_t) + n*sizeof(struct htab_item));
    if (htable == NULL){
        fprintf(stderr,"Nepodarilo sa allokovat pamat pre hash talbe\n");
        return NULL;
    }
    htable->arr_size = n;
    htable->size = 0;
    //nastavenie ukazovatelov na null
    for (size_t i = 0; i < n; i++)
        htable->array[i] = NULL;
    
    return htable;
}