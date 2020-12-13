#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int comp[] = {1,2,3,4,5,6,7,8,9};
char board[4][4];
int win=0;

bool allfilled() //checks for the tie condition
{
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(board[i][j]==' ')
                return false;
        }
    }

    return true;
}
bool check(char board[][4]) // checks if anyone has won the game or not
{
    //Checking for X
    //diagonal1 X
    if(board[1][1] == board[2][2] && board[2][2]==board[3][3] && board[1][1]=='X')
    {
        win = 1;
        return true;
    }
    //Horizontal1 X
    if(board[1][1] == board[1][2] && board[1][2]==board[1][3] && board[1][1]=='X')
    {
        win = 1;
        return true;
    }
    //Vertical1 X
    if(board[1][1] == board[2][1] && board[2][1]==board[3][1] && board[1][1]=='X')
    {
        win = 1;
        return true;
    }
    //Diagonal2 X
    if(board[1][3] == board[2][2] && board[2][2]==board[3][1] && board[1][3]=='X')
    {
        win = 1;
        return true;
    }
    //Vertical2 X
    if(board[1][2] == board[2][2] && board[2][2]==board[3][2] && board[1][2]=='X')
    {
        win = 1;
        return true;
    }
    //Vertical3 X
    if(board[1][3] == board[2][3] && board[2][3]==board[3][3] && board[1][3]=='X')
    {
        win = 1;
        return true;
    }
    //Horizontal2 X
    if(board[2][1] == board[2][2] && board[2][2]==board[2][3] && board[2][1]=='X')
    {
        win = 1;
        return true;
    }
    //Horizontal3 X
    if(board[3][1] == board[3][2] && board[3][2]==board[3][3] && board[3][1]=='X')
    {
        win = 1;
        return true;
    }


    //For O now

    //diagonal1 O
    if(board[1][1] == board[2][2] && board[2][2]==board[3][3] && board[1][1]=='O')
    {
        win = 2;
        return true;
    }
    //Horizontal1 O
    if(board[1][1] == board[1][2] && board[1][2]==board[1][3] && board[1][1]=='O')
    {
        win = 2;
        return true;
    }
    //Vertical1 O
    if(board[1][1] == board[2][1] && board[2][1]==board[3][1] && board[1][1]=='O')
    {
        win = 2;
        return true;
    }
    //Diagonal2 O
    if(board[1][3] == board[2][2] && board[2][2]==board[3][1] && board[1][3]=='O')
    {
        win = 2;
        return true;
    }
    //Vertical2 O
    if(board[1][2] == board[2][2] && board[2][2]==board[3][2] && board[1][2]=='O')
    {
        win = 2;
        return true;
    }
    //Vertical3 O
    if(board[1][3] == board[2][3] && board[2][3]==board[3][3] && board[1][3]=='O')
    {
        win = 2;
        return true;
    }
    //Horizontal2 O
    if(board[2][1] == board[2][2] && board[2][2]==board[2][3] && board[2][1]=='O')
    {
        win = 2;
        return true;
    }
    //Horizontal3 O
    if(board[3][1] == board[3][2] && board[3][2]==board[3][3] && board[3][1]=='O')
    {
        win = 2;
        return true;
    }

    return false;
}

int minimax(bool maximising,char board[][4]) //decides the most optimal move
{
    //printf("%d ",tn);
    if(check(board))
    {
        if(win==1)
        {
            return -1;
        }
        if(win == 2)
        {
            return 1;
        }
    }
    if(!check(board) && allfilled())
    {
        return 0;
    }

        if(maximising)
        {
        int bestScore = -2;
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                if(board[i][j]==' ')
                {
                board[i][j] = 'O';
                int score = minimax(false,board);
                //printf("%d ",depth);
                board[i][j] = ' ';
                    if(bestScore<score)
                    {
                        bestScore = score;
                    }
                }
            }

        }
        return bestScore;
    }

    else{
        int bestScore = 2;
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                if(board[i][j]==' ')
                {
                board[i][j] = 'X';

                int score = minimax(true,board);
                board[i][j] = ' ';
                    if(bestScore>score)
                    {
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;

    }

}



void bestmove() // Fills in the computer's move
{
    //printf("%d",t);
    int bestScore = -2;
    int besti,bestj;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(board[i][j]==' ')
            {
            board[i][j] = 'O';
            int score =  minimax(false,board);
            board[i][j] = ' ';

            if(score > bestScore)
                {
                    bestScore = score;
                    besti = i;
                    bestj = j;
                }
            }
        }
    }
    //printf("%d %d ",besti,bestj);

    board[besti][bestj] = 'O';
}


void showboard() //displays the game board
{
        printf("\t\t  %c    |  %c   |  %c    \n",board[1][1],board[1][2],board[1][3]);
        printf("\t\t|      |      |      |\n");
        printf("\t\t|------|------|------|\n");
        printf("\t\t|  %c   |  %c   |  %c   |\n",board[2][1],board[2][2],board[2][3]);
        printf("\t\t|      |      |      |\n");
        printf("\t\t|------|------|------|\n");
        printf("\t\t|  %c   |  %c   |  %c   |\n",board[3][1],board[3][2],board[3][3]);
        printf("\t\t       |      |       \n");
}

int convertindex(int sp) //converts the player's index into 2D indices
{
    if(sp%3!=0)
        return sp%3;
    else
        return 3;
}


int main()
{
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            board[i][j]= ' ';
        }
    }
    int indi,indj;
    char name[100];
    int n=9;
    int spot;
    int turn = 0;
    int flag = 1;
    printf("\t \t \t \t \t \t ****TIC TAC TOE**** By Kunal Nayyar\t \t \t \t \t \t \t \t \t \nThere is no way on God's Green Earth that you can defeat this computer \n");
    printf("Enter Your Name: ");
    gets(name);
    printf("%s = X \t\t",name);
    printf("Computer = O\n");

    showboard();
    printf("\n");

    while((!check(board)) && turn!=9)
    {
        printf("Player %d's turn \n",flag);
        if(flag==1)
        {
             printf("Enter the box number (starting from 1 to 9) to place your mark  ");
             scanf("%d",&spot);

             if(spot>=1 && spot<=3)
                indi = 1;
             if(spot>=4 && spot<=6)
                indi = 2;
             if(spot>=7 && spot<=9)
                indi = 3;

             indj = convertindex(spot);
        }
        else
        {
                /*srand(time(0));
                //printf("Computer has played it's turn ");
                n--;
                spot = computer(n,spot,rand()%n);*/
                bestmove();

        }

        if((board[indi][indj]== 'X' || board[indi][indj]=='O' )&& flag == 1)
        {
           //showboard();
            printf("Change your spot, this is already filled \n");
        }
        else
        {
            if(flag==1)
            {
                board[indi][indj] = 'X';
                flag = 2;
            }
            else
            {
              // board[rec[0]][rec[1]] = 'O';
                flag = 1 ;
            }
            turn ++;
            showboard();
        }
    }

    if(turn==9 && check(board)!=true)
    {
        printf("\t\t\t\t\t ****THE MATCH IS A DRAW**** TOLD YOU SO ");
    }
    else
    {
        if(win==1)
        {
            printf("\t\t\t\t\t ****%s won the match**** %s",name);
        }
        if(win==2)
        {
            printf("\t\t\t\t\t ****Computer won the match**** TOLD YOU SO %s ",name);
        }
    }

  return 0;
}


