/*
Esercitazione 7.3 C++
Gruppo: DemartiniGiraudo
Data: 31/03/2020

Utilizzando:  il costrutto if-then-else e gli operatori logici ( && e || ), 
scrivere un programma chechieda all'utente una parola di 5 caratteri e controlli
che vengano inserite tutte lettere ( possono essere lettere maiuscole o minuscole),
ovvero segnali un errore se viene inserito un carattere che non corrisponde ad una
lettera.

Dopo l'inserimento corretto della parola chieda all'utente di scegliere tre opzioni
di trasformazione tra maiuscolo e minuscolo (ovviamente le lettere rimangono le
stesse):
    0. tutte maiuscole 
    1. tutte minuscole
    2. una maiuscola una minuscola
*/

/*
PSEUDOCODICE

1. Input stringa e controllo
2. Input opzione
3. Per ogni carattere nella stringa
    4. E' minuscolo/maiuscolo?
        -True: 4.1 Deve essere minuscolo/maiuscolo?
                    - True:  non fare niente
                    - False: togli/aggiungi 32
        -False: Passa al prossimo carattere
5. Stampa stringa
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    // Matrice 2x3 di interi con la codifica ASCII dei carattareri di inizio e fine
    // delle lettere maiuscole e minuscole, e come terzo elemento la distanza tra
    // caratteri minuscoli e maiuscoli con segno.
    // riga 0 -> array con parametri trasformazione da minuscolo a maiuscolo
    // riga 1 -> array con parametri trasformazione da maiuscolo a minuscolo
    const int trasf[2][3] = { {'a', 'z', 'A'-'a'},   // [ 97, 122, -32]
                              {'A', 'Z', 'a'-'A'} }; // [ 65,  90, +32]

    // Stringa per input della stringa utente
    string stringautente;
    // Stringa da modificare
    string modificata;
    // Opzione di trasformazione stringa
    unsigned int op;
    // Per indice di trasformazione nell'array trasf
    unsigned int  t;
    // Per salvare carattere ad ogni ciclo
    char ch;

    // Input stringa utente
    cout << "TRASFORMAZIONE STRINGHE NUMERICHE" << endl;
    cout << "Inserisci la stringa da trasformare: ";
    cin >> stringautente;

    for(unsigned int i=0; i<stringautente.size(); i++){

        // Salva carattere i-esimo della stringa
        ch = stringautente[i];
        
        if ( ((ch<trasf[0][0]) || (ch>trasf[0][1])) && ((ch<trasf[1][0]) || (ch>trasf[1][1])) ){
            // Quindi se ch non e' una lettera minuscola (o maiuscola a seconda del caso)
            // allora si tratta di un carattere NON alfanumerico.

            // Segnala errore all'utente
            cout << endl << "Errore: " << ch << " non e' una lettera" << endl;
            return 0;
        }

    }

    // Assegna stringa modificata a stringa utente
    // andra' a lavorare su quella modificata da qua in poi
    modificata = stringautente;

    // Input opzione
    cout <<endl<< "Opzioni di modifica: " <<endl;
    cout << "0. TUTTO MAIUSCOLO\n1. tutto minuscolo\n2. UnA MaIuScOlA UnA MiNuScOlA\n>> ";
    cin  >> op;

    // Controllo che sia un intero
    if(!cin){
        cout << "Errore: inserito un numero non intero" << endl;
        return 0;
    }

    for(unsigned int i=0; i<modificata.size(); i++){

        // Assegna indice di trasformazione t
        // Se op=0, oppure op=2 e i pari allora:
        //      t=0 -> trasformazione carattere in maiscolo  (riga 0 matrice trasf)
        // Se op=1, oppure op=2 e i dispari allora:
        //      t=1 -> trasformazione carattere in minuscolo (riga 1 matrice trasf)
        t  = (op<=1)? op : i%2;

        // Salva carattere i-esimo della stringa
        ch = modificata[i];

        // Se t=0 considera i caratteri minuscoli (compresi tra 97 e 122)
        // Se t=1 considera i caratteri maiuscoli (compresi tra 65 e 90)
        // Quindi aggiungera':
        // -32 se t=0
        // +32 se t=1
        if( (ch>=trasf[t][0]) && (ch<=trasf[t][1]) ) 
            modificata[i] += trasf[t][2];
    }

    // Stampa risultato
    cout << endl << "Stringa originale:  "<< stringautente << endl;
    cout << endl << "Stringa modificata: "<< modificata << endl;

return 0;
}
