/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// None
//
// Name: Mohammad Naael Ahmed
// login ID: mnahmed
//////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include "words.h"
#include "hangman-io.h"
#include <stdbool.h>
#include <assert.h>


// is_letter() checks if a character is a letter.
// time: O(1)
int is_letter(char input) {
    if ((input >= 65 && input <= 90) || (input >= 97 && input <= 122)) {
        return 1; 
    }
    return 0;
}

// to_uppercase() returns every character to its capital form by decreasing its ASCII value. 
// effects:mutates value.
// time: O(1)
char to_uppercase(char input) {
    if (input >= 'a' && input <= 'z') {
        return input - 32; 
    }
    return input;
}

// play_game() plays the hangman game. 
// effects: mutates values
//         produces output
// time: O(n)
//        where n is the length of the input string letter.
void play_game(const char *word) {
    assert(word);
    char board[50];            //array to represent board
    char guessed_array[50];    //array to store the guessed
    int error = 0;             //error counter
    int word_length = strlen(word);
    int guessed_attempt = 0;   // Counter for the number of guessed letters


    // Initialize the game board with '*' for letters and ' ' for spaces
    for (int i = 0; i < word_length; i++) {
        board[i] = (word[i] == ' ') ? ' ' : '*';
    }
    
    board[word_length] = '\0';

    while (error < max_strikes) {
        char guess_input;
        int found = 0;

        print_hangman(error);
        printf("%s",letter_prompt);
        printf("%s\n", board);

        // Read the input and validate if it is a letter
        if (scanf(" %c", &guess_input) != 1 || !is_letter(guess_input)) {
            
            printf(not_a_letter, guess_input);
            continue;
        }

        guess_input = to_uppercase(guess_input);

        int already_guessed = 0;
        for (int i = 0; i < guessed_attempt; i++) {
            if (guessed_array[i] == guess_input) {
                already_guessed = 1;
                break;
            }
        }
    

        if (already_guessed != 0) {
            printf(already_guessed_letter, guess_input);
            continue;
        }

        guessed_array[guessed_attempt++] = guess_input;

    
        int i = 0;
        while (i < word_length) {
            if (word[i] == guess_input) {
            board[i] = guess_input;
            found = 1;
            }
        i++;
        }

        

        if (!found) {
            printf(not_in_word, guess_input);
            error++;
            if (error < max_strikes) {
                printf(not_last_guess, max_strikes - error);
            }
        } else if (strcmp(board, word) == 0) {
            printf(congratulations, word);
            return;
        }
    }

    print_hangman(error);
    printf(game_over, word);
}

int main(void) {
    int game_number;
    char play_again_response;

    while (true) {
        printf(enter_game_number, max_words);
        while (scanf("%d", &game_number) != 1 || game_number < 1 || game_number > max_words) {
            printf("%s",invalid_game_number);
            printf(enter_game_number, max_words);
            
        }

        const char *word = get_word(game_number);
        assert(word);
        play_game(word);

        printf("%s",play_again);
        while (scanf(" %c", &play_again_response) != 1 || (play_again_response != 'Y' && play_again_response != 'y' && play_again_response != 'N' && play_again_response != 'n')) {
            printf("%s",invalid_play_again_response);
            printf("%s",play_again);
            
        }

        if (play_again_response == 'N' || play_again_response == 'n') {
            break;
        }
    }
    return 0;
}