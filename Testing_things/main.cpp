#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

vector<char> breakupstring(string str){
    vector<char> numdata;
    stringstream ss;     //requires sstream library included
    ss << str;

    while(!ss.eof()){
        char temp;
        ss >> temp;
        numdata.push_back(temp);
    }

    return numdata;
}

int main()
{
    bool map[15][15];
    ifstream Rules("C:\\Temp\\Rules.txt");
    string input;
    vector<char> numbers;
    unsigned a = 0;
    while(getline(Rules,input)){
        //string s1("2 45 1 2.5 9");
        numbers = {};
        numbers = breakupstring(input);
        for (unsigned b = 0; b < 15; ++b){
            cout << numbers.at(b) << " ";
            if (numbers.at(b) == '*')
                map[a][b] = false;
            else {
                map[a][b] = true;
            }
        }
        cout << endl;
        a++;
    }
    Rules.close();

    for (unsigned a = 0; a < 15; a++){
        for (unsigned b = 0; b < 15; b++)
            cout << map[a][b] << ' ';
        cout << endl;
    }
    return 0;
}
