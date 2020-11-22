# Studentų įvertinimai v1.0
Programos veikimo spartos analizė
## Failas su 1000 įrašų
|Strategija \ Konteineris| Vektorius           | Sąrašas          |
|----------------------  |---------------------|------------------|
|Sąrašo dalinimas 1      |0.0004832 | |
|Sąrašo dalinimas 2      |0.0007415| |
|Sąrašo dalinimas 3      |0.0005793 |0.0002513 |

## Failas su 10000 įrašų
|Strategija \ Konteineris| Vektorius           | Sąrašas          |
|----------------------  |---------------------|------------------|
|Sąrašo dalinimas 1      |0.0046093 | |
|Sąrašo dalinimas 2      |0.0062676 | |
|Sąrašo dalinimas 3      |0.0042728 |0.004561 |

## Failas su 100000 įrašų
|Strategija \ Konteineris| Vektorius           | Sąrašas          |
|----------------------  |---------------------|------------------|
|Sąrašo dalinimas 1      |0.0545286 | |
|Sąrašo dalinimas 2      |0.0705715 | |
|Sąrašo dalinimas 3      |0.0384333 | 0.0368391|

## Failas su 1000000 įrašų
|Strategija \ Konteineris| Vektorius           | Sąrašas          |
|----------------------  |---------------------|------------------|
|Sąrašo dalinimas 1      |0.561519 | |
|Sąrašo dalinimas 2      |0.862738 | |
|Sąrašo dalinimas 3      |0.47777 | 0.351315|

*Sąrašo dalinimo strategijos:*
*  1 – Bendro studentai konteinerio skaidymas į du naujus to paties tipo konteinerius: "vargšiukų" ir "galvočių" pabaigoje panaikinant pradinį vektorių (sąrašą).
*  2 - Bendro studentų konteinerio skaidymas panaudojant tik vieną naują konteinerį: "vargšiukai".
*  3 - Bendro studentai konteinerio skaidymas į du naujus to paties tipo konteinerius: "vargšiukų" ir "galvočių" perkeliant po vieną elementą į naują konteinerį ir iškart pašalinant iš pradinio.
