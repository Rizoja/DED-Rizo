/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CLEAR printf("\033[0;0H\033[2J");

void ex01();

int longitudCadena(char *cadena);
void ex02();

void convertirMinusculas(char *cadena);
void ex03();

int esBinario(char *cadena);
void ex04();

int main() {
    printf("Ejercicio 1:\n");
    ex01();
    
    printf("\nEjercicio 2:\n");
    ex02();
    
    printf("\nEjercicio 3:\n");
    ex03();
    
    printf("\nEjercicio 4:\n");
    ex04();

    return 0;
}

void ex01()
{
  /* Excerice 01:
  Create an array of 10 integers, set their value (whatever you want)
  Using pointer arithmetic and a for loop traverse and print all the array

  DO NOT USE BRACKETS [ ]
  
  Print both the value and the address.
  
  ie
    int array = [ 2 , 3 , 5 , 6]

    array[0] = 2 -> addr = 0x00001
    array[1] = 3 -> addr = 0x00004
    array[2] = 5 -> addr = 0x00008
    array[3] = 6 -> addr = 0x0000B
*/

    int nums[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int *p = nums;

    for(int i = 0; i < 10; i++) {
        printf("nums[%d] = %d -> dir = %p\n", i, *(p + i), (p + i));
    
  }
}

int longitudCadena(char *cadena) 
{
    char *aux = cadena;
    int contador = 0;

    while (*aux != '\0') {
        contador++;
        aux++;
    }

    return contador;
}
void ex02()
{
  /* Excercise 02:
  Implement a function mylenght() that returns the size of the passed 
  string (char array). DO NOT USE strlen(), use only pointer arithmetic.

  DO NOT USE BRACKETS [ ]

  TIP: all strings are array of chars, terminated by '\0' character.
*/

    char texto[] = "Jesus Antonio Rizo Muñiz";
    printf("Longitud de la cadena: %d\n", longitudCadena(texto));


}

void convertirMinusculas(char *cadena) 
{
    char *aux = cadena;
    while (*aux != '\0') {
        if (*aux >= 'A' && *aux <= 'Z') {
            *aux += 32;
        }
        aux++;
    }
}
void ex03() 
{
    char mensaje[] = "Dime QUE Esta EN MinusCulAS";
    convertirMinusculas(mensaje);
    printf("Texto en minúsculas: %s\n", mensaje);
}


int esBinario(char *cadena) 
{
    char *aux = cadena;
    while (*aux != '\0') {
        if (*aux != '0' && *aux != '1') {
            return 0; 
        }
        aux++;
    }
    return 1; 
}
void ex04()
{
    char entrada[] = "110010148518";
    if (esBinario(entrada)) {
        printf("La cadena es binaria.\n");
    } else {
        printf("La cadena NO es binaria.\n");
    }
}


/* More practice excerises (similar to Ex02)

  NOTA :    No utilizar arreglos o corchetes dentro de
            ninguna de las 2 funciones.

  Excercise 03
  Implementa una funcion, que reciba por referencia un arreglo,
  recorra este arreglo y cambie cualquier mayuscula a minuscula, 
  el arreglo se debe de imprimir de vuelta en el main  Tip: ASCII table

  Exercise 04
  Implementa una función isBinary que reciba una cadena de texto de consola
  y determine si está formada exclusivamente por dígitos binarios (0, 1). 
  
*/
