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

