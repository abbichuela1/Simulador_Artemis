# Simulador de Misiones Artemis (Lenguaje C)

**Trabajo Práctico Integrador Final - Algoritmos y Estructuras de Datos**

### a) Integrantes y Comisión
* **Comisión:** [K1.2]
* **Integrantes:** 
  * [Galeano Zahira Abigail] - [30445]
  * [Rodriguez Antonella de los Angeles] - [30348]
  * [Sandoval Lautaro] - [31131]

### b) Escenario Asignado
**Situación - Problema 1: Ascenso y Propulsión con el SLS (MRUV y Desprendimiento)**
Simulación del despegue desde el Centro Espacial Kennedy de la nave Orion. Contempla la aceleración de los cohetes SRB (20.0 m/s²), el desacople a los 120s, la fase de aceleración del núcleo principal (12.5 m/s²) hasta los 160 km de altitud, y una simulación de falla crítica con cálculo de inercia y caída libre bajo la gravedad (9.80 m/s²).

### c) Detalle de Funcionamiento
El sistema es un simulador secuencial operado mediante un menú por consola. El usuario debe ejecutar las etapas cronológicamente. No es posible ejecutar la Fase 2 sin haber completado la Fase 1, ni calcular fallas sin llegar a la altitud de diseño. Se implementaron punteros para mutar el estado de la nave y paso por valor para la impresión del reporte final.

### d) Instrucciones de Compilación y Ejecución
Para compilar el proyecto mediante GCC en terminal:
`gcc main.c artemis.c validaciones.c -o simulador`

Para ejecutar en Windows:
`.\simulador.exe`

### e) Registro de uso de Inteligencia Artificial
* **Herramienta:** Google Gemini
* **Uso específico:** Asistencia como mentor y thought-partner para estructurar la modularización del proyecto en C (.h y .c), aplicar buenas prácticas en las validaciones del buffer (`limpiarBuffer`), y refactorizar cálculos físicos de MRUV para evitar redundancias.
* **Validación:** El código sugerido fue analizado en conjunto, probado paso a paso verificando el uso de punteros y structs exigidos por la rúbrica, y adaptado al menú secuencial.