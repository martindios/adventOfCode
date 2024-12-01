#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Para el quicksort*/
int comparar(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main(int argc, char **argv) {
    /*Declaración e inicialización de variables*/
    FILE *archivo;
    char linea[32];
    int lista1[1000], lista2[1000];
    int n = sizeof(lista1) / sizeof(lista1[0]), resultado = 0;

    /*Apertura del archivo*/
    archivo = fopen("input.txt", "r");
    if (archivo == NULL) {
        perror("Error abriendo el archivo\n");
        exit(1);
    }

    /*Guardar en las listas los datos*/
    for(int i = 0; fgets(linea, sizeof(linea), archivo); i++) {
        sscanf(linea, "%d %d", &lista1[i], &lista2[i]);
    }

    /*Ordenar mediante quicksort*/
    qsort(lista1, n, sizeof(int), comparar);
    qsort(lista2, n, sizeof(int), comparar);

    /*Calcular el resultado*/
    for(int i = 0; i < n; i++) {
        resultado += abs(lista1[i] - lista2[i]);
    }

    printf("El resultado es: %d\n", resultado);
}
