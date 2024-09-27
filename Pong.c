#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define SCREEN_WIDTH 30
#define SCREEN_HEIGHT 15
#define RACKET_HEIGHT 4

// Racket struct for both players
typedef struct {
    int xPos;
    int yPos;
} Racket;

// Ball struct
typedef struct {
    int xPos;
    int yPos;
    int xDirection;
    int yDirection;
} Ball;

void moveRacket(Racket *racket, char input, int screen_height) {
    if (input == 'W' && racket->yPos > 0) // Move up for Player 1
        racket->yPos--;
    else if (input == 'S' && racket->yPos + RACKET_HEIGHT < screen_height) // Move down for Player 1
        racket->yPos++;
}

void moveRacketAI(Racket *racket, Ball *ball) {
    if (ball->yPos < racket->yPos) {
        racket->yPos--; // Move up if ball is above
    } else if (ball->yPos > racket->yPos + RACKET_HEIGHT - 1) {
        racket->yPos++; // Move down if ball is below
    }
}

void moveBall(Ball *ball) {
    ball->xPos += ball->xDirection;
    ball->yPos += ball->yDirection;
}

void bounceOffWall(Ball *ball) {
    if (ball->yPos <= 0 || ball->yPos >= SCREEN_HEIGHT - 1) {
        ball->yDirection = -ball->yDirection; // Bounce off top and bottom walls
    }
}

int checkPaddleCollision(Ball *ball, Racket *racket) {
    // Check for ball collision with racket
    if (ball->xPos == racket->xPos && ball->yPos >= racket->yPos && ball->yPos < racket->yPos + RACKET_HEIGHT) {
        ball->xDirection = -ball->xDirection;
        return 1;
    }
    return 0;
}

void drawGameWindow(Racket *leftRacket, Racket *rightRacket, Ball *ball, int leftScore, int rightScore) {
    system("CLS");
    for (int i = 0; i <= SCREEN_WIDTH; i++) {
        printf("-");
    }
    printf("\n");

    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            if (j == 0 || j == SCREEN_WIDTH - 1)
                printf("-");

            // Left racket drawing
            if (j == leftRacket->xPos && i >= leftRacket->yPos && i < leftRacket->yPos + RACKET_HEIGHT)
                printf("|");
            // Right racket drawing
            else if (j == rightRacket->xPos && i >= rightRacket->yPos && i < rightRacket->yPos + RACKET_HEIGHT)
                printf("|");
            // Ball drawing
            else if (j == ball->xPos && i == ball->yPos)
                printf("O");
            else
                printf(" ");
        }
        printf("\n");
    }

    for (int i = 0; i <= SCREEN_WIDTH; i++) {
        printf("-");
    }
    printf("\nPlayer 1: %d    Computer: %d\n", leftScore, rightScore);
}

char takeInput() {
    if (_kbhit()) {
        return _getch(); // Correct input function
    }
    return 'N'; // No input
}

int main() {
    srand((unsigned int)time(0));
    int framerate = 30; // Control the frame rate

    // Initialize rackets and ball
    Racket leftRacket = {1, SCREEN_HEIGHT / 2 - 2};         // Left racket on x = 1
    Racket rightRacket = {SCREEN_WIDTH - 3, SCREEN_HEIGHT / 2 - 2}; // Right racket on x = width - 3
    Ball ball = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, -1, -1}; // Ball starts moving left and up

    int leftScore = 0;
    int rightScore = 0;
    int running = 1;

    // Show initial game instructions
    system("CLS");
    printf("Welcome to the Tennis Game!\n");
    printf("Controls:\n");
    printf("Player 1: W (up), S (down)\n");
    printf("Player 2: AI (Computer controlled)\n");
    printf("Press Q to Quit\n");
    Sleep(2000); // Delay before starting the game

    while (running) {
        // Continuously capture input at the start of the loop
        char input = takeInput(); // Capture input
        if (input != 'N') { // If a key is pressed
            printf("Input detected: %c\n", input); // Debugging line
            if (input == 'Q') 
                running = 0;  // Exit condition

            // Racket movement for Player 1
            moveRacket(&leftRacket, input, SCREEN_HEIGHT);
        }

        // Ball movement
        moveBall(&ball);
        bounceOffWall(&ball);

        // AI Movement for right racket
        moveRacketAI(&rightRacket, &ball);

        // Ball collision with rackets
        if (!checkPaddleCollision(&ball, &leftRacket) && !checkPaddleCollision(&ball, &rightRacket)) {
            // Check if the ball goes off-screen
            if (ball.xPos <= 0) {
                rightScore++;
                ball.xPos = SCREEN_WIDTH / 2; // Reset ball to center
                ball.yPos = SCREEN_HEIGHT / 2;
                ball.xDirection = -1; // Reset direction
                ball.yDirection = -1;
            } else if (ball.xPos >= SCREEN_WIDTH - 1) {
                leftScore++;
                ball.xPos = SCREEN_WIDTH / 2; // Reset ball to center
                ball.yPos = SCREEN_HEIGHT / 2;
                ball.xDirection = -1; // Reset direction
                ball.yDirection = -1;
            }
        }

        drawGameWindow(&leftRacket, &rightRacket, &ball, leftScore, rightScore);
        Sleep(1000 / framerate);  // Control frame rate
    }

    return 0;
}
