/*
Esercizio 3.1 C++
Data: 18/03/2021
Gruppo: DemartiniGiraudo

Scrivere un programma C++ che permetta di esercitarsi con le quattro operazioni aritmetiche
utilizzando il costrutto if.

L'utente dovrà inserire due numeri interi (operandi) e un terzo numero, che identifica un'
operazione aritmetica nel seguente modo
- 1   indicherà la somma
- 2   indicherà la differenza
- 3   indicherà la moltiplicazione
- 4   indicherà la divisione

Il programma eseguirà l'operazione individuata dal terzo numero inserito, mostrando il
risultato.

Il programma dovrà informare l'utente se è avvenuto un errore di inserimento degli operandi
utilizzando if(!cin), o se ha inserito un numero non corrispondente ad una delle 4 operazioni,
o ancora se si tenta di fare la divisione per 0.

Testate il programma accertandovi che dia risultati corretti nella divisione tra due numeri
interi non divisibili (risultato non intero).
*/

#include <iostream>

using namespace std;

int main(){
    int operando1=0, operando2=0, operazione=0; // Dichiarazione operandi

    cout << "CALCOLATRICE\n1. Somma\n2. Differenza\n3. Moltiplicazione\n4. Divisione" << endl;
    cout << "operando1 operando2 operazione >> ";
    cin >> operando1 >> operando2 >> operazione; // Input operandi e codice operazione
    cout << endl;

    // Controllo errori in input
    if(!cin){
        cout << "Errore: Inseriti valori non interi" << endl;
        return 0;
    }

    // Switch con casi in base al valore del codice operazione
    switch(operazione){
        case 1:
            // operazione == 1 : Somma
            cout << operando1 << " + " << operando2 << " = " << operando1+operando2 << endl;
            break;
        case 2:
            // operazione == 2 : Differenza
            cout << operando1 << " - " << operando2 << " = " << operando1-operando2 << endl;
            break;
        case 3:
            // operazione == 3 : Moltiplicazione
            cout << operando1 << " * " << operando2 << " = " << operando1*operando2 << endl;
            break;
        case 4:
            // operazione == 4 : Divisione

            // Controllo per evitare divisioni per 0
            if(operando2!=0){
                // Controllo divisibilità degli operandi interi
                if(operando1%operando2==0){
                    // Divisibili, nessun casting a float
                    cout << operando1 << " / " << operando2 << " = " << operando1/operando2 << endl;
                }else{
                    // Divisione con risultato non intero
                    cout << "Attenzione: divisione non intera, risultato reale" << endl;
                    cout << operando1 << " / " << operando2 << " = " << (float)operando1/operando2 << endl;
                }
            }else{
                // Se operando2 è zero
                cout << "Errore: denominatore == 0, impossbile svolgere divisione" << endl;
            }
            break;
        default:
            // Nel caso il valore di operazione non sia un intero tra 1 e 4
            cout << "Errore: Operazione non riconosciuta" << endl;
    }

    return 0;
}
