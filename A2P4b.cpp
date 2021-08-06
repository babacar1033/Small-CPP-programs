//BABACAR DIOUF
// AZIZA NAZMUTDINOVA
//ELYAAS HASSEN

//problem 4






#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void rollDie(int ftossr[], int ntoss1)
{
    for(int i=0;i<ntoss1;i++)
    {
        ftossr[i]=1+rand()%6;
    }
}

void findSum(int tossrd1[],int tossrd2[],int stossr[],int ntoss2)
{
    for(int i=0;i<ntoss2;i++)
    {
        stossr[i]=tossrd1[i]+tossrd2[i];
    }
}
 void tossCount(int stossr1[],int counterSu[],int ntoss3)
 {
    for(int t=0;t<14;t++)
    {
    	counterSu[t]=0;
	}

     for(int j=0;j<11;j++)
     {
         for(int i=0;i<ntoss3;i++)
         {
             if(stossr1[i]==j+2)
             {
                 counterSu[j]++;
             }
         }
     }

}


void display(int counterSu1[], int ntoss4)
{
    double proba[13];

    for(int i=0;i<11;i++)
    {
        proba[i]=(counterSu1[i]*100.00) / ntoss4;
    }

cout<<"total number of tosses : "<<ntoss4<<endl;

cout<<"Toss \t Count \t Probability \n";

for(int j=0; j<11; j++)
{
cout<<j+2<<"\t"<<counterSu1[j]<<"\t"<<proba[j]<<endl;
}

}

void input(int& numOftoss)
{
	
		cout<<"enter number of tosses (1-100000) \n";
        cin>>numOftoss; 
		if(numOftoss<1 || numOftoss>100000)
        {
        	do{
				
		cout<<"please enter value between 1 and 100000 \n";
        cin>>numOftoss;
        
    		  }while(numOftoss<1 || numOftoss>100000);
        
		
    }
}


int main()
{
     int numOftoss;
  
    char ans;
      
		srand(time(0));
		
 
	do{
		
		input(numOftoss);
		int fdice[numOftoss], sdice[numOftoss],Stoss[numOftoss],counter[11];
        rollDie(fdice,numOftoss);
        rollDie(sdice,numOftoss);
        findSum(fdice,sdice,Stoss,numOftoss);
        tossCount(Stoss,counter,numOftoss);
        display(counter,numOftoss);        
        cout<<"another simulation (y/n) \n";
        cin>>ans;
    }
    while(ans=='y' || ans=='Y' );
    
}

