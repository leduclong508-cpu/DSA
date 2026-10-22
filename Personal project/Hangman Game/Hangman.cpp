#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>

#define MAX_MISTAKES 6
#define MAX_WORDS 12

const char *words_list[MAX_WORDS] = {
    "programming", 
    "hangman", 
    "computer", 
    "science", 
    "algorithm",
    "data",
    "structure",
    "function",
    "variable",
    "telecom",
    "embedded",
    "network"
};

const char *hangman_art[] = {
    "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========",
    "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========",
    "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========",
    "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========",
    "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========",
    "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========",
    "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n========="
};

void clear_buffer(){}

class hangman{
    private:
        char word[20];
        char guess[20];
        int count = 0;

    public:
        hangman(){}

        void guessword(){
            printf("Enter the guess: ");
            scanf("%s", word);
        }

        void checkword()
}