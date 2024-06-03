#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct player{
	char name[20];
	int jerno;
	int innings;
	int wickets;
	int runs;
	
}player;     
//void dummystoreplayer(player *,int );
void storeplayer(player *,int);
void displayer(player*,int );
void addplayer(player*,int);
void removeplayer(player *, int *);
void searchplayer(player*,int );
void searchbyname(player*,int );
void searchbyjerseyno(player*,int );
void updateplayer(player*,int);
void top3(player*,int);
void displayer(player*,int );
void maxruns(player*,int);
void maxwickets(player*,int);
int main()
{  
    int n,choice;
    char c;
    printf("Enter No of Players to add in database:");
    scanf("%d",&n);
	player *arr;
	arr=(player*)malloc (sizeof(player)*n);
	//dummystoreplayer(arr,n);
	storeplayer(arr,n);
	do{
		printf("\nMENU\n1.Add Player\n2.Remove Player\n3.Search Player\n4.Update player.\n5.Top 3\n6.Display Player.\n7.Exit.");
	printf ("\nEnter Choice:");
	scanf("%d",&choice);
	
	switch (choice)	
	{  
	case 1:
	   addplayer(arr,n);
	   n++;
	   break;
	case 2:
		removeplayer(arr,&n);
		break;
	case 3:
		searchplayer(arr,n);
		break;
	case 4:
		updateplayer(arr,n);
		break;
	case 5:
		top3(arr,n);
	case 6:
	    displayer(arr,n);
		break;
	case 7:
        printf("Exit\n");
        break;
        
    default:
       printf("Invalid choice! Please enter a valid choice.\n");
    }
    printf("\nDo You want to Continue(y/n)");
    fflush(stdin);
    scanf("%c",&c);
}
    
    
   	while (c=='y'||c=='Y');
   	
	return 0;
}


void storeplayer(player *arr,int n)
{
	int i;
	for(i=0;i<n;i++)
	{   fflush(stdin);
		printf("Player Name:");
		gets(arr[i].name);
		printf("Jersey No:");
		scanf("%d",&arr[i].jerno);
		printf("Innings:");
		scanf("%d",&arr[i].innings);
		printf("Wickets:");
		scanf("%d",&arr[i].wickets);
		printf("Runs:");
		scanf("%d",&arr[i].runs);
		
	}
	
}

void addplayer(player*arr,int n)
{   
    

	{
		fflush(stdin);
		printf("Player Name:");
		gets(arr[n].name);
		printf("Jersey No:");
		scanf("%d",&arr[n].jerno);
		printf("Innings:");
		scanf("%d",&arr[n].innings);
		printf("Wickets:");
		scanf("%d",&arr[n].wickets);
		printf("Runs:");
		scanf("%d",&arr[n].runs);
	 
	 printf("Player with Jersey Number %d added sucessfully.\n",arr[n].jerno);
            
	}
	
}
void removeplayer(player *arr, int *n) {
    int jerno;
    printf("Enter the Jersey Number player to remove stat: ");
    scanf("%d", &jerno);

    int found = 0;
    for (int i = 0; i < *n; i++)
	 {
        if (arr[i].jerno == jerno)
		 {
            found = 1;
            for (int j = i; j < *n - 1; j++) 
			{
                arr[j] = arr[j + 1];
            }
            
            (*n)--;
			printf("Player with Jersey Number %d removed.\n", jerno);
            break;
        }
    }
    if (found==0) {
        printf("Player with Jersey Number %d not found.\n", jerno);
    }
}
void searchplayer(player*arr,int n)
{
	int choice;
	printf("\nSearch players Stat By:\n1.Name.\n2.Jersey No.");
    printf("\nEnter Choice for Search:");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
	searchbyname(arr,n);
	break;
	case 2:
	searchbyjerseyno(arr,n);
	break;
	default:
	printf("Invalid Choice! please enter valid choice:");
	}
	
}

