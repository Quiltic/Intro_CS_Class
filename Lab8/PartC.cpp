#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <math.h>
#include <limits>

using namespace std;

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
    private:
        int x,y;
};




class Line {
    // implement cout for Line classes objects
    friend ostream & operator<<( ostream &output, const Line &L ){
        output << "Point 1: " << L.P1 << endl << "Point 2: " << L.P2;
        return output;
    }

    // implement cin for Line classes objects
    friend istream & operator>>( istream &input, Line &L ){
        input >> L.P1 >> L.P2;
        return input;
    }

    public:

        Line(){
            Point P1;
            Point P2;
        }

        Line(int x1, int y1, int x2, int y2){
            Point P1(x1, y1);
            Point P2(x2, y2);
        }

        void changepoint1(int x, int y){
            P1.setx(x);
            P1.sety(y);
        }

        void changepoint2(int x, int y){
            P2.setx(x);
            P2.sety(y);
        }

        void display(Line Lineline){
            //just to show stats
            cout << "Line info: " << endl;
            cout << "Slope: " << getslope() << endl;
            cout << "Y-intercept: " << getyintercept() << endl;
            cout << "Is vertical or horizontal: " << ISvORh() << endl;
            cout << "Parallel To other line? : " << Parra(Lineline) << endl << endl;
        }

    private:
        float getslope(){
            if ((P2.getx() - P1.getx()) != 0) // to get inf
                return ((P2.gety() - P1.gety() )/ (P2.getx() - P1.getx()));
            return std::numeric_limits<double>::infinity();// inf
        }


        float getyintercept(){
            //failsafe if it is a strate line with no intersept
            if (ISvORh() != "Vertical")
                return(P1.gety()+getslope()*P1.getx());
            //so it can return something incase of failsafe
            return (0);

        }

        string ISvORh(){
            // vertical lines are inf so 1/inf = 0
            if ((1/getslope()) == 0){
                return("Vertical");
            }else if (getslope() == 0) {
                // if its slope is normal 0 than it is horizontal
                return("Horizontal");
            }else{
                //if there neather
                return("Nither");
            }
        }


        bool Parra(Line LINE){

            // if the lines are parra then there slopes will be the same
            if (getslope() == LINE.getslope()){
                // to see if they arnt the same line
                if (getyintercept() != LINE.getyintercept()){
                    return true;
                }
            }
            return(false);
        }


        Point P1, P2;
};

int main(){
    Line L1;
    Line L2(5,6,7,8);
    cout << "L1: should have all zeros for values" << endl;
    cout << L1 << endl;
    // so it has new numebers for testing
    L1.changepoint1(9,9);
    L1.changepoint2(3,3);

    cout << "Enter Two Points For Line (IE 1 2 3 4   for 1,2 & 3,4): ";
    cin >> L2;
    cout << L2 << endl;

    L1.display(L2);
    L2.display(L1);
    return 0;
}
