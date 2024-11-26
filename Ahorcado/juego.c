#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // libreria necesaria para la palabra aleatoria
#include <string.h>
#include <ctype.h> // Para usar la función toupper()
#include <math.h>
#include <conio.h>

//------- STRUCT -------

// Definimos una estructura para almacenar los datos del usuario
typedef struct {
    char wNombres_de_Usuarios[50];
    int w_palabrasAdivinadas;
    int w_puntos;
    char w_dificultad[30];
} Datos;

//------- DEFINE -------

//DEFINE
#define TotalCategorias 5
#define CAT1 "animales.txt"     // Define el nombre del archivo para la categoría de animales.
#define CAT2 "frutas.txt"       // Define el nombre del archivo para la categoría de frutas.
#define CAT3 "geografia.txt"    // Define el nombre del archivo para la categoría de geografia.
#define CAT4 "paises.txt"       // Define el nombre del archivo para la categoría de países.
#define CAT5 "objetos.txt"      // Define el nombre del archivo para la categoría de objetos.
#define MAX_WORD_LENGTH 100
#define nombre 100
#define MAX_INTENTOS 6

// -- Definiciones para ajustar el formato de espacios en el ranking
#define ANCHO 16
#define LAR 6
#define ARG 5
#define OP 13

// -- Definiciones de colores ANSI
#define MAX_NOMBRE 16
#define COLOR_RESET "\x1b[0m"
#define COLOR_AZUL "\x1b[34m"
#define COLOR_VERDE "\x1b[32m"
#define COLOR_ROJO "\x1b[31m"
#define COLOR_CYAN "\x1b[36m"
#define COLOR_NOMBRE "\x1B[38;5;220m"
#define COLOR_TITULO "\x1B[38;5;166m"
#define COLOR_POSTE "\x1B[38;5;94m"     // Color del poste y base del ahorcado

// -- Definiciones de símbolos del ahorcado
#define CABEZA 'O'                      // Símbolo para la cabeza
#define BRAZO_IZQUIERDO '/'             // Símbolo para el brazo izquierdo
#define TRONCO '|'                      // Símbolo para el tronco
#define BRAZO_DERECHO '\\'              // Símbolo para el brazo derecho
#define PIERNA_IZQUIERDA '/'            // Símbolo para la pierna izquierda
#define PIERNA_DERECHA '\\'             // Símbolo para la pierna derecha

