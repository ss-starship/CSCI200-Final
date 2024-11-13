#ifndef CUSTCOLOR_H
#define CUSTCOLOR_H

#include <vector>
#include <fstream>
#include <iomanip>
#include <SFML/Graphics.hpp>

#include "custColorInterface.h"

class CustColor : public CustColorInterface{
    public:
        /**
         * @brief Construct a new Custom Color object
         * 
         */
        CustColor();

        /**
         * @brief using protected variables to create a Color Object
         * 
         * @return sf::Color 
         */
        sf::Color makeColor() const override;
        /**
         * @brief Set the protected RGB values of the CustColor object
         * 
         * @param r - red
         * @param g - green
         * @param b - blue
         */
        void setColor(int r, int g, int b) override;
        /**
         * @brief prints out to our file
         * 
         * @param out - file to print out to
         * @param correct - checks if should print 
         */
        void writeColor(std::ofstream& out, bool correct) const override;

        /**
         * @brief Get the Guess Count object
         * 
         * @return std::string (converts int to string for output)
         */
        std::string getGuessCount() const override;
        /**
         * @brief Set the Guess Count object
         * 
         * @param guess - int to set the variable to
         */
        void setGuessCount(int guess) override;
        /**
         * @brief increase guessCount by 1
         * 
         */
        void addGuess() override;
        /**
         * @brief write out average guess once at end
         * 
         * @param out - file to write to
         */
        void writeStats(std::ofstream& out) const override;

        /**
         * @brief takes in three parameters to check if user guessed within range and determines what hint to show
         * 
         * @param rand - random color value
         * @param guess - guessed color value
         * @param color - char r,g,b used to finalize values and add details to hint
         * @return std::string 
         */
        std::string compareColor(int rand, int guess, char color) override;

        /**
         * @brief Get the Random State object
         * 
         * @return true 
         * @return false 
         */
        bool getRandomState() const override;
        /**
         * @brief Set the Random Found object
         * 
         * @param tof - bool to update value
         */
        void setRandomFound(bool tof) override;
        /**
         * @brief checks if red, green, and blue values are found and changes _randomFound
         * 
         */
        void checkIfFound() override;

        /**
         * @brief Get the random red value
         * 
         * @return int 
         */
        int getRed() const override;
        /**
         * @brief Get the random green value
         * 
         * @return int 
         */
        int getGreen() const override;
        /**
         * @brief Get the random blue value
         * 
         * @return int 
         */
        int getBlue() const override;

    protected:
        int mRed; // red value for color
        int mGreen; // green value for color
        int mBlue; // blue value for color

    private:
        bool _rFound, _gFound, _bFound; // seperate booleans for each color's found state
        bool _randomFound; // all colors' found state (true when all found)
        int _guessCount; // how many guesses the user made
        std::vector<int> _avGuess; // used to track guesses for data output
    
};

#endif