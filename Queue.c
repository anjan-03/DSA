#include<stdio.h>
#include<stdlib.h>

struct n
{
    int r;
    struct n *next;
    struct n *prev;
   
};
  struct n *front =NULL;
    struct n *rear= NULL;
     
void insertatfront()
{
    struct n *newnode;
    newnode =(struct n *)malloc(sizeof(struct n));
    printf("enter the data:\n");
    scanf("%d",&newnode->r);
     newnode->next =NULL;
    newnode->prev  =NULL; 
    if(front == NULL)
        front =rear =newnode;
    else
    {
        
        front->prev =newnode;
        newnode->next = front;
        front =newnode;
    }
    
}

void insertatrear()
{
    struct n *newnode;
    newnode =(struct n *)malloc(sizeof(struct n));
    printf("enter the data:\n");
    scanf("%d",&newnode->r);
    newnode->next =NULL;
    newnode->prev  =NULL; 
    if(front == NULL && rear == NULL)
        front =rear =newnode;
    else
    {
        rear ->next =newnode;
        newnode->prev =rear;
        rear =newnode;
    }
    
}
void deleteatfront()
{
    if (front == NULL && rear == NULL)
        printf("The Queue is empty\n");
    else
    {
        struct n *temp;
        temp=front;
        front =front->next;
        free(temp);
    }
 
}

void deleteatrear()
{
    if (front == NULL && rear == NULL)
        printf("The Queue is empty\n");
    else
    {
        struct n *temp;
        temp=rear;
        rear =rear->prev;
        free(temp);
        rear->next =NULL;
    }
}


void display()
{
    
    struct n *temp =front;
    if (front==NULL)
        printf("The List is empty\n");
    else
    {
        printf("The Data is:\n");
        while(temp !=NULL)
        {
            printf("%d\n",temp->r);
            temp =temp->next;
        }
    }
}


int main()
{
    int s;
    printf("type a number:1.implementation of deque  2.implement stack  3.implement queue\n");
    scanf("%d",&s);
    if (s==1)
    {int choice =1;
        while (choice)
        {
        int r;
        printf("enter 1.insert at front 2. insert at rear 3.display 4.delete at front 5.delete at rear\n");
        scanf("%d",&r);
        switch(r)
        {
            case 1:
    insertatfront();
    break;
    case 2: 
    insertatrear();
     break;
    case 3:
    display();
     break;
     case 5:
    printf("after deleting at rear\n");
    deleteatrear();
     break;
    case 4:
     printf("after deleting at front\n");
    deleteatfront();
     break;
    }
     printf("do you want continue 1.yes 0.no");
    scanf("%d",&choice);
   }
    }
    else if(s==2)
    {
        insertatfront();
        insertatfront();
        insertatfront();
        display();
        deleteatfront();
         printf("after deleting\n");
        display();
    }
    else if(s==3)
    {
        insertatrear();
        insertatrear();
        insertatrear();
        display();
        deleteatfront();
        printf("after deleting\n");
        display();
    }
    
    
    
    return 0;
}



