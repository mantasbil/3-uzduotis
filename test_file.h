#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
#include <list>
#include <algorithm>
#include "studentas.h"

void create_file(int kiekis);
void write(std::vector<Studentas>& v, std::string file_name);
void test(int kiekis);
