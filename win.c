//
// Created by Suraj M on 2/8/19.
//

#include "win.h"


bool isGameOver(Board board) {
    return win(board) || tie(board);
}

bool win(Board board) {
    return horzWin(board) || vertWin(board) || diagWin(board);
}

bool horzWin(Board board) {

    int count = 0;


    if(board.num_pieces_to_win == 1){

        for(int i = 0; i < board.numRows; i++){

            for(int j = 0; j < board.numCols; j++){

                if(board.theBoard[i][j] != board.blankChar){

                    return true;
                }
            }
        }
    }

    for(int i = 0; i < board.numRows;i++){

        for(int j=0; j < board.numCols-(board.num_pieces_to_win - 1); j++){

            if(board.theBoard[i][j] != board.blankChar){

                for(int k = 0;k < board.num_pieces_to_win ;k++){

                    if(board.theBoard[i][j] == board.theBoard[i][j+k]){
                        count++;
                    }
                }
                if (count == board.num_pieces_to_win){
                    return true;

                }
                count = 0;
            }
        }
    }

    return false;
}

bool vertWin(Board board) {

    int count = 0;

    if(board.num_pieces_to_win == 1){

        for(int i = 0; i < board.numRows; i++){

            for(int j = 0; j < board.numCols; j++){

                if(board.theBoard[i][j] != board.blankChar){
                    return true;
                }
            }
        }
    }

    for(int j = 0; j < board.numCols; j++){

        for(int i = 0; i < board.numRows - (board.num_pieces_to_win-1); i++){

            if(board.theBoard[i][j] != board.blankChar){

                for(int k = 0; k < board.num_pieces_to_win;k++){

                    if(board.theBoard[i][j] == board.theBoard[i+k][j]){

                        count++;
                    }
                }

                if(count == board.num_pieces_to_win){

                    return true;
                }

                count = 0;
            }
        }
    }

    return false;
}

bool diagWin(Board board) {
    return leftDiagWin(board) || rightDiagWin(board);
}


bool leftDiagWin(Board board) {

    int count=0;

    if(board.num_pieces_to_win == 1){

        for(int i = 0; i < board.numRows; i++){

            for(int j = 0; j < board.numCols; j++){

                if(board.theBoard[i][j] != board.blankChar){

                    return true;
                }
            }
        }

    }


    for(int i = 0; i < board.numRows - board.num_pieces_to_win + 1; i++){

        for(int j = 0; j < board.numCols - board.num_pieces_to_win + 1; j++){

            if(board.theBoard[i][j] != board.blankChar){

                for(int k = 0; k < board.num_pieces_to_win - 1; k++){

                    if(board.theBoard[i][j] == board.theBoard[i + k + 1][j + k + 1]){

                        count++;
                    }

                    if(count == board.num_pieces_to_win-1){
                        return true;

                    }
                }
            }
            count = 0;
        }
    }

    return false;


}


bool rightDiagWin(Board board) {

    int count = 0;

    if(board.num_pieces_to_win == 1){

        for(int i = 0; i < board.numRows; i++){

            for(int j = 0; j < board.numCols; j++){

                if(board.theBoard[i][j] != board.blankChar){

                    return true;
                }
            }
        }

    }

    for(int i = board.numRows - board.num_pieces_to_win+2; i < board.numRows ; i++){

        for(int j = 0; j < board.numCols - board.num_pieces_to_win + 1; ++j){

            if(board.theBoard[i][j] != board.blankChar){

                for(int k = 0; k < board.num_pieces_to_win -1; ++k){

                    if(board.theBoard[i][j] == board.theBoard[i-k-1][j+k+1]){

                        count++;
                    }

                    if(count == board.num_pieces_to_win-1){

                        return true;
                    }
                }
            }
            count = 0;

        }
    }

    return false;
}

bool tie(Board board) {

    if(win(board)){
        return false;
    }

    for (int row = 0; row < board.numRows; ++row) {
        for (int col = 0; col < board.numCols; ++col) {
            if(board.theBoard[row][col] == board.blankChar){
                return false;
            }
        }
    }
    return true;
}

void declareWinner(Board board, TurnType playerTurn, WINDOW* Win,FILE* f) {
    if(win(board)){
        //if someone one it would actually be the loser's turn
        //so account for this here
        int winner = playerTurn == Player1 ? Player2 : Player1;
        winner++;

        wprintw(Win, "Player %d won!\n", winner);
        wrefresh(Win);
        fprintf(f, "Player %d won!\n",winner);

    }else{
        wprintw(Win, "Tie Game\n");
        fprintf(f, "Tie Game\n");
    }
}
