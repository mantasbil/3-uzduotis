# 2 užduotis

# Visos programos veikimas

1. Pasirenkama, matuojama failo nuskaitymo ir duomenų surūšiavimo į dvi grupes sparta. Jei taip, įvedamas norimas duomenų kiekis, programa nuskaito atitinkamai pavadintą failą su nurodytu skaičiumi studentų (faile saugomi studento vardas, pavardė ir galutinis balas), jį nuskaito. Į ekraną išvedamas failo nuskaitymo laikas.
2. Studentai, su mažesniu už 5 galutiniu pažymiu, perkeliami į vektorių 'vargsiukai' ir ištrinami iš pradinio konteinerio. Į ekraną išvedamas studentų dalijimo į atskiras grupes laikas. Surūšiuoti duomenys išvedami į du atskirus failus.
3. Jei pasirenkama nematuoti spartos, prašoma pasirinkti, ar duomenys bus nuskaitomi iš failo, ar įvedami ranka.
4. Jei pasirenkamas nuskaitymas iš failo, duomenys nuskaitomi iš failo, kurio pavadinimas privalo būti "kursiokai.txt" ir kuris privalo būti patalpintas toje pačioje direktorijoje kaip ir programa. Jei toks failas randamas, duomenys nuskaitomi į vektorių ir dviem būdais suskaičiuojamas galutinis pažymys - pagal namų darbų pažymių vidurkį ir pagal medianą.
5. Jei pasirenkamas įvedimas ranka, prašoma pasirinkti, ar namų darbų ir egzamino pažymiai bus įvedami ranka, ar generuojami automatiškai.
6. Abiem atvejais įvedamas studentų kiekis; Prašoma įvesti studento vardą ir pavardę. Pasirinkus automatinį generavimą kiekvienam studentui reikia įvesti namų darbų pažymių kiekį, pasirinkus rankinį įvedimą veiksmas stabdomas įvedus bet kokį simbolį, kuris nėra skaičius. Abiem atvejais kiekvieno studento galutinis pažymys suskaičiuojamas dviem būdais - pagal namų darbų pažymių vidurkį ir pagal medianą.
7. Prašoma pasirinkti, kokio tipo galutinis balas bus išvedamas į ekraną.
8. Į ekraną išvedamas studentų sąrašas, surūšiuotas abėcėlės tvarka pagal pavardes, su pasirinkto tipo galutiniais pažymiais.

## v1.1

Struktūra (struct) 'studentas' pakeista į klasę (class) 'Studentas'.
Palyginamas suskirstymo į grupes laikas naudojant struktūrą bei klasę.

Rūšiavimo laikai:

| | 100000 | 1000000 |
| :---: | :---: | :---: |
| Struct | 0.0044573 s | 0.0521368 s |
| Class | 0.0042335 s | 0.0451156 s |

Rūšiavimas buvo šiek tiek greitesnis naudojant klasę.

## v1.2

- Klasėje 'Studentas' realizuota 'Rule of three', t.y., pridėtas destruktorius, kopijavimo konstruktorius ir priskyrimo operatorius.
- Realizuoti palyginimo operatoriai, galintys palyginti dviejų studentų pavardes arba vardus, ir operatoriai, galintys palyginti vieno studento galutinį pažymį su kokiu nors skaičiumi.
