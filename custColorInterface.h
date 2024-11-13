#ifndef CUSTCOLORINTERFACE_H
#define CUSTCOLORINTERFACE_H

#include <fstream>
#include <SFML/Graphics.hpp>

class CustColorInterface {
    public:
        virtual sf::Color makeColor() const = 0;
        virtual void setColor(int r, int g, int b) = 0;
        virtual void writeColor(std::ofstream& out, bool correct) const = 0;
        virtual std::string getGuessCount() const = 0;
        virtual void setGuessCount(int guess) = 0;
        virtual void addGuess() = 0;
        virtual void writeStats(std::ofstream& out) const = 0;
        virtual std::string compareColor(int rand, int guess, char color) = 0;
        virtual bool getRandomState() const = 0;
        virtual void setRandomFound(bool tof) = 0;
        virtual void checkIfFound() = 0;
        virtual int getRed() const = 0;
        virtual int getGreen() const = 0;
        virtual int getBlue() const = 0;
};


#endif
