#ifndef ARTEMIS_H
#define ARTEMIS_H

// Constantes físicas del problema
#define GRAVEDAD 9.80
#define ACEL_FASE1 20.0
#define TIEMPO_FASE1 120.0
#define ACEL_FASE2 12.5
#define ALTURA_CORTE 160000.0

// Estructura para mantener el estado de la nave
typedef struct {
    float tiempo_actual;
    float altitud;
    float velocidad;
    float aceleracion_max;
} EstadoNave;

// Prototipos de funciones de simulación
void inicializarNave(EstadoNave *nave);
void simularFase1(EstadoNave *nave);
void simularFase2(EstadoNave *nave);
void simularFallaMotor(EstadoNave *nave);
void imprimirReporte(EstadoNave nave);

#endif
