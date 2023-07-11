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
    //count is nth pull, fcount = nth pull of 5-star, focount = nth pull of 4-star
    int count = 0, fcount = 0, focount = 0;
    //sum of pulls
    int times = ran();
    //fs = sum of getting 5-star, fos = sum of getting 4-star
    int fs = 0, fos = 0;
    //bound1/1000 is percent of getting 5-star,bound2/1000 is percent of getting 4-star
    int bound1 = 6, bound2 = 51;
    while(count < times){
        int test = (int)rand()%1000;
        //if fcount > 73, percent of getting 5-star will increase 6%
        if(fcount > 73)
            bound1 += 60;
        //if test < bound1 means getting 5-star
        if(test < bound1){
            //sum of getting 5-star adds  1
            fs++;
            //reset fcount &bound1
            fcount = 0;
            bound1 = 6;
        }
        fcount++;
        count++; 
    }
    //reset count
    count = 0;
    while(count < times){
      int test = (int)rand()%1000;
      //if fcount is 8, percent of getting 4-star will de 56.2%
      if(focount ==8)
        bound2 = 562;
      //if focount is more than or equal to 9, percent of getting 4-star will de 99.4%
      if(focount >= 9)
        bound2 = 994;
      //if test < bound2 means getting 4-star
      if(test <= bound2){
        //sum of getting 4-star adds  1
        fos++;
        //reset focount &bound2
        focount = 0;
        bound2 = 51;
      }
      else
        focount++;
      count++;
    }
    printf("test %i times\n", times);
    printf("含保底的五星機率為: %f\n", ((double)fs/times)*100);
    printf("含保底的四星機率為: %f\n",  ((double)fos/times)*100);
}
