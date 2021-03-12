/* Esercitazione 1A C++
   Data: 11/03/2021
   Gruppo: DemartiniGiraudo

   Dichiarare tre variabili destinate a contenere le lunghezze di base maggiore,
   base minore e altezza di un trapezio rettangolo. Chiedere all'utente i valori
   da metterci dentro. Calcolare l'area del trapezio e stamparla.
*/

#include <iostream> // Include la libreria standard per l'input-output

using namespace std;

int main(){
    // Dichiarazione delle variabili di input e di output che utilizzerà
    // nel programma ed inizializza ognuna a 0
    double base_min=0, base_magg=0, altezza=0, area=0;

    cout << "Inserire base minore del trapezio: "; // Output
    cin >> base_min; // Input valore base_min

    // Controlla che in input sia stato inserito un valore legittimo (numero)
    if(!cin){
        // Se inserito un valore non numerico esegue questo
        cout << "Errore: Devi inserire un numero" << endl; // Stampa messaggio errore
        return 0; // Termina esecuzione
    }
    
    cout << "Inserire base maggiore del trapezio: "; // Output
    cin >> base_magg; // Input della base maggiore

    // Controlla che in input sia stato inserito un valore legittimo (numero)
    if(!cin){
        // Se inserito un valore non numerico esegue questo
        cout << "Errore: Devi inserire un numero" << endl; // Stampa messaggio errore
        return 0; // Termina esecuzione
    }

    cout << "Inserire altezza del trapezio: "; // Output
    cin >> altezza; // Input dell'altezza
    
    // Controlla che in input sia stato inserito un valore legittimo (numero)
    if(!cin){
        // Se inserito un valore non numerico esegue questo
        cout << "Errore: Devi inserire un numero" << endl; // Stampa messaggio errore
        return 0; // Termina esecuzione
    }

    // Controlla che l'utente abbia inserito valori maggiori di 0 in input
    if((base_min>0) & (base_magg>0) & (altezza>0)){
        // Se TUTTI i valori sono positivi

        // Controlla che la base minore sia minore o uguale alla base maggiore
        if(base_min<=base_magg){
            // Se minore
            area = ((base_min+base_magg)*altezza)/2 ; // Calcola area del trapezioe
            cout << "Area del trapezio: " << area << endl; // Stampa valore ottenuto
        }else{
            cout << "Errore: Inserita BASE MINORE > BASE MAGGIORE " << endl; // Stampa messaggio di errore
        }

    }else{
        // Se ALMENO UNO dei valori è negativo 

        cout << "Errore: Inserito un valore negativo in input" << endl; //Stampa messaggio errore
    }

    return 0; // Termina esecuzione programma
}