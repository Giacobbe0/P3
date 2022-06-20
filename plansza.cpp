#include "plansza.h"
using namespace std;

//Funkcja tworzaca oraz wyswietlajaca plansze do gry w terminalu, zapisana w tablicy
//tab - tablica zawierajaca plansze
//rozmiar - rozmiar planszy
//wymiar - wymiar planszy
void rysuj_plansze(char tab[], int rozmiar, int wymiar)
{
	for(int i=1; i<=wymiar; i++) //Petla po calej planszy
    {
		if(i==1) //Wyswietlenie numerow kolumn w pierwszej lini planszy
        {
			for (int k=1; k<=rozmiar; k++)
            {
				cout << " " << k << "  ";
            }
                cout << "K/W "<<endl;
		}
        cout << " " << tab[i] << " "; //Wyswietlenie pol
		if (!(i % rozmiar)) //Wyswietlenie numerow wierszy w ostatnich wierszach planszy
        {
			cout << "  " << (i/rozmiar);
        }
		if (i%rozmiar) // Wyswietlenie pionowych lini planszy
        {
			cout << "|";
        }
		else if (i!=wymiar) // Wyswietlenie poziomych lini wraz z lacznikami '+'
        {
			for (int j=1; j<=rozmiar; j++)
            {
				if(j==1)
                {
					cout <<endl<< "---+";
                }
				else if (j==rozmiar)
                {
					cout << "---"<<endl;
                }
				else
                {
					cout << "---+";
                }
			}
		}
		else //Wyswietlenie odstepu po wyswietleniu planszy
        {
             cout << endl;
        }
	}
}