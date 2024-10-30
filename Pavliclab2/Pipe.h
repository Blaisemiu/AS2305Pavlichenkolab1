#pragma once
#include <iostream>
#include <fstream>


class Pipe
{
private:
	std::string name;
	int length = 0;
	int diameter = 0;
	bool state = false;

public:
	void EditPipeState();

	friend std::ostream& operator << (std::ostream& out, const Pipe& pipe);
	friend std::istream& operator >> (std::istream& in, Pipe& pipe);
	//friend std::ofstream& operator << (std::ofstream& fout, const Pipe& pipe);
	//friend std::ifstream& operator >> (std::ifstream& fin, Pipe& pipe);
};

