# [SISTEMA DE CONTROL TÉRMICO]

> **Asignatura:** Electrónica Digital III - Universidad Nacional de Córdoba
> **Integrantes:**
>
> * Joaquín Almada
> * Matías Leonel Sacchi
> * **Profesor:** Marcos Javier Blasco

---

# 1. Descripción General del Proyecto

El presente proyecto consiste en el desarrollo de un sistema de control térmico automático basado en un microcontrolador LPC1769. El objetivo es monitorear la temperatura de una cámara cerrada mediante tres sensores de temperatura LM335 y actuar sobre distintos elementos de control para mantener la temperatura dentro de un rango establecido.

El sistema realiza la adquisición periódica de datos de temperatura mediante el conversor analógico-digital (ADC), procesa las mediciones y genera una temperatura promedio representativa del ambiente. Asimismo, dispone de una interfaz UART para supervisión y control manual de los actuadores.

Para modificar las condiciones térmicas de la cámara se emplean una lámpara incandescente, utilizada como fuente de calor, y un ventilador que permite alterar la circulación del aire y acelerar los intercambios térmicos dentro del recinto.

Los valores medidos por los sensores son enviados periódicamente a una computadora mediante comunicación serie UART para facilitar la visualización y el monitoreo del sistema.

---

## Alcances del Proyecto

### El sistema SÍ es capaz de:

* Adquirir señales analógicas provenientes de tres sensores LM335.
* Convertir las mediciones mediante el ADC interno del LPC1769.
* Utilizar DMA para almacenar automáticamente las muestras adquiridas.
* Calcular el promedio de temperatura de los tres sensores.
* Generar una salida analógica mediante DAC proporcional a la temperatura promedio medida.
* Controlar una lámpara y un ventilador mediante salidas digitales.
* Comunicar datos de temperatura mediante UART.
* Permitir el accionamiento manual de los actuadores a través de comandos UART.
* Operar de forma autónoma sin necesidad de una computadora una vez programado.

### El sistema NO incluye (fuera de alcance)

* Registro permanente de datos en memoria no volátil.
* Comunicación inalámbrica (WiFi, Bluetooth o LoRa).
* Interfaz gráfica dedicada.
* Control PID o estrategias avanzadas de regulación.
* Supervisión remota mediante Internet.
* Almacenamiento histórico de mediciones.

---

## Posibles Etapas Futuras

Como continuación natural del proyecto se plantean las siguientes mejoras:

* Implementar un control automático completo de temperatura con histéresis.
* Incorporar algoritmos de control PID para mejorar la estabilidad térmica.
* Migrar el sistema a una plataforma con conectividad integrada como ESP32.
* Agregar almacenamiento de datos en tarjeta SD.
* Incorporar una pantalla LCD para visualización local.
* Implementar comunicación WiFi para monitoreo remoto.
* Desarrollar una aplicación móvil o interfaz web para supervisión en tiempo real.
* Incorporar modos de bajo consumo para funcionamiento mediante baterías.

---

#  2. Arquitectura del Sistema

##  Hardware e Interconexión

### Componentes principales

* Microcontrolador NXP LPC1769 (ARM Cortex-M3).
* Tres sensores de temperatura LM335.
* Lámpara utilizada como elemento calefactor.
* Ventilador para circulación de aire.
* Conversor DAC interno del microcontrolador.
* Interfaz UART para monitoreo y control.
* Fuente de alimentación externa.

### Funcionamiento general

Los sensores LM335 generan una tensión proporcional a la temperatura absoluta del ambiente.

Las señales analógicas son adquiridas por el ADC del LPC1769. El DMA transfiere automáticamente las muestras a memoria sin intervención del procesador, reduciendo la carga de CPU.

Una vez obtenidas las muestras, el firmware calcula la temperatura promedio de los tres sensores y actualiza una salida analógica mediante el DAC.

Los valores medidos son transmitidos mediante UART hacia una terminal serie en la computadora.

Los actuadores pueden accionarse mediante comandos enviados por UART:

| Comando | Acción              |
| ------- | ------------------- |
| L       | Encender lámpara    |
| l       | Apagar lámpara      |
| F       | Encender ventilador |
| f       | Apagar ventilador   |

### Diagrama de bloques


<img width="2172" height="724" alt="ChatGPT Image 18 jun 2026, 17_59_26" src="https://github.com/user-attachments/assets/26ad188c-72fa-49cf-82d3-f47b8ce54c8a" />


