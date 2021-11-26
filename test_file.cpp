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


void list_test(int kiekis)
{
    int strat;
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

    cout << "Pasirinkite dalijimo strategija: 1 arba 2 ";
    cin >> strat;
    do {
        try {
            if (strat != 1 && strat != 2) throw std::runtime_error("Neatpazinta komanda");
        }
        catch (std::runtime_error& e) {
            cout << e.what() << endl;
            cin.clear();
            cout << "Bandykite is naujo ";
            cin >> strat;
        }
    } while (strat != 1 && strat != 2);
    if (strat == 1) list_dalijimas_1(studentai);
    if (strat == 2) list_dalijimas_2(studentai);
}


void vector_test(int kiekis)
{
    int strat;
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
    for (auto& i : studentai)
    {
        openf >> i.vardas >> i.pavarde >> i.galutinis_vid;
    }
    openf.close();
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1 - start1;
    cout << "Failo su " << kiekis << " studentu nuskaitymas uztruko " << diff1.count() << " s" << endl;

    cout << "Pasirinkite dalijimo strategija: 1 arba 2 ";
    cin >> strat;
    do {
        try {
            if (strat != 1 && strat != 2) throw std::runtime_error("Neatpazinta komanda");
        }
        catch (std::runtime_error& e) {
            cout << e.what() << endl;
            cin.clear();
            cout << "Bandykite is naujo ";
            cin >> strat;
        }
    } while (strat != 1 && strat != 2);
    if (strat == 1) vector_dalijimas_1(studentai);
    if (strat == 2) vector_dalijimas_2(studentai);

}

