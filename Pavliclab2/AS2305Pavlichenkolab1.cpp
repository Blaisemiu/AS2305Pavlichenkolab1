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

struct CS
{
	string csname;
	int numberworkshop;
	int stateworkshop;
	int efficiency;
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
	cout << "Pipe's state: " << (p.state ? "Under repair" : "In progress") << endl;
}

void Editpipestate(Pipe& p)
{
	cout << "Current pipe state: " << (p.state ? "Under repair" : "In progress") << endl;
	cout << "Do you want to change the condition of the pipe? (Yes - 1, No - 0): ";
	bool newstate;
	while (!(cin >> newstate))
	{
		Correction();
	}

	if (newstate == 1)
	{
		p.state = !p.state;
		cout << "Pipe state changed";
	}
	else
	{
		cout << "The state of the pipe hasn't changed";
	}
	
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
	Editpipestate(pp);
	return x;
}