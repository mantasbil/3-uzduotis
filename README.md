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

## v0.2

Patobulinta v0.1 realizacija, naudojant vektorius. Išlaikytas visas v0.1 funkcionalumas, pridėta daugiau galimybių.

Naujos galimybės:
- Duomenų nuskaitymas iš failo. Failas, kuriame saugomi duomenys privalo vadintis "kursiokai.txt". Nuskaitant iš failo, visi studentai turi vienodą namų darbų kiekį.
- Studentai išvedami į ekraną pagal pavardes abėcėlės tvarka. Jei kelių studentų pavardės sutampa, jie vedami abėcėlės tvarka pagal vardą.

## v0.3

Kas naujo:
- Patobulintas atsitiktinių pažymių generavimas (panaudota random biblioteka).
- Funkcijos ir struktūros perkeltos į antraštinius (header) failus.
- Pridėtas išimčių valdymas.

## v0.4

Kas naujo:
- Pridėta galimybė matuoti programos spartą. Pasirinkus šią funkciją:
1. Sukuriamas failas su nurodytu įrašų kiekiu;
2. Studentų duomenys iš failo nuskaitomi į vektorių;
3. Studentai surūšiuojami į atskirus vektorius pagal galutinį pažymį (jei pažymys <5, studentas įrašomas į vektorių "vargsiukai", jei >=5 - į vektorių "galvociai");
4. Surūšiuoti duomenys surašomi į du atskirus failus.
Matuojamas visų išvardintų veiksmų atlikimo laikas.
Lentelėje pateiktas veiksmų atlikimo laikas sekundėmis (buvo matuojama 5 kartus ir apskaičiuotas vidurkis).
| | 1000 įrašų | 10000 įrašų | 100000 įrašų | 1000000 įrašų | 10000000 įrašų|
|---|---|---|---|---|---|
| Failo sukūrimas| 0.0149078 | 0.1488042 | 1.371526 | 11.066468 | 95.23038 |
