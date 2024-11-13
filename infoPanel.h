#ifndef INFOPANEL_H
#define INFOPANEL_H

#include <SFML/Graphics.hpp>
#include <iostream>

class InfoPanel {
    public:
        /**
         * @brief Construct a new Info Panel object with character size 30,
         * fill color white, font Lato, and string ""
         */
        InfoPanel();
    
        /**
         * @brief Set the Postion of the info panel
         * 
         * @param x - x value
         * @param y - y vale
         */
        void setPostion(int x, int y);

        /**
         * @brief Set the text of the info panel
         * 
         * @param text - what to display
         */
        void setText(std::string text);

        /**
         * @brief Set the color (font color) of the textbox
         * 
         * @param color - color to set to
         */
        void setColor(sf::Color color);
        
        /**
         * @brief draws object to window
         * 
         * @param window - the window to draw to
         */
        void draw(sf::RenderWindow& window) const;

    private:
        sf::Text _textbox; // text display object
        std::string _text; // user input storage 
        sf::Font _font; // font of text box
};

#endif