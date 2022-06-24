// htab_private.h
// Řešení IJC-DU2, příklad b), 21.4.2020
// Autor: Matej Hornik (xhorni20), FIT
// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
// htab_private.h -- privatny hlavickovy subor (řešení IJC-DU2)

// následující řádky zabrání násobnému vložení:
#ifndef __HTAB_PRIVATE__
#define __HTAB_PRIVATE__

#include "htab.h"

struct htab {
    size_t size;
    size_t arr_size;
    struct htab_item *array[];
};

struct htab_item {
    char *key;
    int data;
    struct htab_item *next;
};

#endif // __HTAB_PRIVATE__