#include "custColor.h"
#include <iostream>

using namespace sf;
using namespace std;

CustColor::CustColor(){
    mRed = 0;
    mGreen = 0;
    mBlue = 0;
    _rFound = false, _gFound = false, _bFound = false;
    _randomFound = false;
    _guessCount = 0;
    _avGuess = {};
}

Color CustColor::makeColor() const{
    Color color(mRed,mGreen,mBlue);
    return color;
}

void CustColor::setColor(int r, int g, int b) {
    // ignoring negatives as user cannot type "-"
    if (r <= 255){
        mRed = r;
    } else {
        mRed = 255;
    }
    
    if (g <= 255){
        mGreen = g;
    } else {
        mGreen = 255;
    }
    
    if (b <= 255){
        mBlue = b;
    } else {
        mBlue = 255;
    }
    
}

void CustColor::writeColor(ofstream& out, bool correct) const {
    if (!correct){ // only printed while not correctly guessed
        out << "Guess # " << left << setw(3) << _guessCount << ":  Red - " << right << setw(3) << mRed << ", Green - " << setw(3) << mGreen 
            << ", and Blue - " << setw(3) << mBlue << "." << endl;
    }
}

string CustColor::getGuessCount() const{
    return to_string(_guessCount);
}

void CustColor::setGuessCount(int guess){
    _guessCount = guess;
}

void CustColor::addGuess(){
    _guessCount++;
}

void CustColor::writeStats(ofstream& out) const {
    int size = _avGuess.size();
        int average = 0;
        for (int i = 0; i < size; i++){
            average += _avGuess.at(i);
        }
        average = average/size;
        out << "On average, it took you an average of " << average << " guesses. Good Job!" << endl;
}

string CustColor::compareColor(int rand, int guess, char color){
    string hint = ""; // generic string based on relationship with actual value
    bool found = false; // generic boolean that reassigns to color boolean
    if ((guess < 0) || (guess > 255)){
        found = false;
        hint = "Invalid input. Enter number [0-225]";
    } else if (rand == guess){
        found = true;
        hint = "Amazing job! You've guessed it exactly!";
    } else if (((rand - 5) <= guess) && (guess <= (rand + 5))){   // +- 5 inclusive
        found = true;
        hint = "Good job! You've guessed with +/- 5!";
    } else if (((rand - 5) > guess) && (guess > (rand - 20))){    // (-5, -20)
        found = false;
        hint = "Close! You're just a little small.";
    } else if (((rand + 5) < guess) && (guess < (rand + 20))){    // (5, 20)
        found = false;
        hint = "Close! You're just a little big.";
    } else if (((rand - 20) >= guess) && (guess > (rand - 50))){    // [-20, -50)
        found = false;
        hint = "Yikes! You're way too small.";
    } else if (((rand + 20) <= guess) && (guess < (rand + 50))){    // [20, 50)
        found = false;
        hint = "Yikes! You're way too big.";
    } else if (((rand - 50) >= guess) && (guess > (rand - 100))){    // [-50, -100)
        found = false;
        hint = "Egads! You're way, way too small.";
    } else if (((rand + 50) <= guess) && (guess < (rand + 100))){    // [50, 100)
        found = false;
        hint = "Egads! You're way, way too big.";
    } else if (((rand - 100) >= guess) && (guess > (rand - 255))){    // [-100, -255)
        found = false;
        hint = "Zoinks! You're way, way, way too small.";
    } else if (((rand + 100) <= guess) && (guess < (rand + 255))){    // [100, 255)
        found = false;
        hint = "Zoinks! You're way, way, way too big.";
    } 

    if (color == 'r'){
        _rFound = found;
        return ("Red Value:     " + hint);
    } else if (color == 'g'){
        _gFound = found;
        return ("Green Value: " + hint);
    } else if (color == 'b'){
        _bFound = found;
        return ("Blue Value:    " + hint);
    }
    return "Error";

}

bool CustColor::getRandomState() const {
    return _randomFound;
}
        

void CustColor::setRandomFound(bool tof) {
    _randomFound = tof;
}

void CustColor::checkIfFound() {
    if (_rFound == true && _gFound == true && _bFound == true){
        _randomFound = true;
        _avGuess.push_back(_guessCount);
    } else {
        _randomFound = false;
    }
}

int CustColor::getRed() const {
    return mRed;
}

int CustColor::getGreen() const {
    return mGreen;
}

int CustColor::getBlue() const {
    return mBlue;
}