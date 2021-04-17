/*
Esercizio 9.3 C++
Gruppo: DemartiniGiraudo
Data: 15/04/2021

Scrivere un programma che chieda all'utente di inserire un numero intero N
maggiore di 0, e poi chieda N numeri interi. Poi stampi tutti i pari letti
seguiti da quelli dispari (0 è pari).
L'ordinamento tra i pari e tra i dispari non è rilevante.

Suggerimento leggere i numeri ed inserirli in due array, uno per i pari ed
uno per i dispari.
*/

#include <iostream>

using namespace std;

int main(){
    // Array dinamici per elementi pari e dispari
    int *array_pari = NULL;
    int *array_dispari = NULL;
    // Array dinamico di supporto
    int *array_scambio = NULL;
    // a-> per input dell'i-esimo valore, n-> numero di valori 
    int a, n;
    // Contatori elementi pari e dispari
    int cont_pari=0, cont_disp=0;

    cout << "Inserire n (numero di valori): ";
    cin >> n;

    // Controllo errori in input
    if(!cin){
        cout << "Errore: inserito un valore non valido" << endl;
        return 0;
    }

    // Controllo che n sia positivo
    if(n<=0){
        cout << "Errore: inserito un valore n intero negativo" <<endl;
        return 0;
    }

    // Per n volte
    for(int i=0; i<n; i++){

        // Input dell'i-esimo valore
        cout << "[" << i+1 << "] -> ";
        cin >> a;

        // Controllo errori in input
        if(!cin){
            cout << "Errore: inserito un valore non valido" << endl;
            return 0;
        }

        // a pari?
        if(a%2==0){
            /* Se a pari.
               Salva l'area di memoria puntata da array_pari in array_scambio.
               Quindi alloca nuovamente array_pari con una dimensione maggiore
               di 1 rispetto a prima.
               Quindi salva tutti i valori di array_scambio in array_pari
               e aggiunge in fondo l'ultimo valore letto.
               Infine disalloca area di memoria puntata da array_scambio, che
               viene assegnato a NULL e incrementa contatore dei pari.
            */
            array_scambio = array_pari;
            
            array_pari = new int[cont_pari+1];

            for(int i=0; i<cont_pari; i++){
                array_pari[i] = array_scambio[i];
            }
            
            array_pari[cont_pari] = a;

            delete [] array_scambio;
            array_scambio = NULL;

            cont_pari++;
        }else{ 
            /* Se a dispari.
               Salva l'area di memoria puntata da array_dispari in array_scambio.
               Quindi alloca nuovamente array_dispari con una dimensione maggiore
               di 1 rispetto a prima.
               Quindi salva tutti i valori di array_scambio in array_dispari
               e aggiunge in fondo l'ultimo valore letto.
               Infine disalloca area di memoria puntata da array_scambio, che
               viene assegnato a NULL e incrementa contatore dei dispari.
            */
            array_scambio = array_dispari;
            
            array_dispari = new int[cont_disp+1];

            for(int i=0; i<cont_disp; i++){
                array_dispari[i] = array_scambio[i];
            }

            delete [] array_scambio;
            array_scambio = NULL;
            
            array_dispari[cont_disp] = a;

            cont_disp++;
        }
    }

    // Stampa i due array letti
    cout << "\nValori Pari inseriti: \n";
    for(int i=0; i<cont_pari; i++){
        cout << "[" << i+1 << "] -> " << array_pari[i] << endl;
    }

    cout << "\nValori Dispari inseriti: \n";
    for(int i=0; i<cont_disp; i++){
        cout << "[" << i+1 << "] -> " << array_dispari[i] << endl;
    }

    // Disalloca gli array
    delete [] array_pari;
    delete [] array_dispari;

    return 0;
}