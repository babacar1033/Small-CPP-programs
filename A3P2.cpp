#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;


class Complex

{
	public:
		
	Complex();
	Complex(double rValue);
	Complex(double rValue, double iValue);
	double getRvalue() const;
	double getIvalue() const;
	friend const Complex operator +(const Complex& comp1, const Complex& comp2);
	friend const Complex operator -(const Complex& comp1, const Complex& comp2);
	friend const Complex operator *(const Complex& comp1, const Complex& comp2);
	friend const Complex operator /(const Complex& comp1, const Complex& comp2);
	friend bool operator ==(const Complex& comp1, const Complex& comp2);
	friend istream& operator >>(istream& inputStream, Complex& comp3);
	friend ostream& operator <<(ostream& outputStream, const Complex& comp3);	
		
		
	private:
		
	double real;
	double imaginary;	
};



Complex::Complex()
			:real(0), imaginary(0)
			{}
			
Complex::Complex(double rValue)
			:real(rValue), imaginary(0)
			{}
			
Complex::Complex(double rValue, double iValue)
			:real(rValue), imaginary(iValue)
			{}
			

			
double Complex::getRvalue() const
{
	return real;
}

double Complex::getIvalue() const
{
	return imaginary;
}

istream& operator >>(istream& inputStream, Complex& comp3)
{
	char isign ;
	
	inputStream>>comp3.real>>comp3.imaginary>>isign;
	
while(isign != 'i')
{
	cout<<"invalid complex number reenter please \n";
	inputStream>>comp3.real>>comp3.imaginary>>isign;
	
}
	return inputStream;
}

ostream& operator <<(ostream& outputStream, const Complex& comp3)
{
	outputStream<<comp3.real;
	
	if(comp3.imaginary<0)
	{
		outputStream<<comp3.imaginary<<"i \n";
	}
	else 
	{
		outputStream<<"+"<<comp3.imaginary<<"i \n";
	}
	
	return outputStream;
	
}

const Complex operator +(const Complex& comp1, const Complex& comp2)
{
	double realR=comp1.real + comp2.real;
	double imagR= comp1.imaginary+comp2.imaginary;
	
	return Complex(realR,imagR);
}

const Complex operator-(const Complex& comp1, const Complex& comp2)
{
	double realR=comp1.real - comp2.real;
	double imagR=comp1.imaginary - comp2.imaginary;
	
	return Complex(realR, imagR);
}

const Complex operator *(const Complex& comp1, const Complex& comp2)
{
	double realR=(comp1.real*comp2.real-comp1.imaginary*comp2.imaginary);
	double imagR=(comp1.real*comp2.imaginary+comp1.imaginary*comp2.real);
	
	return Complex(realR, imagR);
}

const Complex operator /(const Complex& comp1 , const Complex& comp2)
{
	double realR=(comp1.real*comp2.real+comp1.imaginary*comp2.imaginary)/(pow(comp2.real,2)+pow(comp2.imaginary,2));
	double imagR=(comp1.imaginary*comp2.real-comp1.real*comp2.imaginary)/(pow(comp2.real,2)+pow(comp2.imaginary,2));
	
	return Complex(realR, imagR);
}

bool operator ==(const Complex& comp1 , const Complex& comp2)
{
	return ((comp1.real==comp2.real ) && (comp1.imaginary==comp2.imaginary));
}

void arithmeticOp()
{
	Complex n1,n2,n3;
	char operat;
	
	cout<<"enter a complex number a+bi \n";
	cin>>n1;
	
	cout<<"enter operator sign please \n";
	cin>>operat;
	
	cout<<"enter another complex number please \n";
	cin>>n2;
	
	switch(operat)
	{
		case '+':
		n3=n1+n2;
		cout<<"\n"<<n1<<"+"<<n2<<" = "<<n3<<endl;
		break;
		
		case '-':
		n3=n1-n2;
		cout<<"\n"<<n1<<"-"<<n2<<" = "<<n3<<endl;
		break;
		
		case '*':
		n3=n1*n2;
		cout<<"\n"<<n1<<"*"<<n2<<" = "<<n3<<endl;
		break;
		
		case '/':
		n3=n1/n2;
		cout<<"\n"<<n1<<"/"<<n2<<" = "<<n3<<endl;
		break;
		
		default:
		cout<<"invalid operator sign \n";
		break;
	}
	
	
	
	
}

void quadraticCheck()
{
	Complex n, s1, s2;
	double a,b,c,delta;
	
	cout<<"enter the coefficients of a quadratic equation: ";
	cin>>a>>b>>c;
	cout<<"enter a complex number a+bi \n";
	cin>>n;
	
	delta= pow(b,2)-4*a*c;
	
	if (delta>0)
	{
		s1=Complex(-b+sqrt(delta)/2*a);
		s2=Complex(-b-sqrt(delta)/2*a);
		
	}
	
	else if (delta==0)
	{
		s1=Complex(-b/2*a);
		s2=Complex(-b/2*a);
	}
	
	else
	{
		s1=Complex(-b/2*a , -sqrt(-delta)/2*a);
		s2=Complex(-b/2*a ,sqrt(-delta)/2*a );
	}
	
	if(n==s1 || n==s2)
	{
		cout<<"The complex number: "<< n<<" is a solution of the quadratic equation \n";
	}
	
	else
	{
		cout<<"The complex number: "<<n<<" is not a solution of the quadratic eqaution \n";
	}
	
}

int main()
{
	int choice;
	
do{
	
	cout<<"Select an option - ";
	cout<<"(1) perform complex number arithmetic \n";
	cout<<"(2) check for quadratic equation solution \n";
	cout<<"(3) exit \n";
	
	cin>>choice;
	
	
	switch(choice)
	{
		case 1:
		arithmeticOp();
		cout<<endl;
		break;
		
		case 2:
		quadraticCheck();
		cout<<endl;
		break;
		
		case 3:
		exit(1);
		break;
		
		default:
		cout<<"invalid operation \n";
		break;
		
	}
}while(choice != 3);

}



