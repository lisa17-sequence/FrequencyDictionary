#include "pch.h"
#include "../../src/FrequencyDictionary.h"
TEST(DictionaryValidationTests, EmptyTest) {
	dictionary::Dictionary testFile("text0.txt");
	int counter = testFile.CounterOfWords("Hello");
    ASSERT_EQ(counter, 0);
}

TEST(DictionaryValidationTests, OneWordTest) {
	dictionary::Dictionary testFile("text1.txt");
	int counter = testFile.CounterOfWords("One");
	ASSERT_EQ(counter, 1);
}

TEST(DictionaryValidationTests, AllTheWordsMarks) {
	dictionary::Dictionary testFile("text.txt");

	std::map<std::string, int> counter = testFile.CounterOfWords();
	std::map<std::string, int> expected = { {"Aren't", 1}, {"I", 4}, {"Moscow",4}, {"Motherland", 1}, {"Pangram", 1}, {"Sevastopol", 1}, {"The", 1},
	{"This", 1}, {"about", 1},{"and", 3}, {"around", 1}, {"brown", 1}, {"but", 1}, {"capital", 1}, {"dog",1}, {"everything", 1}, {"fox", 1}, {"gardens", 1},
	{"is", 1}, {"it", 1}, {"its", 1}, {"jumps", 1}, {"lazy", 1}, {"like", 2}, {"love", 2}, {"monuments", 1}, {"my", 1}, {"native", 1}, {"of", 2},{"our", 1}, 
	{"over", 1}, {"parks", 1}, {"quick", 1}, {"sculptures", 1}, {"squares",2}, {"the", 2}, {"tired", 1}, {"wandering", 1}, {"were", 1}, {"you", 1 } };
	ASSERT_EQ(counter, expected);
}