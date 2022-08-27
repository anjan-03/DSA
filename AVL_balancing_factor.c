#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;  
    struct node* left;
    struct node* right;
    int bf;
};

struct node* create_b_tree(struct node* root,int data);
struct node* create_node();
void in_order(struct node* root);
void find_bf(struct node* root);
int height(struct node* root);
void print_bf(struct node* root);

int main()
{
    int n,i;
    printf("Enter the no.of inputs\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elemnets\n");
    for(i=0;i<n;++i)
        scanf("%d",&a[i]);
    struct node* root=NULL;
    for(i=0;i<n;++i)
        root=create_b_tree(root,a[i]);
    printf("Inorder traversal is: ");
    in_order(root);
    printf("\n");
    find_bf(root);
    print_bf(root);
    return 0;
}

struct node* create_b_tree(struct node* root,int data)
{
    if(root==NULL)
    {
        root=create_node();
        root->data=data;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    if(root->data==data)
        return root;
    else if(root->data>data)
        root->left=create_b_tree(root->left,data);
    else
        root->right=create_b_tree(root->right,data);   
}

struct node* create_node()
{
    struct node* temp=NULL;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("memory not allocated\n");
        return NULL;
    }
   return temp; 
}

void in_order(struct node* root)
{
    if(root==NULL)
       return;
    in_order(root->left);
    printf(" %d",root->data);
    in_order(root->right);
}

void find_bf(struct node* root)
{
    int lh,rh;
    if(root==NULL)
        return ;
    find_bf(root->left);
    find_bf(root->right);
    lh=height(root->left);
    rh=height(root->right);
    root->bf=lh-rh;
}

int height(struct node* root)
{
    int lh,rh;
    if(root==NULL)
    return -1;    
    lh=height(root->left);
    rh=height(root->right);
    if(lh>=rh)
        return (lh+1);
    else
        return (rh+1);
}

void print_bf(struct node* root)
{
    if(root==NULL)
        return;
    print_bf(root->left);
    printf(" Data = %d - Balacing Factor = %d ",root->data,root->bf);
    print_bf(root->right);
}