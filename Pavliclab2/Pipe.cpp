#include "Pipe.h"
#include <string>
#include "utils.h"
using namespace std;

void Pipe::EditPipeState() {
	state = !state;
}

ostream& operator << (ostream& out, const Pipe& p)
{
	out << "Pipe's name: " << p.name << endl 
		<< "Pipe's length: " << p.length << endl
		<< "Pipe's diameter: " << p.diameter << endl
		<< "Pipe's state: " << (p.state ? "Under repair" : "In progress") << endl;
	return out;


}

istream& operator >> (istream& in, Pipe& p)
{	
	cout << "Write the name of the pipe: ";
	cin >> ws;
	getline(in, p.name);
	cout << "Write the length of the pipe: ";
	p.length = GetCorrectNumber(5, 100000);

	cout << "Write the diameter of the pipe: ";
	p.diameter = GetCorrectNumber(5, 100000);

	cout << "Is the pipe being repaired? (Yes - 1, No - 0): ";
	p.state = GetCorrectNumber(0, 1);

	return in;
};