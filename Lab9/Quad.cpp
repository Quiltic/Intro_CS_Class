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

        bool operator == (const Point& pp) const{
            if (pp.x == x)
                if (pp.y == y)
                    return true;
            return false;
        }

    private:
        int x,y;
};

class Quadrilateral {
    //Overload << (cout) operator that lets the user display the Quadrilateral and its properties (1-4 specifications above).
    // implement cout for Line classes objects
    friend ostream & operator<<( ostream &output, const Quadrilateral &Q ){
        output <<"True Quadrilateral? : " << Q.eq << endl << "Perimeter: " << Q.per  << endl << "Area: " << Q.a << endl;
        return output;
    }

    //Overload >> (cin) operator that lets the user provide inputs to construct a Quadrilateral.
    // implement cin for Line classes objects
    friend istream & operator>>( istream &input, Quadrilateral &Q ){
        input >> Q.P1 >> Q.P2 >> Q.P3 >> Q.P4;
        return input;
    }

    public:

        Quadrilateral(){
            line1 = 0;
            line2 = 0;
            line3 = 0;
            line4 = 0;
        }

        Quadrilateral(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4 ){
            changepoint1(x1,y1);
            changepoint2(x2,y2);
            changepoint3(x3,y3);
            changepoint4(x4,y4);
            line1 = sqrt((P2.getx()-P1.getx())*(P2.getx()-P1.getx())+(P2.gety()-P1.gety())*(P2.gety()-P1.gety()));
            line2 = sqrt((P2.getx()-P3.getx())*(P2.getx()-P3.getx())+(P2.gety()-P3.gety())*(P2.gety()-P3.gety()));
            line3 = sqrt((P4.getx()-P3.getx())*(P4.getx()-P3.getx())+(P4.gety()-P3.gety())*(P4.gety()-P3.gety()));
            line4 = sqrt((P4.getx()-P1.getx())*(P4.getx()-P1.getx())+(P4.gety()-P1.gety())*(P4.gety()-P1.gety()));
        }

        void changepoint1(int x, int y){
            P1.setx(x);
            P1.sety(y);
        }

        void changepoint2(int x, int y){
            P2.setx(x);
            P2.sety(y);
        }

        void changepoint3(int x, int y){
            P3.setx(x);
            P3.sety(y);
        }
        void changepoint4(int x, int y){
            P4.setx(x);
            P4.sety(y);
        }

        Point getpoint1(){
            return P1;
        }
        Point getpoint2(){
            return P2;
        }
        Point getpoint3(){
            return P3;
        }
        Point getpoint4(){
            return P3;
        }

        //Overload == operator that compares two Quadrilateral objects and returns either true or false. IT returns true if both Quadrilaterals are the same (same points) and false otherwise.
        bool operator == (const Quadrilateral& tritri){
            if  (tritri.P1 == P1)
                if  (tritri.P2 == P2)
                    if  (tritri.P3 == P3)
                        if  (tritri.P4 == P4)
                            return true;
            return false;
        }

        //Calculates the perimeter of the Quadrilateral.
        double perimeter(){
            per = line1+line2+line3+line4;
            return(per);
        }

        //Calculates the area of a Quadrilateral.
        double Area(){
            a = .5*abs(P1.getx()*P2.gety()+P2.getx()*P3.gety()+P3.getx()*P4.gety()+P4.getx()*P1.gety()-P2.getx()*P1.gety()-P3.getx()*P2.gety()-P4.getx()*P3.gety()-P1.getx()*P4.gety());
            return(a);

        }


        //Determines if the object is a Quadrilateral. Using the collinearity test.
        bool trueQuadrilateral(){
            eq = false;
            if (P1.getx()*(P2.gety()-P3.gety())+P2.getx()*(P3.gety()-P1.gety())+P3.getx()*(P1.gety()-P2.gety()) == 0)
                 cout << 1 << endl;
            else if (P2.getx()*(P3.gety()-P4.gety())+P3.getx()*(P4.gety()-P2.gety())+P4.getx()*(P2.gety()-P3.gety()) == 0)
                 cout << 2 << endl;
            else if (P1.getx()*(P3.gety()-P4.gety())+P3.getx()*(P4.gety()-P1.gety())+P4.getx()*(P3.gety()-P1.gety()) == 0)
                 cout << 3 << endl;//x1(y3-y4)+x3(y4-y1)+x4(y3-y1) = 0
            else if (P1.getx()*(P2.gety()-P4.gety())+P2.getx()*(P4.gety()-P1.gety())+P4.getx()*(P1.gety()-P2.gety()) == 0)
                 cout << 4 << endl;
            eq = true;
            return(true);
        }

    private:
        Point P1, P2, P3, P4;
        double line1, line2, line3, line4;
        bool eq;
        double per, a;
};
/*

*/
int main(){
    Quadrilateral Q1;
    Quadrilateral Q2(-3,-3,-3,3,3,3,3,-3);
    Quadrilateral Q3(-3,-3,-3,3,3,3,3,-3);
    cout << "Point P1 should have 0,0 as values" << endl;
    Q1.Area();
    Q1.perimeter();
    Q1.trueQuadrilateral();
    cout << Q1 << endl;

    Q2.Area();
    Q2.perimeter();
    Q2.trueQuadrilateral();
    cout << "Point P2 should have 7,6 as values" << endl;
    cout << Q2 << endl;

    cout << "Are they the same? : " << (Q1 == Q2) << endl;
    cout << "Are they the same? : " << (Q3 == Q2) << endl;

    return 0;
}
