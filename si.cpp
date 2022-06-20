#include "si.h"

//Algorytm minmax symulujacy sztuczna inteligencje, ograniczony do 10 krokow w przod
//tab - tablica na ktorej rozgrywa sie gra
//kto - znak gracza O/X
//rozmiar - rozmiar tablicy
//wymiar - wymiar tablicy
//do_wygranej - liczba pol potrzebna do wygranej
//alfa - minimalny wynik gracza MAX kto
//beta - maksymalny wynik gracza MIN
//glebokosc - maksymalna liczba ruchow do przodu sprawdzanych przez komputer
int minimax(char tab[], char kto, int rozmiar, int wymiar, int do_wygranej, int alfa, int beta, int glebokosc)
{
	if(glebokosc == 10) //Ograniczenie glebokowsci
	{ 
		return 0;
	}
	if(wygrana(tab, kto, true, rozmiar, wymiar, do_wygranej)) //Sprawdzamy, czy gracz wygrywa na planszy.
	{
		return(kto == 'X') ? 1 : -1; 
	}
	if (remis(tab, true, rozmiar, wymiar)) //Sprawdzamy, czy nie ma remisu.
	{
		return 0;
	}
	kto = (kto == 'X') ? 'O' : 'X'; //Zmieniamy gracza na jego przeciwnika
	int obecny, najlepszy = (kto == 'O') ? 2 : -2; 
	for(int i=0; i<=wymiar; i++)
	{
		if(tab[i] == ' ') //Jesli pole jest puste
		{
			tab[i] = kto; //Wpisujemy tam znak i sprawdzamy jak dobry jest ten ruch
			obecny = minimax(tab, kto, rozmiar, wymiar, do_wygranej, alfa, beta, glebokosc + 1); //Rekurencujne wywolanie algorytmu MinMax
			tab[i] = ' '; //Czyscimy pole po sprawdzeniu
			if (((kto == 'O') && (obecny < najlepszy)) || ((kto == 'X') && (obecny > najlepszy))) //Jesli obecny ruch jest lepszy od najlepszego
			{
				najlepszy = obecny; //Obecny ruch staje sie najlepszym
			}
			if(kto=='O')
			{
				beta=min(beta,najlepszy); //Ciecia lafa-beta w celu przyspieszenia algorytmu
				if(beta<=alfa)
				{
					break;
				} 
			}
			if(kto=='X')
			{
				alfa=max(alfa,najlepszy); //Ciecia lafa-beta w celu przyspieszenia algorytmu
				if(beta<=alfa)
				{
					break;
				} 
			}
		}
	}

	return najlepszy; // Wskazanie wartosc najlepszego scenariusza
}

//Funkcja wykonujaca ruch komputera korzystajac z powyzszego algorytmu
//tab - tablica na ktorej rozgrywa sie gra
//rozmiar - rozmiar tablicy
//wymiar - wymiar tablicy
//do_wygranej - liczba pol potrzebna do wygranej
int ruch_komputera(char tab[], int rozmiar, int wymiar, int do_wygranej)
{
	int ruch, obecny, najlepszy; //Zmienne przechowywyjace ruch oraz scenariusze
	int alfa = -2147483647; //alfa = -inf
	int beta = 2147483647;  //beta = inf
	najlepszy = -2147483647;
	obecny = -2147483647;
	for(int i=1; i<=wymiar; i++) //Petla po planszy
	{
		if(tab[i] == ' ') //Jesli pole jest puste
		{
			tab[i] = 'X';
			obecny = minimax(tab, 'X', rozmiar, wymiar, do_wygranej,  alfa, beta, 0); //Wykonanie algorytmu MinMax
			tab[i] = ' ';
			if(obecny > najlepszy) //Jezeli dany ruch jest lepszy to wybieramy go
			{
				najlepszy = obecny;
				ruch = i;
			}
		}
	}

	return ruch;
}

