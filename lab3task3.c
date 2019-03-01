
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void mygrep(FILE*, char*);

void myreplace(FILE *fp,char *find, char * replace);

int  main(int argc,char *argv[])
{


	char* behaviour;
	FILE *fp;
	char *filename=argv[1];
	char *find=argv[2];
	char * replace;

	
	if(strcmp(argv[0], "mygrep") == 0 || strcmp(argv[0], "./mygrep") == 0)
	{
		if(argc != 3)
		{
			printf("usage\t./mygrep filename <string-to-search>\n");
			exit(1);
		}

		behaviour = "GREP";
	}
	else if(strcmp(argv[0], "myreplace") == 0 || strcmp(argv[0], "./myreplace") == 0)
	{
		if(argc != 4)
		{
			printf("\t./myreplace filename  <string-to-search> <string-to-replace>");
			exit(1);
		}
		behaviour = "REPLACE";
		replace = argv[3];
	}
	else
	{
		behaviour = NULL;
	}


	

	fp=fopen(filename,"rt");

	if(behaviour == "GREP")
	{
		mygrep(fp,find);	

	}
	else if ( behaviour == "REPLACE" )
	{
		myreplace(fp,find,replace);		

	}
	
	fclose(fp);		

	return 0;
}


void mygrep(FILE *fp,char *find)
{
	char c1[500];
 
	while(fgets(c1, 500, fp) != NULL)
	{
		for (int i = 0; i < strlen(c1); i++)
		{
			if (find[0] == c1[i])
			{
				if (memcmp(find, c1 + i, strlen(find)) == 0)
				{
					printf("%s\n", c1);
				}
			}
		}
	}
}





void myreplace(FILE *fp,char *find, char * replace)
{
	char c1[500];
	int f = strlen(find);


	while(fgets(c1, 500, fp) != NULL)
	{
		for (int i = 0; i < strlen(c1); i++)
		{
	          	 if (find[0] == c1[i])
			{
                     if (memcmp(find, c1 + i, strlen(find)) == 0)
				{
					char* macro = (char*)malloc(strlen(c1) - f + strlen(replace));
					
				printf("%s\n", c1);
				memcpy(macro, c1, i);
				memcpy(macro + i, replace, strlen(replace));
				memcpy(macro + i + strlen(replace), c1 + i + f, strlen(c1) - (i + f));
				macro[strlen(c1) - f + strlen(replace)] = NULL;
				printf("%s\n", macro);
				}
			       }
		           }
	                 }
                       }
