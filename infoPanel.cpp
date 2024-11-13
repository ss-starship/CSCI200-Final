#include "infoPanel.h"
#include <iostream>

using namespace std;
using namespace sf;

InfoPanel::InfoPanel(){
    _textbox.setPosition(Vector2f(0,0));
    _textbox.setCharacterSize(25);
    _textbox.setFillColor(Color::White);

    // FONT
    _font.loadFromFile("Lato-Regular.ttf");
    if (!_font.loadFromFile("Lato-Regular.ttf")){
        cerr << "Error opening text file" << endl;
    }
    _textbox.setFont(_font);
    // FONT OVER

    _textbox.setString("");
}

void InfoPanel::setPostion(int x, int y){
    _textbox.setPosition(Vector2f(x,y));
}

void InfoPanel::setText(string text){
    _text = text;
    _textbox.setString(_text);
}

void InfoPanel::setColor(Color color){
    _textbox.setFillColor(color);
}

void InfoPanel::draw(RenderWindow& window) const {
    window.draw(_textbox);
}
