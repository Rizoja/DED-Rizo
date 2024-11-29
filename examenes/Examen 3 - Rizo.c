// INICIA RESPUESTA
// Para que agregues tus Librerías para los ejercicios prácticos.

// TERMINA RESPUESTA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char alumno[100] = "Jesús Antonio Rizo Muñiz";

/*  

    Fecha : 29 de Noviembre 2024
    Diseno de Estructura de Datos - Grupo B
    Tercera Evaluación Síncrona

  Teoría 1:     6 preguntas de 5 puntos       /30 pts
  Teoría 2:     4 preguntas de 10 puntos      /40 pts
  Ejercicio 1:  Map                           /20 pts
  Ejercicio 2:  Priority Queue                /20 pts               
       
                                            ________
  Calificación Final:                         /110 puntos
*/

/*
******************************************************** Teoría 1: 6 preguntas de 5 puntos       /30 pts **************************************************************

1)	Explica cuál es la diferencia entre una función pública y una función privada?

  R= Las Funciones públicas, son accesibles desde cualquier parte del programa que utiliza la librería. 
  Pertenecen al archivo de encabezado (.h) y forman parte de la interfaz pública del TDA. 
  A diferencia de las Funciones privadas, que solo son accesibles dentro del archivo donde se definen. 
  Estas funciones suelen estar declaradas como static en C y no forman parte de la interfaz pública. 
  Se usan para realizar operaciones internas sin ser visibles al usuario de la librería.

2)  Menciona una diferencia entre una cola (ordinaria) y una cola de prioridad, desde el punto de vista de su comportamiento, no de su implementación:

  R= En la cola ordinaria, los elementos se consideran en el orden en que llegan, siguiendo la política FIFO (First In, First Out).
    y en la cola de prioridad, los elementos se ven según su prioridad, sin importar el orden en el que llegaron. 

3)  Explica a detalle la importancia de la función "hash" al implementar un Mapa / Tabla Hash, y por qué se le aplica la operación de módulo.

  R= La importancia de la función hash al implementarla en un mapa, es que convierte una "clave" en un índice dentro de un rango predefinido. 
  Esto nos permite acceder al valor asociado con esa clave, logrando eficientar las búsquedas en comparación con listas o arreglos.
  La operación de módulo asegura que el índice generado (clave) esté dentro del rango válido del arreglo de la tabla hash. 


4)	¿Por qué implementamos un conjunto mediante un árbol binario de búsqueda en lugar de utilizar una lista enlazada o un arreglo? Justifica bien tu respuesta.	

  R= Un "árbol binario de búsqueda" tiene una complejidad de búsqueda, inserción y eliminación promedio de O(log n) (Notación "Big-O"), lo que es más eficiente que
una lista enlazada, donde se requiere una búsqueda lineal (O(n)) para determinar si un elemento ya existe.
El Arreglo también necesita una búsqueda lineal para verificar duplicados, además de requerir redimensionamiento dinámico si se llena.
El árbol binario de búsqueda también mantiene los elementos en orden, lo que permite recorridos en tiempo lineal para operaciones como listar elementos ordenados.

5)	Al crear un TDA / Librería ¿Por qué utilizamos void pointers en lugar de datos de un tipo específico?

  R= Los void pointers permiten que el TDA sea genérico y pueda almacenar cualquier tipo de dato sin depender de un tipo específico como int o float.


6) Menciona una diferencia entre un conjunto y un mapa, desde el punto de vista de su comportamiento, no de su implementación:

  R=

******************************************************** Teoría 2: 4 preguntas de 10 puntos       /40 pts **************************************************************

7)  Dibuja cómo queda el siguiente árbol binario de búsqueda después de insertar 14, 5 y 13 (en este orden). 

             10
          /      \
        3         16
      /   \      /   \
    1      8   11     18 
   /     /              \
  0     6                20

  R=


8) Asume que se crea un montículo binario "máximo" a partir del siguiente arreglo.:
    4, 7, 10, 5, 12, 15, 22, 8, 17, 1
    a) ¿Cómo queda el montículo binario (MaxHeap) inicialmente?  Puedes mostrar la respuesta como montículo binario (dibujo) o como arreglo.
 
      R=

    b) ¿Cómo queda el montículo binario (MaxHeap) de arriba después de ejecutar offer(18)?  Puedes mostrar la respuesta como montículo binario (dibujo) o como arreglo.
 
      R=

    b) ¿Cómo queda el montículo binario (MaxHeap) de arriba después de ejecutar poll()? Puedes mostrar la respuesta como montículo binario (dibujo) o como arreglo.

      R=

9)	Asume que existe una Tabla Hash que almacena fechas, y se encuentra en el siguiente estado:

HashIndex
    0   -> |31/10/1987| -> NULL
    1   -> |02/06/2012| -> |19/01/1123| -> NULL
    2   -> |01/01/2024| -> |28/05/1546| -> NULL
    3   -> NULL
    4   -> |03/11/1990| -> NULL
    5   -> |31/12/1987| -> |15/03/2025| -> |19/07/1999| -> NULL
    6   -> |31/08/2005| -> NULL

Asume que el hashing se hace de la siguiente manera:
  
  int DateHash(int dia, int mes, int anyo){
    int hash;
    
    if(anyo >= 2000)
      hash = (dia * mes) + anyo;
    else
      hash = dia + (mes * anyo);

    return hash % 7;
  }

  Dibuja la Tabla Hash resultante después de ejecutar map_put("02/02/2000") y map_put("11/11/1111");
  
  R=


10)	Acabas de instalar la siguiente librería para el uso de colas simples:
//Entiéndela bien antes de continuar.

      #ifndef QUEUE_H
      #define QUEUE_H
      // Tamaño máximo de la cola
      #define MAX 5

      // Estructura de la cola
      typedef struct Queue {
          int items[MAX];
          int front, rear;
      } Queue;

      // Declaración de funciones
      void initQueue(Queue *q);
      void enqueue(Queue *q, int value);
      int dequeue(Queue *q);
      void displayQueue(Queue *q);

      #endif // QUEUE_H


  Imagina que en tu "main" tienes el siguiente código:

      Queue q, z;
      initQueue(&q);
      initQueue(&z);

      enqueue(&q, "Jesus");
      enqueue(&z, "Zyanya");
      enqueue(&q, "Jorge");
      dequeue(&z);
      enqueue(&q, "Sofia"");
      enqueue(&q, "Erick");
      enqueue(&q, "Diego");
      enqueue(&q, "Chava");
      dequeue(&q);
      dequeue(&z);
      enqueue(&q, "Nicole");

      displayQueue(&q);
      return 0;

  Escribe o dibuja el estado final de la cola "q".

  R= 


******************************************************** Ejercicio 1: Mapa                 /20 pts **************************************************************

/* 
   
   Guarda en un mapa, la relacion de cuantas repeticiones por cada numero existen
   en siguiente arreglo:

   {1,1,1,2,3,0,1,2,5,5,1}

  numero | veces
    1    |   5
    2    |   2
    3    |   1
    5    |   2

  Puedes agregar cualquier librería que hayas hecho en clase o en tu proyecto.

*/
/* INICIA RESPUESTA */
// El mapa necesita 2 funciones y tal vez una estructura, declaralas aqui:


