#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <fstream>
#include <sstream> 
#include <random>
#include "studentas.h"
#include "mediana.h"
#include "is_alphabetic.h"
#include "compare_alphabet.h"
#include "student_print.h"
#include "rand_int.h"
#include "create_file.h"
#include "write_to_file.h"
#include "test_file.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std::accumulate;
using std::ifstream;
using std::getline;
using std::stringstream;

int main()
{
    float vid, med;
    int kiek;
    string input_type, galutinis_type, read_type, generate;
    studentas temp_student;
    vector <studentas> grupe;

    cout << "Jeigu norite testuoti sparta spauskite T, jei ne - N ";
    cin >> generate;
    do {
        try {
            if (generate != "t" && generate != "T" && generate != "n" && generate != "N") throw std::runtime_error("Neatpazinta komanda");
        }
        catch (std::runtime_error& e) {
            cout << e.what() << endl;
            cin.clear();
            cout << "Pasirinkite T arba N ";
            cin >> generate;
        }
    } while (generate != "t" && generate != "T" && generate != "n" && generate != "N");
    if (generate == "T" || generate == "t")
    {
        cout << "Iveskite studentu skaiciu: ";
        cin >> kiek;
        do {
            try {
                if (kiek <= 0) throw std::runtime_error("Skaicius turi buti didesnis uz 0");
            }
            catch (std::runtime_error& e) {
                cout << e.what() << endl;
                cin.clear();
                cout << "Iveskite studentu skaiciu is naujo: ";
                cin >> kiek;
            }
        } while (kiek <= 0);
        create_file(kiek);
        list_test(kiek);
        vector_test(kiek);

    }
    if (generate == "N" || generate == "n")
    {
        cout << "Jei norite duomenis nuskaityti is failo spauskite F.\nJei norite ivesti ranka, spauskite R. ";
        cin >> read_type;
        do {
            try {
                if (read_type != "F" && read_type != "f" && read_type != "R" && read_type != "r") throw std::runtime_error("Neatpazinta komanda");
            }
            catch (std::runtime_error& e) {
                cout << e.what() << endl;
                cin.clear();
                cout << "Pasirinkite F arba R ";
                cin >> read_type;
            }
        } while (read_type != "F" && read_type != "f" && read_type != "R" && read_type != "r");

        if (read_type == "F" || read_type == "f")
        {
            int rows = 0, cols = 0;
            float temp_paz;
            string eil, item;
            ifstream open_f("kursiokai.txt");
            try {
                if (open_f.fail()) throw std::runtime_error("Nepavyko atidaryti failo");
            }
            catch (std::runtime_error& e) {
                cout << e.what() << endl;;
                exit(1);
            }
            while (open_f)
            {
                if (!open_f.eof())
                {
                    getline(open_f, eil);
                    rows++;
                    if (rows == 1)
                    {
                        stringstream ss(eil);
                        while (ss >> item) cols++;
                    }
                    open_f >> temp_student.vardas >> temp_student.pavarde;
                    temp_student.nd.reserve(cols - 3);
                    for (int j = 0; j < cols - 3; j++)
                    {
                        open_f >> temp_paz;
                        try {
                            if (temp_paz < 1 || temp_paz > 10) throw std::runtime_error("Pazymiai turi buti nuo 1 iki 10. Patikrinkite faila");
                        }
                        catch (std::runtime_error& e) {
                            cout << e.what() << endl;
                            exit(1);
                        }
                        temp_student.nd.push_back(temp_paz);
                    }
                    open_f >> temp_student.egz;
                    try {
                        if (temp_student.egz < 1 || temp_student.egz > 10) throw std::runtime_error("Egzamino pazymys turi buti nuo 1 iki 10. Patikrinkite faila");
                    }
                    catch (std::runtime_error& e) {
                        cout << e.what() << endl;
                        exit(1);
                    }

                    vid = accumulate(temp_student.nd.begin(), temp_student.nd.end(), 0.0) / temp_student.nd.size();
                    temp_student.galutinis_vid = 0.4 * vid + 0.6 * temp_student.egz;
                    med = mediana(temp_student.nd);
                    temp_student.galutinis_med = 0.4 * med + 0.6 * temp_student.egz;
                    grupe.push_back(temp_student);
                    temp_student.nd.clear();
                }
                else break;
            }

            open_f.close();
        }

        if (read_type == "R" || read_type == "r")
        {
            cout << "Jei norite, kad studentu pazymiai butu generuojami automatiskai spauskite \"R\".\nJei norite pazymius suvesti pats spauskite \"P\".";
            cin >> input_type;
            do {
                try {
                    if (input_type != "R" && input_type != "r" && input_type != "P" && input_type != "p") throw std::runtime_error("Neatpazinta komanda");
                }
                catch (std::runtime_error& e) {
                    cout << e.what() << endl;
                    cin.clear();
                    cout << "Pasirinkite R arba P ";
                    cin >> input_type;
                }
            } while (input_type != "R" && input_type != "r" && input_type != "P" && input_type != "p");
            int n, x;
            float laik_paz;
            cout << "Iveskite studentu skaiciu: ";
            cin >> n;
            do {
                try {
                    if (n <= 0) throw std::runtime_error("Studentu turi buti daugiau nei 0");
                }
                catch (std::runtime_error& e) {
                    cout << e.what() << endl;
                    cin.clear();
                    cout << "Iveskite studentu skaiciu ";
                    cin >> n;
                }
            } while (n <= 0);
            for (int i = 0; i < n; i++)
            {
                cout << "Iveskite " << i + 1 << " -o studento varda ir pavarde : ";
                cin >> temp_student.vardas >> temp_student.pavarde;
                do {
                    try {
                        if (!is_alphabetic(temp_student.vardas) || !is_alphabetic(temp_student.pavarde)) throw std::runtime_error("Varde ir pavardeje turi buti tik raides");
                    }
                    catch (std::runtime_error& e)
                    {
                        cout << e.what() << endl;
                        cin.clear();
                        cout << "Iveskite varda ir pavarde ";
                        cin >> temp_student.vardas >> temp_student.pavarde;
                    }
                } while (!is_alphabetic(temp_student.vardas) || !is_alphabetic(temp_student.pavarde));
                if (input_type == "R" || input_type == "r")
                {
                    cout << "Iveskite " << i + 1 << " -o studento namu darbu kieki : ";
                    cin >> x;
                    do {
                        try {
                            if (x <= 0) throw std::runtime_error("Namu darbu kiekis turi buti didesnis uz 0");
                        }
                        catch (std::runtime_error& e) {
                            cout << e.what() << endl;
                            cin.clear();
                            cout << "Iveskite nd kieki ";
                            cin >> x;
                        }
                    } while (x <= 0);
                    temp_student.nd.reserve(x);
                    for (int j = 0; j < x; j++)
                    {
                        temp_student.nd.push_back(rand_int());
                    }
                    temp_student.egz = rand_int();
                    vid = accumulate(temp_student.nd.begin(), temp_student.nd.end(), 0.0) / temp_student.nd.size();
                    temp_student.galutinis_vid = 0.4 * vid + 0.6 * temp_student.egz;
                    med = mediana(temp_student.nd);
                    temp_student.galutinis_med = 0.4 * med + 0.6 * temp_student.egz;
                    grupe.push_back(temp_student);
                    temp_student.nd.clear();
                }
                if (input_type == "P" || input_type == "p")
                {
                    cout << "Iveskite namu darbu pazymius: ";
                    while (cin >> laik_paz)
                    {
                        do {
                            try {
                                if (laik_paz < 1 || laik_paz > 10) throw std::runtime_error("Pazymys turi buti nuo 1 iki 10");
                            }
                            catch (std::runtime_error& e) {
                                cout << e.what() << endl;;
                                cin.clear();
                                cout << "Iveskite pazymi is naujo ";
                                cin >> laik_paz;
                            }
                        } while (laik_paz < 1 || laik_paz > 10);
                        temp_student.nd.push_back(laik_paz);
                    }
                    if (temp_student.nd.empty())
                    {
                        cout << "Privaloma ivesti namu darbu rezultatus";
                        return 1; //Jei neivedami namu darbu pazymiai, programa stabdoma.
                    }
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Iveskite " << i + 1 << "-o studento egzamino pazymi : ";
                    cin >> temp_student.egz;
                    do {
                        try {
                            if (temp_student.egz < 1 || temp_student.egz > 10) throw std::runtime_error("Pazymys turi buti nuo 1 iki 10");
                        }
                        catch (std::runtime_error& e) {
                            cout << e.what() << endl;
                            cin.clear();
                            cout << "Iveskite egzamino pazymi ";
                            cin >> temp_student.egz;
                        }
                    } while (temp_student.egz < 1 || temp_student.egz > 10);
                    vid = accumulate(temp_student.nd.begin(), temp_student.nd.end(), 0.0) / temp_student.nd.size();
                    temp_student.galutinis_vid = 0.4 * vid + 0.6 * temp_student.egz;
                    med = mediana(temp_student.nd);
                    temp_student.galutinis_med = 0.4 * med + 0.6 * temp_student.egz;
                    grupe.push_back(temp_student);
                    temp_student.nd.clear();
                }
            }
        }
        cout << "Jei norite, kad butu isvedamas galutinis pazymys pagal namu darbu vidurki, spauskite V.\nJei, pagal mediana spauskite M.";
        cin >> galutinis_type;
        do {
            try {
                if (galutinis_type != "V" && galutinis_type != "v" && galutinis_type != "M" && galutinis_type != "m") throw std::runtime_error("Neatpazinta komanda");
            }
            catch (std::runtime_error& e) {
                cout << e.what() << endl;
                cin.clear();
                cout << "Pasirinkite V arba M ";
                cin >> galutinis_type;
            }
        } while (galutinis_type != "V" && galutinis_type != "v" && galutinis_type != "M" && galutinis_type != "m");
        student_print(grupe, galutinis_type);
    }

    cin.get();

}