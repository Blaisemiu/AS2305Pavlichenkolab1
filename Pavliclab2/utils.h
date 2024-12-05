#pragma once
#include <iostream>
#include "Pipe.h"
#include "CS.h"
#include <unordered_map>
#include <unordered_set>


template <typename T>
T GetCorrectNumber(T min, T max)
{
	T x;
	while ((std::cin >> x).fail() || x < min || x>max)
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Type number (" << min << "-" << max << "):";
	}
	return x;
}


#define INPUT_LINE(in, str) getline(in>>std::ws, str);


template<typename T>
using FilterPipe = bool(*)(const Pipe& p, T param);

bool CheckPipeName(const Pipe& p, std::string param);

bool CheckPipeState(const Pipe& p, bool param);


template<typename T>
std::unordered_set<int> PipeFind(const std::unordered_map<int, Pipe>& pipes, FilterPipe<T> f, T param)
{
	std::unordered_set <int> PipeRes;
	for (auto& p : pipes)
	{
		if (f(p.second, param))
		{
			PipeRes.emplace(p.first);
			std::cout << "Pipe's number: " << p.first << std::endl;
			std::cout << p.second << std::endl;
		}
	}
	return PipeRes;
}

template<typename T>
using FilterCS = bool(*)(const CS& s, T param);

bool CheckCSName(const CS& s, std::string param);

bool CheckCSWorkshop(const CS& s, int param);

template<typename T>
std::unordered_set<int> CSFind(const std::unordered_map<int, CS>& cses, FilterCS<T> f, T param)
{
	std::unordered_set <int> CSRes;
	for (auto& s : cses)
	{
		if (f(s.second, param))
		{
			CSRes.emplace(s.first);
			std::cout << "CS's number: " << s.first << std::endl;;
			std::cout << s.second << std::endl;
		}
	}
	return CSRes;
}

void ChangePipeId(std::unordered_map<int, Pipe>& pipes, const std::unordered_set<int>& Piperes);
void ChangeCSId(std::unordered_map<int, CS>& cses, const std::unordered_set<int>& CSes);
void DeletePipeId(std::unordered_map<int, Pipe>& pipes, const std::unordered_set<int>& Piperes);
void DeleteCSId(std::unordered_map<int, CS>& cses, const std::unordered_set<int>& CSes);

