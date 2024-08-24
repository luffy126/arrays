#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxArreglo 5000

struct AFP{
    char *nombreGerente;
    struct Retiro **retiros;
};

struct Retiro{
    char *rut;
    char *nombre;
    char *nombreAFP;
    int montoRetirado;
};

// dar memoria a la estructura de datos de las afp

struct AFP * crearRegistro(int max, char *nombreGerente) {
    struct AFP * afp; // inicia la estructura de la afp

    afp = (struct AFP *)malloc(sizeof(struct AFP));
    afp->nombreGerente = (char *)malloc(sizeof(char) * strlen(nombreGerente) + 1);
    strcpy(afp->nombreGerente, nombreGerente);

    afp->retiros = (struct Retiro **)malloc(sizeof(struct Retiro *) * max);

    for (int i = 0; i < max; i++) {
        afp->retiros[i] = NULL; // inicializa la memoria de cada espacio del arreglo con null
    }
    return afp;
}

// escanear los retiros

struct Retiro * crearNuevoRetiro(char *rut, char *nombre, char *nombreAFP, int montoRetirado) { // asigna memoria a cada dato del nuevo retiro
    struct Retiro *nuevoRetiro;

    nuevoRetiro = (struct Retiro *)malloc(sizeof(struct Retiro));

    nuevoRetiro->rut = (char *)malloc(sizeof(char) * strlen(rut) + 1);
    strcpy(nuevoRetiro->rut, rut);

    nuevoRetiro->nombre = (char *)malloc(sizeof(char) * strlen(nombre) + 1);
    strcpy(nuevoRetiro->nombre, nombre);

    nuevoRetiro->nombreAFP = (char *)malloc(sizeof(char) * strlen(nombreAFP) + 1);
    strcpy(nuevoRetiro->nombreAFP, nombreAFP);

    nuevoRetiro->montoRetirado = montoRetirado;
    return nuevoRetiro;
}

struct AFP *crearRetiros(struct AFP *afp, int cantidadRetiros, int *pLibre) {
    struct Retiro *nuevoRetiro;
    char rut[100], nombre[100], nombreAFP[100];
    int montoRetirado;
    for (int i = 0; i < cantidadRetiros; i++) {
        if (*pLibre >= maxArreglo) { // validación para no meter retiros de mas
            printf("no hay espacio para agregar mas retiros :(");
        } else {
            scanf("%s %s %s %d", rut, nombre, nombreAFP, &montoRetirado);
            nuevoRetiro = crearNuevoRetiro(rut, nombre, nombreAFP, montoRetirado);
            afp->retiros[*pLibre] = nuevoRetiro; // ingresar ese nuevo retiro al arreglo
            (*pLibre)++;
            printf("retiro agregado exitosamente.\n");
        }
    }
    return afp;
}

// buscar los retiros asociados a un rut

int cantidadRetirosAfiliado(struct Retiro **retiros, char *rut) {
    int cantidad = 0;
    for (int i = 0; i < maxArreglo; i++) {
        if (retiros[i] != NULL && strcmp(retiros[i]->rut, rut) == 0) {
            cantidad++;
        }
    }
    return cantidad;
}

int main(void) {
    struct AFP *afp;
    int max = maxArreglo;
    int cantidadRetiros, retirosAfiliado;
    int pLibre = 0;
    char nombreGerente[100], rutBuscado[100];

    scanf("%s", nombreGerente);
    afp = crearRegistro(max, nombreGerente);
    scanf("%d", &cantidadRetiros);
    if (cantidadRetiros < 0 || cantidadRetiros > max) {
        printf("ingrese una cantidad valida");
    }
    else {
        afp = crearRetiros(afp, cantidadRetiros, &pLibre);
        scanf("%s", rutBuscado);
        retirosAfiliado = cantidadRetirosAfiliado(afp->retiros, rutBuscado);
        printf("%d\n", retirosAfiliado);

        printf("Hello, World!\n");
    }
    return 0;
}