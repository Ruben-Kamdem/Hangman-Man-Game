# Hangman-Man-Game
This is the a simplified version of the Hangman game realized with C Language.
The code has 4 main files: main.c, fonctions.c, main.h, and liste_mots.txt.
main.c is contains the main structure of the code. fonctions.c contains the all the important functions of the program.
main.h contains the function prototypes, and liste_mots.txt is a small dictionnary of words from which the "to be found"
word will be selected. 
For the realisation of the game, this is the logic i used:
1. The "to be guessed" word (solution_word) is selected randomly from the dictionnary *liste_mots.txt"
2. The function *initialisationchaineaffichage* then initialises a string "chaineaffichage" constituted of asterix(*) representing the undiscovered letters of the solution word.
3. The user then subsequestly enters various letters, and each time, if the entered letter is present in the solution word, it is stored in a new string "lettretrouvee" via the function *stockerLettres*
4. Lastly, the elements of the string "lettretrouvee" and the solution word ("mot_secret") are compared, and where there's a matching, the initial asterix of the string "chaineaffichage" are replaced by their corresponding letters, thus revealing the solution word progrssively.
5. There's also a counter "coupsRestant" for the number of trials, and when 10 trials is exceeded, Game over. 
