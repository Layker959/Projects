/*
// ������� 2
#include <iostream>
#include <string>
#include <array>
using namespace std;

enum class monsters
{
	Skeleton = 1,
	Troll,
	Ogre,
	Goblin,
	Beastling
};

void printMonster(monsters monster)
{
	srand(time(0));

	int start = 0;
	int end = 4;
	int rnd = rand() % (end - start + 1) + start;

	string skelname[] = { "SANS","Skel","Bony","Narrow","Skull" };
	string Trollname[] = { "Trollolo","Simon","Bober","Bridgeman","Trotro" };
	string Ogrename[] = { "Shrek","Fiona","Fiz","Og'Og","Arg'og" };
	string Goblinname[] = { "GobGob","Goldlin","Bogigi","Hobgob","Bagbear" };
	string Beastlingname[] = { "Woof","Woo","Foo","Boo","Torvega" };
	switch (monster)
	{
	case monsters::Skeleton:
		if (skelname[rnd] == "SANS")
			cout << "�� ��������� ������� Skeleton " << skelname[rnd] << " �� ��������� 1" << endl;
		else
			cout << "�� ��������� Skeleton " << skelname[rnd] << " �� ��������� 10" << endl;
		break;
	case monsters::Troll:
		if (Trollname[rnd] == "Trollolo")
			cout << "�� ��������� ������� Troll " << Trollname[rnd] << " �� ��������� 101" << endl;
		else
			cout << "�� ��������� Troll " << Trollname[rnd] << " �� ��������� 50" << endl;
		break;
	case monsters::Ogre:
		if (Ogrename[rnd] == "Shrek")
			cout << "�� ��������� ������� Ogre " << Ogrename[rnd] << " �� ��������� 20" << endl;
		else
			cout << "�� ��������� Ogre " << Ogrename[rnd] << " �� ��������� 60" << endl;
		break;
	case monsters::Goblin:
		if (Goblinname[rnd] == "Goldlin")
			cout << "�� ��������� ������� Goblin " << Goblinname[rnd] << " �� ��������� 30" << endl;
		else
			cout << "�� ��������� Goblin " << Goblinname[rnd] << " �� ��������� 20" << endl;
		break;
	case monsters::Beastling:
		if (Beastlingname[rnd] == "Torvega")
			cout << "�� ��������� ������� Beastling " << Beastlingname[rnd] << " �� ��������� 1000" << endl;
		else
			cout << "�� ��������� Beastling " << Beastlingname[rnd] << " �� ��������� 100" << endl;
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "�������� ��� �������" << endl;
	cout << "1. Skeleton" << endl;
	cout << "2. Troll" << endl;
	cout << "3. Ogre" << endl;
	cout << "4. Goblin" << endl;
	cout << "5. Beastling" << endl;
	int d;
	cin >> d;
	printMonster(static_cast<monsters>(d));
}
*/