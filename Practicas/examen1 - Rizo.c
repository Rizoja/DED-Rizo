/*  


Alumno: _Jesús Antonio Rizo Muñiz____
    Fecha : 13 de Septiembre 2024
    Diseno de Estructura de Datos - Grupo B
    Primer Parcial "Apuntadores" 

  Teoria                               15 pts
  Ejercicio 1:  Palabra secreta        10 pts
  Ejercicio 2:  °C y °F                15 pts + 10 pts extras
  Ejercicio 3:  Punteros a funcion     10 pts
  Ejercicio 4:  Array + pointers       10 pts
  Ejercicio 5:  Structs                20 pts
  Ejercicio 6:  Array pointers         20 pts                    
                                      _______
                                        110
*/


/* =============================================================
    ====================   Teoria 15 pts =======================
    ============================================================

  1: Describe qué es un apuntador y cuál es su tamaño (no importa tanto el número bytes, sino la teoria detras del tamaño)
    R:
      
  2: Cuando se declara un apuntador, por qué es necesario declarar también el tipo de dato al que apunta?
    R:

  3: Cuál es la diferencia entre pasar por valor y pasar por referencia?
    R:   

  4: Qué es necesario hacer para acceder a los datos de una variable de tipo void *?
    R:

  5: Cómo se recomienda inicializar un apuntador, y por qué es importante esta práctica?
    R:

*/

#include <stdio.h>
#include <stdlib.h>


/* ################      EJERCICIO 01 :    ################################ 
################            10 pts         ################################ 
Implemente una funcion que pueda desencriptar "palabras secretas".
Al recibir una palabra:
  * Si la letra es non, cámbiala por la letra que sigue en el abecedario.
  * Si la letra es par, cámbiala por la letra en el abecedario que está dos espacios atrás.

Ejemplo
            Desencriptar "tpn" debería regresar "uno"
              * "t" es la letra número 1 de mi palabra. Non. Entonces la cambio por una "u".
              * "p" es la letra número 2 de mi palabra. Par. Entonces la cambio por una "n".
              * "n" es la letra número 3 de mi palabra. Non. Entonces la cambio por una "o".

Cambie la palabra directamente en la variable original.
Utilize exclusivamente aritmetica de apuntadores para recorrer la cadena 
de texto, no esta permitido utilizar corchetes [] ni la funcion strlen.
Pruebe que su programa funcione con los ejemplos programados
*/
/*------------------- INICIO RESPUESTA   ------------------ */
 
   

/* ------------------- FIN DE RESPUESTA   ------------------ */

int examen01()
{
  char secreto[10] = "Ewmehqmc";
  printf("Palabra secreta: %s\n",secreto);
  // INICIO RESPUESTA
    //Llama tu funcion aqui, pruebala con la variable secreto.
    //Prueba con mas cadenas para garantizar su funcionamiento.
  
  // FIN DE RESPUESTA
  
  printf("%s", secreto);
  printf("\n");
 
  return 0;
}


/* ################      EJERCICIO 02 :    ################################ 
   ################         15 pts         ################################ 
  Implementa una funcion ConvertirTemp que reciba un float 'temperatura' y un 
  char 'tipo'. La funcion deberá convertir °C a °F y viceversa.
  La funcion debe de afectar directamente ambas variables directamente, es decir no
  retorna nada.

  Si el usuario desea convertir 16 °C deberá de recibir 60.8 °F.
  Si el usuario desea convertir 80 °F deberá de recibir 26.67 °F.

  Fórmulas de conversión:
  °F = (°C x 9 / 5) +32
  °C = (°F - 32) x 5 / 9

*/

/* ------------------- INICIO RESPUESTA   ------------------ */
//Para la función.

/* ------------------- FIN DE RESPUESTA   ------------------ */


