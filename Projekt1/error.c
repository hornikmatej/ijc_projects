// error.c
// Řešení IJC-DU1, příklad a),b), 18.3.2020
// Autor: Matej Hornik (xhorni20), FIT
// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
//programy pre vypis chyb a hlasok

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "error.h"



/**
 * Informujem o errore ktory nieje vazny a v programe sa pokracuje dalej
 */
void warning_msg(const char *fmt, ...){
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, args); 
    va_end(args); 
}
/**
 * Informujem o errore a vzapati skoncim program
 */
void error_exit(const char *fmt, ...){
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, args);
    va_end(args);
    exit(1);
}