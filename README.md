# 1 užduotis

Programa, kuri nuskaito studentų vardą ir pavardę, namų darbų rezultatus bei egzamino pažymį ir suskaičiuoja galutinį įvertinimą.

## v0.1

Programa realizuota dviem būdais:
- Kiekvieno studento namų darbų įvertinimai ir informacija apie visus studentus (vardas, pavardė, namų darbų įvertinimai, egzamino įvertinimas, galutinis pažymys) saugomi dinaminiuose masyvuose (uzd1.cpp).
- Kiekvieno studento namų darbų įvertinimai ir informacija apie visus studentus (vardas, pavardė, namų darbų įvertinimai, egzamino įvertinimas, galutinis pažymys) saugomi vektoriuose (uzd1_vect.cpp).

Programos veikimas:
1. Įvedamas studentų skaičius.
2. Įvedamas studento vardas ir pavardė. Tiek vardas, tiek pavardė turi susidėti tik iš raidžių.
3. Pasirenkama, ar pažymiai bus įvedami vartotojo, ar generuojami automatiškai. Realizacijoje su dinamiu masyvu abiem atvejais reikia nurodyti turimų namų darbų skaičių, realizacijoje su vektoriumi namų darbų skaičių reikia įvesti tik pasirenkant automatinį pažymių generavimą, vedant pažymius ranka įvedamas stabdomas paspaudus bet kokį simbolį, kuris nėra skaičius. Privaloma įvesti bent vieną pažymį.
4. Programa dviem būdais apskaičiuoja studento galutinį pažymį
   - Galutinis = 0.4 * namų_darbų_vidurkis + 0.6 * egzaminas
   - Galutinis = 0.4 * namų_darbų_vidurkis + 0.6 * mediana
5. Pasirenkama, ar į ekraną bus išvedamas galutinis pažymys, apskaičiuotas pagal namų darbų vidurkį, ar pagal medianą.
6. Į ekraną išvedami visų įvestų studentų vardai ir pavardės kartu su jų galutiniu pažymiu, suapvalintu iki dviejų skaičių po kablelio.

## v0.2

Patobulinta v0.1 realizacija, naudojant vektorius. Išlaikytas visas v0.1 funkcionalumas, pridėta daugiau galimybių.

Naujos galimybės:
- Duomenų nuskaitymas iš failo. Failas, kuriame saugomi duomenys privalo vadintis "kursiokai.txt". Nuskaitant iš failo, visi studentai turi vienodą namų darbų kiekį.
- Studentai išvedami į ekraną pagal pavardes abėcėlės tvarka. Jei kelių studentų pavardės sutampa, jie vedami abėcėlės tvarka pagal vardą.

