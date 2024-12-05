#pragma once
#include <iostream>
#include <fstream>
#include <unordered_map>


class Pipe
{
private:
	static int MaxId;
	int id = 0;
	std::string name = "None";
	int length = 0;
	int diameter = 0;
	bool state = false;

public:

	void EditPipeState();
	int GetPipeID();
	std::string GetName() const { return name; }
    int GetLength() const { return length; }
    int GetDiameter() const { return diameter; }
    bool GetState() const { return state; }
	int GetMaxId() const { return MaxId; }


	friend std::ostream& operator << (std::ostream& out, const Pipe& p);
	friend std::istream& operator >> (std::istream& in, Pipe& p);
	friend std::ofstream& operator << (std::ofstream& fout, const Pipe& p);
	friend std::ifstream& operator >> (std::ifstream& fin, Pipe& p);
};

