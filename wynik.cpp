#include "wynik.h"

//Funkcja sprawdzajaca czy nastapil remis
//Sprawdza poszczegolne pola planszy (komorki tablicy) czy nie sa puste (spacje), jesli zadna nie jest wtedy jest remis
//tab - tablica na ktorej rozgrywa sie gra
//pom - zmienna pomocnicza
//rozmiar - rozmiar tablicy
//wymiar - wymiar tablicy
bool remis(char tab[], bool pom, int rozmiar, int wymiar)
{
	for (int i = 1; i <= wymiar; i++) //Po calej tablicy
	{
		if (tab[i] == ' ') // Sprawdzenie  czy sa jeszcze puste miejsca
		{ 
			return false;
		}
	}
	if (!pom) // Tylko po wykonaniu ruchu, nie w algorytmie minimax
	{ 
		rysuj_plansze(tab, rozmiar, wymiar); //Wyswietlenie planszy koncowej
		cout <<endl<< "Remis"; //Wyswietlenie komunikatu o remisie
	}
	return true; 
}

//Funkcja sprawdzajaca czy jeden z graczy wygral rozgrywke
//Sprawdzan ciag znakow pionowo, poziomo i na ukos w 2 kierunkach
//tab - tablica na ktorej rozgrywa sie gra
//kto - znak X/O reprezentujacy graczy (gracza i komputer)
//pom - zmienna pomocnicza
//rozmiar - rozmiar tablicy
//wymiar - wymiar tablicy
//do_wygranej - liczba pol potrzebna do wygranej
bool wygrana(char tab[], char kto, bool pom, int rozmiar, int wymiar, int do_wygranej)
{
	char spr; //zmienna pomocnicza sprawdzajaca czy nastopilo zwyciestwo
	bool win = false; //Zmienna zawierajaca informacje czy nastapilo zwyciestwo

	//Sprawdzanie czy nie nastapila wygrana w pionie
	for(int i=1; i<wymiar; i+=rozmiar) //Pętla po kolumnach
	{                                                  
		for(int j=i; j<=(rozmiar-do_wygranej+i); j++) // Petla po mozliwych kombinacjach
		{
			for(int k=j; k<=(j+do_wygranej-1); k++) //Petla po tylu obok ile potzreba do wygranej
			{
				spr = tab[k];
				if(spr!=kto)  //Jesli kolo siebie nie ma wystarczajacej liczby znakow
				{
					win = false; //Brak zwyciestwa
					break;
				}
				else //Jesli sa
				{
					 win = true; //Zwyciestwo
				}
			}
			if(win==true) //Jesli zwyciestwo
			{
				if(!pom) // Tylko po wykonaniu ruchu, nie w algorytmie minimax
				{
					rysuj_plansze(tab, rozmiar, wymiar); //Wyswietlenie planszy
					cout <<endl<<"Wygrywa ";
					if(kto=='O')  //Wyswietlenie odpowiedniego komunikatu o zwyciezcy
					{
						cout<<"Gracz";
					}
					else
					{
						cout<<"Komputer";
					}
				}

				return true;
			}
		}
	}
    
	//Sprawdzanie czy nie nastapila wygrana w pioziomie
	for(int i=1; i<=rozmiar; i++) //Petla po wierszach
	{
		for (int j=i; j<=(i+wymiar-(do_wygranej*rozmiar)); j+=rozmiar) // Petla po mozliwych kombinacjach
		{
			for(int k=j; k<=((j+(do_wygranej-1)*rozmiar)); k+=rozmiar) //Petla po tylu obok ile potzreba do wygranej
			{
				spr = tab[k];
				if(spr!=kto) //Jesli kolo siebie nie ma wystarczajacej liczby znakow
				{
					win = false; //Brak zwyciestwa
					break;
				}
				else 
				{
					win = true; //Zwyciestwo
				}
			}
			if (win == true) //Jesli zwyciestwo
			{
				if(!pom) // Tylko po wykonaniu ruchu, nie w algorytmie minimax
				{
					rysuj_plansze(tab, rozmiar, wymiar); //Wyswietlenie planszy
					cout <<endl<<"Wygrywa ";
					if(kto=='O') //Wyswietlenie odpowiedniego komunikatu o zwyciezcy
					{
						cout<<"Gracz";
					}
					else
					{
						cout<<"Komputer";
					}
				}

				return true;
			}
		}
	}

	//Sprawdzanie czy nie nastapila wygrana po przekatnej w gore
	for(int i=do_wygranej; i<=wymiar-((do_wygranej-1)*rozmiar); i++) //Petla po przekatnej
	{ 
		if(tab[i] == kto) //Sprawdzenie czy na przekatnej jest odpowiedni znak
		{
			for(int j=i; j<=(do_wygranej-1)*rozmiar+i-do_wygranej+1; j=j+rozmiar-1) //Petla po tylu obok ile potzreba do wygranej
			{
				spr = tab[j];
				if (spr!=kto) //Jesli kolo siebie nie ma wystarczajacej liczby znakow
				{
					win = false; //Brak zwyciestwa
					break;
				}
				else
				{
					 win = true; //Zwyciestwo
				}
			}
			if (win == true) //Jesli zwyciestwo
			{
				if (!pom)  // Tylko po wykonaniu ruchu, nie w algorytmie minimax
				{
					rysuj_plansze(tab, rozmiar, wymiar); //Wyswietlenie planszy
					cout <<endl<<"Wygrywa ";
					if(kto=='O') //Wyswietlenie odpowiedniego komunikatu o zwyciezcy
					{
						cout<<"Gracz";
					}
					else
					{
						cout<<"Komputer";
					}
				}

				return true;
			}
		}
		if(i%rozmiar){}
		else for(int k=1; k<do_wygranej; k++) i++;
	}


	//Sprawdzanie czy nie nastapila wygrana po drugiej przekatnej w dol
	for (int i=wymiar-((do_wygranej-1)*rozmiar)-do_wygranej+1; i>=1; i--) //Petla po przekatnej po drugiej przekatnej
	{ 
		if(i%rozmiar){}
		else for(int k=1; k<do_wygranej; k++) i--;
		if(tab[i] == kto) //Sprawdzenie czy na przekatnej jest odpowiedni znak
		{
			for(int j=i; j<=(do_wygranej-1)*rozmiar+i+do_wygranej-1; j = j+rozmiar+1) //Petla po tylu obok ile potzreba do wygranej
			{
				spr = tab[j];
				if(spr != kto) //Jesli kolo siebie nie ma wystarczajacej liczby znakow
				{
					win = false; //Brak zwyciestwa
					break;
				}
				else
				{
                    win = true; //Zwyciestwo
				} 
			}
			if (win == true) //Jesli zwyciestwo
			{
				if (!pom) // Tylko po wykonaniu ruchu, nie w algorytmie minimax
				{
					rysuj_plansze(tab, rozmiar, wymiar); //Wyswietlenie planszy
					cout <<endl<<"Wygrywa ";
					if(kto=='O') //Wyswietlenie odpowiedniego komunikatu o zwyciezcy
					{
						cout<<"Gracz";
					}
					else
					{
						cout<<"Komputer";
					}
				}

				return true;
			}
		}
	}
	
	return false;
}