//------- PROTOTIPO de FUNCIONES -------
int seleccionar_categoria();
char* seleccionar_palabra(const char *archivo);
char* centro_mando(char* w_CategoriaElegida);
void interface(char w_NombreIngresado[]);
void limpiarPantalla();
void ordenarDatos(Datos arreglo[], int w_cantidad_arreglos);
void imprimirDatos(Datos arreglo[], int w_PartidasJugadas);
void dibujar_ahorcado(int intentos_fallidos);
void eliminar_saltos_de_linea(char *cadena);
void eliminar_saltos_de_linea(char *cadena);
void dibujar_ahorcado_2(int intentos_fallidos);
void consigna();
int calcular_digitos(int numero);
void configurarNuevaPartida(int w_Contador_de_Jugadores, char wNombre_de_Usuarios[10][50], char w_NombreIngresado[]);
int seleccionarDificultad(int *intentos);
void jugarRondas(int intentos, int opcion, int *puntuacion, int *PalabrasAdivinadas, int *w_IntentosFallidos) ;
void guardarDatosPartida(int w_Contador_de_Jugadores, int PalabrasAdivinadas, int puntuacion, int opcion, int w_palabrasAdivinadas[], int w_puntos[], char w_DificultadesElegidas[10][50]);
int preguntarContinuar(int *w_PartidasJugadas);
void mostrarRanking(int w_PartidasJugadas, char wNombre_de_Usuarios[10][50], int w_palabrasAdivinadas[], int w_puntos[], char w_DificultadesElegidas[10][50]);
//------- FUNCION MAIN -------
int main() {
    // Declaración de variables para el nombre del jugador y configuración inicial
    char w_NombreIngresado[50];
    interface(w_NombreIngresado); // Llama a la función para mostrar la interfaz inicial y obtener el nombre del jugador

    // Configuración inicial de las variables
    int intentos = MAX_INTENTOS;    // Cantidad máxima de intentos permitidos
    int opcion = 0;                 // Variable para almacenar la dificultad seleccionada
    char wNombres_de_Usuarios[10][50];           // Arreglo para guardar los nombres de los jugadores
    strcpy(wNombres_de_Usuarios[0], w_NombreIngresado); // Copia el nombre del primer jugador al arreglo

    int w_palabrasAdivinadas[10] = {0}; // Arreglo para almacenar la cantidad de palabras adivinadas por cada jugador
    int w_puntos[10] = {0};             // Arreglo para almacenar los puntos obtenidos por cada jugador
    char w_DificultadesElegidas[10][50];                // Arreglo para almacenar la dificultad seleccionada por cada jugador
    int w_seguir = 1;                   // Variable para controlar si el jugador quiere seguir jugando
    int w_Contador_de_Jugadores = -1;                 // Índice para identificar al jugador actual
    int w_PartidasJugadas = 1;                 // Contador del número de partidas jugadas

    // Ciclo principal del juego, que se ejecuta mientras el jugador decida continuar
    while (w_seguir == 1) {
        w_Contador_de_Jugadores++; // Incrementa el índice para el siguiente jugador

        // Configura una nueva partida, obteniendo datos del jugador actual
        configurarNuevaPartida(w_Contador_de_Jugadores, wNombres_de_Usuarios, w_NombreIngresado);

        // Selecciona la dificultad del juego
        opcion = seleccionarDificultad(&intentos);

        limpiarPantalla(); // Limpia la pantalla antes de iniciar la partida
        printf("\n" COLOR_CYAN "Bienvenido " COLOR_NOMBRE "%s" COLOR_RESET " " COLOR_CYAN "Suerte <3\n" COLOR_RESET, wNombres_de_Usuarios[w_Contador_de_Jugadores]);
        // Variables para los resultados de la partida
        int puntuacion = 0;            // Puntos acumulados en la partida
        int PalabrasAdivinadas = 0;   // Palabras adivinadas en la partida
        int w_IntentosFallidos = 0;   // Contador de intentos fallidos

        // Inicia las rondas del juego
        jugarRondas(intentos, opcion, &puntuacion, &PalabrasAdivinadas, &w_IntentosFallidos);

        // Guarda los datos de la partida actual
        guardarDatosPartida(w_Contador_de_Jugadores, PalabrasAdivinadas, puntuacion, opcion, w_palabrasAdivinadas, w_puntos, w_DificultadesElegidas);

        // Pregunta al jugador si desea continuar con otra partida
        w_seguir = preguntarContinuar(&w_PartidasJugadas);
    }

    limpiarPantalla(); // Limpia la pantalla antes de mostrar el ranking

    // Muestra el ranking final de los jugadores
    mostrarRanking(w_PartidasJugadas, wNombres_de_Usuarios, w_palabrasAdivinadas, w_puntos, w_DificultadesElegidas);

    return 0;
}

//------- FUNCIONES -------

// -- Función que muestra la interfaz inicial
void interface(char w_NombreIngresado[]) {
    limpiarPantalla();
    // Muestra la bienvenida.
    printf("\n%s******************************************************************************%s\n", COLOR_AZUL, COLOR_RESET);
    printf("%s*        ___       ___         ___   ___     ___  ___  ______   ___          *%s\n", COLOR_AZUL, COLOR_RESET);
    printf("%s*       |___ |    |___| |___| |   | |___|_  |    |___|  |    | |   |         *%s\n", COLOR_AZUL, COLOR_RESET);
    printf("%s*       |___ |___ |   | |   | |___| |     | |___ |   | _|____| |___|         *%s\n", COLOR_AZUL, COLOR_RESET);
    printf("%s*                                                                            *%s\n", COLOR_AZUL, COLOR_RESET);
    printf("%s******************************************************************************%s\n", COLOR_AZUL, COLOR_RESET);

    // Solicita al usuario ingresar su nombre
    printf("\nIngrese un nombre de hasta 16 caracteres sin incluir espacios\n");
    do {
        printf("Nombre del jugador: ");
        scanf("%s", w_NombreIngresado);                // Lee el nombre ingresado por el jugador

        // Verifica si el nombre excede el límite permitido de caracteres
        if (strlen(w_NombreIngresado) > MAX_NOMBRE) {
            printf("%sError:%s El nombre debe tener como máximo %d caracteres y no incluir espacios.\n", COLOR_ROJO, COLOR_RESET, MAX_NOMBRE);
        }
    } while (strlen(w_NombreIngresado) > MAX_NOMBRE);  // Repite hasta que el nombre cumpla con las restricciones

    // Llama a la función consigna() para mostrar las reglas del juego
    consigna();
}

