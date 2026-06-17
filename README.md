# [SISTEMA DE CONTROL TERMIC]
> **Asignatura:** Electrónica Digital [III] - Universidad Nacional de Córdoba
> **Integrantes:** > * Almada Joaquin
> * Sacchi Matias Leonel
> **Profesor:** [Blasco Marcos Javier]

---

## 🚀 1. Descripción General del Proyecto
Nuestro proyecto consiste en un sistema de control termico que, dada una habitacion cerrada el sistema debera mantener la temeparatura en un rango 
de entre 20 y 30 °C mediante el uso de sensores y una lampara, adicionalmente cuenta con un ventilador para alterar el flujo de aire en el interior
y estudiar el cambio de te temperatura con/sin la influencia del mismo

### 🎯 Alcances del Proyecto (¿Qué hace y qué NO hace el sistema?)
Delimiten claramente los objetivos alcanzados para la entrega final:
* **El sistema SÍ es capaz de:** [Medir temperatura, activar un cooler y transmitir los datos por UART cada 1 segundo].
* **El sistema NO incluye (Fuera de alcance):** [Encender el ventilador y lampara de manera automatica, guardar registros de los sensores en pc].

### ⏩ Posibles Etapas Siguientes (Líneas Futuras)
Planteen cómo escalaría este desarrollo en una versión 2.0 o en un ámbito profesional:
* [Migrar el circuito a una plataforma mas economica (ESP32) ].
* [Implementar modos de bajo consumo (Sleep) administrados por hardware para permitir el uso de baterías].
* [Diseñar una interfaz gráfica (GUI) en HTML5 o una app móvil para la visualización remota de las variables].

---

## 📐 2. Arquitectura del Sistema: Hardware y Software (Común)

### 🔌 Hardware & Interconexión
* **Diagrama de Bloques:** [Insertar imagen o link al diagrama de bloques del hardware]
* **Esquemático del Circuito:** *[Inserte aquí la captura de imagen/render del esquemático completo desarrollado en KiCad/Altium]*
  `![Esquemático Completo](hardware/esquematico.png)`
* **Descripción del Circuito y Consideraciones de Diseño:** Breve explicación de las etapas (ej: acoplamiento de señales, protecciones inductivas, filtrado, etc.).

### 💻 Arquitectura de Software (Firmware)
* **Diagrama de Flujo o Máquina de Estados:** *[Inserte aquí la imagen del diagrama que explique el lazo principal o el comportamiento del sistema]*
  `![Diagrama de Flujo / Máquina de Estados](docs/diagrama_software.png)`

---

## ⚡ 3. Especificaciones Eléctricas, Alimentación y Entorno (Específico por Asignatura)

### 🔌 Parámetros de Alimentación y Consumo (Común a ambas materias)
* **Tensión de operación del sistema:** [5V / 12V]
* **Método de alimentación:** [Fuente externa de 12V con regulador lineal LM7805 / Alimentación por USB]
* **Consumo estimado o medido:** * En modo activo: `~4,62 A`


### 📌 [Cortex-M / ARM]
* **IDE y SDK:** [Ej: MCUXpresso IDE v11.8 con LPCOpen v2.10 / STM32CubeIDE v1.14 con HAL v1.28].
* **Microcontrolador Principal:** [Ej: NXP LPC1769 / STM32F411].
* **Bibliotecas de Terceros y Versiones:** [Ej: FreeRTOS v10.5.1 / Biblioteca LCD I2C v1.2].
* **Periféricos Avanzados Utilizados:** [Ej: NVIC, DMA, SysTick, DAC].
* **Estrategia de Concurrencia:** Expliquen la arquitectura elegida: [RTOS: EL programa ejecuta secuencialmente todo el proceso,
* los actuadores se ejecutan por software pero de activacion manual (requiere interaccion del usuario)].

---

## 🔄 4. Proceso de Integración y Desarrollo (Común)
Describan cronológicamente cómo fueron sumando y testeando las diferentes partes del proyecto (enfoque modular de ingeniería).

* **Etapa 1 (Validación inicial):** [Ej: Configuración del oscilador/reloj y parpadeo de LED de estado].
* **Etapa 2 (Adquisición/Comunicación):** [Ej: Implementación del ADC y envío de tramas crudas por UART].
* **Etapa 3 (Integración lógica):** [Ej: Procesamiento de datos, lógica de control o montado sobre el RTOS].
* **Etapa 4 (Sistema Completo):** [Ej: Acople de actuadores finales, calibración y pruebas de estrés].

---

## 📊 5. Ensayos, Pruebas y Resultados (Común)
Demuestren con datos empíricos que el sistema funciona correctamente. **Es obligatorio incluir registro visual**.

* **Pruebas Funcionales Realizadas:** Detallen los ensayos (Ej: "Se inyectó una señal controlada para medir la precisión del ADC...").
* **Evidencia Fotográfica y Gráficos:** * *Capturas de instrumental:* [Insertar capturas de Osciloscopio, Analizador Lógico o Terminal Serie]
  * *Foto del Prototipo Real:* [Insertar foto del hardware final cableado/armado en funcionamiento]

---

## 📂 6. Estructura del Repositorio (Común)
El repositorio debe mantener obligatoriamente la siguiente estructura limpia (¡Recuerden configurar correctamente el `.gitignore` para no subir carpetas temporales como `Debug/`, `Release/` o archivos `.p1` / `.d`!).

```text
├── firmware/          # Código fuente del proyecto (MPLABX / MCUXpresso / STM32Cube)
│   ├── src/           # Archivos de código (.c)
│   └── inc/           # Archivos de cabecera (.h)
├── hardware/          # Archivos de diseño (KiCad/Altium), esquemáticos en PDF/Imagen y BOM
├── docs/              # Datasheets clave, imágenes del README, notas de aplicación
└── README.md          # Este archivo de presentación
