#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//transform cars suit &number
void shuffle(int x, int cardnum[13], int cardsuit[13]){
    char suit;
    char num;
    for(int i = 0; i < x; i++){
        //transform int to char
        int m = cardnum[i]+48;
        switch(cardsuit[i]){
            case 0:
                suit = 'S';
                break;
            case 1:
                suit = 'H';
                break;
            case 2:
                suit = 'D';
                break;
            case 3:
                suit = 'C';
                break;
        }
        switch(cardnum[i]){
            case 1:
                num = 'A';
                break;
            case 11:
                num = 'J';
                break;
            case 12:
                num = 'Q';
                break;
            case 13:
                num = 'K';
                break;
            default:
                num = (char)m;
                break;
        }
        //if number is 10, printf int cardnum[i]
        if(cardnum[i] !=10)
          printf("%c %c\n", suit, num);
        else
          printf("%c %d\n", suit, cardnum[i]);
    }
}

//transform suit in permulation
void changesuit(int s){

	char suit;
	switch(s){
		case 0:
			suit = 'S';
			break;
		case 1:
			suit = 'H';
			break;
		case 2:
			suit = 'D';
			break;
		case 3:
			suit = 'C';
			break;
	}
	printf("%c", suit);
}

void changenum(int s){
    char num;
    switch(s){
        case 1:
            num = 'A';
            break;
        case 11:
            num = 'J';
            break;
        case 12:
            num = 'Q';
            break;
        case 13:
            num = 'K';
            break;
    }
    if(s >10 || s == 1)
        printf("%c ", num);
    else
        printf("%d ", s);

}

// swap two number
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//all permutation
void permute(int* arr, int* arr2, int start, int end) {
    if (start == end) {
        for (int i = 0; i <= end; i++) {
			changesuit(arr2[i]);
            changenum(arr[i]);
        }
        printf("\n");
    } 
    else {
        for (int i = start; i <= end; i++) {
            //swap array
            swap((arr + start), (arr + i));
			swap((arr2 + start), (arr2 + i));
            //permutation of start+1
            permute(arr, arr2, start + 1, end);
            //return to original array
            swap((arr + start), (arr + i)); 
			swap((arr2 + start), (arr2 + i));
        }
    }
}

int main(void) {
    srand(time(NULL));
    int cardnum[13] = {0}, cardsuit[13] = {0}, x;
    while(1){
        printf("How many cards do you want:");
        scanf("%i", &x);
        if(x > 13 || x < 1){
            printf("input wrong number!\n");
            continue;
        }   
        else{
            int i, j;
            //avoid dealing duplicate card
            for(i = 0; i < x; i++){
                int m = rand();
                cardnum[i] = m%13+1;
                cardsuit[i] = m%4;
                for(j = 0; i > j; j++){
                    if(cardsuit[i] == cardsuit[j] && cardnum[i] == cardnum[j]){
                        cardnum[i] = 0;
                        cardsuit[i] = 0;
                        i--;
                        break;
                    }
                }
            }
            //show card
            shuffle(x, cardnum, cardsuit);
            break;
        }
    }
    while(1){
        int i, j;
        printf("Do you want deal again(y/n):");
        char ans;
        scanf(" %c", &ans);
        if(ans == 'y'){
            //return to rezo for deal again
            for(i = 0; i < 13; i++){
                cardnum[i] = 0;
                cardsuit[i] = 0;
            }
            for(i = 0; i < x; i++){
                int m = rand();
                cardnum[i] = m%13+1;
                cardsuit[i] = m%4;
                for(j = 0; i > j; j++){
                    if(cardsuit[i] == cardsuit[j] && cardnum[i] == cardnum[j]){
                        cardnum[i] = 0;
                        cardsuit[i] = 0;
                        i--;
                        break;
                    }
                }
            }
            shuffle(x, cardnum, cardsuit);
        }
        else if(ans == 'n'){  
            //Poka Yoke
            do{
                printf("Do you want to list all sorts(y/n):");
                scanf(" %c", &ans);
                if(ans =='n'){
                    printf("End!\n");
                    break;
                }
                else if(x > 6 && ans == 'y'){
                    
                    do{
                        printf("there are lots of permulations,are you sure to show all?:");
                        scanf(" %c",&ans);
                        if(ans =='n'){
                            break;
                        }
                        else if(ans == 'y'){
                            printf("All permutation：\n");
                            permute(cardnum, cardsuit, 0, x-1);
                            printf("End!\n");
                            break;
                        }
                        //Poka Yoke
                        else{
                            printf("input wrong!\n");
                            ans ='y';
                        }
                    }while(ans == 'y');
                    break;
                }

                else if(x <= 6 && ans == 'y'){
                    printf("All permulation:\n");
                    permute(cardnum, cardsuit, 0, x-1);
                    printf("End!\n");
                    break;
                }

            }while(ans != 'n');
            break;
        }
        //Poka Yoke
        else
            printf("input wrong\n");
    }   
}
