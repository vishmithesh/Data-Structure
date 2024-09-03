#include<stdio.h>
#define max 5
int currentsize = 0;
int isfull() {
    return currentsize >= max;
}
int isempty() {
    return currentsize == 0;
}
void insertatend(int *a, int element) {
    if (isfull()) {
        printf("cannot insert\n");
    } else {
        a[currentsize] = element;
        currentsize += 1;
    }
}
void insertatfront(int *a, int element) {
    if (isfull()) {
        printf("cannot insert\n");
    } else {
        for (int i = currentsize; i > 0; i--) {
            a[i] = a[i - 1];
        }
        a[currentsize] = element;
        currentsize += 1;
    }
}
void insertatcentre(int *a, int element, int pos) {
    if (isfull()) {
        printf("cannot insert\n");
    } else if (pos >= 0 && pos <= currentsize) {
        for (int i = currentsize; i > pos; i--) {
            a[i] = a[i - 1];
        }
        a[pos] = element;
        currentsize += 1;
    } else {
        printf("invalid position\n");
    }
}
void delete(int *a) {
    if (isempty()) {
        printf("cannot delete\n");
    } else {
        for (int i = currentsize; i < max; i++) {
            a[i] = a[i + 1];
        }
        currentsize -= 1;
    }
}
void display(int *a) {
    for (int i = 0; i <max; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void search(int *a) {
    int element;
    printf("enter the element to search:");
    scanf("%d",&element);
    for(int i=0; i<max; i++) {
        if(a[i]==element) {
            printf("the element is found in %d position",i);
            break;
        }

    }
}
void sort(int *a) {
    int temp;
    for (int i=0; i<max; i++) {
        for (int j=0; j<max; j++) {
            if(a[i]>a[j]) {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
int main() {
    int choice, element, pos;
    int a[max];
    for(int i=0;i<max;i++) {
      printf("enter the element %d:",i+1);
      scanf("%d",&a[i]);
    }
    printf("1. Insert at front\n2. Insert at centre\n3. Insert at end\n4. Delete an element\n5.search an element\n6. Display\n7.sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        printf("Enter the element to insert: ");
        scanf("%d", &element);
        insertatfront(a, element);
        display(a);
        break;
    case 2:
        printf("Enter the element to insert and position: ");
        scanf("%d%d", &element, &pos);
        insertatcentre(a, element, pos);
        display(a);
        break;
    case 3:
        printf("Enter the element to insert: ");
        scanf("%d", &element);
        insertatend(a, element);
        display(a);
        break;
    case 4:
        delete(a);
        display(a);
        break;
    case 5:
        search(a);
        break;
    case 6:
        display(a);
        break;
    case 7:
        sort(a);
        display(a);
        break;
    default:
        printf("Invalid choice\n");
    }
    return 0;
}