// Pavliclab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>

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


Pipe CreatePipe()
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

void OutputPipe(Pipe p)
{
	cout << "Pipe's name: " << p.name << endl;
	cout << "Pipe's length: " << p.length << endl;
	cout << "Pipe's diameter: " << p.diameter << endl;
	cout << "Pipe's state: " << (p.state ? "Under repair" : "In progress") << endl;
	cout << "\n";
}

void EditPipeState(Pipe& p)
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
	while (!(cin >> s.numberworkshop) || s.numberworkshop < 0)
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

void ChangingWorkshopsInOperation(CS& s)
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
		<< "3.Viev pipe\n"
		<< "4.Viev compressor stetion\n"
		<< "5.Edit pipe state\n"
		<< "6.Edit the number of working workshops\n"
		<< "7.Save data to file\n"
		<< "8.Load data from file\n"
		<< "9.Exit\n"
		<< "Enter menu number: ";
}

void SaveDataPipe(ofstream& fout, const Pipe& p)
{	
	if (p.length == 0)
		fout << "*" << endl;
	else
	{
		fout << "Pipe" << endl;
		fout << p.name << endl;
		fout << p.length << endl;
		fout << p.diameter << endl;
		fout << p.state << endl;
	}
}

void SaveDataCS(ofstream& fout, const CS& s)
{	
	if (s.numberworkshop < 0)
		fout << "*";
	else
	{
		fout << "CS" << endl;
		fout << s.csname << endl;
		fout << s.numberworkshop << endl;
		fout << s.numberworkshopinoperation << endl;
		fout << s.efficiency << endl;
	}
}

void LoadDataPipe(ifstream& fin, Pipe& p)
{	
	string label;
	fin >> ws;
	getline(fin, label);
	if (label == "Pipe")
	{
		fin >> p.name;
		fin >> p.length;
		fin >> p.diameter;
		fin >> p.state;
	}
	else
	{
		p = { "None", 0, 0, 0 };
	}
	
}

void LoadDataCS(ifstream& fin, CS& s)
{	
	string label;
	fin >> ws;
	getline(fin, label);
	if (label == "CS")
	{
		fin >> s.csname;
		fin >> s.numberworkshop;
		fin >> s.numberworkshopinoperation;
		fin >> s.efficiency;
	}
	else
	{
		s = { "None", 0, 0, 0 };
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
	int number;
	Pipe pipe = { "None", 0, 0, 0};
	CS cs = { "None", 0, 0, 0};
	

	do
	{
		Menu();
		cin >> number;
		switch (number)
		{
		case 1:
			pipe = CreatePipe();
			break;
		case 2:
			cs = CreateCS();
			break;
		case 3:
			if (pipe.length == 0)
				cout << "The pipe was not created" << endl;
			else
				OutputPipe(pipe);
			break;
		case 4:
			if (cs.numberworkshop == 0)
				cout << "The compressor station was not created" << endl;
			else
				OutputCS(cs);
			break;
		case 5:
			EditPipeState(pipe);
			break;
		case 6:
			ChangingWorkshopsInOperation(cs);
			break;
		case 7:
		{
			ofstream fout;
			fout.open("data.txt", ios::out);
			if (fout.is_open())
			{
				SaveDataPipe(fout, pipe);
				SaveDataCS(fout, cs);
				fout.close();
				cout << "Data saved to file" << endl;
			}
			else
				cout << "Error! Failed to write data to file" << endl;
			break;
		}
		case 8:
		{
			ifstream fin;
			fin.open("data.txt", ios::in);
			if (fin.is_open())
			{
				LoadDataPipe(fin, pipe);
				LoadDataCS(fin, cs);
				cout << "Data load from file" << endl;
			}
			else
				cout << "Error! Failed to load data from file" << endl;
		}
		}

	} while (number != 9);
	{
		return 0;
	}
}