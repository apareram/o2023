ventana.out: ventana.o 
  gcc -o ventana.exe menu.o `pkg,config --libs gtk+-2.0` 
menu.o: ventana.c 
  gcc -c ventana.c `pkg,config --cflags gtk+-2.0` 
clean: 
  rm *.o