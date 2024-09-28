# Pong/Tennis Game (Player vs Computer)
## Overview
This project is a simple tennis game implemented in C, where Player 1 (the user) plays against an AI-controlled opponent. The game features basic ball and paddle mechanics and uses simple terminal-based graphics. The game runs in a loop, updating at a defined frame rate, until the player decides to quit.

![Screenshot 2024-09-27 125630](https://github.com/user-attachments/assets/2a044c6e-d073-4c93-91d2-9991c158dccc)

## How to Play
1. **Player 1 (Human):**
  Use the following keys to control the left racket:
    * **W:** Move up
    * **S:** Move down
2. **Player 2 (Computer):**
  The computer controls the right racket and follows the ball's position to simulate a competitive opponent.
3. **Quit:**
  Press **Q** at any time to exit the game.

## Game Rules
* The game is played between two rackets and a ball.
* The ball starts in the center of the screen and moves in a random direction.
* The player controls the left racket, and the AI controls the right one.
* The ball bounces off the top and bottom walls.
* When the ball touches a racket, it changes direction and continues moving.
* If the ball goes beyond a racket (i.e., out of bounds on the left or right side), the opposing player scores a point.
* After each score, the ball resets to the center, and the game continues.

## Game Features
* **AI Movement:**
  The AI automatically adjusts its racket’s position to try and intercept the ball based on its current location.
* **Ball Physics:**
  The ball moves diagonally, bouncing off the top and bottom walls. It changes direction when it hits either player's racket.
* **Scoring:**
  The score is displayed at the bottom of the screen, showing Player 1's and the AI's score. The first player to hit the ball out of bounds loses a point.
* **Game Interface:**
  The screen is updated in real-time with the positions of the paddles, the ball, and the current score.

## Code Breakdown
### Functions
1. **moveRacket:**
  Moves the player's racket vertically based on user input (**W** for up and **S** for down).
2. **moveRacketAI:**
  Controls the movement of the AI's racket, adjusting its position to track the ball's vertical position.
3. **moveBall:**
  Updates the ball's position based on its current direction (**xDirection**, **yDirection**).
4. **bounceOffWall:**
  If the ball hits the top or bottom walls, this function inverts its vertical direction, simulating a bounce.
5. **checkPaddleCollision:**
  Detects when the ball hits a racket. If a collision occurs, the ball changes direction and continues moving.
6. **drawGameWindow:**
  This function clears the console and redraws the game scene, including the rackets, ball, and score.
7. **takeInput:**
  Captures player input (non-blocking) using **_kbhit()** and **_getch()** to allow real-time control of the racket.

### Game Loop
  The main game loop continuously runs until the player quits (**Q** key). 
  In each iteration:
  * It captures player input.
  * It moves the player’s racket and AI racket.
  * The ball is moved, and wall collisions are checked.
  * Paddle collisions are checked, and the score is updated if the ball goes out of bounds.
  * The screen is updated to display the current game state.
  * The loop runs at a controlled frame rate, providing a smooth gameplay experience.
    
## Dependencies
  * **<stdio.h>:** Standard input and output functions.
  * **<stdlib.h>:** Standard utility functions, including system and random number generation.
  * **<conio.h>:** Provides console input/output functions (e.g., **_kbhit()** and **_getch()**).
  * **<windows.h>:** Includes the **sleep()** function and other Windows-specific utilities.
  * **<time.h>:** Used for seeding the random number generator with the current time.
    
## Compilation
  To compile and run this game on a Windows system, you can use any C compiler such as **GCC** or **MSVC**. 
  
  Here's an example using GCC:
  
    gcc tennis_game.c -o tennis_game.exe
    
  To Run the Code:
  
    ./tennis_game.exe

    
### Note: 
  This game uses Windows-specific libraries (**<conio.h>**, **<windows.h>**). If you're compiling on a non-Windows system, modifications will be required to replace these dependencies.

## Future Improvements
1. **Multiplayer Mode:**
  Add support for a second player, allowing a human to control the second racket.

2. **Improved AI:**
  Implement a more advanced AI that can predict the ball's trajectory, making the game more challenging.

3. **Adjustable Difficulty:**
  Add options to adjust the AI's speed or reaction time, catering to different skill levels.

4. **Graphics and Sound:**
  Enhance the visual experience by adding color or graphical elements and incorporating sound effects when the ball hits a racket or wall.






