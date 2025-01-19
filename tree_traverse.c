#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node*left;
    struct node*right;
};
struct node*createNode(int data){
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
 void preorder(struct node*root){
    if(root!=NULL){
    printf ("%d ",root->data);
    preorder(root->left);
    preorder(root->right);

}
}
void postorder(struct node*root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
void inorder(struct node*root){
    if(root!=NULL){
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
}
struct node*search(struct node*root, int key){
    while(root!=NULL){
        if(key==root->data)
        return root;
        else if(key<root->data)
        root=root->left;
        else
        root=root->right;
        
 
   }
return NULL;
}
void insert(struct node*root,int k){
    struct node*prev=NULL;
    while(root!=NULL){
    prev=root;
    if(k==root->data)
    return;
    else if(k<root->data)
    root=root->left;
    else
    root=root->right;
    
}
}
 struct node* new = createNode(key);
   if(key<prev->data){
       prev->left = new;
   }
   else{
       prev->right = new;
   }
   struct node *inOrderPredecessor(struct node* root){
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}


struct node *deleteNode(struct node *root, int value){

    struct node* iPre;
    if (root == NULL){
        return NULL;
    }
    if (root->left==NULL&&root->right==NULL){
        free(root);
    }

    //searching for the node to be deleted
    if (value < root->data){
        deleteNode(root->left,value);
    }
    else if (value > root->data){
        deleteNode(root->right,value);
    }
    //deletion strategy when the node is found
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        deleteNode(root->left, iPre->data);
    }
}




int main(){
     struct node *p=createNode(4);
     struct node *p1=createNode(1);
     struct node *p2=createNode(6);
     struct node *p3=createNode(5);
     struct node *p4=createNode(2);
     
     p->left=p1;
     p->right=p2;
     p1->left=p3;
     p1->right=p4;

     preorder(p);
     printf("\n");
     postorder(p);
     printf("\n");
     inorder(p);
     struct node*n =search(p,6);   
     printf("FOUND %d",n->data);
     return 0;
    struct node* n = search(p, 6);
    printf("Found: %d", n->data);
   insert(p,9);
   printf("%d ",p->right->right->data);
   return 0;
    
    }

     
     
  
     



    
     
