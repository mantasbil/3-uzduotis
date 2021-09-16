#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::setw;
using std::endl;
using std::setprecision;
using std::left;
using std::sort;
using std::vector;

struct studentas
{
    string vardas, pavarde;
    int nd_kiek;
    vector <float> nd;
    float egz;
    float galutinis_vid, galutinis_med;
};

void student_print(vector <studentas> grupe, int sk);
int mediana(vector<float> pazymiai);

int main()
{
    cout << "Iveskite studentu skaiciu: ";
    int n, x;
    float paz, suma = 0;
    string input_type;
    cin >> n;
    vector <studentas> grupe;
    cout << "Jei norite, kad studentu pazymiai butu generuojami automatiskai spauskite \"R\".\n Jei norite pazymius suvesti pats spauskite \"P\".";
    cin >> input_type;
    while (input_type != "R" && input_type != "r" && input_type != "P" && input_type != "p")
    {
        cout << "Netinkamas simbolis. Bandykite is naujo. ";
        cin >> input_type;
    }
    for (int i = 0; i < n; i++)
    {
        
        grupe.push_back(studentas());
        cout << "Iveskite " << i + 1 << " -o studento varda ir pavarde : ";
        cin >> grupe[i].vardas >> grupe[i].pavarde;
        suma = 0;
        cout << "Iveskite " << i + 1 << " -o studento namu darbu kieki : ";
        cin >> x;
        if (input_type == "R" || input_type == "r")
        {
            for (int j = 0; j < x; j++)
            {
                grupe[i].nd.push_back(rand() % 10 + 1);
                suma += grupe[i].nd.at(j);
            }
            grupe[i].egz = rand() % 10 + 1;
        }
        else if (input_type == "P" || input_type == "p")
        {
            for (int j = 0; j < x; j++)
            {
                cout << "Iveskite " << j + 1 << "-o namu darbo pazymi: ";
                cin >> paz;
                while (paz < 1 || paz > 10)
                {
                    cout << "Pazymys turi buti nuo 1 iki 10. Bandykite is naujo: ";
                    cin >> paz;
                }
                grupe[i].nd.push_back(paz);
                suma += grupe[i].nd.at(j);
            }
            cout << "Iveskite " << i + 1 << "-o studento egzamino pazymi : ";
            cin >> grupe[i].egz;
            while (grupe[i].egz < 1 || grupe[i].egz > 10)
            {
                cout << "Egzamino ivertinimas turi buti nuo 1 iki 10. Bandykite is naujo: ";
                cin >> grupe[i].egz;
            }
        }
        
        grupe[i].galutinis_vid = 0.4 * suma / float(x) + 0.6 * grupe[i].egz;
        grupe[i].galutinis_med = 0.4 * mediana(grupe[i].nd) + 0.6 * grupe[i].egz;

    }

    student_print(grupe, n);
}

void student_print(vector<studentas> grupe, int sk)
{
    cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis(vid.)"
        << setw(20) << left << "Galutinis(med.)" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    for (int i = 0; i < sk; i++)
    {
        cout << setw(20) << left << grupe[i].vardas << setw(20) << left << grupe[i].pavarde
            << setw(20) << setprecision(3) << left << grupe[i].galutinis_vid
            << setw(20) << setprecision(3) << left << grupe[i].galutinis_med << endl;
    }

}

int mediana(vector <float> pazymiai)
{
    float median;
    int n = pazymiai.size();
    sort(pazymiai.begin(), pazymiai.end());
    if (n % 2 == 0) median = (pazymiai[n / 2] + pazymiai[n / 2 + 1]) / 2.0;
    else median = pazymiai[n / 2];
    return median;

}
