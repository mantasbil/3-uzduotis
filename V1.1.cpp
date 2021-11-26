#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream> 
#include <random>
#include "studentas.h"
#include "create_file.h"
#include "write_to_file.h"
#include "test_file.h"*/
#include "rand_int.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std::ifstream;
using std::getline;
using std::stringstream;

int main()
{
    float vid, med;
    int kiek;
    string input_type, galutinis_type, read_type, generate, vardas, pavarde;
    Studentas temp_student;
    vector <Studentas> grupe;
    vector<double> nd;
    double egz, gal;

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

        test(kiek);
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
        cout << "Jei norite galutini pazymi skaiciuoti pagal namu darbu vidurki, spauskite V. \nJei pagal mediana, spauskite M. ";
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
                    open_f >> vardas >> pavarde;
                    temp_student.setVardas(vardas);
                    temp_student.setPavarde(pavarde);
                    nd.reserve(cols - 3);
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
                        nd.push_back(temp_paz);
                    }
                    temp_student.setNd(nd);
                    open_f >> egz;
                    try {
                        if (egz < 1 || egz > 10) throw std::runtime_error("Egzamino pazymys turi buti nuo 1 iki 10. Patikrinkite faila");
                    }
                    catch (std::runtime_error& e) {
                        cout << e.what() << endl;
                        exit(1);
                    }
                    temp_student.setEgzaminas(egz);
                    gal = galutinis(temp_student, galutinis_type);
                    temp_student.setGalutinis(gal);
                    grupe.push_back(temp_student);
                    nd.clear();
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
                cin >> vardas >> pavarde;
                do {
                    try {
                        if (!is_alphabetic(vardas) || !is_alphabetic(pavarde)) throw std::runtime_error("Varde ir pavardeje turi buti tik raides");
                    }
                    catch (std::runtime_error& e)
                    {
                        cout << e.what() << endl;
                        cin.clear();
                        cout << "Iveskite varda ir pavarde ";
                        cin >> vardas >> pavarde;
                    }
                } while (!is_alphabetic(vardas) || !is_alphabetic(pavarde));
                temp_student.setVardas(vardas);
                temp_student.setPavarde(pavarde);
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
                    nd.reserve(x);
                    for (int j = 0; j < x; j++)
                    {
                        nd.push_back(rand_int());
                    }
                    temp_student.setNd(nd);
                    egz = rand_int();
                    temp_student.setEgzaminas(egz);
                    gal = galutinis(temp_student, galutinis_type);
                    temp_student.setGalutinis(gal);
                    grupe.push_back(temp_student);
                    nd.clear();
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
                        nd.push_back(laik_paz);
                    }
                    if (nd.empty())
                    {
                        cout << "Privaloma ivesti namu darbu rezultatus";
                        return 1; //Jei neivedami namu darbu pazymiai, programa stabdoma.
                    }
                    cin.clear();
                    cin.ignore(10000, '\n');
                    temp_student.setNd(nd);
                    cout << "Iveskite " << i + 1 << "-o studento egzamino pazymi : ";
                    cin >> egz;
                    do {
                        try {
                            if (egz < 1 || egz > 10) throw std::runtime_error("Pazymys turi buti nuo 1 iki 10");
                        }
                        catch (std::runtime_error& e) {
                            cout << e.what() << endl;
                            cin.clear();
                            cout << "Iveskite egzamino pazymi ";
                            cin >> egz;
                        }
                    } while (egz < 1 || egz > 10);
                    temp_student.setEgzaminas(egz);
                    gal = galutinis(temp_student, galutinis_type);
                    temp_student.setGalutinis(gal);
                    grupe.push_back(temp_student);
                    nd.clear();
                }
            }
        }
        student_print(grupe);
    }

    cin.get();

}