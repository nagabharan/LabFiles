#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int matchany(char [],char []);
void main()
{
	char s1[100],s2[100];
	int x;

	clrscr();

	printf("Enter the string s1:");
	gets(s1);
	printf("Enter the string s2:");
	gets(s2);

	x=matchany(s1,s2);
	if(x==-1)
	{
		printf("No character is common between the 2 strings");
		getch();
		exit(0);
	}
	else
		printf("Common characters found\nPosition of character in string1 is %d",x+1);

	getch();

}
int matchany(char a[100],char b[100])
{
	static int l1,l2,i,j;

	while(a[i]!=NULL)
	{
		l1++;
		i++;
	}
	while(b[j]!=NULL)
	{
		l2++;
		j++;
	}

	for(i=0;i<l2;i++)
	{
		for(j=0;j<l2;j++)
		{
			if(b[i]==a[j] && b[i]!=' ')
			{
					return i;
			}
		}
	}
	return (-1);

}