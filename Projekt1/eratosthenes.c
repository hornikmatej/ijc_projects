// eratosthenes.c
// Řešení IJC-DU1, příklad a), 18.3.2020
// Autor: Matej Hornik (xhorni20), FIT
// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
//eratosthenovo sito

#include <stdio.h>
#include <math.h>

#include "bitset.h"

void eratosthenes(bitset_t pole){

    bitset_setbit(pole, 0, 1);
    bitset_setbit(pole, 1, 1);
    unsigned long i,z;
    unsigned long velkost_pola = bitset_size(pole);
    unsigned long odmocnina_vp = sqrt(velkost_pola);
    
    for (i = 2; i <= odmocnina_vp; i++){
        if (bitset_getbit(pole, i) == 0){
            for (z = i*i; z < velkost_pola; z+=i){
                bitset_setbit(pole, z, 1);
            }
        }

    }
    return;
}