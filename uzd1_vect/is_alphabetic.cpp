#include "is_alphabetic.h"

bool is_alphabetic(std::string vardas)
{
    return std::all_of(vardas.begin(), vardas.end(), isalpha);
}