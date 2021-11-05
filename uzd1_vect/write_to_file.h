#pragma once
#include "studentas.h"
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

void vector_write(std::vector<studentas>& v, std::string file_name);
void list_write(std::list<studentas>& l, std::string file_name);