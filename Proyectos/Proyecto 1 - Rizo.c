#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estructura del jugador
struct jugador {
    char nombre[50];                   // Nombre del jugador
    int vida;                          // Puntos de vida
    int defensa;                       // Defensa base
    int defensa_temp;                  // Defensa temporal para el turno
    int aumento_ataque;                // Aumento temporal del ataque
    int turnos_polimorfia;             // Contador de turnos de polimorfia
    void (*magia[3])(void *, void *); // Punteros a función para los magia
};

//Funciones
void atacar(struct jugador *atacante, struct jugador *defensor);
void defender(struct jugador *jugador);
void piroexplosion(void *lanzador, void *objetivo);
void polimorfia(void *lanzador, void *objetivo);
void escudo_exanime(void *lanzador, void *objetivo);
void leeroy_jenkins(void *lanzador, void *objetivo);
void cancion_lunargenta(void *lanzador, void *objetivo);
void seleccionar_hechizo(struct jugador *jugador, int indice, int opcion);
void mostrar_resultado(const char *descripcion);
void mostrar_magia();
void reiniciar_defensa(struct jugador *jugador);
void seleccionar_y_lanzar_hechizo(struct jugador *lanzador, struct jugador *objetivo);

// Función para el ataque básico
void atacar(struct jugador *atacante, struct jugador *defensor) {
    int dado = rand() % 20 + 1; // Lanzar dado de 20 caras
    int doble = (dado == 20) ? 20 : 10;  // Doble de daño si se obtiene un 20

    // Aplicar aumento de ataque temporal si existe
    if (atacante->aumento_ataque > 0) {
        doble += atacante->aumento_ataque;
        atacante->aumento_ataque = 0; // Resetea el buff después del ataque
    }

    if (dado >= defensor->defensa_temp) { // Se compara contra la defensa temporal
        defensor->vida -= doble;
        char resultado[200];
        snprintf(resultado, 200, "%s ataca. Ataque %d vs Defensa %d – Ataque exitoso. %s recibe %d puntos de daño. Vida restante: %d.",
                 atacante->nombre, dado, defensor->defensa_temp, defensor->nombre, doble, defensor->vida);
        mostrar_resultado(resultado);
    } else {
        char resultado[100];
        snprintf(resultado, 100, "%s ataca. Ataque %d vs Defensa %d – Ataque fallido.", atacante->nombre, dado, defensor->defensa_temp);
        mostrar_resultado(resultado);
    }
}


//Defensas
// Función para la defensa
void defender(struct jugador *jugador) {
    jugador->defensa_temp += 5;  // Incrementa solo la defensa temporal
    char resultado[100];
    snprintf(resultado, 100, "%s se defiende. Defensa incrementada temporalmente a %d.", jugador->nombre, jugador->defensa_temp);
    mostrar_resultado(resultado);
}

// Función para mostrar el resultado del turno
void mostrar_resultado(const char *descripcion) {
    printf("%s\n", descripcion);
}

// Función para reiniciar la defensa temporal al inicio del turno
void reiniciar_defensa(struct jugador *jugador) {
    jugador->defensa_temp = jugador->defensa;
}

//Magia (función)
// Magia 1: Piroexplosión, magia de daño contra el oponente
void piroexplosion(void *lanzador, void *objetivo) {
    struct jugador *enemigo = (struct jugador *)objetivo;
    int dado = rand() % 20 + 1;
    char descripcion[200];
    snprintf(descripcion, 200, "Lanzando Piroexplosión. Magia %d vs Defensa %d", dado, enemigo->defensa_temp);
    
    if (dado >= enemigo->defensa_temp) {
        int doble = (dado == 20) ? 40 : 20;  // Doble de daño si se obtiene un 20
        enemigo->vida -= doble;
        printf("%s – Magia exitosa. %s recibe %d puntos de daño. Vida restante: %d.\n",
               descripcion, enemigo->nombre, doble, enemigo->vida);
    } else {
        printf("%s – Magia fallida.\n", descripcion);
    }
}

// Magia 2: Polimorfia, transforma al oponente en una oveja
void polimorfia(void *lanzador, void *objetivo) {
    struct jugador *enemigo = (struct jugador *)objetivo;
    mostrar_resultado("Lanzando Polimorfia. ¡El enemigo es transformado en una oveja!");
    enemigo->turnos_polimorfia = 1;  // los turnos que va a perder el oponente
}

