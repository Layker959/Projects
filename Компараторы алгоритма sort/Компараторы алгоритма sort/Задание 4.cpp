#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
	string name;
	int mark;
};

bool compareStudents(const Student& s1, const Student& s2)
{
	return s1.mark > s2.mark;
}

int main()
{
	vector<Student> students;

	string name;
	int mark;

	while (true)
	{
		try
		{
			cout << "Enter student name: ";
			cin >> name;
			if (name.empty())
			{
				throw invalid_argument("Invalid input");
			}

			cout << "Enter student mark: ";
			cin >> mark;
			if (mark < 0 || mark > 100)
			{
				throw invalid_argument("Invalid input");
			}

			students.push_back({ name, mark });
		}
		catch (invalid_argument& e)
		{
			cout << "Error: " << e.what() << "n" << endl;;
			cout << "Please try again";
		}

		cout << "Do you want to enter another student? (y/n): ";
		char choice;
		cin >> choice;

		if (choice != 'y' && choice != 'Y')
		{
			break;
		}
	}

	sort(students.begin(), students.end(), compareStudents);

	for (const Student& student : students)
	{
		cout << student.name << " got a mark of " << student.mark << "n" << endl;;
	}

	return 0;
}
