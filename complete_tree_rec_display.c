#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int d;
    struct tree *left;
    struct tree *right;

};

struct tree *createnode(int d);
struct tree *createbtree(int a[],int i,int n);
void preorder(struct tree *root);
void inorder(struct tree *root);
void postorder(struct tree *root);

int main()
{
    struct tree *root=NULL;
    root=(struct tree*)malloc(sizeof(struct tree));
    if(root==NULL)                                  
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    int n,i;
    printf("Enter the total number of nodes: ");
    scanf("%d",&n);
    int a[n];                                    
    for(i=0;i<n;i++)
    {
        printf("Enter the value of node %d: ",i+1);
        scanf("%d",&a[i]);
    }
    root=createbtree(a,0,n);
    printf("\nPreorder Traversal: ");
    preorder(root);                                   
    printf("\n");
    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\n");
    printf("\nPostorder Traversal: ");
    postorder(root);
    printf("\n");
    return(0);
}

struct tree *createnode(int d)
{
    struct tree *ptr=NULL;
    ptr=(struct tree*)malloc(sizeof(struct tree));
    if(ptr==NULL)                                      
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    ptr->d=d;
    ptr->left=NULL;
    ptr->right=NULL;
    return(ptr);
}

struct tree *createbtree(int a[],int i,int n)
{
    struct tree *root=NULL;
    root=(struct tree*)malloc(sizeof(struct tree));
    if(i<n)
    {
        root=createnode(a[i]);
        root->left=createbtree(a,2*i+1,n);                                
        root->right=createbtree(a,2*i+2,n);                              
    }
    return(root);
}
void preorder(struct tree *root)                                    
{
    if(root)
        if(root->d!=0)
        {
            printf("%d",root->d);
            preorder(root->left);
            preorder(root->right);
        }
    else
        return;
}

void inorder(struct tree *root)                                        
{
    if(root)
        if(root->d!=0)
        {
            inorder(root->left);
            printf("%d",root->d);
            inorder(root->right);
        }
    else
        return;
}

void postorder(struct tree *root)                             
{
    if(root)
        if(root->d!=0)
        {
            postorder(root->left);
            postorder(root->right);
            printf("%d",root->d);
        }
    else
        return;
}
