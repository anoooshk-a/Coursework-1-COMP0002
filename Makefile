graphics.o: graphics.c
	gcc -c graphics.c -o graphics.o

main.o: main.c
	gcc -c main.c -o main.o

grid.o: grid.c
	gcc -c grid.c -o grid.o

robot.o: robot.c
	gcc -c robot.c -o robot.o

linked_list.o: linked_list.c
	gcc -c linked_list.c -o linked_list.o

# main target
robot: graphics.o main.o grid.o robot.o linked_list.o
	gcc -o robot -fsanitize=address graphics.o main.o grid.o robot.o linked_list.o

# remove all obj files and program output
clean:
	rm *.o
	rm robot