/* FIN DE RESPUESTA */

void ejercicio1()
{
  /* Comprueba que funciona consultando algun numero 
    (el que tu quieras) */
  int arreglo[] = {1,1,1,2,3,0,1,2,5,5,1};
  int size = 11;

  // INICIA RESPUESTA
  
  // TERMINA RESPUESTA
}

/*
******************************************************** Ejercicio 2: Priority Queue              /20 pts **************************************************************

   Este ejercicio tiene un TDA que guarda un color, utilizando sus valores en RGB de 0 a 255.
    *R = Red = Rojo
    *G = Green = Verde
    *B = Blue = Azul
   Referencia: https://www.rapidtables.com/web/color/RGB_Color.html

   Crea una Priority Queue (Cola de prioridad) para guardar 5 colores.
   Puedes agregar cualquier librería que hayas hecho en clase o en tu proyecto.

   Una vez guardados:
   Extrae todos los colores (uno por uno) y comprueba que salen en el orden deseado.
   Cuál es ese orden? Solo hay 2 reglas:
    * El color con más rojo (R) es el más importante.
    * En caso de empate en rojo (R), utliza Azul (B) para desempatar.
*/

typedef struct color
{
  char name[15];
  int r;
  int g;
  int b;
} color;

/* INCIA RESPUESTA */
// aqui va una función que el priority queue necesita para funcionar


/* TERMINA RESPUESTA */

void ejercicio2()
{
  //Inicialización de colores.
  color c1, c2, c3, c4, c5;
  snprintf(c1.name, sizeof(c1.name), "Negro");
  c1.r=0;c1.g=0;c1.b=0;
  snprintf(c2.name, sizeof(c2.name), "Blanco");
  c2.r=255;c2.g=255;c2.b=255;
  snprintf(c3.name, sizeof(c3.name), "Limon");
  c3.r=120;c3.g=200;c3.b=10;
  snprintf(c4.name, sizeof(c4.name), "Naranja");
  c4.r=255;c4.g=153;c4.b=51;
  snprintf(c5.name, sizeof(c5.name), "Aqua");
  c5.r=120;c5.g=180;c5.b=180;

  /* INCIA RESPUESTA */
  // Inserta los 5 colores de arriba, sin importar el orden, comprueba
  // que al extraerlos, siempre sale el de mayor prioridad.


  /* FIN DE RESPUESTA */
}

int main()
{
  printf("Examen Parcial 3 de : %s\n", alumno);
  printf("\n----- Ejercicio 1:-----\n\n");
  ejercicio1();
  printf("\n----- Ejercicio 2:-----\n\n");
  ejercicio2();
}
