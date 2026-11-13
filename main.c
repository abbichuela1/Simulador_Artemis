#include <stdio.h>
#include <stdlib.h>
#include "artemis.h"
#include "validaciones.h"
int main() {
    EstadoNave orion;
    int opcion;
    int etapa_actual = 1;

    inicializarNave(&orion);

    printf("Bienvenido al Centro de Control de Artemis.\n");

    do {
        printf("\n==== SIMULADOR MISION ARTEMIS (SLS) ====\n");
        if (etapa_actual == 1) printf("1. Ejecutar Fase 1 (Despegue y Desacople SRB)\n");
        if (etapa_actual == 2) printf("2. Ejecutar Fase 2 (Aceleracion de Nucleo)\n");
        if (etapa_actual == 3) printf("3. Simular Falla de Motor (Inercia y Caida Libre)\n");
        if (etapa_actual == 3) printf("4. Finalizar Mision Exitosamente e Imprimir Reporte\n");
        printf("0. Abortar simulacion\n");
        
        opcion = leerOpcionMenu(0, 4);

        switch(opcion) {
            case 1:
                if (etapa_actual == 1) {
                    simularFase1(&orion);
                    etapa_actual = 2;
                }
                break;
            case 2:
                if (etapa_actual == 2) {
                    simularFase2(&orion);
                    etapa_actual = 3;
                }
                break;
            case 3:
                if (etapa_actual == 3) {
                    simularFallaMotor(&orion);
                }
                break;
            case 4:
                if (etapa_actual == 3) {
                    imprimirReporte(orion);
                    opcion = 0; // Para salir del bucle
                }
                break;
            case 0:
                printf("\nCerrando terminal del Centro Espacial...\n");
                break;
            default:
                printf("\nAccion no permitida en esta fase.\n");
        }
    } while (opcion != 0);

    return 0;
}
