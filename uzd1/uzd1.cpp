// uzd1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using std::cout;
using std::cin;
using std::string;
using std::setw;
using std::endl;
using std::setprecision;
using std::left;
using std::sort;

struct studentas 
{
    string vardas, pavarde;
    int nd_kiek;
    float *nd;
    float egz;
    float galutinis_vid, galutinis_med;
};

void student_print(studentas grupe[], int sk);
int mediana(float pazymiai[]);

int main()
{
    cout << "Iveskite studentu skaiciu: ";
    int n, x;
    float suma=0;
    cin >> n;
    studentas *grupe = new studentas[n];  //pakeist i std::vector
    for (int i = 0; i < n; i++)
    {
        cout << "Iveskite " << i + 1 << " -o studento varda ir pavarde : ";
        cin >> grupe[i].vardas >> grupe[i].pavarde;
        suma = 0;
        cout << "Iveskite "<< i + 1 << " -o studento namu darbu kieki : ";
        cin >> x;
        grupe[i].nd = new float[x];
        for (int j = 0; j < x; j++)
        {
            cout << "Iveskite " << j + 1 << "-o namu darbo pazymi: ";
            cin >> grupe[i].nd[j];
            suma += grupe[i].nd[j];
        }
        cout << "Iveskite " << i + 1 << "-o studento egzamino pazymi : ";
        cin >> grupe[i].egz;
        grupe[i].galutinis_vid = 0.4 * suma / 5. + 0.6 * grupe[i].egz;
        grupe[i].galutinis_med = 0.4 * mediana(grupe[i].nd) + 0.6 * grupe[i].egz;
        delete[] grupe[i].nd;

    }
    
    student_print(grupe, n);
    delete[] grupe;
}

void student_print(studentas grupe[], int sk)
{
    //int kiek = sizeof(grupe) / sizeof(grupe[0]);
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

int mediana(float pazymiai[])
{
    float median;
    int n = sizeof(pazymiai) / sizeof(pazymiai[0]);
    sort(pazymiai, pazymiai + n);
    if (n % 2 == 0) median = (pazymiai[n / 2] + pazymiai[n / 2 + 1]) / 2.0;
    else median = pazymiai[n / 2];
    return median;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
