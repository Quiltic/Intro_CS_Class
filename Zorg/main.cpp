#include <iostream>
#include <vector>
#include <string>
#include <time.h>

using namespace::std;

int randrange(int start, int end){
  return((rand() % (end-start+1)+start));
}

int input(string words, int max = 3, int min = 1){
  int inp;
  cout << words << endl;
  cin >> inp;
  while ((inp > max) or (inp < min)){
    cout << "That door doesent exist!" << endl;
    cin >> inp;
  }

  inp -= 1;//to get the correct room
  if (inp == 0)// cant stay still
      inp = -1;
return(inp);
}


/*
Lore:
Zorg - Zork I clone

Zorg - the hero/curriur - cousin to Zorian, must go get the most valuable wine in the celler, 19XX Zormestian wine, can't read

Zorian - The rich Baron of Zormestia, concieted and doesn't even recognize his family members. He will require his cousin Zorg to fetch some wine from his cellar.

Zortan - an aWearwolf: gets abruptly interupted by Zorg when he enters the basement by the metal door against the stone floor

When you return with the wine, Zorian smashes the bottle yelling that it was the wrong wine.


items:
  Torch - Allows you to see in the dark
  Mop - cleans spills
  Silver key - Opens the ornate door
  Air horn - removes stupid bats
  Silver Sword - It make swish sound when swung
  Rusted Chainmail
  Zortan's book.

*/

/*
How its done:


number of rooms: Max of 20 randomly generated rooms

Vector of objects(Rooms)
  Each room connects to the next room in the vector
  Each room can connect to 2/3 rooms ahead in the vector

Rooms have three parts:
  Introduction: an array of str "Looks"
  Needs item? : look below
  Connected rooms: look above

For rooms with item requirements it will do case statement with similar ideas as below
  needs torch to see
  need ___ Key to pass
  need a Sword to kill an aWearwolf
  Chainmail allows you to take 1 hit from the aWearwolf

Items will be randomly given to ___ room in the vector

*/

struct Player{
    vector<string> items;
    int rooms_entered = 0;
};


string roomDescriptor_Getitems(string item = "Empty"){
  string intro;

  if (item == "Empty")
    item.push_back(randrange(49,51));

  if (item == "Empty1") {
    intro = "As Zorg enters the room, the soft torchlight fills the interior. Zorg glances around, and notices that the room is mostly bare, save for a table and some chairs, as well as some rather tattered banners hanging from the wall. Zorg does not know what the banners say, but knowing his cousin it is something extraodinarily pretentious.";
  }
  else if (item == "Mop"){
    intro = "Zorg enters the room and glanced down at his feet, wincing at the \nsquishing noice. The torchlight reveals that there is a puddle of mixed blue and green covering the entire floor. It also smells quite bad. The creaking of brass is heard and Zorg hears his cousin speak.\n\n\"I have kept track of your progress, you peasant! You are doing a \nHORRIBLE job at getting me my wine! Mop up that slime puddle while you are there!\"\n\nZorg hears a large rattling noise, slowly getting closer and closer as \nit makes a cacophony of horrid noise. Suddenly, a wet mop shoots out of the brass pipe Zorg's cousin voice had came out from and slams into Zorg's face. Zorg sighs and picks up the mop";
  }
  else if(item == "Empty2") {
    intro = "Zorg looks around in surprise at the sight of this room. It's... completely bare? There is literally no decorations in this room. No furniture, no banners, no paintings of his cousin. This confuses Zorg greatly, as he knows for a fact how much his cousin enjoys to look at himself.";
  }
  else if(item == "Empty3") {
    intro = "Zorg creeps into the room slowly, looking around in case there is any random creatures looking to maul him or something. He glances around, noticing that the room seems to be mostly empty. Well, there is a few pieces of splintered furniture and what seems to be scratches everywhere along the walls, but honestly that isn't too bad.";
  }
  else if(item == "Silver Sword"){
    intro = "When Zorg looks into the room, the first thing he notices is a beam of light shooting down from the ceiling, ";
  }
  else if(item == "Chainmail"){
    intro = "";
  }
  else if(item == "Torch"){
    intro = "";
  }
  else if(item == "Book"){
    intro = "";
  }
  else if(item == "Silver Key"){
    intro = "";
  }
  else if(item == "Air Horn"){
    intro = "";
  }
  else {
    intro = "Zorg stares into the empty abyss of a room. (ERROR_Getitem)";
    cout << item << endl;
  }
  return(intro);
}


