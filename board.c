//
// Created by Suraj M on 2/8/19.
//

#include "board.h"
#include <stdlib.h>


void logFile2(FILE* f, cursorTrackWindow* playWindow, cursorTrackWindow* boardWindow){

    //int r = playWindow->cursorRow;
    int k = playWindow->cursorCol;

    char c = mvwinch(playWindow->cursesWin,playWindow->cursorRow,playWindow->cursorCol)%A_ATTRIBUTES;
    fprintf(f,"%*s%c",k,"",c);


    fprintf(f,"\n");

    for (int row = 0; row < getNumRows(boardWindow); ++row) {

        for (int col = 0; col < getNumCols(boardWindow); ++col) {

            char c =  mvwinch(boardWindow->cursesWin,row,col)%A_ATTRIBUTES;
            fprintf(f,"%c", c);
        }
        fprintf(f,"\n");
    }

    fprintf(f,"\n");

}



Board makeBoard(int numRows, int numCols, char blankChar,int num_to_win) {
    Board board;

    board.theBoard = (char**)malloc(numRows * sizeof(char*));
    for (int i = 0; i < numRows; ++i) {
        board.theBoard[i] = (char*)malloc(numCols * sizeof(char));
        for (int j = 0; j < numCols; ++j) {
            board.theBoard[i][j] = blankChar;
        }
    }

    board.numRows = numRows;
    board.numCols = numCols;
    board.blankChar = blankChar;
    board.num_pieces_to_win = num_to_win;
    return board;
}

void printBoard(Board board) {
    //print column header
    printf("  "); //make things line up
    for (int i = 0; i < board.numCols; ++i) {
        printf("%d ", i);
    }
    printf("\n");

    for (int row = 0; row < board.numRows; ++row) {
        printf("%d ", row); //print row header
        for (int col = 0; col < board.numCols; ++col) {
            printf("%c ", board.theBoard[row][col]);
        }
        printf("\n");
    }
}

void cleanUpBoard(Board* board) {

    for (int row = 0; row < board->numRows; ++row) {
        free(board->theBoard[row]);
    }
    free(board->theBoard);
    board->theBoard = NULL;
    board->numRows = 0;
    board->numCols = 0;
}

void placeMove(Move move, Board* board, cursorTrackWindow* win,cursorTrackWindow* playWin, FILE* f) {

    for(int i =board->numRows-1; i>=0;i-- ){   // Tutored by Eric Li


        if(board->theBoard[i][move.col] == '*'){

            board->theBoard[i][move.col] = move.marker;
            win->cursorRow=i;
            win->cursorCol=move.col;
            addCharacter(win, move.marker);
            cursorTrackedWindowMove(win, win->cursorRow, win->cursorCol);
            wrefresh(win->cursesWin);

           // logFile2(f,win,playWin);


            break;
        }

        else{
            continue;
        }
    }

//    board->theBoard[move.row][move.col] = move.marker;
//    win->cursorRow=move.row;
//    win->cursorCol=move.col;
//    addCharacter(win, move.marker);
//    cursorTrackedWindowMove(win, win->cursorRow, win->cursorCol);
 //   wrefresh(win->cursesWin);
}