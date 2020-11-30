# Studentų įvertinimai

Programa nuskaito studentų duomenis (vardą, pavardę, n pažymių ir egzamino įvertinimą) ir iš šių duomenų suskaičiuoja galutinį įvertinimą pagal formulę:
> galutinis = 0.4 * vidurkis + 0.6 * egzaminas.

## Struktūra
Programą sudaro 3 projektai ir kiekvieno iš jų įdiegimo failai:
 * Naudojamas vektorius: studentuIvertinimai, setup(vektorius);
 * Naudojamas sąrašas: studentuIvertinimai(list), setup(sarasas);
 * Naudojamas vektorius, kai optimizuotas studentų sąrašo dalinimas: studentuIvertinimai(vektorius), setup(vektorius+).

### Programos veikimas
1. Vartotojo prašoma įvesti duomenų failo pavadinimą (.txt programa prideda automatiškai). Jei duomenų failas su tokiu pavadinimu neegzistuoja, parodomas pranešimas „Failas nerastas“ ir programa sustoja.
2. Vartotojas įveda failą sudarančių eilučių skaičių. Šis skaičius naudojamas kuriant naujus sąrašus: prie pavadinimų „galvočiai“ ir „vargšiukai“ pridedamas skaičius  pvz. „galvočiai1000“ ), kad būtų aišku, iš kokio failo perkelti šie duomenys.
3. Vyksta duomenų nuskaitymas, ekrane parodoma, kiek laiko užtruko šis veiksmas. Jei duomenų failas tuščias, programa sustoja.
4. Vartotojui leidžiama pasirinkti, kaip skaičiuoti galutinį balą: "a" – naudojant vidurkį, "b" - naudojant medianą. (*Jei nepasirenkamas nei vienas iš šių būdų, ekrane parodomas pranešimas ir automatiškai naudojamas vidurkis*). 
5. Vartotojas pasirenka sąrašo dalinimo strategiją *(Nepasirinkus nei vienos iš šių, naudojama sparčiausia – 2)*:
   * 1 – Bendro studentai konteinerio skaidymas į du naujus to paties tipo konteinerius: "vargšiukų" ir "galvočių", pabaigoje panaikinant pradinį konteinerį.
   * 2 - Bendro studentų konteinerio skaidymas panaudojant tik vieną naują konteinerį: "galvočiai" (vargšiukai lieka bendrame studentų konteineryje, o galvočiai perkeliami į naują).
   * 3 - Bendro studentai konteinerio skaidymas į du naujus to paties tipo konteinerius: "vargšiukų" ir "galvočių" perkeliant po vieną elementą į naują konteinerį ir iškart pašalinant iš pradinio.
6. Vyksta studentų sąrašo dalinimas pagal pasirinktą strategiją, ekrane parodomas veiksmo laikas.
7. Kuriami nauji sąrašai: „vargšiukai“ ir „galvočiai“. (Realizacijoje su vektoriais ekrane parodomas kiekvieno failo sukūrimo laikas).
