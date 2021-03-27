/*
Esercizio 6.1 C++
Gruppo: DemartiniGiraudo
Data: 26/03/2021

Produrre un programma C++ che legga un carattere dallo standard input
e scriva sullo standard output il numero corrispondente secondo la codifica
ASCII. Poi il programma dovrà effettuare la trasformazione opposta: ossia
leggere un numero intero compreso tra 0 e 126 dallo standard input e
scrivere sullo standard output il corrispondente carattere secondo la
codifica ASCII (per i caratteri non stampabili scrivete semplicemente la
stringa ”non stampabile”).
Extra: modificate il programma facendogli leggere e trasformare dei
numeri fino a quando leggerà un numero non compreso tra 0 e 126.
*/

#include <iostream>

using namespace std;

int main(){
    // Carattere in input
    char c;
    // Numero compreso tra 0 e 126 in input
    int n;

    // Input del carattere
    cout << "ASCII CHAR TO INT" << endl;
    cout << "Inserisci un carattere: ";
    cin >> c;

    // Controllo eventuali errori in input
    if(!cin){
        cout << "Errore: Non e' stato inserito un carattere "<<endl;
        return 0;
    }

    // Output codice ASCII del carattere inserito
    cout << c << " -> "  << (int)c << endl;

    cout << endl << "ASCII INT TO CHAR (INSERIRE UN VALORE NON VALIDO PER TERMINARE)" << endl;
    do{
        // Input di un numero tra 0 e 126
        cout << "Inserisci un numero intero tra 0 e 126: ";
        cin >> n;

        // Controllo input del numero
        if(!cin){
            cout << "Errore: Non e' stato inserito un intero, termina esecuzione" <<endl;
            return 0;
        }

        // Controlla che il numero intero sia compreso tra 0 e 126
        if ((n<0)||(n>126))
            // Se n negativo o maggiore di 126
            cout << "Errore : valore inserito non e' una codifica ASCII, termina esecuzione" <<endl;
        else if (n<32)
            // Se n e' compreso tra 0 e 32 allora carattere non stampabile
            cout << n << " ->  Carattere non stampabile  "<<endl;
        else
            // Se n e' compreso tra 32 e 126 (compresi)
            cout << n << " -> "  << (char)n <<endl;

     // Rientra nel ciclo se e' stato inserito un numero compreso tra 0 e 126
    }while((n>=0)&&(n<=126));

    return 0;
}
