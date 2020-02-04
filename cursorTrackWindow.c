//
// Created by Suraj M on 2/7/19.
//

#include "cursorTrackWindow.h"

cursorTrackWindow newCursorTrackedWindow(int numRows, int numCols, int rowStart, int colStart){
    cursorTrackWindow window;
    window.cursesWin = newwin(numRows, numCols, rowStart, colStart);
    window.cursorRow = 0;
    window.cursorCol = 0;
    return window;
}

/**
 * Doesn't advance the cursor
 * @param win
 * @param fillChar
 */

void fillPlayWindow(cursorTrackWindow* win, char fillChar){

    int curRow = win->cursorRow, curCol = win->cursorCol;

    //mvwaddch(win->cursesWin,curRow,curCol,' ');
    //wmove(win->cursesWin,curRow,curCol);
    mvwaddch(win->cursesWin,curRow,curCol,fillChar);
    wmove(win->cursesWin,curRow,curCol);
}

void fillWindow(cursorTrackWindow* win, char fillChar){
    int curRow = win->cursorRow, curCol = win->cursorCol;
    for (int i = 0; i < getNumRows(win); ++i) {
        for (int j = 0; j < getNumCols(win); ++j) {
            mvwaddch(win->cursesWin, i, j, fillChar);
        }
    }
    wmove(win->cursesWin, curRow, curCol);
}

int getNumRows(cursorTrackWindow* win){
    return getmaxy(win->cursesWin);
}
int getNumCols(cursorTrackWindow* win){
    return getmaxx(win->cursesWin);
}

void moveAndAddCharacter(cursorTrackWindow* win, int row, int col, char toAdd) {
    mvwaddch(win->cursesWin, row, col, toAdd);
    win->cursorRow = row;
    win->cursorCol = col;
}

void addCharacter(cursorTrackWindow* win, char toAdd) {
    moveAndAddCharacter(win, win->cursorRow, win->cursorCol, toAdd);
}

void cursorTrackedWindowMove(cursorTrackWindow* win, int row, int col) {
    wmove(win->cursesWin, row, col);
    win->cursorRow = row;
    win->cursorCol = col;
}
