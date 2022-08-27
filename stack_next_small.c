#include<stdio.h>
#include<stdlib.h>

struct stk
{
    int d;
    struct stk *next;
};

void traverse(struct stk*top);                              
void del(struct stk **top);
int pop(struct stk **top);
struct stk *push(struct stk *top,int no);
struct stk *small(struct stk *top,int a[],int n);

int main()
{
    int n,i;
    printf("Enter the total number of integers in array: ");       
    scanf("%d",&n);
    int a[n];                    
    for(i=0;i<n;i++)
    {
        printf("Enter the integer %d: ",i+1);
        scanf("%d",&a[i]);
    }
    struct stk *top=NULL;      
    top=(struct stk*)malloc(sizeof(struct stk));
    if(top==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    top->d=a[0];
    top->next=NULL;
    top=small(top,a,n);               
    del(&top);
    return(0);
}

void traverse(struct stk *top)                 
{
    struct stk *ptr=top;
    while(ptr!=NULL)
    {
        printf("%d-",ptr->d);
        ptr=ptr->next;
    }
    printf("NULL");
}

struct stk *push(struct stk *top,int no)        
{
    if(top==NULL)
    {
        struct stk *ptr=(struct stk*)malloc(sizeof(struct stk));
        ptr->d=no;
        return(ptr);
    }    
    struct stk *ptr=NULL;
    ptr=(struct stk*)malloc(sizeof(struct stk));
    if(ptr==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    ptr->d=no;
    ptr->next=top;
    top=ptr;
    return(top);
}

int pop(struct stk **top)               
{
    if(*top==NULL)
    {
        printf("Underflow array\n");
        exit(0);
    }
    struct stk *ptr=*top;
    if((*top)->next==NULL)
        (*top)->next=(struct stk*)malloc(sizeof(struct stk));
    *top=(*top)->next;
    free(ptr);
    ptr=NULL;
    return((*top)->d);
}

struct stk *small(struct stk *top,int a[],int n)         
{
    for(int i=1;i<n;i++)
    {
        if(a[i]>=((top)->d))
            top=push(top,a[i]);
        else
        {
            while(top==NULL || (top->d)>a[i])
            {
                printf("Next smallest integer of %d is %d\n",top->d,a[i]);
                pop(&top);
                break;
            }
            top=push(top,a[i]);
        }
    }
    struct stk *ptr=top;
    while(ptr!=NULL)
    {
        printf("Next smallest integer of %d is -1\n",ptr->d);
        ptr=ptr->next;
        if(ptr->d==0)
            break;
    }
    return(top);
}

void del(struct stk **top)         
{
    struct stk *ptr=NULL;
    while(*top)
    {
        ptr=(*top)->next;
        free(*top);
        *top=NULL;
        *top=ptr;
    }
    printf("Space freed successfully\n");
}
