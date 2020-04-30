#include <iostream>
#include <cmath>

using namespace std;


int main()
{
   /*
   double a;
   double b;
   double c;
   double d;

   cin >> a;
   cin >> b;
   cin >> c;
   cin >> d;

   double x = (a + b + c)/(2*a*c);
   cout <<"Formula 1: "<< x << endl;
   x = (pow(a,2))/b + (c/d)*(a+b);
   cout <<"Formula 2: "<< x << endl;
   double y = (pow(a,(2 + b + c)) + a - c + 4);
   cout <<"Formula 3: "<< y << endl;

   //Enter Four numbers: 1 2 3 4
   //Formula 1: 1
   //Formula 2: 2.75
   //Formula 3: 3
    //cout << x << endl;
   //*/

   /*
   int hours;
   int minutes;

   cin >> hours; cin >> minutes;


   float time = hours+(minutes/60.);

   float Ftemperature = (4*pow(time, 2))/(time + 2) - 20;

   cout << "Temperature: "<< Ftemperature << endl;

   //Example:
   //Enter Hours: 4
   //Enter Minutes: 30
   //Approximate Temperature: -7.5 degrees F

   //Note: You will need to covert hours and minutes into fractions. For the above example it is 4.5 hours.
   //*/
    /*
    double number;
    cin >> number;

    if (number < 5.0){
        cout << "Little Damage" << endl;
    }else if ((5.0 <= number) and (number < 5.5)){
        cout << "Some Damage" << endl;
    }else if ((5.5 <= number) and (number < 6.5)){
        cout << "Serious Damage" << endl;
    }else if ((6.5 <= number) and (number < 7.5)){
        cout << "Disastrous Damage" << endl;
    }else{
        cout << "Catastrophic Damage" << endl;
    }

    //Richter Scale Number                                   Characterization  Message
    //r < 5.0                                                      Little Damage
    //5.0 < r < 5.5                                                Some Damage
    //5.5 < r < 6.5                                                Serious Damage
    //6.5 < r < 7.5                                                Disastrous Damage
    //higher than 7.5                                              Catastrophic Damage
    //Each message should end in a newline

    //Sample Output:
    //Enter Richter Scale Number:
    //5
    //Little Damage
    //*/
    double x;
    double y;
    cin >> x;
    cin >> y;

    if ((x == 0) and (y == 0)){
        cout << "Center Point" << endl;
    }else if (x == 0){
        cout << "On Y-Axis" << endl;
    }else if (y == 0){
        cout << "On X-Axis" << endl;
    }else if (y > 0){
        if (x > 0){
            cout << "Pair is quadrant Q1" << endl;
        }else{
            cout << "Pair is quadrant Q2" << endl;
        }

    }else if (y < 0){
        if (x > 0){
            cout << "Pair is quadrant Q4" << endl;
        }else{
            cout << "Pair is quadrant Q3" << endl;
        }

    }


    return 0;
}
