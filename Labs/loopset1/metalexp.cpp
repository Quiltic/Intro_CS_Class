#include <iostream>
#include <iomanip>

using namespace std;
int input(string words){
    int val;
    cout << words << endl;
    cin >> val;
    return(val);
}
double input(){
    double val;
    cin >> val;
    return(val);
}

int main()
{
    /*
    int a = input();
    int max = input()+1;
    int steps = input();

    int total = 0;
    double amount = 0;
    for (a; a < max; a += steps){
        amount++;
        total += a;
    }

    cout << "SUM: "<< total << endl;
    cout << "AVERAGE: " << total/amount << endl;
    //*/
    /*
    double start = input();
    while (start >= 0){
        cout << start << ",";
        start -=.5;
    }
    //*/
    /*
    double total = 0;
    double ints = input();
    while (ints > 0){
        total += ints;
        ints = input();

    }
    cout << "Sum of Entered Numbers: " << total;
    //*/
    /*
    int x = input();
    int y = input();
    for (int b = 0; b < y; b += 1){
        for (int a = 0; a < x; a += 1){
            cout <<"*";
        }
    cout << endl;
    }
    //*/
    /*
    int x = input();
    int y = input();
    for (int b = 0; b < y; b += 1){
        for (int a = 0; a < x; a += 1){
            if ((a == 0) or (b == 0)){
                cout <<"*";
            }else if ((a == x-1) or (b == y-1)){
                cout <<"*";
            }else{
                cout << " ";
            }
        }
    cout << endl;
    }
    //*/

    /*
    double velocity = input();
    double pos = 0;
    int time = 0;
    double max = 0;
    int maxtime = 0;
    while (pos >=0){
        cout <<time <<" " <<pos << endl;
        time++;
        pos = velocity*time - .5*(9.8)*(time*time);
        if (pos > max){max = pos; maxtime = time;}

    }
    if (velocity < .00001){time = 0;}
    cout << "Total Time: " << time << "-seconds" << endl;
    cout << "Maximum Height: " << max << " @ " << maxtime << "-seconds";

    //*/
    /*
    double width = input();
    double tolerance = input();
    double x = 0;
    for (int t = 60; t < 86; t++){
        x = width + (t - 70)*(0.0001);
        cout << t <<" ";
        cout << fixed << setw(10) << setprecision(7) << x;
        if ((x < (width + tolerance)) and (x > (width - tolerance))){
            cout << " *";
        }
        cout << endl;
    }


    //*/
    
    


    return 0;
}