// -- Función para configurar una nueva partida y manejar los datos del jugador
void configurarNuevaPartida(int w_Contador_de_Jugadores, char wNombres_de_Usuarios[10][50], char w_NombreIngresado[]) {

    // Si no es la primera partida, se solicita un nuevo nombre de usuario
    if (w_Contador_de_Jugadores > 0) {
        limpiarPantalla(); // Limpia la pantalla

        // Pregunta si el jugador quiere volver a ver las reglas
        printf("Quieres ver las reglas? \n(1 = Si, 2 = No): ");
        int ver_reglas;
        scanf("%d", &ver_reglas);

        // Si el jugador responde "1", muestra las reglas del juego
        if (ver_reglas == 1) {
            consigna();
        }

        // Solicita un nuevo nombre de usuario y valida su longitud
        do {
            printf("El nombre debe tener 16 caracteres o menos y sin espacios.\n");
            printf("Ingrese el Nombre del Usuario: ");
            scanf("%s", wNombres_de_Usuarios[w_Contador_de_Jugadores]); // Guarda el nuevo nombre en la posición correspondiente del array

            // Verifica si el nombre supera los 16 caracteres permitidos
            if (strlen(wNombres_de_Usuarios[w_Contador_de_Jugadores]) > 16) {
                printf("Error: El nombre debe tener menos de 16 caracteres.\n");
            }
        } while (strlen(wNombres_de_Usuarios[w_Contador_de_Jugadores]) > 16); // Repite mientras el nombre no cumpla las restricciones

    } else {
        // Si es la primera partida, utiliza el nombre ingresado inicialmente
        strcpy(wNombres_de_Usuarios[0], w_NombreIngresado);
    }
}

// -- Función que permite al usuario seleccionar la dificultad del juego
//    -- Recibe un puntero a la variable `intentos` para modificar su valor según la dificultad seleccionada
int seleccionarDificultad(int *intentos) {
    int opcion; // Variable para almacenar la opción seleccionada por el usuario

    // Imprime las opciones de dificultad al usuario
    printf(COLOR_AZUL "\nIngrese la dificultad del juego:" COLOR_RESET "\n");
    printf(COLOR_VERDE "(1) Normal" COLOR_RESET " " COLOR_ROJO "(2) Dificil" COLOR_RESET "\n");

    // Lee la opción ingresada por el usuario
    scanf("%d", &opcion);

    // Asigna el número de intentos según la opción seleccionada
    // - Si la opción es 2 (Difícil), los intentos serian 3
    // - Si la opción es 1 (Normal) o cualquier otro valor, se asigna el valor predeterminado `MAX_INTENTOS`
    *intentos = (opcion == 2) ? 3 : MAX_INTENTOS;

    // Devuelve la opción seleccionada por el usuario
    return opcion;
}


