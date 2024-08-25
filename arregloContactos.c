#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contacto {
    int numero;
    char *nombre;
    char *correo;
    char *ubicacion;
};

struct arregloContactos {
    int pLibre;
    int maxContactos;
    struct Contacto **contactos;
};

struct arregloContactos *crearRegistro(int cantidadContactos) {
    struct arregloContactos *contactos;
    int i;

    contactos = (struct arregloContactos *) malloc(sizeof(struct arregloContactos));
    contactos->pLibre = 0;  
    contactos->maxContactos = cantidadContactos;
    contactos->contactos = (struct Contacto **) malloc(cantidadContactos * sizeof(struct Contacto *));
    for (i = 0; i < cantidadContactos; i++) {
        contactos->contactos[i] = NULL;
    }
    return contactos;
}

struct Contacto *crearContacto(int numero, char *nombre, char *correo, char *ubicacion) {
    struct Contacto *nuevoContacto;
    nuevoContacto = (struct Contacto *) malloc(sizeof(struct Contacto));
    nuevoContacto->numero = numero;

    nuevoContacto->nombre = (char *) malloc((strlen(nombre) + 1) * sizeof(char));
    strcpy(nuevoContacto->nombre, nombre);

    nuevoContacto->correo = (char *) malloc((strlen(correo) + 1) * sizeof(char));
    strcpy(nuevoContacto->correo, correo);

    nuevoContacto->ubicacion = (char *) malloc((strlen(ubicacion) + 1) * sizeof(char));
    strcpy(nuevoContacto->ubicacion, ubicacion);

    return nuevoContacto;
}

int agregarContacto(struct arregloContactos *contactos, struct Contacto *nuevoContacto) {
    if (contactos->pLibre >= contactos->maxContactos) {
        printf("no hay espacio para meter tu nuevo contacto =(\n");
        return 0;
    }
    contactos->contactos[contactos->pLibre] = nuevoContacto;
    contactos->pLibre++;
    return 1;
}

struct Contacto *quitarContacto(struct arregloContactos *contactos, char *nombreAQuitar) {
    struct Contacto *aux;
    int i, j;
    aux = NULL;
    for(i = 0; i < contactos->pLibre; i++) {
        if(strcmp(nombreAQuitar, contactos->contactos[i]->nombre) == 0) {
            aux = crearContacto(contactos->contactos[i]->numero, contactos->contactos[i]->nombre, contactos->contactos[i]->correo, contactos->contactos[i]->ubicacion);
            contactos->contactos[i] = NULL;
            for (j = i; j < contactos->pLibre - 1; j++) {
                contactos->contactos[j] = contactos->contactos[j + 1];
            }
            contactos->contactos[contactos->pLibre - 1] = NULL;
            contactos->pLibre--;
            return aux;
        }
    }
    return aux;
}

int main() {
    struct arregloContactos *contactos;
    struct Contacto *nuevoContacto, *contactoQuitado;
    int numero, i, resultado;
    char nombre[20], correo[50], ubicacion[30], nombreAQuitar[20];
    int cantidadContactos = 5;

    contactos = crearRegistro(cantidadContactos);
    for (i = 0; i < cantidadContactos; i++) {
        scanf("%d %s %s %s", &numero, nombre, correo, ubicacion);
        nuevoContacto = crearContacto(numero, nombre, correo, ubicacion);
        printf("contacto creado con exito\n");
        resultado = agregarContacto(contactos, nuevoContacto);
        if (resultado == 1) {
            printf("contacto agregado con exito =)\n");
        } else {
            printf("no se pudo agregar el contacto =(\n");
        }
    }

    scanf("%s", nombreAQuitar);

    contactoQuitado = quitarContacto(contactos, nombreAQuitar);

    if(contactoQuitado == NULL) {
        printf("no se encontro el contacto que quisiste quitar =(\n");
    } else {
        printf("el contacto q quitaste es este: %d %s %s %s", contactoQuitado->numero, contactoQuitado->nombre, contactoQuitado->correo, contactoQuitado->ubicacion);
    }

    return 0;
}
