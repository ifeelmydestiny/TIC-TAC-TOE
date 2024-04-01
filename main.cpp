#include <iostream>
using namespace std;
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char board1[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char player1 = 'X';
char player2 = 'Y';
char current_player = player1;
int playerX = 0;
int playerY = 0;
void clear_board()
{
    for(int x{0}; x<3; x++)
    {
        for(int y{0}; y<3; y++)
        {
            board[x][y] = board1[x][y];
        }
    }
}
void scoreboard()
{
    if(current_player==player1){playerX++;}
    else {playerY++;}
}
void display()
{
    cout<<"\n\n           TIC TAC TOE GAME            "<<endl;
    cout<<"\nPlayer [X] score: "<<playerX<< "\nPlayer [Y] score: "<<playerY<<endl;
    cout<<"\t\t        |         |   "<<endl;
    cout<<"\t\t"<<board[0][0]<<"       |    "<<board[0][1]<<"    |   "<<board[0][2]<<endl;
    cout<<"\t\t___________________________"<<endl;
    cout<<"\t\t        |         |   "<<endl;
    cout<<"\t\t"<<board[1][0]<<"       |    "<<board[1][1]<<"    |   "<<board[1][2]<<endl;
    cout<<"\t\t___________________________"<<endl;
    cout<<"\t\t        |         |   "<<endl;
    cout<<"\t\t"<<board[2][0]<<"       |    "<<board[2][1]<<"    |   "<<board[2][2]<<endl;

}
bool check_win()
{
    for(int x{0}; x<3; x++)
    {
        int y{0};
        if(board[x][y] == board[x][y+1] && board[x][y+1] == board[x][y+2])
        {
            return true;
        };
    }
    for(int y{0}; y<3; y++)
    {
        int x{0};
        if(board[x][y] == board[x+1][y] && board[x+1][y] == board[x+2][y])
        {
            return true;
        };

    }

    int x{0}, y{0};
    if(board[x][y]==board[x+1][y+1] && board[x+1][y+1]==board[x+2][y+2])
    {
        return true;
    }
    if(board[x][y+2]==board[x+1][y+1] && board[x+1][y+1]==board[x+2][y])
    {
        return true;
    }
    return false;
}
bool check_draw()
{
    int z{0};
    for(int x{0}; x<3; x++)
    {
       for( int y{0}; y<3; y++)
       {
           if(board[x][y] != board1[x][y])
           {    // if this is ture
               //game is stil on
               z++;
               if(z==9)
               {
                   z-=9;
                   return true;
               }
           }

       }

    }
    return false;
}

int main()
{
    char choice;

    bool gameover = false;

    display();

    while(gameover!= true)
    {
        cout<<"Player ["<<current_player<<"] turn:";cin>>choice;
        cout<<"\n__________________________________"<<endl;
        for(int x{0};x<3;x++)
        {
            for(int y{0};y<3;y++)
            {
                if (board[x][y] == choice)
                        {
                            board[x][y] = current_player;
                            display();
                    if (check_win()==true)
                    {
                        cout<<"PLAYER "<<current_player<<" won the game, HURRAY!"<<endl;
                        scoreboard();
                        char choice1;
                        cout<<"Wanna play again [ type 'y' for yes] :  ";cin>>choice1;
                        if(choice1 == 'y'){
                            //clear the board
                            clear_board();
                        }
                        else
                        {cout<<"OK";
                            gameover = true;}
                    }
                    if (check_draw()==true)
                    {
                        char choice2;
                        cout<<"Ohh!! its draw "<<endl;
                        cout<<"Wanna play again [ type 'y' for yes] :  ";cin>>choice2;
                        if(choice2 == 'y'){
                            //clear the board
                            clear_board();
                        }
                        else
                        {cout<<"OK";
                            gameover = true;}
                    }
                    else if (current_player == player1){current_player = player2;}
                    else if(current_player == player2){current_player = player1;}
                        }
            }
        }
    };

    return 0;
}
