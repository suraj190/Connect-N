//
// Created by Suraj M on 2/8/19.
//

#ifndef NCURSESCONNECTN_WIN_H
#define NCURSESCONNECTN_WIN_H
#include "board.h"
#include "move.h"

bool isGameOver(Board board);
bool win(Board board);
bool horzWin(Board board);
bool vertWin(Board board);
bool diagWin(Board board);
bool leftDiagWin(Board board);
bool rightDiagWin(Board board);
bool tie(Board board);
void declareWinner(Board board, TurnType playerTurn,WINDOW* Win,FILE* f);


#endif //NCURSESCONNECTN_WIN_H
