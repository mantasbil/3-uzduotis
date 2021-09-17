#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <time.h>
#include <numeric>

using std::cout;
using std::cin;
using std::string;
using std::setw;
using std::endl;
using std::setprecision;
using std::left;
using std::sort;
using std::vector;
using std::accumulate;

struct studentas
{
    string vardas, pavarde;
    int nd_kiek;
    vector <float> nd;
    float egz;
    float galutinis;
};

void student_print(vector <studentas> grupe, int sk, string type);
float mediana(vector<float> pazymiai);
bool is_alphabetic(string& vardas);

int main()
{
    srand(time(NULL));
    int n, x, vardas_len, pavarde_len;
    float laik_paz, vid, med;
    string input_type, galutinis_type;
    studentas temp_student;
    cout << "Iveskite studentu skaiciu: ";
    cin >> n;
    vector <studentas> grupe;
    grupe.reserve(n);
    cout << "Jei norite, kad studentu pazymiai butu generuojami automatiskai spauskite \"R\".\nJei norite pazymius suvesti pats spauskite \"P\".";
    cin >> input_type;
    while (input_type != "R" && input_type != "r" && input_type != "P" && input_type != "p")
    {
        cout << "Netinkamas simbolis. Bandykite is naujo. ";
        cin >> input_type;
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
        while (is_alphabetic(temp_student.vardas) == false)
        {
            cout << "Pavardeje turi buti tik raides. Iveskite varda is naujo: ";
            cin >> temp_student.pavarde;
        }
                
        if (input_type == "R" || input_type == "r")
        {
            cout << "Iveskite " << i + 1 << " -o studento namu darbu kieki : ";
            cin >> x;
            for (int j = 0; j < x; j++)
            {
                temp_student.nd.push_back(rand() % 10 + 1);
            }
            temp_student.egz = rand() % 10 + 1;
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
            cin.clear();
            cin.ignore(10000, '\n');
            
            cout << "Iveskite " << i + 1 << "-o studento egzamino pazymi : ";
            cin >> temp_student.egz;
            while (temp_student.egz < 1 || temp_student.egz > 10)
            {
                cout << "Egzamino ivertinimas turi buti nuo 1 iki 10. Bandykite is naujo: ";
                cin >> temp_student.egz;
            }
        }
        
        cout << "Jei norite, kad galutinis mazymys butu skaiciuojamas pagal namu darbu vidurki, spauskite V.\nJei norite, kad butu skaiciuojamas pagal mediana spauskite M.";
        cin >> galutinis_type;
        while (galutinis_type != "V" && galutinis_type != "v" && galutinis_type != "M" && galutinis_type != "m")
        {
            cout << "Netinkamas simbolis. Bandykite is naujo: ";
            cin >> galutinis_type;
        }
        if (galutinis_type == "V" || galutinis_type == "v")
        {
            vid = accumulate(temp_student.nd.begin(), temp_student.nd.end(), 0.0) / temp_student.nd.size();
            temp_student.galutinis = 0.4 * vid + 0.6 * temp_student.egz;
        }
        
        if (galutinis_type == "M" || galutinis_type == "m")
        {
            med = mediana(temp_student.nd);
            temp_student.galutinis = 0.4 * med + 0.6 * temp_student.egz;
        }
        
        grupe.push_back(temp_student);
        temp_student.nd.clear();

    }

    student_print(grupe, n, galutinis_type);
}

void student_print(vector<studentas> grupe, int sk, string type)
{
    if (type == "V" || type == "v")
    {
        cout << setw(30) << left << "Vardas" << setw(30) << left << "Pavarde" << setw(20) << left << "Galutinis(vid.)" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        for (int i = 0; i < sk; i++)
        {
            cout << setw(30) << left << grupe[i].vardas << setw(30) << left << grupe[i].pavarde
                << setw(20) << setprecision(3) << left << grupe[i].galutinis << endl;
        }
    }
    else if (type == "M" || type == "m")
    {
        cout << setw(30) << left << "Vardas" << setw(30) << left << "Pavarde" << setw(20) << left << "Galutinis(med.)" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        for (int i = 0; i < sk; i++)
        {
            cout << setw(30) << left << grupe[i].vardas << setw(30) << left << grupe[i].pavarde
                << setw(20) << setprecision(3) << left << grupe[i].galutinis << endl;
        }
    }
    

}

float mediana(vector <float> pazymiai)
{
    float median;
    int n = pazymiai.size();
    sort(pazymiai.begin(), pazymiai.end());
    if (n % 2 == 0) median = (pazymiai[n / 2] + pazymiai[n / 2 + 1]) / 2.0;
    else median = pazymiai[n / 2];
    return median;
}

bool is_alphabetic(string& vardas)
{
    return std::all_of(vardas.begin(), vardas.end(), isalpha);
}
