#include <iostream>
#include <time.h>
#include <Windows.h>
#include "Nag³ówek.h"

using namespace std;

//wype³nienie tablicy minami i polami "bezpiecznymi"
void tablicaMin(char** tab, int liczba) {
	//losowe ulokowanie min
	for (int i = 0; i < liczba; i++) {
		int x = (rand() % 8) + 1;
		int y = (rand() % 8) + 1;
		if (tab[x][y] != 'x') {
			tab[x][y] = 'x';
		}
		else if (tab[x][y] == 'x') {
			i--;
		}
	}
	//wpisanie zer w kazde inne miejsce ni¿ mina
	for (int i = 1; i < liczba - 1; i++) {
		for (int j = 1; j < liczba - 1; j++) {
			if (tab[i][j] != 'x') {
				tab[i][j] = 48;
			}
		}
	}
	//wype³nienie pól "bezpiecznych" informacj¹ ile pól z minami znajduje siê obok nich
	for (int i = 1; i < liczba - 1; i++) {
		for (int j = 1; j < liczba - 1; j++) {
			if (tab[i][j] != 'x') {
				for (int x = i - 1; x <= i + 1; x++) {
					for (int y = j - 1; y <= j + 1; y++) {
						if (tab[x][y] == 'x') {
							tab[i][j] = tab[i][j] + 1;
						}
					}
				}
			}
		}
	}
}

//instrukcja
void instrukcja() {
	cout << "Szybko na temat tego jak to jest zrobione." << endl;
	cout << "Zostaje wygenerowana plansza 8x8 z minami w losowym miejscu." << endl;
	cout << "Zostniemy poproszeni o wybranie czynnosci." << endl;
	cout << "1 - wybranie koordynatow odopwiedzialnych za odkrycie pola pustego. Jesli trafimy na mine przegrywamy" << endl;
	cout << "2 -  wybranie koordynatow miny. Mozna zaznaczyc miejsce gdzie miny nie ma." << endl;
	cout << "Jesli zmienimy zdanie i wskazemy pole puste to zostanie tam pokazana ilosc min wokol pola." << endl;
	cout << "Koordynaty o ktore jestesmy proszeni to x i y." << endl;
	cout << "X - podawany jako pierwszy, odpowiada za wiersz." << endl;
	cout << "Y - podawany jako drugi, odpowiada za kolumne." << endl;
	cout << "Jesli uzytkownik wykorzysta wszystkie flagi (miejsca min) nie bedzie mogl z nich skorzystac." << endl;
	cout << "Jesli gracz wskaze miejsce pola bezpiecznego to pole z 0 nie bedzie odkrywac pol z zaznaczona mina badz mozliwa mina" << endl;
	cout << "To tyle, mozna isc grac. Powodzenia" << endl;
	//cout<<"Radze zmienic dyscypline z boksu na KSW. Tam nie trzeba umiec sie bic."<<endl;
	cout << endl;
}

//funckja w której gracz wybiera pole. Jeœli trafi na mine przegrywa, jeœli nie gra dalej
void strzelanie(char** tab, int liczba) {
	int liczbaMin = 0;
	int czyMina = 0;
	int licznikMin = 0;
	int* czyMina1 = &czyMina;
	int* liczbaMin1 = &liczbaMin;
	int* licznikMin1 = &licznikMin;

	//dynamiczna alokacja tablicy wyœwietlanej u¿ytkownikowi
	char** tablicaPomocnicza = nullptr;
	tablicaPomocnicza = new char* [liczba];
	for (int i = 0; i < liczba; i++) {
		tablicaPomocnicza[i] = new char[liczba];
	}

	//wype³nienie pomocniczej tablicy miejscami nieznanymi
	for (int i = 1; i < liczba - 1; i++) {
		for (int j = 1; j < liczba - 1; j++) {
			tablicaPomocnicza[i][j] = '-';
		}
	}
	char wybor = '0';
	do {
		//wybor co chcemy zrobic
		cout << "Generale, co robimy?" << endl;
		cout << "1 - podanie koordynatow pola pustego" << endl;
		cout << "2 - podanie koordyantow pola zaminowanego" << endl;
		cin >> wybor;
		if (wybor == 49 || wybor == 50) {
			if (wybor == 49) {
				polaPuste(tablicaPomocnicza, tab, liczba, czyMina1, licznikMin1);
			}
			else if (wybor == 50 && licznikMin <= 10) {
				polaMiny(tablicaPomocnicza, tab, liczba, liczbaMin1, licznikMin1);
			}
			else if (licznikMin > 10) {
				cout << "Kapitanie Bomba... skonczyly nam sie flagi" << endl;
			}
		}
		else {
			cout << "Komendy nie rozpoznano." << endl;
		}
	} while (czyMina < 1 && liczbaMin != liczba);

	system("cls");
	//wyswitelenie wyniku 
	if (czyMina >= 1) {
		porazka(liczba, tab);
	}
	else if (liczbaMin == liczba) {
		zwyciestwo(liczba, tab);
	}

	//zwolnienie dynamicznie zalokowanej pamiêci tablicy pomocniczej
	for (int i = 0; i < liczba; i++) {
		delete[] tablicaPomocnicza[i];
	}
	delete[] tablicaPomocnicza;
	tablicaPomocnicza = nullptr;
}