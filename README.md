# Studentų įvertinimai v1.0
Programos veikimo spartos analizė, lyginant vektorių, sąrašą bei optimizuotą vektorių (žymima *vektorius+* ) pagal tris sąrašo dalinimo strategijas:
*  1 – Bendro studentai konteinerio skaidymas į du naujus to paties tipo konteinerius: "vargšiukų" ir "galvočių", pabaigoje panaikinant pradinį konteinerį.
*  2 - Bendro studentų konteinerio skaidymas panaudojant tik vieną naują konteinerį: "galvočiai" (vargšiukai lieka bendrame studentų konteineryje, o galvočiai perkeliami į naują).
*  3 - Bendro studentai konteinerio skaidymas į du naujus to paties tipo konteinerius: "vargšiukų" ir "galvočių" perkeliant po vieną elementą į naują konteinerį ir iškart pašalinant iš pradinio.

## Failas su 1000 įrašų
|Strategija \ Konteineris| Vektorius           | Sąrašas          |Vektorius+      |
|----------------------  |---------------------|------------------|----------------|
|Sąrašo dalinimas 1      |0.0004832 |0.0006671 |0.0004425|
|Sąrašo dalinimas 2      |0.0007415|0.0001413 |0.0002197|
|Sąrašo dalinimas 3      |0.0005793 |0.0002513 ||

## Failas su 10000 įrašų
|Strategija \ Konteineris| Vektorius           | Sąrašas          |Vektorius+      |
|----------------------  |---------------------|------------------|----------------|
|Sąrašo dalinimas 1      |0.0046093 | 0.0085605|0.0048102|
|Sąrašo dalinimas 2      |0.0062676 | 0.0021818|0.0030557|
|Sąrašo dalinimas 3      |0.0042728 |0.004561 |-|

## Failas su 100000 įrašų
|Strategija \ Konteineris| Vektorius           | Sąrašas          |Vektorius+      |
|----------------------  |---------------------|------------------|----------------|
|Sąrašo dalinimas 1      |0.0545286 |0.14509 |0.0493633|
|Sąrašo dalinimas 2      |0.0705715 |0.087299 |0.0346146|
|Sąrašo dalinimas 3      |0.0384333 | 0.0368391|-|

## Failas su 1000000 įrašų
|Strategija \ Konteineris| Vektorius           | Sąrašas          |Vektorius+      |
|----------------------  |---------------------|------------------|----------------|
|Sąrašo dalinimas 1      |0.561519 | 2,65959|0.526359|
|Sąrašo dalinimas 2      |0.862738 |0.965871 |0.318163|
|Sąrašo dalinimas 3      |0.47777 | 0.351315|-|

### Išvada: ###
Prieš optimizuojant programą su vektoriumi, studentų sąrašo dalinimas greičiau atliekamas naudojant sąrašą. Atlikus pakeitimus, 
studentų sąrašas greičiausiai padalinamas naudojant optimizuoto vektoriaus 2 strategiją.
