#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//made a random number
int ran(){
    int min = 5000;
    int max = 1000000;

    //x is a number between minand max 
    int x = rand() % (max - min + 1) + min;
    return x;
}

int main(void){
    srand(time(NULL));
    //count is nth pull
    int count = 0;
    //sum of pulls
    int times = ran();
    //fs = sum of getting 5-star, fos = sum of getting 4-star
    int fs = 0, fos = 0;
    while(count < times){
        int test = (int)rand()%1000;
        //if test is less than 6, sum of getting 5-star adds 1
        if(test<6)
            fs++;
        //if test is less than 57, sum of getting 4-star adds 1
        else if(test<57)
            fos++;
        count++;
    }
    printf("test %i times\n", times);
    printf("五星機率為: %f%%\n", ((double)fs/times)*100);
    printf("四星機率為: %f%%\n",  ((double)fos/times)*100);
}

