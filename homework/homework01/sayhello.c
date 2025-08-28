// Program that prompts user for their name and greets them
// Contributors: Cutovic, Jackson, Smith

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
   char input[25];
   
   printf("What is your name: ");
   scanf("%s", input);
   
   // Extra blank lines and indentation for formatting challenge
   printf("\n\n    Hello, %s!\n\n", input);
   
   exit(0);
}
