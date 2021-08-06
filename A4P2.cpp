#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

class Pairs
{
public:
    Pairs();
    Pairs(double aVal, double bVal);
    const Pairs operator +(const Pairs& n2) const;
    const Pairs operator -(const Pairs& n2) const;
    bool operator ==(const Pairs& n2) const;
    void operator =(const Pairs& n1);
protected:
	double a, b;
};

class Complex : public Pairs
{
public:
    using Pairs::operator =;
    Complex();
    Complex(double aVal, double bVal);
    const Complex operator *(const Complex& n2) const;
    const Complex operator /(const Complex& n2) const;
    friend ostream& operator <<(ostream& outputStream, const Complex& n1);
    friend istream& operator >>(istream& inputStream, Complex& n1);
};

class Vect : public Pairs
{
public:
    using Pairs::operator =;
    Vect();
    Vect(double aVal, double bVal);
    double operator *(const Vect& n2) const;
    const Vect operator *(double scalar) const;
    friend ostream& operator <<(ostream& outputStream, const Vect& n1);
    friend istream& operator >>(istream& inputStream, Vect& n1);
};

void cActions();
void vActions();
int arrLetter(char letter);


Pairs::Pairs() : a(0), b(0){}

Pairs::Pairs(double aVal, double bVal) : a(aVal), b(bVal){ }

const Pairs Pairs::operator +(const Pairs& n2) const {
    double aFinal = a + n2.a;
    double bFinal = b + n2.b;

    return Pairs(aFinal, bFinal);
}

const Pairs Pairs::operator -(const Pairs& n2) const{
    double aFinal = a - n2.a;
    double bFinal = b - n2.b;

    return Pairs(aFinal, bFinal);
}

bool Pairs::operator ==(const Pairs& n2) const
{
    return ((a == n2.a) && (b == n2.b));
}

void Pairs::operator =(const Pairs& n1) 
{
    a = n1.a;
    b = n1.b;
}

Complex::Complex() : Pairs(){}

Complex::Complex(double aVal, double bVal) : Pairs(aVal,bVal){ }

istream& operator >>(istream& inputStream, Complex& n1)
{
	char op, i;
    cout << "Enter a complex number a+bi: ";
    inputStream >> n1.a >> op >> n1.b >> i;

    while ( (op != '+' && op != '-') || (i != 'i')){
        cout << "Invalid number. Enter a complex number a+bi: ";
        inputStream >> n1.a >> op >> n1.b >> i;
    }

    if (op == '-')
        n1.b = -n1.b;

    return inputStream;
}

ostream& operator <<(ostream& outputStream, const Complex& n1)
{
	outputStream << n1.a;
	if (n1.b < 0)
		outputStream << n1.b << "i";
	else
		outputStream << "+" << n1.b << "i";

	return outputStream;
}

const Complex Complex::operator *(const Complex& n2) const{
    double aFinal = (a*n2.a - b*n2.b);
    double bFinal = (a*n2.b + b*n2.a);

    return Complex(aFinal, bFinal);
}

const Complex Complex::operator /(const Complex& n2) const {
    double aFinal = (a*n2.a + b*n2.b)/(pow(n2.a,2)+pow(n2.b,2));
    double bFinal = (b*n2.a - a*n2.b)/(pow(n2.a,2)+pow(n2.b,2));

    return Complex(aFinal, bFinal);
}

Vect::Vect() : Pairs(){}

Vect::Vect(double aVal, double bVal) : Pairs(aVal,bVal){ }

istream& operator >>(istream& inputStream, Vect& n1)
{
    char junk;
	cout << "Enter a vector in <a,b> form: ";
	inputStream >> junk >> n1.a >> junk >> n1.b >> junk;

	return inputStream;
}

ostream& operator <<(ostream& outputStream, const Vect& n1)
{
	outputStream << "<" << n1.a << "," << n1.b << ">";

	return outputStream;
}

double Vect::operator *(const Vect& n2) const{
    return (a*n2.a + b*n2.b);
}

const Vect Vect::operator *(double scalar) const{
    double aFinal = (scalar*a);
    double bFinal = (scalar*b);

    return Vect(aFinal, bFinal);
}

