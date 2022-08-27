#include<stdio.h>
#include<stdlib.h>

struct stud
{
	int rno;
	struct stud *next;
};

void create(struct stud *head);
void circ(struct stud *head);
void display(struct stud *head);

int main()
{
	struct stud *head=NULL;
	head=(struct stud*)malloc(sizeof(struct stud));
	if(head==NULL)
	{
		printf("Memory not allocated\n");
		return(0); 
	}
	create(head);
	display(head);
	return(0);
}

void create(struct stud *head)
{
	struct stud *ptr=head;
	char c,temp;
	head->next=NULL;
	printf("Enter the 1st student's rollno : ");
	scanf("%d",&head->rno);
	printf("Press 'q' to exit or any other key to continue: ");
	scanf("%c%c",&temp,&c);
	while(c!='q')
	{
		struct stud *ptr=NULL;
		ptr=(struct stud*)malloc(sizeof(struct stud));
		if(ptr==NULL)
		{
			printf("Out of memory space\n");
			exit(0);
		}
		head->next=ptr;
		head=ptr;
		printf("Enter the next student's rollno : ");
		scanf("%d",&head->rno);
		head->next=NULL;
		printf("Press 'q' to exit or any other key to continue: ");
		scanf("%c%c",&temp,&c);
	}
}

void display(struct stud *head)
{
	if(head==NULL)
		printf("Linked list is empty\n");
	struct stud *ptr=head;
	printf("The linked list is: ");
	while(ptr!=NULL)
	{
		printf("%d",ptr->rno);
		ptr=ptr->next;
		if(ptr!=NULL)
			printf("-");
	}
	printf("\n");	
}

void circ(struct stud *head)                                              
{
    struct stud *ptr=head;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=head;
}

