/*
Esercizio 5.1 C++
Data: 25/03/2021
Gruppo: DemartiniGiraudo

Prima stampa:
    per i da 1 a 10 scrivere la tabellina di i: ovvero per j da 1 a 10
    scrivere  i*j

Seconda stampa:
    come la prima ma il secondo ciclo termina con valori che dipendono da i
*/

#include <iostream>

using namespace std;

int main(){

    for(int i=1; i<=10; i++){
        for(int j=1; j<=10; j++){
            cout << i*j << "\t";
        }
        cout << endl;
    }

    cout << endl;

    for(int i=1; i<=10; i++){
        for(int j=1; j<=10; j++){

            if(i>=j)
                // Se siamo sulla diagonale oppure sotto di essa
                cout << i*j << "\t";
            else
                // Imposta j=10 in modo da uscire dal seconodo ciclo for
                // se sopra la diagonale principale
                j=10;
            
        }
        // Vai a capo a fine riga
        cout << endl;
    }

    return 0;
}