#include "defTipos.h"

extern int retotnatValor(char nomArch[])
{
    FILE *fp;
    int tamArch, num;

    fp = fopen(nomArch, "r+b");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    tamArch = ftell(fp);
    num = tamArch/sizeof(tipoAlumno);
    fclose(fp);

    return num;
}

extern int imprimirEnPantallaBin(char nomArch[])
{
    tipoAlumno alumno, *ptAlumno;
    FILE *fp;
    int numAlumnos = 0;

    fp = fopen(nomArch, "r+b");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    printf("\nImprimiendo los datos del archivo binario\n");
    while(fread(&alumno, sizeof(tipoAlumno), 1, fp) == 1)
    {
        ptAlumno = &alumno;
        printf("\nCuenta: %d\nAlumno: %s\nCarrera: %s\n", alumno.numCta, ptAlumno->nombre, alumno.carrera);
        printf("Fecha de nacimiento: %i/%i/%i\n", alumno.fecha.dia, alumno.fecha.mes, ptAlumno->fecha.ano);
        printf("Promedio: %f\n", ptAlumno->promedio);
        numAlumnos++;
    }
    printf("\nArchivo contiene %d alumnos.\n", numAlumnos);
    fclose(fp);

    return numAlumnos;
}

extern void actualizarDatos(tipoAlumno *alumno)
{
    printf("\nIngrese los datos que desea actualizar.\n");
    printf("\nDame la cuenta: \n");
    scanf(" %d", &alumno->numCta);
    printf("\nDame el nombre: \n");
    scanf(" %[^\n]", alumno->nombre);
    printf("\nDame la carrera: \n");
    scanf(" %[^\n]", alumno->carrera);
    printf("\nDame la fecha de nacimiento (dd/mm/aaaa): \n");
    scanf("%d/%d/%d", &alumno->fecha.dia, &alumno->fecha.mes, &alumno->fecha.ano);
    printf("\nDame el promedio: \n");
    scanf(" %f", &alumno->promedio);
    return;
}

extern void actualizarAlumno(int pos, char nomArch[])
{
    FILE *fp;
    int tam, numAlumnos;
    tipoAlumno alumno;

    actualizarDatos(&alumno);

    fp = fopen(nomArch, "r+b");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    fseek(fp, (pos-1)*sizeof(tipoAlumno), SEEK_SET);
    fwrite(&alumno, sizeof(tipoAlumno), 1, fp);
    fclose(fp);
    return ;
}