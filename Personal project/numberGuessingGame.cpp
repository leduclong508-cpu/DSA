#include<stdio.h>
#include<time.h>

unsigned long int next_seed = 1;

void my_srand(unsigned int seed){
    next_seed = seed;
}

int my_rand(void){
    next_seed = next_seed * 1103515245 + 12345;
    return (unsigned int)(next_seed/65536) % 32768;
}

int main(){
    unsigned int current_time = (unsigned int)time(NULL);
    my_srand(current_time);

    int target = my_rand() % 100 + 1;

    int guess = 0;
    int attempts = 0;
    int max_attempts = 12;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have selected a number between 1 and 100. Can you guess it?\n"
        "You only have %d attempts to guess the number. Good luck!\n", max_attempts);

    while(guess != target && attempts < max_attempts){
        printf("Enter your guess: ");

        // Check if the input is a valid integer (if true return 1)
        if(scanf("%d", &guess) != 1){
            printf("Invalid input, please enter a valid integer. \n");

            // Clear the input buffer
            while(getchar() != '\n');
            continue;
        }

        attempts++;

        if(guess < target){
            printf("Too low! Try again. \n");
        }
        else if(guess > target){
            printf("Too high! Try again. \n");
        }
        else{
            printf("Congratulations! You guessed the number %d in %d attempts. \n", target, attempts);
        }
    }

    if(guess != target){
        printf("Game Over!\n");
        printf("Sorry, you've used all your attempts. The number was %d. \n", target);
    }

    return 0;

}