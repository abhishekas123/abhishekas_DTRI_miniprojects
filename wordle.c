#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define WORD_LENGTH 5
#define MAX_ATTEMPTS 6


void checkGuess(const char* secret, const char* guess, char* result) {
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (guess[i] == secret[i]) {
            result[i] = '*';
        } else if (strchr(secret, guess[i])) {
            result[i] = '+';
        } else {
            result[i] = '-';
        }
    }
    result[WORD_LENGTH] = '\0';
}

int main() {
    char secret[WORD_LENGTH + 1] = "apple";
    char guess[WORD_LENGTH + 1];
    char result[WORD_LENGTH + 1];
    int attempts = 0;

    printf("Welcome to Wordle!\n");
    printf("You have %d attempts to guess a %d-letter word.\n", MAX_ATTEMPTS, WORD_LENGTH);


    while (attempts < MAX_ATTEMPTS) {
        printf("\nAttempt %d: Enter your 5-letter guess: ", attempts + 1);
        scanf("%s", guess);


        if (strlen(guess) != WORD_LENGTH) {
            printf("Please enter a %d-letter word.\n", WORD_LENGTH);
            continue;
        }


        for (int i = 0; i < WORD_LENGTH; i++) {
            guess[i] = tolower(guess[i]);
        }


        if (strcmp(guess, secret) == 0) {
            printf("Congratulations! You guessed the word: %s\n", secret);
            break;
        }


        checkGuess(secret, guess, result);
        printf("Feedback: %s\n", result);
        attempts++;
    }

    if (attempts == MAX_ATTEMPTS) {
        printf("Out of attempts! The correct word was: %s\n", secret);
    }

    return 0;
}

