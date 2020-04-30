#include <iostream>
#include <cmath>
using namespace std;

double tryangle_sin(char find, double findpart, double b, double B){
    if (find == 'A'){
        return(asin(((sin(B)*findpart)/b)));
    }else if (find == 'a'){
        return((sin(B)/(sin(findpart)*b)));
    }
    return(0);
}

double Angle_finder(double x, double y){
    double angle_array[4] = [0,0,0,0];




    return(angle_array)
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
