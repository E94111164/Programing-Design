#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i = 5, j = 10; //leti = 5 j=10 
    printf("%d + %d = %i \n", i, j, i+j); //calculate i+j 
    printf("%d - %d = %i \n", i, j, i-j); //calculate i-j 
    printf("( %d + %d) *15 / %d = %i \n", i, j, i, (i + j) * 15/i); //calculate (i+j)*15/i
}
