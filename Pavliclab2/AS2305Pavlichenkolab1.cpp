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
	int numberworkshopinoperation;
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
	cout << "\n";
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
	cout << "\n";
}

CS CreateCS()
{
	CS s;
	cout << "Write the name of the compressor station: ";
	cin >> ws;
	getline(cin, s.csname);

	cout << "Write the number of workshops: ";
	while (!(cin >> s.numberworkshop))
	{
		Correction();
	}

	cout << "Write the number of workshops in operation: ";
	while (!(cin >> s.numberworkshopinoperation) || s.numberworkshopinoperation > s.numberworkshop)
	{
		Correction();
	}

	cout << "Write the efficiency of the station (from 0 to 1000): ";
	while (!(cin >> s.efficiency) || s.efficiency < 0 || s.efficiency > 1000)
	{
		Correction();
	}
	cout << "\n";
	return s;
}

void OutputCS(CS s)
{
	cout << "Compressor Station's name: " << s.csname << endl;
	cout << "Number of workshop : " << s.numberworkshop << endl;
	cout << "Number of workshop in operation: " << s.numberworkshopinoperation << endl;
	cout << "The effeciency of the station: " << s.efficiency << endl;
	cout << "\n";
}

void Changingworkshopsinoperation(CS& s)
{
	cout << "Number of workshop in operation: " << s.numberworkshop << endl;
	cout << "Do you want to start or stop the workshop? (1 - start, 0 - stop): ";
	bool choice;
	int numberofchages;
	while (!(cin >> choice))
	{
		Correction();
	}
	if (choice == 1)
	{
		cout << "Write how many workshops to start: ";
		while (!(cin >> numberofchages) || (s.numberworkshopinoperation + numberofchages) > s.numberworkshop || numberofchages < 0)
		{
			Correction();
		}
		s.numberworkshopinoperation += numberofchages;
	}
	else
	{
		cout << "Write how many workshops to stop: ";
		while (!(cin >> numberofchages) || (s.numberworkshopinoperation - numberofchages) < 0 || numberofchages < 0)
		{
			Correction();
		}
		s.numberworkshopinoperation -= numberofchages;
	}

	cout << "Number of workshop in operation: " << s.numberworkshopinoperation << endl;

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
	CS ss = CreateCS();
	Outputpipe(pp);
	OutputCS(ss);
	Editpipestate(pp);
	Changingworkshopsinoperation(ss);

	return x;
}