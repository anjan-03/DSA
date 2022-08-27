#include<stdio.h>
#include<stdlib.h>

struct node
{
    int d;
    struct node *prev;
    struct node *next;
};

void create(struct node *head);
void traverse(struct node *head);
void add(struct node *head,int p,int i);
struct node *rev(struct node *head);
void del(struct node **head);

int main()
{
    struct node *head=NULL;
    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    int p,i;
    create(head);
    printf("\nThe  doubly linked list is : ");
    traverse(head);
    printf("\nEnter the integer to add: ");
    scanf("%d",&i);
    printf("Enter the position of integer: ");
    scanf("%d",&p);
    add(head,p,i);
    head=rev(head);
    printf("\nThe reversed doubly linked list is : ");
    traverse(head);
    del(&head);
    return(0);
}

void create(struct node *head)                                          
{
    struct node *ptr=head;
    printf("Enter the 1st element: ");
    scanf("%d",&ptr->d);
    ptr->next=NULL;
    ptr->prev=NULL;
    char c,t;
    printf("Enter 'q' to quit or any other key to continue: ");
    scanf("%c%c",&t,&c);
    while(c!='q')
    {
        struct node *temp=NULL;
        temp=(struct node*)malloc(sizeof(struct node));
        if(temp==NULL)
        {
            printf("Memory not allocated\n");
            exit(0);
        }
        printf("Enter the next element: ");
        scanf("%d",&temp->d);
        ptr->next=temp;
        temp->prev=ptr;
        ptr=ptr->next;
        ptr->next=NULL;
        printf("Enter 'q' to quit or any other key to continue: ");
        scanf("%c%c",&t,&c);
    }
}

void traverse(struct node *head)                                          
{
    struct node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d <=> ",ptr->d);
        ptr=ptr->next;
    }
    printf("NULL");
}

void add(struct node *head,int p,int i)
{
	struct node *ptr=NULL;
	struct node *temp=head;
	int c=1;
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Memory not allocated\n");
		exit(0);
	}
	ptr->d=i;
	if(p==1)
	{
		ptr->next=head;
		ptr->prev=NULL;
		if(head!=NULL)
			head->prev=ptr;
		head=ptr;
		return;
	}
	while((c<p-1) && (temp->next!=NULL))
	{
		temp=temp->next;
		c+=1;
	}
	if(c<p-1)
	        printf("\nAdding %d at the last\n",i);
	ptr->next=temp->next;
	ptr->prev=temp;
	if(temp->next)
		temp->next->prev=ptr;
	temp->next=ptr;
	traverse(head);
}

struct node *rev(struct node *head)                                       
{
    struct node *ptr=head,*temp=head;
    while(ptr!=NULL)
    {
        temp=ptr->prev;
        ptr->prev=ptr->next;
        ptr->next=temp;
        ptr=ptr->prev;
    }
    return(temp->prev);
}

void del(struct node **head)
{
	struct node *ptr=NULL;
	while(*head)
	{
		ptr=(*head)->next;
		free(*head);
		*head=NULL;
		*head=ptr;
	}
	printf("\nSpace freed successfully\n");
}
