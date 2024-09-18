// Pavliclab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

struct Pipe
{
	string name;
	int length;
	int diameter;
	bool state;
};

void Correct();

Pipe Createpipe()
{
	Pipe p;
	cout << "Write the name of the pipe: ";
	cin >> p.name;

	cout << "Write the length of the pipe: ";

	while (!(cin >> p.length))
	{
		Correct();
	}

	cout << "Write the diameter of the pipe: ";
	while (!(cin >> p.diameter))
	{
		Correct();
	}

	cout << "Write the sing of the pipe: ";
	while (!(cin >> p.state))
	{
		Correct();
	}
	return p;
};

void Outputpipe(Pipe p)
{

	cout << "Pipe's name: " << p.name;
}

void Correct()
{
	cin.clear();
	cin.ignore();
	cout << "Enter correct information: ";
}

int main()
{
	int x = 0;
	Pipe pp = Createpipe();
	Outputpipe(pp);
	return x;
}