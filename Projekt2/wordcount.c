
// wordcount.c
// Řešení IJC-DU2, příklad 2), 23.4.2020
// Autor: Matej Hornik (xhorni20), FIT
// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
// Pocitanie slov 

#include <stdio.h>
#include <stdlib.h>
#include "htab.h"
#include "io.h"

#define MAX_WORD_L 127 + 1  //127 pismen + '\0'
#define HTAB_SIZE 12007 
//cislo som vybral na zaklade poctu unikatnych slov v harry potter serii a vynasobil som to dvoma a este som nasiel najblizsie prvocislo

int main(){
    FILE *f = stdin;
    char *s = malloc(MAX_WORD_L * sizeof(char));

    if (s == NULL){
        fprintf(stderr,"Chyba pri alokaci pamati pre slovo\n");
        exit(1);
    }

    htab_t *dict = htab_init(HTAB_SIZE);

    if (dict == NULL){
        fprintf(stderr, "Nepodarilo sa vytvorit hash table\n");
        free(s);
        exit(1);
    }

    int first_overflow = 0;
    int lenght = 0;
    while((lenght = get_word(s,MAX_WORD_L, f)) != EOF){
        //ak niektoro slovo je dlhsie ako maximum tak vypisem 1 chybovu hlasku
        if (lenght >= MAX_WORD_L && !first_overflow){
            fprintf(stderr, "Zadane slovo bolo prilis dlhe a bolo skratene\n");
            first_overflow = 1;
        }
        htab_iterator_t i = htab_lookup_add(dict, s);
        //kontrolujem htab_lookup_add ci funkcia nezlyhala
        if(htab_iterator_equal(i, htab_end(dict))){
            htab_free(dict);
            free(s);
            exit(1);
        }
        htab_iterator_set_value(i, htab_iterator_get_value(i)+1);
    }
    //pridam posledne slovo do tabulky ak je vacsie ako 0
    if (strlen(s)> 0 ){
        htab_iterator_t i = htab_lookup_add(dict, s);
        //kontrolujem htab_lookup_add ci funkcia nezlyhala
        if(htab_iterator_equal(i, htab_end(dict))){
            htab_free(dict);
            free(s);
            exit(1);
        }
        htab_iterator_set_value(i, htab_iterator_get_value(i)+1);
    }

    //vypisem tabulku
    htab_iterator_t end = htab_end(dict);
    for(htab_iterator_t i= htab_begin(dict); !htab_iterator_equal(i, end); i = htab_iterator_next(i)) {
        printf("%s\t%d\n", htab_iterator_get_key(i), htab_iterator_get_value(i));
    }

    htab_free(dict);
    free(s);
    return 0;
}