int examen02()
{
  char tipo = 'F';      //F = Fahrenheit y C = Celcius
  float  grados = 35;

  printf("Temperatura actual es de: %.2f °%c\n", grados, tipo);

  /* ------------------- INICIO RESPUESTA   ------------------ */
  //covertir_temp(?,?);
  /* ------------------- FIN DE RESPUESTA   ------------------ */
  
  printf("Que equivale a: %.2f °%c\n", grados, tipo);
  
  /* Ahora al revés*/
  tipo = 'C';
  grados = 21;
  printf("Temperatura actual es de: %.2f °%c\n", grados, tipo);

  /* ------------------- INICIO RESPUESTA   ------------------ */
  //covertir_temp(?,?);
  /* ------------------- FIN DE RESPUESTA   ------------------ */

  printf("Que equivale a: %.2f °%c\n", grados, tipo);

  /*El programa debera imprimir: 
    Temperatura actual es de: 35 °F
    Que equivale a: 1.67 °C
    Temperatura actual es de: 21 °C
    Mi dinero convertido es: 69.8 °F  
 */


 /* Por 10 puntos extras: Crea una función llamada covertir_multiple_temps
 que pueda recibir un arreglo de temperaturas y haga funcionar el siguiente
 codigo :  (NOTA, no usar [] en la función) */
 char tipos[4] = {'C','F','C','F'};
 float temps[4] = {45, 110, 0, 0};
 int num_temps = 4;

 //convert_multiple_temps();  DESCOMENTA Y TERMINA .... 
  
 for (int i = 0; i < num_temps; i++)
 {
   printf("La temperatura %d convertida es: %.2f%c\n", i, temps[i], tipos[i]);
 }
  
  return 0;
}


/* ################      EJERCICIO 03 :    ################################ 
################            10 pts         ################################ 
Declara el numero de apuntadores a funcion necesarios para poder
llamar las siguientes 5 funciones. Utiliza el Typedef para crear un nuevo 
tipo de dato apuntador para cada uno de los punteros a funcion que necesites */
void cuadrado(int *num)   
{
  *num = *num * *num;
}

int triplica (int *num)
{
  *num = (*num + *num + *num);
  return;
}

char * convierte(int *ascii, char ** modificador)
{
  return (char*) ascii;
}

int duplica (int *num)
{
  return (*num + *num);
}

int escribe_doble(int *num, char letra)
{
  printf("%c%c",letra,letra);
  return (100);
}

/* Declara tus punteros a funcion aqui: */
/* ------------------- INICIO RESPUESTA   ------------------ */

/* ------------------- FIN DE RESPUESTA   ------------------ */

/* Fin ejercicio 03 */


/* ################      EJERCICIO 04 :    ################################ 
   ################         10 pts         ################################ 
Asigne a los siguientes 2 arrelgos los valores "30, 50, 99" y 'z', 'x' y 'y'
respectivamente pero sin utilizar corchetes. 
Solo apuntadores y aritmetica de apuntadores.

  Salida esperada:
  
    30 - z 
    50 - x 
    99 - y 
 */
void examen04()
{
  int arreglo[3] = {/*No vale inicializar aqui */};
  char las_letras[3] = {/*No vale inicializar aqui */};

  /* ------------------- INICIA RESPUESTA   ------------------ */

  /* ------------------- FIN RESPUESTA   ------------------ */
  
  for(int i = 0; i < 3; i++)
  {
    printf("%d - %c \n", arreglo[i], las_letras[i]);
  }
}



/* ################      EJERCICIO 05 :    ################################
   ################         20 pts         ################################   
  Implementa la funciona mult_condicional:
  recibe   : un void * a una estructura, que contiene un numero y una letra.
  recibe   : otro numero
  
  devuelve : 0. Si la letra es a, b, o c:
  devuelve : la multiplicación de los 2 numeros (la de la estructura y la adicional) si la letra es cualquier otra cosa
             
  Parte 1: Define tu estructura 

  Parte 2: Implementa la funcion mult_condicional()

  Parte 3: Comprueba su funcionamiento en examen05()
*/
/* ------------------- RESPUESTA   ------------------ */
// Declara tu función aquí