// -- Función que maneja las rondas de juego
void jugarRondas(int intentos, int opcion, int *puntuacion, int *PalabrasAdivinadas, int *w_IntentosFallidos) {

    // Ejecuta el juego mientras el jugador tenga intentos disponibles
    while (intentos > 0) {
        char w_CategoriaElegida[50];              // Variable para almacenar la categoría de la palabra
        char *w_palabra_rescatada = centro_mando(w_CategoriaElegida); // Obtiene la palabra y su categoría
        if (!w_palabra_rescatada) break;   // Si no se encuentra una palabra válida, termina la ronda

        // Configuración inicial de la palabra
        char palabra[50], w_ocultar_palabra[50], letras_intentadas[30] = {0};
        strcpy(palabra, w_palabra_rescatada);               // Copia la palabra seleccionada
        int longitudPalabra = strlen(palabra);              // Calcula la longitud de la palabra
        memset(w_ocultar_palabra, '_', longitudPalabra);    // Inicializa la palabra oculta con guiones bajos
        w_ocultar_palabra[longitudPalabra] = '\0';          // Agrega el terminador nulo para formar una cadena válida

        int aciertos = 0; // Contador para las letras adivinadas correctamente

        // Realiza un ciclo mientras que el jugador tenga intentos y no haya adivinado la palabra
        while (intentos > 0 && aciertos < longitudPalabra) {

            // Muestra el estado del juego: puntuación, vidas, y el progreso en la palabra
            printf("\n                                        " COLOR_CYAN "Puntos:%i  Vidas:%i" COLOR_RESET, *puntuacion, intentos);
            (opcion == 2) ? dibujar_ahorcado_2(*w_IntentosFallidos) : dibujar_ahorcado(*w_IntentosFallidos);
            printf("%s\n", w_ocultar_palabra);       // Muestra la palabra oculta
            printf("La categoria es: %s\n", w_CategoriaElegida);
            printf("Letras intentadas: %s\n", letras_intentadas);

            // Solicita una letra al jugador
            char letra;
            printf("Ingrese una letra: ");
            scanf(" %c", &letra);
            letra = toupper(letra); // Convierte la letra ingresada a mayúscula

            // Verifica si la letra ya fue intentada previamente
            if (strchr(letras_intentadas, letra)) {
                printf("Ya intentaste la letra '%c'. Intenta con otra.\n", letra);
                continue; // Solicita una nueva letra
            }

            // Registra la letra como intentada
            letras_intentadas[strlen(letras_intentadas)] = letra;

            // Busca la letra en la palabra
            int encontrado = 0; // Indica si la letra fue encontrada
            for (int i = 0; i < longitudPalabra; i++) {
                if (palabra[i] == letra) {
                    w_ocultar_palabra[i] = letra; // Descubre la letra en la palabra oculta
                    aciertos++;                   // Incrementa el contador de aciertos
                    encontrado = 1;               // Marca la letra como encontrada
                }
            }

            // Si la letra no se encuentra, disminuye los intentos y actualiza el ahorcado
            if (!encontrado) {
                intentos--;
                (*w_IntentosFallidos)++;
            }

            limpiarPantalla(); // Limpia la pantalla antes de mostrar el nuevo estado del juego
        }

        // Verifica si el jugador logró adivinar la palabra
        if (aciertos == longitudPalabra) {
            printf("Acertaste! La palabra era: %s\n", palabra);
            *puntuacion += (opcion == 2) ? 30 : 20; // Incrementa los puntos según la dificultad
            (*PalabrasAdivinadas)++;               // Incrementa el contador de palabras adivinadas
        } else {
            // Si no logró adivinar, verifica si los intentos llegaron a 0
            if (intentos == 0) {
                // Resta puntos según la dificultad
                if (*puntuacion - ((opcion == 2) ? 10 : 15) <= 0) {
                    *puntuacion = 0; // Evita puntuaciones negativas
                } else {
                    *puntuacion -= (opcion == 2) ? 10 : 15;
                }

                // Muestra el estado final del ahorcado y la palabra
                (opcion == 2) ? dibujar_ahorcado_2(*w_IntentosFallidos) : dibujar_ahorcado(*w_IntentosFallidos);
                printf("Perdiste...\n");
                printf("La palabra era: %s\n", palabra);
            }
        }

    }
}

// -- Función para guardar los datos de una partida al finalizar
void guardarDatosPartida(int w_Contador_de_Jugadores, int PalabrasAdivinadas, int puntuacion, int opcion, int w_palabrasAdivinadas[], int w_puntos[], char w_DificultadesElegidas[10][50]) {
    // Guarda la cantidad de palabras adivinadas en la posición correspondiente al jugador actual
    w_palabrasAdivinadas[w_Contador_de_Jugadores] = PalabrasAdivinadas;

    // Guarda la puntuación obtenida en la posición correspondiente al jugador actual
    w_puntos[w_Contador_de_Jugadores] = puntuacion;

    // Guarda la dificultad seleccionada como "difícil" o "normal" en función de la opción elegida
    strcpy(w_DificultadesElegidas[w_Contador_de_Jugadores], (opcion == 2) ? "Dificil" : "Normal");
}

