#include <iostream>
#include <cmath>

using namespace std;

const double pi = 3.14159265;



class Shape 
{
public:
    virtual void Display() = 0;
    virtual void GetDimensions() = 0;
    virtual double Area() = 0;
    virtual double Perimeter() = 0;
    virtual double Volume() = 0;
};

class Rectangle : public Shape 
{
public:
    Rectangle() : d1(0), d2(0){}
    Rectangle(double d1Val, double d2Val) : d1(d1Val), d2(d2Val){}
    void Display();
    void GetDimensions();
    double Area();
    double Perimeter();
    double Volume() {}
private:
    double d1, d2;
};

class Circle : public Shape 
{
public:
    Circle() : d1(0){}
    Circle(double d1Val) : d1(d1Val){}
    void Display();
    void GetDimensions();
    double Area();
    double Perimeter();
    double Volume() {};
private:
    double d1;
};

class Triangle : public Shape 
{
public:
    Triangle() : d1(0), d2(0), d3(0){}
    Triangle(double d1Val, double d2Val, double d3Val) : d1(d1Val), d2(d2Val),
    d3(d3Val){}
    void Display();
    void GetDimensions();
    double Area();
    double Perimeter();
    double Volume() {};
private:
    double d1, d2, d3;
};

class Box : public Shape {
public:
    Box() : d1(0), d2(0), d3(0){}
    Box(double d1Val, double d2Val, double d3Val) : d1(d1Val), d2(d2Val),
    d3(d3Val){}
    void Display();
    void GetDimensions();
    double Area();
    double Perimeter(){}
    double Volume();
private:
    double d1, d2, d3;
};

class Can : public Shape 
{
public:
    Can() : d1(0), d2(0){}
    Can(double d1Val, double d2Val) : d1(d1Val), d2(d2Val){}
    void Display();
    void GetDimensions();
    double Area();
    double Perimeter(){}
    double Volume();
private:
    double d1, d2;
};

class Cone : public Shape 
{
public:
    Cone() : d1(0), d2(0){}
    Cone(double d1Val, double d2Val) : d1(d1Val), d2(d2Val){}
    void Display();
    void GetDimensions();
    double Area();
    double Perimeter(){}
    double Volume();
private:
    double d1, d2;
};

class Ball : public Shape 
{
public:
    Ball() : d1(0){}
    Ball(double d1Val) : d1(d1Val){}
    void Display();
    void GetDimensions();
    double Area();
    double Perimeter(){}
    double Volume();
private:
    double d1;
};

void Rectangle::GetDimensions(){
    cout << "Input for Rectangle - enter length and width "
         << "(separated by space): ";
    cin >> d1 >> d2;
    cout << endl;
}

void Rectangle::Display(){
        cout << "Shape = Rectangle  Length = " << d1 << " Width = "
				<< d2 << endl;
        cout << "Area = " << Area() << endl;
        cout << "Perimeter = " << Perimeter() << endl;
}

double Rectangle::Area(){
    return (d1*d2);
}
double Rectangle::Perimeter(){
    return (2 * d1 + 2 * d2);
}


void Circle::GetDimensions(){
    cout << "Input for Circle - enter radius: ";
    cin >> d1;
    cout << endl;
}

void Circle::Display(){
        cout << "Shape = Circle  Radius = " << d1 << endl;
        cout << "Area = " << Area() << endl;
        cout << "Perimeter = " << Perimeter() << endl;
}

double Circle::Area(){
    return (pi*pow(d1,2));
}
double Circle::Perimeter(){
    return (2 * pi * d1);
}


void Triangle::GetDimensions(){
    cout << "Input for Triangle - enter sides 1, 2 and 3 "
         << "(separated by space): ";
    cin >> d1 >> d2 >> d3;
    cout << endl;
}

void Triangle::Display(){
        cout << "Shape = Triangle  Side lenghts = "
             << d1 << " " << d2 << " " << d3 << endl;
        cout << "Area = " << Area() << endl;
        cout << "Perimeter = " << Perimeter() << endl;
}

