// htab.c
// Řešení IJC-DU2, příklad b), 21.4.2020
// Autor: Matej Hornik (xhorni20), FIT
// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
// pre pouzite inline funkcii


#include "htab.h"

extern bool htab_iterator_valid(htab_iterator_t it);
extern bool htab_iterator_equal(htab_iterator_t it1, htab_iterator_t it2);