// -- Función que pregunta al jugador si quiere continuar jugando
int preguntarContinuar(int *w_PartidasJugadas) {
    int w_seguir;
    printf("Quieres volver a jugar? \n(1 = Si, 2 = No): ");
    scanf("%d", &w_seguir);

    // Si el jugador elige continuar, incrementa el contador de partidas
    if (w_seguir == 1) {
        (*w_PartidasJugadas)++;
    }
    // Retorna la decisión del jugador
    return w_seguir;
}

// -- Función que muestra el ranking de jugador al finalizar la partida.
void mostrarRanking(int w_PartidasJugadas, char wNombres_de_Usuarios[10][50], int w_palabrasAdivinadas[], int w_puntos[], char w_DificultadesElegidas[10][50]) {
    Datos datos[w_PartidasJugadas]; // Crea un arreglo de estructuras para almacenar la información de los jugadores

    // Llena el arreglo de estructuras con los datos de cada jugador
    for (int i = 0; i < w_PartidasJugadas; i++) {
        strcpy(datos[i].wNombres_de_Usuarios, wNombres_de_Usuarios[i]);                    // Copia el nombre del jugador actual
        datos[i].w_palabrasAdivinadas = w_palabrasAdivinadas[i]; // Guarda las palabras adivinadas por el jugador actual
        datos[i].w_puntos = w_puntos[i];                         // Guarda los puntos del jugador actual
        strcpy(datos[i].w_dificultad, w_DificultadesElegidas[i]);                // Copia la dificultad elegida por el jugador actual
    }

    // Ordena los datos de los jugadores en base a los puntos obtenidos (de mayor a menor)
    ordenarDatos(datos, w_PartidasJugadas);

    // Muestra el ranking de los jugadores de manera ordenada
    imprimirDatos(datos, w_PartidasJugadas);
}

// Función que muestra las reglas del juego
void consigna() {
    printf("%s\nReglas del juego:%s\n", COLOR_AZUL, COLOR_RESET);
    printf("\n");
    printf("%s1) El jugador debe adivinar una palabra seleccionada aleatoriamente entre 5 categorias.%s\n", COLOR_CYAN, COLOR_RESET);
    printf("%s2) El juego tiene dos niveles de dificultad:%s\n", COLOR_CYAN, COLOR_RESET);
    printf("   %s- NORMAL:%s 6 intentos\n", COLOR_VERDE, COLOR_RESET);
    printf("   %s- DIFICIL:%s 3 intentos\n", COLOR_ROJO, COLOR_RESET);
    printf("%s3) Se otorgaran o descontaran puntos dependiendo de la dificultad seleccionada:%s\n", COLOR_CYAN, COLOR_RESET);
    printf("   %s- NORMAL:%s Si acertas la Palabra +20 puntos, y si pierdes todos los intentos -15 puntos. \n", COLOR_VERDE, COLOR_RESET);
    printf("   %s- DIFICIL:%s Si acertas la Palabra +30 puntos, y si pierdes todos los intentos -10 puntos. \n", COLOR_ROJO, COLOR_RESET);
    printf("%s4) Por cada error, se sumara una parte al dibujo del ahorcado.%s\n", COLOR_CYAN, COLOR_RESET);
    printf("%s5) El juego termina cuando completes el dibujo del ahorcado o adivines la palabra.%s\n", COLOR_CYAN, COLOR_RESET);
    printf("\n");
}

// -- Secuencia ANSI para limpiar la pantalla y mover el cursor al inicio
void limpiarPantalla() {
    printf("\033[2J\033[H");    // \033[2J: borra todo el contenido visible de la pantalla.
                                // \033[H: posiciona el cursor en la esquina superior izquierda (posición inicial).
}

// -- Función que ordena un arreglo de estructuras `Datos` en base a los puntos obtenidos por los usuarios
void ordenarDatos(Datos arreglo[], int w_cantidad_usuarios) {
    int i, j;       // Variables de control para los bucles
    Datos temp;     // Variable temporal para realizar intercambios
    // Bucle externo: controla el número de pasadas necesarias para ordenar
    for (i = 0; i < w_cantidad_usuarios - 1; i++) {
        // Bucle interno: compara pares de elementos y realiza intercambios si es necesario
        for (j = i + 1; j < w_cantidad_usuarios; j++) {
            // Si el elemento actual tiene menos puntos que el siguiente, se intercambian
            if (arreglo[i].w_puntos < arreglo[j].w_puntos) {
                // Intercambia las estructuras completas usando una variable temporal
                temp = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = temp;
            }
        }
    }
}