void vActions()
{
    Vect v[26], v0;
    int sel;
    char opr, l1, l2, l3;
    double scalar = 0.0;

    do{
        cout << "Select an option:\n";
        cout << "    (1) Enter a vector\n";
        cout << "    (2) Display a vector\n";
        cout << "    (3) Display a scalar\n";
        cout << "    (4) Perform arithmetic or equality check\n";
        cout << "    (5) Exit\n";
        cin >> sel;
        if (sel == 1) {
            cin >> v0;
            cout << "Where do you want to store this (enter A-Z): ";
            cin >> l1;
            v[arrLetter(l1)] = v0;
        }
        else if(sel == 2){
            cout << "Which one do you want to display (enter A-Z): ";
            cin >> l1;
            cout << v[arrLetter(l1)] << endl;
        }
        else if(sel == 3){
            cout << "Scalar = " << scalar << endl;
        }
        else if(sel == 4){
            cout << "Enter an operation: (+, -, .(dot prod), *(scalar prod)"
                 << ", =): ";
            cin >> opr;

            switch (opr){
                case '+':
                    cout << "Enter first number (enter A-Z): ";
                    cin >> l1;
                    cout << "Enter second number (enter A-Z): ";
                    cin >> l2;
                    cout << "Enter result location (enter A-Z): ";
                    cin >> l3;
                    v[arrLetter(l3)] = v[arrLetter(l1)] + v[arrLetter(l2)];
                    break;
                case '-':
                    cout << "Enter first number (enter A-Z): ";
                    cin >> l1;
                    cout << "Enter second number (enter A-Z): ";
                    cin >> l2;
                    cout << "Enter result location (enter A-Z): ";
                    cin >> l3;
                    v[arrLetter(l3)] = v[arrLetter(l1)] - v[arrLetter(l2)];
                    break;
                case '.':
                    cout << "Enter first number (enter A-Z): ";
                    cin >> l1;
                    cout << "Enter second number (enter A-Z): ";
                    cin >> l2;
                    cout << "Enter result location (enter A-Z): ";
                    cin >> l3;
                    scalar = v[arrLetter(l1)] * v[arrLetter(l2)];
                    break;
                case '*':
                    cout << "Enter number (enter A-Z): ";
                    cin >> l1;
                    cout << "Enter scalar: ";
                    cin >> scalar;
                    cout << "Enter result location (enter A-Z): ";
                    cin >> l3;
                    v[arrLetter(l3)] = v[arrLetter(l1)]*scalar ;
                    break;
                case '=':
                    cout << "Enter first number (enter A-Z): ";
                    cin >> l1;
                    cout << "Enter second number (enter A-Z): ";
                    cin >> l2;
                    if (v[arrLetter(l1)] == v[arrLetter(l2)]){
                        cout << v[arrLetter(l1)] << " equals "
                             << v[arrLetter(l2)] << endl;
                    }
                    else
                        cout << v[arrLetter(l1)] << " differs "
                             << v[arrLetter(l2)] << endl;
                    break;
            }
        }
        else if(sel == 5){
            cout << "Bye..\n";
        }
        else
            cout << "Invalid input - try again\n";

    }while (sel != 5);
}

int arrLetter(char letter) {
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i< 26; i++){
        if (abc.at(i) == letter){
            return i;
            break;
        }
    }
}



int main()
{
   int choice;
   do {
      cout << "Select an option - (1) perform complex number actions\n";
      cout << "                   (2) perform vector actions\n";
      cout << "                   (3) exit\n";
      cin >> choice;
      if(choice == 1)
         cActions();
      else if(choice== 2)
         vActions();
      else if (choice == 3)
         cout << "Bye...\n";
      else
         cout << "Invalid input - try again\n";
   } while (choice != 3);
   
}


void cActions(){
    Complex c[26], c0;
    int sel;
    char opr, l1, l2, l3;

    do{
        cout << "Select an option:\n";
        cout << "    (1) Enter a complex number\n";
        cout << "    (2) Display a complex number\n";
        cout << "    (3) Perform arithmetic or equality check\n";
        cout << "    (4) Exit\n";
        cin >> sel;
        if (sel == 1) {
            cin >> c0;
            cout << "Where do you want to store this (enter A-Z): ";
            cin >> l1;
            c[arrLetter(l1)] = c0;
        }
        else if(sel == 2){
            cout << "Which one do you want to display (enter A-Z): ";
            cin >> l1;
            cout << c[arrLetter(l1)] << endl;
        }
        else if(sel == 3){
            cout << "Enter an operation: (+, -, *, /, =): ";
            cin >> opr;
            cout << "Enter first number (enter A-Z): ";
            cin >> l1;
            cout << "Enter second number (enter A-Z): ";
            cin >> l2;
            switch (opr){
                case '+':
                    cout << "Enter result location (enter A-Z): ";
                    cin >> l3;
                    c[arrLetter(l3)] = c[arrLetter(l1)] + c[arrLetter(l2)];
                    break;
                case '-':
                    cout << "Enter result location (enter A-Z): ";
                    cin >> l3;
                    c[arrLetter(l3)] = c[arrLetter(l1)] - c[arrLetter(l2)];
                    break;
                case '*':
                    cout << "Enter result location (enter A-Z): ";
                    cin >> l3;
                    c[arrLetter(l3)] = c[arrLetter(l1)] * c[arrLetter(l2)];
                    break;
                case '/':
                    cout << "Enter result location (enter A-Z): ";
                    cin >> l3;
                    c[arrLetter(l3)] = c[arrLetter(l1)] / c[arrLetter(l2)];
                    break;
                case '=':
                    if (c[arrLetter(l1)] == c[arrLetter(l2)]){
                        cout << c[arrLetter(l1)] << " does equal "
                             << c[arrLetter(l2)] << endl;
                    }
                    else
                        cout << c[arrLetter(l1)] << " does not equal "
                             << c[arrLetter(l2)] << endl;
                    break;
            }
        }
        else if(sel == 4){
            cout << "Bye..:\n";
        }
        else
            cout << "Invalid input would you try again\n";

    }while (sel != 4);
}










