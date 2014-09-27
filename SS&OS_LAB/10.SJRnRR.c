#include<stdio.h>

typedef struct
{
	int name;
	int at;
	int burst;
	int wait;
	int tat;
	int remaining;
	int flag;
}process;

process p[5], p1[5];
int n, n1;
void round_robin();
void accept();
void sjf();
int minimum();
int tq, t, i, c=0, rtwt=0, rttat=0, temp, sq=0, stwt=0, sttat=0;
float rawt=0.0, ratat=0.0, sawt=0.0, satat=0.0;

void main()
{
	int ch;
	printf("\nChoose one of the folowing options:");
	printf("\n\t1-SJF\n\t2-Round Robin\n\tExit");
	printf("\nEnter your choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
				accept();
				sjf();
				break;
		case 2:
				round_robin();
				break;
		case 3:
				break;
		default:
				printf("\nInvalid Entry");
	}
}

void accept()
{
	int i;
	printf("\nEnter the total number of procedures: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the procedure name: ");
		scanf("%d",&p[i].name);
		printf("Enter the arrival time: ");
		scanf("%d",&p[i].at);
		printf("Enter the burst time: ");
		scanf("%d",&p[i].burst);
		p[i].wait=0;
	}
}

void sjf()
{
	int i, j, tbt=0, no, k;
	for(i=0;i<n;i++)
	{
		p[i].remaining=p[i].burst;
		tbt=tbt+p[i].burst;
	}
	printf("\n");
	for(i=0;i<tbt;i++)
	{
		for(j=0;j<n;j++)
		{
			p[j].flag=0;
			if(p[j].at<=i && p[j].remaining>0)
			{
				p[j].flag=1;
			}
		}
		no=minimum();
		printf("%d-P%d-",i,no);
		p[no].remaining=p[no].remaining-1;

		for(k=0;k<n;k++)
		{
			if(p[k].at<=i && p[k].remaining>0 && p[k].name!=no)
			{
				p[k].wait=p[k].wait+1;
			}
		}
	}
	printf("%d",i);

	for(k=0;k<n;k++)
		p[k].tat=p[k].burst+p[k].wait;

	printf("\n\nProcess Name\tArrival\tBurst\tWait\tTurn Around Time");
	for(k=0;k<n;k++)
	{
		stwt=stwt+p[k].wait;
		sttat=sttat+p[k].tat;
		printf("\n    P%d\t\t   %d\t%d\t%d\t\t%d", p[k].name, p[k].at, p[k].burst,p[k].wait,p[k].tat);
	}
	sawt=(float)stwt/n;
	satat=(float)sttat/n;
	printf("\nstwt=%d\nsttat=%d\nsatwt=%f\nsatat=%f\n\n", stwt, sttat, sawt, satat);
}

int minimum()
{
	int i, j, min, pro_no, k;
	min=999;
	for(i=0;i<n;i++)
	{
		if(p[i].flag==1)
		{
			if(p[i].remaining<min)
			{
				min=p[i].remaining;
				pro_no=i;
			}
		}
	}
	return(pro_no);
}

void round_robin()
{
	printf("\nEnter the number of processes: ");
	scanf("%d",&n1);
	printf("\nEnter the burst time for sequences:\n");
	for(i=0; i<n1; i++)
	{
		scanf("%d",&p1[i].burst);
		p1[i].remaining=p1[i].burst;
		p1[i].at=0;
	}
	printf("\nEnter the time quantum: ");
	scanf("%d",&tq);
	printf("\n");
	t=0;
	while(1)
	{
		for(i=0,c=0;i<n1;i++)
		{
			temp=tq;
			if(p1[i].remaining==0)
			{
				c++;
				continue;
			}
			if(p1[i].remaining>tq)
			{
				p1[i].remaining=p1[i].remaining-tq;
				printf("%d-",t);
				t=t+tq;
				printf("P%d-",i);
			}
			else if(p1[i].remaining>=0)
			{
				temp=p1[i].remaining;
				printf("%d-",t);
				t=t+p1[i].remaining;
				p1[i].remaining=0;
				printf("P%d-",i);
			}
			sq=sq+temp;
			p1[i].tat=sq;
		}
		if(n1==c)
			break;
	}
	printf("%d",t);
	for(i=0;i<n1;i++)
	{
		p1[i].wait=p1[i].tat-p1[i].burst;
		rtwt=rtwt+p1[i].wait;
		rttat=rttat+p1[i].tat;
	}
	rawt=(float)rtwt/n1;
	ratat=(float)rttat/n1;
	printf("\n\nProcess_no\tBurst time\tWait Time\tTurn Around Time\n");

	for(i=0;i<n1;i++)
		printf("P%d\t\t%d\t\t%d\t\t%d\n",i+1,p1[i].burst,p1[i].wait,p1[i].tat);
	printf("\nAverage waiting time is: %f",rawt);
	printf("\nAverage turn around time is: %f\n\n",ratat);
}
