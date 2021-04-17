/*
Esercizio 9.2 C++
Gruppo: DemartiniGiraudo
Data: 15/04/2021

Rifare l'esercizio: 6.4 (riusando la vostra soluzione,
dopo averle corrette nel caso  vi siano stati segnalati
dei problemi, altrimenti riusando la nostra) modificando
l'allocazione statica in allocazione dinamica degli array
ed eliminando le restrizioni sul numero massimo di
elementi processabili. 
*/

/*
Consegna esercizio 6.4 C++

Scrivere un programma C++ che:
1. chieda all’utente il numero N (con N>=3 e N<=100) di dati da
elaborare (segnalare come errore se N<3 o N>100);

2. legga dallo standard input N numeri reali maggiori o uguali a zero e li
assegni agli elementi di un array (segnalare opportunamente gli errori
in input);

3. solo alla fine di 2. calcoli media, media geometrica, media armonica
(vedere il Labo 4). Attenzione: si possono calcolare tutte le medie
in tutti i casi? C’è qualche caso in cui non si possono calcolare?
Segnalarlo adeguatamente;

4. stampi i risultati sullo standard output.

Nota: la media armonica è il reciproco della media dei reciproci.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    // Numero di valori di cui si vuole calcolare la media armonica
    int n;
    // Array dinamico in cui salvare i valori in input
    double *array_valori = NULL;
    double somma_reciproci=0, somma=0, prodotto=1;

    // Input del numero di valori considerati
    cout << "CALCOLO MEDIE CON ARRAY DINAMICO" << endl;
    cout << "Inserire n (numero di valori): ";
    cin >> n;

    // Controllo errori in input
    if(!cin){
        cout << "Errore: inserito un valore non valido" << endl;
        return 0;
    }

    // Controllo numero di valori da gestire, deve essere maggiore di 3
    if(n<3){
        cout << "Errore: inserire un valore n>=3" <<endl;
        return 0;
    }

    // Alloca array dinamico di double di dimensione n    
    array_valori = new double[n];

    // Input degli n valori
    cout << "Inserire valori: " << endl;

    for(int i=0; i<n; i++){

        // Input dell'i-esimo valore
        cout << "[" << i+1 << "] -> ";
        cin >> array_valori[i];

        if(!cin){
            cout << "Errore: inserito un valore non valido" << endl;
            return 0;
        }

        // Controllo che valore inserito >= 0
        if(array_valori[i]<0){
            cout << "Errore: inserito un valore negativo" << endl;
            return 0;
        }
    }

    // Ciclo for per il calcolo delle somme e del prodotto
    for(int i=0; i<n; i++){
        
        // Se valore diverso da zero, somma il reciproco alla somma dei reciproci
        if(array_valori[i]!=0)
            somma_reciproci += 1/array_valori[i];

        somma += array_valori[i];

        prodotto *= array_valori[i];
    }

    // Disalloca array dinamico, non ci serve piu' una volta fatte le somme
    delete [] array_valori;
    
    // n>=3, quindi sempre possibile calcolare la media
    cout << "Media = " << somma/n << endl;

    // Stampa valore della media geometrica, prodotto diverso da 0
    if(prodotto!=0)
        cout << "Media geometrica = " << pow(prodotto, 1.0/n) << endl;
    else
        cout << "Errore: Non e' possibile calcolare la media geometrica" << endl;

    // Stampa valore della media armonica, se la somma dei reciproci diverso da 0
    if(somma_reciproci!=0)
        cout << "Media armonica = " << n/somma_reciproci << endl;
    else
        cout << "Errore: Non e' possibile calcolare la media armonica" << endl;

    return 0;
}