# Simulador de Misiones Artemis (Lenguaje C)

**Trabajo Práctico Integrador Final - Algoritmos y Estructuras de Datos**

### a) Integrantes y comisión
* **Comisión:** [K1.2]
* **Integrantes:** 
  * [Galeano Zahira Abigail] - [30445]
  * [Rodriguez Antonella de los Angeles] - [30348]
  * [Sandoval Lautaro] - [31131]

### b) Escenario asignado
**Situación - Problema 1: Ascenso y Propulsión con el SLS (MRUV y Desprendimiento)**
Simulación del despegue desde el Centro Espacial Kennedy de la nave Orion. Contempla la aceleración de los cohetes SRB (20.0 m/s²), el desacople a los 120s, la fase de aceleración del núcleo principal (12.5 m/s²) hasta los 160 km de altitud, y una simulación de falla crítica con cálculo de inercia y caída libre bajo la gravedad (9.80 m/s²).

### c) Detalle de funcionamiento
El sistema es un simulador secuencial operado mediante un menú por consola. El usuario debe ejecutar las etapas cronológicamente. No es posible ejecutar la Fase 2 sin haber completado la Fase 1, ni calcular fallas sin llegar a la altitud de diseño. Se implementaron punteros para mutar el estado de la nave y paso por valor para la impresión del reporte final.

### d) Instrucciones de compilación y ejecución
Para compilar el proyecto mediante GCC en terminal:
`gcc main.c artemis.c validaciones.c -o simulador`

Para ejecutar en Windows:
`.\simulador.exe`

### e) Registro de uso de IA
* **Herramienta:** Google Gemini
* **Uso específico:** Asistencia como mentor socrático para estructurar la modularización del proyecto en C (.h y .c), aplicar buenas prácticas en las validaciones del buffer (`limpiarBuffer`), y refactorizar cálculos físicos de MRUV para evitar redundancias.
* **Prompts utilizados:** 1. *Para modularización:* "Actúa como mi mentor socrático de programación en C. Tengo la lógica de un simulador aeroespacial Artemis en un solo archivo monolítico y necesito modularizarlo. No me des el código resuelto; en su lugar, hazme preguntas guiadas para ayudarme a deducir qué variables, constantes y prototipos de structs deben ir en el archivo de cabecera (`artemis.h`) y qué implementaciones deben ir en el archivo fuente (`artemis.c`)."
* 2. *Para validación de la funcion buffer:* "Estoy programando un menú interactivo por consola en C usando `scanf`. Noté que cuando ingreso una letra en lugar de un número, el programa entra en un bucle infinito y se colapsa. Explícame por qué ocurre este comportamiento indefinido en la memoria y enséñame las mejores recomendaciones para implementar una función `limpiarBuffer` que descarte caracteres inválidos de forma segura."
  3. *Para remodelar y facilitar nuestro entendimiento de física:* "En la Fase 2 de mi simulador, estoy calculando la velocidad final y el tiempo de un MRUV despejando las fórmulas físicas estándar. Sin embargo, noto que estoy repitiendo cálculos redundantes (como la misma raíz cuadrada) en variables distintas. Actúa como revisor de código y ayúdame a refactorizar estas operaciones matemáticas en C para que el cálculo sea más directo, óptimo y sin redundancias." 
* **Validación:** El código sugerido fue analizado en conjunto, probado paso a paso verificando el uso de los punteros y structs exigidos por la rúbrica de la consigna, y adaptado al menú secuencial.
