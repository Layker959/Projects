/*
#include <iostream>
#include <numeric> // для accumulate
#include <vector>

using namespace std;

double Average(const vector<int>& xs)
{
	if (xs.empty())
	{
		return 0;
	}
	else
	{
		int result = accumulate(xs.begin(), xs.end(), 0.0);
		return result;
	}
}

int main()
{
	cout << Average({ 1, 2, 3 }) << endl;
	return 0;
}
*/