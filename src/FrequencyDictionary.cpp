#include "FrequencyDictionary.h"

namespace dictionary
{
	std::vector<std::string> Dictionary::MakeWordsSeparated(std::string textAtString)
	{
		std::string separatedWord = "";
		std::vector<std::string> sequenceOfWords{};
		for (int i = 0; i < textAtString.length() - 1; ++i) {
			if (textAtString[i] != '\n' and textAtString[i] != ' ' and textAtString[i] != '.' and textAtString[i] != ',' and textAtString[i] != ';' and textAtString[i] != ':' and textAtString[i] != '!' and textAtString[i] != '?' and textAtString[i] != '-' and textAtString[i] != '(' and textAtString[i] != ')' and textAtString[i] != '"') {
				separatedWord += textAtString[i];
			}
			else {
				if (separatedWord != "" and separatedWord != " " and separatedWord[0] != ' ') {
					sequenceOfWords.push_back(separatedWord);
					separatedWord = "";
				}
			}
		}
		return sequenceOfWords;
	}

	//std::vector<std::string> Dictionary::MakeWordsSeparatedBoost(std::string textAtString)
	//{
	//	std::vector<std::string> sequenceOfWords{};
	//	boost::char_separator<char> sep(" .,;:!?-()""");
	//	boost::tokenizer<boost::char_separator<char>> tok(textAtString, sep);
	//	for (auto it = tok.begin(); it != tok.end(); it++) {
	//		sequenceOfWords.push_back(*it);
	//	}
	//	return sequenceOfWords;
	//}

	std::string Dictionary::ReadTextFromFile(std::string nameOfFile)
	{
		std::string textAtString;
		std::string line;
		std::ifstream text_For_Read(nameOfFile);
		if (text_For_Read.is_open()) {
			std::cout << "Successful file upload" << '\n';
			while (std::getline(text_For_Read, line)) {
				textAtString += line + '\n';
				++counter_Of_Lines;
			}
		}
		else
			std::cout << "There's an error of reading the file";
		text_For_Read.close();
		return textAtString;
	}

	void Dictionary::PrintTheCounterOfWordsMap(std::map<std::string, int> countOfWords)
	{
		for (auto it = countOfWords.begin(); it != countOfWords.end(); it++)
			std::cout << it->first << ' ' << it->second << '\n';

	}

	std::map<std::string, int> Dictionary::CounterOfWords()
	{
		std::map<std::string, int> countOfWords{};
		for (auto& words : sequenceOfWords) {
			++countOfWords[words];
		}
		PrintTheCounterOfWordsMap(countOfWords);
		return countOfWords;
	}

	int Dictionary::CounterOfWords(std::string key)
	{
		std::map<std::string, int> countOfWords{};
		for (auto& words : sequenceOfWords) {
			++countOfWords[words];
		}
		const auto found = countOfWords.find(key);
		if (found == countOfWords.end()) {
			std::cout << "The word was not found." << '\n';
			return -1;
		}
		std::cout << key << " went into text " << countOfWords[key] << " times" << '\n';
		return countOfWords[key];
	}

}