#include "textboxBackground.h"

using namespace sf;

TextboxBackground::TextboxBackground(int x, int y){
    _background.setPosition(x, y);
    _background.setFillColor(Color::White);
    _background.setSize(Vector2f(120, 40));

}

void TextboxBackground::setSize(int w, int h){
    _background.setSize(Vector2f(w, h));
}


void TextboxBackground::draw(RenderWindow& window) const {
    window.draw(_background);
}