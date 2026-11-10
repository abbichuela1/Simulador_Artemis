#include <stdio.h>
#include <math.h>
#include "artemis.h"

void inicializarNave(EstadoNave *nave) {
    nave->tiempo_actual = 0.0;
    nave->altitud = 0.0;
    nave->velocidad = 0.0;
    nave->aceleracion_max = 0.0;
}

void simularFase1(EstadoNave *nave) {
    printf("\n--- INICIANDO FASE 1: ASCENSO SRB ---\n");
    
    // MRUV: v = v0 + a*t
    nave->velocidad += ACEL_FASE1 * TIEMPO_FASE1;
    
    // MRUV: y = y0 + v0*t + 0.5*a*t^2
    nave->altitud += 0.5 * ACEL_FASE1 * pow(TIEMPO_FASE1, 2);
    nave->tiempo_actual += TIEMPO_FASE1;
    
    // Registro de aceleracion maxima (inciso d)
    if (ACEL_FASE1 > nave->aceleracion_max) {
        nave->aceleracion_max = ACEL_FASE1;
    }
    
    printf("> Desacople SRB completado a los %.1f s.\n", nave->tiempo_actual);
    printf("> Altitud actual: %.2f m\n", nave->altitud);
    printf("> Rapidez actual: %.2f m/s\n", nave->velocidad);
}
void simularFase2(EstadoNave *nave) {
    printf("\n--- INICIANDO FASE 2: NUCLEO PRINCIPAL ---\n");
    float distancia_restante = ALTURA_CORTE - nave->altitud;
    
    // Despejando V_f de: Vf^2 = Vi^2 + 2*a*d
    float velocidad_cuadrado = pow(nave->velocidad, 2) + 2 * ACEL_FASE2 * distancia_restante;
    nave->velocidad = sqrt(velocidad_cuadrado);
    
    // Metodo directo usando velocidad anterior para calcular el tiempo
    float velocidad_anterior = sqrt(velocidad_cuadrado - 2 * ACEL_FASE2 * distancia_restante);
    nave->tiempo_actual += (nave->velocidad - velocidad_anterior) / ACEL_FASE2;
    nave->altitud = ALTURA_CORTE;

    printf("> Motores principales apagados en altitud de diseno: %.1f m.\n", nave->altitud);
    printf("> Rapidez maxima alcanzada: %.2f m/s\n", nave->velocidad);
}

void simularFallaMotor(EstadoNave *nave) {
    printf("\n--- SIMULACION DE FALLA CRITICA A 160 KM ---\n");
    // Caida libre: Vf = 0 en el punto mas alto. 0 = Vi^2 - 2*g*d -> d = Vi^2 / (2*g)
    float distancia_inercia = pow(nave->velocidad, 2) / (2 * GRAVEDAD);
    float altitud_maxima = nave->altitud + distancia_inercia;
    
    printf("> Motores fallaron. La nave sigue ascendiendo por inercia.\n");
    printf("> Altitud maxima alcanzada (H_max): %.2f m\n", altitud_maxima);
}

void imprimirReporte(EstadoNave nave) {
    printf("\n========================================\n");
    printf("      REPORTE FINAL DE LA MISION        \n");
    printf("========================================\n");
    printf("Tiempo total simulado: %.2f s\n", nave.tiempo_actual);
    printf("Altitud final: %.2f m\n", nave.altitud);
    printf("Fuerza G Maxima experimentada: %.2f G\n", nave.aceleracion_max / GRAVEDAD);
    printf("========================================\n\n");
}