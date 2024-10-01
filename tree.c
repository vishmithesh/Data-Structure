#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left, *right;
};
struct node* createnode(int data){
    struct node* new=(struct node *)malloc(sizeof(struct node));
    new->data=data;
    new->left = new->right =NULL;
    return new;
}
struct node* insert(struct node* root,int data){
    if(root == NULL){
        root=createnode(data);
    }else if(data>root->data){
        root->left=insert(root->left,data);
    }else{
        root->right=insert(root->right,data);
    }
    return root;
}
void preorder(struct node* root) {
    if(root == NULL) {
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node* root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(struct node* root) {
    if(root == NULL) {
        return;
    }
    preorder(root->left);
    preorder(root->right);
    printf("%d ",root->data);
}
void main(){
    struct node* root=NULL;
    int total,data;
    printf("enter the total number of node:");
    scanf("%d",&total);
    for(int i=1; i <= total;i++){
        printf("enter the element:%d",i);
        scanf("%d",&data);
        root=insert(root,data);
    }
    inorder(root);
    printf("\n");
    printf("preorder traversal:\n");
    preorder(root);
    printf("\n");
    printf("post order traversal:\n");
    postorder(root);
    printf("\n");
}