#Este es un ejemplo para la compilación automática utilizando MAKE

#Para lograr mi objetivo del ejetucable formulas.exe hago esto

ejecutable1.exe: formulas.o funciones1.o funciones2.o
	gcc formulas.o funciones1.o funciones2.o -o ejecutable1.exe -lm

#Para lograr el objetivo del objeto de formulas.o hago esto:

formulas.o: formulas.c
	gcc -c formulas.c

#Para lograr el objetivo del objeto funciones1.o hago esto:
funciones1.o: funciones1.c
	gcc -c funciones1.c

#Para lograr el objetivo del objeto funciones2.o hago esto:
funciones2.o: funciones2.c
	gcc -c funciones2.c