#include "stdio.h"
#include "stdlib.h"

struct employee{
    char ssn[50];
    char name[50];
    char dept[50];
    char designation[50];
    double sal;
    char ph;
};typedef struct employee EMP;

struct node{
    struct node* next;
    struct node* prev;
    EMP e;

}; typedef struct node* NODE;

void input(EMP* e){
    printf("Enter name : ");
    scanf("%s", e->name);
    printf("Enter salary : ");
    scanf("%lf", &e->sal);
    printf("Enter ssn : ");
    scanf("%s", e->ssn);
    printf("Enter dept : ");
    scanf("%s", e->dept);
    printf("Enter designation : ");
    scanf("%s", e->designation);
    printf("Enter ph : ");
    scanf("%s", e->ph);

}

NODE insert_at_end(NODE head, EMP e){
    NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->e = e;
    if(head==NULL){
        return newNode;
    }
    NODE temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;

}
NODE insert_at_beg(NODE head, EMP e){
    NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->e = e;
    if(head==NULL){
        return newNode;
    }
    newNode->next= head;
    head->prev = newNode;
    return newNode;
}

NODE delete_at_end(NODE head){
    if(head == NULL){
        printf("Nothing to delete\n");
        return NULL;
    }
    
    if(head->next==NULL){
        return NULL;
    }

    NODE temp = head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    return head;
}

NODE delete_at_beg(NODE head){
    if(head==NULL){
        printf("nothing to delete\n");
        return NULL;
    }
    if(head->next==NULL){
        return NULL;
    }
    NODE temp = head;
    temp = temp->next;
    temp->prev = NULL;
    free(head);
    return temp;
}

void display(NODE head){
    if(head==NULL){
        printf("Nothing to display\n");
        return;
    }

    NODE temp = head;
    while(temp!=NULL){
        printf("\n\nName : %s\n", temp->e.name);
        printf("Salary : %lf\n", temp->e.sal);
        printf("SSN : %lf\n", temp->e.ssn);
        printf("Dept : %lf\n", temp->e.dept);
        printf("Designation : %lf\n", temp->e.designation);
        printf("Phone number : %lf\n", temp->e.ph);
        temp=temp->next;
    }
    printf("\n\n\n");
}

int main()
{
    NODE head = NULL;
    EMP e;
    int ch;
    printf("1) insert at end 2) inset at beg 3) delete from end 4) delete from beg 5) display 6) exit\n");
    while(1){
        printf("Enter choice : ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                input(&e);
                head = insert_at_end(head, e);
                break;
            case 2:
                input(&e);
                head = insert_at_beg(head, e);                
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