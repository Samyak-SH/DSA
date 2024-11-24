#include "stdio.h"
#include "stdlib.h"

struct student{
    char USN[10];
    char name[50];
    char Branch[50];
    int sem;
    char Ph[50];
};typedef struct student STUDENT;

struct node{
    struct node* next;
    STUDENT s;
};typedef struct node* NODE;

NODE insert(NODE head, STUDENT s){
    NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->s = s;
    if(head==NULL){
        return newNode;
    }
    NODE temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = newNode;
    return head;
}

NODE delete(NODE head){
    if(head==NULL){
        printf("Nothing to delete\n");
        return NULL;
    }
    if(head->next==NULL){
        return NULL;
    }
    NODE temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

void display(NODE head){
    if(head==NULL){
        printf("Nothing to display\n");
        return;
    }
    printf("\nDetails : \n");
    NODE temp = head;
    while(temp!=NULL){
        printf("Name : %s\n", temp->s.name);
        printf("USN : %s\n", temp->s.USN);
        printf("Branch : %s\n", temp->s.Branch);
        printf("Sem : %d\n", temp->s.sem);
        printf("ph : %d\n\n", temp->s.Ph);
        temp=temp->next;
    }
    printf("\n\n");
}

void input(STUDENT* s){
    printf("Enter USN : ");
    scanf("%s", s->USN);
    printf("Enter Name : ");
    scanf("%s", s->name);
    printf("Enter Branch : ");
    scanf("%s", s->Branch);
    printf("Enter Sem : ");
    scanf("%d", &s->sem);
    printf("Enter ph : ");
    scanf("%s", s->Ph);
}

int main()
{
    NODE head=NULL;
    int ch;
    STUDENT s;
    printf("1) Insert 2) Delete 3) Display 4) exit\n");
    while(1){
        printf("enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            input(&s);
            head = insert(head, s);
            break;
        case 2:
            head = delete(head);
            break;
        case 3:
            display(head);
            break;
        
        default:
            printf("Exiting..\n");
            exit(0);
            break;
        }
    }

}