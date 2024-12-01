// Pavliclab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include "Pipe.h"
#include "CS.h"
#include <unordered_map>

using namespace std;

void AddPipe(unordered_map<int, Pipe>& pipes)
{
	Pipe pipe;
	cin >> pipe;
	pipes.emplace(pipe.GetPipeID(), pipe);
	cout << "Pipe added with number: " << pipe.GetPipeID() << endl;
}

void ViewPipes(const unordered_map<int, Pipe>& pipes)
{
	if (pipes.empty())
	{
		cout << "No pipes available." << endl;
		return;
	}

	for (const auto& [id, pipe] : pipes)
	{
		cout << "Number of pipe: " << id << "\n" << pipe << endl;
	}
}

void AddCS(unordered_map<int, CS>& cses)
{
	CS cs;
	cin >> cs;
	cses.emplace(cs.GetCSID(), cs);
	cout << "CS added with number: " << cs.GetCSID() << endl;
}

void ViewCSes(const unordered_map<int, CS>& cses)
{
	if (cses.empty())
	{
		cout << "No CSes available." << endl;
		return;
	}

	for (const auto& [id, cs] : cses)
	{
		cout << "Number of cs: " << id << "\n" << cs << endl;
	}
}




//void ChangingWorkshopsInOperation(CS& s)
//{
//		cout << "Number of workshop in operation: " << s.numberworkshop << endl;
//		cout << "Do you want to start or stop the workshop? (1 - start, 0 - stop): ";
//		bool choice;
//		int numberofchages;
//		while (!(cin >> choice))
//		{
//			//Correction();
//		}
//		if (choice == 1)
//		{
//			cout << "Write how many workshops to start: ";
//			while (!(cin >> numberofchages) || (s.numberworkshopinoperation + numberofchages) > s.numberworkshop || numberofchages < 0)
//			{
//				//Correction();
//			}
//			s.numberworkshopinoperation += numberofchages;
//		}
//		else
//		{
//			cout << "Write how many workshops to stop: ";
//			while (!(cin >> numberofchages) || (s.numberworkshopinoperation - numberofchages) < 0 || numberofchages < 0)
//			{
//				//Correction();
//			}
//			s.numberworkshopinoperation -= numberofchages;
//		}
//
//		cout << "Number of workshop in operation: " << s.numberworkshopinoperation << endl;
//
//}

void Menu()
{
	cout << "1.Add pipe\n"
		<< "2.Add compressor station\n"
		<< "3.View all objects\n"
		<< "4.Edit pipe state\n"
		<< "5.Edit the number of working workshops\n"
		<< "6.Save data to file\n"
		<< "7.Load data from file\n"
		<< "8.Exit\n"
		<< "Enter menu number: ";
}









int main()
{
	int number;
	Pipe pipe;
	CS cs;
	unordered_map < int, Pipe> pipes;
	unordered_map <int, CS> cses;
	

	while (1)
	{
		Menu();
		while (!(cin >> number))
		{
			//Correction();
			continue;
		}

		switch (number)
		{
		case 1:
			AddPipe(pipes);
			break;
		case 2:
			AddCS(cses);
			break;
		case 3:
			ViewPipes(pipes);
			ViewCSes(cses);
			/*cout << cs;
			if (pipe.length == 0)
				cout << "The pipe was not created" << endl;
			else*/
				//OutputPipe(pipe);
			//if (cs.numberworkshop == 0)
			//	cout << "The compressor station was not created" << endl;
			//else
			//	//OutputCS(cs);
			break;
		case 4:
			//if (pipe.length == 0)
			//	cout << "The pipe was not created" << endl;
			//else
			//	//EditPipeState(pipe);
			break;
		case 5:
			//if (cs.numberworkshop == 0)
			//	cout << "The compressor station was not created" << endl;
			//else
			//	//ChangingWorkshopsInOperation(cs);
			break;
		case 6:
		{
			ofstream fout;
			fout.open("data.txt", ios::out);
			if (fout.is_open())
			{
				//SaveDataPipe(fout, pipe);
				//SaveDataCS(fout, cs);
				fout.close();
				cout << "Data saved to file" << endl;
			}
			else
				cout << "Error! Failed to write data to file" << endl;
			break;
		}
		case 7:
		{
			ifstream fin;
			fin.open("data.txt", ios::in);
			if (fin.is_open())
			{
				//LoadDataPipe(fin, pipe);
				//LoadDataCS(fin, cs);
				cout << "Data load from file" << endl;
			}
			else
				cout << "Error! Failed to load data from file" << endl;
		}
		case 8:
			return 0;
		default:
		{
			cout << "no action" << endl;
			break;
		}
		}
	}
	return 0;
}