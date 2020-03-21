#include <iostream>
#include <conio.h>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#define VK_H 0x48
void generate_maze();
int player_position_row();
int player_position_column(); 
std::string maze[12][22]={{" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
                        {" ","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"," "},
                        {" ","#"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","#"," "},
                        {" ","#"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","#"," "},
                        {" ","#"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","#"," "},
                        {" ","#"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","#"," "},
                        {" ","#"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","#"," "},
                        {" ","#"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","#"," "},
                        {" ","#"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","#"," "},
                        {" ","#"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","#"," "},//8 , 19
                        {" ","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"," "},
                        {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "}};//9 , 19;


int main() {
    int moves=0,x,adder=0;
    int row,column,rowX,columnY;
    std::string answer;
    do{
        if(answer=="Y"||answer == "y"||answer == "YES"||answer == "Yes"||answer == "yes"){
            maze[row][column]=" ";
        }
    	srand(time(0));
    	for(int i = 1; i<=4;) {//generate 10 random numbers
    		x=rand()%22;
      		if (i==1&&x>1&&x<10){
                std::cout<<"asdsd\n";
      			row=x;
      			++i;
                
			  }
			else if (i==2&&x>1&&x<10&&x!=row){
      			rowX=x;
      			++i;
			  }
            else if (i==3&&x>1&&x<20){
      			column=x;
      			++i;
			  }
			else if (i==4&&x>1&&x<20&&x!=column){
      			columnY=x;
      			++i;
			  }
            else continue;
			
   		}
   		
    	maze[row][column]="<";
    	maze[rowX][columnY]="*";
    	
		do{
            generate_maze();
            row=player_position_row();
            column=player_position_column();
            if (maze[rowX][columnY]=="<"||maze[rowX][columnY]==">"||maze[rowX][columnY]=="v"||maze[rowX][columnY]=="^")
                break;
            getch();
            if(GetAsyncKeyState(VK_UP)){
                if(maze[row-1][column]=="#")
                    continue;
                ++adder;
                maze[row][column]=" ";
                maze[row-adder][column]="^";
                row=player_position_row();
                column=player_position_column();
                generate_maze();
            }

            else if(GetAsyncKeyState(VK_DOWN)){
                if(maze[row+1][column]=="#")
                    continue;
                maze[row][column]=" ";
                maze[row+1][column]="v";
                generate_maze();
                
            }   

            else if(GetAsyncKeyState(VK_LEFT)){
                if(maze[row][column-1]=="#")
                    continue;
                maze[row][column]=" ";
                maze[row][column-1]="<";
                generate_maze();
            }

            else if(GetAsyncKeyState(VK_RIGHT)){
                if(maze[row][column+1]=="#")
                    continue;
                maze[row][column]=" ";
                maze[row][column+1]=">";
                generate_maze();
            }
            
            else
                continue;
    	}while(true);
    	std::cout<<"GAMEOVER\nWould you like to play again? (Yes[y] or No[n]):"; std::cin>>answer;	
	}while(answer == "Y"||answer == "y"||answer == "YES"||answer == "Yes"||answer == "yes");

	return 0;
}
void generate_maze(){
    system("CLS");
    for(int i=0;i<12;++i){
        for (int j=0;j<22;++j)
            std::cout<<maze[i][j];
        std::cout<<"\n";
    }
}
int player_position_row(){
    for(int i=0;i<12;++i){
        for (int j=0;j<22;++j)
            if(maze[i][j]=="<"||maze[i][j]==">"||maze[i][j]=="v"||maze[i][j]=="^")
                return i;
    }
}
int player_position_column(){
    for(int i=0;i<12;++i){
        for (int j=0;j<22;++j)
            if(maze[i][j]=="<"||maze[i][j]==">"||maze[i][j]=="v"||maze[i][j]=="^")
                return j;
    }
}