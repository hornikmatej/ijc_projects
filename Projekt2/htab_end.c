// htab_end.c
// Řešení IJC-DU2, příklad b), 21.4.2020
// Autor: Matej Hornik (xhorni20), FIT
// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
//



#include "htab.h"
#include "htab_private.h"
// tu treba tiez byt isty ze posielame funkcii odkaz na spravny hashtable
//inac vyhodi chybu
htab_iterator_t htab_end(const htab_t * t){
    htab_iterator_t end;
    end.idx = t->arr_size;
    end.t = t;
    end.ptr = NULL;
    return end;
}