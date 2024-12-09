#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Pipe.h"
#include "CS.h"
#include <unordered_map>
#include <unordered_set>
#include "utils.h"

void AddPipe(std::unordered_map<int, Pipe>& pipes);
void ViewPipes(const std::unordered_map<int, Pipe>& pipes);
void AddCS(std::unordered_map<int, CS>& cses);
void ViewCSes(const std::unordered_map<int, CS>& cses);
void DeletePipe(std::unordered_map<int, Pipe>& pipes);
void DeleteCS(std::unordered_map<int, CS>& cses);
void SavePipe(std::unordered_map<int, Pipe>& pipes);
void SaveCS(std::unordered_map<int, CS>& cses);
void SaveAll(std::unordered_map<int, Pipe>& pipes, std::unordered_map<int, CS>& cses);
void LoadPipe(std::unordered_map<int, Pipe>& pipes, int NumPipe);
void LoadCS( std::unordered_map<int, CS>& cses, int NumCS);
void LoadAll( std::unordered_map<int, Pipe>& pipes, std::unordered_map<int, CS>& cses);
