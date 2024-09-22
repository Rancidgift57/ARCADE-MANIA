#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int RockPaperScissor() {
    int playerChoice, computerChoice;
    int playerScore = 0, computerScore = 0;
    int rounds, currentRound = 0;

    printf("Welcome to Rock, Paper, Scissors!\n");
    printf("Enter the number of rounds: ");
    scanf("%d", &rounds);

    srand(time(NULL));  // Seed for random number generation

    while (currentRound < rounds) {
        printf("\nRound %d\n", currentRound + 1);
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        printf("Enter your choice (1/2/3): ");
        scanf("%d", &playerChoice);

        if (playerChoice < 1 || playerChoice > 3) {
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
            continue;
        }

        computerChoice = rand() % 3 + 1;

        if (playerChoice == computerChoice) {
            printf("It's a tie!\n");
        } else if ((playerChoice == 1 && computerChoice == 3) ||
                   (playerChoice == 2 && computerChoice == 1) ||
                   (playerChoice == 3 && computerChoice == 2)) {
            printf("You win this round!\n");
            playerScore++;
        } else {
            printf("Computer wins this round!\n");
            computerScore++;
        }

        currentRound++;
    }

    printf("\nGame Over!\n");
    printf("Your Score: %d\n", playerScore);
    printf("Computer's Score: %d\n", computerScore);

    if (playerScore > computerScore) {
        printf("Congratulations, you win the game!\n");
    } else if (computerScore > playerScore) {
        printf("Computer wins the game. Better luck next time!\n");
    } else {
        printf("It's a tie game!\n");
    }
    return 0;
}

// Entry point of the program
int main() {
    RockPaperScissor();  // Calling the RockPaperScissor function
    return 0;
}

