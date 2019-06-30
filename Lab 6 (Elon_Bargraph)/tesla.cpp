/*
This is a game where you have to run from Elon Musk and steal his car that he wants to launch into space.
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int randrange(int start, int end){// Gives a random number
    return(((rand() % (start-(end+1))) + start));
}


char input(string words){// just gets the input and returns it
    char outp;
    cout << words << endl;
    cin >> outp;
    while ((outp != 'w') and (outp != 'a') and (outp != 'd') and (outp != 's') and (outp != 'q')){
        cout << "Your leter is invalid. Enter a valid letter!" << endl;
        cin >> outp;
    }
    return(outp);
}

//Shows the map
void showbord(char map[][15], int placed[][2]){
    system("CLS");
    //Cleans the map
    for (unsigned a = 0; a < 15; a++)
        for (unsigned b = 0; b < 15; b++)
            map[a][b] = '*';

    //show the objects
    int a = 0;//to go through the objects
    do{
        if ((a != 0) and (a != 4))
            map[placed[a][1]][placed[a][0]] = '?';//put B,C,D
        else
            map[placed[a][1]][placed[a][0]] = a+65;//put B,C,D

        a++;//go to the next object
    }while((a < 5));

    //show map
    for (int y = 0; y < 15; y++){
        for (int x = 0; x < 15; x++){
            if ((abs(x - placed[0][0]) < 2) and (abs(y - placed[0][1]) < 2))//shows only the area around you
                cout << map[y][x];
            else {
                cout << ' ';//rest of map
            }
            cout << ' ';//makes it evenly spaced
        }
        cout << endl;
    }
}




//controls movement so you dont leave the map
bool movement(int &playerx, int &playery){
    char dir = input("Which direction do you want to go?");

    if (dir == 'q')
       return(false);

    if (dir == 'a')
        playerx -= 1;
    if (dir == 'd')
        playerx += 1;
    if (dir == 'w')
        playery -= 1;
    if (dir == 's')
        playery += 1;

    //to say you left the map
    if ((playerx > 14)){
        cout << "You Ran into a wall!" << endl << "Elon heard that!" << endl;
        playerx = 14;
    }
    if (playerx < 0){
        cout << "You Ran into a wall!" << endl << "Elon heard that!" << endl;
        playerx = 0;
    }
    if ((playery > 14)){
        cout << "You Ran into a wall!" << endl << "Elon heard that!" << endl;
        playery = 14;
    }
    if (playery < 0){
        cout << "You Ran into a wall!" << endl << "Elon heard that!" << endl;
        playery = 0;
    }
    return(true);
}

//checks to see if you where caught
char Alive(int placed[][2],int &wins, int &ELON, bool playing, bool safty = false){

    char Al = 'p';
    if ((placed[1][0] == placed[0][0]) and (placed[1][1] == placed[0][1]))
        Al = 'w';
    else if ((abs(placed[4][0] - placed[0][0]) < 2) and (abs(placed[4][1] - placed[0][1]) < 2)) {
        cout << "Elon found you!" << endl;
        Al = 'E';
    }else if ((placed[2][0] == placed[0][0]) and (placed[2][1] == placed[0][1]))
        Al = 'l';
    else if ((placed[3][0] == placed[0][0]) and (placed[3][1] == placed[0][1]))
        Al = 'l';


    if (Al == 'w'){
        cout << "You found the Roadster!" << endl;
        wins++;
    }else if (Al == 'l'){
        cout << "You found the wrong car!" << endl;
        cout << "Elon has captured you! Your the starman now!" << endl;
        return(false);
    }else if (Al == 'E'){
        if ((ELON == -1) and (safty == false)){
            cout << "Elon has captured you! Your the starman now!" << endl;
            return(false);
        }else{
            if (safty == false)
                ELON = -1;
            return(playing);
        }
    }else{
        return(playing);
    }
    return(false);
}

//elons random ai
void EWALK(int &locx,int &locy){
    locx += randrange(-1,1);
    locy += randrange(-1,1);
    if ((locx > 14)){
        locx = 13;
    }
    if (locx < 0){
        locx = 1;
    }
    if ((locy > 14)){
        locy = 13;
    }
    if (locy < 0){
        locy = 1;
    }

}

//clues
void clues(int placed[][2]){
    if ((abs(placed[1][0] - placed[0][0]) < 4))
        cout << "You are close to the left or right of the Roadster." << endl;
    else if ((abs(placed[1][0] - placed[0][0]) < 7))
        cout << "You are closer to the left or right of the Roadster." << endl;
    else
        cout << "You are far to the left or right of the Roadster." << endl;

    if ((abs(placed[1][1] - placed[0][1]) < 4))
        cout << "You are close above or below the Roadster." << endl;
    else if ((abs(placed[1][1] - placed[0][1]) < 7))
        cout << "You are closer above or below the Roadster." << endl;
    else
        cout << "You are far above or below the Roadster." << endl;

}



int main()
{
    srand(time(0));
    int wins = 0;
    int games = 0;
    int Average = 0;

    bool playing = true;

    while (playing){
        games++;

        //Make the map
        char map[15][15];
        for (unsigned a = 0; a < 15; a++)
            for (unsigned b = 0; b < 15; b++)
                map[a][b] = '*';

        //asign locations
        int x = randrange(0,14);
        int y = randrange(0,14);

        //A is Player, B is Lauched car, E is Elon, C/D are other cars
        int placed[5][2] = {{0,0},{0,0},{0,0},{0,0},{0,0}};//listed locations (Placements)
        int a = 0;//to go through the objects above
        do{
            if (map[y][x] == '*'){//if the spot is clear
                map[y][x] = a+65;//put A,B,C,D,E

                //save the location
                placed[a][0] = x;
                placed[a][1] = y;

                a++;//go to the next object
            }
            x = randrange(0,14);//new cords
            y = randrange(0,14);
        }while((a < 5));


        int ELON = randrange(4,10);
        bool EWOKE = false;

        bool game = true;
        int turns = 0;

        while(game){
            turns++;
            showbord(map, placed);

            //checks to see if elon ran into you
            game = Alive(placed,wins,ELON,playing);

            //kills the game if you got cot
            if(game != false){
                if(ELON <= 0){//Elon stuff
                    if (EWOKE == false){
                        cout << "Elon has AWOKEN!" << endl;
                        EWOKE = true;
                    }
                    EWALK(placed[4][0],placed[4][1]);//elon walking
                }else {
                    ELON--;//wakeup timer
                }

                clues(placed);//gives clues

                playing = movement(placed[0][0],placed[0][1]);//movement

                //checks to see if you walked into the wrong car
                game = Alive(placed,wins,ELON,playing,true);
            }
        }
        //to start a new game
        if (playing != false){
            char again = 'l';
            cout << "Turns taken: " << turns << endl << "Do you want to play again (y/n)?" << endl;
            cin >> again;
            while ((again != 'y') and (again != 'n')){//to get y or n
                cout << "That wasen't a y or an n!" << endl;
                cin >> again;
            }
            if (again == 'n')
                playing = false;
        }
        Average += turns;

    }

    //stats
    system("CLS");
    cout << "Games: " << games << endl;
    cout << "Roadsters: " << wins << endl;
    cout << "Stars: " << games-wins << endl;
    cout << "Average turns taken: " << Average/games << endl;
    return 0;
}
