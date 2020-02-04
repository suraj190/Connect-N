//
// Created by Suraj M on 2/8/19.
//

#ifndef NCURSESCONNECTN_MOVE_H
#define NCURSESCONNECTN_MOVE_H
#include <stdbool.h>
#include "cursorTrackWindow.h"
#include "board.h"

typedef struct Board_Struct Board;

typedef enum{Player1 = 0, Player2 = 1}TurnType;

typedef struct Move_Struct{
    int row, col;
    char marker;
    char marker2;
}Move;




Move getValidMove(struct Board_Struct* board, TurnType playerTurn, cursorTrackWindow* playWin, cursorTrackWindow* boardWin,FILE* f);
bool isValidMove(Move move,  struct Board_Struct* board, int numArgsRead, int numArgsNeeded);
const char* PlayerToString(TurnType player);

#endif //NCURSESCONNECTN_MOVE_H
