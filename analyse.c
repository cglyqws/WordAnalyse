#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>
char stmp[500];

int tempint;

void printtoken(char *word)
{
	if (!strcmp(word,"BEGIN"))
	{
		printf("Begin\n");
	}
	else if (!strcmp(word,"END"))
	{
		printf("End\n");
	}
	else if (!strcmp(word,"FOR"))
	{
		printf("For\n");
	}
	else if (!strcmp(word,"IF"))
	{
		printf("If\n");
	}
	else if (!strcmp(word,"THEN"))
	{
		printf("Then\n");
	}
	else if (!strcmp(word,"ELSE"))
	{
		printf("Else\n");
	}
	else 
	{
		printf("Ident(%s)\n",word);
	}
}
int analyse (char *s)
{
//	printf("%s\n",s);
	char temp[500];
	int i,start=0,lenth=0;
	for (i=0;s[i]!='\0'&&s[i]!='\n';i++)
	{
//		printf("%c",s[i]);

		if (isalpha(s[i]))
		{
			start = 0;
			while (isalpha(s[i])||isdigit(s[i]))
			{
				temp[start++] = s[i];
				i++;	
			} 
			temp[start] = '\0'; 
			printtoken(temp);
			i--;
		}
		else if (isdigit(s[i]))
		{
			start = 0;
			while (isdigit(s[i]))
			{
				temp[start++] = s[i];
				i++;	
			} 
			temp[start] = '\0'; 
		
			tempint = atoi(temp);
			printf ("Int(%d)\n",tempint);
			
		}
		else 
		{
			switch(s[i])
			{
				case ':':
					if (s[i+1]=='=')
					{
						printf("Assign\n");
						i++;
						break;
					}
					else 
					{
						printf("Colon\n");	
					}
					break;
				case '+':
					printf("Plus\n");
					break;
				case '*':
					printf("Star\n");
					break;
				case ',':
					printf("Comma\n");
					break;
				case '(':
					printf("LParenthesis\n");
					break;
				case ')':
					printf("RParenthesis\n");
					break;	
				case ' ':
					break;
				default :
					return 0;		
			}	
		}
	}
	return 1;
}
int flag;
int main ()
{
	FILE *in = fopen("./dockerfile","rt");
	fgets(stmp,500,in);
	int size = sizeof(stmp) ;
		
	while  (stmp[0]!='\0')
	{
		flag = analyse(stmp);
//		printf("%d\n",flag);
		if (flag)
		{
			memset(stmp, 0, size);
			fgets(stmp,1025,in);
		}
		else break;
		
	}
}