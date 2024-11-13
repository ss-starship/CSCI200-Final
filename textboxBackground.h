#ifndef TEXTBOXBACKGROUND_H
#define TEXTBOXBACKGROUND_H

#include <SFML/Graphics.hpp>

class TextboxBackground {
    public:
        /**
         * @brief Construct a new Textbox Background object with fill
         * color white, and size (120, 40)
         * 
         * @param x - x position for background
         * @param y - y positions for background
         */
        TextboxBackground(int x, int y);

        void setSize(int w, int h);

        /**
         * @brief draws background to window
         * 
         * @param window - what to draw to
         */
        void draw(sf::RenderWindow& window) const;
        
    private:
        sf::RectangleShape _background; // RectangleShape to display
};

#endif