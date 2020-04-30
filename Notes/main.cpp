#include <iostream>
#include <time.h>
#include <vector>
#include <fstream>

using namespace std;

int randrange(int a, int b){

    return((rand() % (a-(b+1))) + a);
}

vector<int> upgrade(int array[], unsigned size){
    vector<int> thing(size);
    for (unsigned a = 0; a < size; a++){
        thing.at(a) = array[a];
    }
    return(thing);

}

vector<int> vectorprune(vector<int> thing){
    vector<int>::iterator it = thing.begin();
    for (int a = 0; a < thing.size(); a++){
        if ((thing.at(a) % 4) == 0){
            thing.erase(it+a);
            it = thing.begin();
            a--;
        }
    }
    return(thing);
}

void showvector(vector<int> thing){
    for (unsigned a = 0; a < thing.size(); a++){
        cout << thing.at(a) << endl;
    }

}

int main()
{
    char a, *b, **c, d;
    a = 'z';
    b = &a;
    c = &b;
    d = **c;

    cout << d << endl;
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    srand(0);
    vector<int> thing = vectorprune(upgrade(array,10));
    showvector(thing);

    cout << randrange(10,12) << endl;
    return 0;
}



/*
 only takes int for value
switch(variable)
{
    case<value>:

        break;
    case<value>:

        break;
    default:

        break;

}

x = x>y ? 2 : 3;


do{
}while(___);

int myarray[length___ UNCHANGEABLE!] = {stuff};

vector<TYPE> NAME{STUFF};
vector<TYPE> NAME(size, fill);


vector<TYPE>::iterator it = NAME.begin();
NAME.erase(it+__); <-- location

class Rectangle {
  private:
    int width, height;
  public:
    void set_values (int,int);
    int area();
};



ifstream file_input("C:\\temp\\shapes.txt");
ofstream file_output("C:\\temp\\shapes-info.txt");
string input;
while(getline(file_input,input))
    file_output << input << endl;
file_input.close()
file_output.close()



ifstream infile; - input from file
ofstream infile; - output to file
fstream infile;- both

ifstream infile;
infile.open("name.txt");
string var;
infile >> var;
infile.close();

ofstream oufile;
oufile.open("name.txt");
oufile << var;
oufile.close();

if (!infile)
    print error
while(!infile.eof())//goes until the end of a file.


Tennants of Obj Or Pro
    Polymorph
    Encap
    Inherit

Overloading is when 2 things do the same name but difrent things
-> acsess something from a class thats a pointer
. is acsessing something thats not a pointer
:: used to get something inside a class from outside of the class
* get a value from a pinded pointer
& adress operator get the number or thing from a pointer


O(n^2) comp options (Serching)
    Insertion
    Selection
    Bubble (worst)


start begin head
*/
