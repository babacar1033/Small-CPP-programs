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
     cout<<slope(A4,B4,r1)<<"*x"<<"+"<<yo<<endl;
 }
 else if(y0<0){
 
    cout<<slope(A4,B4,r1)<<"*x"<<yo<<endl;
 }
 else
 {
 	cout<<slope(A4,B4,r1)<<"x"<<endl;
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



 int main()
 {
     Point a,b;
     bool r;
     cout<<"first point \n";
     cin>>a.x>>a.y;
     cout<<"second point \n";
     cin>>b.x>>b.y;

     equation(a,b);

 }