int examen05()
{

  return 0;
}
/* ------------------- RESPUESTA   ------------------ */

/* ################      EJERCICIO 06 :    ################################
   ################         20 pts         ################################ 
Dentro de la funcion foo() Interpreta args como un arreglo de punteros
En donde cada posicion de ese arreglo indica un tipo de dato especifico.
  - El arreglo se llena automaticamente en la funcion ejercicio06
  - MyData es un arreglo de apuntadores void.
  - Cada espacio de MyData indica algo diferente

El objetivo es:
  - Aplicar la operacion para "duplicar un numero" sobre el arreglo en 
   la posicion DATA, guardar los resultados en el arreglo representado
    por DOUBLE_RES
  - Aplicar la operacion para "triplicar un numero" sobre el arreglo en 
   la posicion NUM_DATA, guardar los resultados en el arreglo 
   representado por TRIPLE_RES

  Ojo, las funciones "duplicar" y "triplicar" son las mismas del EJERCICIO04
  TIP: Quiza la respuesta del Ejercicio 04, te sea util aqui.

  Ejemplo de salida esperada:
  ==== init ====
  arr[0] = 5
  arr[1] = 6
  arr[2] = 7
  ==== Doubles Result ====
  arr[0] = 10
  arr[1] = 12
  arr[2] = 14
  ==== Triples Result ====
  arr[0] = 15
  arr[1] = 18
  arr[2] = 21
*/

#define MAXELEM 3
#define DOUBLE_OP 0
#define TRIPLE_OP 1
#define DATA 2
#define DOUBLE_RES 3
#define TRIPLE_RES 4

void * foo(void *args)
{
  /* ------------------- RESPUESTA   ------------------ */
  
  /* ------------------- RESPUESTA   ------------------ */
  /* Aqui va la solucion del Ejercicio 06 */
  return NULL;
}

/* No tocar estas funciones */
void InitArray(int *arr, int len)
{
  int *parr = arr;
  for (int i=0;i<len; i++, parr++)
  {
    *parr = 5+i;
  }
}

void PrintArray(int *arr, int len)
{
  int i = 5;
  int *parr = arr;
  for (i=0;i<len; i++, parr++)
  {
    printf("  arr[%d] = %d\n", i, *parr);
  }
}

int examen06(void) {

  int numbers[MAXELEM];
  int doubles[MAXELEM], triples[MAXELEM];
  void * MyData[5] = {};
  void **ptrToMyData = MyData;

  printf("==== init ====\n");
  InitArray(numbers, MAXELEM);
  PrintArray(numbers, MAXELEM);

  MyData[DOUBLE_OP] = duplica;
  MyData[TRIPLE_OP] = triplica;
  MyData[DATA]   = numbers;
  MyData[DOUBLE_RES] = doubles;
  MyData[TRIPLE_RES] = triples;
  
  foo((void *)ptrToMyData);
 
  printf("==== Doubles Result ====\n");
  PrintArray(doubles, MAXELEM);

  printf("==== Triplets Result ====\n");
  PrintArray(triples, MAXELEM);
  return 0;
}/* No tocar estas funciones */


int main()
{
  char nombre[20] = "TUNOMBRE";
  printf("-Examen 01: \n\tPor: \t\t%s\n", nombre);
  
  printf("--------------------ex01 ------------------------\n");
  examen01();
  printf("--------------------ex02 ------------------------\n");
  examen02();
  //ejercicio 3 no imprime nada en pantalla.  
  printf("--------------------ex04 ------------------------\n");        
  examen04();
  printf("--------------------ex05 ------------------------\n");
  examen05();
  printf("--------------------ex06 ------------------------\n");
  examen06();
  
  return 0;
}