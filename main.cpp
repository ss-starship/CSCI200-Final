/**
 * @file main.cpp
 * @author Sarah Bunnell
 * @brief GuessTheRGBValueGame
 * @References: https://www.youtube.com/watch?v=T31MoLJws4U 
 *              ^^^ for textbox walkthrough ^^^
 * 
 * @version 0.1
 * @date 2024-04-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "custColorInterface.h"
#include "custColor.h"
#include "randomColor.h"
#include "textbox.h"
#include "textboxBackground.h"
#include "infoPanel.h"

#include <SFML/Graphics.hpp>
using namespace sf;

#include <random>
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

void startupVisuals(CircleShape* random, CircleShape* guess, Color colorRand, vector<Textbox>* textVec, vector<InfoPanel>* infoVec){

    random->setFillColor(colorRand);
    guess->setFillColor(colorRand);

    for (int i = 0; i < 3; i++){
        textVec->at(i).setSelected(false);
        textVec->at(i).setText("");
    }

    // info panels
    const int MPX = 40; // Main Panel X coordinate
    const int HPX = 320; // Half Panel X coordinate
    int currY = 580; // starting y 580, small spacer 30, large spacer 50

    // STARTING STRINGS
    const string S1 = "Welcome to Guess The RGB Value game."; 
    const string S2 = "To enter your values, press R to enter red,";
    const string S3 = "G for green, B for blue, and Enter to sumbit.";
    const string S4 = "Game #"; // front half panel
    const string S5 = "255 - White, 0 - Black"; // back half panel
    const string S6 = "# Guesses"; // front half panel
    const string S7 = "Keys: R, G, B, Enter, S, Y, N"; // back half panel
    vector<string> startText = {S1, S2, S3, S4, S5, S6, S7};

    for (int i = 0; i < 7; i++){ 
        if (i < 3){
            infoVec->at(i).setColor(Color::White);
            infoVec->at(i).setPostion(MPX, currY);
            currY += 40;
        } else if (i == 3 || i == 5){
            infoVec->at(i).setColor(Color::Black);
            infoVec->at(i).setPostion(MPX+5, currY);
        } else if (i == 4 || i == 6){
            infoVec->at(i).setColor(Color::White);
            infoVec->at(i).setPostion(HPX, currY);
            currY += 40;
        } 
        
        infoVec->at(i).setText(startText.at(i));
        
    }
}


int main(){
    srand(time(0)); // seeding once
    rand();

    RenderWindow window( VideoMode(640, 800), "Guess The RGB Value Game" );

    // OPENING WRITING FILE
    ofstream fout("results.txt");
    if (fout.fail()){
        cerr << "Error opening file to write" << endl;
        return -1;
    }
    // END OF WRITING FILE BLOCK

    // user input and backgrounds
    const int RBX = 80; // red text box and background x val
    const int GBX = 260; // green text box and background x val
    const int BBX = 440; // blue text box and background x val
    const int GENY = 520; // all boxes share the same y val

    // GENERAL VALUES
    int game = 1; // which game the player is on
    bool activeGuessing = true; // where the player is still able to guess
    const string CUTESPACE = " ~---~---~---~---~---~---~---~---~---~---~---~ ";
    const string ENDSTRING = "Be sure to copy your results from the results file if you want to them! The file will be wiped next play through.";

    //OBJECT CREATION
    RandomColor randColor; // RandomColor object (contains RGB values)
    Color colorRand; // Color object to store random color

    CustColor guessC; // user input CustColor object
    Color guessColor; // user input Color color

    // COLOR GENERATION
    randColor.makeRandomColor(); // generating new numbers
    colorRand = randColor.makeColor(); // Color object made of random color


    // drawing shape with random color
    CircleShape random; // Shape to display random color
    random.setRadius(240);
    random.setPosition(80, 20);
    random.setFillColor(colorRand);

    // drawing shape with random color
    CircleShape guess; // Shape to display guessed color
    guess.setRadius(120);
    guess.setPosition(200, 140);
    guess.setFillColor(colorRand);

    // creating white boxes to help text stand out (create first)
    TextboxBackground redBack(RBX, GENY);
    TextboxBackground greenBack(GBX, GENY);
    TextboxBackground blueBack(BBX, GENY);

    // creating textboxes for inputs (plus 5 for spacing from edge)
    Textbox redBox(RBX+5, GENY); 
    Textbox greenBox(GBX+5, GENY);
    Textbox blueBox(BBX+5, GENY);

    redBox.setTextColor(Color::Red);
    greenBox.setTextColor(Color(10, 150, 20)); // the built in green was searing my retinas
    blueBox.setTextColor(Color::Blue);
    vector<Textbox> textVec = {redBox, greenBox, blueBox};

    TextboxBackground panel4Back(40, 700);
    TextboxBackground panel6Back(40, 740);

    panel4Back.setSize(180, 40);
    panel6Back.setSize(180, 40);

        // all info panels
    InfoPanel panel1; // first box, red value
    InfoPanel panel2; // second box, green value
    InfoPanel panel3; // third box, blue value
    InfoPanel panel4; // forth half box, guess count
    InfoPanel panel5; // fifth half box, hints
    InfoPanel panel6; // sixth half box, game number
    InfoPanel panel7; // seventh half box, controls, replay
    vector<InfoPanel> infoVec = {panel1, panel2, panel3, panel4, panel5, panel6, panel7}; // vector of panels

    startupVisuals(&random, &guess, colorRand, &textVec, &infoVec);
    
    // END OF CREATING AND PREPPING ALL SHAPES

    fout << "Game " << game << CUTESPACE << endl;
    infoVec.at(3).setText("Game " + to_string(game));

    // WINDOW OPEN (DRAW LOOP)
    while( window.isOpen() ) {
        window.clear();

        // SET UP DRAWING STUFF
        window.draw(random);
        window.draw(guess); // guess shape on top

        // background first (under textboxes)
        redBack.draw(window);
        greenBack.draw(window);
        blueBack.draw(window);
        panel4Back.draw(window);
        panel6Back.draw(window);
        
        // editable text
        for (int i = 0; i < 3; i++){
            textVec.at(i).draw(window);
        }

        for (int i = 0; i < 7; i++){
            infoVec.at(i).draw(window);
        }

    // END OF SET UP DRAWING

        Event event;

        // EVENT HANDLING
        while( window.pollEvent(event) ) {
    
            if (event.type == Event::Closed) {
                
                if (guessC.getRandomState() == false){ // output the actual values if not found
                    randColor.writeColor(fout, false);
                    guessC.writeColor(fout, true); // print out av guesses
                }
                randColor.writeStats(fout);
                guessC.writeStats(fout);
                fout << "Goodbye! " << CUTESPACE << endl;
                fout << endl << endl << ENDSTRING;
                window.close();

            } else if (event.type == Event::TextEntered){

                // ADJUSTING SELECTED TEXT BOX
                if (Keyboard::isKeyPressed(Keyboard::R)){ // When user wants to select textbox Red
                    textVec.at(0).setSelected(true);
                    textVec.at(1).setSelected(false);
                    textVec.at(2).setSelected(false);
                } else if (Keyboard::isKeyPressed(Keyboard::G)){ // When user wants to select textbox Green
                    textVec.at(0).setSelected(false);
                    textVec.at(1).setSelected(true);
                    textVec.at(2).setSelected(false);
                } else if (Keyboard::isKeyPressed(Keyboard::B)){ // When user wants to select textbox Blue
                    textVec.at(0).setSelected(false);
                    textVec.at(1).setSelected(false);
                    textVec.at(2).setSelected(true);
                // END OF ADJUSTMENTS

                } else if (Keyboard::isKeyPressed(Keyboard::Enter)) { // When user wants to submit a guess
                    
                    if (activeGuessing) { // can't update or write to file post-reveal
                        if ((textVec.at(0).getText() != "") && (textVec.at(1).getText() != "") && (textVec.at(2).getText() != "")){ // can only use stoi if number
                            // get integers from user input
                            guessC.setColor(stoi(textVec.at(0).getText()), stoi(textVec.at(1).getText()), stoi(textVec.at(2).getText())); // updating CustColor variables
                            guessColor = guessC.makeColor(); // creating Color object with user input
                            guess.setFillColor(guessColor); // updating color of middle circle

                            guessC.addGuess(); // user has guessed, updating guess
                            guessC.writeColor(fout, false); // only writes once window is closed

                            infoVec.at(0).setText(guessC.compareColor(randColor.getRed(), guessC.getRed(), 'r')); // we are COOKING
                            infoVec.at(1).setText(guessC.compareColor(randColor.getGreen(), guessC.getGreen(), 'g'));
                            infoVec.at(2).setText(guessC.compareColor(randColor.getBlue(), guessC.getBlue(), 'b'));
                            infoVec.at(5).setText(guessC.getGuessCount() + " Guesses");

                            guessC.checkIfFound(); // compares all values bool to see if all are true
                        }
                        
                        if (guessC.getRandomState() == true){ // user found the answer (output says good job)
                            randColor.writeColor(fout, true);
                            guessC.writeColor(fout, true);
                            infoVec.at(6).setColor(Color::Yellow);
                            infoVec.at(6).setText("Play Again? Y/N");
                        }
                    } // activeGuessing only

                } else if (Keyboard::isKeyPressed(Keyboard::S)) { // When user gives up
                    activeGuessing = false; // you will not be able to guess after showing the answers

                    // showing correct values
                    infoVec.at(0).setText("The red value you were looking for was " + to_string(randColor.getRed()));
                    infoVec.at(1).setText("The green value you were looking for was " + to_string(randColor.getGreen()));
                    infoVec.at(2).setText("The blue value you were looking for was " + to_string(randColor.getBlue()));
        
                    infoVec.at(6).setColor(Color::Yellow);
                    infoVec.at(6).setText("Play Again? Y/N");

                } else if (Keyboard::isKeyPressed(Keyboard::Y)) {

                    if (guessC.getRandomState() == false){ // output the actual values if not found
                        randColor.writeColor(fout, false);
                        guessC.writeColor(fout, true); // print out av guesses
                    }
                    
                    guessC.setRandomFound(false);
                    guessC.setGuessCount(0);
                    randColor.makeRandomColor();
                    colorRand = randColor.makeColor();
                    activeGuessing = true;
                    
                    startupVisuals(&random, &guess, colorRand, &textVec, &infoVec);
                    game++;
                    fout << endl << "Game " << game << CUTESPACE << endl; 
                    infoVec.at(3).setText("Game " + to_string(game));
                
                } else if (Keyboard::isKeyPressed(Keyboard::N)) {
            
                    if (guessC.getRandomState() == false){ // output the actual values if not found
                        randColor.writeColor(fout, false);
                        guessC.writeColor(fout, true); // print out av guesses
                    }
                    randColor.writeStats(fout);
                    guessC.writeStats(fout);
                    fout << "Goodbye!" << CUTESPACE << endl;
                    fout << endl << endl << endl << ENDSTRING;

                    window.close();

                } else { // instead of just having another nested, i'm calling all because typedIn checks for selected status
                    if (activeGuessing){ // only allow user input when activeGuessing
                        textVec.at(0).typedIn(event);
                        textVec.at(1).typedIn(event);
                        textVec.at(2).typedIn(event);
                    }
                }
                        
            } // end if
        } // END EVENT HANDLING

        window.display();

    } // end of draw loop

    fout.close(); // CLOSING FILE
    return 0;

} // end main

