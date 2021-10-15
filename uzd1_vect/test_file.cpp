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

void test_file(int kiekis)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1., 10.);
    double galutinis_random;

    auto start_test = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::high_resolution_clock::now();
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
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo su " << kiekis << " studentu sukurimas uztruko " << diff.count() << " s" << endl;
    
    auto start1 = std::chrono::high_resolution_clock::now();
    vector<studentas> studentai;
    string eil;
    studentai.resize(kiekis);
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
    for (int i = 0; i < kiekis; i++)
    {
        if (studentai[i].galutinis_vid < 5.) vargsiukai.push_back(studentai[i]);
        else galvociai.push_back(studentai[i]);
    }
    studentai.clear();
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2 - start2;
    cout << kiekis << " studentu suskirstymas i dvi grupes uztruko " << diff2.count() << " s" << endl;

    auto start3 = std::chrono::high_resolution_clock::now();
    string vargsiukai_file_name = "Vargsiukai" + to_string(kiekis) + ".txt";
    
    ofstream outfile_v(vargsiukai_file_name);
    outfile_v << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(15) << "Galutinis" << endl;
    for (int j = 0; j < vargsiukai.size(); j++)
    {
        outfile_v << left << setw(20) << vargsiukai[j].vardas
            << left << setw(20) << vargsiukai[j].pavarde
            << left << setw(15) << vargsiukai[j].galutinis_vid << endl;;
    }
    vargsiukai.clear();
    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff3 = end3 - start3;
    cout << kiekis << " studentu surasymas i vargsiuku faila uztruko " << diff3.count() << " s" << endl;

    auto start4 = std::chrono::high_resolution_clock::now();
    string galvociai_file_name = "Galvociai" + to_string(kiekis) + ".txt";
    ofstream outfile_g(galvociai_file_name);
    outfile_g << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(15) << "Galutinis" << endl;
    for (int j = 0; j < galvociai.size(); j++)
    {
        outfile_g << left << setw(20) << galvociai[j].vardas
            << left << setw(20) << galvociai[j].pavarde
            << left << setw(15) << galvociai[j].galutinis_vid << endl;
    }
    galvociai.clear();
    auto end4 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff4 = end4 - start4;
    cout << kiekis << " studentu surasymas i galvociu uztruko " << diff4.count() << " s" << endl;

    auto end_test = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> test_time = end_test - start_test;
    cout << kiekis << " irasu testo laikas " << test_time.count() << " s" << endl;
}