/*
Esercizio 5.2 C++
Data: 25/03/2021
Gruppo: DemartiniGiraudo

Scrivere un programma C++ che chiede all'utente un numero intero k>1, e stampa
sullo standard output tutti i suoi divisori (propri e impropri) in ordine 
crescente e dice se k è primo.
Il programma dovrà terminare con un messaggio di errore se il numero inserito
non è un intero >1.
*/

#include <iostream>
// Libreria cmath per funzioni sqrt() e floor()
#include <cmath>

using namespace std;

int main(){
    // Numero in input
    int k;
    // k e' primo fino a prova contraria
    bool primo=true;

    // Input di k
    cout << "DIVISORI DI K" << endl;
    cout << "Inserisci k: ";
    cin >> k;

    // Controllo input
    if(!cin){
        cout << "Errore: Inserito un valore non intero" <<endl;
        return 0;
    }

    // Controllo che k sia > 1
    if(k<=1){
        cout << "Errore: Inserito un valore minore o uguale a 1" <<endl;
        return 0;
    }

    // 1 divide ogni valore k intero
    cout << endl << "Divisori di " << k << ": " << endl << 1 << "\t";

    // Controllo dei divisori da 2 a k/2 compreso
    // (funzione floor() -> arrotonda per difetto)
    for(int i=2; i<=floor(k/2); i++){
        if(k%i==0){
            // Se i divide k allora k non e' primo
            // Se primo e' ancora true allora assegna primo a false
            if(primo) primo=false;
            // Stampa divisore i di k
            cout << i << "\t";
        }
    }

    // Ogni numero intero k ha sicuramente divisori 1 e k
    cout << k << endl;

    // Output
    if(primo)
        cout << endl << k << " e' un numero primo " <<endl;
    else
        cout << endl << k << " NON e' un numero primo " <<endl;
    return 0;
}
