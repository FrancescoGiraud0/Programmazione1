/*
Esercizio 3.2 C++
Data: 18/03/2021
Gruppo: DemartiniGiraudo

Scrivere un programma che permetta di risolvere  un'equazione di secondo grado
aX2 + bX + c = 0 dati i suoi coefficienti.

Più precisamente il programma deve considerare tutti i seguenti casi:
-se a vale 0 equazione di I grado: 
    considerare tutti i casi possibili a seconda dei valori di b e c
-se a diverso da 0 equazione di II grado e
    + se discriminante  < 0: il programma comunica che non ci sono soluzioni reali
    + se discriminante == 0: il programma comunica che le soluzioni sono reali e 
                             coincidenti e ne mostra il valore
    + se discriminante  > 0: il programma comunica che le soluzioni sono reali e 
                             ne mostra il valore.
*/

/*
PSEUDOCODICE:
1. Input a,b,c
2. Controllo che a,b,c siano numeri reali
3. a == 0?
    - True: (Equazione di primo grado) b == 0?
            - True: c == 0?
                    -True:  0=0 ha infinite soluzioni
                    -False: c=0 e' assurdo, nessuna soluzione
            - False: bX+c ha soluzione X= (-c)/b
    - False: (Equazione di secondo grado)
        3.1 Calcolo delta eq. di secondo grado
        3.2 Calcolo prima soluzione
        3.3 delta >= 0?
            - True: delta > 0?
                    - True:  Calcolo seconda soluzioni e stampa le soluzioni
                    - False: (delta==0) Stampa prima soluzione
            - False: Stampa messaggio di errore
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double a=0, b=0, c=0; // Coefficienti dell'equazione
    double delta=0;       // Variabile per il delta
    double s1=0, s2=0;    // Variabili per le soluzioni dell'equazione

    cout << "RISOLUTORE DI EQUAZIONI DI SECONDO GRADO" << endl;
    cout << "aX^2 + bX + c = 0 " << endl;
    cout << "Inserire a b c >> ";
    cin >> a >> b >> c; // Input dei tre coefficienti

    // Controllo errori in input
    if (!cin){
        cout << "Errore: Inserire valori numerici" <<endl;
        return 0;
    }

    // Verifica se equazione e' di primo grado
    if (a==0) {
        
        // Verifica se b e' uguale a 0
        if (b==0){
            // Equazione senza incognita X
            if(c!=0)
                // Caso equazione del tipo c=0, con c reale e c!=0
                cout << "Errore: L'equazione non ha soluzione" << endl;
            else
                // Caso equazione 0=0, uguaglianza sempre vera per ogni valore di X
                cout << "L'equazione 0 = 0" << endl << "Ha infinite soluzioni" << endl;
            
        }else{
            // Caso equazione di primo grado bX + c = 0

            s1= (-c)/b; // Calcolo dell'unica soluzione reale

            cout << "L'equazione e' di primo grado" <<endl;
            cout << "L'equazione " << b << "X + " << c << " = 0 "<<endl;
            cout << "Ha 1 soluzione: " << " X = " << s1 <<endl;
        }

    }else{
        // Caso equazione di secondo grado
        
        delta= pow(b,2)- 4*a*c; // Calcolo valore del delta dell'equazione

        // Distinguo i casi in base al delta
        if (delta>=0){
            // Caso delta >=0, ha almeno una soluzione

            s1= (-b + sqrt(delta)) / (2*a); // Calcolo prima soluzione

            cout << "L'equazione " << a << "X^2 + " << b << "X + " << c << " = 0 "<< endl;
            if (delta>0){
                // Se delta > 0, ha due soluzioni
                s2= (-b - sqrt(delta)) / (2*a); // Calcolo seconda soluzione
                cout << "Ha 2 soluzioni: " << " X1 = " << s1 << " X2 = "<< s2 << endl;
            }else {
                // Se delta == 0, allora s1==s2, allora ha solo una soluzione
                cout << "Ha 1 soluzione: " << " X = "  << s1 << endl;
            }

        }else{
            // Caso delta negativo, soluzioni non reali
            cout << "Errore delta negativo, non ci sono soluzioni reali" << endl;
        }
    }

    return 0;
}
