// steg-decode.c
// Řešení IJC-DU1, příklad b), 18.3.2020
// Autor: Matej Hornik (xhorni20), FIT
// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
// Hlavny subor pre dekodovanie spravy z obrazka

#include <stdio.h>

#include "error.h"
#include "ppm.h"
#include "bitset.h"
#include "eratosthenes.h"


int main(int argc, char *args[]){

    if (argc != 2) error_exit("Program bere iba jeden argument a to nazov obrazka\n");

    struct ppm *p = ppm_read(args[1]);
    if (p == NULL) error_exit("Nepodarilo sa nacitat data z obrazku %s\n",args[1]);

    unsigned int data_size = p->xsize * p->ysize * 3;
    bitset_alloc(primes, data_size);
    eratosthenes(primes);

    unsigned int j = 0;
    char c = 0;
    for(unsigned int i = 23; i < data_size; i++){
        if(bitset_getbit(primes, i)) continue;
        c = c|(p->data[i+1] & 1) << j;
        j++;
        if(j == 8){
            if(c == '\0'){
                putchar('\n');
                bitset_free(primes);
                ppm_free(p);
                return 0;
            }
            putchar(c);
            j = 0;
            c = 0;
        }
    }
    ppm_free(p);
    bitset_free(primes);
    error_exit("Ukoncovaci znak '\0' nebol najdeny.\n");
}