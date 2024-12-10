#include "Pipe.h"
#include <string>
#include "utils.h"


using namespace std;

int Pipe::MaxId = 1;

void Pipe::EditPipeState() {
	state = !state;
}

ostream& operator << (ostream& out, const Pipe& p)
{
	out << "Pipe's number: " << p.id << endl
		<< "Pipe's name: " << p.name << endl
		<< "Pipe's length: " << p.length << endl
		<< "Pipe's diameter: " << p.diameter << endl
		<< "Pipe's state: " << (p.state ? "Under repair" : "In progress") << endl;
	return out;


}

istream& operator >> (istream& in, Pipe& p)
{
	p.id = p.MaxId++;
	cout << "Write the name of the pipe: ";
	INPUT_LINE(in, p.name);
	cout << "Write the length of the pipe: ";
	p.length = GetCorrectNumber(1, 100000);

	cout << "Write the diameter of the pipe: ";
	p.diameter = GetCorrectNumber(1, 100000);

	cout << "Is the pipe being repaired? (Yes - 1, No - 0): ";
	p.state = GetCorrectNumber(0, 1);

	return in;
}
;

ofstream& operator << (ofstream& fout, const Pipe& p)
{
	if (p.name != "None")
	{
		fout << p.id << endl 
			<< p.name << endl
			<< p.length << endl
			<< p.diameter << endl
			<< p.state << endl;
	}
	return fout;
}
std::ifstream& operator>>(std::ifstream& fin, Pipe& p)
{
	fin >> p.id;
	fin >> ws;
	getline(fin, p.name);
	fin >> p.length;
	fin >> p.diameter;
	fin >> p.state;

	return fin;
}

int Pipe::GetPipeID()
{
	return id;
}

