#include <stdio.h>
#include <stdlib.h>

//Traete el codigo del STACK aqui, que necesitas hacerle para que
//funcione? Son muy pocos cambios.

/* OJO Todo este stack, funciona solo con numeros enteros, ya que 
el nodo del Stack guarda un valor entero. En el proximo parcial
veremos como mejorar esto y generalizarlo utilizando un 
TDA (Tipo de dato abstracto) */

// Estructura para crear un stack_node, esta tendra el previous node
typedef struct stack_node {
    int info;
    struct stack_node *prev;
}stack_node;

/* STACK GLOBAL */
stack_node *stack_top = NULL;
int count = 0;

// Operacion Push() para meter elementos al stack 
void push(int data) 
{
    // Creación del nuevo nodo
    stack_node *new_node = (stack_node*) malloc(sizeof(stack_node));
    if (new_node == NULL) {
        printf("Desbordamiento de memoria\n");
        return;
    }
    
    // Asignar el valor al nuevo nodo
    new_node->info = data;
    
    // Apuntar el nuevo nodo al previo
    new_node->prev = stack_top; 
    
    // El nuevo nodo es el primer valor
    stack_top = new_node;
    
    count++;  // Incrementar los elementos

}

// Para esta version de stack de enteros, regresa -1 si no hay 
// nada que hacer pop
int pop() 
{
    if (stack_top == NULL) {
        printf("Stack vacío\n");
        return -1;
    }

    // Guardar el valor del superior
    int popped_value = stack_top->info;

    // Mover el top al siguiente nodo
    stack_node *temp = stack_top;
    stack_top = stack_top->prev;

    // Liberar la memoria del nodo eliminado
    free(temp);
    count--; //decrementar los elementos

    return popped_value;

}

// Muestra los elementos actuales del stack
void display() 
{
  stack_node * nptr = stack_top;
  
  if (nptr == NULL)
  {
      printf("\nNingun Elemento en el stack\n");
      return;
  }
  
  printf("The stack is \n");
  while (nptr != NULL)
  {
      printf("%d--->", nptr->info);
      nptr = nptr->prev;
  }
  printf("NULL\n\n");
  
}

void isvalidformula(char * formula)
{
  //Imprime aqui si la formula "f" recibida esta bien formada o no
int indice = 0;
    
    // Recorremos la fórmula caracter por caracter
    while (formula[indice] != '\0') {
        if (formula[indice] == '(') {
            // Insertar paréntesis de apertura en el stack
            push(1);  // Usamos 1 para representar '('
        } else if (formula[indice] == ')') {
            // Si encontramos un paréntesis, realizamos pop
            if (pop() == -1) {
                // Si el stack estaba vacío, la fórmula no está bien
                printf("La fórmula '%s' no está bien formada\n", formula);
                return;
            }
        }
        indice++;
    }

    // Verificar si el stack está vacío al final
    if (stack_top == NULL) {
        printf("La fórmula '%s' está bien formada\n", formula);
    } else {
        printf("La fórmula '%s' no está bien formada\n", formula);
    }
    
    // Vaciar el stack si quedan elementos
    while (stack_top != NULL) {
        pop();
    }

}

int main() 
{
  char formula1[30] = "aa()bb((c))(ddd((rr((a)a)))";
  char formula2[30] = "((a+b)-(z*d))";

  isvalidformula(formula1);
  isvalidformula(formula2);
}