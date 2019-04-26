#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>
#include <stdlib.h>
//#include <conio.h>
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
    
    int getType() {
        if(type == "spades")
            return 1;
        else if(type == "clubs")
            return 2;
        else if(type == "heart")
            return 3;
        else if(type == "diamonds")
            return 4;
        else
            return 0;
    }
    
    int getNum() {
        return num;
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

vector<cards> MakePile(vector<cards> &pile, vector<cards> myDeck, vector<cards> tableauDeck, int opt) {
    
    
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
    
    return pile;
}

void ShowPile(vector<cards> &pile, int pos) {
    cout<<"Pile: ";
    
    for(int i=0;i<pile.size();i++) {
        if(i==(pos%24)) {
            cout<<pile.at(i);
            pile.at(i).isFlipped = true;
        }
        else {
            cout<<" * ";
            pile.at(i).isFlipped = false;
        }
    }

    /*
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
     */
}

vector<cards> Tableau(vector<cards> myDeck, vector<cards> &row1, vector<cards> &row2, vector<cards> &row3, vector<cards> &row4, vector<cards> &row5, vector<cards> &row6, vector<cards> &row7) {
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
    
    /*
    //show the Tableau -- CHECK ONLY
    for(int i=0;i<28;i++)
        tableauDeck[i].display();
    
    cout<<endl<<endl;
    */
    
    /*
    //arrange the cards on the tableau -- NOT REQUIRED
    int counter=0;
    
    for (int r=0;r<7;r++){
        for(int c=0;c<=r;c++){
            columns[r][c] = tableauDeck.at(counter);
            counter++;
        }
    }
    */
    
    //first time setup for the tableau
    int i=0;
    for(i=0;i<1;i++)
        row1.at(i) = tableauDeck.at(i);
    row1.at(0).isFlipped = true;
    
    for(i=0;i<2;i++)
        row2.at(i) = tableauDeck.at(i+1);
    row2.at(1).isFlipped = true;
    
    for(i=0;i<3;i++)
        row3.at(i) = tableauDeck.at(i+3);
    row3.at(2).isFlipped = true;
    
    for(i=0;i<4;i++)
        row4.at(i) = tableauDeck.at(i+6);
    row4.at(3).isFlipped = true;
    
    for(i=0;i<5;i++)
        row5.at(i) = tableauDeck.at(i+10);
    row5.at(4).isFlipped = true;
    
    for(i=0;i<6;i++)
        row6.at(i) = tableauDeck.at(i+15);
    row6.at(5).isFlipped = true;
    
    for(i=0;i<7;i++)
        row7.at(i) = tableauDeck.at(i+21);
    row7.at(6).isFlipped = true;
    
    /*  ALTERNATE WAY OF PRINTING -- NOT REQUIRED
    //cout<<endl<<endl;
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
    */
    
    int j = 0;
    
    for(j=0;j<1;j++) {
        if(row1.at(j).isFlipped == true)
            cout<<row1.at(j);
        else
            cout<<" * ";
    }
    cout<<endl;
    
    for(j=0;j<2;j++) {
        if(row2.at(j).isFlipped == true)
            cout<<row2.at(j);
        else
            cout<<" * ";
    }
    cout<<endl;
    
    for(j=0;j<3;j++) {
        if(row3.at(j).isFlipped == true)
            cout<<row3.at(j);
        else
            cout<<" * ";
    }
    cout<<endl;
    
    for(j=0;j<4;j++) {
        if(row4.at(j).isFlipped == true)
            cout<<row4.at(j);
        else
            cout<<" * ";
    }
    cout<<endl;
    
    for(j=0;j<5;j++) {
        if(row5.at(j).isFlipped == true)
            cout<<row5.at(j);
        else
            cout<<" * ";
    }
    cout<<endl;
    
    for(j=0;j<6;j++) {
        if(row6.at(j).isFlipped == true)
            cout<<row6.at(j);
        else
            cout<<" * ";
    }
    cout<<endl;
    
    for(j=0;j<7;j++) {
        if(row7.at(j).isFlipped == true)
            cout<<row7.at(j);
        else
            cout<<" * ";
    }
    cout<<endl;
    
    return tableauDeck;
}

void MoveCard(vector<cards> &row_init, int element, vector<cards> &row_fin) {
    int counter = 0;
    int size = row_fin.size()-1;
    if(element > row_init.size())
        cout<<"\n\nCARD SELECTION OUT OF RANGE. TRY AGAIN.\n\n";
    
    
    else if(row_init.at(element).isFlipped==true) {     //CHECK IF THE NUMBER BEING ADDED IS ONE LOWER THAN THE PREVIOUS ONE
        if(row_fin.at(size).getNum() - row_init.at(element).getNum()==1) {
            for(int i=element; i<row_init.size();i++) {
                row_fin.push_back(row_init.at(i));
                counter +=1;
            }
            //row_fin.resize(row_fin.size()+1); -- NOT REQUIRED
            row_init.resize(row_init.size()-counter);
            int i;
            for(i=0;i<row_init.size();i++);
            if(row_init.size()!=0)
                row_init.at(i-1).isFlipped = true;
        }
        else
            cout<<"\n\nCANNOT PLACE THE CARD THERE. TRY AGAIN.\n\n";
    }
    
    else if(row_init.at(element).isFlipped==false)
        cout<<"\n\nAll cards in the selected range are not flipped. TRY AGAIN.\n\n";
}

void showTableau(vector<cards> &row1, vector<cards> &row2, vector<cards> &row3, vector<cards> &row4, vector<cards> &row5, vector<cards> &row6, vector<cards> &row7) {
    int j = 0;
    
    for(j=0;j<row1.size();j++) {
        if(row1.at(j).isFlipped == true)
            cout<<row1.at(j);
        else
            cout<<" * ";
    }
    cout<<endl;
    
    for(j=0;j<row2.size();j++) {
        if(row2.at(j).isFlipped == true)
            cout<<row2.at(j);
        else
            cout<<" * ";
    }
    cout<<endl;
    
    for(j=0;j<row3.size();j++) {
        if(row3.at(j).isFlipped == true)
            cout<<row3.at(j);
        else
            cout<<" * ";
    }
    cout<<endl;
    
    for(j=0;j<row4.size();j++) {
        if(row4.at(j).isFlipped == true)
            cout<<row4.at(j);
        else
            cout<<" * ";
    }
    cout<<endl;
    
    for(j=0;j<row5.size();j++) {
        if(row5.at(j).isFlipped == true)
            cout<<row5.at(j);
        else
            cout<<" * ";
    }
    cout<<endl;
    
    for(j=0;j<row6.size();j++) {
        if(row6.at(j).isFlipped == true)
            cout<<row6.at(j);
        else
            cout<<" * ";
    }
    cout<<endl;
    
    for(j=0;j<row7.size();j++) {
        if(row7.at(j).isFlipped == true)
            cout<<row7.at(j);
        else
            cout<<" * ";
    }
    cout<<endl<<endl;
}

void Use_Pile(vector<cards> &pile, vector<cards> &target) {
    for(int i=0;i<pile.size();i++) {
        if(pile.at(i).isFlipped==true) {
            target.push_back(pile.at(i));
            pile.erase(pile.begin()+i);
        }
    }
}

void Edit_Bin(vector<cards> &bin, vector<cards> &row) {
    
    int size_b, size,i;
    
    for(i=0;i<row.size();i++);
    size = i-1;
    for(i=0;i<bin.size();i++);
    size_b = i-1;
    
    if(bin.size()==0) {
        if(row.at(size).getNum()==1) {
            bin.push_back(row.at(size));
            row.erase(row.begin()+size);
            row.at(size-1).isFlipped=true;
        }
    }
    else if(bin.size()!=0 && (bin.at(size_b).getNum() - row.at(size).getNum() == 1) && bin.at(size_b).getType() == row.at(size).getType()) {
        bin.push_back(row.at(size));
    }
    else
        cout<<"\n\nCannot be put in the bin\n\n";
     
}

void show_Bins(vector<cards> &bin1, vector<cards> &bin2, vector<cards> &bin3, vector<cards> &bin4) {
    
    cout<<"\n\nBIN1: \n";
    for(int i=0;i<bin1.size();i++)
        cout<<bin1.at(i);
    
    cout<<"\nBIN2: \n";
    for(int i=0;i<bin2.size();i++)
        cout<<bin2.at(i);
    
    cout<<"\nBIN3: \n";
    for(int i=0;i<bin3.size();i++)
        cout<<bin3.at(i);
    
    cout<<"\nBIN4: \n";
    for(int i=0;i<bin4.size();i++)
        cout<<bin4.at(i);
    
    cout<<endl;
}

void pileToBin(vector<cards> &pile, vector<cards> &bin) {
    for(int i=0;i<pile.size();i++) {
        if(pile.at(i).isFlipped==true) {
            bin.push_back(pile.at(i));
            pile.erase(pile.begin()+i);
        }
    }
}


void main_Game() {
    int opt, pos=-1, row_pile, bin, bin_pile;
    int element, row_init, row_fin, row_bin;
RESTART:
    vector<cards> startingDeck(52);
    vector<cards> tableauDeck(52);
    
    vector<cards> pile(24);
    vector<cards> row1(1);
    vector<cards> row2(2);
    vector<cards> row3(3);
    vector<cards> row4(4);
    vector<cards> row5(5);
    vector<cards> row6(6);
    vector<cards> row7(7);
    
    vector<cards> bin1(0);
    vector<cards> bin2(0);
    vector<cards> bin3(0);
    vector<cards> bin4(0);
    
    //initialize card color in the deck
    for(int i=0; i<2; i++) {
        for(int j=(26*i); j<(26*2); j++){
            startingDeck[j].setColor(i);
        }
    }
    
    //initialize card number and type in the deck
    for(int i=0;i<13;i++) {
        startingDeck[i].setNum(i+1);
        startingDeck[i].setType(0);
    }
    
    for(int i=13;i<26;i++) {
        startingDeck[i].setNum(i-12);
        startingDeck[i].setType(1);
    }
    
    for(int i=26;i<39;i++) {
        startingDeck[i].setNum(i-25);
        startingDeck[i].setType(2);
    }
    
    for(int i=39;i<52;i++) {
        startingDeck[i].setNum(i-38);
        startingDeck[i].setType(3);
    }
    
    //place 28 cards randomly on the tableau
    tableauDeck = Tableau(startingDeck, row1, row2, row3, row4, row5, row6, row7);
    
    cout<<endl;
    
    //Show the pile
    MakePile(pile, startingDeck, tableauDeck, 0);
    ShowPile(pile, pos);
    show_Bins(bin1, bin2, bin3, bin4);
    cout<<endl;
    
    //`     showTableau(row1, row2, row3, row4, row5, row6, row7);
    
    do{
        cout<<"\n 1 : MOVE CARD\n 2 : REVEAL NEXT FROM PILE\n 3 : USE CARD FROM PILE ON TABLEAU\n 4 : PUT CARD FROM PILE TO BIN\n 5 : ADD CARD TO A BIN\n 6 : RESTART\n 7 : EXIT\n";
        cin>>opt;
        //opt = _getchar();
        //system("CLS");
        if(opt==6) {
            pos = -1;
            cout<<"\nRESTARED\n\n";
            goto RESTART;
        }
        
        else if(opt==2) {
            pos+=1;
            
            showTableau(row1, row2, row3, row4, row5, row6, row7);
            ShowPile(pile, pos);
            show_Bins(bin1, bin2, bin3, bin4);
        }
        
        else if(opt==4) {
            cout<<"Choose bin: ";
            cin>>bin_pile;
            
            if(bin_pile==1)
                pileToBin(pile, bin1);
            if(bin_pile==2)
                pileToBin(pile, bin2);
            if(bin_pile==3)
                pileToBin(pile, bin3);
            if(bin_pile==4)
                pileToBin(pile, bin4);
            
            showTableau(row1, row2, row3, row4, row5, row6, row7);
            ShowPile(pile, pos);
            show_Bins(bin1, bin2, bin3, bin4);
        }
        
        else if(opt==5) {
            cout<<"Choose BIN: ";
            cin>>bin;
            
            cout<<"Choose row where the card lies: ";
            cin>>row_bin;
            
            if(bin==1 && row_bin==1)
                Edit_Bin(bin1, row1);
            else if(bin==1 && row_bin==2)
                Edit_Bin(bin1, row2);
            else if(bin==1 && row_bin==3)
                Edit_Bin(bin1, row3);
            else if(bin==1 && row_bin==4)
                Edit_Bin(bin1, row4);
            else if(bin==1 && row_bin==5)
                Edit_Bin(bin1, row5);
            else if(bin==1 && row_bin==6)
                Edit_Bin(bin1, row6);
            else if(bin==1 && row_bin==7)
                Edit_Bin(bin1, row7);
            
            else if(bin==2 && row_bin==1)
                Edit_Bin(bin2, row1);
            else if(bin==2 && row_bin==2)
                Edit_Bin(bin2, row2);
            else if(bin==2 && row_bin==3)
                Edit_Bin(bin2, row3);
            else if(bin==2 && row_bin==4)
                Edit_Bin(bin2, row4);
            else if(bin==2 && row_bin==5)
                Edit_Bin(bin2, row5);
            else if(bin==2 && row_bin==6)
                Edit_Bin(bin2, row6);
            else if(bin==2 && row_bin==7)
                Edit_Bin(bin2, row7);
            
            else if(bin==3 && row_bin==1)
                Edit_Bin(bin3, row1);
            else if(bin==3 && row_bin==2)
                Edit_Bin(bin3, row2);
            else if(bin==3 && row_bin==3)
                Edit_Bin(bin3, row3);
            else if(bin==3 && row_bin==4)
                Edit_Bin(bin3, row4);
            else if(bin==3 && row_bin==5)
                Edit_Bin(bin3, row5);
            else if(bin==3 && row_bin==6)
                Edit_Bin(bin3, row6);
            else if(bin==3 && row_bin==7)
                Edit_Bin(bin3, row7);
            
            else if(bin==4 && row_bin==1)
                Edit_Bin(bin4, row1);
            else if(bin==4 && row_bin==2)
                Edit_Bin(bin4, row2);
            else if(bin==4 && row_bin==3)
                Edit_Bin(bin4, row3);
            else if(bin==4 && row_bin==4)
                Edit_Bin(bin4, row4);
            else if(bin==4 && row_bin==5)
                Edit_Bin(bin4, row5);
            else if(bin==4 && row_bin==6)
                Edit_Bin(bin4, row6);
            else if(bin==4 && row_bin==7)
                Edit_Bin(bin4, row7);
            
            showTableau(row1, row2, row3, row4, row5, row6, row7);
            ShowPile(pile, pos);
            show_Bins(bin1, bin2, bin3, bin4);

        }
        
        else if(opt==3) {
            cout<<"Enter the row where you want to place the card: ";
            cin>>row_pile;
            
            if(row_pile == 1)
                Use_Pile(pile, row1);
            else if(row_pile == 2)
                Use_Pile(pile, row2);
            else if(row_pile == 3)
                Use_Pile(pile, row3);
            else if(row_pile == 4)
                Use_Pile(pile, row4);
            else if(row_pile == 5)
                Use_Pile(pile, row5);
            else if(row_pile == 6)
                Use_Pile(pile, row6);
            else if(row_pile == 7)
                Use_Pile(pile, row7);
            
            showTableau(row1, row2, row3, row4, row5, row6, row7);
            ShowPile(pile, pos);
            show_Bins(bin1, bin2, bin3, bin4);
        }
        
        else if(opt==1) {
            //moving a card on the tableau
            cout<<"\nRow number and card position of the card PICKED: ";
            cin>>row_init>>element;
            
            cout<<"\nRow where the picked card will be PLACED: ";
            cin>>row_fin;
            
            
            //CAN MAKE INTO A NEW FUNCTION -- CALLING TO CHANGE LOCATION OF CARDS
            if(row_init==1 && row_fin==2)
                MoveCard(row1, element, row2);
            else if(row_init==1 && row_fin==3)
                MoveCard(row1, element, row3);
            else if(row_init==1 && row_fin==4)
                MoveCard(row1, element, row4);
            else if(row_init==1 && row_fin==5)
                MoveCard(row1, element, row5);
            else if(row_init==1 && row_fin==6)
                MoveCard(row1, element, row6);
            else if(row_init==1 && row_fin==7)
                MoveCard(row1, element, row7);
            
            else if(row_init==2 && row_fin==1)
                MoveCard(row2, element, row1);
            else if(row_init==2 && row_fin==3)
                MoveCard(row2, element, row3);
            else if(row_init==2 && row_fin==4)
                MoveCard(row2, element, row4);
            else if(row_init==2 && row_fin==5)
                MoveCard(row2, element, row5);
            else if(row_init==2 && row_fin==6)
                MoveCard(row2, element, row6);
            else if(row_init==2 && row_fin==7)
                MoveCard(row2, element, row7);
            
            else if(row_init==3 && row_fin==1)
                MoveCard(row3, element, row1);
            else if(row_init==3 && row_fin==2)
                MoveCard(row3, element, row2);
            else if(row_init==3 && row_fin==4)
                MoveCard(row3, element, row4);
            else if(row_init==3 && row_fin==5)
                MoveCard(row3, element, row5);
            else if(row_init==3 && row_fin==6)
                MoveCard(row3, element, row6);
            else if(row_init==3 && row_fin==7)
                MoveCard(row3, element, row7);
            
            else if(row_init==4 && row_fin==1)
                MoveCard(row4, element, row1);
            else if(row_init==4 && row_fin==3)
                MoveCard(row4, element, row3);
            else if(row_init==4 && row_fin==2)
                MoveCard(row4, element, row2);
            else if(row_init==4 && row_fin==5)
                MoveCard(row4, element, row5);
            else if(row_init==4 && row_fin==6)
                MoveCard(row4, element, row6);
            else if(row_init==4 && row_fin==7)
                MoveCard(row4, element, row7);
            
            else if(row_init==5 && row_fin==1)
                MoveCard(row5, element, row1);
            else if(row_init==5 && row_fin==3)
                MoveCard(row5, element, row3);
            else if(row_init==5 && row_fin==4)
                MoveCard(row5, element, row4);
            else if(row_init==5 && row_fin==2)
                MoveCard(row5, element, row2);
            else if(row_init==5 && row_fin==6)
                MoveCard(row5, element, row6);
            else if(row_init==5 && row_fin==7)
                MoveCard(row5, element, row7);
            
            else if(row_init==6 && row_fin==1)
                MoveCard(row6, element, row1);
            else if(row_init==6 && row_fin==3)
                MoveCard(row6, element, row3);
            else if(row_init==6 && row_fin==4)
                MoveCard(row6, element, row4);
            else if(row_init==6 && row_fin==5)
                MoveCard(row6, element, row5);
            else if(row_init==6 && row_fin==2)
                MoveCard(row6, element, row2);
            else if(row_init==6 && row_fin==7)
                MoveCard(row6, element, row7);
            
            else if(row_init==7 && row_fin==1)
                MoveCard(row7, element, row1);
            else if(row_init==7 && row_fin==3)
                MoveCard(row7, element, row3);
            else if(row_init==7 && row_fin==4)
                MoveCard(row7, element, row4);
            else if(row_init==7 && row_fin==5)
                MoveCard(row7, element, row5);
            else if(row_init==7 && row_fin==6)
                MoveCard(row7, element, row6);
            else if(row_init==7 && row_fin==2)
                MoveCard(row7, element, row2);
            
            showTableau(row1, row2, row3, row4, row5, row6, row7);
            ShowPile(pile, pos);
            show_Bins(bin1, bin2, bin3, bin4);
            cout<<endl;
            //system('cls');
        }
        else if(opt==7)
            exit(0);
        
    }while(1);
}
int main() {
    
    srand(time(NULL));
    main_Game();
    
    //int num;
    //cout<<"Flip the pile? ";
    //cin >> num;

    return 0;
}


/*
 
 //IF GOTO FAILS TO RESTART, USE THIS
 
 vector<cards> startingDeck(52);
 vector<cards> tableauDeck(52);
 vector<cards> pile(24);
 vector<cards> row1(1);
 vector<cards> row2(2);
 vector<cards> row3(3);
 vector<cards> row4(4);
 vector<cards> row5(5);
 vector<cards> row6(6);
 vector<cards> row7(7);
 //initialize card color in the deck
 for(int i=0; i<2; i++) {
 for(int j=(26*i); j<(26*2); j++){
 startingDeck[j].setColor(i);
 }
 }
 
 //initialize card number and type in the deck
 for(int i=0;i<13;i++) {
 startingDeck[i].setNum(i+1);
 startingDeck[i].setType(0);
 }
 
 for(int i=13;i<26;i++) {
 startingDeck[i].setNum(i-12);
 startingDeck[i].setType(1);
 }
 
 for(int i=26;i<39;i++) {
 startingDeck[i].setNum(i-25);
 startingDeck[i].setType(2);
 }
 
 for(int i=39;i<52;i++) {
 startingDeck[i].setNum(i-38);
 startingDeck[i].setType(3);
 }
 
 //place 28 cards randomly on the tableau
 tableauDeck = Tableau(startingDeck, row1, row2, row3, row4, row5, row6, row7);
 
 cout<<endl;
 
 //Show the pile
 MakePile(startingDeck, tableauDeck, 0);
 ShowPile(pile, pos);
 cout<<endl;
 
 showTableau(row1, row2, row3, row4, row5, row6, row7);
 */
