#include <iostream>
using namespace std;

typedef int* pointer;

class DynArray{
	
	public:
	
	DynArray();
	DynArray(int nInt);
	void show(int nInt);
	void set(int nInt, int x);
	void expand(int x);
	~DynArray();
	
	
	
	private:
		
	pointer a;  // a= new int[size] <==> a[size]  <==> *(a)
	int n;	
};

DynArray::DynArray() : n(0)
{
	a= new int[n];
}

DynArray::DynArray(int nInt): n(nInt)
{
	a= new int[n];
}

void DynArray::show(int nInt)
{
	if(n==0)
	{
		cout<<"cannot show- DynArray empty \n";
	}
	
	else if(nInt<0 || nInt >n )
	{
		cout<<"invalid index in show \n";
	}
	
	else
	{
		cout<<*(a+nInt)<<endl;
	}
} 

void DynArray::set(int nInt, int x)
{
	if(n==0)
	{
		cout<<"cannot set- DynArray empty \n";
	}
	
	else if(nInt<0)
	{
		cout<<"invalid index in set \n";
	}
	
	else
	{
		*(a+nInt)=x;
	}
}

void DynArray::expand(int x)
{
	pointer Larray= new int[n+x];
	
	for(int i=0; i<n; i++)
	{
		*(Larray+i)=*(a+i);
	}
	
	delete [] a;
	a = Larray;
	n += x;
	
	
}

DynArray::~DynArray()
{
	cout<<"Hi from the DynArray destructor... \n";
	delete [] a;
}

void myFunc()
{
     int i;
     cout << "hi from myFunc...\n";
     DynArray y(5);
     for(i=0;i<5;i++)
        y.set(i,i*i);
     for(i=0;i<5;i++)
        y.show(i);
     cout << "bye from myFunc...\n";
}


int main()
{
	int size,more,i;
	
	DynArray y;
	
	cout << "Enter dynamic array size: ";
	
	cin >> size;
	
	DynArray x(size);
	
	for(i=0;i<size;i++)
	
		x.set(i,3*i);
	
	for(i=0;i<size;i++)
	
		x.show(i);
	
	cout << "How much more dynamic array space do you want? ";
	
	cin >> more;
	
	x.expand(more);
	
	for(i=0;i<(size+more);i++)
	
		x.set(i,5*i);
	
	for(i=0;i<(size+more);i++)
	
		x.show(i);
	
	x.show(size+more+5);	//invalid index in show
	
	x.set(-2,9);		//invalid index in set
	
	y.set(3,6);			//empty DynArray set
	
	y.show(3);			//empty DynArray show
	
	myFunc();
	
	char ch; 
	
	cin >> ch;
    
	return 0;
}

