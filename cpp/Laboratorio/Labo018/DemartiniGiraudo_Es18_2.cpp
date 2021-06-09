/**
 * Esercizio 18.2 C++
 * @author DemartiniGiraudo
 * @file DemartiniGiraudo_Es18_2.cpp
 * 
 * Scrivere un programma C++ che:
 * - contenga la definizione completa della classe rettangolo accennata
 *   nel seguito (ovviamente tutti i metodi il cui prototipo si trova 
 *   nella parte pubblica devono essere definiti), ma ovviamente potete
 *   aggiungere ogni altro metodo che riteniate utile;
 * - testi i diversi metodi su diversi rettangoli creati nel testo del
 *   programma senza leggerli da file o da standard input; 
 * - quindi  legga i dati di una sequenza di rettangoli da un file il 
 *   cui nome deve essere chiesto all'utente e li inserisca in un vector
 *   di rettangoli (per testare il programma usate il file di nome 
 *   "rettangoli.txt"; dovrà anche segnalare eventuali dati inappropriati
 *   (i lati dei rettangoli devono essere numeri positivi) e subito dopo
 *   terminare il programma.
 * - infine scriva sullo standard output:
 *      - L'area e il perimetro di ogni rettangolo contenuto nel vettore
 *      - I lati del rettangolo con area minima (dopo aver usato min_element)
 *      - I lati del rettangolo con area massima (dopo aver usato max_element)
 *      - quanti rettangoli sono "quadrati".
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class rettangolo{
public:
    // costruttore, ritorna il rettangolo avete lati L1 e L2
    rettangolo(double L1,double L2){
        // Controllo che lati non siano negativi
        if(L1>=0 && L2>=0){
            this->l1 = L1;
            this->l2 = L2;
        }else{
            cout << "Errore: i lati non devono essere negativi" << endl;
            exit(1);
        }
    }
    
    // ritorna vero ses l’area del rettangolo a cui si applica il metodo e’
    // minore dell’area di R
    bool operator<(rettangolo R){
        // Confronto tra le aree
        return this->area() < R.area();
    }
    
    // scrive sulla stream STR il rettangolo R in questo modo R[l1,l2]
    friend ostream& operator<<(ostream& STR, rettangolo R){
        STR << "R[" << R.l1 << "," << R.l2 << "]";

        return STR;
    }

    // legge dalla stream STR i lati di un rettangolo, e assegna ad R il 
    // corrispondente oggetto dopo averlo creato
    friend istream& operator>>(istream& STR, rettangolo &R){
        double lato1, lato2;
        STR >> lato1 >> lato2;

        // Controllo che i lati non siano negativi
        if(lato1<0 || lato2<0){
            cout << "Errore: errore lettura rettangolo, lati non positivi" << endl;
            exit(1);
        }

        // Se lati >=0 allora istanzia rettangolo con lato1 e lato2
        R = rettangolo(lato1, lato2);

        return STR;
    }

    // ritorna il perimetro dell’oggetto a cui si applica il metodo
    double perimetro(){
        return 2*l1 + 2*l2;
    }

    // ritorna l’area dell’oggetto a cui si applica il metodo
    double area(){
        return l1*l2;
    }

    //restituisce vero se l’oggetto a cui si applica il metodo e’ un quadrato
    bool quadrato(){
        // Controlla che i due lati siano uguali e che non sia degenere (un punto)
        return l1==l2 && l1!=0 && l2!=0;
    }
    
    // ritorna vero ses l'oggetto a cui si applica è veramente un rettangolo,
    // cioè i suoi lati sono strettamente positivi
    bool ok(){
        // Controlla che non sia degenere (un punto)
        return l1>0 && l2>0;
    }

private:
    double l1,l2;// i lati del rettangolo
};

// Procedura per testare metodi della classe
void test_su_rettangoli(){
    rettangolo r1(1,1), r2(3,2), r3(0,0);

    cout << "Rettangolo 1: " << r1 << endl;
    cout << "Rettangolo 2: " << r2<< endl;
    cout << "Rettangolo 3: " << r3 << endl;

    // Aree
    cout << endl << "AREE: " << endl;
    cout << "Area rettangolo 1: " << r1.area() << endl;
    cout << "Area rettangolo 2: " << r2.area() << endl;
    cout << "Area rettangolo 3: " << r3.area() << endl;

    // Perimetri
    cout << endl << "PERIMETRO: " << endl; 
    cout << "Perimetro rettangolo 1: " << r1.perimetro() << endl;
    cout << "Perimetro rettangolo 2: " << r2.perimetro() << endl;
    cout << "Perimetro rettangolo 3: " << r3.perimetro() << endl;

    // E' un quadrato?
    cout << endl << "SONO DEI QUADRATI? " << endl; 
    cout << ( (r1.quadrato()) ? "Rettangolo 1 e' un quadrato" : "Rettangolo 1 NON e' un quadrato" ) << endl;
    cout << ( (r2.quadrato()) ? "Rettangolo 2 e' un quadrato" : "Rettangolo 2 NON e' un quadrato" ) << endl;
    cout << ( (r3.quadrato()) ? "Rettangolo 3 e' un quadrato" : "Rettangolo 3 NON e' un quadrato" ) << endl;

    // E' un rettangolo?
    cout << endl <<"SONO DEI RETTANGOLI? " << endl; 
    cout << ( (r1.ok()) ? "Rettangolo 1 e' un rettangolo" : "Rettangolo 1 NON e' un rettangolo" ) << endl;
    cout << ( (r2.ok()) ? "Rettangolo 2 e' un rettangolo" : "Rettangolo 2 NON e' un rettangolo" ) << endl;
    cout << ( (r3.ok()) ? "Rettangolo 3 e' un rettangolo" : "Rettangolo 3 NON e' un rettangolo" ) << endl;
    cout << endl;
}

// funzione che restituisce un vector di rettangoli letti da file
vector<rettangolo> leggirettangoli(string nome_file){
    vector<rettangolo> v;
    rettangolo r(0,0);
    ifstream leggi( nome_file.c_str() );

    if(!leggi){
        cout << "Errore: errore lettura file " << nome_file << endl;
        return v;
    }

    while(leggi.good()){
        // Leggi rettangolo e salva in r
        leggi >> r;

        // Se c'e' un errore in lettura e non siamo alla fine del file
        if(!leggi && !leggi.eof()){
            cout << "Errore: errore durante lettura file" << endl;
            leggi.close();
            exit(1);
        }

        if(leggi){
            v.push_back(r);
        }
        
    }

    // Chiudi il file una volta terminata la lettura
    leggi.close();

    return v;
}

int main(){
    vector<rettangolo> vector_rettangoli;
    vector<rettangolo>::iterator start;
    vector<rettangolo>::iterator end;
    int cnt;
    string nome_file;

    // Procedura per """test""" metodi della classe
    test_su_rettangoli();

    cout << "Inserire nome del file da leggere: ";
    cin >> nome_file;
    
    // leggi rettangoli da file
    vector_rettangoli = leggirettangoli(nome_file);

    cout << endl << "AREE e PERIMETRI RETTANGOLI LETTI: " << endl;
    for (unsigned int i=0; i<vector_rettangoli.size(); i++){
        cout << vector_rettangoli.at(i) << " -> A = " << vector_rettangoli.at(i).area();
        cout << " P = " << vector_rettangoli.at(i).perimetro() << endl;
    }
    
    // Assegna iteratori
    start = vector_rettangoli.begin();
    end = vector_rettangoli.end();

    cout << endl;
    cout << "Valore massimo -> " << *max_element(start, end) << endl;
    cout << "Valore minimo -> " << *min_element(start, end) << endl;

    cout << endl << "Quadrati letti: " << endl;
    cnt=0;
    for (unsigned int i=0; i<vector_rettangoli.size(); i++){
        if(vector_rettangoli.at(i).quadrato())
            cout << ++cnt << ". " << vector_rettangoli.at(i) << endl;
    }
    
    return 0;
}