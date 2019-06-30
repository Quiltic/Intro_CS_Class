/*
 * Project Title:
 * - Game o Life?
 * Description: (Similar to Conways game of life, but with flexability)
 *
 *
 * Developers:
 * - Josh Zack - zackjm@mail.uc.edu
 * - Casey Cundiff - cundifcm@mail.uc.edu
 *
 * Help Received:
 * - Nobody
 *
 * Special Instructions:
 * - Needs a Rules file in a tmp folder
 * - Look below for what the file should look like
 *
 * Developer comments: // Not optional
 * Josh:
 * I created the classes and map
 * Casey:
 * More coordination is needed for team efforts so that members don't do the same tasks

Rules file should look like this (No tabs)


        * * * * * * * * * * * * * * *
        * * * * * * * * * * * * * * *
        * * * * * * * * * * * * * * *
        * * * * * * * * * * * * * * *
        * * * * * * * * * * * * * * *
        * * * * * o * o * o * * * * *
        * * * * * o * * * o * * * * *
        * * * * * o * * * o * * * * *
        * * * * * o * * * o * * * * *
        * * * * * o * o * o * * * * *
        * * * * * * * * * * * * * * *
        * * * * * * * * * * * * * * *
        * * * * * * * * * * * * * * *
        * * * * * * * * * * * * * * *
        * * * * * * * * * * * * * * *
        * * * * * * * * * * * * * * *

        + 4
        - 0
        R 1
        C 1



The box is the starting seed map
+ is max number of nabors needed to survive
- is min number of nabors needed to survive
R is the number of nabors needed to revive
C is weather or not the screen will refresh as the timer goes up

THE NUMBERS NEXT TO IT NEED TO BE ONE NUMBER

The origional is:
+ 4
- 1
R 3
C 1

A fun one is:
+ 2
- 0
R 1
C 1
 */

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <thread> // for delay
#include <chrono> // for delay
#include <fstream>
#include <sstream>

using namespace std;

//Splits the lines
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

//RANDOM!
int randrange(int start, int end){// Gives a random number
    return(((rand() % (start-(end+1))) + start));
}
/*

Inputs:
    Time between bord shows
    max number of turns - empty is max longlong
    size of grid
    map?

every cell is a class
Contains
    x,y point on a grid
    pointer to nearby freinds
    a function asking for if its freind is alive
    alive or dead
    the "next" cell


grid Looks like below
***********************
********ooo************
********o*o************
********ooo************
***********************
***********************
***********************
***********************
***********************

o is alive cell * is dead

Rules to basic game of life
    For a space that is 'populated':
        Each cell with one or no neighbors dies, as if by solitude.
        Each cell with four or more neighbors dies, as if by overpopulation.
        Each cell with two or three neighbors survives.
    For a space that is 'empty' or 'unpopulated'
        Each cell with three neighbors becomes populated.

*/
class cell{
    bool Alive;//alive or dead
    bool tobe = false;// tobe alive or dead

    int max, min, rev;

    // for testing to know where it is on the map
    int x;
    int y;

    //pointers to nearby freinds
    cell *north = NULL;
    cell *south= NULL;
    cell *east= NULL;
    cell *west= NULL;

    cell *northeast = NULL;
    cell *southeast= NULL;
    cell *northwest= NULL;
    cell *southwest= NULL;

    public:

        //constructors
        cell(){
            x = 0;
            y = 0;
            Alive = false;
            min = 1;
            max = 4;
            rev = 3;
        }
        cell(int xthing, int ything, bool al, int mina , int maxa, int reva){
            x = xthing;
            y = ything;
            Alive = al;
            tobe = al;
            min = mina;
            max = maxa;
            rev = reva;
        }

        //setup/change
        void change (int xthing, int ything, bool al, int mina , int maxa, int reva){
            x = xthing;
            y = ything;
            Alive = al;
            tobe = al;
            min = mina;
            max = maxa;
            rev = reva;
        }

        void changefreinds_n_s (cell* n, cell* s){
            this->north = n;
            this->south= s;
        }

        void changefreinds_e_w (cell* e, cell* w){
            this->east = e;
            this->west = w;
        }

        void changefreinds_Ne(cell* e){
            this->northeast = e;
        }
        void changefreinds_Se(cell* e){
            this->southeast = e;
        }
        void changefreinds_Sw (cell* w){
            this->southwest = w;
        }
        void changefreinds_Nw (cell* w){
            this->northwest = w;
        }


        void freinds(){
            int tally = 0;
            //cout << this->south->isalive() << endl;
            //checks the poles
            if (this->north != NULL)
                if (this -> north -> isalive() == true)
                    tally += 1;
            if (this->south != NULL)
                if (this -> south -> isalive() == true)
                    tally += 1;
            if (this->east != NULL)
                if (this -> east -> isalive() == true)
                    tally += 1;
            if (this->west != NULL)
                if (this -> west -> isalive() == true)
                    tally += 1;


            //cout << this->northeast << ' ' << this->northwest << ' ' << this->southeast << ' ' << this->southwest << ' ' << NULL << endl;
            //checks the corners
            if (this->northwest != NULL)
                if (this -> northwest->isalive() == true)
                    tally += 1;

            if (this->southwest != NULL)
                if (this -> southwest->isalive() == true)
                    tally += 1;
            if (this->northeast != NULL)
                if (this -> northeast->isalive() == true)
                    tally += 1;
            if (this->southeast != NULL)
                if (this -> southeast->isalive() == true)
                    tally += 1;

            //rules to live
            if ((tally <= min) or (tally >= max)) // dies if over/under populated
                tobe = false;
            else if ((Alive == false) and (tally == rev)) // revives if dead
                tobe = true;
            else if ((Alive == true) and ((tally == 2) or (tally == 3)))// probably unneeded but a backup
                tobe = true;
            else// failsafe
                tobe = false;
        }

