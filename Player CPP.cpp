using namespace std;
#include<iostream>
#include<string.h>
#include<stdlib.h>

 struct Player
{
	char name[30];
	int jerseyNum;
	int runs;
	int wickets;
	int matchplayed;
	
};

void addplayer(struct Player *,int);
void display(struct Player *,int);
void search(struct Player*,int);
void update(struct Player *,int);
void removeData(struct Player *,int);
void displaytop3(struct Player*,int);


int main(){
	
	int choice;
    int n;
	cout<<"Enter how many players you want to print : ";
	cin>>n;

	do{
		 cout<<"\n"<<"====="<< "Player Management System"<< "====="<<"\n";
	cout<<"1.Add Player"<<"\n"<<"2.Display"<<"\n"<<"3.Search"<<"\n"<<"4.Update"<<"\n"<<"5.RemoveData"<<"\n"<<"6.displaytop3"<<"\n";	
	cout<<"\n"<<"Enter your choice: ";
	fflush(stdin);
	cin>>choice;
	switch (choice){
		case 1:{
			Player p1[5];
			addplayer(p1,5);
			break;	
		}
		case 2:{
			Player p1[5];
			display(p1,5);
			break;
		
		}
		case 3:{
			Player p1[5];
			search(p1,5);
			break;
			
		}
		case 4:{
			Player p1[5];
			update(p1,5);
			break;
		}
				
		case 5:{
			Player p1[5];
			removeData(p1,5);
			break;
		
		}
			 
		case 6:{
			Player p1[5];
		   displaytop3(p1,5);
			break;
		}
	}
}
while(1);
}
void addplayer(struct Player *p1, int n)
{

	cout<<"~~~~~~~~~~~~~~~~~~~ "<<"Add The Player Info"<<"~~~~~~~~~~~~~~~~~~~";
	for(int i=0;i<n;i++)
	{
	
	cout<<"\n"<<"Enter Player name: ";
    cin>>p1[i].name;
    
    cout<<"Enter Jersey number: ";
    cin>>p1[i].jerseyNum;
    
    cout<<"Enter the runs: ";
    cin>>p1[i].runs;
    
    cout<<"Enter the wickets number: ";
    cin>>p1[i].wickets;
    
    cout<<"Enter the matched played: ";
    cin>>p1[i].matchplayed;
    
    
    cout<<"Player added successfully!"<<"\n";
   }
}
void display(Player *p1, int n)
{	
	for(int i=0;i<n;i++)
{
	cout<<"\n";
	cout<<"Player name is: "<<p1[i].name<<"\n"; 
	cout<<"Jersey number is: "<<p1[i].jerseyNum<<"\n";
    cout<<"Runs are: "<<p1[i].runs<<"\n";
    cout<<"Total wickets are: "<<p1[i].wickets<<"\n";
    cout<<"Total matched played: "<<p1[i].matchplayed<<"\n";
    cout<<"\n";
	  	
}
}

void search(Player* p1,int n)
{
	char name[30];
	int jerseyNum;
	int choice;
	cout<<"1=Search for Player name OR 2=Search for Player Jersey no."<<"\n";
	cout<<"Enter the choice:  ";
	cin>>choice;
	if(choice==1){
		cout<<"Search Player name: "<<"\n";
		fflush(stdin);
		cin>>name;
	}
	else{
		cout<<"Search Player Jersey no.: "<<"\n";
		cin>>jerseyNum;
	}
	
	int count=0;
	for(int i=0;i<n;i++){
		if(strcmp(name,p1[i].name)==0 || jerseyNum==p1[i].jerseyNum)
		{
			count=1;
		}
	
	}
	
	if(count==1){
		cout<<"Player is present... "<<"\n";
		
	}
	else{
		cout<<"Player is not present... "<<"\n";
	}
}

void update(struct Player* p1,int n)
{
    int jerseyNum;
    int runs;
    int wickets;
    int matchplayed;
	cout<<"Enter Players Jersey Number: ";
	cin>>jerseyNum;
	for(int i=0;i<n;i++)
	{
		if(jerseyNum==p1[i].jerseyNum)
		{
			cout<<"Update Players Runs: ";
			cin>>runs;
			p1[i].runs=runs;
			cout<<"Update Players Wickets: ";
			cin>>wickets;
			p1[i].wickets=wickets;
			cout<<"Update total matched played : ";
			cin>>matchplayed;
			p1[i].matchplayed=matchplayed;
			
		}
	}
}

void removeData(Player* p1,int n)
{
	int removePlayer;
	cout<<"Enter the jersey no you want to remove: ";
	cin>>removePlayer;

    int found = 0;

    for (int i = 0; i < n; i++)
	 {
        if (p1[i].jerseyNum == removePlayer)
		 {
            for (int j = i; j < n - 1; j++) 
			{
                p1[j] = p1[j + 1];
            }
            (n)--;
            found = 1;
            cout<<"Player with jersey number  has been removed successfully."<<"\n"<<removePlayer;
            break;
        }
    }

    if (found == 0)
	 {
        cout<<"Player with jersey number  not found."<<"\n"<<removePlayer;
    }
}


//////////////////////////////////////////////////////////////////////////////////////
void displaytop3(Player* p1,int n){

for(int i=0;i<n;i++){
 cout<<"\n"<<"jersery no: "<<p1[i].jerseyNum<<"\n"<<"runs : "<<p1[i].runs<<"\n"<<"wickets: "<<p1[i].wickets<<"\n"<<"name: "<<p1[i].name<<"\n"<<"matchplayed: "<<p1[i].matchplayed<<"\n"; 
 cout<<"\n";
}
     for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p1[j].runs < p1[j + 1].runs) {
                 Player temp = p1[j];
                p1[j] = p1[j + 1];
                p1[j + 1] = temp;
           }
        }
     }
     cout<<"TOP 3 PLAYERS:"<<"\n";
     for(int i=0;i<n;i++){
         cout<<"jersery no: "<<p1[i].jerseyNum<<"\n"<<"runs:  "<<p1[i].runs<<"\n"<<"wickets: "<<p1[i].wickets<<"\n"<<"name: "<<p1[i].name<<"\n"<<"matchplayed: "<<p1[i].matchplayed<<"\n"; 
         cout<<"\n";
     }
}

