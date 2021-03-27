/*
Esercizio 6.4 C++
Data: 26/03/2021
Gruppo: DemartiniGiraudo

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
    // Costante dimensione massima vettore
    const int DIM=100;
    // Per numero di valori di cui si vuole calcolare la media armonica
    int n=0;
    // Array in cui salvare i valori in input
    double array_valori[DIM];
    // Variabile per somma dei reciproci inizializzata a zero
    double somma_reciproci=0;

    // Input del numero di valori considerati
    cout << "MEDIA ARMONICA DI N VALORI" << endl;
    cout << "Inserire n: ";
    cin >> n;

    // Controllo errori in input
    if(!cin){
        cout << "Errore: inserito un valore non valido" << endl;
        return 0;
    }

    // Controllo numero di valori da gestire, deve essere compreso tra 3 e 100
    if((n<3) || (n>100)){
        cout << "Errore: inserire un valore n compreso tra 3 e 100" <<endl;
        return 0;
    }

    // Input degli n valori
    cout << "Inserire valori: " << endl;
    for(int i=0; i<n; i++){
        // Input dell'i-esimo valore
        cout << "[" << i+1 << "] -> ";
        cin >> array_valori[i];

        // Controllo correttezza valore in input
        if(!cin){
            cout << "Errore: inserito un valore non valido" << endl;
            return 0;
        }

        // Controllo inserimento valore >= 0
        if(array_valori[i]<0){
            cout << "Errore: inserito un valore negativo" << endl;
            return 0;
        }
    }

    // Ciclo for per il calcolo della somma dei reciproci
    for(int i=0; i<n; i++){
        
        if(array_valori[i]==0){
            // Se il valore e' uguale a zero, non esiste il reciproco
            cout << "Errore: Divisione per zero, impossibile calcolare reciproco" << endl;
            // Allora non esiste media armonica, quindi termina programma
            return 0;
        }
        
        // Se valore diverso da zero somma il reciproco alla somma dei reciproci
        somma_reciproci += 1/array_valori[i];
    }

    // Stampa valore della media armonica, la somma dei reciproci sicuramente > 0
    cout << "Media armonica = " << n/somma_reciproci << endl;

    return 0;
}