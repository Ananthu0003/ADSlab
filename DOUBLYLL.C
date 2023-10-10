#include<stdio.h>
#include<stdlib.h>
void insbeg();
void insmid();
void insend();
void delbeg();
void delmid();
void delsend();
void display();
void creation();
void searching();
struct node
{
  int data;
  struct node *head,*newnode,*temp,*temp1;
};
typedef struct node node;
void main()
{
  int choice=0;
  clrscr();
  do
  {
  printf("Enter Your choice 1.Creation\n2.Insertion at BIG\n3.Insertion at MiD\n4.Insertion at END\n5.Deletion from BIG\n6.Deletion from MID\n7.Deletion from END\n8.Search\n9.End\n Press a number:");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:creation();
	   display();
	   break;
    case 2:insbeg();
	   display();
	   break;
    case 3:insmid();
	   display();
	   break;
    case 4:insend();
	   display();
	   break;
    case 5:delbeg();
	   display();
	   break;
    case 6:delmid();
	   display();
	   break;
    case 7:delend();
	   display();
	   break;
    case 8:searching();
	   display();
	   break;
    case 9:exit(0);
	   break;
  }
 }
 while(choice!=9);
 getch();
}

void creation()
{
  int ch=1,head=0;
  while(ch)
  {
    newnode=(node*)malloc(sizeof(node));
    printf("Enter the element to be inserted:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->pre=NULL;
    if(head==0)
    {
      head=temp=newnode;
    }
    else
    {
      temp->next=newnode;
      newnode->pre=temp;
      temp=newnode;
    }
    printf("Do you want to continue?");
    scanf("%d",&ch);
  }
}
void display()
{
  int count=0;
  temp=head;
  printf("The linked list:");
  printf("START->");
  while(temp!=NULL)
  {
    count=count+1;
    printf("%d",temp->data);
    temp=temp->next;
  }
  printf("END");
  printf("The no.of nodes is %d",count);
}

void insbeg()
{
  newnode=(node *)malloc(sizeof(node));
  printf("Enter the element to be inserted:");
  scanf("%d",&newnode->data);
  newnode->next=NULL;
  newnode->prev=NULL;
  head=newnode;
}

void insmid()
{
  int pos,count=0,i=1;
  temp=head;
  while(temp!=NULL)
  {
    count=count+1;
    temp=temp->next;
  }
  printf("Enter the position after which the element to be inserted:");
  scanf("%d",&pos);
  if(pos>count)
  {
    printf("Invalid Position");
  }
  else
  {
    temp=temp1=head;
    while(i<pos)
    {
      temp1=temp;
      temp=temp->next;
      i++;
    }
    printf("Enter the element:");
    newnode=(node*)malloc(sizeof(node));
    scanf("%d",newnode);
    newnode->next=temp;
    temp->prev=temp1;
    temp1->next=newnode;
  }
}

void insend()
{
  newnode=(node *)malloc(sizeof(node));
  printf("Enter the element:");
  scanf("%d",&newnode->data);
  newnode->next=NULL;
  temp=head;
  while(temp->next!=NULL)
  {
    temp=temp->next;
  }
  temp->next=newnode;
  newnode->prev=temp;
}

void delbeg()
{
  int del;
  if(head==NULL)
  {
    printf("Node absent");
    printf("Enter the data to delete:");
    scanf("%d",&del);
  }
  temp=head;
  while(temp->data!=del)
  {
    if(temp->next==NULL)
    {
      printf("Given node not found");
      break;
    }
    else
    {
      temp=temp->next;
    }
  }
  while(temp->data==del)
  {
    if(temp==head)
    {
      head=NULL;
      free(temp);
    }
    else
    {
      temp->prev->next=temp->next;
      free(temp);
    }
  }
}

void delend()
{
 if(head==NULL)
 {
   printf("Nde adsent");
 }
 temp=head;
 while(temp->next!=NULL)
 {
   temp1=temp;
   temp=temp->next;
 }
 temp->next=NULL;
}

void searching()
{
  int item,i,flag=0;
  printf("Enter the element to be searched:")
  scanf("%d",&item);
  temp=head;
  while(temp!=NULL)
  {
    if(temp->data==item)
    {
      printf("Item found at %d position",i);
      flag=flag+1;
    }
    i=i+1;
    temp=temp->next;
  }
  if(flag==0)
  {
    printf("Sorry Ite ot found!!");
  }
}








