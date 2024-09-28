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
	p.state = !p.state;
	cout << "Pipe state changed" << endl
		<< "New pipe state: " << (p.state ? "Under repair" : "In progress");
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

void Menu()
{
	cout << "1.Add pipe\n"
		<< "2.Add compressor station\n"
		<< "3.Viev all objects\n"
		<< "4.Edit pipe state\n"
		<< "5.Edit the number of working workshops\n"
		<< "6.Save data to file\n"
		<< "7.Load data to file\n"
		<< "8.Exit\n"
		<< "Enter menu number: ";
}

void Correction()
{
	cin.clear();
	cin.ignore(10000, '\n');
	cout << "Enter correct information: ";
}

int main()
{
	int number;
	Pipe pipe;
	CS cs;

	do
	{
		Menu();
		cin >> number;
		switch (number)
		{
		case 1:
			pipe = Createpipe();
			break;
		case 2:
			cs = CreateCS();
			break;
		case 3:
			Outputpipe(pipe);
			OutputCS(cs);
			break;
		case 4:
			Editpipestate(pipe);
			break;
		case 5:
			Changingworkshopsinoperation(cs);
			break;
		}

	} while (number != 8);
	{
		return 0;
	}
}