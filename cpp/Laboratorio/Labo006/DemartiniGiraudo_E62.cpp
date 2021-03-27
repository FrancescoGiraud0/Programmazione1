/*
Esercizio 6.2 C++
Data: 26/03/2021
Gruppo: DemartiniGiraudo

Produrre un programma C++ che, usando il costrutto while, legga dei
caratteri dallo standard input e alla fine scriva sullo standard output
quante cifre decimali, quante lettere minuscole e quante lettere maiuscole
(in questo ordine) sono state lette. Il programma dovrà terminare quando
leggerà un carattere non appartenente a queste tre categorie.
*/

#include <iostream>

using namespace std;

int main(){
    // Carattere in input
    char c;
    // Valore numerico per codifica ASCII di c
    int n;
    // Contatori valori inseriti
    int n_cifredecimali=0, n_letteremaiuscole=0, n_lettereminuscole=0;
    
    cout << "CONTATORE CARATTERI ALFANUMERICI" << endl;
    cout << "Inserisci uno o piu' caratteri alfanumerici ";
    cout << "(inserisci un carattere non alfanumerico per terminare): " << endl;

    do{
        // Input con controllo valori inseriti
        if(!(cin >> c)){
            cout << "Errore: Non e' stato inserito un carattere "<<endl;
            return 0;
        }

        // n e' il codice ASCII di c inserito
        n = (int)c;

        if ((n>=48)&&(n<=57))
            // Se c cifra decimale incrementa contatore
            n_cifredecimali++;
        else if ((n>=65)&&(n<=90))
            // Se c lettera maiuscola incrementa contatore
            n_letteremaiuscole++;
        else if ((n>=97)&&(n<=122))
            // Se c lettera minuscola incrementa contatore
            n_lettereminuscole++;
    
    // Rientra nel ciclo solo se ultimo carattere inserito e' alfanumerico
    }while(((n>=48)&&(n<=57)) || ((n>=65)&&(n<=90)) || ((n>=97)&&(n<=122)));

    // Output dei contatori
    cout << endl;
    cout << "CIFRE DECIMALI    = " << n_cifredecimali    << endl;
    cout << "LETTERE MAIUSCOLE = " << n_letteremaiuscole << endl;
    cout << "LETTERE minuscole = " << n_lettereminuscole << endl;

    return 0;
}
