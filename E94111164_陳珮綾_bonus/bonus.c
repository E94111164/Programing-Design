#include <stdio.h>
#include <stdlib.h>

//set a node with data and pointer
struct node{
    int data;
    struct node *next;
};typedef struct node Node;

//create a linklist, return first pointer
Node *createlist(int *arr, int len){
    int i;
    Node *first, *current, *previous;
    for(i = 0; i < len; i++){
        current = (Node*)malloc(sizeof(Node));
        current ->  data = arr[i];
        //set it as first node
        if(i == 0)
            first  = current;
        //set next of previous node being current
        else
            previous -> next = current;
        //set pointer of last node to NULL
        current -> next = NULL;
        //for next node
        previous = current;
    }
    //return first node
    return first;
}

//output a linklist
void printlist(Node* first){
    Node* node = first;
    if(first == NULL)
        printf("list is empty!\n");
    else{
        //if node != NULL means it isn't last node
        while(node != NULL){
            //output data of node
            printf("%3d", node -> data);
            node = node -> next;
        }
        printf("\n");
    }
}

//free node in linklist
void freelist(Node* first){
    //set a temp node to save a current node
    Node *current, *temp;
    current = first;
    while(current != NULL){
        temp = current;
        //let current as next node
        current = current -> next;
        free(temp);
    }
}

//combine two linklist
void combineList(Node *first, Node *second){
    Node* current = first;
    while(current ->next != NULL){
        current = current->next;
    }
    current->next = second;
}

Node*  insertFirstNode(Node* first){
    int n, num, i;
    printf("How many nodes you want to insert?");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        printf("Input the number you want to insert:");
        scanf("%d", &num);
        //set a new node
        Node* newnode = (Node*)malloc(sizeof(Node));
        //set data of new node as num
        newnode -> data = num;
        //set next od new node as first address
        newnode -> next = first;
        //let first as new node
        first = newnode;
        //print new linklist
        printlist(first);
    }
    return first;
}

//calculate length of link list
int listLength(Node* first){
    //set first as last node
    Node* last = first;
    int num = 1;
    while(last -> next != NULL){
        //set last node as next node
        last = last->next;
        num++;
    }
    return num;
}

//reverse link list
Node* reverseList(Node* first){
    Node *previous, *current, *preceding ;
	previous=NULL;
	current=first;
	preceding=first->next;
    //reverse direction
	while (preceding!=NULL){
		current -> next = previous;
		previous = current;
		current = preceding;
		preceding = preceding -> next;
	}
    //current -> next is second, after reverse linklist
	current -> next=previous;
    //let first as last node(current)
	first = current;
    return first;
}

int main(void){
    int arr[] = {12, 43, 56, 34, 98}, arr2[] = {36, 77, 99};
    Node *first, *second;
    //first link list
    first = createlist(arr, 5);
    printlist(first);
    //second link list
    second = createlist(arr2, 3);
    printlist(second);
    combineList(first, second);
    printlist(first);
    first = insertFirstNode(first);
    printf("sum of nodes:%d\n", listLength(first));
    first = reverseList(first);
    printlist(first);
    freelist(first);
}