// -- Funcion que calcula la cantidad de digitos que tiene los puntos y las palabras adivinadas.
int calcular_digitos(int numero) {
    if (numero == 0) return 1;      // Si el numero es 0 devuelve que el numero tiene un digito.
    return (int)log10(numero) + 1;  // Utiliza la funcion log10 para calcular los digitos
}

// -- Función para imprimir una cantidad específica de espacios en blanco
void imprimirEspacios(int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf(" ");
    }
}

/*void imprimirSeparador() {
    printf("\x1B[34m_\x1B[0m\n");
}*/

// -- Función que imprime los datos de los jugadores en un ranking organizado y estético.
void imprimirDatos(Datos arreglo[], int w_PartidasJugadas) {
    limpiarPantalla(); // Limpia la pantalla antes de imprimir
    printf("\n");

    int a = 1; // Contador para los puestos de los jugadores

    for (int i = 0; i < w_PartidasJugadas; i++) {
        // Cálculo de espacios dinámicos para el formato de la tabla
        int longitudNombre = strlen(arreglo[i].wNombres_de_Usuarios);//calcula el tamaño del nombre del jugador
        int EspacioRestanteNombre = ANCHO - longitudNombre; // Espacios necesarios después del nombre
        int w_DigitosPalabra = calcular_digitos(arreglo[i].w_palabrasAdivinadas);//calcula la cantidad de digitos que se utilisa para la cantidad de palabras que adivino el jugador
        int EspacioRestantePalabra = ARG - w_DigitosPalabra + 1; // Espacios después de palabras adivinadas
        int w_DigitosPuntos = calcular_digitos(arreglo[i].w_puntos);//calcula la cantidad de digitos que se utilisa para escribir los puntos
        int EspacioRestantePuntos = LAR - w_DigitosPuntos + 1; // Espacios después de los puntos
        int w_TamanioDificultad = strlen(arreglo[i].w_dificultad);//calcula el tamaño de la dificultad que coloco el jugador  ("facil","dificil")
        int EspacioRestanteDificultad = OP - w_TamanioDificultad; // Espacios después de la dificultad

        // Imprime el separador superior del cuadro
        printf(COLOR_AZUL "_________________________________________________________________________\n" COLOR_RESET);
        // Imprime la línea del encabezado con el puesto del jugador
        printf(COLOR_AZUL "|" COLOR_RESET " " COLOR_TITULO "[Puesto : %i]" COLOR_RESET "             " COLOR_AZUL "|" COLOR_RESET "                          " COLOR_AZUL "|" COLOR_RESET "                 " COLOR_AZUL "|\n", a);

        // Imprime el nombre del jugador
        printf(COLOR_AZUL "|" COLOR_RESET " " COLOR_TITULO "Nombre:" COLOR_RESET);
        printf(" " COLOR_NOMBRE "%s" COLOR_RESET " ", arreglo[i].wNombres_de_Usuarios);
        for (int j = 0; j < EspacioRestanteNombre; j++) {
            printf(" ");
        }

        // Imprime las palabras adivinadas
        printf(COLOR_AZUL "|" COLOR_RESET " " COLOR_TITULO "Palabras Adivinadas:" COLOR_RESET " %d", arreglo[i].w_palabrasAdivinadas);
        for (int w = 0; w < EspacioRestantePalabra - 2; w++) {
            printf(" ");
        }

        // Imprime los puntos del jugador
        printf(COLOR_AZUL "|" COLOR_RESET " " COLOR_TITULO "Puntos:" COLOR_RESET " %d", arreglo[i].w_puntos);
        for (int k = 0; k < EspacioRestantePuntos + 1; k++) {
            printf(" ");
        }
        printf(COLOR_AZUL "|\n" COLOR_RESET);

        // Imprime la dificultad elegida por el jugador
        printf(COLOR_AZUL "|" COLOR_RESET " " COLOR_TITULO "Dificultad:" COLOR_RESET " %s", arreglo[i].w_dificultad);
        for (int f = 0; f < EspacioRestanteDificultad; f++) {
            printf(" ");
        }
        printf(COLOR_AZUL "|                          |                 |\n" COLOR_RESET);

        // Imprime el separador inferior del cuadro
        printf(COLOR_AZUL "|__________________________|__________________________|_________________|\n" COLOR_RESET);

        a++; // Incrementa el puesto del jugador
    }

    // Mensaje final para el usuario
    printf("\n");
    printf("Toca una tecla para finalizar\n");
    getch();
}

