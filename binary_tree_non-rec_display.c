#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int d;
    struct tree *left;
    struct tree *right;
};

struct stack
{
    struct tree *val;
    struct stack *next;
};

struct tree *createnode(int d);
struct tree *createbtree(struct tree *root);
struct tree *pop(struct stack *top);
void preorder(struct tree *root,struct stack *top);
void inorder(struct tree *root,struct stack *top);
void postorder(struct tree *root,struct stack *top);
void del(struct stack **top);

int main()
{
    struct tree *root=NULL;
    root=(struct tree*)malloc(sizeof(struct tree)); 
    if(root==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    struct tree *top=NULL;
    top=(struct tree*)malloc(sizeof(struct tree));
    if(top==NULL)                                        
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    createbtree(root);
    printf("\nPreorder traversal: ");
    preorder(root,top);
    printf("\n");
    printf("\nInorder traversal: ");
    inorder(root,top);
    printf("\n");
    printf("\nPostorder traversal: ");
    //postorder(root,top);
    printf("\n");
    del(&top);                                    
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

struct tree *createbtree(struct tree *root)
{
    root=(struct tree*)malloc(sizeof(struct tree)); 
    if(root==NULL)                                                              
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    printf("Enter the value of root: ");
    scanf("%d",&root->d);
    char t,c;
    printf("Enter 'q' to quit or 'l' to insert into left or 'r' to insert in the right: ");    
    scanf("%c%c",&t,&c);                                   
    while(c!='q')
    {
        if(c=='l')
        {
            printf("Enter the value you want to insert in the left: ");         
            scanf("%d",&root->left->d);
            root->left=createnode(root->left->d);
            root=root->left;
        }
        else if(c=='r')
        {
            printf("Enter the value you want to insert in the right: ");         
            scanf("%d",&root->right->d);
            root->right=createnode(root->right->d);
            root=root->right;
        }
        printf("Enter 'q' to quit or 'l' to insert into left or 'r' to insert in the right: ");
        scanf("%c%c",&t,&c);
    }
}

void push(struct tree *root,struct stack *top)                   
{
    struct stack *ptr=NULL;
    ptr=(struct stack*)malloc(sizeof(struct stack));
    if(ptr==NULL)                                     
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    ptr->val=root;
    ptr->next=top;
    top=ptr;
}

struct tree *pop(struct stack *top)                      
{
    if(top)
    {
        struct stack *ptr=top;
        top=ptr->next;
        return(ptr->val);
    }
    return(NULL);
}

void preorder(struct tree *root,struct stack *top)         
{
    while(1)
    {
        while(root)
        {
            printf("%d",root->d);
            push(root,top);
            root=root->left;
        }
        if(top==NULL)
            return;
        root=pop(top);
        root=root->right;
    }
}

void inorder(struct tree *root,struct stack *top)                       
{
    while(1)
    {
        while(root)
        {
            push(root,top);
            root=root->left;
        }
        if(top==NULL)
            return;
        root=pop(top);
        printf("%d",root->d);
        root=root->right;
    }
}

void postorder(struct tree *root,struct stack *top)
{
    while(1)
    {
        if(root)
        {
            push(top,root);
            root=root->left;
        }
        else if(top->val->right==NULL)
        {
            root=pop(top);
            printf("%d",root->d);
            if(root==top->next)
            {
                printf("%d",root->d);
                if(root==top->val->right)
                {
                    printf("%d",root->d);
                    pop(top);
                }
            }
            if(top==NULL)
                root=top->val->right;
            else
                root=NULL;
        }
    }
}

void del(struct stack **top)
{
    struct stack *ptr=NULL;
    while(*top)
    {
        ptr=(*top)->next;
        free(*top);
        *top=NULL;
        *top=ptr;
    }
    printf("\nSpace freed successfully\n");
}
