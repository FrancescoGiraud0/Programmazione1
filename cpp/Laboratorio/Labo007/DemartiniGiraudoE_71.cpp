/*
Esercitazone 7.1 C++
Gruppo: DemartiniGiraudo
Data: 31/03/2020

Scrivere un programma che chieda all'utente un numero binario (base 2)
(a partire dal bit più significativo a quello meno significativo) e 
stampi il numero decimale corrispondente. Suggerimento leggere il 
numero come stringa. Controllare se effettivamente viene letto un 
numero binario, cioè è una stringa fatta di 0 e 1, in caso contrario 
segnalare errore.
*/

/*
PSEUDOCODICE:

1. Dichiara n_decimale, stringa n_binario
2. Per i da 0 a lung con lung=lunghezza stringa:
    2.1 i-esima cifra e' '0' o '1'?
        2.1.1 True:  moltiplica cifra per 2^(lung-i-1) e aggiungi a n_decimale
                     (Dato che prima cifra inserita e' la piu' significativa)
        2.1.2 False: segnala errore e termina programma
3. Stampa numero in base decimale
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    // Stringa per input del numero binario
    string n_binario;
    // Intero per salvare valore decimale
    int n_decimale=0;
    // Intero per lunghezza della stringa in input
    int lung;
    
    // Input stringa numero binario
    cout << "CONVERTITORE BINARIO -> DECIMALE" << endl;
    cout << "Inserisci il numero binario: ";
    cin >> n_binario;

    // Salva lunghezza della stringa inserita
    lung = n_binario.size();

    // Per tutti i caratteri della stringa
    for(int i=0; i<lung; i++){
        // Controlla la singola cifra
        switch(n_binario[i]){
            case '1':
                // Se e' '1' allora aggiungi la potenza decimale corrispondente
                n_decimale += pow(2,lung-i-1);
                break;
            case '0':
                // Se e' '0' non aggiungere niente ( sarebbbe 0*2^(lung-i-1)=0 )
                break;
            // Se il carattere i-esimo non e' una cifra binaria allora segnala errore e termina
            default:
                cout << "Errore: '" << n_binario[i] << "' non e' una cifra binaria" << endl;
                return 0;
        }
    }

    // Output del numero in base decimale
    cout << endl << n_binario << " [b2] = " << n_decimale << " [b10]" << endl;

    return 0;
}