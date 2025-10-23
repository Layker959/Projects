//Задание 1
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() 
{
    int count;
    cout << "Number of people" << endl;
    cin >> count;
    vector<pair<int, string>> people;

    for (int i = 0; i < count; ++i) 
    {
        string name;
        int age;
        cin >> name >> age;
        people.push_back(make_pair(age, name));
    }

    sort(people.begin(), people.end());
    reverse(people.begin(), people.end());

    for (const auto& person : people) 
    {
        cout << person.second << endl;
    }

    return 0;
}
