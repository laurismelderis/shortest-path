#include "Utils.h"

using namespace std;

vector<string> Utils::seperate(string str, char delimiter)
{
	vector<string> words;
	string word;
	for (int i = 0; i < str.length(); i++)
	{
		char c = str[i];
		if (i == str.length() - 1)
		{
			word += c;
			words.push_back(word);
			break;
		}
		if (c == delimiter)
		{
			words.push_back(word);
			word = "";
			continue;
		}
		word += c;
	}
	return words;
}