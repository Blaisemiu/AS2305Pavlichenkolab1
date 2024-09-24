// Pavliclab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

struct Pipe
{
	string name;
	int length;
	int diameter;
	bool state;
};

void Correction();

Pipe Createpipe()
{
	Pipe p;
	cout << "Write the name of the pipe: ";
	cin >> ws;
	getline(cin,p.name);

	cout << "Write the length of the pipe: ";

	while (!(cin >> p.length) || p.length <= 0)
	{
		Correction();
	}

	cout << "Write the diameter of the pipe: ";
	while (!(cin >> p.diameter) || p.diameter <= 0)
	{
		Correction();
	}

	cout << "Is the pipe being repaired? (Yes - 1, No - 0): ";
	while (!(cin >> p.state))
	{
		Correction();
	}
	cout << "\n";
	return p;
};

void Outputpipe(Pipe p)
{
	cout << "Pipe's name: " << p.name << endl;
	cout << "Pipe's length: " << p.length << endl;
	cout << "Pipe's diameter: " << p.diameter << endl;
	cout << "Pipe's state: " << (p.state ? "Under repair\n" : "In progress\n");
}

void Correction()
{
	cin.clear();
	cin.ignore(10000, '\n');
	cout << "Enter correct information: ";
}

int main()
{
	int x = 0;
	Pipe pp = Createpipe();
	Outputpipe(pp);
	return x;
}