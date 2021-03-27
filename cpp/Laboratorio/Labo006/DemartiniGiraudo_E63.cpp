/*
Esercizio 6.3 C++
Data: 26/03/2021
Gruppo: DemartiniGiraudo

Scrivere un programma C++ che chiede all’utente di indovinare una
stringa di 8 caratteri, al massimo in 10 tentativi, utilizzando il
costrutto do while.
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    // Stringa da 8 lettere da indovinare
    const string DaIndovinare = "Gabbiano";
    // Contatore tentativi
    int NumeroTentativi = 10;
    // Variabile bool, true quando utente indovina parola
    bool HaiVinto = false;
    // Stringa utente in input
    string StringaUtente;

    do{
        // Output tentativi rimasti e richiesta input
        cout << endl;
        cout << NumeroTentativi << " TENTATIVI/O RIMASTI" << endl;
        cout << "Inserire parola segreta (8 Caratteri): ";

        // Input con controllo
        if(!(cin >> StringaUtente)){
            cout << "Errore: non hai inserito una stringa" << endl;
            return 0;
        }

        // Controlla se stringa utente e' uguale a quella da indovinare
        if(StringaUtente==DaIndovinare)
            // Quando indovina
            HaiVinto = true;
        else
            // Quando sbaglia
            cout << "Hai sbagliato!\n";

        // Avverte utente se inserita parola con lunghezza diversa da 8 caratteri
        if(StringaUtente.size()!=8)
            cout << "Attenzione! La parola segreta è lunga 8 Caratteri!" << endl;

        // Decrementa di uno il numero di tentativi
            NumeroTentativi--;

     // Rientra nel ciclo se ci sono ancora tentativi e non ha ancora indovinato
    }while(NumeroTentativi>0 && !HaiVinto);

    // Verifica se ha indovinato
    if(HaiVinto)
        // Se ha indovinato
        cout << endl << "Hai indovinato in "<< 10-NumeroTentativi << " tentativi/o!" << endl;
    else
        // Se hai terminato i tentativi
        cout << endl << "Hai esaurito i tentativi!" << endl;

    return 0;
}