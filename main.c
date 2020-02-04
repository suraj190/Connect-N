#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include "cursorTrackWindow.h"
#include "board.h"
#include "win.h"
#include "move.h"





int main(int argc, char** argv) {

//  int dummy;
//  printf("Waiting to debug");
//  scanf("%d",&dummy);

    initscr();
    noecho();
    cbreak();

    int num_rows = atoi(argv[1]);
    int num_cols = atoi(argv[2]);
    int num_pieces_to_win = atoi(argv[3]);
    char* file_path = argv[4];

    FILE* f = fopen(file_path,"w");




    cursorTrackWindow boardWindow = newCursorTrackedWindow(num_rows, num_cols, 1, 0);
    fillWindow(&boardWindow, '*');
    wrefresh(boardWindow.cursesWin);

    cursorTrackWindow playWindow = newCursorTrackedWindow(1,num_cols,0,0);
    keypad(playWindow.cursesWin, true);
    wrefresh(playWindow.cursesWin);

    cursorTrackWindow resultWindow = newCursorTrackedWindow(1,13,num_rows+1,0);
    wrefresh(resultWindow.cursesWin);



    Board board = makeBoard(num_rows,num_cols,'*',num_pieces_to_win); //important


    TurnType playerTurn = Player1;

    fillPlayWindow(&playWindow,'X');



   while(!isGameOver(board)){




        Move move = getValidMove(&board, playerTurn, &playWindow,&boardWindow,f);




        //place their move on the board
        placeMove(move, &board, &boardWindow,&playWindow,f);

        //logFile(f,&playWindow,&boardWindow);



        playerTurn = playerTurn == Player1 ? Player2 : Player1;

   }


    int k = playWindow.cursorCol;

    char c = mvwinch(playWindow.cursesWin,playWindow.cursorRow,playWindow.cursorCol)%A_ATTRIBUTES;
    fprintf(f,"%*s%c",k,"",c);


    fprintf(f,"\n");

    for (int row = 0; row < getNumRows(&boardWindow); ++row) {

        for (int col = 0; col < getNumCols(&boardWindow); ++col) {

            char c =  mvwinch(boardWindow.cursesWin,row,col)%A_ATTRIBUTES;
            fprintf(f,"%c", c);
        }
        fprintf(f,"\n");
    }





   // logFile(f,&playWindow,&boardWindow);




    printBoard(board);

    declareWinner(board,playerTurn,resultWindow.cursesWin,f);

    wmove(playWindow.cursesWin,playWindow.cursorRow,playWindow.cursorCol);

    wrefresh(boardWindow.cursesWin);
    wrefresh(playWindow.cursesWin);
    wrefresh(resultWindow.cursesWin);

    delwin(boardWindow.cursesWin);
    delwin(playWindow.cursesWin);
    delwin(resultWindow.cursesWin);

    endwin();

    cleanUpBoard(&board);






    return 0;


}
