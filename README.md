# Studentų įvertinimai v1.0
Programos veikimo spartos analizė
## Failas su 1000 įrašų
|Strategija \ Konteineris| Vektorius           | Sąrašas          |
|----------------------  |---------------------|------------------|
|Sąrašo dalinimas 1      |0.0006178 | |
|Sąrašo dalinimas 2      |0.0007415| |
|Sąrašo dalinimas 3      |0.0005793 | |

## Failas su 10000 įrašų
|Strategija \ Konteineris| Vektorius           | Sąrašas          |
|----------------------  |---------------------|------------------|
|Sąrašo dalinimas 1      |0.0116787 | |
|Sąrašo dalinimas 2      |0.010292 | |
|Sąrašo dalinimas 3      |0.007777 | |

## Failas su 100000 įrašų
|Strategija \ Konteineris| Vektorius           | Sąrašas          |
|----------------------  |---------------------|------------------|
|Sąrašo dalinimas 1      |0.0704648 | |
|Sąrašo dalinimas 2      |0.0805715 | |
|Sąrašo dalinimas 3      |0.0623741 | |

## Failas su 1000000 įrašų
|Strategija \ Konteineris| Vektorius           | Sąrašas          |
|----------------------  |---------------------|------------------|
|Sąrašo dalinimas 1      |1.91959 | |
|Sąrašo dalinimas 2      |1.01769 | |
|Sąrašo dalinimas 3      |0.548882 | |

*Sąrašo dalinimo strategijos:*
*  1 – Bendro studentai konteinerio skaidymas į du naujus to paties tipo konteinerius: "vargšiukų" ir "galvočių" pabaigoje panaikinant pradinį vektorių (sąrašą).
*  2 - Bendro studentų konteinerio skaidymas panaudojant tik vieną naują konteinerį: "vargšiukai".
*  3 - Bendro studentai konteinerio skaidymas į du naujus to paties tipo konteinerius: "vargšiukų" ir "galvočių" perkeliant po vieną elementą į naują konteinerį ir iškart pašalinant iš pradinio.
