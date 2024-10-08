#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front=NULL,*rear=NULL;

void enqueue(){
    int d;
    printf("enter the element to insert:");
    scanf("%d",&d);
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=d;
    
    if(new==NULL){
        printf("memory is not allocated properly");
    }
    if(rear==NULL){
        front=rear=new;
    }
    else{
        rear->next=new;
        rear=new;
        new->next=NULL;
    }
}
void dequeue(){
    if(front==NULL && rear==NULL){
        printf("queue is empty can't be deleted");
    }
    else{
        struct node *temp=front;
        front=front->next;
        if(front==NULL){
            rear==NULL;
        }
        free(temp);
    }
}    

void display(){
    if(front==NULL && rear==NULL){
        printf("cannot display queue Empty");
    }
    else{
        struct node *temp=front;
        while(temp != NULL){
            printf("%d\t\t",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main(){
    int choice;
    do{
        printf("1.Enqueue\t\t2.Dequeue\t\t3.display\n");
        printf("enter the choice:");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        default:
            printf("invalid choice\n");
        } 
    }while(choice != 0);
  return 0;
}
