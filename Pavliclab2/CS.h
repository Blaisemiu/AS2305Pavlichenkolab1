#pragma once
#include <iostream>
#include <fstream>


class CS
{
private:
	std::string csname;
	int numberworkshop = 0;
	int numberworkshopinoperation = 0;
	int efficiency = 0;
public:
	void ChangingWorkshopsInOperation();

	friend std::ostream& operator << (std::ostream& out, const CS& cs);
	friend std::istream& operator >> (std::istream& in, CS& cs);
	//friend std::ofstream& operator << (std::ofstream& fout, const CS& cs);
	//friend std::ifstream& operator >> (std::ifstream& fin, CS& cs);
};

