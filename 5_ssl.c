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

NODE insert_at_end(NODE head, STUDENT s){
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

NODE delete_at_end(NODE head){
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

NODE insert_at_beg(NODE head, STUDENT s){
    NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->s = s;
    if(head==NULL){
        return newNode;
    }
    newNode->next = head;
    return newNode;
    
}

NODE delete_at_beg(NODE head){
    if(head==NULL){
        printf("nothing to delete : \n");
        return NULL;
    }
    if(head->next == NULL){
        return NULL;
    }
    NODE temp = head;
    temp=temp->next;
    free(head);
    return temp;
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
    printf("1) Insert at end 2) Insert at beg 3) Delete at end 4) Delete at beg 5) Display 6) exit\n");
    while(1){
        printf("enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            input(&s);
            head = insert_at_end(head, s);
            break;
        case 2:
            input(&s);
            head = insert_at_beg(head, s);
            break;
        case 3:
            head = delete_at_end(head);
            break;
        case 4:
            head = delete_at_beg(head);
            break;
        case 5:
            display(head);
            break;
        
        default:
            printf("Exiting..\n");
            exit(0);
            break;
        }
    }

}