#include "stdio.h"
#include "string.h"

void push(char* arr, int* top, char value){
    arr[++(*top)] = value;
}
char pop(char* arr, int* top){
    return arr[(*top)--];
}

int IPV(char ch){
    if(ch=='+' || ch=='-') return 1;
    if(ch=='*' || ch=='/') return 3;
    if(ch=='(') return 9;
    if(ch==')') return 0;
    if(ch=='^') return 6;
    return 7;
}

int SPV(char ch){
    if(ch=='+' || ch=='-') return 2;
    if(ch=='*' || ch=='/') return 4;
    if(ch=='(') return 0;
    if(ch=='#') return -1;
    if(ch=='^') return 5;
    return 8;
}

int main()
{
    while(1){
        char infix[50], postfix[50], stack[50];
        int top = -1, index = 0;
        char ch;

        printf("Enter a valid Infix expression : ");
        scanf("%s", infix);

        push(stack, &top, '#');

        for(int i=0; i<strlen(infix); i++){
            ch = infix[i];

            while(IPV(ch)<SPV(stack[top])){
                postfix[index++] = pop(stack, &top);
            }

            if(IPV(ch)>SPV(stack[top])){
                push(stack, &top, ch);
            }

            if(IPV(ch)==SPV(stack[top])){
                pop(stack, &top);
            }
        }

        while(stack[top]!='#'){
            postfix[index++] = pop(stack, &top);
        }

        postfix[index]='\0';

        printf("Postfix expression is : \n");
        for(int i=0;i<=index; i++){
            printf("%c", postfix[i]);
        }
        printf("\n\n");
    }
}