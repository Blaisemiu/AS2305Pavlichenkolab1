// Pavliclab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include "Pipe.h"
#include "CS.h"
#include <unordered_map>
#include <unordered_set>
#include "utils.h"
#include "Func.h"
#include <chrono>
#include <format>

//using namespace chrono;
using namespace std;



void Menu()
{
	cout << "1.Add pipe\n"
		<< "2.Add compressor station\n"
		<< "3.View all objects\n"
		<< "4.Edit pipe state\n"
		<< "5.Edit the number of working workshops\n"
		<< "6.Save data to file\n"
		<< "7.Load data from file\n"
		<< "8.Delete pipe\n"
		<< "9.Delete compressor station\n"
		<< "10.Filter objects\n"
		<< "11.Exit\n"
		<< "Enter menu number: ";
}

void MenuFilter()
{
	cout << "1.Filter pipe by name\n"
		<< "2.Filter pipe by state\n"
		<< "3.Filter cs by name\n"
		<< "4.Filter cs by number of workstations in operation\n"
		<< "5.Return for main menu\n"
		<< "Enter menu number: ";
}

void MenuChoice()
{
	cout << "1. Edit objects\n"
		<< "2. Delete objects\n"
		<< "Enter menu number: ";
}





int main()
{
	redirect_output_wrapper cerr_out(cerr);
	string time = format("{:%d_%m_%Y %H_%M_%OS}", chrono::system_clock::now());
	ofstream logfile("log_" + time);
	if (logfile)
		cerr_out.redirect(logfile);

	unordered_map < int, Pipe> pipes;
	unordered_map <int, CS> cses;
	unordered_set<int> filtres;

	while (1)
	{
		Menu();
		int number = GetCorrectNumber(1, 11);

		switch (number)
		{
		case 1:
			AddPipe(pipes);
			break;
		case 2:
			AddCS(cses);
			break;
		case 3:
		{
			ViewPipes(pipes);
			ViewCSes(cses);
			break;
		}
		case 4:
		{
			Pipe pipe;
			cout << "Enter pipe number to edit state: ";
			int idp = GetCorrectNumber(1, pipe.GetMaxId());
			if (pipes.find(idp) != pipes.end())
			{
				pipes.at(idp).EditPipeState();
				cout << "State edit successfully" << endl;
			}
			else
			{
				cout << "Pipe with number " << idp << " not found" << endl;
			}
			break;
		}
		case 5:
		{
			CS cs;
			cout << "Enter compressor station ID to edit workshops in operation: ";
			int idc = GetCorrectNumber(1, cs.GetMaxId());

			if (cses.find(idc) != cses.end())
			{
				cses.at(idc).ChangeWorkshopsInOperation();
			}
			else
			{
				cout << "Compressor station with ID " << idc << " not found." << endl;
			}
			break;
		}
		case 6:
		{
		
			SaveAll(pipes, cses);
			break;
		}
		case 7:
		{	
			
			LoadAll(pipes, cses);
			break;
		}
		case 8:
			DeletePipe(pipes);
			break;
		case 9:
			DeleteCS(cses);
			break;
		case 10:
		{
			bool NewMenu = false;
			while (!NewMenu)
			{
				MenuFilter();
				number = GetCorrectNumber(1, 5);
				switch (number)
				{
				case 1:
					if (pipes.empty())
					{
						cout << "No pipes found";
						break;
					}
					else
					{
						string name;
						int choice;
						cout << "Enter the name for filter: ";
						INPUT_LINE(cin, name);
						filtres = PipeFind(pipes, CheckPipeName, name);
						MenuChoice();
						choice = GetCorrectNumber(1, 2);
						if (choice == 1)
						{
							ChangePipeId(pipes, filtres);
						}
						if (choice == 2)
						{
							DeletePipeId(pipes, filtres);
						}
					}
					break;
				case 2:
					if (pipes.empty())
					{
						cout << "No pipes found";
						break;
					}
					else
					{
						
						cout << "Enter the state for filter: ";
						bool state = GetCorrectNumber(0, 1);
						filtres = PipeFind(pipes, CheckPipeState, state);
						MenuChoice();
						int choice = GetCorrectNumber(1, 2);
						if (choice == 1)
						{
							ChangePipeId(pipes, filtres);
						}
						if (choice == 2)
						{
							DeletePipeId(pipes, filtres);
						}
					}
					break;
				case 3:
					if (cses.empty())
					{
						cout << "No cses found";
						break;
					}
					else
					{
						string name;
						cout << "Enter the name for filter: ";
						INPUT_LINE(cin, name);
						filtres = CSFind(cses, CheckCSName, name);
						MenuChoice();
						int choice = GetCorrectNumber(1, 2);
						if (choice == 1)
						{
							ChangeCSId(cses, filtres);
						}
						if (choice == 2)
						{
							continue;
						}
					}
					break;
				case 4:
					if (cses.empty())
					{
						cout << "No cses found";
						break;
					}
					else
					{
						cout << "Enter the workshops for filter: ";
						int workshops = GetCorrectNumber(1, 10000000);
						filtres = CSFind(cses, CheckCSWorkshop, workshops);
						MenuChoice();
						int choice = GetCorrectNumber(1, 2);
						if (choice == 1)
						{
							ChangeCSId(cses, filtres);
						}
						if (choice == 2)
						{
							continue;
						}
					}
					break;
				case 5:
					NewMenu = true;
					break;
				default:
					cout << "no action" << endl;
					break;
				}
			}
			break;
		}
		case 11:
			return 0;
			break;
		default:
		{
			cout << "no action" << endl;
			break;
		}
		}
	}
	return 0;
}