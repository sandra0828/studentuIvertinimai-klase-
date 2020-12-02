# Efektyvumo tyrimas
Tikrinama sparta, lyginant programą, kurioje asmens duomenys saugomi struktūroje ir programą, kuri naudoja klasę „Asmuo“.

## Failas su 100000 įrašų
|              |Duomenų nuskaitymas| Studentų sąrašo dalinimas| „Galvočių“ įrašymo į failą trukmė | „Vargšiukų“ įrašymo į failą trukmė|
|--------------|-------------------|--------------------------|-----------------------------------|-----------------------------------|
|Struktūra| 0.529803|0.032707 |0.545982 |0.471009 |
|Klasė| 0.565758|0.0346087 |0.559352 |0.477205 |

## Failas su 1000000 įrašų
|              |Duomenų nuskaitymas| Studentų sąrašo dalinimas| „Galvočių“ įrašymo į failą trukmė | „Vargšiukų“ įrašymo į failą trukmė|
|--------------|-------------------|--------------------------|-----------------------------------|-----------------------------------|
|Struktūra|5.59695 |0.389309 | 5.10926|5.07403 |
|Klasė| 5.58995| 0.352637|5.41216 |4.97299 |

*Apie tyrimą:*
*  *Tyrimas atliktas su 100000, 1000000 studentų duomenų failais;*
*  *Namų darbų pažymys skaičiuojamas laikant, kad kiekvienas studentas gavo po 5 namų darbų pažymius;*
*  *Galutinis pažymys skaičiuojamas naudojant vidurkį;*
*  *Sąrašo dalinimui naudojama greičiausia (2) strategija;*
*  *Testavimo sistemos parametrai: CPU – 1.99 GHz, RAM – 4,00 GB, SSD – 128 GB*

