//
// Created by Suraj M on 2/8/19.
//
#include <ctype.h>
#include <stdio.h>
#include "inputValidation.h"


bool isValidFormat(const int numArgsRead, const int numArgsNeed) {
    bool formatIsGood = numArgsRead == numArgsNeed;
    char character;
    do{
        scanf("%c", &character);
        if(!isspace(character)){
            formatIsGood = false;
        }
    }while(character != '\n');
    return formatIsGood;
}

bool isInRange(int value, int lowerBound, int uppderBound) {
    return value >= lowerBound && value <= uppderBound;
}
