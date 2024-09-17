// Pavliclab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

struct Pipe
{
	string name;
	int length;
	int diameter;
	bool sing;
};

Pipe Createdpipe()
{
	Pipe p;
	cout << "Write the name of the pipe: ";
	cin >> p.name;

	cout << "Write the length of the pipe: ";
	cin >> p.length;

	cout << "Write the diameter of the pipe: ";
	cin >> p.diameter;

	cout << "Write the sing of the pipe: ";
	cin >> p.sing;
	return p;
};

int main()
{
	int x = 0;
	Pipe pp = Createdpipe();
	return x;
}