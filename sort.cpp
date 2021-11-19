#include "sort.h"

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::list;

bool is_lower(const studentas& a, const studentas& b)
{
	return a.galutinis_vid < b.galutinis_vid;
}

bool islaike(studentas& s)
{
	return s.galutinis_vid >= 5;
}

void vector_dalijimas_1(std::vector<studentas>& studentai)
{
    int kiek = studentai.size();
    vector<studentas> galvociai;
	vector<studentas> vargsiukai;
    galvociai.reserve(0.6 * kiek);
    vargsiukai.reserve(0.6 * kiek);
    auto start2 = std::chrono::high_resolution_clock::now();
    for (studentas& stud : studentai)
    {
        if (stud.galutinis_vid < 5)
        {
            vargsiukai.push_back(stud);
        }
        else
            galvociai.push_back(stud);
    }
    studentai.clear();

    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2 - start2;
    cout << kiek << " studentu suskirstymas i dvi grupes 1-a strategija uztruko " << diff2.count() << " s" << endl;

    string vargsiukai_file_name = "Vargsiukai" + to_string(kiek) + "_vect.txt";
    vector_write(vargsiukai, vargsiukai_file_name);
    vargsiukai.clear();

    string galvociai_file_name = "Galvociai" + to_string(kiek) + "_vect.txt";
    vector_write(galvociai, galvociai_file_name);
    galvociai.clear();
}

void vector_dalijimas_2(std::vector<studentas>& studentai)
{
    int kiekis = studentai.size();
    vector<studentas> vargsiukai;
    vargsiukai.reserve(0.6 * kiekis);
    std::sort(studentai.begin(), studentai.end(), is_lower);
    auto start2 = std::chrono::high_resolution_clock::now();
    vector<studentas>::iterator it = std::find_if(studentai.begin(), studentai.end(), islaike);
    vargsiukai = vector<studentas>(studentai.begin(), it);
    vector<studentas>::iterator it1 = studentai.begin();
    studentai.erase(studentai.begin(), it);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2 - start2;
    cout << kiekis << " studentu suskirstymas i dvi grupes 2-a strategija uztruko " << diff2.count() << " s" << endl;

    string vargsiukai_file_name = "Vargsiukai" + to_string(kiekis) + "_vect.txt";
    vector_write(vargsiukai, vargsiukai_file_name);
    vargsiukai.clear();

    string galvociai_file_name = "Galvociai" + to_string(kiekis) + "_vect.txt";
    vector_write(studentai, galvociai_file_name);
    studentai.clear();
}
void list_dalijimas_1(std::list<studentas>& studentai)
{
    int kiekis = studentai.size();
    list<studentas> galvociai;
    list<studentas> vargsiukai;
    auto start2 = std::chrono::high_resolution_clock::now();

    for (studentas& stud : studentai)
    {
        if (stud.galutinis_vid < 5)
        {
            vargsiukai.push_back(stud);
        }
        else
            galvociai.push_back(stud);
    }

    studentai.clear();
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2 - start2;
    cout << kiekis << " studentu suskirstymas i dvi grupes 1-a strategija uztruko " << diff2.count() << " s" << endl;

    string vargsiukai_file_name = "Vargsiukai" + to_string(kiekis) + "_list.txt";
    list_write(vargsiukai, vargsiukai_file_name);
    vargsiukai.clear();
    string galvociai_file_name = "Galvociai" + to_string(kiekis) + "_list.txt";
    list_write(galvociai, galvociai_file_name);
    galvociai.clear();
}

void list_dalijimas_2(std::list<studentas>& studentai)
{
    int kiekis = studentai.size();
    list<studentas> vargsiukai;
    studentai.sort(is_lower);
    auto start2 = std::chrono::high_resolution_clock::now();
    list<studentas>::iterator lit = std::find_if(studentai.begin(), studentai.end(), islaike);
    vargsiukai = list<studentas>(studentai.begin(), lit);
    studentai.erase(studentai.begin(), lit);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2 - start2;
    cout << kiekis << " studentu suskirstymas i dvi grupes 2-a strategija uztruko " << diff2.count() << " s" << endl;

    string vargsiukai_file_name = "Vargsiukai" + to_string(kiekis) + "_list.txt";
    list_write(vargsiukai, vargsiukai_file_name);
    vargsiukai.clear();
    string galvociai_file_name = "Galvociai" + to_string(kiekis) + "_list.txt";
    list_write(studentai, galvociai_file_name);
    studentai.clear();
}