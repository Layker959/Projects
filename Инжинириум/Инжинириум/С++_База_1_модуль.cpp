/*
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int count = 0;
	int longest = -1;
	string s;
	cin >> s; //последовательность
	s += "1";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '0')
		{
			count++;

		}
		else {
			
			if (count > longest)
			{
				longest = count;
			}
			else 
			{
			}
			count = 0;
		}
	}

	cout << longest << endl;
	return 0;
}
*/