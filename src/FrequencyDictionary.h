#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
//#include <boost/tokenizer.hpp>

namespace dictionary {
	class Dictionary
	{
	private:
		int counter_Of_Lines = 0;
		std::vector<std::string> sequenceOfWords;
		std::string textAtString;
		std::vector<std::string> MakeWordsSeparated(std::string textAtString);
		//std::vector<std::string> MakeWordsSeparatedBoost(std::string textAtString);
		std::string ReadTextFromFile(std::string nameOfFile);
		void PrintTheCounterOfWordsMap(std::map<std::string, int>);
	public:
		std::map<std::string, int> CounterOfWords();
		int CounterOfWords(std::string key);

		Dictionary(std::string FileName) {
			textAtString = ReadTextFromFile(FileName);
			sequenceOfWords = MakeWordsSeparated(textAtString);
		}

		//Dictionary(std::string FileName, std::string) {
		//	textAtString = ReadTextFromFile(FileName);
		//	sequenceOfWords = MakeWordsSeparatedBoost(textAtString);
		//}


	};
}
