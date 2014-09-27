#include<stdio.h>
#include<conio.h>
void main()
{
	char str[100];
	int l=0,i=0,w=1;

	clrscr();

	printf("Enter string:\n");
	scanf("%[^\n]",str);

	while(str[i]!='\0')
	{
		if(str[i]!=' ')
			l++;
		else
			w++;
		i++;
	}
	printf("Words=%d\nLength=%d",w,l);

	getch();

}