#include "CS.h"
using namespace std;

ostream& operator << (ostream& out, const CS& s)
{
	out << "Name: " << s.csname << endl;
	return out;
}

istream& operator >> (istream& in, CS& s)
{
	cout << "Type name: ";
	in >> s.csname;
	return in;
};