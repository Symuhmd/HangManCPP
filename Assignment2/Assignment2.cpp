#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

bool CheckGuesses(const string& word, const vector<bool>& letter) {

    for (size_t i = 0; i < word.size(); ++i) {

        if (!letter[i]) {
            return false;
        }
    }
    return true; 
}

void drawHangman(int incorrectGuesses) {

    switch (incorrectGuesses)
    {
        case 0:
            cout << "  ________" << endl;
            cout << " |        |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << " |_" << endl;
            break;
        case 1:
            cout << "  ________" << endl;
            cout << " |        |" << endl;
            cout << " |        @" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << " |_________" << endl;
            break;
        case 2:
            cout << "  ________" << endl;
            cout << " |        |" << endl;
            cout << " |        @" << endl;
            cout << " |        |" << endl;
            cout << " |        |" << endl;
            cout << " |" << endl;
            cout << " |_________" << endl;
            break;
        case 3:
            cout << "  ________" << endl;
            cout << " |        |" << endl;
            cout << " |        @" << endl;
            cout << " |       /|" << endl;
            cout << " |        |  " << endl;
            cout << " |" << endl;
            cout << " |_________" << endl;
            break;
        case 4:
            cout << "  ________" << endl;
            cout << " |        |" << endl;
            cout << " |        @" << endl;
            cout << " |       /|\\" << endl;
            cout << " |        |  " << endl;
            cout << " |" << endl;
            cout << " |_________" << endl;
            break;
        case 5:
            cout << "  ________" << endl;
            cout << " |        |" << endl;
            cout << " |        @" << endl;
            cout << " |       /|\\" << endl;
            cout << " |        | " << endl;
            cout << " |       /" << endl;
            cout << " |_________" << endl;
            break;
        case 6:
            cout << "  ________" << endl;
            cout << " |        |" << endl;
            cout << " |        @" << endl;
            cout << " |       /|\\" << endl;
            cout << " |        | " << endl;
            cout << " |       / \\" << endl;
            cout << " |_________" << endl;
            break;
        default:
            break;
    }
}

int main() {

    bool playAgain = true;

    while (playAgain)
    {
        vector<string> words; 
        string word;
        ifstream inputFile("words.txt"); 

        while (getline(inputFile, word)) {

            if (!word.empty() && word[word.size() - 1] == '\r') { 

                word = word.substr(0, word.size() - 1);
            }
            words.push_back(word); 
        }

        inputFile.close(); 

        string secretWord = words[rand() % words.size()]; 
        vector<bool> guessedLetters(secretWord.size(), false);
        int attemptsLeft = 6; 

        cout << "-------------------\nHangman Game\n-------------------" << endl;
        cout << "Guess the name of animal below\n" << endl;

        while (attemptsLeft > 0) { 

            cout << "Secret Word: ";
            for (size_t i = 0; i < secretWord.size(); ++i) {
                if (guessedLetters[i]) {
                    cout << secretWord[i] << " ";
                }
                else {
                    cout << "_ "; 
                }
            }
            cout << endl;
            char inputChar;
            cout << "Guess a letter: "; 
            cin >> inputChar;

            bool letterFound = false;
            for (size_t i = 0; i < secretWord.size(); ++i) {

                if (secretWord[i] == inputChar) {
                    guessedLetters[i] = true;
                    letterFound = true;
                }
            }

            if (!letterFound) {
                attemptsLeft--;
                cout << "Incorrect guess. Attempts left: " << attemptsLeft << endl;
            }

            drawHangman(6 - attemptsLeft);

            if (CheckGuesses(secretWord, guessedLetters)) {

                cout << "Congratulations! You have won the game. The word was:" << secretWord << endl;
                break;
            }
        }

        if (attemptsLeft <= 0) {

            cout << "Game Over! The word was: " << secretWord << endl; 
        }

        char answer;
        cout << "\nAre you willing to play again ?? [ Y | N ]" << endl;
        cin >> answer;
        
        if (answer == 'y' || answer == 'Y')
        {
            playAgain = true;
        }
        else
        {
            playAgain = false;
        }
    }

    return 0;
}