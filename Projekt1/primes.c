// primes.c
// Řešení IJC-DU1, příklad a), 18.3.2020
// Autor: Matej Hornik (xhorni20), FIT
// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
// make run zvysi pamat stacku inac treba nastavit ulimit -s aspon na 65000 pre zistenie 10 poslednych primes do 500 milionov

#include <stdio.h>
#include <time.h>


#include "bitset.h"
#include "eratosthenes.h"
#include "error.h"

#define PRIMES_UPTO 500000000
#define N_OF_PRIMES 10

int main(){
    
    clock_t start = clock();
    if (PRIMES_UPTO < 2){
        error_exit("PRIMES_UPTO must be more than 2\n");
    }
    if (PRIMES_UPTO < N_OF_PRIMES){
        error_exit("There cant be more primes then actual numbers..\n");
    }

    bitset_create(pole, PRIMES_UPTO);
    eratosthenes(pole);
    unsigned long i;
    unsigned long n_of_p = N_OF_PRIMES;


    for (i = PRIMES_UPTO-1; n_of_p > 0 && i > 1; i--){
        if ((bitset_getbit(pole, i)) == 0){
            n_of_p--;
            printf("%lu\n", i);
        }
    }
    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    return 0;
}