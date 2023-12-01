#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NodoArbol {
    char nombre[50];
    float peso;
    float altura;
    float imc;
    struct NodoArbol *izquierda;
    struct NodoArbol *derecha;
};

struct NodoArbol* insertar(struct NodoArbol* nodo, char nombre[], float peso, float altura) {
    if (nodo == NULL) {
        struct NodoArbol* nuevoNodo = (struct NodoArbol*)malloc(sizeof(struct NodoArbol));
        strcpy(nuevoNodo->nombre, nombre);
        nuevoNodo->peso = peso;
        nuevoNodo->altura = altura;
        nuevoNodo->imc = peso / (altura * altura);
        nuevoNodo->izquierda = nuevoNodo->derecha = NULL;
        return nuevoNodo;
    }

    if (peso / (altura * altura) < nodo->imc) {
        nodo->izquierda = insertar(nodo->izquierda, nombre, peso, altura);
    } else if (peso / (altura * altura) > nodo->imc) {
        nodo->derecha = insertar(nodo->derecha, nombre, peso, altura);
    }

    return nodo;
}

void imprimirArbol(struct NodoArbol* nodo) {
    if (nodo != NULL) {
        imprimirArbol(nodo->izquierda);
        printf("Nombre: %s, Peso: %.2f kg, Altura: %.2f m, IMC: %.2f\n", nodo->nombre, nodo->peso, nodo->altura, nodo->imc);
        imprimirArbol(nodo->derecha);
    }
}

void imprimirIMC(struct NodoArbol* nodo) {
    printf("\nIMC del paciente %s: %.2f\n", nodo->nombre, nodo->imc);

    if (nodo->imc > 25) {
        printf("El paciente tiene sobrepeso.\n");
    } else {
        printf("El paciente no tiene sobrepeso.\n");
    }
}

int main() {
    struct NodoArbol* usuario = NULL;

    char nombre[50];
    float peso, altura;

    printf("Ingrese su nombre: ");
    scanf(" %s", nombre);

    printf("Ingrese su peso en kilogramos: ");
    scanf(" %f", &peso); 

    printf("Ingrese su altura en metros: ");
    scanf(" %f", &altura);

    
    usuario = insertar(usuario, nombre, peso, altura);

   
    printf("\nDatos insertados en el arbol:\n");
    imprimirArbol(usuario);

    imprimirIMC(usuario);

    return 0;
}
