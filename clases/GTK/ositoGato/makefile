imagenOsito.exe: imagenOsito.o 
	gcc -o imagenOsito.exe imagenOsito.o `pkg-config --libs gtk+-2.0`

imagenOsito.o: imagenOsito.c 
	gcc -c imagenOsito.c `pkg-config --cflags gtk+-2.0`

clean: 
	rm *.o