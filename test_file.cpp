#include "test_file.h"

using std::cout;
using std::left;
using std::setw;
using std::endl;
using std::fixed;
using std::setprecision;
using std::cin;
using std::string;
using std::to_string;
using std::ofstream;
using std::ifstream;
using std::vector;
using std::list;

void test(int kiekis)
{
    int strat;
    cout << endl;
    cout << "Vector strukturos rezultatai:" << endl;
    auto start1 = std::chrono::high_resolution_clock::now();
    Studentas temp;
    vector<Studentas> studentai;
    string vard, pav;
    double gal;
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
    for (auto& i : studentai)
    {
        openf >> vard >> pav >> gal;
        temp.setVardas(vard);
        temp.setPavarde(pav);
        temp.setGalutinis(gal);
        studentai.push_back(temp);
    }
    openf.close();
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1 - start1;
    cout << "Failo su " << kiekis << " studentu nuskaitymas uztruko " << diff1.count() << " s" << endl;

    vector<Studentas> vargsiukai;
    vargsiukai.reserve(0.6 * kiekis);
    std::sort(studentai.begin(), studentai.end(), compare_mark);
    auto start2 = std::chrono::high_resolution_clock::now();
    vector<Studentas>::iterator it = std::find_if(studentai.begin(), studentai.end(), islaike);
    vargsiukai = vector<Studentas>(studentai.begin(), it);
    vector<Studentas>::iterator it1 = studentai.begin();
    studentai.erase(studentai.begin(), it);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2 - start2;
    cout << kiekis << " studentu suskirstymas i uztruko " << diff2.count() << " s" << endl;

    string vargsiukai_file_name = "Vargsiukai" + to_string(kiekis) + ".txt";
    write(vargsiukai, vargsiukai_file_name);
    vargsiukai.clear();

    string galvociai_file_name = "Galvociai" + to_string(kiekis) + ".txt";
    write(studentai, galvociai_file_name);
    studentai.clear();

}

