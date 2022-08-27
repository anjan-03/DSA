#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int token;
    struct queue *next;
    struct queue *prev;
   
};

struct queue *front=NULL;
struct queue *rear=NULL;

void null_check(void *ptr);
void apply(int n,int size);
void renewal(int n,int size);
void enqueue();
void display();
void dequeue();
void vehi_class();
void vehi_type();
void age_check(int i);
void age_ren(int j);
void docs_for_up();
void docs_for_ren();

int main()
{
    int ch,size=5,n;
    printf("\nPress '1' to apply for driving license or '2' for renewing the existence license or '-1' to quit: ");
    scanf("%d",&ch);
    if(ch!=-1)
    {
        printf("Enter the total number of persons applied for RTO appointment: ");
        scanf("%d",&n);
        if(ch==1)
            apply(n,size);
        else if(ch==2)
            renewal(n,size);
        else
            printf("Enter only 1 or 2 or -1\n");
    }
    return(0);
}

void null_check(void *ptr)
{
    if(ptr==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
}

void enqueue()
{
    struct queue *new=NULL;
    new=(struct queue*)malloc(sizeof(struct queue));
    null_check(new);
    printf("\nEnter the token number: ");
    scanf("%d",&new->token);
    new->next=NULL;
    new->prev =NULL; 
    if(front==NULL && rear==NULL)
        front=rear=new;
    else
    {
        rear->next=new;
        new->prev=rear;
        rear=new;
    }
    printf("Token no. %d just went in\n",new->token);
}

void dequeue()
{
    if (front==NULL && rear==NULL)
        printf("Queue is empty\n");
    else
    {
        struct queue *temp=NULL;
        temp=front;
        front=front->next;
        printf("\nToken no. %d just came out",temp->token);
        free(temp);
    }
}

void age_check(int i)
{
    int age;
    printf("Enter the age of person %d as per Aadhaar card: ",i+1);
    scanf("%d",&age);
    if(age<18)
        printf("Minimum age for applying License is 18\nApplication rejected\n");
    else
        printf("Application processed\n");
}

void age_ren(int j)
{
    int age;
    printf("Enter the age of person %d as per Aadhaar card: ",j+1);
    scanf("%d",&age);
    if(age>=40)
        printf("Driving license renewed for 5 years\n");
    else
        printf("Driving license renewed for 20 years\n");
}

void vehi_class()
{
    char c,t;
    printf("\nEnter 's' for applying driving license for single class of vehicle or 'd' for double class vehicle: ");
    scanf("%c%c",&t,&c);
    while(c!='s' && c!='d')
    {
        printf("Invalid choice! Enter only 's' or 'd' : ");
        scanf("%c%c",&t,&c);
    }
    if(c=='s')
        printf("Please pay Rs 800 for going through further processes");
    else if(c=='d')
        printf("Please pay Rs 1100 for going through further processes\n");
             
}

void apply(int n,int size)
{
    docs_for_up();
    vehi_class();
    int i;
    if(n<=5)
    {
        for(i=0;i<n;i++)
        {
            enqueue();
            age_check(i);
        }
        display();
        for(i=0;i<n;i++)
            dequeue();
    }
    else
    {
        for(i=0;i<size;i++)
        {
            enqueue();
            age_check(i);
        }    
        display();
        for(i=size;i<n;i++)
        {
            dequeue();
            enqueue();
            age_check(i);
        }
        display();
        for(i=0;i<size;i++)
            dequeue();
    }
}

void renewal(int n,int size)
{
    docs_for_ren();
	vehi_type();
    int i;
    if(n<=5)
    {
        for(i=0;i<n;i++)
        {
            enqueue();
            age_ren(i);
            printf("Application processed\n");
        }
        display();
        for(i=0;i<n;i++)
           dequeue();
    }
    else
    {
        for(i=0;i<size;i++)
        {
            enqueue();
            age_ren(i);
            printf("Application processed\n");
        }
        display();
        for(i=size;i<n;i++)
        {
            dequeue();
            enqueue();
            age_ren(i);
            printf("Application processed\n");
        }
        display();
        for(i=0;i<size;i++)
            dequeue();
    }
}

void vehi_type()
{
    char c,t;
    printf("\nEnter 't' for renewing Transport vehicle license or 'n' for renewing Non-transport vehicle license: ");
    scanf("%c%c",&t,&c);
    while(c!='t' && c!='n')
    {
        printf("Invalid choice! Enter only 'n' or 't' : ");
        scanf("%c%c",&t,&c);
    }
    if(c=='t')
        printf("Please pay Rs 450 for going through further processes");
    else if(c=='n')
        printf("Please pay Rs 500 for going through further processes\n");
            
}

void docs_for_ren()
{
    printf("\nThe following documents are necessary for renewal of driving license:-\n");
    printf("1. Identity proof like Aadhar card, PAN card, Voter ID\n2. Address proof like Ration card, telephone bill\n");
    printf("3. Proof of Date of Birth\n4. Original Driving License\n5. 3 Passport-sized photographs\n");
    printf("6. Form 1(for those aged between 17-40) or Form 1A(for those aged above 40)\n");    
}

void docs_for_up()
{
    printf("\nThe following documents are necessary for applying driving license:-\n");
    printf("1. Application of Form-2 generated through online\n2. Valid Learner License\n");
	printf("3. Identity proof like Aadhar card, PAN card, Voter ID\n4. Form 5 and form 15 for only those who went training in a driving school\n");
    printf("5. Valid insurance certificate, registeration certificate and pollution under control certificate of the vehicle in which the applicant will appear for driving test\n");
}

void display()
{  
    struct queue *temp =front;
    if (front==NULL && rear==NULL)
        printf("\nThe queue is empty\n");
    else
    {
        printf("\nThe token number of people waiting are:\n");
        while(temp!=NULL)
        {
            printf("%d\n",temp->token);
            temp=temp->next;
        }
    }
    printf("\n");
}