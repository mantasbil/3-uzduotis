#include "write_to_file.h"

using std::vector;
using std::string;
using std::ofstream;
using std::left;
using std::setprecision;
using std::setw;
using std::list;
using std::endl;

void write(vector<Studentas>& v, string file_name)
{
    ofstream outfile(file_name);
    outfile << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(15) << "Galutinis" << endl;
    for (Studentas s : v)
    {
        outfile << left << setw(20) << s.getVardas()
            << left << setw(20) << s.getPavarde()
            << left << setw(15) << s.getGalutinis() << endl;
    }
}