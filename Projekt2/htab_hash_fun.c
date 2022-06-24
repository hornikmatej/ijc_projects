// htab_hash_fun.c
// Řešení IJC-DU2, příklad b), 21.4.2020
// Autor: Matej Hornik (xhorni20), FIT
// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
// ak bude vo wordcounte definove HASHTEST tak bude brat druhu hashovaciu funkciu



#include <stdint.h>
#include "htab.h"

#ifdef HASHTEST

size_t htab_hash_fun(htab_key_t str){
    //djb2
    uint32_t  h = 5381;
    int c;
    while (c = *str++)
        h = ((h << 5) + h) + c; /* hash * 33 + c */

    return h;
}




#else

size_t htab_hash_fun(htab_key_t str){
    uint32_t h=0;     // musí mít 32 bitů   
    const unsigned char *p;
    for(p=(const unsigned char*)str; *p!='\0'; p++)
        h = 65599*h + *p;
    return h;
}


#endif