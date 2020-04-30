#include <iostream>
#include <cmath>

using namespace std;

const double TOLERANCE = .001;

double f(double x){ // the function, forced
    return(pow(x,4)+2*pow(x,3)-31*pow(x,2)-32*x+60);
}

double fprime(double x){ //f's dirivitive, forced
    return(4*pow(x,3)+6*pow(x,2)-62*x-32);
}

double newtonRoot(double guess){ // root finder

    double wub = guess;
    while(TOLERANCE < fabs(f(wub))){
        wub = wub - (f(wub)/fprime(wub));
    }
    //}
    return(wub); // where x == 0
}



int main() {
   int guess;
   char ret;
   bool retry = true;
   while (retry){
       cin >> guess;
        cout <<"Root: " << newtonRoot(guess) << endl;
        cout << "Enter Another Guess: y/n?" << endl;
        cin >> ret;
        if (!((ret == 'y') or (ret == 'Y'))){retry = false;}

   }

   return 0;
}