// Magia 3: Escudo Exánime, aumenta la defensa temporal del lanzador
void escudo_exanime(void *lanzador, void *objetivo) {
    struct jugador *jugador = (struct jugador *)lanzador;
    int dado = rand() % 20 + 1;
    jugador->defensa_temp += dado + 2;
    char descripcion[100];
    snprintf(descripcion, 100, "%s lanza Escudo Exánime. Defensa incrementada en %d puntos temporalmente.", jugador->nombre, dado + 2);
    mostrar_resultado(descripcion);
}

// Magia 4: ¡Leeroy Jenkins!, aumenta el ataque del lanzador para el próximo turno
void leeroy_jenkins(void *lanzador, void *objetivo) {
    struct jugador *jugador = (struct jugador *)lanzador;
    jugador->aumento_ataque = 10; // Aumenta el ataque para el próximo turno
    mostrar_resultado("¡Leeroy Jenkins! El ataque se incrementará en 10 puntos en el próximo turno.");
}

// Magia 5: Canción Lunargenta, cura al lanzador
void cancion_lunargenta(void *lanzador, void *objetivo) {
    struct jugador *jugador = (struct jugador *)lanzador;
    jugador->vida += 15;
    if (jugador->vida > 100) jugador->vida = 100; // Limitar la curación para no sobrepasar el máximo de HP
    char descripcion[100];
    snprintf(descripcion, 100, "Canción Lunargenta. %s se cura 15 puntos de vida. Vida restante: %d.", jugador->nombre, jugador->vida);
    mostrar_resultado(descripcion);
}

//Magia (Funciones varias)
 // Función para mostrar las opciones de magia disponibles
void mostrar_magia() {
    printf("\nOpciones de magia Disponibles:\n");
    printf("1. Piroexplosión - Magia de daño con posibilidad de doble daño.\n");
    printf("2. Polimorfia - Convierte al enemigo en oveja, pierde el turno actual\n");
    printf("3. Escudo Exánime - Incrementa la defensa temporalmente basado en el resultado del dado.\n");
    printf("4. Leeroy Jenkins - Aumenta el ataque del próximo turno en 10 puntos.\n");
    printf("5. Canción Lunargenta - Cura al jugador 15 puntos de vida.\n");
}

// Función para seleccionar la magia
void seleccionar_hechizo(struct jugador *jugador, int indice, int opcion) {
    // Asignación de funciones de magia al arreglo de punteros utilizando aritmética de apuntadores
    switch (opcion) {
        case 1:
            *(jugador->magia + indice) = piroexplosion;
            break;
        case 2:
            *(jugador->magia + indice) = polimorfia;
            break;
        case 3:
            *(jugador->magia + indice) = escudo_exanime;
            break;
        case 4:
            *(jugador->magia + indice) = leeroy_jenkins;
            break;
        case 5:
            *(jugador->magia + indice) = cancion_lunargenta;
            break;
        default:
            printf("Hechizo no válido, selecciona entre 1 y 5.\n");
            break;
    }
}


// Función para que el jugador seleccione cuál hechizo usar
void seleccionar_y_lanzar_hechizo(struct jugador *lanzador, struct jugador *objetivo) {
    printf("Selecciona el hechizo que deseas usar:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. ", i + 1);
        if (lanzador->magia[i] == piroexplosion) {
            printf("Piroexplosión\n");
        } else if (lanzador->magia[i] == polimorfia) {
            printf("Polimorfia\n");
        } else if (lanzador->magia[i] == escudo_exanime) {
            printf("Escudo Exánime\n");
        } else if (lanzador->magia[i] == leeroy_jenkins) {
            printf("Leeroy Jenkins\n");
        } else if (lanzador->magia[i] == cancion_lunargenta) {
            printf("Canción Lunargenta\n");
        }
    }

    int opcion;
    printf("Elige el hechizo (1-3): ");
    scanf("%d", &opcion);

    if (opcion >= 1 && opcion <= 3) {
        lanzador->magia[opcion - 1](lanzador, objetivo); // Aplicar el efecto del hechizo correctamente
    } else {
        printf("Selección no válida. Turno perdido.\n");
    }
}

