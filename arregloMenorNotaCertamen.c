#include <stdio.h>
#include <stdlib.h>
#define MAXCURSOS 500


struct Curso {
    char *sigla;
    char *nombreProfesor;
    int cantCreditos;
    int cantCertamenes;
    struct Certamen ** pruebas;
};

struct Certamen {
    char *nombre;
    char *tema;
    char *fecha;
    int nota;
};

int compararNotas(int menorNotaSistema, int nota) {
    if(nota < menorNotaSistema) {
        return 1;
    } else {
        return 0;
    }
}

struct Certamen *menorNotaGlobal(struct Curso ** cursos) {
    struct Certamen *aux = NULL;
    int menorNotaSistema, indiceMenorNota, cursoMenorNota, esMenor, i, j;
    if (cursos[0] != NULL && cursos[0]->pruebas[0] != NULL) {
        aux = (struct Certamen *) malloc (sizeof(struct Certamen));
        menorNotaSistema = cursos[0]->pruebas[0]->nota;
        indiceMenorNota = 0;
        cursoMenorNota = 0;
    }
    for(i = 0; cursos[i] != NULL; i++) {
        for(j = 0; cursos[i]->pruebas[j] != NULL; j++) {
            esMenor = compararNotas(menorNotaSistema, cursos[i]->pruebas[j]->nota);
            if (esMenor == 1) {
                menorNotaSistema = cursos[i]->pruebas[j]->nota;
                indiceMenorNota = j;
                cursoMenorNota = i;
            }
        }
    }
    aux = cursos[cursoMenorNota]->pruebas[indiceMenorNota];
    return aux;
}

int main() {
    struct Curso **cursos;
    printf("Hello, World!\n");
    return 0;
}
