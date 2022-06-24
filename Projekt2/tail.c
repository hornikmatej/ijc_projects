// tail.c
// Řešení IJC-DU2, příklad a), 21.4.2020
// Autor: Matej Hornik (xhorni20), FIT
// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0


#include <stdio.h>  
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <limits.h>
#include <stdarg.h>

#define DEFAULT_LINES 10
#define LINE_LIMIT 1024
#define MAX_LINES 1000

void usage(void){
    printf("Usage: ./tail [-n cislo > 0] [FILE]\n");
}


//funckia ktora printe poslednych n riadkov v subore
void print_line_file(FILE *file, int startline)
{
    char buffer[LINE_LIMIT];
    memset(buffer, 0, sizeof(buffer));
    int c;
    fseek(file,(startline + 1),SEEK_SET);
    int i = 0;
    bool can_store = false, error_msg = false;
    while ((c = fgetc(file)) != EOF){
        if (i > LINE_LIMIT - 2){
                if (!error_msg){
                    fprintf(stderr, "Prekrocenie poctu znakov na riadok (%lu + miesto pre '\\0' a '\\n') takze orezem riadok a vypisem ho\n", (unsigned long)LINE_LIMIT);
                    error_msg = true;
                }
            }
            if (LINE_LIMIT - 2 == i){
                buffer[i] = '\n';
                buffer[i+1] = '\0';
                i++;

            }
            if (i < LINE_LIMIT - 2){
                buffer[i] = c;
                i++;
            }
        if (c == '\n'){
            if (error_msg)
                buffer[i+1] = '\0';
            can_store = true;
            error_msg = false;
            i = 0;
        }
        if (can_store){
            printf("%s",buffer);
            memset(buffer, 0, sizeof(buffer));
            can_store = false;
        }
    }
    printf("%s",buffer);
}

//funckia ktora printe riadky od n cisla
void walk_file(FILE *file, unsigned long nlines)
{
    int fposition;
    fseek(file,0,SEEK_END);
    fposition = ftell(file);
    int end = fposition;
    unsigned long countlines= 0;
    char cbyte;

    for(int index = fposition; index >= 0; index--)
    {
        cbyte= fgetc(file);
        if (cbyte == '\n' && (end - index) > 1){
            countlines ++;
            if(countlines == nlines){
                break;
            }
        }
        fposition--;
        fseek(file,fposition,SEEK_SET);
    }
    print_line_file(file, fposition);
    fclose(file);
}
//prinotvacia funkcia pre riadky zo suboru
void start_from_file(FILE *file, unsigned long nlines){
    int c;
    int fposition;
    while ((c = fgetc(file)) != EOF){
        if (nlines == 1){
            fposition = ftell(file) - 2;
            break;
        }
        if (c == '\n')
            nlines--;
    }
    print_line_file(file, fposition);
    fclose(file);
}

//funkcia zacne printovat od riadky on n-teho riadku
void walk_stdin(FILE *file, unsigned long nlines){
    char arr_str[nlines][LINE_LIMIT];
    memset(arr_str, 0, sizeof(arr_str));
    int c;
    int i = 0;
    unsigned long circular_i = 0, num_of_l = 0;
    bool error_msg = false;
    while ((c = fgetc(file)) != EOF){
        if (i > LINE_LIMIT - 2){
            if (!error_msg){
                fprintf(stderr, "Prekrocenie poctu znakov na riadok (%lu + miesto pre '\\0' a '\\n') takze orezem riadok a vypisem ho\n", (unsigned long)LINE_LIMIT);
                error_msg = true;
            }
        }
        if (LINE_LIMIT - 2 == i){
            arr_str[circular_i][i] = '\n';
            arr_str[circular_i][i+1] = '\0';
            i++;
        }
        if (i < LINE_LIMIT - 2){
            arr_str[circular_i][i] = c;
            i++;
        }
        if (c == '\n'){
            num_of_l++;
            if (!error_msg)
                arr_str[circular_i][i] = '\0';
            if (circular_i == nlines -1){
                circular_i = 0;
            }
            else{
                circular_i++;
            }
            error_msg = false;
            i = 0;
        }
    }
    unsigned long index = num_of_l%nlines;
    for (unsigned long j = 0; j < nlines; j++){
        char c = '1';
        unsigned long k = 0;
        while (c != '\0'){
            c = arr_str[index][k];
            k++;
            putchar(c);
        }
        index = (index+1)%nlines;
        c = '1';
    }
}

