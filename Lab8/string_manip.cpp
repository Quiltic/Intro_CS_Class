#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// This prototype is complete
class stringManip {
    public:
        stringManip();
        stringManip(string input);
        string retrieve();
        void setString(string input);
        void chop();
        void padString(int n);
        void center(int length);
        void truncate(int n);
        void removeNonAlpha();
        void convertToUpperCase();
        void convertToLowerCase();
    private:
        string tobeEdited;
};

// Not all functions are defined here

// Default Constructor
stringManip::stringManip(){
    tobeEdited = "";
}

// Overloaded Constructor
stringManip::stringManip(string in_string){
    tobeEdited = in_string;
}

// retrieve function
string stringManip::retrieve(){
    return tobeEdited;
}

// padString() function
void stringManip::padString(int length){
    while (tobeEdited.length() < length)//makes it the same length
        tobeEdited.append(" ");

}

//Cuts off the front and back spaces
void stringManip::chop(){
    //front
    if (tobeEdited.length()){//if its achualy something
    char ch = tobeEdited.at(0);
    while (isspace(ch)){//checks to see if it is a charicter or a string then removes it if need be
        tobeEdited.erase(0,1);
        ch = tobeEdited.at(0);
    }
    //back of string
    ch = tobeEdited.at(tobeEdited.length()-1);
    while (isspace(ch)){//makes it the same length
        tobeEdited.erase(tobeEdited.length()-1,1);
        ch = tobeEdited.at(tobeEdited.length()-1);
    }
    }
}

//truncate(int n) is a function which shortens the string to n characters.
void stringManip::truncate(int length){
    if (tobeEdited.length()){//if its achualy something
    char ch = tobeEdited.at(tobeEdited.length()-1);
    while (tobeEdited.length() > length){//makes it the same length
        tobeEdited.erase(tobeEdited.length()-1,1);
        ch = tobeEdited.at(tobeEdited.length()-1);
    }

}}

//removeNonAlpha() is function that removes all characters (including spaces) that are not alphabetical from the string. The isalpha function may be helpful for this purpose.
void stringManip::removeNonAlpha(){
    if (tobeEdited.length()){//if its achualy something
    char ch = tobeEdited.at(0);
    unsigned a = 0;
    bool something;
    while (tobeEdited.length() != a){//go through the entire string
        ch = tobeEdited.at(a);
        something = isalpha((ch));
        if (!something)
            tobeEdited.erase(a,1);//removes the non alfa charicter
        else{
            a++;//next thing

        }
    }
}
}


//convertToUpperCase() is a function that converts all lowercase characters in the string to uppercase. All other characters remain the same.4
void stringManip::convertToUpperCase(){
    if (tobeEdited.length()){//if its achualy something
    char ch = tobeEdited.at(0);
    unsigned a = 0;
    while (tobeEdited.length()-1 != a){
        tobeEdited[a] = toupper(tobeEdited.at(a));//iterates and upercases the letters
        a++;
        ch = tobeEdited.at(a);
        }

    tobeEdited[a] = toupper(tobeEdited.at(a));//last letter to upper
    }
 }


//convertToLowerCase() is a function that converts all lowercase characters in the string to uppercase. All other characters remain the same.

void stringManip::convertToLowerCase(){
    if (tobeEdited.length()){//if its achualy something
    char ch = tobeEdited.at(0);
    unsigned a = 0;
    while (tobeEdited.length()-1 != a){
        tobeEdited[a] = tolower(tobeEdited.at(a));//makes the letters lowercase
        a++;
        ch = tobeEdited.at(a);
        }

    tobeEdited[a] = tolower(tobeEdited.at(a));//make the last letter lower
 }}

//center(int length) - Write a function to center the string within the space specified by length.  You should remove any existing leading and trailing spaces in the string before centering it.

void stringManip::center(int length){
    chop();

    unsigned a = 1;//to swich between beginging and end
    while (tobeEdited.length() != length){//go untill x
        if (a % 2)
            tobeEdited.append(" ");//to end
        else
            tobeEdited = " " + tobeEdited;//to begining
        a++;
        }
}

//Add blanks to the front and back of the string.  If an odd number of blanks have to be added, put the extra blank on the right. You should store the result back in the “tobeEdited” string.

void stringManip::setString(string str){
    tobeEdited = str;
}

// Add test cases to main()
int main(){
    stringManip S1;
    stringManip S2("I miss spring break already!!!");

    // Test case for padString() You should correct some of your own.
    cout << "S2 before Chop(): <" << S2.retrieve() << ">" << endl;
    S2.chop();
    cout << "S2 before padString(20): <" << S2.retrieve() << ">" << endl;
    //S2.padString(20);
    //cout << "S2 before truncate(11): <" << S2.retrieve() << ">" << endl;
    //S2.truncate(11);
    cout << "S2 before removeNonAlfa(): <" << S2.retrieve() << ">" << endl;
    S2.removeNonAlpha();
    cout << "S2 before ToUpper: <" << S2.retrieve() << ">" << endl;
    S2.convertToUpperCase();
    cout << "S2 before tolower: <" << S2.retrieve() << ">" << endl;
    S2.convertToLowerCase();
    cout << "S2 before center: <" << S2.retrieve() << ">" << endl;
    S2.center(20);
    cout << "S2 at end: <" << S2.retrieve() << ">" << endl;
    cout << "Should be: <testing>" << endl;


    return 0;
}

//<testing 123          >
//<testing 123       >
