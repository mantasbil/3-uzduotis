#include "mediana.h"


float mediana(std::vector <float> pazymiai)
{
    float median;
    int n = pazymiai.size();
    std::sort(pazymiai.begin(), pazymiai.end());
    if (n % 2 == 0) median = (pazymiai[n / 2] + pazymiai[n / 2 + 1]) / 2.0;
    else median = pazymiai[n / 2];
    return median;
}