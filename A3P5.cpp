#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

void input(string& Eadress);
bool wschecker(string Eadress);
bool adcount(string Eadress);
bool fstcharchecker(string Eadress);
bool sidechecker(string Eadress);



void input(string& Eadress)
{
	cout<<"enter the adress: ";
	getline(cin,Eadress);
	cout<<"you entered: "<<Eadress<<endl;
	
}

bool wschecker(string Eadress)
{
	bool b=false;
	
	for(int i=0; i<Eadress.length(); i++)
	{
		if(isspace(Eadress.at(i)))
		{
			b=true;
		}

		
	}
	return b;
}

bool adcount(string Eadress)
{
  int counter=0;
  bool b=false;
  
  for(int i=0; i<Eadress.length(); i++)
  {
  	if(Eadress.at(i)=='@')
  	{
  		counter++;
	}
  }
 
 if(counter != 1)
 
 	b=true;
 
 
 
 
 return b;
}


bool fstcharchecker(string Eadress)
{
	bool b=false;
	
	for(int i=0; i<Eadress.length(); i++)
	{
		if(Eadress.at(0)=='@')
		{
			b=true;
		}
		
	}
	
	return b;
}

bool sidechecker(string Eadress)
{
	bool b=false;
	
	int l = Eadress.length();
	if (Eadress.at(0) == '.' || Eadress.at(l-1)== '.')
	{
            b = true;
	}
	
	for(int i=1; i<l-1; i++)
		{
		
		if(Eadress.at(i)=='.')
		{
			if (Eadress.at(i-1)=='@' || Eadress.at(i-1)=='.')
			{
				b=true;
			}
			if (Eadress.at(i+1)=='@' || Eadress.at(i+1)=='.')
			{
				b=true;
			}
		}
		
		
			
		}
		return b;
}
		
		

int main()
{
	string email;
	char answer;
	bool result[4]={false,false,false,false};
	
	do
	{
	
	input(email);
	
	result[0]=wschecker(email);
	result[1]=adcount(email);
	result[2]=fstcharchecker(email);
	result[3]=sidechecker(email);
	
	
        
    if(result[0])
    {
    	cout<<" invalid - contains a blank \n";
	}
	
	else if(result[1])
	{
		cout<<"invalid - not exactly one '@' \n";
	}
	
	else if(result [2])
	{
		cout<<"invalid - '@' is the first charchter \n";
	}
	
	else if(result[3])
	{
		cout<<"invalid- a dot is first or last, or preceded or followed by '@' or '.' \n";
	}
	
	else
	{
		cout<<"email is valid \n";
	}
	
	cout<<"enter another one ? (yes/no)";
	cin>>answer;
	cin.ignore(80, '\n');
	
	}while(answer=='Y'|| answer=='y');
	
}
  	
  

