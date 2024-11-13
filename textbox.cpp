#include "textbox.h"


using namespace sf;
using namespace std;

Textbox::Textbox(int x, int y){
    _textbox.setPosition(Vector2f(x,y));
    _textbox.setCharacterSize(30);
    _textbox.setFillColor(Color::Black);
    _isSelected = false;
    // FONT
    _font.loadFromFile("Lato-Regular.ttf");
    if (!_font.loadFromFile("Lato-Regular.ttf")){
        cerr << "Error opening text file" << endl;
    }
    _textbox.setFont(_font);
    // FONT OVER
    _text = "";
}

void Textbox::setTextColor(Color color){
    _textbox.setFillColor(color);
}

string Textbox::getText() const {
    return _text;
}

void Textbox::setText(string text){
    _text = text;
    _textbox.setString(_text);
}

void Textbox::setSelected(bool sel){
    _isSelected = sel;

    if (_isSelected == false){
        string currT = _text;
        string edited = "";
        for (size_t i = 0; i < currT.length(); i++){
            edited += currT.at(i);
        }
        _text = edited;
        _textbox.setString(edited);
    } else {
        _textbox.setString(_text + "_");
    }
}

void Textbox::draw(RenderWindow& window) const {
    window.draw(_textbox);
}

void Textbox::typedIn(Event input) {
    if (_isSelected == true){
        int charIn = input.text.unicode;
        if ((charIn <= 57) && (charIn >= 48)){ //if a number ascii [48, 57]
            if (_text.length() < 3){ // only taking in 3 chars
                inputText(charIn);
            } 
        } else if (charIn == DELETE_KEY){
            deleteLastChar();
        }
    } // end of selected if
} // end of function

// PRIVATE MEMBER FUNCTIONS
void Textbox::inputText(int charIn){
    if (charIn != DELETE_KEY && charIn && ENTER_KEY){
        _text += ((char)(charIn));
    } else if (charIn == DELETE_KEY){
        if(_text.length() > 0){
            deleteLastChar();
        }
    }
    _textbox.setString(_text + "_");
} // end of function

void Textbox::deleteLastChar(){
    string edited = "";
    if (_text.length() > 0){ // double-checking for funsies
        for (size_t i = 0; i < _text.length()-1; i++){
            edited += _text.at(i);
        }
        _text = edited;
    }
    _textbox.setString(_text);
}

