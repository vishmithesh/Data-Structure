#include<stdio.h>
#include<conio.h>
#define max 10
int rear=-1,front=-1;
int a[max];
void enqueue(){
    int d;
    printf("enter the element to insert:");
    scanf("%d",&d);
    if(rear==max-1){
        printf("the queue is overflow");
    }
    if(front==-1 && rear==-1){
        front=rear=0;
        a[rear]=d;
    }
    else{
        rear=rear+1;
        a[rear]=d;
    }
    
}
void dequeue(){
    if(front==-1){
        printf("the queue is empty"); 
    }
    else if(front==-1 && rear==-1){
      front=0;
      rear=-1;  
    }
    else{
        front=front+1;
        front++;    
    }
    
}
void display(){
    if(front==-1 && rear==-1){
        printf("the queue is under flow");
    }
    else{
        for(int i=front;i<=rear;++i){
            printf("%d\t",a[i]);
        }
        printf("\n");
    }
}
int main(){
  int choice;
  do{
    printf("1.Enqueue\t2.Dequeue\t3.Display\n");
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