        void revive(){
            Alive = tobe;
        }

        //retrievals
        bool isalive(){
            return(Alive);
        }
        bool istobe(){
            return(tobe);
        }

        cell* getnorth(){
            return(north);
        }
        cell* getsouth(){
            return(south);
        }
        cell* geteast(){
            return(east);
        }
        cell* getwest(){
            return(west);
        }

        cell* getnorthwest(){
            return(northwest);
        }
        cell* getsoutheast(){
            return(southeast);
        }
        cell* getnortheast(){
            return(northeast);
        }
        cell* getsouthwest(){
            return(southwest);
        }


};


//Shows the map
void Showmap(cell map[][15], bool clear = false){
    if (clear)
        system("CLS");//makes it a vid insted of a bunch of blocks in one sitting

    for (unsigned a = 0; a < 15; a++){
        for (unsigned b = 0; b < 15; b++){
             if (map[a][b].isalive())
                 cout << " o";
             else
                 cout << " *";
             }
        cout << endl;
    }
    this_thread::sleep_for (chrono::milliseconds(50));// delay for the vid
}

//Shows the map
void Updatemap(cell map[][15]){
    //makes the cells ahualy show what they are
    for (unsigned a = 0; a < 15; a++)
        for (unsigned b = 0; b < 15; b++)
            map[a][b].revive();

    // figures out what they should be next cycle
    for (unsigned a = 0; a < 15; a++)
        for (unsigned b = 0; b < 15; b++)
             map[a][b].freinds();


    cout << endl << endl;
}

class rules{
    private:
        //achual rules
        int MINRULE = 1, MAXRULE = 4, REVRULE = 3; // minimum number of nabors needed, max num of nambors needed, num of nab needed for revive
        bool Clear = false;// weather the map resets and is more of a vidio or a bunch of slides

        bool minimap[15][15];//seed map
        cell map[15][15];// the achual map


     public:
        void getrules(){
        ifstream Rules("C:\\Temp\\Rules.txt");//minimap
        string input; //holder of tmp data
        vector<char> numbers; // another holder of tmp data
        unsigned a = 0; //row
        while(getline(Rules,input)){
            //until it runs out of lines it will move forward
            numbers = {}; // clear data
            numbers = breakupstring(input);
            if (numbers.size() >= 4){

                for (unsigned b = 0; b < 15; ++b){//collum
                    if (numbers.at(b) == '*') //dead
                        minimap[a][b] = false;
                    else { //alive
                        minimap[a][b] = true;
                    }
                }
            }
            else {
                if (numbers.at(0) == '+')
                    MAXRULE = numbers.at(1)-48;
                if (numbers.at(0) == '-')
                    MINRULE = numbers.at(1)-48;
                if (numbers.at(0) == 'R')
                    REVRULE = numbers.at(1)-48;
                if (numbers.at(0) == 'C')
                    Clear = numbers.at(1)-48;
            }

            a++;
        }
        Rules.close();
        }

        void MAKE_MAP(){

            //srand(time(0));//for making the map randomly

            for (unsigned a = 0; a < 15; a++)
                for (unsigned b = 0; b < 15; b++){
                    map[a][b].change(a,b,minimap[a][b],MINRULE, MAXRULE, REVRULE); // seting everything up nicely
                }

            //gives all the cells there neighbors
            for (unsigned a = 0; a < 15; a++)
                for (unsigned b = 0; b < 15; b++){
                    // for the north south
                    if ((a-1) >= 105){
                        map[a][b].changefreinds_n_s(NULL,&map[a+1][b]);
                    }
                    else if ((a+1) >= 15){
                        map[a][b].changefreinds_n_s(&map[a-1][b],NULL);
                    }
                    else{
                        map[a][b].changefreinds_n_s(&map[a-1][b],&map[a+1][b]);
                    }

                    //for the east west
                    if ((b-1) >= 105){
                        map[a][b].changefreinds_e_w(&map[a][b+1],NULL);
                    }
                    else if ((b+1) >= 15){
                        map[a][b].changefreinds_e_w(NULL,&map[a][b-1]);
                    }
                    else
                        map[a][b].changefreinds_e_w(&map[a][b+1],&map[a][b-1]);


                    //for north east/west
                    if (map[a][b].getnorth() != NULL){
                            if (map[a][b].geteast() != NULL)
                                map[a][b].changefreinds_Ne(&map[a-1][b+1]);

                            if (map[a][b].getwest() != NULL)
                                map[a][b].changefreinds_Nw(&map[a-1][b-1]);
                    }

                    //south east/west
                    if (map[a][b].getsouth() != NULL){
                            if (map[a][b].geteast() != NULL)
                                map[a][b].changefreinds_Se(&map[a+1][b+1]);

                            if (map[a][b].getwest() != NULL)
                                map[a][b].changefreinds_Sw(&map[a+1][b-1]);

                    }
                    //cout << map[a][b].getnortheast() << ' ' << map[a][b].getnorthwest() << ' ' << map[a][b].getsoutheast() << ' ' << map[a][b].getsouthwest() << endl;
                    //map[a][b].changefreinds(&map[a-1][b],&map[a+1][b],&map[a][b+1],&map[a][b-1]); // extra

                }

        }

        void RUNGAME(){

            Showmap(map);

            for (unsigned a = 0; a < 40; a++){
                Updatemap(map);
                cout << endl;
                cout << endl;
                Showmap(map,Clear);
            }
        }

};

int main()
{

    rules game;
    game.getrules();
    game.MAKE_MAP();
    game.RUNGAME();

    return 0;
}
