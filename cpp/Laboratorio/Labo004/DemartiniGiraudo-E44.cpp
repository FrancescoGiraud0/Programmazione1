/*
Esercizio 4.4 C++
Data: 19/03/2021
Gruppo: DemartiniGiraudo

Scrivere un programma C++ che legge un un numero N intero e maggiore di 1 dallo standard input,
poi legge sempre da standard input N numeri reali strettamente positivi, e infine  stampa su 
standard output:
    - la loro media aritmetica,
    - la loro media geometrica
    -e il loro scarto quadratico medio o deviazione standard
*/

#include <iostream>
#include <cmath>

using namespace std;

const int DIM = 50; // Dimensione dell'array

int main(){
    int n=0;                                                    // Numero di valori considerati
    double vettore_num[DIM];                                    // Vettore dove salvare i valori in input
    double sommatoria=0, produttoria=1, sommatoria_quadrati=0;  // Variabili accomulatori
    double media_ar = 0, media_geom = 0, deviazione=0;          // Variabili per le medie e per la std

    // Input del numero di valori considerati
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
        // Input dell'i-esimo valore del vettore
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

        // Incremento del valore sommatoria con ultimo valore in input
        sommatoria  += vettore_num[i];  // Equivalente a sommatoria  = sommatoria  + vettore_num[i]
        // Moltiplico valore produttoria per ultimo valore in input
        produttoria *= vettore_num[i];  // Equivalente a produttoria = produttoria * vettore_num[i]
        // Incremento del valore sommatoria_quadrati con ultimo valore in input al quadrato
        sommatoria_quadrati += pow(vettore_num[i], 2);
    }

    media_ar   = sommatoria / n; // Calcolo media aritmetica (n e' sicuramente diverso da 0)
    media_geom = pow(produttoria, 1.0/n);   // Calcolo media geometrica
    deviazione = (1.0/n)*sqrt( (n*sommatoria_quadrati) - pow(sommatoria,2) ); // Calcolo deviazione std

    // Output dei risultati
    cout << endl;
    cout << "Media Aritmetica    = " << sommatoria << "/" << n << " = " << media_ar << endl;
    cout << "Media Geometrica    = " << media_geom << endl;
    cout << "Deviazione Standard = " << deviazione << endl;

    return 0;
}