#include "CSV.h"
#include "Utils.h"

using namespace std;

// https://java2blog.com/read-csv-file-in-cpp/#:~:text=To%20read%20a%20CSV%20file%2C,variable%20as%20its%20second%20argument.
vector<string> CSV::read(string fileName)
{
	vector<string> content;
	string line, word;

	fstream file(fileName, ios::in);

	if (file.is_open())
	{
		while (getline(file, line))
		{
			for (char c : line)
			{
				if (c == ',')
				{
					c = ' ';
				}
			}
			content.push_back(line);
		}
	}
	else {
		cout << "Could not open file: " << fileName << endl;
	}

	return content;
}

void CSV::print(vector<string> content)
{
	for (string el: content)
	{
		vector<string> words = Utils::seperate(el, ',');
		for (auto word : words)
		{
			cout << word << " ";
		}
		cout << endl;
	}
}