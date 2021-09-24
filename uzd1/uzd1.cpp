#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
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
using std::fixed;

struct studentas 
{
    string vardas, pavarde;
    int nd_kiek;
    float *nd;
    float egz;
    float galutinis_vid, galutinis_med;
};

void student_print(studentas grupe[], int sk, string type);
float mediana(float pazymiai[], int size);
bool is_alphabetic(string& vardas);

int main()
{
    srand(time(NULL));
    
    cout << "Iveskite studentu skaiciu: ";
    int n, x, nd_kiek=1;
    float suma=0.;
    string input_type, galutinis_type;
    cin >> n;
    while (n <= 0)
    {
        cout << "Studentu skaicius turi buti didesnis uz 0. Bandykite is naujo.";
        cin >> n;
    }
    studentas *grupe = new studentas[n];
    cout << "Jei norite, kad studentu pazymiai butu generuojami automatiskai spauskite \"R\".\n Jei norite pazymius suvesti pats spauskite \"P\".";
    cin >> input_type;
    while (input_type != "R" && input_type != "r" && input_type != "P" && input_type != "p")
    {
        cout << "Netinkamas simbolis. Bandykite is naujo. ";
        cin >> input_type;
    }
    
    cout << "Jei norite, kad galutinis pazymys butu skaiciuojamas pagal namu darbu vidurki, spauskite V.\nJei norite, kad butu skaiciuojamas pagal mediana spauskite M.";
    cin >> galutinis_type;
    while (galutinis_type != "V" && galutinis_type != "v" && galutinis_type != "M" && galutinis_type != "m")
    {
        cout << "Netinkamas simbolis. Bandykite is naujo: ";
        cin >> galutinis_type;
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << "Iveskite " << i + 1 << " -o studento varda ir pavarde : ";
        cin >> grupe[i].vardas >> grupe[i].pavarde;
        while (is_alphabetic(grupe[i].vardas) == false)
        {
            cout << "Varde turi buti tik raides. Iveskite varda is naujo: ";
            cin >> grupe[i].vardas;
        }
        while (is_alphabetic(grupe[i].pavarde) == false)
        {
            cout << "Pavardeje turi buti tik raides. Iveskite varda is naujo: ";
            cin >> grupe[i].pavarde;
        }
        
        suma = 0;
        
        if (input_type == "R" || input_type == "r")
        {
            cout << "Iveskite " << i + 1 << " -o studento namu darbu kieki : ";
            cin >> x;
            while (x <= 0)
            {
                cout << "Namu darbu kiekis turi buti didesnis uz 0. Bandykite is naujo: ";
                cin >> x;
            }
            grupe[i].nd = new float[x];
            for (int j = 0; j < x; j++) 
            { 
                grupe[i].nd[j] = rand() % 10 + 1; 
                suma += grupe[i].nd[j];
            }
            grupe[i].egz = rand() % 10 + 1;
            grupe[i].galutinis_vid = 0.4 * suma / float(x) + 0.6 * grupe[i].egz;
            grupe[i].galutinis_med = 0.4 * mediana(grupe[i].nd, x) + 0.6 * grupe[i].egz;
        }
        else if (input_type == "P" || input_type == "p") 
        {
            grupe[i].nd = new float[nd_kiek];
            cout << "Iveskite " << i + 1 << " -o studento namu darbu pazymius. Baige iveskite -1: ";
            for (int k = 0; k < nd_kiek; k++)
            {
                
                cin >> grupe[i].nd[k];
                if (grupe[i].nd[k] == -1) break;
                while (grupe[i].nd[k] < 1 || grupe[i].nd[k] > 10)
                {
                    cout << "Pazymys turi buti nuo 1 iki 10. Bandykite is naujo: ";
                    cin >> grupe[i].nd[k];
                }
                
                float* temp = new float[nd_kiek + 1];
                for (int j = 0; j < nd_kiek; j++)
                {
                    temp[j] = grupe[i].nd[j];
                }
                delete[](grupe[i].nd);
                nd_kiek += 1;
                grupe[i].nd = new float[nd_kiek];
                for (int j = 0; j < nd_kiek; j++)
                {
                   grupe[i].nd[j] = temp[j];
                }
                delete[](temp);
            }
            for (int z = 0; z < nd_kiek; z++)
            {
                suma += grupe[i].nd[z];
            }
            cout << "Iveskite " << i + 1 << "-o studento egzamino pazymi : ";
            cin >> grupe[i].egz;
            while (grupe[i].egz < 1 || grupe[i].egz > 10)
            {
                cout << "Egzamino ivertinimas turi buti nuo 1 iki 10. Bandykite is naujo: ";
                cin >> grupe[i].egz;
            }
            grupe[i].galutinis_vid = 0.4 * suma / float(nd_kiek) + 0.6 * grupe[i].egz;
            grupe[i].galutinis_med = 0.4 * mediana(grupe[i].nd, nd_kiek) + 0.6 * grupe[i].egz;
        }
        delete[] grupe[i].nd;
    }
    
    student_print(grupe, n, galutinis_type);
    delete[] grupe;
}

void student_print(studentas grupe[], int sk, string type)
{
    cout << endl;
    if (type == "V" || type == "v")
    {
        cout << setw(30) << left << "Vardas" << setw(30) << left << "Pavarde" << setw(20) << left << "Galutinis(vid.)" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        for (int i = 0; i < sk; i++)
        {
            cout << setw(30) << left << grupe[i].vardas << setw(30) << left << grupe[i].pavarde
                << setw(20) << fixed << setprecision(2) << left << grupe[i].galutinis_vid << endl;
        }
    }
    else if (type == "M" || type == "m")
    {
        cout << setw(30) << left << "Vardas" << setw(30) << left << "Pavarde" << setw(20) << left << "Galutinis(med.)" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        for (int i = 0; i < sk; i++)
        {
            cout << setw(30) << left << grupe[i].vardas << setw(30) << left << grupe[i].pavarde
                << setw(20) << fixed << setprecision(2) << left << grupe[i].galutinis_med << endl;
        }
    }
   
}

float mediana(float pazymiai[], int size)
{
    float median;
    sort(pazymiai, pazymiai + size);
    if (size % 2 == 0) median = (pazymiai[size / 2] + pazymiai[size / 2 + 1]) / 2.0;
    else median = pazymiai[size / 2];
    return median;

}

bool is_alphabetic(string& vardas)
{
    return std::all_of(vardas.begin(), vardas.end(), isalpha);
}

