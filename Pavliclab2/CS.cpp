#include "CS.h"
#include "utils.h"
#include <string>
using namespace std;

int CS::CSMaxId = 1;

ostream& operator << (ostream& out, const CS& s)
{
	out << "Compressor Station's name: " << s.csname << endl 
		<< "Number of workshop : " << s.numberworkshop << endl 
		<< "Number of workshop in operation: " << s.numberworkshopinoperation << endl 
		<< "The effeciency of the station: " << s.efficiency << endl;
	return out;
}

istream& operator >> (istream& in, CS& s)
{	
	s.id = s.CSMaxId++;
	cout << "Write the name of the compressor station: ";
	cin >> ws;
	getline(in, s.csname);

	cout << "Write the number of workshops: ";
	s.numberworkshop = GetCorrectNumber(1, 100000);

	cout << "Write the number of workshops in operation: ";
	s.numberworkshopinoperation = GetCorrectNumber(1, 100000);

	cout << "Write the efficiency of the station (from 0 to 1000): ";
	s.efficiency = GetCorrectNumber(0, 1000);
	cout << "\n";

	return in;
}
std::ofstream& operator<<(std::ofstream& fout, const CS& s)
{
	if (s.csname != "None")
	{
		fout << s.csname << endl
			<< s.numberworkshop << endl
			<< s.numberworkshopinoperation << endl
			<< s.efficiency << endl;
	}
	return fout;
}
std::ifstream& operator>>(std::ifstream& fin, CS& s)
{
	fin >> ws;
	getline(fin, s.csname);
	fin >> s.numberworkshop;
	fin >> s.numberworkshopinoperation;
	fin >> s.efficiency;
	return fin;
};

int CS::GetCSID()
{
	return id;
}
