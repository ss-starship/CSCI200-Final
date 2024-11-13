#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <SFML/Graphics.hpp>
#include <iostream>

// Defining keys to access textboxes
#define DELETE_KEY 8
#define ENTER_KEY 13

class Textbox {
    public: 
        /**
         * @brief Construct a new Textbox object with
         * font Lato, font size 30, font color black
         * 
         * @param x - x of position
         * @param y - y of position
         */
        Textbox(int x, int y);

        /**
         * @brief Set the text color
         * 
         * @param color - what to set text to
         */
        void setTextColor(sf::Color color);

        /**
         * @brief Get the Text object
         * 
         * @return std::string - returns _text
         */
        std::string getText() const;

        /**
         * @brief Set the string of the text box
         * 
         * @param text - what to display
         */
        void setText(std::string text);

        /**
         * @brief Set the status of object
         * 
         * @param sel - instead of toggling, takes in status
         */
        void setSelected(bool sel);

        /**
         * @brief draws object to window
         * 
         * @param window - the window to draw to
         */
        void draw(sf::RenderWindow& window) const;

        /**
         * @brief handles event to update text (processes input and acts accordingly)
         * 
         * @param input - type of event being passed in (the value of key pressed)
         */
        void typedIn(sf::Event input);

    private:
        sf::Text _textbox; // text display object
        std::string _text; // user input storage 
        sf::Font _font; // font of text box
        bool _isSelected; // allows the box to be typed in while true

        /**
         * @brief updates _text
         * 
         * @param charIn - user input passed in to add to string _text
         */
        void inputText(int charIn);

        /**
         * @brief deletes last char when called
         * 
         */
        void deleteLastChar();
};

#endif