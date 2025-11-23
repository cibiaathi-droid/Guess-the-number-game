#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Generate random number between 1 and 100
    int secretNumber = (rand() % 100) + 1;
    int guess;
    int attempts = 0;
    const int maxAttempts = 10;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100.\n");
    printf("You have %d attempts to guess it!\n", maxAttempts);

    while (attempts < maxAttempts) {
        printf("\nAttempt %d/%d\n", attempts + 1, maxAttempts);
        printf("Enter your guess (1-100): ");
        scanf("%d", &guess);

        if (guess < 1 || guess > 100) {
            printf("Please enter a number between 1 and 100 only!\n");
            continue;
        }

        attempts++;

        if (guess > secretNumber) {
            printf("Too high! Try again.\n");
        } else if (guess < secretNumber) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts!\n", attempts);
            break;
        }

        if (attempts < maxAttempts && guess != secretNumber) {
            printf("Remaining attempts: %d\n", maxAttempts - attempts);
        }
    }

    if (attempts == maxAttempts && guess != secretNumber) {
        printf("\nGame Over! You've used all %d attempts.\n", maxAttempts);
        printf("The secret number was: %d\n", secretNumber);
    }

    return 0;
}
