#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};
typedef struct node* NODE;
NODE create_BST(NODE root,int key){
    NODE temp,curr,prev;
    temp=(NODE)malloc(sizeof(struct node));
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;
    if (root==NULL)
        return temp;
    curr=root;
    prev=NULL;
    while(curr!=NULL){
        prev=curr;
        if (key<curr->data)
            curr=curr->left;
        else
            curr=curr->right;

    }
    if(key<prev->data)
        prev->left=temp;
    else
        prev->right=temp;
    return root;

}
void preorder(NODE root){
    if(root!=NULL){
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(NODE root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
void postorder(NODE root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);

    }
}
int main(){
    NODE root=NULL;
    int item,ch;
    for(;;){
        printf("1.insert\n 2.preorder\n 3.inorder\n 4.postorder\n 5.exit");
        printf("enter your choice");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("enter item to be inserted:");
                    scanf("%d",&item);
                    root=create_BST(root,item);
                    break;
            case 2 :printf("preorder traversal is \n");
                    preorder(root);
                    break;
            case 3 :printf("inorder traversal is \n");
                    inorder(root);
                    break;
            case 4 :printf("postorder traversal is \n");
                    postorder(root);
                    break;
           default:exit(0);
    }
        }
        return 0;

}






















