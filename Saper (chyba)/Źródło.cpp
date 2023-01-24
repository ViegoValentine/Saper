#include <iostream>
#include <time.h>
#include <Windows.h>
#include "Nag³ówek.h"

using namespace std;

int main() {
	//zainicjowanie wielkosci tablicy (10x10) i liczb pseudolosowych
	srand(time(NULL));
	int liczba=10;

	//dynamiczna alokacja i stworzenie planszy
	char** tab = nullptr;
	tab = new char* [liczba];
	for (int i = 0; i < liczba; i++) {
		tab[i] = new char[liczba];
	}

	//kolejne funkcje odpowiedzialne za dzia³anie sapera
	instrukcja();
	tablicaMin(tab, liczba);
	strzelanie(tab, liczba);

	//zwolnienie pamiêci 
	for (int i = 0; i < liczba; i++) {
		delete[] tab[i];
	}
	delete[] tab;
	tab = nullptr;

	system("pause");
}