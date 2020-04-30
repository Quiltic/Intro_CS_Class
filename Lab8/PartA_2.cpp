#include <iostream>
#include <math.h>

using namespace std;

class Sphere {
    public:
        Sphere(){
            setR(0);
        }

        Sphere(double in_r){
            setR(in_r);
        }

        double getR(){
            return r;
        }

        void setR(double in_r){
            r = in_r;
        }


        void display(){
            cout << "Sphere Parameters: " << endl;
            cout << "Radius: " << getR() << endl;
            cout << "Surface Area: " << getSArea() << endl;
            cout << "Volume : " << getVol() << endl << endl;
        }

    private:
        double getSArea(){
            //Serface area of a sphere
            return M_PI*4*r*r;
        }

        double getVol(){
            // volume of a sphere
            return r*r*r*M_PI*(4.0/3.0);
        }

        double r;

};


int main(){

    Sphere sph;
    sph.display();

    Sphere sph2(5);
    sph2.display();

    sph2.setR(3);
    sph2.display();

    return 0;
}
