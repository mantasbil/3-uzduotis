#include "test_file.h"
#include "rand_int.h"
#include<sstream>;

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
    std::stringstream buff;
    buff << openf.rdbuf();
    openf.close();
    getline(buff, eil);
    for (auto& i : studentai)
    {
        i.readStudent(buff);
    }
    //openf.close();
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1 - start1;
    cout << "Failo su " << kiekis << " studentu nuskaitymas uztruko " << diff1.count() << " s" << endl;

    vector<Studentas> vargsiukai;
    //vargsiukai.reserve(0.6 * kiekis);
    std::sort(studentai.begin(), studentai.end(), compare_mark);
    auto start2 = std::chrono::high_resolution_clock::now();
    vector<Studentas>::iterator it = std::find_if(studentai.begin(), studentai.end(), islaike);
    vargsiukai = vector<Studentas>(studentai.begin(), it);
    vargsiukai.shrink_to_fit();
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

