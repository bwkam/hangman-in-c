#include "context.h"

Context new_context(char *word) {
    // Init some important variables for easy access from other source files.
    Context context;
    context.right_word = word;
    context.LEN = strlen(context.right_word);
    context.user_word = (char*)malloc(context.LEN * sizeof(char));
    context.game_over = false;
    context.lives = context.LEN + 2; 

    return context;  
}

void fillWord(char *word, int size) {
    // Because it probably contains garbage values, and I don't want a SEGV
    for (int i = 0; i < size; i++) {
        word[i] = '_';
    }
}