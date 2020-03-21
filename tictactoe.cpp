#include <iostream>
#include <cstring>
using namespace std;
void board(char input[]);
int results(char input[]);

int main()
{
    int player=1,numOfBox;
    bool flag = true;
    char  input[9]={'1','2','3','4','5','6','7','8','9'};
    char moves,num;

    for(int numMoves=0;numMoves<9;++numMoves){
        board(input);
        if (results(input)==1){
            cout<<"WINNER PLAYER "<<player;
            return 0;
        }

         if (flag == true){
            moves='X'; player=1;flag=false;
        }
        else{
            moves='O'; player=2;flag=true;
        }
    
        do{
            cout <<"Player "<<player<<": ";
            cin >>num;
            numOfBox=num-'0';
        }while(input[numOfBox-1]=='X'||input[numOfBox-1]=='O'||numOfBox<1||numOfBox>9||isdigit(num)==false);
        input[numOfBox-1]=moves;
    }

    board(input);
    cout << "DRAW.";
    return 0;
}

void board(char input[]){
    system("CLS");
    cout<<"TICTACTOE!!\n\n";
    cout <<input[0] <<" | "<< input[1] <<" | "<< input[2]<<"\n";
    cout <<"- "<<"+ "<<"- "<<"+ "<<"- \n";
    cout <<input[3] <<" | "<< input[4] <<" | "<< input[5]<<"\n";
    cout <<"- "<<"+ "<<"- "<<"+ "<<"- \n";
    cout <<input[6] <<" | "<< input[7] <<" | "<< input[8]<<"\n";
}

int results(char input[]){
    if (input[0]==input[1]&&input[1]==input[2])
        return 1;
    else if (input[3]==input[4]&&input[4]==input[5])
        return 1;
    else if (input[6]==input[7]&&input[7]==input[8])
        return 1;
    else if (input[0]==input[3]&&input[3]==input[6])
        return 1;
    else if (input[1]==input[4]&&input[4]==input[7])
        return 1;
    else if (input[2]==input[5]&&input[5]==input[8])
        return 1;
    else if (input[0]==input[4]&&input[4]==input[8])
        return 1;
    else if (input[2]==input[4]&&input[4]==input[6])
        return 1;
    return 0;
}