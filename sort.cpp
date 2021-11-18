#include "sort.h"

bool is_lower(const studentas& a, const studentas& b)
{
	return a.galutinis_vid < b.galutinis_vid;
}

bool islaike(studentas& s)
{
	return s.galutinis_vid >= 5;
}