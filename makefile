point: point.o main.o
	gcc -Wall -g -o point point.o main.o

point.o: point.c point.h types.h
	gcc -Wall -g -c point.c

main.o: main.c point.h
	gcc -Wall -g -c main.c

clean:
	rm -rf *.o point
