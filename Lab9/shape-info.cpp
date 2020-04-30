#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <cctype>
#include <limits>
#include <fstream>
#include <sstream>

using namespace std;

vector<double> breakupstring(string str){
    vector<double> numdata;
    stringstream ss;     //requires sstream library included
    ss << str;

    while(!ss.eof()){
        double temp;
        ss >> temp;
        numdata.push_back(temp);
    }

    return numdata;
}

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

        Point(double in_x, double in_y){
            x = in_x;
            y = in_y;
        }

        // Add your functions here
        double getx(){
            return x;
        }
        double gety(){
            return y;
        }

        void setx(double intx){
            x = intx;
        }
        void sety(double inty){
            y = inty;
        }

        bool operator == (const Point& pp) const{
            if (pp.x == x)
                if (pp.y == y)
                    return true;
            return false;
        }

    private:
        double x,y;
};

class Quadrilateral {
    //Overload << (cout) operator that lets the user display the Quadrilateral and its properties (1-4 specifications above).
    // implement cout for Line classes objects
    friend ostream & operator<<( ostream &output, const Quadrilateral &Q ){
        output << "Perimeter: " << Q.per  << endl << "Area: " << Q.a << endl;
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

        Quadrilateral(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4 ){
            changepoint1(x1,y1);
            changepoint2(x2,y2);
            changepoint3(x3,y3);
            changepoint4(x4,y4);
            line1 = sqrt((P2.getx()-P1.getx())*(P2.getx()-P1.getx())+(P2.gety()-P1.gety())*(P2.gety()-P1.gety()));
            line2 = sqrt((P2.getx()-P3.getx())*(P2.getx()-P3.getx())+(P2.gety()-P3.gety())*(P2.gety()-P3.gety()));
            line3 = sqrt((P4.getx()-P3.getx())*(P4.getx()-P3.getx())+(P4.gety()-P3.gety())*(P4.gety()-P3.gety()));
            line4 = sqrt((P4.getx()-P1.getx())*(P4.getx()-P1.getx())+(P4.gety()-P1.gety())*(P4.gety()-P1.gety()));
        }

        void changepoint1(double x, double y){
            P1.setx(x);
            P1.sety(y);
        }

        void changepoint2(double x, double y){
            P2.setx(x);
            P2.sety(y);
        }

        void changepoint3(double x, double y){
            P3.setx(x);
            P3.sety(y);
        }
        void changepoint4(double x, double y){
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

class Triangle {
    //Overload << (cout) operator that lets the user display the Triangle and its properties (1-4 specifications above).
    // implement cout for Line classes objects
    friend ostream & operator<<( ostream &output, const Triangle &T ){
        output << "Perimeter: " << T.per  << endl << "Area: " << T.a << endl << "Equilateral triangle? : " << T.eq << endl;
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

        Triangle(double x1, double y1, double x2, double y2, double x3, double y3 ){
            changepoint1(x1,y1);
            changepoint2(x2,y2);
            changepoint3(x3,y3);
            line1 = sqrt((P2.getx()-P1.getx())*(P2.getx()-P1.getx())+(P2.gety()-P1.gety())*(P2.gety()-P1.gety()));
            line2 = sqrt((P2.getx()-P3.getx())*(P2.getx()-P3.getx())+(P2.gety()-P3.gety())*(P2.gety()-P3.gety()));
            line3 = sqrt((P3.getx()-P1.getx())*(P3.getx()-P1.getx())+(P3.gety()-P1.gety())*(P3.gety()-P1.gety()));
        }

        void changepoint1(double x, double y){
            P1.setx(x);
            P1.sety(y);
        }

        void changepoint2(double x, double y){
            P2.setx(x);
            P2.sety(y);
        }

        void changepoint3(double x, double y){
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

class Circle {

    //Overload << (cout) operator that lets the user display the Circle and its properties (1-5 specifications above)
    // implement cout for Line classes objects
    friend ostream & operator<<( ostream &output, const Circle &C ){
        output << "Radius: " << C.Rad << endl << "Diameter: " << C.Diam << endl << "Cercumfrance: "<< C.cer  << endl << "Area: " << C.a << endl;
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

        Circle(double x1, double y1, double x2, double y2){
            changepoint1(x1,y1);
            changepoint2(x2,y2);

            //Calculates the radius using the line distance formula
            Rad = sqrt((P2.getx()-P1.getx())*(P2.getx()-P1.getx())+(P2.gety()-P1.gety())*(P2.gety()-P1.gety()));
            //Calculates the diameter.
            Diam = 2*Rad;
        }

        void changepoint1(double x, double y){
            P1.setx(x);
            P1.sety(y);
        }

        void changepoint2(double x, double y){
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
    ifstream file_input("C:\\Temp\\shapes.txt");
    ofstream file_output("C:\\Temp\\shapes-info.txt");
    string input;
    vector<double> numbers;
    while(getline(file_input,input)){
        //string s1("2 45 1 2.5 9");
        numbers = {};
        numbers = breakupstring(input);
        cout << numbers.size();
        for (unsigned a = 0; (a < numbers.size()); ++a)
            cout << numbers.at(a) << ", ";
        cout << endl;

        if (numbers.size() == 4){
            file_output << "Sufficient coordinates input." << endl;
            Circle C1(numbers.at(0),numbers.at(1),numbers.at(2),numbers.at(3));
            if (C1.trueCircle() != 1)
                file_output << "Not a true Circle." << endl;
            else {
                C1.Area();
                C1.circumference();
                file_output << "This is a true Circle." << endl;
                file_output << C1 << endl;
            }

        }else if (numbers.size() == 6){
            file_output << "Sufficient coordinates input." << endl;
            Triangle T1(numbers.at(0),numbers.at(1),numbers.at(2),numbers.at(3),numbers.at(4),numbers.at(5));
            if (T1.truetriangle() != 1)
                file_output << "Not a true Triangle." << endl;
            else {
                T1.Area();
                T1.perimeter();
                file_output << "This is a true Triangle." << endl;
                file_output << T1 << endl;
            }

        }else if (numbers.size() == 8){
            file_output << "Sufficient coordinates input." << endl;
            Quadrilateral Q1(numbers.at(0),numbers.at(1),numbers.at(2),numbers.at(3),numbers.at(4),numbers.at(5),numbers.at(6),numbers.at(7));
            if (Q1.trueQuadrilateral() != 1)
                file_output << "Not a true Quadrilateral." << endl;
            else {
                Q1.Area();
                Q1.perimeter();
                file_output << "This is a true Quadrilateral." << endl;
                file_output << Q1 << endl;
            }

        }else {
            file_output << "Insufficient coordinate input." << endl << endl;
        }

    }
    file_input.close();
    file_output.close();

    return 0;
}