//funckia vyprintuje poslednych n riadkov zo stdin
void start_from_stdin(FILE *file, unsigned long from_line){
    char buffer[LINE_LIMIT];
    memset(buffer, 0, sizeof(buffer));
    int c;
    int i = 0;
    bool can_store = false, error_msg = false;
    while ((c = fgetc(file)) != EOF){
        if (from_line == 1){
            if (i > LINE_LIMIT - 2){
                if (!error_msg){
                    fprintf(stderr, "Prekrocenie poctu znakov na riadok (%lu + miesto pre '\\0' a '\\n') takze orezem riadok a vypisem ho\n", (unsigned long)LINE_LIMIT);
                    error_msg = true;
                }
            }
            if (LINE_LIMIT - 2 == i){
                buffer[i] = '\n';
                buffer[i+1] = '\0';
                i++;

            }
            if (i < LINE_LIMIT - 2){
                buffer[i] = c;
                i++;
            }
            if (c == '\n'){
                if (error_msg)
                    buffer[i+1] = '\0';
                can_store = true;
                error_msg = false;
                i = 0;
            }
            if (can_store){
                printf("%s",buffer);
                memset(buffer, 0, sizeof(buffer));
                can_store = false;
            }
            continue;
        }
        if (c== '\n')
            from_line--;
    }
}
//funkcia konvertuje string na unsinged long
unsigned long convert_strtoul(char *string_to_convert){
    unsigned long result;
    char *eptr;
    // prekonvertujeme string na unsigned long
    result = strtoul(string_to_convert, &eptr, 10);
    
    // ak nastala chyba pri konvertovani
    if (result == 0){
        usage();
        fprintf(stderr,"Nepodarilo sa previest string na cislo alebo cislo bolo mensie 1\n");
        exit(1);
    }

    // ak cislo bolo mimo rozsah unsigned long
    if (errno == ERANGE){
        fprintf(stderr,"Cislo bolo mimo rozsah: <0,%lu>\n",ULONG_MAX);
        exit(1);
    }
    return result;
}
  
int main(int argc, char *argv[])  
{ 
    unsigned long n_of_lines = DEFAULT_LINES;
    unsigned long print_from;
    bool plus_n = false;
    FILE *f;

    //parsovanie argumentov zo vstupu
    if (argc >= 5){
        usage();
        fprintf(stderr, "Prilis vela argumentov\n");
        exit(1);
    }
    else if (argc == 1)
        f = stdin;
    else if (argc == 2){
        f = fopen(argv[1], "r");
        if (f == NULL){
            fprintf(stderr, "Nepodarilo sa otvorit subor '%s'\n",argv[1]);
            exit (1);
        }
    }
    else {
        if (strcmp(argv[1], "-n")){
            usage();
            fprintf(stderr, "Zla moznost argumentu '%s'\n",argv[1]);
            exit(1);
        }
        char check_plus = argv[2][0];
        if ('+' == check_plus)
            plus_n = true;
        if ('-' == check_plus){
            fprintf(stderr, "Pred stringom: '%s' nemoze byt '-'\n",argv[2]);
            exit(1);
        }
        if (plus_n){
            print_from = convert_strtoul(argv[2]);
        }
        else
            n_of_lines = convert_strtoul(argv[2]);
        f = stdin;
        if (argc == 4){
            f = fopen(argv[3], "r");
            if (f == NULL){
                fprintf(stderr, "Nepodarilo sa otvorit subor '%s'\n",argv[3]);
                exit (1);
            }
        }
    }
    if (f == stdin){
        if (plus_n)
            start_from_stdin(f, print_from);
        else
            walk_stdin(f, n_of_lines);
    }
    else{
        if (plus_n)
            start_from_file(f, print_from);
        else
            walk_file(f, n_of_lines);
    }

    return 0; 
} 