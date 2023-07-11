#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


//mood one function
void first(){
  //n[4]is a array with 4 different numbers between 0 to 9、counter[10] comfirms whether is the i-th number used、numis i-th number
  int n[4], i, j, counter[10] = {0},num;
  //make a array with 4 different numbers between 0 to 9
  for(i = 0;i < 4;i++){
      do{
        n[i] = rand()%10;
        num = n[i];
      }while(counter[num] != 0);
      counter[num]++;
  }
  
  while(1){
    //record sum of A and B
    int a = 0,b = 0;
    //user input a string
    char pla[200];
    printf("請輸入一個四位不重複的數字: ");
    scanf("%s", pla);
    //transform char to int
    int arr[4];
    for(i = 0; i < 4;i++){
      arr[i] = (int)pla[i]-48;
    }
    //if there are any number same in the array, it means having duplicate number
    if(arr[0]==arr[1] || arr[0]==arr[2] || arr[0]==arr[3] || arr[1]== arr[2] || arr[1]==arr[3] || arr[2]==arr[3]){
      printf("玩家輸入了一個有重複的四位數，請重新輸入\n");
    }
    //if the length of array != 4, user need to input the answer again
    else if( strlen(pla) != 4)
      printf("玩家輸入了一個並非四位的數，請重新輸入\n");
    //random number maked by computer is same as user's answer, end the mood
    else if(n[0] == arr[0] && n[1] == arr[1] && n[2] == arr[2] && n[3] == arr[3]){
      a = 4;
      b = 0;
      printf("玩家輸入的數字和謎底相差為%i A %i B\n", a, b);
      break;
    }
    else{
      for(i = 0; i < 4; i++){
        for(j = 0; j <4; j++){
          //if arr[i] == n[j], it means a or b change 
          if(arr[i] == n[j]){
            //i=j means a+1
            if(i == j)
              a++;
            //i!=j means B+1
            else
              b++;
          }
        }
      }
      printf("玩家輸入的數字和謎底相差為%i A %i B\n", a, b);
  }

  }
}
//mood two function
void second(){
  char ans[200];
  int arr[4];
  //n[4]is a array with 4 different numbers between 0 to 9、num is i-th number,a is sum of A, b is sum of b
  int n[4], i, j, num, a, b, times = 0;
  while(1){
    printf("請玩家輸入四位數謎底: ");
    scanf("%s", ans);
    //transform char to int
    for(int i = 0; i < 4;i++){
      arr[i] = (int)ans[i]-48;
    }
    //if there are any number same in the array, it means having duplicate number
    if(arr[0]==arr[1] || arr[0]==arr[2] || arr[0]==arr[3] || arr[1]== arr[2] || arr[1]==arr[3] || arr[2]==arr[3]){
      printf("玩家輸入了一個有重複的四位數，請重新輸入\n");
    }
    //if the length of array != 4, user need to input the answer again
    else if(strlen(ans) != 4){
      printf("玩家輸入了一個並非四位的數，請重新輸入\n");
    }
    //it's right format
    else
      break;
  }
  while(1){
    //a, b return to 0
    a =0; b = 0;
    //counter[10] comfirms whether is the i-th number used
    int counter[10] = {0};
    //make a array with 4 different numbers between 0 to 9
    for(i = 0;i < 4; i++){
      do{
        n[i] = rand()%10;
        num = n[i];
      }while(counter[num] != 0);
      counter[num]++;
    }
    for(i = 0; i < 4; i++){
        for(j = 0; j <4; j++){
          //if arr[i] == n[j], it means a or b change 
          if(arr[i] == n[j]){
            //i=j means a+1
            if(i == j)
              a++;
            //i!=j means B+1
            else
              b++;
          }
        }
    }
    times++;
    if(a == 4)
      
      break;
  }
  printf("電腦猜測了%i後猜對答案\n", times);
}

//mood third function
void third(){
  //n[5]is a array with 5 different numbers between 0 to 9、counter[10] comfirms whether is the i-th number used、numis i-th number
  int n[5], i, counter[10] = {0},num;
  ////make a array with 5 different numbers between 0 to 9
  for(i=0;i<5;i++){
      do{
        n[i] = rand()%10;
        num = n[i];
      }while(counter[num] != 0);
      counter[num]++;
  }
  
  //無限迴圈，直到玩家輸入正確才break
  while(1){
    ///record sum of A and B
    int a = 0,b = 0;
    //user input a string
    char pla[200];
    printf("請輸入一個五位不重複的數字: ");
    scanf("%s", pla);
    //transform char to int
    int arr[5];
    for(int i = 0; i < 5;i++){
      arr[i] = (int)pla[i]-48;
    }
    ////if there are any number same in the array, it means having duplicate number
    if(arr[0]==arr[1] || arr[0]==arr[2] || arr[0]==arr[3] || arr[0]==arr[4] || arr[1]==arr[2] || arr[1]==arr[3] || arr[1]==arr[4] || arr[2]==arr[3] || arr[2]==arr[4] || arr[3]==arr[4])
      printf("玩家輸入了一個有重複的五位數，請重新輸入\n");
    //if the length of array != 5, user need to input the answer again
    else if(strlen(pla) != 5)
      printf("玩家輸入了並非五位的數，請重新輸入\n");
    //random number maked by computer is same as user's answer, end the mood
    else if(n[0] == arr[0] && n[1] == arr[1] && n[2] == arr[2] && n[3] == arr[3] && n[4] == arr[4]){
      a = 5;
      b = 0;
      printf("玩家輸入的數字和謎底相差為%i A %i B\n", a, b);
      break;
    }
    else{
      for(int i = 0; i < 5; i++){
        for(int j = 0; j <5; j++){
          //if arr[i] == n[j], it means a or b change 
          if(arr[i] == n[j]){
            //i=j means A+1
            if(i == j)
              a++;
            //i!=j meansB+1
            else
              b++;
          }
        }
      }
      printf("玩家輸入的數字和謎底相差為%i A %i B\n", a, b);
    }

  }
}



int main(void) {
  srand(time(NULL));
  int num;
  //introduce the game
  printf("mood1：電腦為出題者，使用者為答題者。謎底由電腦亂數給定。\nmood2：使用者為出題者，電腦為答題者。謎底由使用者輸入。\nmood3：五位數版本之電腦為出題者，使用者為答題者。\nmood4：遊戲結束\n");
  while(1){
    printf("請輸入1~4之間的整數選擇遊戲模式: ");
    scanf("%i", &num);
    //get in mood 1
    if(num==1){
      first();
    }
    //get in mood 2
    else if(num==2){
      second();
    }
    //get in mood 3
    else if(num==3){
      third();
    }
    //get in mood 4, end game
    else if(num == 4){
      printf("玩家選擇模式4，遊戲結束!");
      break;
    }
    //input again
    else{
      printf("玩家輸入了不符合格式的答案，請重新輸入\n");
    }
  }
  system("pause");
  return 0;
}
