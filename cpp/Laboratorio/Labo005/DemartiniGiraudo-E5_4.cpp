/*
Esercizio 5.4 C++
Data: 25/03/2021
Gruppo: DemartiniGiraudo

Scrivere un programma C++ che chiede all'utente di inserire una
serie di numeri interi fino a quando non verrà  inserito un 
carattere che non sia un intero. Al termine il programma stamperà
sullo standard output il prodotto dei numeri inseriti.
*/

#include <iostream>

using namespace std;

int main(){
    // Intero in input ad ogni ciclo
    int n;
    // Variabili per salvare prodotto e contatore per controllare numero fattori
    int prodotto=1, cnt=0;

    cout << "PRODOTTO (INSERIRE UN CARATTERE O UN VALORE DECIMALE PER TERMINARE)"<< endl;
    cout << "Inserisci fattori: "<< endl;

    // Input con controllo sull'intero inserito, se non intero esci
    while(cin>>n){
        // Moltiplico prodotto ad n se intero valido
        prodotto*=n;
        // Incrementa contatore dei fattori
        cnt++;
    }

    // Controlla che utente abbia inserito almeno un fattore
    if(cnt>0)
        cout << endl << "Prodotto = " << prodotto << endl << endl;
    else
        cout << endl << "Errore: Non hai inserito nessun fattore" << endl << endl;

    return 0;
}