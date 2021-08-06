//BABACAR DIOUF
// AZIZA NAZMUTDINOVA
//ELYAAS HASSEN

//problem 3







#include <iostream>
using namespace std;

void input(int& number);


void input(int& number){

		cout<<"which one do you want ? (negative to exit) "<<endl;
		cin>>number;
	
	
}


int fiboc(int number)
{
	
if (number == 1) 
        {
		
		return 0; 
		
	}
    else if (number==2)
    {
    	return 1;
    }
    
else
{

	
	return fiboc(number-1) + fiboc(number-2); 
}



}




int main()
{

int number;

cout<<"Fibbonaci number generator \n";	

	
do{

input(number);
cout<<"the "<<number<<" th fibonacci number is " <<fiboc(number)<<endl;

}while(number>=0);
}



