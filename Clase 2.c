#include <stdio.h>
#define CLEAR printf("\033[0;0H\033[2J");
/* 
  Excercise 1 : swap
  Create a function that "swaps" the contents of two variables.
  It should receive two intengers, return nothing and after it execution
  whatever what inside one variable should be inside the other and viceversa 
  
*/

/* Excercise 2 : blackjack

Create a blackjack function that:
  -receives 2 numbers and a FLAG (char)
  -returns 1 of the sum of the numbers is positive (greater than 0).
  -returns 0 if the sum of the numbers is negative.
  -Stores the sum of the two numbers in number2.
  -If the sum is 21, set the FLAG to = 'W' (winner)

   IN  IN/OUT  OUT
 (num1, num2, flag)

*/

void swap(int *a, int *b){
        int c = *a;
        *a = *b;
        *b = c;
    }




int main()
{
  CLEAR
  /* Exercise 1:  swap num1 and num2 value */
  int num1 = 10;
  int num2 = 20;
    swap(&num1, &num2);
    printf("numero 1: %d %d numero 2: ",num1,num2);




  /* Exercise 2:  Blackjack 
    Call and test your program here */
  
  return 0;
}