#include "stdio.h"
#include "stdlib.h"
#define SIZE 6

void push(int* arr, int* top, int value){
    if(*top>=SIZE-1){
        printf("Cannot push. Stack overflow\n");
        return;
    }
    arr[++(*top)]=value;
}

int pop(int* arr, int* top){
    if(*top<0){
        printf("Stack underflow\n");
        return NULL;
    }

    int temp = arr[(*top)--];
    printf("Popped : %d\n", temp);
    return arr[*top];

}

void display(int* arr, int top){
    if(top<0){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack is : \n");
    for(int i=0;i<=top;i++){
        printf("%d ", arr[i]);
    }  
    printf("\n");
}

int main()
{
    int arr[SIZE];
    int top = -1;

    int value, ch;
    printf("1) Push 2) Pop 3) Display 4) Exit\n");

    while(1){
        printf("Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter element to insert : ");
            scanf("%d", &value);
            push(arr, &top, value);
            break;
        case 2:
            pop(arr, &top);
            break;
        case 3:
            display(arr, top);
            break;
        
        default:
            printf("Exiting..");
            exit(0);
            break;
        }
    }

}