#// Makefile
#// Řešení IJC-DU2, 16.4.2020
#// Autor: Matej Hornik (xhorni20), FIT
#// Přeloženo: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0

#premenne
CC=gcc -std=c99 -pedantic -Wall -Wextra 

#preklad programov
all: tail wordcount wordcount-dynamic

# uloha 1) tail
#
tail: tail.o
	$(CC) tail.o -o $@

tail.o: tail.c
	$(CC) -c tail.c -o $@

# uloha 2) wordcount, io a knihovny
#

wordcount: wordcount.o io.o libhtab.a
	$(CC) -o $@ wordcount.o io.o libhtab.a

wordcount-dynamic: wordcount.o io.o libhtab.so
	$(CC) -o $@ wordcount.o io.o libhtab.so

wordcount.o: wordcount.c
	$(CC) -o $@ -c wordcount.c

io.o: io.c io.h
	$(CC) -o $@ -c io.c


#knihovny

libhtab.a: htab_begin.o htab_bucket_count.o htab_clear.o htab_end.o htab_erase.o htab_find.o htab_free.o htab_hash_fun.o htab_init.o htab_iterator_get_key.o htab_iterator_get_value.o htab_iterator_set_value.o htab_iterator_next.o htab_lookup_add.o htab_size.o htab.o
	ar crs $@ $^

libhtab.so: htab_begin.o htab_bucket_count.o htab_clear.o htab_end.o htab_erase.o htab_find.o htab_free.o htab_hash_fun.o htab_init.o htab_iterator_get_key.o htab_iterator_get_value.o htab_iterator_set_value.o htab_iterator_next.o htab_lookup_add.o htab_size.o htab.o
	$(CC) -fPIC -shared -o $@ $^  

#objektove subory pre kniznice

htab_begin.o: htab_begin.c htab.h htab_private.h
	$(CC) -fPIC -c $<

htab_bucket_count.o: htab_bucket_count.c htab.h htab_private.h
	$(CC) -fPIC -c $<

htab_clear.o: htab_clear.c htab.h htab_private.h
	$(CC) -fPIC -c $<

htab_end.o: htab_end.c htab.h htab_private.h
	$(CC) -fPIC -c $<

htab_erase.o: htab_erase.c htab.h htab_private.h
	$(CC) -fPIC -c $<

htab_find.o: htab_find.c htab.h htab_private.h
	$(CC) -fPIC -c $<

htab_free.o: htab_free.c htab.h
	$(CC) -fPIC -c $<

htab_hash_fun.o: htab_hash_fun.c htab.h
	$(CC) -fPIC -c $<

htab_init.o: htab_init.c htab.h htab_private.h
	$(CC) -fPIC -c $<

htab_iterator_get_key.o: htab_iterator_get_key.c htab.h htab_private.h
	$(CC) -fPIC -c $<

htab_iterator_get_value.o: htab_iterator_get_value.c htab.h htab_private.h
	$(CC) -fPIC -c $<

htab_iterator_set_value.o: htab_iterator_set_value.c htab.h htab_private.h
	$(CC) -fPIC -c $<

htab_iterator_next.o: htab_iterator_next.c htab.h htab_private.h
	$(CC) -fPIC -c $<

htab_lookup_add.o: htab_lookup_add.c htab.h htab_private.h
	$(CC) -fPIC -c $<

htab_size.o: htab_size.c htab.h htab_private.h
	$(CC) -fPIC -c $<

htab.o: htab.c htab.h
	$(CC) -fPIC -c $<



#ostatne prikazy
.PHONY: clean, zip, clean-all

zip:
	zip xhorni20.zip *.c *.cc *.h Makefile

clean:
	rm -f *.o

clean-all:
	rm -f *.o tail wordcount wordcount-dynamic libhtab.a libhtab.so