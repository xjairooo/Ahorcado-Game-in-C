# Ahorcado Game in C 🕹
![Imagen de WhatsApp 2024-11-24 a las 22 15 15_43d49c8c](https://github.com/user-attachments/assets/46fe035b-ce3f-4caf-af00-a7fabb8d5788)

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
2. **[Asignación de Tareas](#2-asignación-de-tareas)**
3. 
___

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

## 2. Asignación de Tareas

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

---
## 3. Mejoras Propuestas
1. **Juego Bilingüe (Elección de Lenguaje):**
   - ***Implementación de selección de idioma:*** Puedo implementar una pantalla de inicio que permita al usuario seleccionar su idioma preferido, como inglés o español. Esto haría que el juego sea más accesible y personalizable según las preferencias del jugador.  
2. **Incorporación del Motor OpenGL:**
   - ***Gráficos mejorados:*** Con OpenGL puedo mejorar la parte visual de mi juego, agregando gráficos para las letras, la representación del ahorcado y también incluir animaciones tanto para cuando el jugador gane como cuando pierda. 
3. **Integracion de todos los archivos en uno:**
   - ***Unificación de datos para simplificar la gestión y optimizar el rendimiento del juego:*** Actualmente, el juego utiliza cinco archivos de texto separados para almacenar las palabras de cada categoría. La idea es integrar todo en un único archivo que contenga todas las categorías organizadas, usando un formato claro que permita identificar fácilmente a qué categoría pertenece cada palabra. Esto simplificaría la gestión de los datos y facilitaría las operaciones de lectura y escritura durante el juego.
