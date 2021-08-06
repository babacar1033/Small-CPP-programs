#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main ()
{
	string tInput;
	int upper=0, lower=0,  digit=0, space=0, punct=0;
	char c;
	
	cout<<"enter a text for evaluation- put a '@' sign to end your text entring \n";
	getline(cin, tInput, '@');
	
	for (int i=0; i < tInput.length(); i++)
	{
	
		
		if(isupper(tInput.at(i)))
		{
			upper++;
		}
		
		if(islower(tInput.at(i)))
		{
			lower++;
		}
		
		if(isdigit(tInput.at(i)))
		{
			digit++;
		}
		
		if(isspace(tInput.at(i)))
		{
			space++;
		}
		
		if(ispunct(tInput.at(i)))
		{
			punct++;
		}
	}
	
	cout<<"There were "<<tInput.length()<<" total charcters \n";
	cout<<"There were "<<upper<<" upper case letters \n";
	cout<<"There were "<<lower<<" lower case letters \n";
	cout<<"There were "<<digit<<" digits \n";
	cout<<"There were "<<space<< " white space charcters \n";
	cout<<"There were "<<punct<<" other charcters \n";
}

