// io.c
// Řešení IJC-DU2, příklad b), 21.4.2020
// Autor: Matej Hornik (xhorni20), FIT
// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
//


#include <stdio.h>
#include "io.h"

int get_word(char *s, int max, FILE*f){
    if (f == NULL){
        fprintf(stderr,"Neplatni subor\n");
        return -1;
    }
    int lenght = 0;
    int c;
    int overflow = 0;
    //preskocenie znakov ktore niesu isspace
    while ( isspace((c = fgetc(f))) ){
        if (c == EOF)
            return EOF;
    }
    if (!isspace(c) &&  c != EOF){
        s[lenght] = c;
        lenght = 1;
    }
    //nacitavam znaky zo suboru  ukladam ich
    while ((c = fgetc(f)) != EOF && !isspace(c)){
        s[lenght] = c;
        lenght++;
        if (max == lenght){
            overflow = 1;
            s[lenght-1] = '\0';
            break;
        }
    }
    if (c == EOF){
        s[lenght] = '\0';
        return EOF;
    }

    if (overflow){
        while((c = fgetc(f)) != EOF && !isspace(c)){
            ;//preskocime znaky v overflowed slove
        }
        return lenght+1;
    }
    else{
        s[lenght]='\0';
    }
    return lenght;
}
