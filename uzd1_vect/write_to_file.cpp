#include "write_to_file.h"

using std::vector;
using std::string;
using std::ofstream;
using std::left;
using std::setprecision;
using std::setw;
using std::list;
using std::endl;

void vector_write(vector<studentas>& v, string file_name)
{
    ofstream outfile(file_name);
    outfile << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(15) << "Galutinis" << endl;
    for (studentas s : v)
    {
        outfile << left << setw(20) << s.vardas
            << left << setw(20) << s.pavarde
            << left << setw(15) << s.galutinis_vid << endl;
    }
}

void list_write(list<studentas>& l, string file_name)
{
    ofstream outfile(file_name);
    outfile << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(15) << "Galutinis" << endl;
    for (studentas s : l)
    {
        outfile << left << setw(20) << s.vardas
            << left << setw(20) << s.pavarde
            << left << setw(15) << s.galutinis_vid << endl;
    }
}