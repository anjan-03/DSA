#include<stdio.h>
#include<stdlib.h>

int i=5,s=1,size;                        

struct list
{
    int d;
    struct list *next;
};

struct list *top=NULL;                      

struct q
{
    struct list *head;
    struct list *front;
    struct list *rear;
};

struct q *enque(struct q *que);
struct q *deque(struct q *que);
struct q *dequeatk(struct q *que);
void push(int m);
struct q *enquestar(struct q *que,int n);
void display(struct q *que);
void del();

int main()
{
    struct q *que=NULL;
    que=(struct q*)malloc(sizeof(struct q));
    if(que==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    printf("Enter the size of parking lot: ");     
    scanf("%d",&size);
    que->head=(struct list*)malloc(sizeof(struct list));
    if(!que->head)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    que->front=(struct list*)malloc(sizeof(struct list));
    if(!que->front)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    que->rear=(struct list*)malloc(sizeof(struct list));
    if(!que->rear)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    int c;
    printf("Enter 1 to park the car: ");
    scanf("%d",&c);
    if(c==1)
    {
        que->head->d=i;
        que->front->d=i;
        que->head->next=que->front;
        que->rear=que->front;
        i+=5;
    }
    else
        return(0);
    while(c!=-1)
    {
        printf("\nEnter 1 to park the car");                              
        printf("\nEnter 2 to remove the car from front end");
        printf("\nEnter 3 to remove the car from kth position");
        printf("\nEnter 4 to display");
        printf("\nEnter -1 to exit");
        printf("\nEnter the choice: ");
        scanf("%d",&c);
        if(c==1)
            que=enque(que);
        else if(c==2)
            que=deque(que);
        else if(c==3)
            que=dequeatk(que);
        else if(c==4)
            display(que);
    }
    free(que);
    del();
    
    return(0);
}

struct q *enque(struct q *que)
{
    if((que->head->d)>size)
    {
        printf("Parking lot is full\n");
        exit(0);
    }
    struct list *ptr=NULL;                                     
    ptr=(struct list*)malloc(sizeof(struct list));
    if(ptr==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    ptr->d=i;
    ptr->next=NULL;
    s+=1;
    que->rear->next=ptr;
    que->rear=ptr;
    que->head->d=s;                 
    i+=5;
    return(que);
}

struct q *deque(struct q *que)
{
    if(que->head->d==0)
    {
        printf("Queue Underflow\n1");
        return(0);
    }
    struct list *ptr=que->front;
    que->head->next=que->front->next;
    s-=1;
    que->front=que->front->next;
    free(ptr);
    que->head->d=s;
    return(que);
}

int pop()
{
    struct list *ptr=top;
    int n=ptr->d;
    top=top->next;
    free(ptr);
    return(n);
}

struct q *dequeatk(struct q *que)                      
{
    if(que->head->d==0)
    {
        printf("Queue Underflow\n1");
        return(0);
    }
    int k,n;
    printf("Enter the position of car: ");
    scanf("%d",&k);                   
    que->head->d=s;
    for(i=1;i<k;i++)
    {
        push(que->front->d);
        que=deque(que);
    }
    que=deque(que);
    for(i=1;i<k;i++)
    {
        n=pop();
        enquestar(que,n);
    }
    return(que);
}

void push(int m)
{
    struct list *ptr=NULL;
    ptr=(struct list*)malloc(sizeof(struct list));
    if(ptr==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    ptr->d=m;
    ptr->next=NULL;
    if(top==NULL)
        top=ptr;
    else
    {
        ptr->next=top;
        top=ptr;
    }
}

struct q *enquestar(struct q *que,int n)            
{
    struct list *ptr=NULL;
    ptr=(struct list*)malloc(sizeof(struct list));
    if(ptr==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    ptr->d=n;
    ptr->next=que->front;
    s+=1;
    que->front=ptr;
    que->head->d=s;
    return(que);
}

void display(struct q *que)                               
{
    if(que->head->d==0)
    {
        printf("Queue is empty");
        exit(0);
    }
    if((que->head->d)>size)
    {
        printf("Parking lot is full\n");
        exit(0);
    }
    struct list *ptr=que->front;
    printf("Header is %d\n",que->head->d);                          
    printf("The queue is: ");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->d);
        ptr=ptr->next;
    }
    printf("\n");
}

void del()
{
    struct list *ptr=top;
    while(top!=NULL)
    {
        top=top->next;
        free(ptr);
        ptr=top;
    }
    printf("Space freed successfully\n");
}