void searchbyname(player*arr,int n)
{   int count=0;
    char searchname[20];
    fflush(stdin);
    printf("\nEnter name You want search:");
    gets(searchname);
	int i;
	for(i=0;i<n;i++)
	{
	   if ((strcasecmp(arr[i].name, searchname) == 0))
		{
		  count++;
		    
		  	printf("\n%s\nInnings:%d\nWickets:%d\nRuns:%d",arr[i].name,arr[i].innings,arr[i].wickets,arr[i].runs);	
		}
	}

	if(count!=0)
	printf("Player not found ! please enter valid name.");
}
void searchbyjerseyno(player*arr,int n)
{   int count=0;
    int no;
    printf("\nEnter jersey No You want search:");
    scanf("%d",&no);
	int i;
	for(i=0;i<n;i++)
	{
	   if (arr[i].jerno==no)
		{
		  count++;
		    
		  	printf("\n%s\nInnings:%d\nWickets:%d\nRuns:%d",arr[i].name,arr[i].innings,arr[i].wickets,arr[i].runs);	
		}
	}
	if(count==0)
	printf("Player not found ! please enter valid name.");
}
void updateplayer(player* arr, int n) {
    int count = 0;
    int no;
    printf("\nEnter jersey No You want to update:");
    scanf("%d", &no);
    int i;
    for (i = 0; i < n; i++) 
	{
        if (arr[i].jerno == no) 
		{
            count++;
            int choice;
            printf("\nUpdate Player stat:\n1. Innings\n2. Runs\n3. Wickets\n");
            printf("Enter choice: ");
            scanf("%d", &choice);
            switch (choice)
			 {
                case 1:
                    printf("Update innings: ");
                    scanf("%d", &arr[i].innings);
                    printf("Player with Jersey Number %d's innings updated.\n", no);
                    break;
                case 2:
                    printf("Update runs: ");
                    scanf("%d", &arr[i].runs);
                    printf("Player with Jersey Number %d's runs updated.\n", no);
                    break;
                case 3:
                    printf("Update wickets: ");
                    scanf("%d", &arr[i].wickets);
                    printf("Player with Jersey Number %d's wickets updated.\n", no);
                    break;
                default:
                    printf("Invalid choice! Please enter a valid choice.\n");
            }
        }
    }
    if (count == 0) {
        printf("Player not found! Please enter a valid jersey number.\n");
    }
    displayer(arr, n);
}
void top3(player*arr,int n)
{
  int choice;
	printf("\nSearch Top 3 Stat By:\n1.Runs.\n2.Wickets.");
    printf("\nEnter Choice for Search:");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
	maxruns(arr,n);
	break;
	case 2:
	maxwickets(arr,n);
	break;
	default:
	printf("Invalid Choice! please enter valid choice:");
	}
		
}
void maxruns(player* arr, int n)
{
    int i, j;
    player temp;
    
    
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j].runs < arr[j + 1].runs)
            {
                
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Top 3 players with the most runs:\n");
    for (i = 0; i < 3 && i < n; i++)
    {
        printf("Name: %s\nJersey No: %d\nInnings: %d\nWickets: %d\nRuns: %d\n",
               arr[i].name, arr[i].jerno, arr[i].innings, arr[i].wickets, arr[i].runs);
    }
}

void maxwickets(player *arr, int n) {
    int i, j;
    player temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].wickets < arr[j + 1].wickets) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\nTop 3 players with the most wickets:\n");
    for (i = 0; i < 3 && i < n; i++) {
        printf("Name: %s\nJersey No: %d\nInnings: %d\nWickets: %d\nRuns: %d\n",
               arr[i].name, arr[i].jerno, arr[i].innings, arr[i].wickets, arr[i].runs);
    }
}
void displayer(player*arr,int n)
{   printf("|Player Name     | Jersey No    |Innings   |Wickets      |Runs ");
	int i;
	for(i=0;i<n;i++) 
	{  
    	printf("\n|---------------|---------|---------|-----------|-------|\n");
		printf("|  %-15s%-5d     %-5d      %-5d      %-5d",arr[i].name,arr[i].jerno,arr[i].innings,arr[i].wickets,arr[i].runs);
	}   printf("\n|---------------|---------|---------|-----------|-------|\n");
}



	  		
