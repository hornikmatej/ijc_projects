// io.h
// Řešení IJC-DU2, příklad b), 21.4.2020
// Autor: Matej Hornik (xhorni20), FIT
// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
//


#ifndef __IO_H__
#define __IO_H__

#include <stdio.h> //frprintf
#include <ctype.h> //isspace
 
int get_word(char *s, int max, FILE *f);

#endif