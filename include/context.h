#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct {
    char *right_word;
    char *user_word;
    int lives;
    int LEN;
    bool game_over;

} Context;

Context new_context(char *word);
void fillWord(char *word, int size);
