all: gaussfile

gaussfile: gaussfile.o gauss.o
	cc gaussfile.o gauss.o -o gaussfile -lm -lcurses

gaussfile.o: gauss.h

gauss.o: gauss.h

clean:
	rm *.o

real_clean: clean
	rm -f gaussfile
