#include <stdio.h>
#include <stdlib.h>

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

int main() 
{
  int choice, value, ret;
  printf("\nSTACK:\n");
  while (1) 
  {
    printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
    printf("\n\tChoice : ");
    ret = scanf("%d", &choice);
    switch (choice) 
    {
      case 1:
        printf("\tEnter the value to insert: ");
        ret = scanf("%d", &value);
        push(value);
        break;
      case 2:
        printf("Popped element is :%d\n", pop());
        break;
      case 3:
        display();
        break;
      case 4:
        exit(0);
        break;
      default:
        printf("\nWrong Choice\n");
    }
  }
}