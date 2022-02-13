#include <iostream>
#include <Windows.h>
#include <time.h>
using namespace std;

int liczbaPorwonan = 0;
int liczbaZmian = 0;

void WyswietlTablice(int tab[], int n, int j, int m) {
	for (int i = 0; i < n; i++) {
		if (i == j || i == j + 1 && i < m) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << tab[i] << " ";
		}
		else if (i >= m) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
			cout << tab[i] << " ";
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << tab[i] << " ";
		}
		
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << endl;
}

void PorownajLiczby(int tab[], int i, int n, int m) {
	liczbaPorwonan++;
	if (tab[i] > tab[i + 1] && i < m - 1){
		WyswietlTablice(tab, n, i, m);
		swap(tab[i], tab[i + 1]);
		liczbaZmian++;
	}
	else {
		WyswietlTablice(tab, n, i, m);
	}
}

void SprawdzTablice(int tab[], int n) {
	int m = n;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m - 1; i++) {
			PorownajLiczby(tab, i, n, m);
		}
		m = m - 1;
	}
	
}
int main()
{
	int n;

	cout << "Wpisz ilosc elementow tablicy: " << endl;
	cin >> n;

	int *tab = new int[n];

	srand(time(NULL));

	int choice;
	cout << "Czy tablica ma byc generowana losowo? 1 dla tak, 0 dla nie: " << endl;
	cin >> choice;
	switch (choice)
	{
	case 0:
		cout << "Tablica nie zostanie wygenerowana losowo" << endl;
		for  (int i = 0; i < n; i++)
		{
			cout << "Wpisz liczbe numer " << i + 1 << endl;
			cin >> tab[i];
		}
		//WyswietlTablice(tab, n, -1);
		SprawdzTablice(tab, n);
		break;
	case 1:
		cout << "Tablica zostanie wygenerowana losowo" << endl;
		for (int i = 0; i < n; i++)
		{
			tab[i] = rand() % 101;
		}
		//WyswietlTablice(tab, n, -1);
		SprawdzTablice(tab, n);
		break;
	default:
		cout << "Bledna odpowiedz" << endl;
		break;
	}
	WyswietlTablice(tab, n, -1, 0);
	cout << "Liczba porownan: " << liczbaPorwonan << endl << "Liczba zmian: " << liczbaZmian;
}
