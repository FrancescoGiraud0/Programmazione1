/*
Esercizio 4.3 C++
Data: 19/03/2021
Gruppo: DemartiniGiraudo

Scrivere un programma C++ che legge un un numero N intero e positivo dallo standard input,
poi legge sempre dallo standard input N numeri reali strettamente positivi, e  stampa su 
standard output il massimo ed il minimo tra di essi.   Segnalare opportunamente OGNI errore
che potrebbe verificarsi durante l'esecuzione di questo programma (es: lettura che non va a
buon fine, N che non rispetta il vincolo di essere maggiore di 1, ...).
*/

#include <iostream>

using namespace std;

int main(){
    int n=0;              // Variabile n per numero di valori in input
    double in;            // Variabile per input n valori
    double min=0, max=0;  // Variabili per salvare min e max

    cout << "Inserire numero di valori: ";
    cin >> n;

    // Controllo errori in input
    if(!cin){
        cout << "Errore: inserito un valore non valido" << endl;
        return 0;
    }

    // Controllo numero di valori da gestire, deve essere compreso tra 0 e DIM (== 50)
    if((n<=0)){
        cout << "Errore: inserire un valore strettamente positivo" << endl;
        return 0;
    }

    for(int i=1; i<=n; i++){
        // Input dell'i-esimo valore 
        cout << "[" << i << "] -> ";
        cin >> in;

        // Controllo correttezza valori in input
        if(!cin){
            cout << "Errore: inserito un valore non valido" << endl;
            return 0;
        }

        // Controllo inserimento valore strettamente maggiore di 0
        if(in<=0){
            cout << "Errore: inserito un valore negativo" << endl;
            return 0;
        }

        if(i==1){
            // Per il primo ciclo assegno min e max al primo valore inserito
            max = in;
            min = in;
        }else{
            // Se non siamo al primo ciclo
            
            if(max<in)
                // Se max e' minore dell'ultimo valore inserito
                max = in; // l'ultimo valore diventa il nuovo max 

            if(min>in)
                // Se min e' maggiore dell'ultimo valore inserito
                min = in; // l'ultimo valore diventa il nuovo min
        }
    }

    // Stampa dei valori minimo e massimo tra quelli inseriti
    cout << "MIN = " << min << endl;
    cout << "MAX = " << max << endl;

    return 0;
}