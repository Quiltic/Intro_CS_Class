#include <iostream>
#include <math.h>

using namespace std;


class Cylinder {
    public:
        Cylinder(){
            setrad(0);
            setheight(0);
        }

        Cylinder(double in_w, double in_l){
            setrad(in_w);
            setheight(in_l);
        }

        double getr(){
            return r;
        }

        double geth(){
            return h;
        }

        void setrad(double in_r){
            r = in_r;
        }

        void setheight(double in_h){
            h = in_h;
        }

        void display(){
            cout << "Cylinder Parameters: " << endl;
            cout << "Radius: " << getr() << endl;
            cout << "Height: " << geth() << endl;
            cout << "Surface Area: " << getSArea() << endl;
            cout << "Volume : " << getVol() << endl << endl;
        }

    private:
        double getVol(){
            //volume of a Cylinder
            return M_PI*r*r*h;
        }

        double getSArea(){
            //serface area of a Cylinder
            return (2*M_PI*r*(r+h));
        }

        double r;
        double h;

};

int main(){

    Cylinder cyl;
    cyl.display();

    Cylinder cyl2(2,7);
    cyl2.display();

    cyl2.setrad(3);
    cyl2.display();

    return 0;
}
