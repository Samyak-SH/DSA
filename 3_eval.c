#include "stdio.h"
#include "math.h"
#include "ctype.h"
#include "string.h"

void push(int* arr, int* top, int value){
    arr[++(*top)] = value;
}
int pop(int* arr, int* top){
    return arr[(*top)--];
}

int main()
{
    while(1){
        char postfix[50];
        int res, top=-1, a, b, stack[50];
        printf("Enter postfix expression : ");
        scanf("%s", postfix);
        
        for(int i=0; i<strlen(postfix); i++){
            char ch = postfix[i];
            if(isdigit(ch)){
                push(stack, &top, ch-'0');
            }
            else{
                b = pop(stack, &top);
                a = pop(stack, &top);
                switch (ch)
                {
                    case '+':
                        res = a+b;
                        break;
                    case '-':
                        res = a-b;
                        break;
                    case '*':
                        res = a*b;
                        break;
                    case '/':
                        res = a/b;
                        break;
                    case '%':
                        res = a%b;
                        break;
                    case '^':
                        res = a^b;
                        break;                
                }
                push(stack, &top, res);
            }
        }
        printf("Evaluated value : %d\n\n", res); 

    }
    
}