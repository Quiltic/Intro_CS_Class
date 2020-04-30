#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <cctype>
#include <limits>

using namespace std;

// Please complete this Point class.
// The cin/cout operators have been overloaded for you
class Point {

    // cout implementation for Point class
    friend ostream & operator<<( ostream &output, const Point &P ){
        output << "x: " << P.x << " y: " << P.y;
        return output;
    }

    // cin implementation for Point class
    friend istream & operator>>( istream &input, Point &P ){
        input >> P.x >> P.y;
        return input;
    }

    public:
        Point(){
            x = 0;
            y = 0;
        }

        Point(int in_x, int in_y){
            x = in_x;
            y = in_y;
        }

        // Add your functions here
        int getx(){
            return x;
        }
        int gety(){
            return y;
        }

        void setx(int intx){
            x = intx;
        }
        void sety(int inty){
            y = inty;
        }

        bool operator == (const Point& pp) const {
            if ((pp.x == x) && (pp.y == y))
                    return true;
            return false;
        }

    private:
        int x,y;
};

class Circle {

    //Overload << (cout) operator that lets the user display the Circle and its properties (1-5 specifications above)
    // implement cout for Line classes objects
    friend ostream & operator<<( ostream &output, const Circle &C ){
        output << "Is a circle? : " << C.eq << endl << "Radius: " << C.Rad << endl << "Diameter: " << C.Diam << endl << "Cercumfrance: "<< C.cer  << endl << "Area: " << C.a << endl;
        return output;
    }

    // Overload >> (cin) operator that lets the user provide inputs to construct a Circle.
    // implement cin for Line classes objects
    friend istream & operator>>( istream &input, Circle &T ){
        input >> T.P1 >> T.P2;
        return input;
    }

    public:

        Circle(){
            Rad = 0;
            Diam = 0;
        }

        Circle(int x1, int y1, int x2, int y2){
            changepoint1(x1,y1);
            changepoint2(x2,y2);

            //Calculates the radius using the line distance formula
            Rad = sqrt((P2.getx()-P1.getx())*(P2.getx()-P1.getx())+(P2.gety()-P1.gety())*(P2.gety()-P1.gety()));
            //Calculates the diameter.
            Diam = 2*Rad;
        }

        void changepoint1(int x, int y){
            P1.setx(x);
            P1.sety(y);
        }

        void changepoint2(int x, int y){
            P2.setx(x);
            P2.sety(y);
        }

        Point getpoint1(){
            return P1;
        }
        Point getpoint2(){
            return P2;
        }

        double getRad(){
            Rad = sqrt((P2.getx()-P1.getx())*(P2.getx()-P1.getx())+(P2.gety()-P1.gety())*(P2.gety()-P1.gety()));
            return (Rad);
        }
        double getDiam(){
            Diam = getRad()*2;
            return (Diam);
        }

        //Overload == operator that compares two Circle objects and returns either true or false. IT returns true if both circles are the same (same center and radius) and false otherwise. To compare them, both circles have to be valid (Use Step 1).
        bool operator == (const Circle& circ) {
            if  (circ.P1 == P1 && circ.P2 == P2)
                    return true;
            return false;
        }

        //Calculates the circumference of a circle.
        double circumference(){
            cer = 2*M_PI*Rad;
            return(cer);
        }

        //Calculates the area of a circle.
        double Area(){
            a = M_PI*Rad*Rad;
            return(a);

        }


        //Determine if the object is a circle.
        //Point test: If both points are the same, a circle cannot be formed.
        bool trueCircle(){
            if (P2 == P1){
                eq = false;
                return false;
            }
            eq = true;
            return(true);
        }

    private:
        Point P1, P2;
        double Rad, Diam;
        bool eq;
        double cer, a;
};
/*

*/
int main(){
    Circle C1;
    Circle C2(0,0,0,4);
    cout << "C1 should have all 0's as values" << endl;
    C1.Area();
    C1.circumference();
    C1.trueCircle();
    cout << C1 << endl;

    C2.Area();
    C2.circumference();
    C2.trueCircle();
    cout << "C2 should have 1,4,8,25.1327,50.2655 as values" << endl;
    cout << C2 << endl;

    cout << "Are they the same? : " << (C1 == C2) << endl;

    return 0;
}
