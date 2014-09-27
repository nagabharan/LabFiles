#include<stdio.h>
#include<process.h>
void add(int,int[]);                                                                Nagabharan.N
void del(int[]);                                                                        1PE10CS054
void display(int[]);                                                                   3rd Sem CSE A
int q[10];
int front=-1,rear=-1;
void main()
{
    int ch,el;
    do{

   		printf("\t\tMENU:\n\t\t1.Add an element\n\t\t2.Delete an element\n\t\t3.Display Queue\n\t\tAnother to Exit\n");
   		scanf("%d",&ch);
   		switch(ch)
		{
			case 1:	printf("\nEnter the element to be added\n");
                        scanf("%d",&el);
                        add(el,q);
                        break;
			case 2: del(q);
                        break;
			case 3: display(q);
                        break;
			default:exit(0);
		}
 }while(ch);
}
void add(int a,int q[10])
{
    if(rear<10)
		q[++rear]=a;
    else
		printf("\nQueue Overflow");
}
void del(int q[10])
{

    if(front<rear)
	{
		printf("\nElement deleted is %d",q[++front]);
            q[front]=NULL;
	}
    else
		printf("\nQueue underflow");
}
void display(int q[10])
{

    int temp=front;
    printf("QUEUE: ");
    while(temp<rear)
		printf("%d ",q[++temp]);
}

OUTPUT:
                MENU:
                1.Add an element
                2.Delete an element
                3.Display Queue
                Another to Exit
                1

Enter the element to be added
                1
                MENU:
                1.Add an element
                2.Delete an element
                3.Display Queue
                Another to Exit
                1

Enter the element to be added
                2
                MENU:
                1.Add an element
                2.Delete an element
                3.Display Queue
                Another to Exit
                1

Enter the element to be added
                3

                MENU:
                1.Add an element
                2.Delete an element
                3.Display Queue
                Another to Exit
                3
QUEUE: 1 2 3
                MENU:
                1.Add an element
                2.Delete an element
                3.Display Queue
                Another to Exit
                2

Element deleted is 1
                MENU:
                1.Add an element
                2.Delete an element
                3.Display Queue
                Another to Exit
                2

Element deleted is 2
                MENU:
                1.Add an element
                2.Delete an element
                3.Display Queue
                Another to Exit
2

Element deleted is 3

