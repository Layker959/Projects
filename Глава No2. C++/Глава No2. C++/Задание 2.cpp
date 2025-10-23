/*
// Задание 2
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
			cout << "Вы встретели Элитный Skeleton " << skelname[rnd] << " со здоровьем 1" << endl;
		else
			cout << "Вы встретели Skeleton " << skelname[rnd] << " со здоровьем 10" << endl;
		break;
	case monsters::Troll:
		if (Trollname[rnd] == "Trollolo")
			cout << "Вы встретели Элитный Troll " << Trollname[rnd] << " со здоровьем 101" << endl;
		else
			cout << "Вы встретели Troll " << Trollname[rnd] << " со здоровьем 50" << endl;
		break;
	case monsters::Ogre:
		if (Ogrename[rnd] == "Shrek")
			cout << "Вы встретели Элитный Ogre " << Ogrename[rnd] << " со здоровьем 20" << endl;
		else
			cout << "Вы встретели Ogre " << Ogrename[rnd] << " со здоровьем 60" << endl;
		break;
	case monsters::Goblin:
		if (Goblinname[rnd] == "Goldlin")
			cout << "Вы встретели Элитный Goblin " << Goblinname[rnd] << " со здоровьем 30" << endl;
		else
			cout << "Вы встретели Goblin " << Goblinname[rnd] << " со здоровьем 20" << endl;
		break;
	case monsters::Beastling:
		if (Beastlingname[rnd] == "Torvega")
			cout << "Вы встретели Элитный Beastling " << Beastlingname[rnd] << " со здоровьем 1000" << endl;
		else
			cout << "Вы встретели Beastling " << Beastlingname[rnd] << " со здоровьем 100" << endl;
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Выберите тип монстра" << endl;
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