#include<stdio.h>
#include<conio.h>
void rev(char [],char [],int );
void main()
{
	int i=0,l=0;
	static char a[100],rv[100];

	clrscr();

	printf("Enter the string: ");
	gets(a);

	while(a[i]!=NULL)
	{
		l++;
		i++;
	}

	rev(a,rv,l);

	printf("Original string: ");
	puts(a);
	printf("Reversed string: ");
	puts(rv);


	getch();

}
void rev(char a[100],char rv[100],int l)
{
	int i;

	for(i=l;i>=0;i--)
	{
		rv[l-i-1]=a[i];
	}
}
