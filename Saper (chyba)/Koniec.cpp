#include <iostream>
#include <time.h>
#include <Windows.h>
#include "Nag³ówek.h"

//funckje o komunikacie zwyciestwa lub porazki
void zwyciestwo(int liczba, char** tab) {
	system("cls");
	cout << "Udalo sie generale, teraz mozemy spokojnie przejechac przez to pole." << endl;
	for (int i = 1; i < liczba - 1; i++) {
		for (int j = 1; j < liczba - 1; j++) {
			cout << "[" << tab[i][j] << "] ";
		}
		cout << endl;
	}
}
void porazka(int liczba, char** tab) {
	system("cls");
	cout << "Pojazd wjechal na mine. Wycofujemy sie generale" << endl;
	for (int i = 1; i < liczba - 1; i++) {
		for (int j = 1; j < liczba - 1; j++) {
			cout << "[" << tab[i][j] << "] ";
		}
		cout << endl;
	}
}