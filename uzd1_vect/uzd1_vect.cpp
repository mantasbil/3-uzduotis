#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <time.h>
#include <numeric>
#include <fstream>
#include <sstream> 
#include <random>
#include "studentas.h"
#include "mediana.h"
#include "is_alphabetic.h"
#include "compare_alphabet.h"
#include "student_print.h"

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
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 10);
    float vid, med;
    string input_type, galutinis_type, read_type;
    studentas temp_student;
    vector <studentas> grupe;

    cout << "Jei norite duomenis nuskaityti is failo spauskite F.\nJei norite ivesti ranka, spauskite R. ";
    cin >> read_type;
    try {
        if (read_type == "F" || read_type == "f")
        {
            int rows = 0, cols = 0;
            float temp_paz;
            string eil, item;
            ifstream open_f("kursiokai.txt");
            try
            {
                if (open_f.fail()) throw 0;
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
                            if (temp_paz < 1 || temp_paz > 10)
                            {
                                cout << "Pazymiai turi buti nuo 1 iki 10. Patikrinkite faila.";
                                return 0;
                            }
                            else temp_student.nd.push_back(temp_paz);

                        }
                        open_f >> temp_student.egz;
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
            catch (int e)
            {
                cout << "Nepavyko atidaryti failo";
                exit(1);                
            }
        }
        else if (read_type == "R" || read_type == "r")
        {
            
                        
            cout << "Jei norite, kad studentu pazymiai butu generuojami automatiskai spauskite \"R\".\nJei norite pazymius suvesti pats spauskite \"P\".";
            cin >> input_type;
            try 
            {
                if (input_type != "R" && input_type != "r" && input_type != "P" && input_type != "p") throw(input_type);
                else
                {
                    int n, x;
                    float laik_paz;
                    cout << "Iveskite studentu skaiciu: ";
                    cin >> n;           
                    while (n <= 0)
                    {
                        cout << "Studentu skaicius turi buti didesnis uz 0. Bandykite is naujo: ";
                        cin >> n;
                    }
                    for (int i = 0; i < n; i++)
                    {
                        cout << "Iveskite " << i + 1 << " -o studento varda ir pavarde : ";
                        cin >> temp_student.vardas >> temp_student.pavarde;
                        while (is_alphabetic(temp_student.vardas) == false)
                        {
                            cout << "Varde turi buti tik raides. Iveskite varda is naujo: ";
                            cin >> temp_student.vardas;
                        }
                        while (is_alphabetic(temp_student.pavarde) == false)
                        {
                            cout << "Pavardeje turi buti tik raides. Iveskite varda is naujo: ";
                            cin >> temp_student.pavarde;
                        }
                        if (input_type == "R" || input_type == "r")
                        {
                            cout << "Iveskite " << i + 1 << " -o studento namu darbu kieki : ";
                            cin >> x;
                            while (x <= 0)
                            {
                                cout << "Namu darbu kiekis privalo buti didesnis uz 0. Bandykite is naujo.";
                                cin >> x;
                            }
                            temp_student.nd.reserve(x);
                            for (int j = 0; j < x; j++)
                            {
                                temp_student.nd.push_back(dist(mt));
                            }
                            temp_student.egz = dist(mt);
                            vid = accumulate(temp_student.nd.begin(), temp_student.nd.end(), 0.0) / temp_student.nd.size();
                            temp_student.galutinis_vid = 0.4 * vid + 0.6 * temp_student.egz;
                            med = mediana(temp_student.nd);
                            temp_student.galutinis_med = 0.4 * med + 0.6 * temp_student.egz;
                            grupe.push_back(temp_student);
                            temp_student.nd.clear();
                        }
                        else if (input_type == "P" || input_type == "p")
                        {
                            cout << "Iveskite namu darbu pazymius: ";
                            while (cin >> laik_paz)
                            {
                                if (laik_paz < 1 || laik_paz > 10)
                                {
                                    cout << "Pazymys turi buti nuo 1 iki 10. Bandykite is naujo: ";
                                }
                                else { temp_student.nd.push_back(laik_paz); };

                            }
                            if (temp_student.nd.empty())
                            {
                                cout << "Privaloma ávesti namø darbø rezultatus. Bandykite is naujo.";
                                return 1; //Jei neivedami namu darbu pazymiai, programa stabdoma.
                            }
                            cin.clear();
                            cin.ignore(10000, '\n');

                            cout << "Iveskite " << i + 1 << "-o studento egzamino pazymi : ";
                            cin >> temp_student.egz;
                            while (temp_student.egz < 1 || temp_student.egz > 10)
                            {
                                cout << "Egzamino ivertinimas turi buti nuo 1 iki 10. Bandykite is naujo: ";
                                cin >> temp_student.egz;
                            }
                            vid = accumulate(temp_student.nd.begin(), temp_student.nd.end(), 0.0) / temp_student.nd.size();
                            temp_student.galutinis_vid = 0.4 * vid + 0.6 * temp_student.egz;
                            med = mediana(temp_student.nd);
                            temp_student.galutinis_med = 0.4 * med + 0.6 * temp_student.egz;
                            grupe.push_back(temp_student);
                            temp_student.nd.clear();
                        }

                    }
                }
            }
            catch (string input_type)
            {
                cout << "Pasirinkite R arba P" << endl;
                exit(1);
            }
           
        }
        else throw(read_type);
    }
    catch (string read_type)
    {
        cout << "Pasirinkite F arba R" << endl;
        exit(1);
    }
    
    cout << "Jei norite, kad butu isvedamas galutinis pazymys pagal namu darbu vidurki, spauskite V.\nJei, pagal mediana spauskite M.";
    cin >> galutinis_type;
    try 
    {
        if (galutinis_type == "V" || galutinis_type == "v" || galutinis_type == "M" || galutinis_type == "m")
        {
            student_print(grupe, galutinis_type);
        }
        else throw(galutinis_type);
    }
    catch (string galutinis_type)
    {
        cout << "Pasirinkite V arba M" << endl;
        exit(1);
    }

    
    cin.get();
    
}
