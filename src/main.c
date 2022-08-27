#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "context.h"


// Context for holding all important details
Context c;

// Function prototypes
void drawArea(void);
char prompt(void);
void clearScreen(void);
void checkGame(void);

int main(void)
{
    clearScreen();

    char word;
    // Init the context variable
    printf("What word do you want to insert or play with? \n");
    printf("Your word: ");
    scanf("%s", &word);

    c = new_context(&word);
    fillWord(c.user_word, c.LEN);

    clearScreen();

    while (!c.game_over) {
        drawArea();
        prompt();
        checkGame();
        clearScreen();
    }

    return 0;
}

void drawArea(void) {

    printf("\tCurrent lives: %d\n", c.lives);

    printf("\n\n\n\t");

    for (int i = 0; i < c.LEN; i++) {
        printf("  %c  ", *(c.user_word+i));
    }

    printf("\n");

}

char prompt(void) {
    char input;

    printf("\n\nYour guess: ");
    scanf(" %c", &input);

    // Check if it's there if true then write it to user_word else don't. (this also handles dups)
    for (int i = 0; i < c.LEN; i++) {
        if (c.right_word[i] == input) {
            c.user_word[i] = input;
        }
    }

    c.lives--;

    return input;
}

void clearScreen(void) {
    printf("\e[1;1H\e[2J");
}

void checkGame(void) {

    int underscores = 0;

    for (int i = 0; i < c.LEN; i++) {
        if (c.user_word[i] == '_') {
            underscores++;
        }
    }

    if (underscores == 0) {
        clearScreen();
        drawArea();
        printf("\n\n\n\tCongrats, you won!\n");
        exit(0);
    }

    if (c.lives == 0) {
        clearScreen();
        drawArea();
        printf("\n\n\n\tGAME OVER\n");
        exit(0);
    }
}




