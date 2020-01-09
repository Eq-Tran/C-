#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <time.h>
#include<algorithm>


using namespace std;

string fileProcess();
void play_game();
void display_board(string board);


int main() {

	//C:\\Users\\Eqtra\\Desktop\\Words.txt
	// should make methods for win, loss, reset, and endgame
	// hangman must handle duplicate guesses keep track of misses
	
	//variables needed numberOfmisses, numberOfguess, wordToGuess, playerGuess, 
	string board = "ethan";

	//play_game();
	cout << board << endl;
	display_board(board);

	system("pause");
	return 0;
}

/*
*	what this function does:
*
*	it reads a files contents line by line
*   pushes each word per line into a vector
*	than returns a random word from the vector
*
*/
string fileProcess() {

	//Variable Declaration
	string line, fileName, randWord;
	int index;
	vector<string> words;
	fstream file;

	// static filename set for security
	fileName = "C:\\Users\\Eqtra\\Desktop\\Words.txt";

	// open the file 
	file.open(fileName);

	if (file.is_open()){

		std::cout << "File opened " << std::endl;

		// read the files contents line by line
		while (getline(file, line)) {

			// push each line into the words vector
			words.push_back(line);
			
		}
	}
	else {

		std::cout << "File could not be opened. " << std::endl;
	}

	// random word generator
	srand(time(nullptr));
	index = rand() % words.size();
	randWord = words[index];

	return randWord;
}

// simple game win function 
bool game_won(string guessWord, string guess) {

	if (guess == guessWord) {

		cout << "You won! play again y/n" << endl;
		return true;
	}

	return false;

}

/* NOTE: should think about separating this function 
   WHY:  in order to replace the letters in the display you need to repeat after each guess
         creating a function that replaces letters would make it easier call and repeat

*/
void play_game() {

	
	bool gameState = false;
	char guessLetter;
	int MAX_TRIES, guesses;
	string guessWord, display;


	MAX_TRIES = 10;
	guessWord = fileProcess();

	cout << guessWord;

	display = guessWord;

	for (int i = 0; i < guessWord.length(); i++) {


		display[i] = '*';
	}

	cout << "TEST guessWord shown: " << endl;
	cout << display;
	cout << "enter a letter to guess " << endl;
	cin >> guessLetter;


	for (int i = 0; i < display.length(); i++) {

		
		if (guessLetter == guessWord[i]) {

			//guessLetter = display[i];
			display[i] = guessLetter;
			cout << display[i] << endl;


		}
		else if (guessLetter != guessWord[i]) {
			cout << "no" << endl;
			//guesses++;
		}
	
	}

}


void display_board(string board) {

	int letter = board.length();
	//char** b = new char*[letter + 1]; // this will create memory leaks need to delete b[i] and b[] to fix See: allocating memory c++

	for (int i = 0; i < letter; i++) {
		board += "*";
	
		
	}

	cout << board << endl;

}


//TODO
// create separate functions 
// focus on game winning logic 
// refactor what can be refactored
// EXTRA
// evil hangman
// replace each letter entered with another letter

