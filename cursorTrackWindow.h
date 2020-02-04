//
// Created by Suraj M on 2/7/19.
//

#ifndef NCURSESCONNECTN_CURSORTRACKWINDOW_H
#define NCURSESCONNECTN_CURSORTRACKWINDOW_H
#include <ncurses.h>

typedef struct cursorTrackWindow_struct{

    WINDOW* cursesWin;
    int cursorRow, cursorCol;


}cursorTrackWindow;

cursorTrackWindow newCursorTrackedWindow(int numRows, int numCols, int rowStart, int colStart);
void fillWindow(cursorTrackWindow* win, char fillChar);
void fillPlayWindow(cursorTrackWindow* win, char fillChar);

int getNumRows(cursorTrackWindow* win);
int getNumCols(cursorTrackWindow* win);

void moveAndAddCharacter(cursorTrackWindow* win, int row, int col, char toAdd);
void addCharacter(cursorTrackWindow* win, char toAdd);
void cursorTrackedWindowMove(cursorTrackWindow* win, int row, int col);

#endif //NCURSESCONNECTN_CURSORTRACKWINDOW_H
