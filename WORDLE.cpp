#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>  // For random number generation

#define MAX_ATTEMPTS 6

// List of fruit words to guess
const char* word_list[] = {"apple", "banana", "cherry", "grape", "lemon", "orange", "litchi", "mango"};

// Function to select a random word from the list
const char* getRandomWord() {
    int num_words = sizeof(word_list) / sizeof(word_list[0]);
    int index = rand() % num_words;
    return word_list[index];
}

// Function to display the word with guessed letters and underscores
void displayWord(const char* target_word, const bool* guessed) {
    for (int i = 0; target_word[i] != '\0'; i++) {
        if (guessed[i]) {
            printf("%c ", target_word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int main() {  // The entry point of the program
    srand(time(NULL));  // Initialize random number generator
    const char* target_word = getRandomWord();  // Select a random word from the list
    int word_length = strlen(target_word);  // Get the length of the target word
    bool guessed[word_length];  // Array to keep track of guessed letters
    int attempts = 0;

    // Initialize all letters as not guessed
    for (int i = 0; i < word_length; i++) {
        guessed[i] = false;
    }

    printf("Welcome to Fruit Wordle!\n");
    printf("Enter a Fruit name:\nGuess the word: ");
    displayWord(target_word, guessed);  // Display the word with blanks

    // Main game loop
    while (attempts < MAX_ATTEMPTS) {
        char guess;
        printf("Enter a letter guess: ");
        scanf(" %c", &guess);  // Read the guessed letter from the user

        bool found = false;
        // Check if the guessed letter is in the target word
        for (int i = 0; i < word_length; i++) {
            if (!guessed[i] && target_word[i] == guess) {
                guessed[i] = true;  // Mark the letter as guessed
                found = true;
            }
        }

        // If the guess was correct, update the display
        if (found) {
            printf("Good guess!\n");
            displayWord(target_word, guessed);  // Display updated word with guessed letters
        } else {
            printf("Incorrect guess. Attempts left: %d\n", MAX_ATTEMPTS - attempts - 1);
            attempts++;  // Increment the number of attempts if the guess was incorrect
        }

        // Check if all letters have been guessed
        bool all_guessed = true;
        for (int i = 0; i < word_length; i++) {
            if (!guessed[i]) {
                all_guessed = false;
                break;
            }
        }

        // If the word is fully guessed, congratulate the user and exit
        if (all_guessed) {
            printf("Congratulations! You guessed the word: %s\n", target_word);
            return 0;
        }
    }

    // If all attempts are used up, reveal the word
    if (attempts == MAX_ATTEMPTS) {
        printf("Out of attempts! The word was: %s\n", target_word);
    }

    return 0;  // Exit the program
}

