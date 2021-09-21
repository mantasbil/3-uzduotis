# 1 užduotis

Programa, kuri nuskaito studentų vardą ir pavardę, namų darbų rezultatus bei egzamino pažymį ir suskaičiuoja galutinį įvertinimą.

## v0.1

Programa realizuota dviem būdais:
- Studentai bei jų namų darbų rezultatai saugomi dinaminiuose masyvuose (uzd1.cpp).
- Studentai bei jų namų darbų rezultatai saugomi vektoriuose (uzd1_vect.cpp).

Programos veikimas:
1. Įvedamas studentų skaičius.
2. Įvedamas studento vardas ir pavardė. Tiek vardas, tiek pavardė turi susidėti tik iš raidžių.
3. Pasirenkama, ar pažymiai bus įvedami vartotojo, ar generuojami automatiškai. Realizacijoje su dinamiu masyvu abiem atvejais reikia nurodyti turimų namų darbų skaičių, realizacijoje su vektoriumi namų darbų skaičių reikia įvesti tik pasirenkant automatinį pažymių generavimą, vedant pažymius ranka įvedamas stabdomas paspaudus bet kokį simbolį, kuris nėra skaičius. Privaloma įvesti bent vieną pažymį.
4. Pasirenkama, ar galutinis pažymys bus skaičiuojamas pagal namų darbų įvertinimų vidurkį, ar pagal medianą.
5. Į ekraną išvedami visų įvestų studentų vardai ir pavardės kartu su jų galutiniu pažymiu, suapvalintu iki dviejų skaičių po kablelio.

