/*  Esercizio 2.4 C++
    Data: 12/03/2021
    Gruppo: DemartiniGiraudo

    PSEUDOCODICE:

    1 INPUT 3 numeri reali positivi
    2 Nessun errore in input?
        - Vero: Continua
        - Falso: Fermati e segnala errore
    3 Sono tutti maggiori di 0?
        - Vero: Continua
        - Falso: Fermati e segnala errore
    4 I tre valori NON sono in ordine? [ovvero !(a>=b>=c)]
        - Vero :
            4.1 a<b?
                - Vero  : Scambia i valori di a e b
                - Falso : Non fare niente
            4.2 b<c?
                - Vero  : Scambia i valori di b e c
                - Falso : Non fare niente
            4.3 Ritorna al punto 4
        - Falso: Stampa i valori
    5 Termina
*/

#include<iostream>

using namespace std;

int main(){
    double a=0, b=0, c=0; // Variabili di input
    double s=0;           // Variabile usata per lo scambio dei valori

    // Inpute dei tre valori
    cout << "Inserire 3 numeri reali positivi: ";
    cin >> a >> b >> c;

    // Controllo input andato a buon fine
    if(!cin){
        cout << "Errore: inseriti in input valori non numerici" << endl;
        return 0;
    }

    // Controllo che siano tutti positivi
    if( !( (a>=0) && (b>=0) && (c>=0) ) ){
        cout << "Errore: inseriti in input uno o piu' valori negativi" << endl;
        return 0;
    }

    // Entra nel ciclo se i valori NON sono in ordine decrescente
    while( !((a>=b)&&(b>=c)) ){
        
        // Se a < b scambia a e b
        if(a<b){
            s = a;
            a = b;
            b = s;
        }

        // Se b < c scambia b e c
        if(b<c){
            s = b;
            b = c;
            c = s;
        }
    }

    cout << a << " " << b << " " << c << endl;

    return 0;
}