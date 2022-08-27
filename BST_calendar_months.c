#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_oneway_link(struct node* head,int count);
struct node* create_node();
struct node* create_two_way(struct node* head);
void print_list(struct node* ptr);
struct node*  create_bst( struct node* head, struct node* tail);
struct node* find_mid(struct node* head,struct node* tail);
void in_order(struct node* root);

int main()
{
    int count=1,i;
   struct node* head=NULL; 
   head=create_oneway_link(head,count); 
    count=count+1;
    
    struct node* temp=head;
    
    for(i=1;i<12;++i)
    {
        temp=create_oneway_link(temp,count);
        count++;
    }
    struct node* tail=NULL;
    tail=create_two_way(head);
    printf("\n");
    struct node* root=NULL;
    root=create_bst(head,tail); 
    in_order(root);
    return 0;
}

struct node* create_oneway_link(struct node* head,int count)
{
    if(head==NULL)
    {
        head=create_node();
        head->data=count;
        head->left=NULL;
        head->right=NULL;       
        return head;
    }
    struct node* ptr=head;
    struct node* current=NULL;
    current=create_node();
    current->data=count;
    current->right=NULL;
    current->left=NULL;
    ptr->right=current;
    ptr=current;
    return ptr;
}
 struct node* create_node()
 {
     
     struct node* temp=NULL;
     temp=(struct node*)malloc(sizeof(struct node));
     if(temp==NULL)
     {
         printf("Memory not allocated\n");
         return NULL;
     }
     return temp;
 }
 
 struct node* create_two_way(struct node* head)
 {
    struct node* p1=NULL;
    struct node* p2=NULL;
     p1=head;
     p2=head;
     while(p1->right)
     {
         p1=p1->right;
         p1->left=p2;
         p2=p1;
     }
     return p2;
 }
 
 void print_list(struct node* ptr)
 {
     while(ptr)
     {
         printf(" %d",ptr->data);
         ptr=ptr->left;
     }
 }
 
struct node*  create_bst( struct node* head, struct node* tail)
{
    if(head==NULL)
    return NULL;
    if(head->right==NULL)
    return head;
    struct node* mid=find_mid(head,tail);
    if(mid->left)
        mid->left->right=NULL;
    if(mid->right)
        mid->right->left=NULL;
    mid->left=create_bst(head,mid->left);
    mid->right=create_bst(mid->right,tail); 
    return mid;
}

struct node* find_mid(struct node* head,struct node* tail)
{
    if(head==NULL)
        return NULL;
    struct node* p1=head;
    struct node* p2=tail;
    while(p1!=p2)
    {
        p1=p1->right;
        if(p1==p2)
            break;
        p2=p2->left; 
    }
    return p1; 
}

void in_order(struct node* root)
{
    if(root==NULL)
        return;
    in_order(root->left);
    switch(root->data)
    {
        case 1:
            printf("JAN ");
            break;  
        case 2:
            printf("FEB ");
            break;
        case 3:
            printf("MAR ");
            break;
        case 4:
            printf("APRIL ");
            break;
        case 5:
            printf("MAY ");
            break;
        case 6:
            printf("JUNE ");
            break;
        case 7:
            printf("JULY ");
            break;    
        case 8:
            printf("AUG ");
            break;    
        case 9:
            printf("SEP ");
            break;    
        case 10:
            printf("OCT ");
            break;    
        case 11:
            printf("NOV ");
            break;    
        case 12:
            printf("DEC ");
            break;    
    }   
    in_order(root->right);
}