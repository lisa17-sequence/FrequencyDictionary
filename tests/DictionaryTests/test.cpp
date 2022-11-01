#include "pch.h"
#include "../../src/FrequencyDictionary.h"

TEST(TestCaseName, TestName) {
	dictionary::Dictionary dictionary("file");
	int count = dictionary.CounterOfWords("word");

	ASSERT_EQ(count, 1);
}