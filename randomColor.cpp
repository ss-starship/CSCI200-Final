#include "randomColor.h"
#include <random>
#include <ctime>

using namespace std;
using namespace sf;

RandomColor::RandomColor(){
    _redVec = {};
    _greenVec = {};
    _blueVec = {};
}

void RandomColor::makeRandomColor(){
    int randNum = 0;
    for (int i = 0; i < 3; i++){
        randNum = rand() % 256; // restricting to 0-255 (hex value range)
        switch (i) {
            case 0:
                mRed = randNum;
                //colorVec.at(i) = randNum;
                break;
            case 1:
                mGreen = randNum;
                //colorVec.at(i) = randNum;
                break;
            case 2:
                mBlue = randNum;
                //colorVec.at(i) = randNum;
                break;
        } // end switch
    } // end for loop
        _redVec.push_back(mRed);
        _greenVec.push_back(mGreen);
        _blueVec.push_back(mBlue);
} // end function


 void RandomColor::writeColor(ofstream& out, bool correct) const {
    if (correct){ // User pressed enter, and guessed correct number
        out << endl << "You've guessed it!" << endl;
    } else if (!correct) { // Use pressed S, and gave up
        out << endl << "That's quite alright! You can't get them all." << endl;
    }
    out << setw(14) << left << "Actual RGB: " << "Red - " << setw(3) << right <<  mRed << ", Green - " << setw(3) << mGreen << ", and Blue - " << setw(3) << mBlue << "." << endl;
}

void RandomColor::writeStats(ofstream& out) const {
    out << endl << "Playthrough statistics: " << endl;
    averageColor(out);
    min(out);
    max(out);
}


// PRIVATE MEMBER FUNCTIONS
void RandomColor::averageColor(ofstream& out) const {
    int size = _redVec.size(); // all vectors should be the same length
        int avRed = 0, avGreen = 0, avBlue = 0; 
        for (int i = 0; i < size; i++){
            avRed += _redVec.at(i);
            avGreen += _greenVec.at(i);
            avBlue += _blueVec.at(i);
        }
        avRed = avRed/size;
        avGreen = avGreen/size;
        avBlue = avBlue/size;

        out << setw(14) << left << "Mean RGB: " << "Red - " << setw(3) << right << avRed << ", Green - " << setw(3) << avGreen << ", and Blue - " << setw(3) << avBlue << "." << endl; 
}

void RandomColor::min(ofstream& out) const {
    int size = _redVec.size(); // all vectors should be the same length
    int minR = _redVec.at(0), minG = _greenVec.at(0), minB = _blueVec.at(0);

    for (int i = 0; i < size; i++){
        if (minR > _redVec.at(i) ){
            minR = _redVec.at(i);
        }
        if (minG > _greenVec.at(i) ){
            minG = _greenVec.at(i);
        } 
        if (minB > _blueVec.at(i) ){
            minB = _blueVec.at(i);
        }
        
    }
    //                          "Actual RGB:   "
    out << setw(14) << left <<  "Smallest RGB: " << "Red - " << setw(3) << right << minR << ", Green - " << setw(3) << minG << ", and Blue - " << setw(3) << minB << "." << endl; 
}

void RandomColor::max(ofstream& out) const{
    int size = _redVec.size(); // all vectors should be the same length
    int maxR = _redVec.at(0), maxG = _greenVec.at(0), maxB = _blueVec.at(0);

    for (int i = 0; i < size; i++){
        if (maxR < _redVec.at(i) ){
            maxR = _redVec.at(i);
        }
        if (maxG < _greenVec.at(i) ){
            maxG = _greenVec.at(i);
        } 
        if (maxB < _blueVec.at(i) ){
            maxB = _blueVec.at(i);
        }
    }
    out << setw(14) << left << "Largest RGB: " << "Red - " << setw(3) << right << maxR << ", Green - " << setw(3) << maxG << ", and Blue - " << setw(3) << maxB << "." << endl; 
}
