#include "test_file.h"

using std::cout;
using std::left;
using std::setw;
using std::endl;
using std::fixed;
using std::setprecision;
using std::string;
using std::to_string;
using std::ofstream;
using std::ifstream;
using std::vector;
using std::list;

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

void list_test(int kiekis)
{
    cout << endl;
    cout << "List strukturos rezultatai:" << endl;
    auto start1 = std::chrono::high_resolution_clock::now();
    studentas temp;
    list<studentas> studentai;
    list<studentas>::iterator it;
    it = studentai.begin();
    string eil;
    string file_name1, file_name2;
    int VargsiukuKiekis = 0, GalvociuKiekis = 0;
    ifstream openf("Studentai" + to_string(kiekis) + ".txt");
    try {
        if (openf.fail()) throw std::runtime_error("Nepavyko atidaryti failo");
    }
    catch (std::runtime_error& e) {
        std::cout << e.what();
        exit(1);
    }
    getline(openf, eil);
    for (int i = 0; i < kiekis; i++)
    {
        
        openf >> temp.vardas >> temp.pavarde >> temp.galutinis_vid;
        studentai.push_back(temp);
    }   
    openf.close();
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1 - start1;
    cout << "Failo su " << kiekis << " studentu nuskaitymas uztruko " << diff1.count() << " s" << endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    list<studentas> galvociai;
    list<studentas> vargsiukai;
    list<studentas>::iterator galv_it;
    list<studentas>::iterator varg_it;
    galv_it = galvociai.begin();
    varg_it = vargsiukai.begin();
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
    cout << kiekis << " studentu suskirstymas i dvi grupes uztruko " << diff2.count() << " s" << endl;

    string vargsiukai_file_name = "Vargsiukai" + to_string(kiekis) + "_list.txt";
    list_write(vargsiukai, vargsiukai_file_name);
    string galvociai_file_name = "Galvociai" + to_string(kiekis) + "_list.txt";
    list_write(galvociai, galvociai_file_name);
}


void vector_test(int kiekis)
{
    cout << endl;
    cout << "Vector strukturos rezultatai:" << endl;
    auto start1 = std::chrono::high_resolution_clock::now();

    vector<studentas> studentai;
    
    studentai.resize(kiekis);
    string eil;
    ifstream openf("Studentai" + to_string(kiekis) + ".txt");
    try {
        if (openf.fail()) throw std::runtime_error("Nepavyko atidaryti failo");
    }
    catch (std::runtime_error& e) {
        std::cout << e.what();
        exit(1);
    }
    getline(openf, eil);
    for (int i = 0; i < kiekis; i++)
    {
        openf >> studentai[i].vardas >> studentai[i].pavarde >> studentai[i].galutinis_vid;
    }
    openf.close();
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1 - start1;
    cout << "Failo su " << kiekis << " studentu nuskaitymas uztruko " << diff1.count() << " s" << endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    vector<studentas> galvociai;
    vector<studentas> vargsiukai;
    
    galvociai.reserve(0.6 * kiekis);
    vargsiukai.reserve(0.6 * kiekis);
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
    cout << kiekis << " studentu suskirstymas i dvi grupes uztruko " << diff2.count() << " s" << endl;


    string vargsiukai_file_name = "Vargsiukai" + to_string(kiekis) + "_vect.txt";
    vector_write(vargsiukai, vargsiukai_file_name);
    vargsiukai.clear();

    string galvociai_file_name = "Galvociai" + to_string(kiekis) + "_vect.txt";
    vector_write(galvociai, galvociai_file_name);
    galvociai.clear();

}

