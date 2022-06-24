// bitset.c
// Řešení IJC-DU1, příklad a), 18.3.2020
// Autor: Matej Hornik (xhorni20), FIT
// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
// modul s externimi definicemi inline funkcii

#include "bitset.h"

#ifdef USE_INLINE

extern inline unsigned long bitset_size(bitset_t pole);
extern inline unsigned long bitset_getbit(bitset_t pole, bitset_index_t index);
extern inline void bitset_setbit(bitset_t pole, bitset_index_t index, bitset_index_t vyraz);    

#endif