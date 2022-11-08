#include "pch.h"
#include "../FrequencyDictionary/src/FrequencyDictionary.h"
#include "CppUnitTest.h"

TEST(TestCaseName, TestName) {
	dictionary::Dictionary d("text.txt");
	int c = d.CounterOfWords("Hello");
	ASSERT_EQ(c, 1);
}