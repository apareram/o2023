appIMC.exe: appIMC.o funGTK.o funC.o
	gcc -o appIMC.exe appIMC.o funGTK.o funC.o `pkg-config --libs gtk+-2.0`

appIMC.o: appIMC.c funGTK.c funC.c
	gcc -c appIMC.c funGTK.c funC.c `pkg-config --cflags gtk+-2.0`

clean: 
	rm *.o