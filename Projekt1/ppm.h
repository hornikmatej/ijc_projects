// ppm.h
// Řešení IJC-DU1, příklad b), 18.3.2020
// Autor: Matej Hornik (xhorni20), FIT
// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
// Hlavickovy subor pre ppm.c

#ifndef PPM_H
	#define PPM_H


#define MAX_RES 8000
#define SUPPORTED_COLORD 255

struct ppm {
        unsigned xsize;
        unsigned ysize;
        char data[];    // RGB bajty, celkem 3*xsize*ysize
};

struct ppm * ppm_read(const char * filename);
void ppm_free(struct ppm *p);

#endif