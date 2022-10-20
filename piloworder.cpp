#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
	int menu=0;
	char name[100][500]={};
	int index=0;
	char type[100][500]={};
	char addr[100][500]={};
	float quan[100]={};
	char date[100][500]={};
	srand(time(0));
	float price[100]={};
	
	while(1)
	{
		system("cls");
		puts("===================");
		puts("| Bluejack Pillow |");
		puts("===================");
		puts("1. Order Pillow");
		puts("2. View Order");
		puts("3. Remove Order");
		puts("4. Exit");
		printf(">>");
		scanf("%d",&menu);
		getchar();
		if(menu==1)
		{
			system("cls");
			do{
				printf("Input receiver name: ");
				scanf("%[^\n]",&name[index]);
				getchar();
			}while(strlen(name[index])<5||strlen(name[index])>25);
			int spacefind=0;
			int countal=0;
			int countspc=0;
			do{
				printf("Input address[alphanumeric and space only]: ");
				scanf("%[^\n]",&addr[index]);
				getchar();
				spacefind=0;
				if(addr[index][0]==' '||addr[index][strlen(addr[index])-1]==' ')
				{
					spacefind++;
				}
				countal=0;
				countspc=0;
				for(int x=0;x<strlen(addr[index]);x++)
				{
					if(isalnum(addr[index][x])!=0||isspace(addr[index][x])!=0)
					{
						countal++;
					}
				}
			}while(spacefind!=0||strlen(addr[index])!=countal);
			do{
				printf("Input pillow type: ");
				scanf("%s",&type[index]);
				getchar();
			}while(strcmp(type[index],"Microfiber")!=0&&strcmp(type[index],"Latex")!=0&&strcmp(type[index],"Feather")!=0);
			do{
				printf("Input Quantity: ");
				scanf("%f",&quan[index]);
				fflush(stdin);
			}while(quan[index]<1||quan[index]>10);
			int d=0;
			int m=0;
			int y=0;
			int benar=0;
			do{
				benar=1;
				printf("Select Order date: ");
				scanf("%[^\n]",&date[index]);
				getchar();
				for(int z=0;z<strlen(date[index]);z++)
				{
					if((z==2||z==5)&&date[index][z]!='/')
					{
						benar=0;
						break;
					}
					else if((z!=2&&z!=5)&&isdigit(date[index][z])==0)
					{
						benar=0;
						break;
					}
				}
				if(benar==1)
				{
					d=m=y=0;
					d=(10*(date[index][0]-'0'))+(date[index][1]-'0');
					m=(10*(date[index][3]-'0'))+(date[index][4]-'0');
					y=(1000*(date[index][6]-'0'))+(100*(date[index][7]-'0'))+(10*(date[index][8]-'0'))+(date[index][9]-'0');

				}
				
				}while(benar!=1||strlen(date[index])!=10||(d<=0||d>31)||(m<=0||m>12)||(y<=0||y>9999));
				printf("\n");
				float dis=(rand()%10+1)*5;
				printf("Thank you for your order...\n");
				printf("Congratulations, %.f%c was deducted from your purchase!\n",dis,'%');
				if(strcmp(type[index],"Latex")==0)
				{
					price[index]=(250000*quan[index])*((100-dis)/100);
				}
				else if(strcmp(type[index],"Microfiber")==0)
				{
					price[index]=(350000*quan[index])*((100-dis)/100);
				}
				else
				{
					price[index]=(450000*quan[index])*((100-dis)/100);
				}
				printf("Amount to be paid: %.2f\n",price[index]);
				printf("Press any key to continue");
				index++;
				getchar();	
		}
		if(menu==2)
		{
			system("cls");
			if(index==0)
			{
			printf("Order is empty...\n");
			printf("Please make an order first!");
			getchar();
			continue;
			}
			else
			{
				puts("=========================================================================================================================");
				puts("|No  |Receiver Name             |Destination                         |Pillow Type |Quantity  |Order Date  |Total Price  |");
				puts("=========================================================================================================================");
				for(int x=0;x<index;x++)
				{
				printf("|%-3d |%-25s |%-35s |%-11s |%-9d |%-11s |%-12.2f |\n",x+1,name[x],addr[x],type[x],(int)quan[x],date[x],price[x]);
				}
				puts("=========================================================================================================================");
				printf("Press Any Key to Continue...");
				getchar();
			}
		}
		if(menu==3)
		{
			system("cls");
			if(index==0)
			{
			printf("Order is empty...\n");
			printf("Please make an order first!");
			getchar();
			continue;
		}
		else
		{
			int pick=0;
			do{
				printf("Choose the order to be cancelled [1-%d][0 to return to main menu]: ",index);
				scanf("%d",&pick);
				fflush(stdin);
			}while(pick<0||pick>index);
			if(pick==0)
			{
				continue;
			}
			for(int x=pick-1;x<index;x++)
			{
				strcpy(name[x],name[x+1]);
				strcpy(addr[x],addr[x+1]);
				strcpy(type[x],type[x+1]);
				quan[x]=quan[x+1];
				strcpy(date[x],date[x+1]);
				price[x]=price[x+1];
			}
			index--;
			printf("Order has been canceled...");
			printf("Press Any key to continue");
			getchar();
		}
		}
		if(menu==4)
		{
			break;
		}
		
	}
}
