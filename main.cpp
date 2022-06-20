#include "si.h"


int main()
{
	int rozmiar, do_wygranej=0, wymiar; //Zmienne zawierajace parametry gry
	cout <<endl<< "Gra Kolko i Krzyzyk" << endl;
	while(1) //Petla glowna programu
    {
        cout << "Podaj rozmiar planszy: ";
        cin >> rozmiar;
        cout << "Podaj liczbe znakow w rzedzie potrzebna do wygranej: ";
        cin >> do_wygranej;
        while(do_wygranej>rozmiar || do_wygranej<=0) // Sprawdzanie czy mozliwe jest wygranie na danej planszy
        {
            cout << "Liczaba znakow potrzbena do wygranej musi byc mniejsza lub rowna rozmiarowi planszy i wieksza od zera."<<endl<<"Sproboj ponownie: ";
            cin >> do_wygranej;
        }
        char kto;
        cout<<"Kto ma zaczac gre:  X-Komputer   O-Ty:    ";
        cin>>kto;                                          //Kto ma zaczac gre
         while(!(kto=='O' ||kto=='X')) // Sprawdzanie czy wybrano poprawnego gracza
        {
            cout << "Wygrano zły znak. Sproboj ponownie:  ";
            cin >> kto;
        }
        wymiar = rozmiar * rozmiar;
        char *tab = new char[wymiar+1];
        for(int i=1; i<=wymiar; i++) //Wypelnienie tablicy pustymi polami
        {
            tab[i] = ' ';
        }
        cout<<endl<<"Plansza do gry:"<<endl<<endl;
        while(1) //Petla przeprowadzajaca gre. Po kazdym ruchu sprawdza czy gra sie nie skonczyla
        {
            gra(tab, kto, rozmiar, wymiar, do_wygranej); //Wykonanie ruchu gracza lub komputera
            if (wygrana(tab, 'X', false, rozmiar, wymiar, do_wygranej) || //Sprawdzenie czy wygral Komputer
                wygrana(tab, 'O', false, rozmiar, wymiar, do_wygranej) || //Sprawdzanie czy wygral Gracz
                remis(tab, false, rozmiar, wymiar)) //Sprawdzenie czy wystapil remis
                break;
        }
        break;
    }
	cout << endl << "Koniec gry" << endl;

	return 0;
}
