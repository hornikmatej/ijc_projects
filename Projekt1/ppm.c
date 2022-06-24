// ppm.c
// Řešení IJC-DU1, příklad b), 18.3.2020
// Autor: Matej Hornik (xhorni20), FIT
// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
// Nacitanie dat z obrazku

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ppm.h"
#include "error.h"


struct ppm * ppm_read(const char * filename){
    
    FILE *f;
    f = fopen(filename,"rw");
    if (f == NULL){
        warning_msg("Nepodarilo sa otvorit obrazok: %s\n",filename);
        return NULL;
    }

    char buff[3];
    unsigned int x_size, y_size, colordepth, data_size;

    if(fscanf(f, "%2s %u %u %u",buff, &x_size, &y_size, &colordepth) < 4 ){
        warning_msg("Neslo precitat velkost obrazka a jeho farebnu hlbku  %s.\n", filename);
        fclose(f);
        return NULL;
    }

    if (strcmp(buff, "P6")) {
         warning_msg("Zly format obrazku (musi byt 'P6')\n");
         fclose(f);
         return NULL;
    }


    if (x_size > MAX_RES || y_size > MAX_RES){
        warning_msg("Prekrocenie maximalneho rozlisenia obrazka(MAX 8000x8000): %ux%u\n",x_size,y_size);
        fclose(f);
        return NULL;
    }

    if (colordepth != SUPPORTED_COLORD){
        warning_msg("Farebna hlbka musi byt 255, nie %u\n",colordepth);
        fclose(f);
        return NULL;
    }

    data_size = x_size*y_size*3;
    struct ppm *framebuffer;
    framebuffer = malloc(sizeof(struct ppm) + data_size);
    if (framebuffer == NULL){
        warning_msg("Nepodarilo sa alokovat pamat\n");
        fclose(f);
        return NULL;
    }

    framebuffer->xsize = x_size;
    framebuffer->ysize = y_size;
    if (fread(framebuffer->data, sizeof(char), data_size, f) != data_size){
          warning_msg("Neuspecne nacitanie binarnych dat\n");
          free(framebuffer);
          fclose(f);
          return NULL;
    }

    fclose(f);
    return framebuffer;
}

void ppm_free(struct ppm *p){
    free(p);
}
