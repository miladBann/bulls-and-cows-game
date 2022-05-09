#include <iostream>
#include <ctime>
#include <vector>
#include <string>

int main() {

	srand(time(0));

	int bullsCount = 0;
	int cowsCount = 0;

	std::vector <std::string> words = { "love", "smart", "action", "computer" };

	std::string chosenWord = words[rand() % 4];

	int lives = chosenWord.length();

	std::cout << "welcome to bulls and cows, try to guess the word!" << std::endl;

	bool end = false;
	while (end == false) {

		std::cout << "current word is " << chosenWord << std::endl;

		std::cout << "it's a " << chosenWord.length() << " letter word." << std::endl;
		std::cout << "you have " << lives << " lives left\n\n" << std::endl;

		std::string response;
		std::cin >> response;

		for (int i = 0; i < response.length(); ++i) {
			for (int j = 0; j < chosenWord.length(); ++j) {
				if (response.find(response[i]) == chosenWord.find(chosenWord[j]) && response[i] == chosenWord[j]) {
					//checks if the letter is in the chosen word and in the right place
					bullsCount += 1;
				}
				else if (response.find(response[i]) == chosenWord.find(chosenWord[j]) && response[i] != chosenWord[i]) {
					//checks if the letter is in the chosen word but in the wrong place
					cowsCount += 1;
				}
			}
		}

		std::cout << "you have " << bullsCount << " bulls and " << cowsCount << " cows." << std::endl;

		if (response == chosenWord) {
			std::cout << "that's right, the word is " << chosenWord << "\n\n" << std::endl;
			end = true;
		}
		else if (response != chosenWord && (bullsCount >= bullsCount / 2 || cowsCount >= cowsCount / 2)) {
			std::cout << "close!, but that's not the answer \n\n" << std::endl;

			bullsCount = 0;
			cowsCount = 0;

			lives -= 1;
			if (lives == 0) {
				end = true;
				std::cout << "\n\nGame Over." << std::endl;
			}
		}

	}

	return 0;
}