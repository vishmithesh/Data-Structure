#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left, *right;
};
struct node* createnode(int data){
    struct node* new=(struct node *)malloc(sizeof(struct node)) ;
    new->data=data;
    new->left = new->right =NULL;
    return new;
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
    struct node* root=createnode(80);
    root->left=createnode(70);
    root->right=createnode(32);
    root->left->left=createnode(48);
    root->left->right=createnode(64);
    root->right->left=createnode(12);
    printf("in order traversal:\n");
    inorder(root);
    printf("\n");
    printf("preorder traversal:\n");
    preorder(root);
    printf("\n");
    printf("post order traversal:\n");
    postorder(root);
    printf("\n");
}
