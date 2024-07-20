# hangman
Welcome to the Hangman Game repository! This project is a console-based implementation of the classic Hangman game, developed in C. The game challenges players to guess a hidden word one letter at a time, with a limited number of incorrect guesses allowed before the game ends.

Features:
Dynamic Word Selection: Words are dynamically selected from an external source for each game.
Input Validation: Robust validation ensures only valid letters are accepted as input.
Case Insensitivity: Handles both uppercase and lowercase inputs seamlessly.
Graphical Display: Uses ASCII art to visually represent the hangman and game progress.
User-Friendly Interface: Prompts and feedback guide the player throughout the game.

How to Play:
Start the Game: Run the main executable to begin a new game.
Input a Guess: Enter a letter to guess. The game will validate and process your input.
Check Progress: View the updated game board and the hangman display after each guess.
Win or Lose: Guess the word correctly to win, or exhaust the maximum number of incorrect guesses to lose.

Files:
hangman.c: Contains the main game logic and flow control.
hangman-io.c & hangman-io.h: Handle input/output operations and display functions.
words.h: Provides the external word list for the game.

Code Highlights:
Input Handling: Ensures only valid letters are accepted, ignoring other characters.
Memory Optimization: Efficient use of memory and dynamic allocation.
Modular Design: Clear separation of game logic, I/O operations, and data handling.
Getting Started

Prerequisites
A C compiler (e.g., GCC)
Standard C library
