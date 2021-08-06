#include <iostream>
#include <cmath>
using namespace std;

class Complex {

public:
    Complex(); // 
    Complex(double aVal, double bVal);
    void add(Complex n1, Complex n2);
    void sub(Complex n1, Complex n2);
    void mult(Complex n1, Complex n2);
    void div(Complex n1, Complex n2);
    void conv(double realN);
    bool equality(Complex n1, Complex n2);
    void input();
    void output();

private:
    double a, b;
};

void arithmetic();
void quadratic();

int main(){

    int choice;

    do {
        cout << "Select an option - (1) perform complex number arithmetic\n"
        "\t\t   (2) check for quadratic equation solution \n"
        "\t\t   (3) exit \n";
        cin >> choice;

        switch (choice){
            case 1:
                arithmetic();
                break;
            case 2:
                quadratic();
                break;
            case 3:
                exit(1);
                break;
            default:
                cout << "Invalid choice! please select again \n\n";
                break;

        }

    } while (choice != 3);


}

void arithmetic(){
    char operat;
    Complex n1, n2, n3;

    n1.input();
    cout << "Enter an operation: (+, -, *, /): ";
    cin >> operat;
    n2.input();

    switch (operat){
        case '+':
            n3.add(n1,n2);
            break;
        case '-':
            n3.sub(n1,n2);
            break;
        case '*':
            n3.mult(n1,n2);
            break;
        case '/':
            n3.div(n1,n2);
            break;
        default:
            cout << "Invalid operator!\n\n";
            break;

    }
    cout << "\n(";
    n1.output();
    cout << ") " << operat << " (";
    n2.output();
    cout << ") = ";
    n3.output();
    cout << endl << endl;

}
void quadratic(){

    Complex s1, s2, n;
    double delta, a, b, c;

    cout << "Enter the coefficients of a quadratic equation: ";
    cin >> a >> b >> c;

    while(a == 0){
        cout << "a can't be zero. Enter coefficient a: ";
        cin >> a;
    }
    delta = pow(b,2) - 4*a*c;

    if (delta >=0) {
        s1.conv( (-b+sqrt(delta)) / (2*a) );
        s2.conv( (-b-sqrt(delta)) / (2*a) );
    }
    else {
        s1 = Complex(-b/(2*a), sqrt(-delta)/(2*a));
        s2 = Complex(-b/(2*a), -sqrt(-delta)/(2*a));
    }

    n.input();
    cout << "The complex number: ";
    n.output();
    if (n.equality(n,s1) || n.equality(n,s2)){
        cout << " is a solution of the quadratic equation.\n\n";
    }
    else {
        cout << " is not a solution of the quadratic equation.\n\n";
    }
}

Complex::Complex() : a(0), b(0){}

Complex::Complex(double aVal, double bVal) : a(aVal), b(bVal)
{ }

void Complex::input(){
    char op, i;
    cout << "Enter a complex number a+bi: ";
    cin >> a >> op >> b >> i;

    if (op == '-')
        b = -b;
}

void Complex::output(){
    if (b < 0)
        cout << a << b << "i";
    else
        cout << a << "+" << b << "i";
}

void Complex::add(Complex n1, Complex n2) {
    a = n1.a + n2.a;
    b = n1.b + n2.b;
}
void Complex::sub(Complex n1, Complex n2){
    a = n1.a - n2.a;
    b = n1.b - n2.b;
}
void Complex::mult(Complex n1, Complex n2){
    a = (n1.a*n2.a - n1.b*n2.b);
    b = (n1.a*n2.b + n1.b*n2.a);
}
void Complex::div(Complex n1, Complex n2){
    a = (n1.a*n2.a + n1.b*n2.b)/(pow(n2.a,2)+pow(n2.b,2));
    b = (n1.b*n2.a - n1.a*n2.b)/(pow(n2.a,2)+pow(n2.b,2));
}

void Complex::conv(double realN){
    a = realN;
    b = 0;
}

bool Complex::equality(Complex n1, Complex n2){
    return (abs(n1.a - n2.a) < 0.000001 && abs(n1.b - n2.b) < 0.000001);
}
