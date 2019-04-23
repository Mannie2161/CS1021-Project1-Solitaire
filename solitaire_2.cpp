#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>
using namespace std;

class cards {

    string color;
    int num;
    string type;
public:
    
    bool isFlipped = false;
    
    friend ostream & operator<< ( ostream &output, const cards &c ){
        output<< c.type<< c.num;
        return output;
    }

    void setColor(int c) {
        if(c==0)
            color = "black";
        else if(c==1)
            color = "red";
    }
    
    void setNum(int n) {
        num = n;
    }
    void setType(int t) {
        switch (t) {
            case 0: type = "spades"; break;
            case 1: type = "clubs"; break;
            case 2: type = "hearts"; break;
            case 3: type = "diamonds"; break;
        }
    }
    
    void display() {
        cout<<type<<num<<endl;
    }
    
    /*
    bool cardIsFlipped(cards card){
        return card.IsFlipped();
    }
    */
    bool operator == (cards &rhs) {
        if((color == rhs.color)&&(num == rhs.num)&&(type == rhs.type))
            return true;
        else
            return false;
    }
};

vector<cards> ShowPile(vector<cards> myDeck, vector<cards> tableauDeck, int opt) {
    vector<cards> pile(52);
    int pos=-1;
    
    //assigning cards to the pile
    int c=0;
    int itr=0;
    do {
        
        int flag = 0;
        for(int i=0;i<28;i++) {
            if((myDeck.at(c) == tableauDeck.at(i))==true) {
                flag=1;
                break;
            }
        }
        
        if(flag==0) {
            pile.at(itr)=myDeck.at(c);
            itr+=1;
        }
        
        c+=1;
    } while (itr!=24);
    
    //show the pile
    cout<<"Pile: ";
    
    if(opt == 0)
        for(int i=0;i<24;i++) {
            cout<<" * ";
        }
    else if(opt==1)
        for(int i=0;i<24;i++) {
            if(i == 23-pos)
                cout<<pile.at(i);
            else
                cout<<" * ";
        }
    pos += 1;
    return pile;
}

vector<cards> Tableau(vector<cards> myDeck, int opt) {
    vector<cards> tableauDeck(52);
    vector<int> random_nums(28);
    
    for(int r=0;r<28;r++) {
        random_nums.at(r) = rand()%52;
        for(int j=r;j>=0;j--) {
            if(random_nums.at(r)==random_nums.at(j))
                random_nums.at(r) = rand()%52;
        }
    }
    
    for(int i=0;i<28;i++) {
        tableauDeck.at(i) = myDeck.at(random_nums.at(i));
    }
    
    ShowPile(myDeck, tableauDeck, opt);
    
    
    /*
    //show the Tableau
    for(int i=0;i<28;i++)
        tableauDeck[i].display();
    
    cout<<endl<<endl;
    */
    
    cards columns[13][7];
    int counter=0;
    
    /*
    //arrange the cards on the tableau -- NOT REQUIRED
    for (int r=0;r<7;r++){
        for(int c=0;c<=r;c++){
            columns[r][c] = tableauDeck.at(counter);
            counter++;
        }
    }
    */
    
    //first time setup for the tableau
    cout<<endl<<endl;
    for (int r=0;r<7;r++){
        for(int c=0;c<=r;c++){
            if(c==r) {
                cout<<tableauDeck.at(counter);
                tableauDeck.at(counter).isFlipped = true;
                counter++;
            }
            else {
                cout<<" * "<<"\t";
                counter++;
            }
        }
        cout<<endl;
    }
    
    return tableauDeck;
}

vector<cards> FlipPile(vector<cards> pile) {

}

int main() {
    
    srand(time(NULL));
    
    vector<cards> myDeck(52);
    
    //initialize card color in the deck
    for(int i=0; i<2; i++) {
        for(int j=(26*i); j<(26*2); j++){
            myDeck[j].setColor(i);
        }
    }
    
    //initialize card number and type in the deck
    for(int i=0;i<13;i++) {
        myDeck[i].setNum(i+1);
        myDeck[i].setType(0);
    }
    
    for(int i=13;i<26;i++) {
        myDeck[i].setNum(i-12);
        myDeck[i].setType(1);
    }
    
    for(int i=26;i<39;i++) {
        myDeck[i].setNum(i-25);
        myDeck[i].setType(2);
    }
    
    for(int i=39;i<52;i++) {
        myDeck[i].setNum(i-38);
        myDeck[i].setType(3);
    }
    
    //place 28 cards randomly on the tableau
    Tableau(myDeck,0);
    
    //int num;
    cout<<"Flip the pile? ";
    //cin >> num;

    return 0;
}

