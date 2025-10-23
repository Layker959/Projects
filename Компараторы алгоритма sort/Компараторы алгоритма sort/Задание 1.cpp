/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Document
{
	int id;
	double relevance;
	int rating;
};
void SortDocuments(vector<Document>& matched_documents)
{
	sort(matched_documents.begin(), matched_documents.end(),
		[](const Document& lhs, const Document& rhs)
		{
			if (lhs.rating == rhs.rating)
			{
				return lhs.relevance < rhs.relevance;
			}
			else
			{
				return lhs.rating > rhs.rating;
			};
		}
	);
}
int main()
{
	vector<Document> documents =
	{
	{100, 0.5, 4},
	{101, 1.2, 4},
	{102, 0.3, 5}
	};
	SortDocuments(documents);
	for (const Document& document : documents)
	{
		cout << document.id << ' '
			<< document.relevance << ' '
			<< document.rating << endl;
	}
}
*/