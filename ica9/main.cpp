#include <iostream>

using namespace std;

struct node{
    char lett;
    node *north;
    node *south;
    node *east;
    node *west;
};

int main(){

    //Defines Each Node
    node* nodeA = new node;
    node* nodeB = new node;
    node* nodeC = new node;
    node* nodeD = new node;
    node* nodeE = new node;
    node* nodeF = new node;
    node* nodeG = new node;
    node* nodeH = new node;
    node* nodeI = new node;
    node* nodeJ = new node;
    node* nodeK = new node;
    node* nodeL = new node;
    node* nodeM = new node;
    node* nodeN = new node;
    node* nodeO = new node;
    node* nodeP = new node;
    node* nodeQ = new node;
    node* nodeR = new node;
    node* nodeS = new node;
    node* nodeT = new node;
    node* nodeU = new node;
    node* nodeV = new node;
    node* nodeW = new node;
    node* nodeX = new node;
    node* nodeY = new node;
    node* nodeZ = new node;

    //Defining Letters at Each Node
    nodeA->lett = 'A';
    nodeB->lett = 'B';
    nodeC->lett = 'C';
    nodeD->lett = 'D';
    nodeE->lett = 'E';
    nodeF->lett = 'F';
    nodeG->lett = 'G';
    nodeH->lett = 'H';
    nodeI->lett = 'I';
    nodeJ->lett = 'J';
    nodeK->lett = 'K';
    nodeL->lett = 'L';
    nodeM->lett = 'M';
    nodeN->lett = 'N';
    nodeO->lett = 'O';
    nodeP->lett = 'P';
    nodeQ->lett = 'Q';
    nodeR->lett = 'R';
    nodeS->lett = 'S';
    nodeT->lett = 'T';
    nodeU->lett = 'U';
    nodeV->lett = 'V';
    nodeW->lett = 'W';
    nodeX->lett = 'X';
    nodeY->lett = 'Y';
    nodeZ->lett = 'Z';

    //North Node Connections
    nodeA->north = NULL;
    nodeB->north = nodeA;
    nodeC->north = NULL;
    nodeD->north = NULL;
    nodeE->north = nodeD;
    nodeF->north = nodeE;
    nodeG->north = nodeF;
    nodeH->north = nodeI;
    nodeI->north = nodeJ;
    nodeJ->north = nodeC;
    nodeK->north = nodeB;
    nodeL->north = nodeK;
    nodeM->north = nodeN;
    nodeN->north = nodeO;
    nodeO->north = NULL;
    nodeP->north = NULL;
    nodeQ->north = NULL;
    nodeR->north = nodeQ;
    nodeS->north = nodeP;
    nodeT->north = nodeS;
    nodeU->north = nodeR;
    nodeV->north = nodeU;
    nodeW->north = nodeT;
    nodeX->north = nodeM;
    nodeY->north = nodeL;
    nodeZ->north = nodeY;

    //East Node Connections
    nodeA->east = NULL;
    nodeB->east = nodeC;
    nodeC->east = nodeD;
    nodeD->east = NULL;
    nodeE->east = NULL;
    nodeF->east = NULL;
    nodeG->east = NULL;
    nodeH->east = nodeG;
    nodeI->east = nodeF;
    nodeJ->east = nodeE;
    nodeK->east = nodeJ;
    nodeL->east = nodeI;
    nodeM->east = nodeL;
    nodeN->east = nodeK;
    nodeO->east = nodeB;
    nodeP->east = nodeO;
    nodeQ->east = nodeP;
    nodeR->east = nodeS;
    nodeS->east = nodeN;
    nodeT->east = nodeM;
    nodeU->east = nodeT;
    nodeV->east = nodeW;
    nodeW->east = nodeX;
    nodeX->east = nodeY;
    nodeY->east = nodeH;
    nodeZ->east = NULL;

    //South Node Connections (NEED COMPLETED)
    nodeA->south = nodeB;
    nodeB->south = NULL;
    nodeC->south = NULL;
    nodeD->south = nodeE;
    nodeE->south = nodeF;
    nodeF->south = nodeG;
    nodeG->south = NULL;
    nodeH->south = NULL;
    nodeI->south = NULL;
    nodeJ->south = NULL;
    nodeK->south = nodeL;
    nodeL->south = NULL;
    nodeM->south = NULL;
    nodeN->south = NULL;
    nodeO->south = NULL;
    nodeP->south = NULL;
    nodeQ->south = nodeR;
    nodeR->south = NULL;
    nodeS->south = nodeT;
    nodeT->south = NULL;
    nodeU->south = nodeV;
    nodeV->south = NULL;
    nodeW->south = NULL;
    nodeX->south = NULL;
    nodeY->south = nodeZ;
    nodeZ->south = NULL;

    //West Node Connections (NEED COMPLETED)
    nodeA->west = NULL;
    nodeB->west = nodeC;
    nodeC->west = nodeD;
    nodeD->west = NULL;
    nodeE->west = NULL;
    nodeF->west = NULL;
    nodeG->west = nodeH;
    nodeH->west = NULL;
    nodeI->west = NULL;
    nodeJ->west = nodeK;
    nodeK->west = NULL;
    nodeL->west = nodeM;
    nodeM->west = NULL;
    nodeN->west = NULL;
    nodeO->west = nodeP;
    nodeP->west = nodeQ;
    nodeQ->west = NULL;
    nodeR->west = NULL;
    nodeS->west = NULL;
    nodeT->west = nodeU;
    nodeU->west = NULL;
    nodeV->west = NULL;
    nodeW->west = NULL;
    nodeX->west = NULL;
    nodeY->west = NULL;
    nodeZ->west = NULL;

    //Navigation Test (DO NOT TOUCH)
    node* temp = nodeA;
    for(char i='A'; i<='Z'; i++){
        if (temp->lett != i){
            cout << endl << "Pointing at wrong node, ending..." << endl;
            return 0;
        }
        cout << temp->lett;
        if (temp->north != NULL){
            if (temp->north->lett == temp->lett+1){
                temp = temp->north;
                continue;
            }
        }
        if (temp->south != NULL){
            if (temp->south->lett == temp->lett+1){
                temp = temp->south;
                continue;
            }
        }
        if (temp->east != NULL){
            if (temp->east->lett == temp->lett+1){
                temp = temp->east;
                continue;
            }
        }
        if (temp->west != NULL){
            if (temp->west->lett == temp->lett+1){
                temp = temp->west;
                continue;
            }
        }
    }
    cout << endl;
    cout << "YOU HAVE DONE IT! YOU HAVE COMPLETED THE ALPHABET MAP! CONGRATULATIONS!" << endl;

    return 0;
}
