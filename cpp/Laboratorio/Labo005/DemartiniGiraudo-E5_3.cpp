/*
Esercizio 5.3 C++
Data: 25/03/2021
Gruppo: DemartiniGiraudo

Scrivere un programma C++ che stampa su standard output i primi K numeri primi,
dove K è un intero inserito dall'utente.
Suggerimento: utilizzare il codice dell'esercizio precedente, il costrutto while
e una variabile contatore che conta i numeri primi trovati.
Di nuovo prima formulate l'algoritmo e descrivetelo usando il pseudo-codice,poi
scrivete il codice C++.
*/
/*
PSEUDOCODICE
1. cnt <- 0, p <- 2
2. Input di k
3. k < cnt?
    - 3.1 VERO: 
        - p e' primo?
            - 3.1.1 VERO  -> Stampa p ed incrementa cnt di 1
            - 3.1.2 FALSO -> Non fare niente
        - Incrementa p di 1
        - Ritorna a 3.1
    - 3.2 FALSO: Fine del ciclo
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    // Valore di primi stampare
    int k;
    // Per capire se il valore p e' primo
    bool primo;
    // Contatore di primi stampati
    int cnt=0;
    // Variabile per p da stampare se primo, primo valore e' 2
    int p=2;

    // Input di k
    cout << "STAMPA I PRIMI K NUMERI PRIMI" << endl;
    cout << "Inserisci k: ";
    cin >> k;

    // Controllo input k
    if (!cin){
        cout << "Errore: Inserito un valore non intero" <<endl;
        return 0;
    }

    // Controllo che k sia maggiore stretto di 1
    if (k<1){
        cout << "Errore: Inserito un valore minore di 1" <<endl;
        return 0;
    }

    // Entra nel ciclo il contatore e' minore di k
    while (cnt<k){
        // p e' primo fino a che non troviamo almeno un divisore
        primo=true;

        // Se p NON e' primo allora ha almeno un divisore <= sqrt(p)
        // Quindi per capire se non e' primo controlla se esiste un
        // divisore di p compreso tra 2 e sqrt(p) arrotondata
        // per eccesso (funzione ceil()).
        // Ottimizziamo di più facendo prima un controllo su 2 e poi
        // controllando solo i divisori dispari tra 3 e sqrt(p).
        // Dato che 2 e' l'unico primo pari allora controlliamo che 
        // p sia maggiore di 2.
        if((p%2==0) && (p>2))
            primo=false;
        // Entra nel ciclo solo se i e' minore della radice di p e primo e' true
        for (int i=3; ( i<=ceil(sqrt(p)) ) && (primo); i+=2){
            if (p%i==0)
                primo=false;
        }
        
        if (primo){
            // Incrementa contatore dei primi stampati
            cnt++;
            // Se p e' primo lo stampa
            cout << "[" << cnt << "]\t" <<  p << endl;
        }
        
        // Incrementa p di 1
        p++;
    }

    cout << endl;

    return 0;
}


