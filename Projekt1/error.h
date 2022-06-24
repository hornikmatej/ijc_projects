// error.h
// Řešení IJC-DU1, příklad a),b), 18.3.2020
// Autor: Matej Hornik (xhorni20), FIT
// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
//hlavickovy subor pre error.c


#ifndef ERROR_H
    #define ERROR_H
void warning_msg(const char *fmt, ...);
void error_exit(const char *fmt, ...);

#endif