// -- Dibuja el estado actual del ahorcado en función de los intentos fallidos.
void dibujar_ahorcado(int intentos_fallidos) {
    // Imprime la estructura superior del ahorcado (poste y cuerda)
    printf("\n" COLOR_POSTE "+---+" COLOR_RESET "\n");  // Línea superior del poste
    printf(COLOR_POSTE "|   |" COLOR_RESET "\n");       // Poste vertical y cuerda

    // Dibuja la cabeza si los intentos fallidos son al menos 1
    printf(COLOR_POSTE "|   " COLOR_RESET);
    printf("%c\n", (intentos_fallidos >= 1) ? CABEZA : ' ');  // Cabeza o espacio en blanco

    // Dibuja el tronco y los brazos según los intentos fallidos
    printf(COLOR_POSTE "|  " COLOR_RESET);
    printf("%c%c%c\n",
           (intentos_fallidos >= 3) ? BRAZO_IZQUIERDO : ' ',  // Brazo izquierdo
           (intentos_fallidos >= 2) ? TRONCO : ' ',           // Tronco
           (intentos_fallidos >= 4) ? BRAZO_DERECHO : ' ');   // Brazo derecho

    // Dibuja las piernas según los intentos fallidos
    printf(COLOR_POSTE "|  " COLOR_RESET);
    printf("%c %c\n",
           (intentos_fallidos >= 5) ? PIERNA_IZQUIERDA : ' ', // Pierna izquierda
           (intentos_fallidos >= 6) ? PIERNA_DERECHA : ' ');  // Pierna derecha

    // Base del poste
    printf(COLOR_POSTE "|" COLOR_RESET "\n");     // Línea del poste sin contenido
    printf(COLOR_POSTE "=====     " COLOR_RESET); // Base del ahorcado
}

// -- Selecciona una categoría aleatoria para el juego.
int seleccionar_categoria() {
    srand(time(NULL));                                        // Inicializa la semilla para el generador de números aleatorios usando la hora actual.
    int categoria_random = rand() % TotalCategorias + 1;    // Genera un número aleatorio entre 1 y TotalCategorias.

    return categoria_random;    // Devuelve el número de la categoría seleccionada aleatoriamente.
}

// -- Asigna una palabra aleatoria de una categoría seleccionada.
char* centro_mando(char* w_CategoriaElegida) {
    char mostrar_categoria[20];                // Almacena temporalmente el nombre de la categoría.
    int categoria = seleccionar_categoria();   // Selecciona una categoría aleatoria.
    char *palabra = NULL;                      // Inicializa el puntero para la palabra seleccionada.

    // Asigna una palabra y el nombre de la categoría según el número generado.
    switch (categoria) {
        case 1:
            palabra = seleccionar_palabra(CAT1);
            strcpy(mostrar_categoria, "Animales");
            break;
        case 2:
            palabra = seleccionar_palabra(CAT2);
            strcpy(mostrar_categoria, "Frutas");
            break;
        case 3:
            palabra = seleccionar_palabra(CAT3);
            strcpy(mostrar_categoria, "Geografia");
            break;
        case 4:
            palabra = seleccionar_palabra(CAT4);
            strcpy(mostrar_categoria, "Paises");
            break;
        case 5:
            palabra = seleccionar_palabra(CAT5);
            strcpy(mostrar_categoria, "Objetos");
            break;
        default:
            printf("Categoría no valida.\n"); // Caso de error si el número no coincide con una categoría.
            return NULL;
    }

    // Si se obtuvo una palabra, copia el nombre de la categoría en `w_CategoriaElegida`.
    if (palabra) {
        strcpy(w_CategoriaElegida, mostrar_categoria);
    }

    return palabra; // Devuelve la palabra seleccionada o NULL si hubo un error.
}

