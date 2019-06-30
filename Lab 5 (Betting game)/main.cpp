/*
This is a betting Game
*/

#include <iostream>
//#include <time.h>// was used for rand seed but doesent work as intended

using namespace std;

void stats(int games, float wins, int cash){// prints the statistics
    cout << endl; // makes the terminal look cleaner
    cout << "Number of games: " << games << endl;
    cout << "Number of wins: " << wins << endl;
    cout << "Number of losses: " << games - wins << endl;
    cout << "% won: " << (wins/games*100) << endl;
    cout << "Final bank balance: $" << cash << endl;

}

char input(string words){//for geting the number your beting on
    char outp;
    cout << words << endl;
    cin >> outp;
    return(outp);
}


int input(string words, int total){// for geting the bet
    int outp;
    cout << words << endl;
    cin >> outp;
    while (outp > total){
        cout << "Your number is too large. Enter a value less than or equal to " << total << endl;
        cin >> outp;
    }
    return(outp);
}

int roleDice(){// roles the dice
    return(((rand() % (1-(6+1))) + 1));
}

bool playOneGame(){// plays one game


    char numberchosen = input("What number are you betting on?");// gets input and prints line

    // when I had x be the end statement
    //if (numberchosen == 'x'){
    //    cout << "Bye!" << endl;
    //    return(numberchosen);// checks to see if it needs to quit
    //}

    int chosen = numberchosen-48; // turns the input to a number cleanly (0 is 48 from aski table)

    // if what is entered doesent make sence
    while(((chosen < 1) or (chosen > 6)) and (numberchosen != 'x')){
        cout << "This caricter is invalid enter 1, 2, 3, 4, 5, or 6!" << endl;
        numberchosen = input("What number are you betting on?");

        //when I had the x be end
        //if (numberchosen == 'x'){
        //    cout << "Bye!" << endl;
        //    return(numberchosen);
        //}

        chosen = numberchosen-48;
    }


    int num;// temp variable for the dice number
    bool cash = false; // "false"
    // role 3 times
    for (int a = 0; a < 3; a++){
        num = roleDice();
        cout << "You roled a " << num << endl;
        if (num == chosen) // makes it "True"
            cash = true;
    }

    if (cash == 1)
        cout << "Congrats your a winner!" << endl;
    else
        cout << "Sorry you lost." << endl;

    return(cash);
}


int main()
{
    int cash = 100;
    int games = 1;
    int wins = 0;

    cout << "Welcome! You currently have $" << cash << endl;
    int wager = input("How much do you want to wager? Enter (0 or a negitive) to quit", cash);
    bool out = playOneGame();

    while (wager > 0 and cash > 0){ // to see if we should keep going

        if (out == true){
            cash += wager;//change to int to get a clean exchange
            wins++;
        }else {
            cash -= wager;
        }

        cout << "You currently have $" << cash << endl;// say amount of cash
        if (cash <= 0 ){
            cout << "Sorry but your out of cash!"<< endl;
        }
        else{
            cout << endl;// makes the terminal look cleaner
            wager = input("How much do you want to wager? Enter (0 or a negitive) to quit", cash);
            if (wager > 0){
                out = playOneGame();// play again
                games++;
            }
        }
    }
    stats(games, wins, cash);

    return 0;
}
