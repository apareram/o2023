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
