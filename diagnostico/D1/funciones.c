 #include <stdio.h>
#include <string.h>

 extern void contVoc(int argc, char *argv[])
 {
    int i, j, voc, cont;
    char pal[100];
    i=1;
    cont=0;
    sscanf(argv[i], " %s[^\n]", pal);

    for(j = 0; j <= strlen(pal); j++)
    {
        if((pal[j] == 97) || (pal[j] == 101) || (pal[j] == 105) 
        || (pal[j] == 111) || (pal[j] == 117))
        {
            cont++;
        }
                
        if((pal[j] > 65) && (pal[j] < 90))
        {
            printf("\nLa palabra no puede tener mayusculas");

        }
            
    }
    printf("\n%s %i\n", pal, cont);
    i++; 
    cont = 0;
 }
