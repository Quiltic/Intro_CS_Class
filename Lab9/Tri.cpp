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

class Triangle {
    //Overload << (cout) operator that lets the user display the Triangle and its properties (1-4 specifications above).
    // implement cout for Line classes objects
    friend ostream & operator<<( ostream &output, const Triangle &T ){
        output << "True Triangle? : " << T.truetr << endl << "Perimeter: " << T.per  << endl << "Area: " << T.a << endl << "Equilateral triangle? : " << T.eq << endl;
        return output;
    }

    //Overload >> (cin) operator that lets the user provide inputs to construct a Triangle.
    // implement cin for Line classes objects
    friend istream & operator>>( istream &input, Triangle &T ){
        input >> T.P1 >> T.P2 >> T.P3;
        return input;
    }

    public:

        Triangle(){
            Point P1;
            Point P2;
            Point P3;
            line1 = 0;
            line2 = 0;
            line3 = 0;
        }

        Triangle(int x1, int y1, int x2, int y2, int x3, int y3 ){
            changepoint1(x1,y1);
            changepoint2(x2,y2);
            changepoint3(x3,y3);
            line1 = sqrt((P2.getx()-P1.getx())*(P2.getx()-P1.getx())+(P2.gety()-P1.gety())*(P2.gety()-P1.gety()));
            line2 = sqrt((P2.getx()-P3.getx())*(P2.getx()-P3.getx())+(P2.gety()-P3.gety())*(P2.gety()-P3.gety()));
            line3 = sqrt((P3.getx()-P1.getx())*(P3.getx()-P1.getx())+(P3.gety()-P1.gety())*(P3.gety()-P1.gety()));
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

        void display(){
            //just to show stats
            if (truetriangle()){
                cout << "Triangle info: " << endl;
                cout << "Perimeter: " << perimeter() << endl;
                cout << "Area: " << Area() << endl;
                cout << "Equilateral triangle? : " << Equilateral() << endl;
                //cout << "Parallel To other line? : " << (TriTri) << endl << endl;
            }
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

        //Overload == operator that compares two triangle objects and returns either true or false. IT returns true if both triangles are the same (same points) and false otherwise.
        bool operator == (const Triangle& tritri){
            if  (tritri.P1 == P1)
                if  (tritri.P2 == P2)
                    if  (tritri.P3 == P3)
                        return true;
            return false;
        }

        //Calculates the perimeter of the triangle.
        double perimeter(){
            per = line1+line2+line3;
            return(per);
        }

        //Calculates the area of a triangle.
        double Area(){
            double p = perimeter()/2;
            a = sqrt((p*(p-line1)*(p-line2)*(p-line3)));
            return(a);

        }


        //Determines if the triangle is a an equilateral triangle.
        bool Equilateral(){
            if ((line1 == line2) and (line2 == line3)){
                eq = true;
                return(true);
            }
            eq = false;
            return(false);

        }

        //Determines if the object is a triangle. Using the collinearity test.
        bool truetriangle(){
            if ((P2.gety()-P1.gety())/(P2.getx()-P1.getx()) == (P3.gety()-P2.gety())/(P3.getx()-P2.getx())){
                truetr = false;
                return(false);
            }
            else if ((P1.getx()*(P2.gety()-P3.gety())+P2.getx()*(P3.gety()-P1.gety())+P3.getx()*(P1.gety()-P2.gety())) == 0){
                truetr = false;
                return(false);
            }
            truetr = true;
            return(true);
        }

    private:
        Point P1, P2, P3;
        double line1, line2, line3;
        bool eq, truetr;
        double per, a;
};
/*

*/
int main(){
    Triangle T1;
    Triangle T2(3,3,4,4,5,5);
    cout << "Point P1 should have 0,0 as values" << endl;
    T1.Area();
    T1.Equilateral();
    cout << T1 << endl;

    T2.Area();
    T2.Equilateral();
    cout << "Point P2 should have 7,6 as values" << endl;
    cout << T2 << endl;

    cout << "Are they the same? : " << (T1 == T2) << endl;

    return 0;
}
