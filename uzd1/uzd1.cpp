// uzd1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::setw;
using std::endl;
using std::setprecision;
using std::left;

struct studentas 
{
    string vardas, pavarde;
    float nd[5];
    float egz;
    float galutinis;
};

void student_print(studentas);

int main()
{
    cout << "Áveskite studentø skaièiø: ";
    int n;
    float suma=0;
    cin >> n;
    studentas grupe[n];  //pakeist i std::vector
    for (int i = 0; i < n; i++)
    {
        cout << "Iveskite " << i + 1 << "studento varda ir pavarde : ";
        cin >> grupe[i].vardas >> grupe[i].pavarde;
        suma = 0;
        for (int j = 0; j < 5; j++)
        {
            cout << "Iveskite " << j + 1 << "-o namu darbo pazymi: ";
            cin >> grupe[i].nd[j];
            suma += grupe[i].nd[j];
        }
        cout << "Iveskite " << i + 1 << "-o studento egzamino pazymi : ";
        cin >> grupe[i].egz;
        grupe[i].galutinis = 0.4 * suma / 5. + 0.6 * grupe[i].egz;

    }
    
    for (auto& stud : grupe) student_print(stud);
}

void student_print(studentas stud)
{
    cout << setw(15) << left << stud.vardas << setw(15) << left << stud.pavarde;
    for (auto& i : stud.nd) cout << setw(5) << left << i;
    cout << setw(5) << left << stud.egz << setw(5) << setprecision(2) << left << stud.galutinis << endl;
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
