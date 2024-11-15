--TITLE: Guess the RGB Value - Sarah Bunnell                    Section: B

--PROBLEM DESCRIPTION: The program will generate and display a random color 
and allow the player to enter three values from 0 to 255 for the color's red, 
green, and blue values into corresponding textboxes on the screen. After the 
player submits their guess, the color they created will be displayed next to a 
random color, and hints will be given on how close/far the guess is. The 
amount of guesses will be tracked. To win, guesses need to be within +/-5 of 
each color component to win.

--PROGRAM DOCUMENTATION: When you run the program (using “GuessTheRGBValue” in 
the terminal), a window will pop up with a colored circle, three white text 
boxes, and a little introduction with other gameplay panels. In order to play, 
you will need to press R, G, and B to access the appropriate text boxes. Once 
you have typed in your value guess, you can press Enter to reveal the color 
you created and receive your hints for each value. You can continue guessing 
as long as you want, but if you want to give up, press S. This will SHOW the 
answers and prevent you from further guessing. You will then be prompted if 
you want to replay or not. Pressing Y will reset the game, but continue to 
write to the file under next game section. Pressing N will write the color to 
the file and close the game.

--CLASS DESCRIPTION: My most significant class is probably CustColor. My class 
contains variables for my RGB values, (protected so randomColor class can use, 
as it is publicly extending CustColor), booleans to store if the player has 
guessed in range of each color component, a randomFound boolean that is only 
true when the color-specifics are true, and an int to store guesses. Creating 
this class allowed me to organize my variables and create helpful functions as 
well as provide a base class for my randomColor class.

--LIST DATA STRUCTURE: I chose to use a vector to shorten my function 
parameter section and make it easier to update each component. It also allowed 
me to use a vector rather than continuously call three different variables. I 
also used it to store guess counts and RGB values to find the average for each 
game.

--FILE I/O: It was incorporated in the main, but the CustColor and randomColor 
classes do a large portion of the use. It wasn't *necessary*, but it is very 
nice to have to see the past guesses to learn from the actual values of the 
color. It is also fun to see your average guesses over multiple games. It now 
also shows the minimum, maximum, and average random RGB values encountered. 

--REFLECTIONS: I didn't encounter a lot of issues as I have worked on large 
projects like this before. The main issues I encountered were: getting stuck 
on occasional logic issues (namely the compare logic), making the interface, 
and a little bit of combining functions or pulling out repeated lines of code 
(compareColor was compareRed, compareGreen etc., and passing stuff by pointers 
in the functions in main). I don't know if there is anything I would change 
about my process. I had to figure out what I needed as I was working on it 
because I kept discovering new issues and tasks I had to work on and I 
couldn’t predict some of the quirks of my program.
