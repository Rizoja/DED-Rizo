#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///////////////////////////////////////////// Estructuras /////////////////////////////////////////
typedef struct Nodo {
    char pieza;
    struct Nodo *norte;
    struct Nodo *sur;
    struct Nodo *este;
    struct Nodo *oeste;
} Nodo;

typedef struct {
    int fila;
    int columna;
} Coordenadas;

typedef struct Movimiento {
    char posicion[3];
    int valor;
} Movimiento;

typedef struct StackNode {
    Movimiento movimiento;
    struct StackNode *siguiente;
} StackNode;
///////////////////////////////////////////// Estructuras /////////////////////////////////////////

/////////////////////////////////////////// Tablero de Ajedrez ////////////////////////////////////

Nodo* crearTablero() {
    Nodo *inicio = NULL; // Puntero al inicio del tablero
    Nodo *filaAnterior = NULL; // Puntero a la fila anterior
    Nodo *actual = NULL; // Nodo actual

    for (int i = 0; i < 8; i++) {
        Nodo *filaInicio = NULL;
        Nodo *nodoAnterior = NULL;

        for (int j = 0; j < 8; j++) {
            Nodo *nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
            nuevoNodo->pieza = '.';
            nuevoNodo->norte = NULL;
            nuevoNodo->sur = NULL;
            nuevoNodo->este = NULL;
            nuevoNodo->oeste = NULL;

            if (i == 0 && j == 0) {
                inicio = nuevoNodo;
            }

            if (nodoAnterior != NULL) {
                nodoAnterior->este = nuevoNodo;
                nuevoNodo->oeste = nodoAnterior;
            }

            if (filaAnterior != NULL) {
                Nodo *nodoArriba = filaAnterior;
                for (int k = 0; k < j; k++) {
                    nodoArriba = nodoArriba->este;
                }
                nodoArriba->sur = nuevoNodo;
                nuevoNodo->norte = nodoArriba;
            }

            if (j == 0) filaInicio = nuevoNodo;
            nodoAnterior = nuevoNodo;
        }
        filaAnterior = filaInicio;
    }
    return inicio;
}

/////////////////////////////////////////// Tablero de Ajedrez /////////////////////////////////////////

////////////////////////////////////////// Dirección Cardinal /////////////////////////////////////////

Nodo* obtenerNorte(Nodo* n) { return n->norte; }
Nodo* obtenerSur(Nodo* n) { return n->sur; }
Nodo* obtenerEste(Nodo* n) { return n->este; }
Nodo* obtenerOeste(Nodo* n) { return n->oeste; }

////////////////////////////////////////// Dirección Cardinal /////////////////////////////////////////

////////////////////////////////////////// Coordenadas a indices /////////////////////////////////////////

void convertirCoordenadas(const char* coord, int* fila, int* columna) {
    if (coord == NULL || fila == NULL || columna == NULL || strlen(coord) != 2) {
        printf("Error: Coordenadas inválidas o mal formateadas.\n");
        *fila = -1;
        *columna = -1;
        return;
    }
    *columna = coord[0] - 'A';
    *fila = 8 - (coord[1] - '0');
}

////////////////////////////////////////// Coordenadas a indices /////////////////////////////////////////

////////////////////////////////////////// Llenar tablero desde el file //////////////////////////////////

Coordenadas llenarTablero(Nodo* tablero, const char* nombreArchivo, Nodo** posicionTorre) {
    Coordenadas coordenadas = {-1, -1};
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return coordenadas;
    }

    Nodo *filaInicio = tablero;
    Nodo *nodoActual = filaInicio;

    for (int i = 0; i < 8; i++) {
        nodoActual = filaInicio; // Reinicia al inicio de cada fila
        for (int j = 0; j < 8; j++) {
            char pieza;
            fscanf(archivo, " %c", &pieza); // Leer la pieza
            nodoActual->pieza = pieza; // Asignar la pieza

            nodoActual = nodoActual->este; // Mover al siguiente nodo en la fila
        }
        filaInicio = filaInicio->sur; // Mover al inicio de la siguiente fila
    }

    
    char coordenadasStr[3];
    fscanf(archivo, "%s", coordenadasStr);
    convertirCoordenadas(coordenadasStr, &coordenadas.fila, &coordenadas.columna);
    fclose(archivo);

    // Posicionar la torre
    Nodo *nodo = tablero;
    for (int i = 0; i < coordenadas.fila; i++) {
        nodo = nodo->sur;
    }
    for (int j = 0; j < coordenadas.columna; j++) {
        nodo = nodo->este;
    }

    if (nodo->pieza == 'T') {
        *posicionTorre = nodo;  
    } else {
        *posicionTorre = NULL;  // Si no es una torre NULL
    }

    return coordenadas;
}
////////////////////////////////////////// Llenar tablero desde el file //////////////////////////////////

///////////////////////////////////////// Movimientos de Torre //////////////////////////////////////////