//Funkcja przeprowadzajaca rozgrywke
//Wykonuje ruch gracza oraz komputera
//tab - tablica na ktorej rozgrywa sie gra
//kto - znak gracza O/X
//rozmiar - rozmiar tablicy
//wymiar - wymiar tablicy
//do_wygranej - liczba pol potrzebna do wygranej
void gra(char tab[], char &kto, int rozmiar, int wymiar, int do_wygranej)
{
	int ruch, kolumny, wiersze, pom; //Zmienne zawierajace parametry gry
	rysuj_plansze(tab, rozmiar, wymiar); //Wyswietlenie planszy
	if (kto == 'O') //Jesli gracz to czlowiek
	{
		cout <<endl<< "-------------------------------------"<<endl;
		cout << "Ruch Gracza: "<<endl;
		while(1) //Pobieranie informacji o kolumnie, w ktorej gracz chce umiescic znak,
		{		// Do momentu az gracz wybierze kolumne prawidlowo
			cout << "Nr Kolumny: ";
			cin >> kolumny;
			if (kolumny <= rozmiar && kolumny > 0) //Jesli kolumna jest z prawidlowego zakresu przerywamy petle
			{
				break; 
			}
            else //Jesli nie trzeba podac nowa wartosc
			{
                cout << "Kolumna poza zakresem planszy! Sprobuj ponownie."<<endl; 
			}
		}
		while(1) //Pobieranie informacji o wierszu, w ktorym gracz chce umiescic znak
		{		// Do momentu az gracz wybierze kolumne prawidlowo
			cout << "Nr Wiersza: ";
			cin >> wiersze;
			if (wiersze <= rozmiar && wiersze > 0) //Jesli wiersz jest z prawidlowego zakresu przerywamy petle
			{
			    cout<<endl;
				break;
			}
            else //Jesli nie trzeba podac nowa wartosc
			{
                cout << "Wiersz poza zakresem planszy! Sprobuj ponownie."<<endl;
			}
		}
		pom = (rozmiar*wiersze) + kolumny - rozmiar; //Obliczenie wymiaru planszy
		while(1)
		{
			if (tab[pom] != ' ') // Jezeli pod wskazanym polem stoi juz jakis znak
			{ 								
				cout << "Wskazane pole jest juz zajete! " << endl;
				cout << "Sproboj ponownie: "<<endl<<endl;
				rysuj_plansze(tab, rozmiar, wymiar);
				cout<<endl;

				while(1) //Wpisujemy na nowo parametry tak jak robilismy to na poczatku
		    	{
					cout << "Nr Kolumny: ";
					cin >> kolumny;
					if (kolumny <= rozmiar && kolumny > 0)
					{
						break;
					}
            		else
					{
                		cout << "Kolumna poza zakresem planszy! Sprobuj ponownie."<<endl;
					}
				}

				while(1)
				{
					cout << "Nr Wiersza: ";
					cin >> wiersze;
					if (wiersze <= rozmiar && wiersze > 0)
					{
			    		cout<<endl;
						break;
					}
            		else
					{
                		cout << "Wiersz poza zakresem planszy! Sprobuj ponownie."<<endl;
					}
				}	

				pom = (rozmiar*wiersze) + kolumny - rozmiar;
			}
			else //Jesli pole zostalo wybrane prawidlowo, przechodzimy dalej
			{
				ruch=pom;
				break;
			}
		}
	}
	else //Jesli ruch wykonuje komputer
	{
		ruch = ruch_komputera(tab, rozmiar, wymiar, do_wygranej); //Ruch komputera
		cout <<endl<<"-------------------------------------"<<endl;
	    cout<<"Ruch Komputera:"<<endl<<endl;
	}
	if ((ruch >= 1) && (ruch <= wymiar) && (tab[ruch] == ' ')) //Wpisanie symbolu na plansze, jesli ruch zostal wykonany poprawnie
	{
		tab[ruch] = kto;
	}
	kto = (kto == 'O') ? 'X' : 'O'; //Zmiana gracza po wykonaniu ruchu
}