//What needs to be solved in each room
string roomDescriptor_problem(string item = "Empty"){
  string intro;

  if (item == "Empty")
    item.push_back(randrange(49,51));


  if (item == "Empty1") {
    intro = "";
  }
  else if(item == "Empty2") {
    intro = "";
  }
  else if(item == "Empty3") {
    intro = "";
  }
  else if(item == "Silver Sword") {
    intro = "";
  }
  else if(item == "Chainmail"){
    intro = "";
  }
  else if(item == "Torch"){
    intro = "";
  }
  else if(item == "Book"){
    intro = "";
  }
  else if(item == "Silver Key"){
    intro = "";
  }
  else if(item == "Air Horn"){
    intro = "";
  }
  else {
    intro = "Zorg stares into the empty abyss of a room. (ERROR_Problem)";
    cout << item << endl;
  }
  return(intro);
}

class Room{
  private:
    string description;
    string item;
    string needed;
    int connected_rooms;
  public:
    Room(string items = "Empty")
    {
        vector<string> items_Needed = {"Torch","Silver Key","Air Horn","Silver Sword","Chainmail", "Mop","Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty"};

        item = items;
        description = roomDescriptor_Getitems(item);// Items gotten
        if (item != "Mop"){
            needed = items_Needed[randrange(0,items_Needed.size()-1)];//Items needed
            description = description + (roomDescriptor_problem(needed));
        }
        connected_rooms = randrange(2,4);

    }
    string GetDescription(){
      return(description);
    }
    int GetConnectors(){
      return(connected_rooms);
    }
    string GetItems(){
      return(item);
    }
    string GetNeeded(){
      return(needed);
    }
    //int num_doors = randrange(0,2);// + the one it connects to
};



vector<Room> Create_new_map(){
  vector<string> items = {"Torch","Silver Key","Air Horn","Silver Sword","Chainmail","Mop","Book", "Empty"};//List of items

  vector<Room> Floorplan;//Rooms

  int item = 0;//number that gets items cleanly

  while(items.size() > 1){// run while there are items in the list

    if (randrange(0,100) < 75)//get a random item potentaly
      item = randrange(0,items.size()-2);
    else
      item = items.size()-1;//no items ("empty")

    Floorplan.push_back(Room(items.at(item)));//makes the room
    //cout << Floorplan.at(Floorplan.size()-1).GetDescription() <<" " << items.at(item) << endl;

    if (item != (items.size()-1)){//removes an item if its been used
      vector<string>::iterator it = items.begin();
      items.erase(it+item);
    }

  }
  //cout << "Room count: " << Floorplan.size() << endl;
  return(Floorplan);
}

void playgame(vector<Room> map){
    Player me;
    me.items.push_back("empty");
    vector<int> path = {0};
    int current = 0;
    Room cur_room = map.at(current);
    int haveit = 1;

    cout << "Begin game" << endl;// For start of game!

    while (current != map.size()-1){

        //Uncoment before playing
        //cout << cur_room.GetDescription() << endl;//Show Words
        for (unsigned a = 0; a < me.items.size()-1; a++)
            if (cur_room.GetNeeded() == me.items.at(a))
                haveit = 0;

        if ((cur_room.GetConnectors()-haveit == 1) or (cur_room.GetConnectors()-haveit == 0)){
            if (current != 0){
                cout << "The path forward is blocked, you will have to go back" << endl;
                current -= 1;}
            else {
                cout << "NO LEAVING WITHOUT MY WINE!" << endl;
                current += 1;}
        }else if (cur_room.GetConnectors()-haveit == 2){
            current += input("There are two ways to go, forward(2) or back(1), which do you chose? ",2);

        }else if (cur_room.GetConnectors() == 3){
            current += input("There are three ways to go, to the left(3), right(2), and back(1) to the preveous room. Which do you chose? ",3);
        }else if (cur_room.GetConnectors() == 4){
            current += input("There are three ways to go, forward(4), to the left(3), right(2), and back(1) to the preveous room. Which do you chose? ",4);
        }
        else{
            cout << "Error too many room connections" << endl;
        }


        cout << current << endl;
        if (current < 0){
            cout << "NO LEAVING WITHOUT MY WINE!" << endl;
            current = 2;}
        else if (current > map.size()-1)
            current = map.size()-1;

        cur_room = map.at(current);
        me.items.push_back(cur_room.GetItems());
    }
    cout << "Victory!" << endl;// the last room!

}


int main() {
  srand(time(0));
  //for (unsigned a = 0; a < 21; a++){
    vector<Room> map = Create_new_map();
    playgame(map);
    cout << "Done" << endl;
    //}
  return 0;
}

