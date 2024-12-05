#include "Func.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Pipe.h"
#include "CS.h"
#include <unordered_map>
#include <unordered_set>
#include "utils.h"

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

void DeletePipe(unordered_map<int, Pipe>& pipes)
{
	Pipe pipe;
	cout << "Enter the number of pipe to delete: ";
	int id = GetCorrectNumber(1, pipe.GetMaxId());

	if (pipes.find(id) != pipes.end())
	{
		pipes.erase(id);
		cout << "Pipe with number " << id << " deleted successfully" << endl;
	}
	else
	{
		cout << "Pipe with number " << id << " not found" << endl;
	}
}

void DeleteCS(unordered_map<int, CS>& cses)
{	
	CS cs;
	cout << "Enter the number of cs to delete: ";
	int id = GetCorrectNumber(1, cs.GetMaxId());

	if (cses.find(id) != cses.end())
	{
		cses.erase(id);
		cout << "CS with number " << id << " deleted successfully" << endl;
	}
	else
	{
		cout << "CS with number " << id << " not found" << endl;
	}
}

void SavePipe(ofstream& fout, unordered_map<int, Pipe>& pipes)
{
	for (const auto& [id, pipe] : pipes)
	{
		fout << id << endl;
		fout << pipe;
	}
}

void SaveCS(ofstream& fout,unordered_map<int, CS>& cses)
{
	ofstream fout;
	for (const auto& [id, cs] : cses)
	{
		fout << id << endl;
		fout << cs;
	}
}

void SaveAll(unordered_map<int, Pipe>& pipes, unordered_map<int, CS>& cses)
{
	ofstream fout;
	cout << "Please, enter the name of the file: ";
	string filename;
	INPUT_LINE(cin,filename);
	fout.open(filename);
	if (fout.is_open())
	{
		fout << pipes.size() << endl;
		fout << cses.size() << endl;
		SavePipe(fout, pipes);
		SaveCS(fout, cses);
		fout.close();
		cout << "Data saved to file" << endl;
	}
	else
	{
		cout << "Error! Failed to write data to file" << endl;
	}
}

void LoadPipe(ifstream& fin, unordered_map<int, Pipe>& pipes, int NumPipe)
{	

	for (int i = 0; i < NumPipe; i++)
	{
		int id;
		fin >> id;

		Pipe pipe;
		fin >> pipe;
		pipes.emplace(id, pipe);
	}
}

void LoadCS(ifstream& fin,unordered_map<int, CS>& cses, int NumCS)
{

	for (int i = 0; i < NumCS; i++)
	{
		int id;
		fin >> id;

		CS cs;
		fin >> cs;
		cses.emplace(id, cs);
	}
}

void LoadAll(unordered_map<int, Pipe>& pipes, unordered_map<int, CS>& cses)
{
	ifstream fin;
	int NumPipe = 0;
	int NumCS = 0;
	cout << "Please, enter the name of the file: ";
	string filename;
	INPUT_LINE(cin, filename);
	fin.open(filename);
	if (fin.is_open())
	{
		fin >> NumPipe;
		fin >> NumCS;
		LoadPipe(fin, pipes, NumPipe);
		LoadCS(fin, cses, NumCS);
		cout << "Data load from file" << endl;
	}
	else
		cout << "Error! Failed to load data from file" << endl;
}
