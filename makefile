FLAG = -Wall -Werror -Wextra

all: teste clean

debug:	
	gcc -g main.c sorts.c $(FLAG)

teste: main.o sorts.o	
	gcc main.o sorts.o -o teste $(FLAG)
	./teste

main.o: main.c sorts.h
	gcc main.c -c $(FLAG)

sorts.o: sorts.c sorts.h
	gcc sorts.c -c $(FLAG)

clean:
	rm -r *.o teste


