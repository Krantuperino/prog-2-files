point: point.o main.o map.o
	gcc -Wall -g -o point point.o main.o map.o

map.o: map.c map.h point.h types.h
	gcc -Wall -g -c map.c

point.o: point.c point.h types.h
	gcc -Wall -g -c point.c

main.o: main.c point.h
	gcc -Wall -g -c main.c

clean:
	rm -rf *.o point
