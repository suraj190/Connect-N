//
// Created by Suraj M on 2/8/19.
//

#ifndef NCURSESCONNECTN_BOARD_H
#define NCURSESCONNECTN_BOARD_H

#include "move.h"

typedef struct Move_Struct Move;

typedef struct Board_Struct{
    char** theBoard;
    int numRows;
    int numCols;
    char blankChar;
    int num_pieces_to_win;
}Board;



Board makeBoard(int numRows, int numCols, char blankChar,int num_piece_to_win);
void printBoard(Board board);
void cleanUpBoard(Board* board);

void placeMove(Move move, Board* board, cursorTrackWindow* win,cursorTrackWindow* playWin,FILE* f);
void logFile2(FILE* f, cursorTrackWindow* playWindow, cursorTrackWindow* boardWindow);

#endif //NCURSESCONNECTN_BOARD_H
