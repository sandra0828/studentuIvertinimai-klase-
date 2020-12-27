#include "pch.h"

#include "../studentuIvertinimai(vektorius)/Studentas.h"
#include "../studentuIvertinimai(vektorius)/Studentas.cpp"
#include "../studentuIvertinimai(vektorius)/galutinisPazymys.h"
#include "../studentuIvertinimai(vektorius)/galutinisPazymys.cpp"
#include "../studentuIvertinimai(vektorius)/pagalbine.h"
#include "../studentuIvertinimai(vektorius)/pagalbine.cpp"
TEST(medianosTestas, medianaSuLyginiuSkaiciumiNariu)
{
	EXPECT_EQ(mediana({8, 10, 9, 9}), 9);
	EXPECT_EQ(mediana({ 4, 6, 8, 10}), 7);
	EXPECT_EQ(mediana({ 4, 6, 9, 10 }), 7.5);
}

TEST(medianosTestas, medianaSuNelyginiuSkaiciumiNariu)
{
	EXPECT_EQ(mediana({9, 10, 9}), 9);
	EXPECT_EQ(mediana({ 10, 10, 9 }), 10);
}


TEST(Skaicius, arIvestasSkaicius)
{
	EXPECT_TRUE(arSkaicius("10"));
}

TEST(Skaicius, arDaugiau5)
{
	Studentas s1("Vardas", "Pavarde", { 5, 5, 5 }, 4);
	EXPECT_FALSE(arDaugiau_5(s1));
}

TEST(Vardas, kurisDaugiau)
{
	Studentas s1("Vardas1", "Pavarde1", { 10 }, 9);
	Studentas s2("Vardas1", "Pavarde2", { 9 }, 10);
	EXPECT_TRUE(palyginimasPagalVarda(s1, s2));
}