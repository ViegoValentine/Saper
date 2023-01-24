#include <iostream>
#include <time.h>
#include <Windows.h>
#include "Nag��wek.h"

using namespace std;

//funckja kt�ra odkrywa pola na tablicy wyswietlanej uzytkownikowi (rekurencja)
void pokazywaniePola(char** tablicaPomocnicza, char** tab, int x, int y, int liczba) {

	//jesli x lub y wykraczaja poza tablice rekurencja konczy dzialanie
	if (x > 8 || x < 1 || y < 1 || y>8) {
		return;
	}
	//jesli tablica zostala odkryta nie bedzie jej odkrywac 2 raz przez co ko�czy dzia�anie
	if (tablicaPomocnicza[x][y] != '-') {
		return;
	}
	//jesli pole nie jest min� i nie zosta�o odkryte, zostanie odkryte teraz
	if (tablicaPomocnicza[x][y] == '-' && tab[x][y] != 'x') {
		tablicaPomocnicza[x][y] = tab[x][y];
	}
	//jesli liczba odkryta jest inna niz 0 rekurencja konczy dzialanie 
	if (tablicaPomocnicza[x][y] != 48) {
		return;
	}

	//odwolania do rekurencji
	pokazywaniePola(tablicaPomocnicza, tab, x - 1, y - 1, liczba);
	pokazywaniePola(tablicaPomocnicza, tab, x, y - 1, liczba);
	pokazywaniePola(tablicaPomocnicza, tab, x - 1, y, liczba);
	pokazywaniePola(tablicaPomocnicza, tab, x, y, liczba);
	pokazywaniePola(tablicaPomocnicza, tab, x + 1, y, liczba);
	pokazywaniePola(tablicaPomocnicza, tab, x, y + 1, liczba);
	pokazywaniePola(tablicaPomocnicza, tab, x + 1, y + 1, liczba);
	pokazywaniePola(tablicaPomocnicza, tab, x + 1, y - 1, liczba);
	pokazywaniePola(tablicaPomocnicza, tab, x - 1, y + 1, liczba);
}

//funkcja odpowiedzialna za wskazywanie pola pustego/bezpiecznego
void polaPuste(char** tablicaPomocnicza, char** tab, int liczba, int* czyMina, int* licznikMin) {
	cout << "Generale prosze podac koordynaty (1-8): ";
	//koordynaty tablicy
	int x, y;
	//podanie koordynatow na polu
	cin >> x;
	cin >> y;

	//funkcja sprawdzajaca czy podane koordynaty s� poprawne
	if (x < 1 || x > 8 || y < 1 || y > 8 || x == NULL || y == NULL) {
		cout << "Generale, to poza polem walki, prosze poprawic koordynaty." << endl;
	}

	else if (x >= 1 && x <= 8 && y >= 1 && y <= 8) {
		//je�li koordynaty s� poprawne i natrafiono na mine koniec gry
		if (tab[x][y] == 'x') {
			*czyMina = 1;
		}
		//je�li koordynaty s� poprawne i nie natrafiono na mine wypisuje ile min jest wok� pola
		else if (tab[x][y] != 'x' && tablicaPomocnicza[x][y] == '-') {
			pokazywaniePola(tablicaPomocnicza, tab, x, y, liczba);
			//wyczyszczenie konsoli i wypisywanie tablicy po podaniu koordynatow
			system("cls");
			for (int i = 1; i < liczba - 1; i++) {
				cout << i << ": ";
				for (int j = 1; j < liczba - 1; j++) {
					cout << "[" << tablicaPomocnicza[i][j] << "] ";
				}
				cout << endl;
			}
		}
		else if (tab[x][y] != 'x' && tablicaPomocnicza[x][y] == 'x') {
			//jesli u�ytkownik zmieni zdanie odno�nie miejsca miny i bedzie miec racje zmieni to na liczbe jaka si� tam znajduje
			tablicaPomocnicza[x][y] = tab[x][y];
			*licznikMin = *licznikMin - 1;
			system("cls");
			for (int i = 1; i < liczba - 1; i++) {
				cout << i << ": ";
				for (int j = 1; j < liczba - 1; j++) {
					cout << "[" << tablicaPomocnicza[i][j] << "] ";
				}
				cout << endl;
			}
		}
	}
}

//funkcja odpowiedzialna za wskazanie pola z min�
void polaMiny(char** tablicaPomocnicza, char** tab, int liczba, int* liczbaMin, int* licznikMin) {
	cout << "Generale prosze podac koordynaty (1-8): ";
	//koordynaty tablicy
	int x, y;
	//podanie koordynatow na polu
	cin >> x;
	cin >> y;

	//funkcja sprawdzajaca czy podane koordynaty s� poprawne
	if (x < 1 || x > 8 || y < 1 || y > 8 || x == NULL || y == NULL) {
		cout << "Generale, to poza polem walki, prosze poprawic koordynaty." << endl;
	}
	//jesli na podanych koordynatach bedzie mina to zostanie ona zaznaczona dodajac do wyniku ile min zostalo znalezionych
	else {
		if (tab[x][y] == 'x' && tablicaPomocnicza[x][y] == '-' && *licznikMin < 10) {
			*liczbaMin = *liczbaMin + 1;
			tablicaPomocnicza[x][y] = 'x';
			*licznikMin = *licznikMin + 1;
		}
		else if (tab[x][y] != 'x' && tablicaPomocnicza[x][y] == '-' && *licznikMin < 10) {
			tablicaPomocnicza[x][y] = 'x';
			*licznikMin = *licznikMin + 1;
		}
		else if (*licznikMin >= 10) {
			cout << "Szefi... skonczyly sie flagi do zaznaczania min" << endl;
			cout << "Oj Marcinek, Marcinek, Marcinek, to przynies, a nie stoisz jak szpadel wbity w ziemie" << endl;
			cout << "Kiedy nie ma szefi. Nawet Domino sprawdza�." << endl;
			Sleep(6000);
		}
		//wyswietlanie tablicy
		system("cls");
		for (int i = 1; i < liczba - 1; i++) {
			cout << i << ": ";
			for (int j = 1; j < liczba - 1; j++) {
				cout << "[" << tablicaPomocnicza[i][j] << "] ";
			}
			cout << endl;
		}
	}
}