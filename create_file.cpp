#include "create_file.h"

using std::string;
using std::to_string;
using std::left;
using std::setw;
using std::ofstream;
using std::fixed;
using std::setprecision;
using std::endl;

void create_file(int kiekis)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1., 10.);
    double galutinis_random;

    string file_name = "Studentai" + to_string(kiekis) + ".txt";
    ofstream outfile(file_name);
    outfile << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(15) << "Galutinis" << endl;
    for (int i = 1; i <= kiekis; i++)
    {
        galutinis_random = dist(mt);
        outfile << left << setw(20) << "Vardas" + to_string(i)
            << left << setw(20) << "Pavarde" + to_string(i)
            << left << setw(20) << fixed << setprecision(2) << galutinis_random << endl;
    }
}