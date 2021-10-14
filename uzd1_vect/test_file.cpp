#include "test_file.h"

void test_file(int kiekis)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1., 10.);
    double galutinis_random;

    auto start_test = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::high_resolution_clock::now();
    std::string file_name = "Studentai" + std::to_string(kiekis) + ".txt";
    std::ofstream outfile(file_name);
    outfile << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(15) << "Galutinis" << std::endl;
    for (int i = 1; i <= kiekis; i++)
    {
        galutinis_random = dist(mt);
        outfile << std::left << std::setw(20) << "Vardas" + std::to_string(i)
            << std::left << std::setw(20) << "Pavarde" + std::to_string(i)
            << std::left << std::setw(20) << std::fixed << std::setprecision(2) << galutinis_random << std::endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Failo su " << kiekis << " studentu sukurimas uztruko " << diff.count() << " s" << std::endl;
    std::vector<studentas> studentai;
    std::vector<studentas> galvociai;
    std::vector<studentas> vargsiukai;



    studentas temp;
    std::string eil;
    auto start1 = std::chrono::high_resolution_clock::now();
    studentai.resize(kiekis);
    std::ifstream openf("Studentai" + std::to_string(kiekis) + ".txt");
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
    std::cout << "Failo su " << kiekis << " studentu nuskaitymas uztruko " << diff1.count() << " s" << std::endl;

    auto start2 = std::chrono::high_resolution_clock::now();
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
    std::cout << kiekis << " studentu suskirstymas i dvi grupes uztruko " << diff2.count() << " s" << std::endl;

    auto start3 = std::chrono::high_resolution_clock::now();
    std::string vargsiukai_file_name = "Vargsiukai" + std::to_string(kiekis) + ".txt";
    std::string galvociai_file_name = "Galvociai" + std::to_string(kiekis) + ".txt";
    std::ofstream outfile_v(vargsiukai_file_name);
    outfile_v << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(15) << "Galutinis" << std::endl;
    for (int j = 0; j < vargsiukai.size(); j++)
    {
        outfile_v << std::left << std::setw(20) << vargsiukai[j].vardas
            << std::left << std::setw(20) << vargsiukai[j].pavarde
            << std::left << std::setw(15) << vargsiukai[j].galutinis_vid << std::endl;;
    }
    vargsiukai.clear();
    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff3 = end3 - start3;
    std::cout << kiekis << " studentu surasymas i vargsiuku faila uztruko " << diff3.count() << " s" << std::endl;

    auto start4 = std::chrono::high_resolution_clock::now();
    std::ofstream outfile_g(galvociai_file_name);
    outfile_g << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(15) << "Galutinis" << std::endl;
    for (int j = 0; j < galvociai.size(); j++)
    {
        outfile_g << std::left << std::setw(20) << galvociai[j].vardas
            << std::left << std::setw(20) << galvociai[j].pavarde
            << std::left << std::setw(15) << galvociai[j].galutinis_vid << std::endl;
    }
    galvociai.clear();
    auto end4 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff4 = end4 - start4;
    std::cout << kiekis << " studentu surasymas i galvociu uztruko " << diff4.count() << " s" << std::endl;

    auto end_test = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> test_time = end_test - start_test;
    std::cout << kiekis << " irasu testo laikas " << test_time.count() << " s" << std::endl;
}