/*
This code makes a set number of random numbers and makes a rough bargraph that is then shown
*/

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int randrange(int start, int end){// Gives a random number
    return(((rand() % (start-(end+1))) + start));
}


int input(string words, int max, int min = 0){// just gets the input and returns it
    int outp;
    cout << words << endl;
    cin >> outp;
    while ((outp < min) or (outp > max)){
        cout << "Your number is invalid. Enter a value greater than or equal to " << min <<" but smaller than " << max << endl;
        cin >> outp;
    }
    return(outp);
}

//Shows the data
void showbargraph(vector<long long> vect,long long size, long long scale, int maxnumb,long long maximmum,int minnumb,long long minimmum,long long sum,long long mean){
    cout << "Number:" << setw(10) << "Amount:"<< setw(10) <<"Bar:" << endl;// table head
    for (unsigned a = 0; a < size; a++){
        cout << a << setw(10) << vect[a] << setw(10);// show the curent number and total
        for (unsigned b = 0; b < (vect[a]/scale); b++)
            cout << "*";//bar part
        cout << endl;
    }
    // shows stats sum mean max min maxamount, minamount not in that order
    cout << "Sum: " << sum << "   Mean: "<< mean <<"\nMost rolled: " << maxnumb << "   Amount: " << maximmum <<"   Least rolled: " << minnumb << "   Amount: " << minimmum << endl;
}

long long Createlist(int number, vector<long long> &vect, int maxRandval){
    long long sum = 0;
    long long ran = 0;
    //Makes the array and gets sum
    for (unsigned a = 0; a < number; a++){
        ran = randrange(0,maxRandval);
        vect.at(ran) += 1;
        sum += ran;
    }
    return sum;
}



int main()
{
    int number = input("Input the amount of stuff and things: ", 10000);
    long long maxRandval = input("Input the largest value wanted (10-100): ", 100, 10);
    vector<long long> made(maxRandval+1);

    //sets the lists numbers to 0
    for (int a = 0; a < maxRandval+1; a++)
        made.at(a) = 0;


    long long sum = Createlist(number, made, maxRandval);


    long long mean = sum/number;
    long long maximmum = -10;
    long long minimmum = 100000;
    int maxnumb = 0;
    int minnumb = 0;

    //gets the max, min, and the largest value for clean looking bargraph
    long long max_vector_value = -10;
    for (unsigned a = 0; a < made.size(); a++){
        if (made[a] > max_vector_value)
            max_vector_value = made[a];

        if (made[a] > maximmum){
            maximmum = made[a];
            maxnumb = a;
        }
        if (made[a] < minimmum){
            minimmum = made[a];
            minnumb = a;
        }
    }


    showbargraph(made,made.size(), (max_vector_value/60), maxnumb, maximmum, minnumb, minimmum, sum, mean);

    return 0;
}
