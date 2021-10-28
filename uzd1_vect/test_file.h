#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>
#include <list>
#include "studentas.h"

void create_file(int kiekis);
void vector_write(std::vector<studentas>& v, std::string file_name);
void list_write(std::list<studentas>& l, std::string file_name);
void list_test(int kiekis);
void vector_test(int kiekis);
