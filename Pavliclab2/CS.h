#pragma once
#include <iostream>
#include <fstream>
#include <unordered_map>


class CS
{
private:
	static int CSMaxId;
	int id = 0;
	std::string csname = "None";
	int numberworkshop = 0;
	int numberworkshopinoperation = 0;
	int efficiency = 0;
public:
	//void ChangingWorkshopsInOperation();
	int GetCSID();


	friend std::ostream& operator << (std::ostream& out, const CS& s);
	friend std::istream& operator >> (std::istream& in, CS& s);
	friend std::ofstream& operator << (std::ofstream& fout, const CS& s);
	friend std::ifstream& operator >> (std::ifstream& fin, CS& s);
};