// Función principal
int main() {
    struct jugador jugadores[2];       // Arreglo de jugadores
    struct jugador *j1 = jugadores;    // Puntero al jugador 1
    struct jugador *j2 = jugadores + 1; // Puntero al jugador 2
    srand(time(NULL));

    // Selección del nombre del jugador 1
    printf("Selecciona tu personaje:\n");
    printf("1. Thrall\n");
    printf("2. Anduin\n");
    printf("3. Gul'dan\n");
    printf("4. Illidan\n");
    printf("5. Sylvanas\n");
    int eleccion_nombre;
    printf("Elige un nombre (1-5): ");
    scanf("%d", &eleccion_nombre);

    // Asignación del nombre seleccionado
    switch (eleccion_nombre) {
        case 1:
            strcpy(j1->nombre, "Thrall");
            break;
        case 2:
            strcpy(j1->nombre, "Anduin");
            break;
        case 3:
            strcpy(j1->nombre, "Gul'dan");
            break;
        case 4:
            strcpy(j1->nombre, "Illidan");
            break;
        case 5:
            strcpy(j1->nombre, "Sylvanas");
            break;
        default:
            printf("Opción no válida. Se seleccionará por defecto Sylvanas.\n");
            strcpy(j1->nombre, "Sylvanas");
            break;
    }

    j1->vida = 100;
    j1->defensa = 10;
    j1->defensa_temp = j1->defensa;
    j1->aumento_ataque = 0;
    j1->turnos_polimorfia = 0;

    // Mostrar opciones de magia disponibles
    mostrar_magia();

    // Selección de magia para el jugador humano
    printf("Selecciona 3 magia para usar (1-5):\n");
    for (int i = 0; i < 3; i++) {
        int opcion;
        printf("Elige el hechizo #%d: ", i + 1);
        scanf("%d", &opcion);
        seleccionar_hechizo(j1, i, opcion);
    }

    // Inicialización del jugador 2 (j2)
    snprintf(j2->nombre, sizeof(j2->nombre), "Arthas - El Rey Exánime");
    j2->vida = 100;
    j2->defensa = 10;
    j2->defensa_temp = j2->defensa;
    j2->aumento_ataque = 0;
    j2->turnos_polimorfia = 0;

    // Asignación aleatoria de magia para el j2
    for (int i = 0; i < 3; i++) {
        seleccionar_hechizo(j2, i, rand() % 5 + 1);
    }

    // Ejecución del juego por turnos
    while (j1->vida > 0 && j2->vida > 0) {
        // Comprobar si el jugador humano está polimorfado
        if (j1->turnos_polimorfia > 0) {
            printf("%s está polimorfado: beeeee\n", j1->nombre);
            j1->turnos_polimorfia--;
        } else {
            // Turno del jugador 1 
            printf("\nTurno de %s:\n", j1->nombre);
            printf("1. Atacar\n2. Defender\n3. Usar Hechizo\nElige una acción: ");
            int accion;
            scanf("%d", &accion);
            switch (accion) {
                case 1:
                    atacar(j1, j2);
                    break;
                case 2:
                    defender(j1);
                    break;
                case 3:
                    seleccionar_y_lanzar_hechizo(j1, j2); // Selección manual del hechizo
                    break;
                default:
                    printf("Acción no válida.\n");
            }
        }

        // Comprobar si el j2 ha sido derrotado
        if (j2->vida <= 0) break;

        // Reinicia la defensa temporal al valor base antes del turno del j2
        reiniciar_defensa(j2);

        // Turno del jugador 2 (j2)
        if (j2->turnos_polimorfia > 0) {
            printf("%s está polimorfado: beeeee\n", j2->nombre);
            j2->turnos_polimorfia--;
            continue;  // Saltar el turno si está bajo efecto de Polimorfia
        }

        printf("\nTurno de %s:\n", j2->nombre);
        int accion_j2 = rand() % 3 + 1;
        switch (accion_j2) {
            case 1:
                atacar(j2, j1);
                break;
            case 2:
                defender(j2);
                break;
            case 3:
                j2->magia[rand() % 3](j2, j1); // Aplicar hechizo del j2 sobre el jugador 1
                break;
        }

        // Comprobar si j1 ha sido derrotado
        if (j1->vida <= 0) break;

        // Reinicia la defensa temporal al valor base antes del turno del jugador
        reiniciar_defensa(j1);
    }

    // Ganador o perdedor
    if (j1->vida <= 0) {
        printf("\n%s ha perdido. %s gana la partida.\n", j1->nombre, j2->nombre);
    } else {
        printf("\n%s ha perdido, eres el nuevo Rey Exánime!. %s gana la partida.\n", j2->nombre, j1->nombre);
    }

    return 0;
}