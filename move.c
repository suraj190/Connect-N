//
// Created by Suraj M on 2/8/19.
//

#include "move.h"
#include "board.h"
#include "inputValidation.h"
#include "cursorTrackWindow.h"


void logFile(FILE* f, cursorTrackWindow* playWindow, cursorTrackWindow* boardWindow){

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
    fprintf(f,"\n");

}



Move getValidMove(struct Board_Struct* board, TurnType playerTurn, cursorTrackWindow* win, cursorTrackWindow* boardWin, FILE* f) {
    Move move;



    while (true) {



        move.marker2 = "XO"[playerTurn];

        fillPlayWindow(win,move.marker2);


        char input = wgetch(win->cursesWin);
        logFile(f, win, boardWin);


          if (input == 'a' /*|| input == (KEY_LEFT & A_CHARTEXT)*/ || input=='j') {



              fillPlayWindow(win,move.marker2);
              fillPlayWindow(win,' ');
             // logFile(f, win, boardWin);


              if(win->cursorCol == 0){       // if cursor is out of bounds on the left then
                  win -> cursorCol = board->numCols;   // move it to the last col on board
                  wmove(win->cursesWin,win->cursorRow,win->cursorCol);




              }


              if (win->cursorCol > 0) {
                win->cursorCol -= 1;
                wmove(win->cursesWin, win->cursorRow, win->cursorCol);
                 //logFile(f, win, boardWin);


              }

              fillPlayWindow(win,move.marker2);



        }  else if (input == 's' || input == 'k') {



              fillPlayWindow(win,move.marker2);
              fillPlayWindow(win,' ');
             // logFile(f, win, boardWin);


              if(win->cursorCol > board->numCols-2){  // if cursor is out of bounds on the right
                  win -> cursorCol = -1;              // then move the cursor to starting col on board
                  wmove(win->cursesWin,win->cursorRow,win->cursorCol);


              }


            if (win->cursorCol < board->numCols - 1) {
                win->cursorCol += 1;
                wmove(win->cursesWin, win->cursorRow, win->cursorCol);

                //logFile(f, win, boardWin);
            }


              fillPlayWindow(win,move.marker2);



        } else if ((input == ' ' || input == '\n') &&
                   board->theBoard[win->cursorRow][win->cursorCol] == board->blankChar) {




              move.row = win->cursorRow;
              move.col = win->cursorCol;


              move.marker = "XO"[playerTurn];




            return move;


        }


        wrefresh(win->cursesWin);


    }


}

bool isValidMove(Move move, struct Board_Struct* board, int numArgsRead, int numArgsNeeded) {
    return isValidFormat(numArgsRead, numArgsNeeded) &&
           isInRange(move.row, 0, board->numRows - 1) &&
           isInRange(move.col, 0, board->numCols - 1) &&
           board->theBoard[move.row][move.col] == board->blankChar;
}

const char* PlayerToString(TurnType player) {
    static const char p1[] = "Player1";
    static const char p2[] = "Player2";
    if (player == Player1) {
        return p1;
    } else {
        return p2;
    }
}
