#include <iostream>
#include <cmath>

using namespace std;

const double Q = pow(10,-9);
const double k = 9*pow(10,9);

double Efield(double r, double a = 1){

    if (r >= a){
        return((k*Q)/pow(r,2));
    }else{
        return(k*Q*(r/pow(a,3)));

    }


}




int main() {
    double r;
    double a;
    cout << "Enter r: " << endl;
    cin >> r;
    cout << "Enter a: " << endl;
    cin >> a;


   cout << "Efield: " << Efield(r,a) << endl;

   return 0;
}
