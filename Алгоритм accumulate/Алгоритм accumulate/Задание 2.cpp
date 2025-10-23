/*
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

extern string query = "some tasty oranges";
// или 
// static string query = "some tasty oranges"; глобальная переменная

string AddStopWords(const string& query, const vector<string>& stop_words)
{
	string result = query;
	vector<string> sorted_stop_words(stop_words);
	sort(sorted_stop_words.begin(), sorted_stop_words.end());
	for (const auto& stop_word : sorted_stop_words)
	{
		result += " -" + stop_word;
	}
	return result;
}

int main()
{
	vector<string> stop_words
	{
		"of", "in"
	};
	cout << AddStopWords(query, stop_words) << endl;
	return 0;
}
*/