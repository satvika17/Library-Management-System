#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct library
{
	char bk_name[30];
	char author[30];
	char publication[30];
	float price;
};
struct issued
{
        char bk_nm[30];
};

//global variables:
struct library l[100];
struct issued z[50];
char ar_nm[30],bk_nm1[30],bk_nm2[30];
int i, j, k, x, y , keepcount;
char Password[10]="PesuEcc";
char password[10];

//functions
void add_info()
{
	fflush(stdin);
	printf ("Enter book name = ");
	scanf ("%[^'\n']s",&l[i].bk_name);
	fflush(stdin);
	printf ("Enter author name = ");
	scanf ("%[^'\n']s",&l[i].author);
	fflush(stdin);
	printf ("Enter publication = ");
	scanf ("%[^'\n']s",&l[i].publication);
	fflush(stdin);
	printf ("Enter price = ");
	scanf ("%f",&l[i].price);
	keepcount++;
	i++;
}

void display_info()
{
	if (i==0)
	{
		printf("\nNo books existing in record\n");
	}
	else
	{
		printf("Details of the books present:\n");
                printf("\n");
		for(k=0; k<keepcount; k++)
		{
			printf ("Book name = %s\n",l[k].bk_name);
			printf ("Author name = %s\n",l[k].author);
			printf ("Publication = %s\n",l[k].publication);
			printf ("Price = %f\n",l[k].price);
			printf("\n");
		}
	}
}

void given_author()
{
	fflush(stdin);
	printf ("Enter author name : \n");
	scanf ("%[^'\n']s",ar_nm);
	printf("\n");
	for (k=0; k<keepcount; k++)
	{
		if (strcmp(ar_nm, l[k].author) == 0)
		printf ("Book name:%s, Author:%s, Publication:%s, Price:%f\n",l[k].bk_name,l[k].author,l[k].publication,l[k].price);
		printf("\n");
	}
}

void book_details()
{
	fflush(stdin);
	printf ("Enter book name : \n");
	scanf ("%[^'\n']s",bk_nm1);
	printf("\n");
	for (k=0; k<keepcount; k++)
	{
		if (strcmp(bk_nm1, l[k].bk_name) == 0)
		printf ("Book name:%s, Author name:%s, Publication:%s, Price:%f",l[k].bk_name,l[k].author,l[k].publication,l[k].price);
		printf("\n");
	}
}

void issue_book()
{
        y=0;
        int issue=0;
	fflush(stdin);
	printf ("Enter book name = ");
	scanf ("%[^'\n']s",bk_nm2);
        printf("\n");
        for (k=0; k<keepcount; k++)
        {
            if(strcmp(bk_nm2,l[k].bk_name)==0)
             {
             printf(" %s is issued\n\n",l[k].bk_name);
             issue=1;
             strcpy(z[y].bk_nm,bk_nm2);
             }
             y++;
        }
        if(issue==0)
        printf("book is not present in the library\n");
	
}

void display_info_issued()
{
	int c,issue;
        if (issue==0)
	{
		printf("\nNo books issued\n");
	}
	else
	{
           for(c=0;c<y;c++) 
           {
                printf("%s",z[c].bk_nm); 
                printf("\n"); 
           }     
	}
}

int main()
{
	i=j=k=x=keepcount=0;	
	printf("******ENTER PASSWORD******\n");
	scanf("%s",&password);
	if(strcmp(Password,password)==0)
	{
		while(j!=8)
		{
			printf("\n\n1. Add book information\n2. Display book information\n");
			printf("3. List all books of given author\n");
			printf("4. List the details of specified book\n");
			printf("5. List the count of books in the library\n");
			printf("6. Issue Book\n");
			printf("7. List all issued books\n");
			printf("8. Exit");
			printf ("\n\nEnter one of the above :\n");
			scanf("%d",&j);
			switch (j)
			{
				/* Add book */
				case 1:  
					add_info();
					break;
				case 2:
					display_info();
					break;
				case 3:
					given_author();
					break;
				case 4:
					book_details();
					break;
				case 5:
					printf("\n No of books in library : %d", keepcount);
					break;
				case 6:
					issue_book();
					break;
				case 7:
					display_info_issued();
					break;
				case 8:
					exit (0);
                                default:
                                        printf("INVALID OPTION ENTERED");

			}
		} 
	}
	else
		printf("INVALID PASSWORD");
	return 0;
}
