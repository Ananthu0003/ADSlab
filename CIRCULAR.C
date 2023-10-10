#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX_SIZE 5
int front=-1,rear=-1,i;
int queue[MAX_SIZE];
int isEmpty()
{
  return(front==-1&&rear==-1);
}
int isfull()
{
  return((rear+1)%MAX_SIZE==front);
}

//ENQUEUE........

void enqueue(int data)
{
 if(isfull())
 {
   printf("Queue is full-over");
   return;
 }
 if(isEmpty())
 {
   front=rear=0;
 }
 else
 {
   rear=(rear+1)%MAX_SIZE;
 }
queue[rear]=data;
printf("%d added to the Queue",data);
}

//DEQUEUE.....

void dequeue()
{
  if(isEmpty())
  {
    printf("Queue is Empty-under");
    return;
  }
  printf("%d removed from the Queue",queue[front]);
  if(front==rear)
  {
    front=rear=-1;
  }
  else
  {
  front=(front+1)%MAX_SIZE;
  }
}

//SEARCH.....

int search(int key)
{
  if(isEmpty())
  {
    printf("Queue is empty");
    return -1;
  }
  i=front;
  do
  {
    if(queue[i]==key)
    {
      printf("%d found at position %d in the queue",key,i);
      return i;
    }
    i=(i+1)%MAX_SIZE;
  }
  while(i!=(rear+1)%MAX_SIZE);
  printf("%d not in the queue",key);
  return -1;
}

//DISPLAY.....

void display()
{
  if(isEmpty())
  {
    printf("Queue is Empty");
    return;
  }
  printf("circular Queue");
  i=front;
  do
  {
    printf("%d",queue[i]);
    i=(i+1)%MAX_SIZE;
  }
  while(i!=(rear+1)%MAX_SIZE);
  printf("\n");
}
  void main()
  {
    int choice,data,key;
    clrscr();
    while(1)
    {
      printf("\n\n Circular queue:\n");
      printf("\n 1.ADD(Enqueue):\n");
      printf("\n 2.DELETE(Dequeue):\n");
      printf("\n 3.SEARCH:\n");
      printf("\n 4.DISPLAY:\n");
      printf("\n 5.EXIT:\n");
      printf("Enter your choice:");
      scanf("%d",&choice);
      switch(choice)
      {
	case 1:printf("Enter the element to add:");
	       scanf("%d",&data);
	       enqueue(data);
	       break;
	case 2:dequeue(data);
	       break;
	case 3:printf("Enter the element to add:");
	       scanf("%d",&key);
	       search(key);
	       break;
	case 4:display();
	       break;
	case 5:exit(0);
	       break;
	default:printf("Invalid choice.Please try again\n");
      }
    }
  return 0;
}
