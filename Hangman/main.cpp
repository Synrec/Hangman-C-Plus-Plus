#include<iostream>;
#include <string>;
#include <regex>;
#include "randomNumber.h";
using std::cout;
using std::cin;
using std::floor;
using std::rand;
using std::string;
using std::regex;
using std::regex_match;

bool isValidCharacter(string input) {
	if (regex_match(input, regex("^[A-Za-z]+$"))) {
		cout << "\n" << input << " appears to a valid character.\n";
		return true;
	}
	return false;
}

bool letterPlayed(string letter, string allInputs) {
	if (allInputs.length() <= 0)return false;
	for (int i = 0; i < allInputs.length(); i++) {
		string strIn = string(1, allInputs[i]);
		if (regex_match(letter, regex(strIn))) {
			return true;
		}
	}
	return false;
}

bool allPlayed(string gameWord, string allInputs) {
	if (gameWord.length() <= 0)return false;
	if (allInputs.length() <= 0)return false;
	int matchNum = 0;
	for (int q = 0; q < gameWord.length(); q++) {
		string letter = string(1, gameWord[q]);
		for (int i = 0; i < allInputs.length(); i++) {
			string strIn = string(1, allInputs[i]);
			if (regex_match(letter, regex(strIn))) {
				matchNum++;
			}
		}
	}
	return matchNum == gameWord.length();
}

int main() {
	int const wordLength = 7;
	string words[wordLength] = { "apple", "bat", "cord", "drug", "elephant", "foster", "geriatic" };
	string allInputs = " ", gameWord = " ";
	char input = 'a';
	int lives = 3, rndmNum = 0;
	bool gameEnd = false, gamerestart = false;
	while(!gameEnd){
		allInputs = "";
		gamerestart = false;
		rndmNum = random_number(0, wordLength);
		gameWord = words[rndmNum];
		int gameWordLength = gameWord.length();
		while(!gamerestart){
			cout << "Please type a single character.\nNo special characters are used.\n\n";
			cout << "You have " << lives << " tries remaining.\n\n";
			cout << "Current:";
			for (int i = 0; i < gameWordLength; i++) {
				char wordLetter = gameWord[i];
				if (letterPlayed(string(1, wordLetter), allInputs)) {
					cout << " " << wordLetter << " ";
				}
				else {
					cout << " _ ";
				}
			}
			cout << "\n";
			cout << "Your letter?:";
			cin >> input;
			string strIn = string(1, input);
			if (!letterPlayed(strIn, allInputs) && letterPlayed(strIn, gameWord)) {
				cout << "Correct letter played.\n";
			}
			else {
				lives--;
				if (lives > 0) {
					cout << "Wrong letter played.\nYou have lost a letter attempt.\nBe wary...\n\n";
				}
				else {
					cout << "You have no more tries left.\nYou have failed this game.\nDo you want to restart?(y for yes):";
					cin >> input;
					if (input == 'y') {
						gamerestart = true;
					}
					else {
						gameEnd = true;
						break;
					}
					cout << "\n";
				}
			}
			allInputs += strIn;
			if (allPlayed(gameWord, allInputs)) {
				cout << "Success:";
				for (int i = 0; i < gameWordLength; i++) {
					char wordLetter = gameWord[i];
					if (letterPlayed(string(1, wordLetter), allInputs)) {
						cout << " " << wordLetter << " ";
					}
					else {
						cout << " _ ";
					}
				}
				cout << "\n\n";
				cout << "Unfortunately, you have won.\nWould you like to play again?(y for yes):";
					cin >> input;
				if (input == 'y') {
					gamerestart = true;
				}
				else {
					gameEnd = true;
					break;
				}
				cout << "\n";
			}
		}
	}
	cout << "Hangman game has ended.\nThanks for playing!\nBye bye!\n\n";
	return 0;
}