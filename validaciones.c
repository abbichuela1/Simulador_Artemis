#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"

// Limpia el buffer de entrada para evitar bucles infinitos al ingresar letras
void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

float leerFloatPositivo(const char *mensaje) {
    float valor;
    int leidos;
    do {
        printf("%s", mensaje);
        leidos = scanf("%f", &valor);
        limpiarBuffer();
        if (leidos != 1 || valor < 0) {
            printf("[!] Error: Ingrese un numero decimal positivo valido.\n");
        }
    } while (leidos != 1 || valor < 0);
    return valor;
}

int leerOpcionMenu(int min, int max) {
    int opcion, leidos;
    do {
        printf("\nSeleccione una opcion (%d-%d): ", min, max);
        leidos = scanf("%d", &opcion);
        limpiarBuffer();
        if (leidos != 1 || opcion < min || opcion > max) {
            printf("[!] Error: Opcion fuera de rango o invalida.\n");
        }
    } while (leidos != 1 || opcion < min || opcion > max);
    return opcion;
}
