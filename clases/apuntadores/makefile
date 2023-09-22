#Este es un ejemplo para la compilación automática utilizando MAKE

#Para lograr mi objetivo del ejetucable apuntArreglo.exe hago esto

apuntArreglo.exe: apuntArreglo.o funciones.o 
	gcc apuntArreglo.o funciones.o -o apuntArreglo.exe

#Para lograr el objetivo del objeto de funciones.o hago esto:
funciones.o: funciones.c
	gcc -c funciones.c

#Para lograr el objetivo del objeto apuntArreglo.o hago esto:
apuntArreglo.o: apuntArreglo.c
	gcc -c apuntArreglo.c

