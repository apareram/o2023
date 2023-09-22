#include "defTipos.h"

extern void capturarAlumnos(int tam, tipoAlumno grupo[])
{
    int i;

    for(i=0; i < tam; i++)
    {
        printf("\nDame la cuenta: \n");
        scanf(" %d", &grupo[i].numCta);
        printf("\nDame el nombre: \n");
        scanf(" %[^\n]", grupo[i].nombre);
        printf("\nDame la carrera: \n");
        scanf(" %[^\n]", grupo[i].carrera);
        printf("\nDame la fecha de nacimiento (dd/mm/aaaa): \n");
        scanf("%d/%d/%d", &grupo[i].fecha.dia, &grupo[i].fecha.mes, &grupo[i].fecha.ano);
        printf("\nDame el promedio: \n");
        scanf(" %f", &grupo[i].promedio);
    }

    return;
}

extern void imprimirAlumnos(int tam, tipoAlumno grupo[])
{
    int i;
    printf("\nImprimiendo los datos del arreglo grupo\n");
    for(i=0; i < tam; i++)
    {
        printf("\n%d.- %i %s %s ", i+1, grupo[i].numCta, grupo[i].nombre, grupo[i].carrera);
        printf("%d/%d/%d ", grupo[i].fecha.dia, grupo[i].fecha.mes, grupo[i].fecha.ano);
        printf("%f\n", grupo[i].promedio);
    }
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

extern int guardarArchText(int tam, tipoAlumno grupo[])
{
    int guardados = 0, i = 0;
    FILE *fp;

    fp = fopen("lista.txt", "w");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    for(i=0; i < tam; i++)
    {
        fprintf(fp, "%i\t", grupo[i].numCta);
        fprintf(fp, "%s\t", grupo[i].nombre);
        fprintf(fp, "%s\t", grupo[i].carrera);
        fprintf(fp, "%i/%i/%i\t", grupo[i].fecha.dia, grupo[i].fecha.mes, grupo[i].fecha.ano);
        fprintf(fp, "%f\n", grupo[i].promedio);
    }
    fclose(fp);

    return guardados;
}

extern int guardarArchBin(int tam, tipoAlumno grupo[])
{
    int guardados = 0, i;
    FILE *fp;

    fp = fopen("lista.bin", "w+b");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    for(i=0; i < tam; i++)
    {
        fwrite(&grupo[i], sizeof(tipoAlumno), 1, fp);
    }
    fclose(fp);
    guardados = i;
    
    return guardados;
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

extern void cargarBinMem(tipoAlumno grupo[], int tam, char nomArch[])
{
    int i;
    FILE *fp;
    
    fp = fopen(nomArch, "r+b");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    for(i=0; i<tam; i++)
    {
        fread(&grupo[i], sizeof(tipoAlumno), 1, fp);
    }
    fclose(fp);
    
    return;
}

extern int contarAlumnosTxt(char nomArch[])
{
    int tam = 0;
    char renglon[200];
    tipoAlumno alumno;
    FILE *fp;

    fp = fopen(nomArch, "r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    while(fscanf(fp, " %[^\n]", renglon) == 1)
    {
        tam++;
    }
    fclose(fp);

    return tam;
}

extern void cargarTxtMEm(tipoAlumno grupo[], int tam, char nomArch[])
{
    int i;
    FILE *fp;

    fp = fopen(nomArch, "r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    for(i=0; i<tam; i++)
    {
        fscanf(fp, "%i\t", &grupo[i].numCta);
        fscanf(fp, " %[^\t]", grupo[i].nombre);
        fscanf(fp, " %[^\t]", grupo[i].carrera);
        fscanf(fp, "%i/%i/%i\t", &grupo[i].fecha.dia, &grupo[i].fecha.mes, &grupo[i].fecha.ano);
        fscanf(fp, "%f\n", &grupo[i].promedio);
    }
    fclose(fp);

    return;
}