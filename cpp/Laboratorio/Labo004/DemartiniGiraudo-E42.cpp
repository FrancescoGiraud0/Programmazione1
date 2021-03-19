/*
Esercizio 4.2 C++
Data: 19/03/2021
Gruppo: DemartiniGiraudo

Scrivere un programma C++ che legge un un numero N intero e positivo dallo standard input,
poi stampa su standard output il fattoriale di N. Nel caso che la lettura non vada a buon 
fine o che N non sia maggiore di 0  il programma deve segnalare in maniera opportuna l'errore.

***
Si verifichi, dando in input numeri interi sempre maggiori, qual è l'intero N massimo per
cui è possibile calcolare il fattoriale ottenendo risultati corretti. Se anziché usare un 
intero per immagazzinare il risultato del calcolo, usiamo un long long int, otteniamo 
risultati diversi? Riflettere sulle relazioni con costante INT_MAX introdotta nelle lezioni 
ha con gli output che si ottengono quando l'input è maggiore di 10.
***
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
#include <climits> // Libreria per costanti con MAX numero intero rappresentabile

using namespace std;

int main(){
    int n=0;            // Valore n di input
    int fattoriale=1;   // Variabile in cui salvare valore fattoriale di n
    
    cout << "CALCOLATORE FATTORIALE" << endl;
    cout << "Inserire in input il valore di cui si vuole calcolare il fattoriale: ";
    cin >> n; // Input di n

    // Controllo correttezza input
    if(!cin){
        cout << "Errore: Inserire un valore intero positivo" << endl;
        return 0;
    }

    // Controllo che n sia strettamente positivo
    if(n<=0){
        cout << "Errore: Inserito un valore negativo, inserire un intero positivo" << endl;
        return 0;
    }

    for(int i=1; i<=n; i++){
        // Controllo per evitare overflow del valore del fattoriale
        // fattoriale*i > INT_MAX se e solo se fattoriale > INT_MAX/i
        if(fattoriale <= INT_MAX/i){
            fattoriale *= i; // Equivalente a  fattoriale = fattoriale*i
        }else{
            // Nel caso fattoriale*i > INT_MAX
            cout << "Errore: Overflow durante calcolo fattoriale" << endl;
            return 0;
        }
    }

    // Output del risultato
    cout << endl << n << "! = " << fattoriale << endl << endl;

    return 0;
}