void pushOrdenado(StackNode** top, Movimiento movimiento) {
    StackNode *nuevoNodo = (StackNode*)malloc(sizeof(StackNode));
    nuevoNodo->movimiento = movimiento;

    if (*top == NULL || movimiento.valor >= (*top)->movimiento.valor) {
        nuevoNodo->siguiente = *top;
        *top = nuevoNodo;
    } else {
        StackNode *actual = *top;
        while (actual->siguiente != NULL && actual->siguiente->movimiento.valor > movimiento.valor) {
            actual = actual->siguiente;
        }
        nuevoNodo->siguiente = actual->siguiente;
        actual->siguiente = nuevoNodo;
    }
}

void agregarMovimiento(StackNode** stack, Nodo* nodo, int fila, int columna) {
    Movimiento mov;
    sprintf(mov.posicion, "%c%d", 'A' + columna, 8 - fila);
    mov.valor = nodo->pieza == '.' ? 0 : (nodo->pieza == 'P' ? 1 : (nodo->pieza == 'A' || nodo->pieza == 'C' ? 3 : nodo->pieza == 'T' ? 5 : nodo->pieza == 'Q' ? 8 : 10));
    printf("Agregando movimiento: %s - Valor: %d\n", mov.posicion, mov.valor);
    pushOrdenado(stack, mov);
}

void explorarDireccion(StackNode** stack, Nodo* actual, Nodo* (*direccion)(Nodo*), int fila, int columna, int deltaFila, int deltaColumna) {
    Nodo* siguiente = direccion(actual);
    int nuevaFila = fila + deltaFila;
    int nuevaColumna = columna + deltaColumna;

    while (siguiente != NULL) {
        agregarMovimiento(stack, siguiente, nuevaFila, nuevaColumna);  // Agrega todos los movimientos, incluso vacíos

        if (siguiente->pieza != '.') {
            break;
        }

        siguiente = direccion(siguiente);  // Avanzar en la misma dirección
        nuevaFila += deltaFila;
        nuevaColumna += deltaColumna;
    }
}



void encontrarMovimientosTorre(Nodo* torre, StackNode** stack, int fila, int columna) {
    printf("Posición inicial de la Torre: Fila %d, Columna %d\n", fila, columna);

    explorarDireccion(stack, torre, obtenerNorte, fila, columna, -1, 0);
    explorarDireccion(stack, torre, obtenerSur, fila, columna, 1, 0);
    explorarDireccion(stack, torre, obtenerEste, fila, columna, 0, 1);
    explorarDireccion(stack, torre, obtenerOeste, fila, columna, 0, -1);
}

///////////////////////////////////////// Movimientos de Torre //////////////////////////////////////////

//////////////////////////////////////// Imprimir el stack //////////////////////////////////////////////

void imprimirStack(StackNode* top) {
    if (top == NULL) {
        printf("El stack está vacío. No se encontraron movimientos con valor.\n");
        return;
    }

    int index = 1;
    while (top != NULL) {
        if (top->movimiento.valor > 0) {  // Imprimir solo si el valor es mayor que 0
            printf("%d. %s - %d\n", index++, top->movimiento.posicion, top->movimiento.valor);
        }
        top = top->siguiente;
    }
}

//////////////////////////////////////// Imprimir el stack //////////////////////////////////////////////

/////////////////////////////////////// Free Tablero ///////////////////////////////////////////////////

void liberarTablero(Nodo* tablero) {
    Nodo *filaInicio = tablero;
    while (filaInicio != NULL) {
        Nodo *nodoActual = filaInicio;
        filaInicio = filaInicio->sur;
        while (nodoActual != NULL) {
            Nodo *temp = nodoActual;
            nodoActual = nodoActual->este;
            free(temp);
        }
    }
}


void liberarStack(StackNode* top) {
    while (top != NULL) {
        StackNode *temp = top;
        top = top->siguiente;
        free(temp);
    }
}


/////////////////////////////////////// Free Tablero ///////////////////////////////////////////////////

/////////////////////////////////////////////// Main //////////////////////////////////////////////////

int main() {
    char nombreArchivo[100];
    printf("Ingrese el nombre del archivo de entrada: ");
    scanf("%s", nombreArchivo);

    Nodo* tablero = crearTablero();
    Nodo* posicionTorre = NULL;

    // Llenar el tablero y obtener la posición de la Torre
    Coordenadas coordenadas = llenarTablero(tablero, nombreArchivo, &posicionTorre);

    if (posicionTorre == NULL) {
        printf("Error: No se pudo encontrar la Torre en el tablero.\n");
        liberarTablero(tablero);
        return 1;
    }

    StackNode* movimientos = NULL;
    encontrarMovimientosTorre(posicionTorre, &movimientos, coordenadas.fila, coordenadas.columna);

    printf("Movimientos de la Torre en orden de valor:\n");
    imprimirStack(movimientos);

    liberarStack(movimientos);
    liberarTablero(tablero);
    return 0;
}

/////////////////////////////////////////////// Main //////////////////////////////////////////////////
