/* Esercizio 2.3 C++
   Data: 12/03/2021
   Gruppo: DemartiniGiraudo

   Scrivere un programma C++ che presi in input due numeri interi dica se il primo
   e' divisibile per il secondo o se il secondo è divisible per il primo oppure dica
   che i due numeri non sono vicendevolmente divisibili (segnalare eventuali errori 
   in lettura).
*/

#include <iostream>

using namespace std;

int main(){
    // Variabili per salvare valori in input
    int a=0, b=0;
    // Stringhe in cui verrà salvato " divide " o " NON divide " a seconda del risultato ottenuto
    string a_divide_b, b_divide_a;

    // Input dei due valori interi
    cout << "Inserire due numeri interi: ";
    cin  >> a >> b;

    // Controllo correttezza input
    if(!cin){
        cout << "Errore: inseriti valori non interi in input" << endl;
        return 0;
    }

    // Controllo se sono due numeri uguali
    if(a==b){
        // Caso in cui a==b, ovvero a divide b e viceversa sempre vero
        a_divide_b = " divide "; 
        b_divide_a = " divide ";

    }else{

        // a divide b ? 

        // Controllo che a sia diverso da 0, per evitare divisioni per 0
        if(a!=0)
            /* Per controllare che a divide b sfruttiamo l'operatore % che
            *  restituisce il valore del resto della divisione intera a/b.
            *  Qui viene utilizzato anche l'operatore ternario, che è
            *  equivalente ad una if, ed ha la seguente struttura:
            * 
            *  nomeVariabile = (condizione) ? True : False;
            * 
            *  Quindi in questo caso ad a_divide_b viene assegnata la stringa
            *  " divide " se b%a uguale a 0 mentre " NON divide " se b%a
            *  diverso da 0. */
            a_divide_b = (b%a==0) ? " divide " : " NON divide ";
        else
            // Nel caso a==0, 0 non divide niente tranne 0
            a_divide_b = " NON divide ";

        // b divide a?

        // Ripetiamo il procedimento precedente, controllando che b!=0
        if(b!=0)
            b_divide_a = (a%b==0) ? " divide " : " NON divide ";
        else
            b_divide_a = " NON divide ";

    }

    // Output dei risultati
    cout << a << a_divide_b << b << endl;
    cout << b << b_divide_a << a << endl;

    return 0;
}