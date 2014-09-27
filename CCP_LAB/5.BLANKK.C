#include<stdio.h>
#include<conio.h>
void main()
{
	char s1[100],s2[100];
	int sp=0,i=0,j=0;

	clrscr();

	printf("Enter string:\n");
	gets(s1);

	while(s1[i]!='\0')
	{
		if(s1[i]==' ')
		{
			if(sp>0)
			{
				i++;
				continue;
			}
			s2[j++]=s1[i++];
			sp++;
		}
		else
		{
			s2[j++]=s1[i++];
			sp=0;
		}
	}
	s2[j]='\0';

	printf("New string:\n");
	puts(s2);

	getch();

}