//-- Selecciona una palabra aleatoria de un archivo de texto.
char* seleccionar_palabra(const char *archivo) {
    // Abre el archivo en modo lectura
    FILE *file = fopen(archivo, "r");
    if (!file) {
        printf("No se pudo abrir el archivo %s.\n", archivo);
        return NULL;
    }

    // Reserva memoria dinámica para leer líneas del archivo
    char *buffer = (char *)malloc(1024 * sizeof(char));
    if (!buffer) {
        fclose(file);
        printf("Error al asignar memoria para el buffer.\n");
        return NULL;
    }

    // Cuenta la cantidad de palabras (líneas) en el archivo
    int total_palabras = 0;
    while (fgets(buffer, 1024, file)) {
        eliminar_saltos_de_linea(buffer); // Limpia el salto de línea al final de cada palabra
        total_palabras++;
    }

    // Verifica si el archivo está vacío
    if (total_palabras == 0) {
        printf("No hay palabras en el archivo %s.\n", archivo);
        free(buffer);
        fclose(file);
        return NULL;
    }

    // Genera un índice aleatorio dentro del rango de palabras
    srand(time(NULL));
    int seleccion = rand() % total_palabras;

    // Relee el archivo para encontrar la palabra seleccionada
    rewind(file);
    for (int i = 0; i <= seleccion; i++) {
        if (!fgets(buffer, 1024, file)) break;
    }
    fclose(file);

    eliminar_saltos_de_linea(buffer); // Limpia el salto de línea de la palabra seleccionada

    // Crea una copia dinámica de la palabra seleccionada
    char *palabra_seleccionada = strdup(buffer);
    free(buffer); // Libera el buffer original

    // Verifica si la copia dinámica fue exitosa
    if (!palabra_seleccionada) {
        printf("Error al asignar memoria para la palabra seleccionada.\n");
        return NULL;
    }

    return palabra_seleccionada; // Retorna la palabra seleccionada
}

//-- Función para eliminar el salto de línea al final de una cadena
void eliminar_saltos_de_linea(char *cadena) {
    if (cadena[strlen(cadena) - 1] == '\n')
        cadena[strlen(cadena) - 1] = '\0'; // Reemplaza el '\n' por '\0'
}

//-- Dibuja el estado actual del ahorcado con 3 intentos disponibles.
void dibujar_ahorcado_2(int intentos_fallidos) {
    // Imprime la estructura superior del ahorcado (poste y cuerda)
    printf("\n" COLOR_POSTE "+---+" COLOR_RESET "\n");  // Línea superior del poste
    printf(COLOR_POSTE "|   |" COLOR_RESET "\n");       // Poste vertical con la cuerda

    // Dibuja la cabeza si hay al menos 1 fallo
    printf(COLOR_POSTE "|   " COLOR_RESET);
    printf("%c\n", (intentos_fallidos >= 1) ? CABEZA : ' ');  // Cabeza o espacio en blanco

    // Dibuja el tronco y los brazos si hay al menos 2 fallos
    printf(COLOR_POSTE "|  " COLOR_RESET);
    printf("%c%c%c\n",
           (intentos_fallidos >= 2) ? BRAZO_IZQUIERDO : ' ',  // Brazo izquierdo
           (intentos_fallidos >= 1) ? TRONCO : ' ',           // Tronco
           (intentos_fallidos >= 2) ? BRAZO_DERECHO : ' ');   // Brazo derecho

    // Dibuja las piernas si hay 3 fallos
    printf(COLOR_POSTE "|  " COLOR_RESET);
    printf("%c %c\n",
           (intentos_fallidos >= 3) ? PIERNA_IZQUIERDA : ' ', // Pierna izquierda
           (intentos_fallidos >= 3) ? PIERNA_DERECHA : ' ');  // Pierna derecha

    // Imprime la base del poste
    printf(COLOR_POSTE "|" COLOR_RESET "\n");
    printf(COLOR_POSTE "=====     " COLOR_RESET);  // Base del ahorcado
}
