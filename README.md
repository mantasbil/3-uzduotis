# 1 užduotis

Programa, kuri nuskaito studentų vardą ir pavardę, namų darbų rezultatus bei egzamino pažymį ir suskaičiuoja galutinį įvertinimą.

## v0.1

Programa realizuota dviem būdais:
- Kiekvieno studento namų darbų įvertinimai ir informacija apie visus studentus (vardas, pavardė, namų darbų įvertinimai, egzamino įvertinimas, galutinis pažymys) saugomi dinaminiuose masyvuose [uzd1.cpp](https://github.com/mantasbil/1-uzduotis/blob/v0.1/uzd1/uzd1.cpp).
- Kiekvieno studento namų darbų įvertinimai ir informacija apie visus studentus (vardas, pavardė, namų darbų įvertinimai, egzamino įvertinimas, galutinis pažymys) saugomi vektoriuose [uzd1_vect.cpp](https://github.com/mantasbil/1-uzduotis/blob/v0.1/uzd1_vect/uzd1_vect.cpp).

Programos veikimas:
1. Įvedamas studentų skaičius.
2. Įvedamas studento vardas ir pavardė. Tiek vardas, tiek pavardė turi susidėti tik iš raidžių.
3. Pasirenkama, ar pažymiai bus įvedami vartotojo, ar generuojami automatiškai. Pasirinkus automatinį generavimą, reikia įvesti namų darbų pažymių kiekį. Pasirinkus rankinį įvedimą realizacijoje su masyvu įvedamas stabdomas įvedus -1, realizacijoje su vektoriumi įvedimas stabdomas paspaudus bet kokį simbolį, kuris nėra skaičius. Privaloma įvesti bent vieną pažymį.
4. Programa dviem būdais apskaičiuoja studento galutinį pažymį
   - Galutinis = 0.4 * namų_darbų_vidurkis + 0.6 * egzaminas
   - Galutinis = 0.4 * namų_darbų_vidurkis + 0.6 * mediana
5. Pasirenkama, ar į ekraną bus išvedamas galutinis pažymys, apskaičiuotas pagal namų darbų vidurkį, ar pagal medianą.
6. Į ekraną išvedami visų įvestų studentų vardai ir pavardės kartu su jų galutiniu pažymiu, suapvalintu iki dviejų skaičių po kablelio.

