#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int menu;
	int index;
	char id[100][500]={};
	char name[100][500]={};
	double price[100]={};
	char disc={};
	char random[10]={"112222222"};
	srand(time(0));
	while(1)
	{
		system("cls");
		puts("Electronics!");
		puts("=========================");
		puts("1. Insert Electronics");
		puts("2. Update  Electronics");
		puts("3. Sell Electronics");
		puts("4. Exit");
		printf(">>");
		scanf("%d",&menu);
		getchar();
		if(menu==1)
		{
			system("cls");
			int check=0;
			do{
				check=0;
			printf("Input Item Id [must be numeric with exactly 3 digit]: ");
			scanf("%s",&id[index]);
			getchar();
			for(int x=0;x<3;x++)
				{
					if(isalpha(id[index][x]))
					{
						check++;
					}
				}
			}while(strlen(id[index])!=3||check!=0);
			do{
				printf("Input item name [5-25 character]: ");
				scanf("%[^\n]",&name[index]);
				getchar();
			}while(strlen(name[index])<=5||strlen(name[index])>=25);
			do{
				printf("Input item price [not more than 5M]: ");
				scanf("%lf",&price[index]);
				getchar();
			}while(price[index]>5000000);
			index++;
			printf("Item sucessfully inserted!\n");
			printf("Press enter to continue\n");
			getchar();
		}
		if(menu==2)
		{
			int pick=0;
			system("cls");
			if(index==0)
			{
				printf("There is no item yet...\n");
				printf("Press enter to continue...\n");
				getchar();
			}
			else{
				printf("=============================================================\n");
				printf("| No. | Id     | Name                      | Price          |\n");
				printf("=============================================================\n");
				for(int x=0;x<index;x++)
				{
				printf("| %-3d | ETC%s | %-25s | Rp. %-10.2lf |\n",x+1,id[x],name[x],price[x]);	
				}
				printf("=============================================================\n");
				do{
					printf("which item you want to update? [0 to exit] [1..%d]: ",index);
					scanf("%d",&pick);
					getchar();
				}while(pick<0||pick>index);
				if(pick==0)
				{
					continue;
				}
			int check=0;
			do{
				check=0;
			printf("Input Item Id [must be numeric with exactly 3 digit]: ");
			scanf("%s",&id[pick-1]);
			getchar();
			for(int x=0;x<3;x++)
				{
					if(isalpha(id[pick-1][x]))
					{
						check++;
					}
				}
			}while(strlen(id[pick-1])!=3||check!=0);
			do{
				printf("Input item name [5-25 character]: ");
				scanf("%[^\n]",&name[pick-1]);
				getchar();
			}while(strlen(name[pick-1])<=5||strlen(name[pick-1])>=25);
			do{
				printf("Input item price [not more than 5M]: ");
				scanf("%lf",&price[pick-1]);
				getchar();
			}while(price[index]>5000000);
			printf("Item sucessfully updated!\n");
			printf("Press enter to continue\n");
			getchar();
			}
		}
		if(menu==3)
		{
			char yn[5]={};
			int pick=0;
			system("cls");
			if(index==0)
			{
				printf("There is no item yet...\n");
				printf("Press enter to continue...\n");
				getchar();
			}
			else{
				printf("=============================================================\n");
				printf("| No. | Id     | Name                      | Price          |\n");
				printf("=============================================================\n");
				for(int x=0;x<index;x++)
				{
				printf("| %-3d | ETC%s | %-25s | Rp. %-10.2lf |\n",x+1,id[x],name[x],price[x]);	
				}
				printf("=============================================================\n");
						do{
					printf("which item you want to sell? [0 to exit] [1..%d]: ",index);
					scanf("%d",&pick);
					getchar();
				}while(pick<0||pick>index);
				if(pick==0)
				{
					continue;
				}
				disc=random[rand()%11];
				if(disc=='1')
				{
					printf("##########################\n");
					printf("Customer got discount 25%!\n");
					printf("##########################\n");
					printf("\n");
				printf("ETC%s Item Detail\n",id[pick-1]);
				printf("===========================\n");
				printf("Item Name: %s\n",name[pick-1]);
				printf("Item Price: %.2lf\n",price[pick-1]*0.75);
				}
				else{
				
				printf("\n");
				printf("ETC%s Item Detail\n",id[pick-1]);
				printf("===========================\n");
				printf("Item Name: %s\n",name[pick-1]);
				printf("Item Price: %.2lf\n",price[pick-1]);
			}
				int check=0;
				do{
				printf("Are you sure you want to sell this? [yes|no]: ");
				scanf("%s",&yn);
				getchar();
				if(strcmp(yn,"yes")||strcmp(yn,"no"))
				{
					check++;
				}
				}while(check==0);
				if(strcmp(yn,"yes")==0)
				{
					for(int x=pick-1;x<index-1;x++)
					{
						strcpy(id[x],id[x+1]);
						strcpy(name[x],name[x+1]);
						price[x]=price[x+1];
					}
					printf("Item successfuly sold!");
					printf("Press enter to continue...");
					index--;
					getchar();
					continue;
				}
				else{
					printf("cancel selling!\n");
					printf("Press enter to continue...");
					getchar();
					continue;
				}
		}
	}
		if(menu==4)
		{
			break;
		}
	}
}
