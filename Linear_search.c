#include<stdio.h>
#include<math.h>
int main(){
    int size;
    printf("enter the total no of elements:");
    scanf("%d",&size);
    int key,a[size];
    for(int i=0;i<size;i++){
        printf("enter the element%d:",i+1);
        scanf("%d",&a[i]);
    }
    for(int x=0;x<size;x++){
        for(int y=0;y<size;y++){
            if(a[x]<a[y]){
            int temp;
            temp=a[x];
            a[x]=a[y];
            a[y]=temp;
        }
    }
    }
    printf("the elements in sorted:\n");
    for(int j=0;j<size;j++){
        printf("%d\t\t",a[j]);
    }
    
    int low=0;
    int high=size-1;
    int mid=floor((low+high)/2);
    printf("enter the element to search:");
    scanf("%d",&key);
    printf("key value is %d\n",key);
    if(key==mid){
        printf("the element is found in the middle position:",mid);
    }else if(key<a[mid]){
        for(int i=0;i<mid;i++){
            if(a[i]==key){
                printf("the element is found in the position %d",i+1);
            }
        }
    }else if(key>a[mid]){
        for(int i=mid;i<size;i++){
            if(a[i]==key){
                printf("the element is found in the position %d",i+1);
            }
        }
    }else{
        printf("not found\n");
    }
    return 0;           
}
