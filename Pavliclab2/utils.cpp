#include "utils.h"

using namespace std;

bool CheckPipeName(const Pipe& p, string param)
{
	return p.GetName().find(param) != string::npos;
}

bool CheckPipeState(const Pipe& p, bool param)
{
	return p.GetState() == param;
}


bool CheckCSName(const CS& s, string param)
{
	return s.GetCSName().find(param) != string::npos;
}

bool CheckCSWorkshop(const CS& s, int param)
{
	return s.GetWorkshopsInOperation() >= param;
}

void ChangePipeId(std::unordered_map<int, Pipe>& pipes, const std::unordered_set<int>& PipeRes)
{
	cout << "Do you want edit all or select number? (1 - all, 2 - select): ";
	int choice = GetCorrectNumber(1, 2);
	if (choice == 1)
	{
		for (int id : PipeRes)
		{
			pipes.at(id).EditPipeState();
			cout << "All objects succesfully changes\n";
		}
	}
	else
	{
		cout << "Enter the numbers of objects to change (separated by a space): ";
		unordered_set<int> ids;
		int id;

		while (cin >> id)
		{
			ids.emplace(id);
			if (cin.peek() == '\n') break;
		}
		for (int id : PipeRes)
		{
			if (ids.count(id) > 0)
			{
				pipes.at(id).EditPipeState();
				cout << "Object number " << id << " succesfully changes\n";
			}
		}
	}
}

void ChangeCSId(std::unordered_map<int, CS>& cses, const std::unordered_set<int>& CSRes)
{
	cout << "Do you want edit all or select number? (1 - all, 2 - select): ";
	int choice = GetCorrectNumber(1, 2);
	if (choice == 1)
	{
		for (int id : CSRes)
		{
			cses.at(id).ChangeWorkshopsInOperation();
			cout << "All objects succesfully changes\n";
		}
	}
	else
	{
		cout << "Enter the numbers of objects to change (separated by a space): ";
		unordered_set<int> ids;
		int id;

		while (cin >> id)
		{
			ids.emplace(id);
			if (cin.peek() == '\n') break;
		}

		for (int id : CSRes)
		{
			if (ids.count(id) > 0)
			{
				cses.at(id).ChangeWorkshopsInOperation();
				cout << "Object number " << id << " succesfully changes\n";
			}
		}
	}
}

void DeletePipeId(std::unordered_map<int, Pipe>& pipes, const std::unordered_set<int>& PipeRes)
{
	cout << "Do you want delete all or select number? (1 - all, 2 - select): ";
	int choice = GetCorrectNumber(1, 2);
	if (choice == 1)
	{
		for (int id : PipeRes)
		{
			pipes.erase(id);
			cout << "All objects succesfully delete\n";
		}
	}
	else
	{
		cout << "Enter the numbers of objects to delete (separated by a space): ";
		unordered_set<int> ids;
		int id;

		while (cin >> id)
		{
			ids.emplace(id);
			if (cin.peek() == '\n') break;
		}
		for (int id : PipeRes)
		{
			if (ids.count(id) > 0)
			{
				pipes.erase(id);
				cout << "Object number " << id << " succesfully delete\n";
			}
		}
	}
}

void DeleteCSId(std::unordered_map<int, CS>& cses, const std::unordered_set<int>& CSRes)
{
	cout << "Do you want delete all or select number? (1 - all, 2 - select): ";
	int choice = GetCorrectNumber(1, 2);
	if (choice == 1)
	{
		for (int id : CSRes)
		{
			cses.erase(id);
			cout << "All objects succesfully delete\n";
		}
	}
	else
	{
		cout << "Enter the numbers of objects to delete (separated by a space): ";
		unordered_set<int> ids;
		int id;

		while (cin >> id)
		{
			ids.emplace(id);
			if (cin.peek() == '\n') break;
		}
		for (int id : CSRes)
		{
			if (ids.count(id) > 0)
			{
				cses.erase(id);
				cout << "Object number " << id << " succesfully delete\n";
			}
		}
	}
}
