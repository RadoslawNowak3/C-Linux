all: sem.c sem.h pamdziel.c pamdziel.h prod.c kons.c prodkons.c
	gcc -c sem.c -o sem.o -lpthread
	gcc -c pamdziel.c -o pamdziel.o -lpthread -lrt
	ar rcs libsem.a sem.o
	ar rcs libpamdziel.a pamdziel.o
	rm -f *.o
	gcc prodkons.c -o prodkons.x -L. -lpamdziel -lsem -lrt -lpthread
	gcc kons.c -o kons.x -L. -lpamdziel -lsem -lrt -lpthread
	gcc prod.c -o prod.x -L. -lpamdziel -lsem -lrt -lpthread
	

.PHONY: clean all new tar 
clean:
	rm -f *.x
	rm -f *.o
	rm -f *.a

DIR = `basename $(PWD)`

tar: clean
	

new: clean all

.PHONY: run_prodkons
run_prodkons: prodkons.x
	./prodkons.x in out /SegmentPD 120

