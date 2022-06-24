#// primes.c
#// Řešení IJC-DU1,, priklad a), 18.3.2020
#// Autor: Matej Hornik (xhorni20), FIT
#// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0

#premenne
LC_ALL=cs_CZ.utf8
CC=gcc -O2 -std=c11 -pedantic -Wall -Wextra -lm
INLINE=-DUSE_INLINE

#preklad programov
all: primes primes-i steg-decode

#spustenie
run:
	ulimit -s 65000 && time ./primes
	ulimit -s 65000 && time ./primes-i
#
# uloha a) primes
#
primes: primes.o error.o bitset.o eratosthenes.o
	$(CC) primes.o error.o bitset.o eratosthenes.o -o primes -lm 

primes.o: primes.c bitset.h error.h
	$(CC) -c primes.c -o primes.o

eratosthenes.o: eratosthenes.c  eratosthenes.h bitset.h error.h
	$(CC) -c eratosthenes.c -o eratosthenes.o -lm

bitset.o: bitset.c bitset.h
	$(CC) -c bitset.c -o bitset.o

#preklad pre inline funkcie
primes-i: primes-i.o error.o bitset-i.o eratosthenes-i.o
	$(CC) $(INLINE) primes-i.o error.o bitset-i.o eratosthenes-i.o -o primes-i -lm

primes-i.o: primes.c bitset.h error.h
	$(CC) $(INLINE) -c primes.c -o primes-i.o

eratosthenes-i.o: eratosthenes.c eratosthenes.h bitset.h error.h
	$(CC) $(INLINE) -c eratosthenes.c -o eratosthenes-i.o -lm


bitset-i.o: bitset.c bitset.h
	$(CC) $(INLINE) -c bitset.c -o bitset-i.o

#
# uloha 2 steg-decode b)
#

steg-decode: steg-decode.o ppm.o error.o bitset.o eratosthenes.o
	$(CC) steg-decode.o ppm.o error.o bitset.o eratosthenes.o -o steg-decode -lm

steg-decode.o: steg-decode.c bitset.h error.h eratosthenes.h ppm.h
	$(CC) -c steg-decode.c -o steg-decode.o

ppm.o: ppm.c ppm.h error.h eratosthenes.h bitset.h
	$(CC) -c ppm.c -o ppm.o


error.o: error.c error.h
	$(CC) -c error.c

#ostatne pirkazy

zip:
	zip xhorni20.zip *.c *.h Makefile

clean:
	rm -f *.o primes primes-i steg-decode