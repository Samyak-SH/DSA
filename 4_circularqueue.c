#include "stdio.h"
#define size 4


void enqueue(int* arr, int* rear, int* c, int value){
    if(*c>=size){
        printf("Queue is full\n");
        return;
    }
    printf("inserting %d...\n",value);
    *rear = (1+*rear)%size;
    arr[*rear] = value;
    (*c)++;
}
void display(int arr[size], int front, int rear, int c){
    if(c==0){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue is : \n");
    for(int i=1;i<=c;i++){
        printf("%d ", arr[front]);
        front = (1+front)%size;
    }
    printf("\n");
}
int dequeue(int* arr, int* front, int* rear, int* c){
    int temp=*front;
    if(*c<=0){
        printf("queue is empty\n");
        return NULL;
    }
    printf("Removing..\n");
    *front = (1+*front)%size;
    (*c)--;
    return arr[temp];
}

int main()
{
    int arr[size], front=0,rear=-1,c=0, input;
    char C;
    printf("1) enqueue 2) dequeue 3) display 4) exit\n");
    while (1)
    {
        printf("Enter choice : ");
        scanf(" %c", &C);
        if(C=='1'){
            printf("Enter value to enqueue : ");
            scanf("%d", &input);
            enqueue(arr, &rear, &c, input);
        }
        else if(C=='2'){
            printf("removed %d\n", dequeue(arr, &front, &rear, &c));
        }
        else if(C=='3'){
            display(arr, front, rear, c);
        }
        else{
            break;
        }
    }    
}
