#include <iostream>
using namespace std;

template<class T>
class List {
    public:
        List();
        List(const List<T>& listObject);
        void getElem();
        void disp();
        void sortElem();
    private:
        T e[5];
};

class Distance                           
{
   private:
      int feet;
      float inches;
   public:
      Distance() : feet(0), inches(0.0)  
      {  }
                                         
      Distance(int ft, float in) : feet(ft), inches(in)
      {  }
      Distance( float fltfeet )          
      {                                  
         feet = int(fltfeet);            
         inches = 12*(fltfeet-feet);     
      }
      bool operator < (Distance) const;  
      friend istream& operator >> (istream& s, Distance& d);
      friend ostream& operator << (ostream& s, Distance& d);
};

template<class T>
void demo(T flag);


template<class T>
 List<T>::List(){
     for (int i = 0; i < 5; i++)
        e[i] = 0;
 }

 template<class T>
 List<T>::List(const List<T>& listObject){
    for (int i = 0; i < 5; i++)
        e[i] = listObject.e[i];
 }

 template<class T>
 void List<T>::getElem(){
     for (int i = 0; i < 5; i++){
        cout << "Enter element " << i+1 << " : ";
        cin >> e[i];
     }
 }

 template<class T>
 void List<T>::disp(){
    for (int i = 0; i < 5; i++){
        cout << e[i] << "\t";
    }
    cout << endl;
 }

 template<class T>
 void List<T>::sortElem(){
     T temp;
     for (int i = 0; i < 4; i++){
        for (int j = i+1; j < 5; j++){
            if (e[j] < e[i]){
                temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
     }
 }


template<class T>
void demo(T flag) {
    List<T> l1;
    cout << "New blank list created\nList values -> ";
    l1.disp();
    cout << "Enter values into the list\n";
    l1.getElem();
    cout << "List entered\n";
    l1.disp();
    cout << "Create a second list initialized to the first\n";
    List<T> l2;
    l2 = l1;
    cout << "List created -> ";
    l2.disp();
    cout << "Sort the first list\n";
    l1.sortElem();
    cout << "Sorted list -> ";
    l1.disp();
    cout << endl;

}



bool Distance::operator < (Distance d2) const
{
   float bf1 = feet + inches/12;
   float bf2 = d2.feet + d2.inches/12;
   return (bf1 < bf2) ? true : false;
}


istream& operator >> (istream& s, Distance& d)  
{                                               
   cout << "\nEnter feet: ";  s >> d.feet;      
   cout << "Enter inches: ";  s >> d.inches;    
   return s;                                    
}

ostream& operator << (ostream& s, Distance& d)  
{                                               
   s << d.feet << "\'-" << d.inches << '\"';    
   return s;                                    
}                                       

int main()
{
	int sel;
	bool end=false;
	int iFlag=0;
	float fFlag=0;
	char cFlag=0;
	Distance dFlag;
	cout << "TEMPLATE DEMO PROGRAM\n";
	do{
		cout << "Enter list type (1=int 2=float 3=char 4=Distance 5=exit): ";
		cin >> sel;
		switch (sel)
		{
		case 1:
			demo(iFlag);
			break;
		case 2:
			demo(fFlag);
			break;
		case 3:
			demo(cFlag);
			break;
		case 4:
			demo(dFlag);
			break;
		default:
			end=true;
			cout << "Bye...\n";
			break;
		}
	}while(!end);
	return 0;
}
 
         
