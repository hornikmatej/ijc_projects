// bitset.h
// Řešení IJC-DU1, příklad a), 18.3.2020
// Autor: Matej Hornik (xhorni20), FIT
// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
// makra a inline funkcie

#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <stdlib.h>
#include "error.h"

#ifndef BITSET_H
    #define BITSET_H

typedef unsigned long *bitset_t;
typedef unsigned long bitset_index_t;

#define UL_size (CHAR_BIT * sizeof(unsigned long))

#define bitset_create(pole, velikost) if (velikost <= 0) {error_exit("Velikost pola nemoze byt 0\n");} \
            unsigned long pole[velikost%UL_size == 0 ? velikost / UL_size +1 : velikost/UL_size +2] = {velikost};

#define bitset_alloc(pole, velikost) if (velikost <= 0) {error_exit("Velikost pola nemoze byt 0\n");} \
            bitset_t pole = calloc(velikost%UL_size == 0 ? velikost / UL_size +1 : velikost/UL_size +2, sizeof(unsigned long)); \
            pole != NULL ? pole[0] = velikost : (error_exit("bitset_alloc: Chyba alokace paměti\n"), 0);

#define bitset_free(pole) (free(pole))


#ifndef USE_INLINE
//ak je vypnuta optimalizacia pouziju sa makra
#define bitset_size(pole) (pole[0])

#define bitset_setbit(pole,index,vyraz) \
            if((bitset_index_t)index >= bitset_size(pole)) \
            {error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n", \
            (unsigned long)index, (unsigned long)pole[0]-1);}\
            ((vyraz) ? (pole[((bitset_index_t)index/UL_size)+1] |= (1UL << ((bitset_index_t)index%UL_size))) : \
            (pole[((bitset_index_t)index/UL_size)+1] &= ~(1UL << ((bitset_index_t)index%UL_size))))

#define bitset_getbit(pole, index) \
        ((bitset_index_t)index >= bitset_size(pole)) ? \
        (error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", \
        (unsigned long)index, (unsigned long)pole[0]-1), -1) : \
        ((pole[(((bitset_index_t)index)/UL_size)+1] & (1UL << (((bitset_index_t)index)%UL_size))) != 0)\

//ak je zapnuta optimalizacia pouziju sa tieto funkcie namiesto makier
#else

inline unsigned long bitset_size(bitset_t pole){
    return pole[0];
}

inline void bitset_setbit(bitset_t pole, bitset_index_t index, unsigned long vyraz){
    if((bitset_index_t)index >= bitset_size(pole))
        error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, (unsigned long)pole[0]-1);
    ((vyraz) ? (pole[((bitset_index_t)index/UL_size)+1] |= (1UL << ((bitset_index_t)index%UL_size))) : \
    (pole[((bitset_index_t)index/UL_size)+1] &= ~(1UL << ((bitset_index_t)index%UL_size))));
    return;
}

inline unsigned long bitset_getbit(bitset_t pole, bitset_index_t index){
    if((bitset_index_t)index >= bitset_size(pole))
    error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, (unsigned long)pole[0]-1);
    return (pole[((bitset_index_t)index/UL_size)+1] & (1UL << ((bitset_index_t)index%UL_size)));
}

#endif //koniec if-u pre inline

#endif