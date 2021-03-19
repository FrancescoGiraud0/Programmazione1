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

/*
INT_MAX   = 2147483647
LONG_MAX  = 9223372036854775807 
LLONG_MAX = 9223372036854775807

Quindi e' possibile calcolare il fattoriale fino al valore 12 (12! = 479001600), mentre dal
valore 13 andra' in overflow.
Per long long int fattoriale, è possibile calcolare il fattoriale fino a 20, mentre dal
valore 21 andra' in overflow.
*/

#include <iostream>

using namespace std;

const int DIM = 50; // Dimensione dell'array

int main(){
    double vettore_num[DIM]; // Creazione del vettore di dimensione DIM = 50
    int n=0;                 // Variabile n per numero di valori in input
    double min=0, max=0;     // Variabili per salvare min e max

    cout << "Inserire numero di valori: ";
    cin >> n;

    // Controllo errori in input
    if(!cin){
        cout << "Errore: inserito un valore non valido" << endl;
        return 0;
    }

    // Controllo numero di valori da gestire, deve essere compreso tra 0 e DIM (== 50)
    if( (n<=0)||(n>DIM) ){
        cout << "Errore: inserire un valore strettamente positivo minore di " << DIM << endl;
        return 0;
    }

    for(int i=0; i<n; i++){
        // Input dell'i-esimo valore 
        cout << "[" << i+1 << "] -> ";
        cin >> vettore_num[i];

        // Controllo correttezza valori in input
        if(!cin){
            cout << "Errore: inserito un valore non valido" << endl;
            return 0;
        }

        // Controllo inserimento valore strettamente maggiore di 0
        if(vettore_num[i]<=0){
            cout << "Errore: inserito un valore negativo" << endl;
            return 0;
        }

        if(i==0){
            // Per il primo ciclo assegno min e max al primo valore inserito
            max = vettore_num[i];
            min = vettore_num[i];
        }else{
            // Se non siamo al primo ciclo

            if(max<vettore_num[i])
                // Se max e' minore dell'ultimo valore inserito
                max = vettore_num[i]; // l'ultimo valore diventa il nuovo max 

            if(min>vettore_num[i])
                // Se min e' maggiore dell'ultimo valore inserito
                min = vettore_num[i]; // l'ultimo valore diventa il nuovo min
        }
    }

    // Stampa dei valori minimo e massimo tra quelli inseriti
    cout << "MIN = " << min << endl;
    cout << "MAX = " << max << endl;

    return 0;
}