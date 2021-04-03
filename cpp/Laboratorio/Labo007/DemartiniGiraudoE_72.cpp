/*
Esercitazone 7.2 C++
Gruppo: DemartiniGiraudo
Data: 31/03/2020

Produrre un programma C++ che dopo aver letto dallo standard input
un intero non negativo minore di 100, scriva sullo standard output
la sua rappresentazione binaria (fatta usando i caratteri '0' e '1').

Usate  l'algoritmo introdotto a lezione per trovare la rappresentazione
binaria, che però vi porterà a trovare per prime le cifre meno 
significative, quindi vi suggeriamo di scrivere tali cifre mano a mano
che le trovate in un array, alla fine basterà stamparlo a partire 
dall'ultima cifra inserita.
*/

/*
PSEUDOCODICE:

1. Dichiara n_decimale, stringa n_binario e variabili q ed r (quoziente e resto)
2. Input di n_decimale con dovuti controlli
3. Assegna n_decimale a q (q=n_decimale)
4. r=q%2, q=q/2 (divisione intera)
5. Aggiungi r all'inizio della stringa (resto sara' 0 o 1 per divisione per 2)
6. q>0?
    6.1 True:  torna a punto 4
    6.2 False: finisci ciclo e stampa numero


Esempio: 25(base10) = ? (base2)

q  |  r
25 |  /     
12 |  1     q = 25/2 = 12   r=1
6  |  0     q = 12/2 =  6   r=0
3  |  0     q =  6/2 =  3   r=0
1  |  1     q =  3/2 =  1   r=1
0  |  1     q =  1/2 =  0   r=1

(Leggere colonna r da basso verso alto)

25(base10) = 11001(base2)
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    // Stringa vuota per il numero binario
    string n_binario="";
    // Intero per numero in base decimale
    int n_decimale;
    // Variabili per quoziente e resto
    int q=0, r=0;

    // Input del numero decimale
    cout << "CONVERTITORE DECIMALE -> BINARIO" << endl;
    cout << "Inserisci il numero decimale positivo (<100): ";
    cin >> n_decimale;

    // Controllo che sia un intero
    if(!cin){
        cout << "Errore: inserito un numero non intero" << endl;
        return 0;
    }

    // Controllo che sia positivo e < 100
    if((n_decimale<0) || (n_decimale>=100)){
        cout << "Errore: inserito un intero non compreso tra 0 e 100" << endl;
        return 0;
    }
    
    // Assegna primo quoziente a n_decimale
    q = n_decimale;

    do{
        // Calcolo il resto della divisione per 2
        r = q % 2;
        // Calcola divisione (intera) per 2
        q /= 2;

        if(r==0)
            // Se r e' 0 allora aggiungi carattere '0' all'inizio della stringa
            n_binario = '0'+ n_binario;
        else
            // Se no r sara' uguale a 1, allora aggiungi carattere '1' all'inizio
            n_binario = '1'+ n_binario;

    // Entra nel ciclo fino a che q e' maggiore stretto di 0
    // Ovvero esce quando q arriva a 0
    }while(q>0);

    // Output del numero in base binaria
    cout << endl << n_decimale << " [b10] = " << n_binario << " [b2]" << endl;

    return 0;
}