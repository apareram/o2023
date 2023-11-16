petsGTK.exe: petsGTK.o 
	gcc -o petsGTK.exe petsGTK.o funGTK.o funC.o `pkg-config --libs gtk+-2.0`

petsGTK.o: petsGTK.c funGTK.c funC.c
	gcc -c petsGTK.c funGTK.c funC.c `pkg-config --cflags gtk+-2.0`

clean: 
	rm *.o