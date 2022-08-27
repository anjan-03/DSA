#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
    struct tree* left;
    struct tree* right;
};
struct queue
{
    struct tree* root;
    struct queue* link;
}*front=NULL,*rear=NULL;

struct tree* CreateNode(int value)
{
    struct tree *temp=NULL;
    temp=(struct tree*)malloc(sizeof(struct tree));
    if(temp==NULL)
    {
        printf("Memory allocation failed");
        exit;
    }
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    return(temp);
}
struct tree* CreateBinaryTree(int a[],int i,int n)
{
    struct tree *root=NULL;
    if(i<n)
    {
        root=CreateNode(a[i]);
        root->left=CreateBinaryTree(a,2*i+1,n);
        root->right=CreateBinaryTree(a,2*i+2,n);
    }
    return(root);
}
void PreOrder(struct tree* root)
{
    if(root)
    {
        printf("%d ",root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
void Enqueue(struct tree* root)
{
    struct queue* ptr=NULL;
    ptr=(struct queue*)malloc(sizeof(struct queue));
    if(ptr==NULL)
    {
        printf("Memory allocation failed");
        return;
    }
    ptr->root=root;
    ptr->link=NULL;
    if(front==NULL)
    {
        rear=ptr;
        front=ptr;
    }
    else
    {
        rear->link=ptr;
        rear=ptr;
    }
}
struct tree* Dequeue()
{
    if(front==NULL)
    {
        printf("Underflow");
    }
    struct queue* temp=front;
    struct tree* ptr=temp->root;
    front=front->link;
    free(temp);
    return(ptr);
}

void LevelOrder(struct tree* root)
{
    struct tree* temp=root;
    Enqueue(temp);
    while(front)
    {
        temp=Dequeue();
        if(temp)
        {
            printf("%d ",temp->data);
        }
        if(temp->left)
        Enqueue(temp->left);
        if(temp->right)
        Enqueue(temp->right);
    }
    
}

int main()
{
    int n,i;
    printf("Enter the number of elements of the array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the array of %d elements:",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    struct tree *root=NULL;
    root=CreateBinaryTree(a,0,n);
    printf("\n...Preorder traversal of the complete binary tree...\n");
    PreOrder(root);
    printf("\n...Level order traversal of the complete binary tree...\n");
    LevelOrder(root); 
    return(0);
}