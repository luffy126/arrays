#include <stdio.h>
#include <stdlib.h>

#define maxArreglo 1000

struct Equipo {
    int id;
    char *nombre;
    char *nombreDirector;
    int pLibre;
    struct Auto **autos;
};

struct Auto {
    int numero;
    char *nombrePiloto;
    int cantidadVictorias;
};

int getGanadores(struct Equipo **equipos) {
    int contador = 0;
    int i, j;

    for (i = 0; i < maxArreglo; i++) {
        if (equipos[i] != NULL) {
            for (j = 0; j < equipos[i]->pLibre; j++) {
                if (equipos[i]->autos[j]->cantidadVictorias > 0) {
                    contador += 1;
                    break;
                }
            }
        }
    }
    return contador;
}

struct Auto *getGanador(struct Auto **arregloAutos, int pLibre) {
    int i;
    struct Auto *autoGanador;
    autoGanador = arregloAutos[0];

    for (i = 0; i < pLibre; i++) {
        if(arregloAutos[i]->cantidadVictorias > autoGanador->cantidadVictorias) {
            autoGanador = arregloAutos[i];
        }
    }

    if (autoGanador->cantidadVictorias == 0) {
        return NULL;
    }
    return autoGanador;
}

struct Auto **getAutosGanadoresPorEquipo(struct Equipo **equipos) {
    struct Auto **arregloGanadores = NULL;
    struct Auto *autoGanador;
    int cantEquiposGanadores, i, j = 0;

    if (equipos == NULL) {
        return arregloGanadores;
    }

    cantEquiposGanadores = getGanadores(equipos);
    if (cantEquiposGanadores == 0) {
        return arregloGanadores;
    }

    arregloGanadores = (struct Auto **) malloc(cantEquiposGanadores * sizeof(struct Auto *));

    for (i = 0; i < cantEquiposGanadores; i++) {
        if (equipos[i] != NULL) {
            autoGanador = getGanador(equipos[i]->autos, equipos[i]->pLibre);
            if (autoGanador != NULL) {
                arregloGanadores[j] = autoGanador;
                j++;
            }
        }
    }
    return arregloGanadores;
}
int main(void) {
    printf("Hello, World!\n");
    return 0;
}
