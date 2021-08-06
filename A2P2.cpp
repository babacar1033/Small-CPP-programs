//BABACAR DIOUF
// AZIZA NAZMUTDINOVA
//ELYAAS HASSEN

//problem 2







#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;



void getCompSelection(int& cs)
{
	cs= 1+rand()%3;
}

void getUserSelection(int& ps)
{
	cout<<"what's your play ? \n";
	cout<<"Rock (1), Paper (2), Scissors (3) \n";
	cin>>ps;
}

void PlayResults(int& x,int& y, int& z)
{

int counterT=0;
int counterP=0;
int counterC=0;
char ans;


do{

int ps,cs;


getUserSelection(ps);
getCompSelection(cs);

if (ps==1 && cs==1)
{
	cout<<"you play rock and i play rock \n";
	cout<<"the play was a tie \n";
	counterT++;
	}
	
else if(ps==2 && cs==2)	
{
	cout<<"you play paper and i play paper \n";
	cout<<"the play was a tie \n";
	counterT++;
}
else if(ps==3 && cs ==3)
{
	cout<<"you play scissor and i play scissor \n ";
	cout<<"the play was a tie \n";
	counterT++;
}

else if(ps==1 && cs== 3)
{
	cout<<"you play rock and i play scissor \n ";
	cout<<"you win \n";
	counterP++;
}
else if(ps==3 && cs == 2)
{
	cout<<"you play scissor and i play paper"<<endl;
	cout<<"you win"<<endl;
	counterP++;
}

else if(ps==2 && cs==1)
{
	cout<<"you play paper and i play rock \n";
	cout<<"you win "<<endl;
	counterP++;
}
else if (cs==1 && ps==3)
{
	cout<<"you play scissor and i play rock \n";
	cout<<" I win"<<endl;
	counterC++;
}
else if(cs==3 && ps==2)
{
	cout<<"you play paper and i play scissor \n";
	cout<<"i win \n";
	counterC++;
}
else if(cs==2 && ps==1)
{
	cout<<"you play rock and i play paper \n";
	cout<<"i win \n";
	counterC++;
}

cout<<"play again ? (y or n)"<<endl;
cin>>ans;

}while(ans=='y' || ans == 'Y');

x=counterT;
y=counterC;
z=counterP;

}

void finalResults(int x, int y, int z)
{
	
	int counterP,counterC,counterT;
	cout<<"Final results of our game : "<<endl;
	cout<<"you won "<<z<<" time(s)"<<endl;
	cout<<"i won "<<y<<" time(s)"<<endl;
	cout<<"There were "<<x<<" tie(s)"<<endl;
	cout<<"see ya next time homie ! \n";
	
}


int main()
{
	
	int cs, ps, counterT, counterP, counterC,x,y,z;
	char ans;
	
	srand(time(0));
	
	cout<<"it's time to play ROCK , PAPER, SCISSORS mesdames et messieurs ! \n";	
	PlayResults(counterT,counterC,counterP);
	finalResults(counterT,counterC,counterP);
	
	
	
	
}


