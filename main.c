#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS = 10000
#define MAX_ADMINS = 20

#define MAX_A = 1000
#define MAX_B = 500
#define MAX_C = 50

struct INFTube {
    struct Usuario **usuarios;
    struct Admin **administradores;
};

struct Usuario {
    int id;
    char *username;
    char tipoCuenta;
    struct Video **videosSubidos;
    int cantVideosSubidos;
    int infracciones;
};

struct Admin {
    int id;
    char *username;
    int nivelAcceso;
    struct Video **videosModerados;
    int cantVideosModerados;
};

struct Video {
    int id;
    char *nombreVideo;
    char *fechaPublicacion;
    char *tipoContenido;
    int segundos;
    int minutos;
    int comentarios;
    char *estadoVideo;
};

int compararInfraccion(char *estadoVideo) {
    char infraccion[] = "infraccion";
    if(strcmp(infraccion, estadoVideo) == 0) {
        return 1;
    }
    return 0;
}

void quitarVideosInfraccion(struct INFTube *itube) {
    int tieneInfraccion, i, j;

    if (itube != NULL) {
        for (i = 0; itube->usuarios[i] != NULL && i < 10000; i++) {
            for (j = 0; itube->usuarios[i]->videosSubidos[j] != NULL && j < itube->usuarios[i]->cantVideosSubidos; j++) {
                tieneInfraccion = compararInfraccion(itube->usuarios[i]->videosSubidos[j]->estadoVideo);

                if (tieneInfraccion == 1) {
                    itube->usuarios[i]->videosSubidos[j] = NULL;
                    itube->usuarios[i]->infracciones += 1;
                }
            }
            if (itube->usuarios[i]->infracciones > 3) {
                itube->usuarios[i] = NULL;
            }
        }
    }
}

int main() {
    struct INFTube *itube;
    printf("Hello, World!\n");
    return 0;
}
