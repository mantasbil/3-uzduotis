#pragma once
#include "studentas.h"
#include "write_to_file.h"
#include <chrono>
#include <iostream>
#include <string>
#include <list>
#include <algorithm>


bool is_lower(const studentas& a, const studentas& b);
bool islaike(studentas& s);
void vector_dalijimas_1(std::vector<studentas>& studentai);
void vector_dalijimas_2(std::vector<studentas>& studentai);
void list_dalijimas_1(std::list<studentas>& studentai);
void list_dalijimas_2(std::list<studentas>& studentai);

