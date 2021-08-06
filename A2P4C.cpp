//BABACAR DIOUF
// AZIZA NAZMUTDINOVA
//ELYAAS HASSEN

//problem 5


#include <iostream>
#include <cmath>
 using namespace std;

 struct Point
 {
     double x;
     double y;

 };


 double dist(Point A1, Point B1)
 {

     return sqrt(pow(B1.x - A1.x,2) + pow(B1.y-A1.y,2));
 }


 double slope(Point A2, Point B2 ,bool& result)

 {
     double numerator,denominator,s;
     numerator=B2.y-A2.y;
     denominator=B2.x-A2.x;

     if(denominator==0)
     {
         result=false;
         return 0;
     }
     else
     {
         s=numerator/denominator;
         result=true;
         return(s);
     }


 }
Point midpoint(Point A3,Point B3)
 {
     Point mpoint;
     mpoint.x=(A3.x+B3.x)/2;
     mpoint.y=(A3.y+B3.y)/2;
     return mpoint;
 }


 void equation(Point& A4,Point& B4)
 {
     double yo;
     bool r1;
     yo=A4.y-slope(A4,B4,r1)*A4.x;
     if(yo>0)
     {
   cout<<"Equation: y= " <<slope(A4,B4,r1)<<"x"<<"+"<<yo<<endl;
 }
 else if(y0<0){

   cout <<"Equation: y= "<<slope(A4,B4,r1)<<"x"<<yo<<endl;
 }
 else
 {
 	cout<<"Equation: y= " <<slope(A4,B4,r1)<<"x"<<endl;
 }
 }

 bool collinear(Point A5,Point B5,Point c5)
 {
     double s1,s2;
     bool r2;
     s1=slope(A5,B5,r2);
     s2=slope(A5,c5,r2);

if(fabs(s1-s2)<0.000001)
{
    return true;
}
else{
    return false;
}

 }

void readPt(Point& A6)
{
    char jk;
    cin>>jk>>A6.x>>jk>>A6.y>>jk;
}

void showPt(Point A6)
{
    char jk;
    cout<<"("<<A6.x<<","<<A6.y<<")";
}


 int main()
 {
     Point a,b,c;
     bool r;
     int choice;
     char answ,pansw;

     cout<<"POINTLAND \n";

    

    cout<<"what do you want to do \n";
    cout<<"1-Find a distance between two points \n";
    cout<<"2-Find slope \n";
    cout<<"3-Find a midpoint \n";
    cout<<"4-Find an equation of the line \n";
    cout<<"5-Determine if three points are collinear \n";
    cout<<"6 or else -Exit \n";

    cin>>choice;
    while(choice>=1 && choice <=5)
{

    switch (choice)
    {
    case 1:
    cout<<"enter point 1 : \n";
    readPt(a);
    cout<<"enter point 2 : \n";
    readPt(b);
    cout<<"distance = "<<dist(a,b)<<endl;
    break;

    case 2:
    cout<<"enter point 1 : \n";
    readPt(a);
    cout<<"enter point 2 : \n";
    readPt(b);
    cout<<"slope = "<<slope(a,b,r)<<endl;
    break;

    case 3:
    cout<<"enter point 1 : \n";
    readPt(a);
    cout<<"enter point 2 : \n";
    readPt(b);
    cout<<"Midpoint = \n";
    showPt(midpoint(a,b));
    cout<<endl;
    break;

    case 4:
    cout<<"enter point 1 : \n";
    readPt(a);
    cout<<"enter point 2 : \n";
    readPt(b);
    equation(a,b);
    break;

    case 5:
    cout<<"enter point 1 : \n";
    readPt(a);
    cout<<"enter point 2 : \n";
    readPt(b);
    cout<<"enter point 3 : \n";
    readPt(c);
    if(collinear(a,b,c))
    {
        cout<<"Points collinear \n";
    }
    else
    {
        cout<<"Points are not collinear \n";
    }
    break;

    default:
    return 0;
    break;
    };



cout<<"what do you want to do \n";
    cout<<"1-Find a distance between two points \n";
    cout<<"2-Find slope \n";
    cout<<"3-Find a midpoint \n";
    cout<<"4-Find an equation of the line \n";
    cout<<"5-Determine if three points are collinear \n";
    cout<<"6 or else -Exit \n";

    cin>>choice;


}




 }



