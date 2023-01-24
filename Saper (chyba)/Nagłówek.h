#pragma once
#include <time.h>

using namespace std;

//Trzon gry (backend)
void strzelanie(char** tab, int liczba);
void tablicaMin(char** tab, int liczba);
void instrukcja();

//Funkcje gry (Frontend)

void pokazywaniePola(char** tablicaPomocnicza, char** tab, int x, int y, int liczba);
void polaPuste(char** tablicaPomocnicza, char** tab, int liczba, int* czyMina, int* licznikMin);
void polaMiny(char** tablicaPomocnicza, char** tab, int liczba, int* liczbaMin, int* licznikMin);

//Funkcje wygranej bπdü poraøki
void porazka(int liczba, char** tab);
void zwyciestwo(int liczba, char** tab);