#include<stdio.h>
int main(){
    int size,i,j,temp;
    printf("enter the total no of elements:");
    scanf("%d",&size);
    int key,a[size];
    for(i=0;i<size;i++){
        printf("enter the element%d:",i+1);
        scanf("%d",&a[i]);
    }
    printf("The elements in the array:\n");
    for(int k=0;k<size;k++){
        printf("%d\t",a[k]);
    }
    printf("\n");
    for(i=0;i<size;i++){
        for(j=0;j<size-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
     for(j=0;j<size;j++){
        printf("%d\t",a[j]);
    }
    printf("\n");
return 0;
}
