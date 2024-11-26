# Ahorcado Game in C 🕹
![4](https://github.com/user-attachments/assets/d85d3b96-5058-46b3-b1dc-fdacc159c102)

*made by Wilder.C*
## Integrantes

- **Campero Jairo**
- **Nattes Choque Jose**
- **Champi Choque Wilder**
- **Mamani Alegre Alexis**

**Facultad de Ingeniería 2024**  
**Universidad Nacional de la Patagonia San Juan Bosco (UNPSJB)**  
___
## Contenido

1. **[Introducción](#1-introducción)**
2. **[Flujo del Programa](#2-flujo-del-programa)**
3. **[Estructura General del Proyecto](#3-estructura-general-del-proyecto)**
4. **[Detalles Tecnicos](#4-detalles-tecnicos)**
5. **[Asignación de Tareas](#5-asignación-de-tareas)**
6. **[Soluciones a la Compilación](#6-soluciones-a-la-compilación)**
7. **[Mejoras Propuestas](#7-mejoras-propuestas)**
---
## 1. Introducción

El juego clásico del **Ahorcado** fue desarrollado en forma grupal como parte del **Trabajo Integrador Final** de la asignatura **Algorítmica y Programación I** en la **Licenciatura en Informática** de la sede Puerto Madryn. El proyecto cuenta con funcionalidades como:

1. **Categorías de Palabras:** El juego incluye cinco categorías seleccionadas al azar: animales, frutas, geografía, países y objetos. Las palabras de cada categoría se leen de forma de archivos externos.

2. **Niveles de Dificultad:**
    - Normal: Hasta 6 intentos disponibles.
    - Difícil: Hasta 3 intentos disponibles.

3. **Interfaz de Consola Mejorada:**
    - Uso de colores y efectos visuales para mejorar la experiencia del usuario.
    - Dibujos progresivos del ahorcado según los errores cometidos.

4. **Puntuación y Ranking:**
El sistema guarda el rendimiento de cada jugador, ordena los puntajes y los presenta de forma visual al finalizar el juego.

5. **Buenas Prácticas de Programación:**
    - División del código en funciones claras y organizadas para facilitar su mantenimiento y comprensión.
    - Uso de estructuras (struct) para manejar los datos del jugador.
    - Implementación de un sistema de validación para entradas del usuario, como evitar letras repetidas y garantizar nombres válidos.

El código fuente está optimizado para ejecutarse en entornos de desarrollo integrados (IDEs) como [Visual Studio Code](https://code.visualstudio.com/), [CLion](https://www.jetbrains.com/clion/), y [Code::Blocks](http://www.codeblocks.org/).

---
## **2. Flujo del Programa**

### **1. Inicio:**
- Mostrar la interfaz inicial (`interface()`).
- Solicitar el nombre del jugador y mostrar las reglas del juego (`consigna()`).

### **2. Configuración de la Partida:**
- Configurar los datos iniciales del jugador (`configurarNuevaPartida()`).
- Seleccionar la dificultad (`seleccionarDificultad()`).
- Seleccionar una palabra al azar según la categoría (`seleccionar_categoria()` y `centro_mando()`).

### **3. Mecánica del Juego:**
- Iniciar las rondas de juego (`jugarRondas()`):
  - Validar letras ingresadas.
  - Actualizar el estado del ahorcado (`dibujar_ahorcado()` o `dibujar_ahorcado_2()`).
  - Incrementar o disminuir la puntuación según los aciertos y errores.

### **4. Gestión de Partidas:**
- Guardar los datos al finalizar la partida (`guardarDatosPartida()`).
- Preguntar al jugador si quiere continuar (`preguntarContinuar()`).

### **5. Mostrar Ranking:**
- Ordenar los datos de los jugadores (`ordenarDatos()`).
- Mostrar un ranking con las puntuaciones y detalles de los jugadores (`mostrarRanking()`).

### **6. Finalización:**
- Limpiar la pantalla y terminar el programa.
---
## 3. Estructura General del Proyecto

### **1.1 Introducción e Interfaz**
Solicitar el nombre del jugador, validarlo y mostrar las reglas del juego para preparar el inicio.

- [Documentación de **Introducción e Interfaz**](https://github.com/xjairooo/Ahorcado-Game-in-C/wiki/1.-Estructura-General-del-Proyecto#funci%C3%B3n-interface)

### **1.2 Configuración del Juego**
Maneja la configuración inicial, incluyendo la selección de categoría, dificultad, y la preparación de las variables necesarias para cada partida.

- [Documentación de **Configuracion del Juego**](https://github.com/xjairooo/Ahorcado-Game-in-C/wiki/1.-Estructura-General-del-Proyecto#12-configuraci%C3%B3n-del-juego)

### **1.3 Mecánica del Juego**
Controla la lógica principal del juego, como manejar rondas, registrar los intentos del jugador, actualizar puntuaciones y verificar el progreso.

- [Documentación de **Mecánica del Juego**](https://github.com/xjairooo/Ahorcado-Game-in-C/wiki/1.-Estructura-General-del-Proyecto#13-mec%C3%A1nica-del-juego)

### **1.4 Palabras y Categorías**
Gestiona la selección de palabras aleatorias desde archivos predefinidos según la categoría seleccionada.

- [Documentación de **Palabras y Categorías**](https://github.com/xjairooo/Ahorcado-Game-in-C/wiki/1.-Estructura-General-del-Proyecto#14-palabras-y-categor%C3%ADas)

### **1.5 Gestión de Partidas**
Almacena, organiza, y presenta los datos de las partidas jugadas, como puntuaciones y palabras adivinadas.

- [Documentación de **Palabras y Categorías**](https://github.com/xjairooo/Ahorcado-Game-in-C/wiki/1.-Estructura-General-del-Proyecto#15-gesti%C3%B3n-de-partidas)

### **1.6 Utilidades y Funciones Auxiliares**
Contiene funciones de apoyo para tareas generales, como limpieza de pantalla, calculo de digitos, y formatos.

- [Documentación de **Palabras y Categorías**](https://github.com/xjairooo/Ahorcado-Game-in-C/wiki/1.-Estructura-General-del-Proyecto#16-utilidades-y-funciones-auxiliares)
---
## 4. Detalles Tecnicos
### **Estructura de Datos**
```c
// Definimos una estructura para almacenar los datos del usuario
typedef struct {
    char wNombres_de_Usuarios[50];
    int w_palabrasAdivinadas;
    int w_puntos;
    char w_dificultad[30];
} Datos;
```
### *Constantes*
- **Categorias**
```c
#define CAT1 "animales.txt"     // Define el nombre del archivo para la categoría de animales.
#define CAT2 "frutas.txt"       // Define el nombre del archivo para la categoría de frutas.
#define CAT3 "geografia.txt"    // Define el nombre del archivo para la categoría de geografia.
#define CAT4 "paises.txt"       // Define el nombre del archivo para la categoría de países.
#define CAT5 "objetos.txt"      // Define el nombre del archivo para la categoría de objetos.
```

- **Intentos**
```c
#define MAX_INTENTOS 6
```
- **Formato de Ranking**
```c
// -- Definiciones para ajustar el formato de espacios en el ranking
#define ANCHO 16
#define LAR 6
#define ARG 5
#define OP 13
```
- **Colores**
```c
// -- Definiciones de colores ANSI
#define COLOR_RESET "\x1b[0m"
#define COLOR_AZUL "\x1b[34m"
#define COLOR_VERDE "\x1b[32m"
#define COLOR_ROJO "\x1b[31m"
#define COLOR_CYAN "\x1b[36m"
#define COLOR_NOMBRE "\x1B[38;5;220m"
#define COLOR_TITULO "\x1B[38;5;166m"
#define COLOR_POSTE "\x1B[38;5;94m"     // Color del poste y base del ahorca
```
- **Formato para el Ahorcado**
```c
// -- Definiciones de símbolos del ahorcado
#define CABEZA 'O'                      // Símbolo para la cabeza
#define BRAZO_IZQUIERDO '/'             // Símbolo para el brazo izquierdo
#define TRONCO '|'                      // Símbolo para el tronco
#define BRAZO_DERECHO '\\'              // Símbolo para el brazo derecho
#define PIERNA_IZQUIERDA '/'            // Símbolo para la pierna izquierda
#define PIERNA_DERECHA '\\'             // Símbolo para la pierna derecha
```
---
## 5. Asignación de Tareas

| **Área de Trabajo**          | **Responsable** | **Contribuciones**                                                                                                 | **Correcciones**                                                                                   |
|------------------------------|-----------------|-------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------|
| **Interfaz de Usuario**      | José            | Diseñó la pantalla inicial del juego, incluyendo la bienvenida, solicitud del nombre del jugador y reglas del juego. | Ajustó mensajes de bienvenida, reglas y validación del nombre del jugador para mayor claridad con ayuda de *Alexis* y *Wilder*.             |
| **Configuración de Dificultad** | José         | Implementó la lógica para ajustar los intentos permitidos según el nivel de dificultad elegido (Normal o Difícil). | Refinó la lógica para evitar selecciones incorrectas de dificultad y valores fuera del rango ocn el aporte de *Wilder*.        |
| **Sistema de Ranking**       | Wilder          | Desarrolló la funcionalidad de registro y visualización dinámica del ranking de jugadores basado en puntajes.     | Corrigió errores en la actualización de puntajes para reflejar correctamente los datos de cada partida. |
| **Ordenamiento del Ranking** | Wilder          | Implementó un algoritmo de ordenamiento por burbuja para organizar las posiciones en el ranking según los puntajes. | Optimizó el algoritmo de ordenamiento para manejar correctamente los empates en puntajes.           |
| **Manejo de Archivos**       | Alexis          | Programó la lectura de palabras desde archivos externos organizados por categorías, garantizando un acceso dinámico. | Verificó y corrigió errores de lectura en archivos mal formateados o vacíos.                       |
| **Gestión de Memoria Dinámica** | Alexis       | Implementó el manejo de memoria dinámica para gestionar palabras seleccionadas aleatoriamente.                    | Ajustó la gestión de memoria para evitar fugas y mejorar la estabilidad del programa con el apoyo de *Wilder*.               |
| **Lógica del Juego**         | Jairo           | Desarrolló la mecánica principal del juego, incluyendo validación de letras, intentos restantes y control de flujo. | Solucionó casos límite donde las letras ingresadas no eran validadas correctamente.                |
| **Representación Visual**    | Jairo           | Diseñó el dibujo del muñeco del ahorcado, adaptando su progreso según el nivel de errores cometidos.              | Refinó el dibujo del ahorcado para mantener consistencia visual en diferentes niveles de dificultad. |

**Horas de Programación de cada miembro:**
- Wilder: 50 horas.
- Alexis: 45 horas.
- Jose: 40 horas.
- Jairo: 38 horas.
---
## 6. Soluciones a la Compilación
 **No Complila el Código en VSCODE:**
   - En caso de que en VSCODE no compile el Código en consecuencia de la libreria <conio.h>, utilizar el IDE "Code::Blocks" en su version: 20.03.
   - En caso de que al compilar el Código en Code::Blocks no muestre las secuencias ANSI correctamente, se Debera configurarlo manualmente.  
***Pasos:***

1. Abrir el registro de Windows:  
    Presiona Win + R, escribe `regedit`, y presiona Enter.  
    Navega a la siguiente clave:  
    `"HKEY_CURRENT_USER\Console"`  
    Busca un valor llamado `VirtualTerminalLevel`. Si no existe:  
    - Haz clic derecho → Nuevo → Valor DWORD (32 bits).  
    - Nómbralo `VirtualTerminalLevel`.  
    - Establece su valor a `1`.  

    Esto habilitará el soporte de secuencias ANSI de manera persistente en todas las consolas.  

2. Reinicia la consola:  
    - Cierra todas las ventanas de consola abiertas (cmd, PowerShell, etc.).  
    - Abre una nueva consola para que los cambios surtan efecto.
---
## 7. Mejoras Propuestas
1. **Juego Bilingüe (Elección de Lenguaje):**
   - ***Implementación de selección de idioma:*** Puedo implementar una pantalla de inicio que permita al usuario seleccionar su idioma preferido, como inglés o español. Esto haría que el juego sea más accesible y personalizable según las preferencias del jugador.  
2. **Incorporación del Motor OpenGL:**
   - ***Gráficos mejorados:*** Con OpenGL puedo mejorar la parte visual de mi juego, agregando gráficos para las letras, la representación del ahorcado y también incluir animaciones tanto para cuando el jugador gane como cuando pierda. 
3. **Integracion de todos los archivos en uno:**
   - ***Unificación de datos para simplificar la gestión y optimizar el rendimiento del juego:*** Actualmente, el juego utiliza cinco archivos de texto separados para almacenar las palabras de cada categoría. La idea es integrar todo en un único archivo que contenga todas las categorías organizadas, usando un formato claro que permita identificar fácilmente a qué categoría pertenece cada palabra. Esto simplificaría la gestión de los datos y facilitaría las operaciones de lectura y escritura durante el juego.
---
<img src="https://st5.depositphotos.com/1826664/70743/i/450/depositphotos_707434086-stock-photo-gracias-text-written-colorful-background.jpg" width="950"/>
