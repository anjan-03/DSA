#include<stdio.h>
#include<stdlib.h>
#define size 50

int queue[size];
int front=-1;
int rear=-1;

void enque(int a);                                                      
void deque();
void display();

int main()
{
    int c=0,a;
    while(c<4)
    {
        printf("\nEnter 1 to insert an integer into the queue\n");
        printf("Enter 2 to delete an integer into the queue\n");
        printf("Enter 3 to display the queue\n");
        printf("Press -1 to exit");
        printf("\nEnter your choice: ");
        scanf("%d",&c);                                       
        if(c==-1)
            break;                                   
        if(c==1)
        {
            printf("Enter the integer to add: ");
            scanf("%d",&a);                             
            enque(a);
        }
        else if(c==2)
            deque();
        else if(c==3)
            display(); 
        else
        {
            printf("Enter valid input\n");                                
            printf("\nEnter your choice: ");
            scanf("%d",&c);
        }
    }
    return(0);
}

void enque(int a)                                                   
{
    if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        queue[rear]=a;
    }
    else if((rear+1)%size==front)
        printf("Queue Overflow\n");
    else
    {
        rear=(rear+1)%size;
        queue[rear]=a;
    }
}

void deque()                                                      
{
    if(rear==-1 && front==-1)
        printf("Queue Underflow\n");
    else if(front==rear)
    {
        printf("The dequeued element is %d",queue[front]);
        front=-1;
        rear=-1;
    }
    else
    {
        printf("The dequeued element is %d",queue[front]);
        front=(front+1)%size;
    }
}

void display()
{
    if(rear==-1 && front==-1)
        printf("\nThe queue is empty\n");
    else
    {
        printf("\nThe elements in the queue are : ");
        while(front<=rear)
        {
           printf("%d ",queue[front]);                                       
           front=(front+1)%size;
        }
    }
    printf("\n");
}
