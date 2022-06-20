#include "wynik.h"

//Prototypy funkcji
int minimax(char tab[], char kto, int rozmiar, int wymiar, int do_wygranej, int alfa, int beta, int glebokosc);
int ruch_komputera(char tab[], int rozmiar, int wymiar, int do_wygranej);
void gra(char tab[], char &kto, int rozmiar, int wymiar, int do_wygranej);