<img width="6593" height="1404" alt="Control Termico Automatico" src="https://github.com/user-attachments/assets/3e2aa226-214c-476c-9694-f913b710d1fa" />


<img width="3838" height="1674" alt="Control Termico Automatico(1)" src="https://github.com/user-attachments/assets/e48b9d09-3369-40cf-895f-5a5acd1e0248" /> 

---

## Arquitectura de Software

El firmware se encuentra organizado en módulos independientes:

### Plataforma

Implementación y configuración de periféricos:

* ADC
* DMA
* DAC
* Timer
* UART

### Núcleo del sistema

Procesamiento de datos:

* Cálculo de promedios
* Conversión ADC → Temperatura
* Gestión de buffers DMA

### Actuadores

Control de:

* Lámpara
* Ventilador

### Comunicación

* Recepción de comandos UART
* Envío de información de monitoreo

### Flujo principal

1. Inicialización de periféricos.
2. Inicio de conversiones ADC.
3. Transferencia de muestras mediante DMA.
4. Cálculo de temperatura promedio.
5. Actualización del DAC.
6. Envío de datos por UART.
7. Atención de comandos UART.

---

# 3. Especificaciones Eléctricas

## Alimentación

### Tensión de operación
* 12 V para la Lampara y el ventilador
* 5 V para sensores y actuadores.
* 3.3 V para el LPC1769.

### Método de alimentación

* Alimentación mediante USB para la placa LPC1769.
* Fuente externa para los actuadores.

### Consumo estimado

* Sistema electrónico: < 150 mA.
* Sistema completo con ventilador y lámpara: dependiente de la potencia instalada.

---

## Plataforma de Desarrollo

### Microcontrolador

* NXP LPC1769
* Arquitectura ARM Cortex-M3
* Frecuencia máxima: 100 MHz

### IDE

* MCUXpresso IDE

### Bibliotecas utilizadas

* CMSIS v2.00 LPC17xx
* Drivers LPC17xx

### Periféricos avanzados utilizados

* NVIC
* DMA
* ADC
* DAC
* UART
* Timers

### Estrategia de concurrencia

El sistema utiliza una arquitectura cooperativa basada en super-loop.

Las tareas principales se ejecutan secuencialmente dentro del ciclo principal mientras que las transferencias ADC y la comunicación UART utilizan interrupciones y DMA para minimizar la carga del procesador.

---

# 4. Proceso de Integración y Desarrollo

### Etapa 1 – Puesta en marcha

* Configuración del entorno de desarrollo.
* Validación de GPIOs.
* Control individual de lámpara y ventilador.

### Etapa 2 – Adquisición de datos

* Configuración del ADC.
* Lectura de sensores LM335.
* Conversión de muestras a temperatura.

### Etapa 3 – Optimización

* Implementación de DMA para adquisición automática.
* Procesamiento de buffers.
* Obtención de temperatura promedio.

### Etapa 4 – Comunicación

* Implementación de UART.
* Envío de temperaturas a PC.
* Recepción de comandos de control.

### Etapa 5 – Integración final

* Integración de sensores, actuadores y comunicaciones.
* Verificación del funcionamiento conjunto.
* Ensayos térmicos dentro de la cámara.

---

# 5. Ensayos, Pruebas y Resultados

## Pruebas funcionales realizadas

### Sensores

* Verificación individual de los tres LM335.
* Comparación de mediciones entre sensores.

### ADC

* Verificación de conversión correcta de tensiones.

### DMA

* Verificación de transferencia automática de muestras.

### UART

* Envío de temperaturas a terminal serie.
* Recepción de comandos de usuario.

### Actuadores

* Encendido y apagado individual de lámpara y ventilador.
* Verificación de respuesta a comandos UART.

## Evidencia a incorporar

* Fotografías del prototipo.
* Capturas de terminal serie.
* Capturas de osciloscopio.
* Curvas de temperatura obtenidas durante los ensayos.

---

# 6. Estructura de codigo

<img width="1608" height="1621" alt="Control Termico Automatico(2)" src="https://github.com/user-attachments/assets/86b6d04a-8c02-498a-8ea3-6df795faf59a" /> 

# 7. Estructura del Repositorio

```text
├
│   ├── src/
│   │   ├── actuators/
│   │   ├── communication/
│   │   ├── core/
│   │   ├── plataform/
│   │   └── thermal_control/
│   │
│   └── inc/
  
└── README.m
