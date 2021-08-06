//BABACAR DIOUF
// AZIZA NAZMUTDINOVA
//ELYAAS HASSEN

//problem 1








#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.141592654;

void getDim(double& r)
{
	cout<<"enter circle radius"<<endl;
	cin >>r;
	
}

void getDim (double& l, double& w)
{

	
	cout<<"enter rectangle lenght "<<endl;
	cin>>l;
	cout<<"enter rectangle width"<<endl;
	cin>>w;
	
}

void getDim (double& s1, double& s2, double& s3 )

{
	cout<<"enter 1st side of triangle \n";
	cin>>s1;
	cout<<"enter 2nd side of triangle \n";
	cin>>s2;
	cout<<"enter 3rd side of triangle \n";
	cin>>s3;
	
}


double area(double r)

{n
	
	return (PI* pow(r,2));
	
}


double area(double l, double w)
{
	
	return(l*w);
}


double area(double s1, double s2, double s3)
{
	
	double s= (s1+s2+s3)/2;
	
	return(sqrt(s*(s-s1)*(s-s2)*(s-s3)));
	
}


double perimeter(double r)
{
	return(2*PI*r);
}

double perimeter (double l, double w)
{
	return((2*l)+(2*w));
}

double perimeter (double s1, double s2, double s3)

{
	return (s1+s2+s3);
}


void display()
{
	int choice;
	double r,l,w,s1,s2,s3;
	char ans;

	do
	{
	
	cout<<"select a shape \n";
	cout<<" circle (1)  Rectangle (2)  triangle (3) exit(4) \n";
	cin>>choice;
	
	switch(choice)
	
	{
		case 1 :
		getDim(r);
		cout<<"circle area = "<<area(r)<<" and perimeter = "<<perimeter(r)<<endl;
		break;
		
		case 2 :
		getDim(l,w);
		cout<<"rectangle area = "<<area(l,w)<<" and perimeter = "<<perimeter(l,w)<<endl;
		break;
		
		case 3 :
		getDim(s1,s2,s3);
		cout<<"triangle area = "<<area(s1,s2,s3)<<" and perimeter = "<<perimeter(s1,s2,s3)<<endl;
		break;
		
		default :
		cout<<"bye ! \n";
		break;
	}
	
	cout<<"do you want to perform another operation ? (y/Y) \n";
	cin>> ans;
	}while(ans =='y' || ans =='Y');
			
}


int main()
{
	double r,l,w,s1,s2,s3;
	display();
}
	
	