double Triangle::Area(){
    double p = Perimeter() / 2;
    return (sqrt(p*(p-d1)*(p-d2)*(p-d3)));
}
double Triangle::Perimeter(){
    return (d1 + d2 + d3);
}

void Box::GetDimensions(){
    cout << "Input for Box - enter length, width and height "
         << "(separated by space): ";
    cin >> d1 >> d2 >> d3;
    cout << endl;
}

void Box::Display()
{
        cout << "Shape = Box  Lenght = "
             << d1 << " Width = " << d2 << " Height = " << d3 << endl;
        cout << "Surface Area = " << Area() << endl;
        cout << "Volume = " << Volume() << endl;
}

double Box::Area()
{
    return (2*(d1*d2)+2*(d1*d3)+2*(d2*d3));
}
double Box::Volume(){
    return (d1 * d2 * d3);
}


void Can::GetDimensions(){
    cout << "Input for Can - enter radius and height "
         << "(separated by space): ";
    cin >> d1 >> d2;
    cout << endl;
}

void Can::Display(){
        cout << "Shape = Can  Radius = " << d1 << " Height = "
				<< d2 << endl;
        cout << "Surface Area = " << Area() << endl;
        cout << "Volume = " << Volume() << endl;
}

double Can::Area(){
    return (2*pi*pow(d1,2)+d2*2*pi*d1);
}
double Can::Volume(){
    return (pi * pow(d1,2) * d2);
}


void Cone::GetDimensions(){
    cout << "Input for Cone - enter radius and height "
         << "(separated by space): ";
    cin >> d1 >> d2;
    cout << endl;
}

void Cone::Display(){
        cout << "Shape = Cone  Radius = " << d1 << " Height = "
				<< d2 << endl;
        cout << "Surface Area = " << Area() << endl;
        cout << "Volume = " << Volume() << endl;
}

double Cone::Area(){
    return (pi*d1*(d1+sqrt(pow(d2,2)+pow(d1,2))));
}
double Cone::Volume(){
    return (pi * pow(d1,2) * (d2/3));
}


void Ball::GetDimensions(){
    cout << "Input for Ball - enter radius: ";
    cin >> d1;
    cout << endl;
}

void Ball::Display(){
        cout << "Shape = Ball  Radius = " << d1 << endl;
        cout << "Surface Area = " << Area() << endl;
        cout << "Volume = " << Volume() << endl;
}

double Ball::Area(){
    return (4*pi*pow(d1,2));
}
double Ball::Volume(){
    return (4*(pi/3)*pow(d1,3));
}



int main(){

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
	
	Shape *p[20];
    int c = 0, shapeT;
    char cont;

    do {
        cout << "Enter the number of the shape type:\n"
             << "\t1 - Rectangle\n"
             << "\t2 - Circle\n"
             << "\t3 - Triangle\n"
             << "\t4 - Box\n"h
             << "\t5 - Can\n"
             << "\t6 - Cone\n"
             << "\t7 - Ball\n => ";
        cin >> shapeT;
        switch(shapeT) {
            case 1: 
                p[c] = new Rectangle;
                p[c] -> GetDimensions();
                c++;
                break;
            case 2: 
                p[c] = new Circle;
                p[c] -> GetDimensions();
                c++;
                break;
            case 3: 
                p[c] = new Triangle;
                p[c] -> GetDimensions();
                c++;
                break;
            case 4: 
                p[c] = new Box;
                p[c] -> GetDimensions();
                c++;
                break;
            case 5: 
                p[c] = new Can;
                p[c] -> GetDimensions();
                c++;
                break;
            case 6: 
                p[c] = new Cone;
                p[c] -> GetDimensions();
                c++;
                break;
            case 7: 
                p[c] = new Ball;
                p[c] -> GetDimensions();
                c++;
                break;
            default:
                cout << "Invalid shape.\n";
                break;

        }
        cout << c << endl;
        cout << "Select another shape? (y or n): ";
        cin >> cont;

    }while (cont == 'y' && c < 20);
    cout << "\n Next, a display of your selected shapes, dimensions"
         << " and other data.\n\n";
    for (int i = 0; i < c ; i++){
        p[i] -> Display();
        cout << endl << i << endl;
    }

}



