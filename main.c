#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Remedio {
    int precio;
    int codigo;
    char *nombre;
};

struct nodoRemedio {
    struct Remedio *remedios;
    struct nodoRemedio *sig;
};

struct Remedio *crearRemedio(int precio, int codigo, char *nombre) {
    struct Remedio *nuevoRemedio;
    nuevoRemedio = (struct Remedio *) malloc (sizeof(struct Remedio));

    nuevoRemedio->nombre = (char *) malloc (sizeof(char) * strlen(nombre));
    strcpy(nuevoRemedio->nombre, nombre);
    nuevoRemedio->codigo = codigo;
    nuevoRemedio->precio = precio;

    return nuevoRemedio;
}

int agregarRemedioLista(struct nodoRemedio **listaepica, struct Remedio *nuevoRemedio) {
    struct nodoRemedio *nodoNuevo, *rec;
    if(*listaepica == NULL) {
        nodoNuevo = (struct nodoRemedio *) malloc(sizeof (struct nodoRemedio));
        nodoNuevo->remedios = nuevoRemedio;
        nodoNuevo->sig = NULL;
        *listaepica = nodoNuevo;
        return 1;
    }

    else {
        rec = *listaepica;
        while (rec->sig != NULL) {
            rec = rec->sig;
        }
        nodoNuevo = (struct nodoRemedio *) malloc(sizeof (struct nodoRemedio));
        nodoNuevo->remedios = nuevoRemedio;
        nodoNuevo->sig = NULL;
        rec->sig = nodoNuevo;
        return 1;
    }
    return 0;
}

int main(){
    struct nodoRemedio *listaepica = NULL;
    struct Remedio *nuevoRemedio;
    int cantidadRemedios, i, precio, codigo;
    char nombre[20];

    printf("ingrese cantidad de remedios\n");
    scanf("%d", &cantidadRemedios);
    for(i = 0; i < cantidadRemedios; i++){
        printf("ingrese precio codigo y nombre\n");
        scanf("%d %d %s", &precio, &codigo, nombre);
        nuevoRemedio = crearRemedio(precio, codigo, nombre);
        printf("remedio creado\n");
        agregarRemedioLista(&listaepica, nuevoRemedio);
        printf("remedio agregado a la lista\n");
    }
    printf("el pepe");
    return 0;
}