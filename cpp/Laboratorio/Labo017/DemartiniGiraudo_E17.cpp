/**
 * Esercizio 17 C++
 * @author DemartiniGiraudo
 * @file DemartiniGiraudo_E17.cpp
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

/**
 * @class Punto 
 * Classe per salvare ed interagire con le coordinate x e y di un punto.
 */ 
class Punto{
    public:
        // Coordinate
        double x,y;

        // Metodo costruttore senza parametri
        Punto(){
            this->x = 0;
            this->y = 0;
        }

        // Metodo costruttore con coordinate
        Punto(double x, double y){
            this->x = x;
            this->y = y;
        }

        // Modifica le coordinate del punto
        void modifica(double x, double y){
            this->x = x;
            this->y = y;
        }

        // Copia coordinate del punto passato come parametro
        void modifica(Punto a){
            this->modifica(a.x, a.y);
        }

        // Overloading di ==
        bool operator==(Punto p){
            // Coordinate uguali se e solo se coordinate entrambi uguali
            return (x == p.x) && (y==p.y);
        }

        void shiftSinistra(double shift){
            x -= shift;
        }

        void shiftDestra(double shift){
            x += shift;
        }

        void shiftSotto(double shift){
            y -= shift;
        }

        void shiftSopra(double shift){
            y += shift;
        }

        // Prototipi funzioni amiche per overloading << e >>
        friend ostream &operator<<(ostream& output, Punto p);
        friend istream &operator>>(istream& input, Punto &p);

};

// Per output singolo punto
ostream &operator<<(ostream& output, Punto p){
    cout << "(" << p.x << "," << p.y << ")";
    return output;
}

// Per input singolo punto
istream &operator>>(istream& input, Punto &p){
    input >> p.x >> p.y;
    return input;
}

/**
 * @class Segmento
 * Classe per salvare ed interagire con un segmento determinato da due punti.
 */
class Segmento{
    public:
        Punto a, b;
        
        // Costruttore senza parametri
        Segmento(){}

        // Costruttore con estremi come parametri
        Segmento(Punto a, Punto b){
            this->a.modifica(a);
            this->b.modifica(b);
        }
        
        // Overloading ==
        bool operator==(Segmento s){
            return ((this->a == s.a) && (this->b == s.b)) || ((this->a == s.b) && (this->b == s.a));
        }

        // Lunghezza vettore (norma)
        double lung(){
            return sqrt( pow(a.x-b.x,2) + pow(a.y-b.y,2) );
        }

        // Primo estremo segmento
        Punto estA(){
            return a;
        }
        
        // Secondo estremo segmento
        Punto estB(){
            return b;
        }

        // Prototipi per overloadin << e >>
        friend ostream &operator<<(ostream& output, Segmento s);
        friend istream &operator>>(istream& input, Segmento &s);
};

// Overloading << (utilizza anche overloading << di Punto)
ostream &operator<<(ostream& output, Segmento s){
    cout << s.a << "---" << s.b;
    return output;
}

// Overloading >> (utilizza anche overloading >> di Punto)
istream &operator>>(istream& input, Segmento &s){
    input >> s.a >> s.b;
    return input;
}

// Funzione che restituisce la lunghezza media di una lista di N segmenti
double lungmedia(Segmento *l, unsigned int N){
    double somma_lung = 0;

    // Controllo che N!=0
    if(N==0){
        cout << "Errore: il numero di segmenti non può essere 0" << endl;
        exit(1);
    }
    
    // Sommatoria di tutte le lunghezze
    for(unsigned int i=0; i<N; i++)
        somma_lung += l[i].lung();

    return somma_lung/N;
}

int main(){
    // nome del file
    string filename;
    ifstream leggi;
    unsigned int N;
    // array dinamico di segmenti
    Segmento *l_segmenti = NULL;
    double lung_media = 0;

    cout << "Inserire nome del file da leggere con estensione: ";
    cin >> filename;
    leggi.open(filename.c_str());
    
    if(!leggi){
        cout << "Errore: errore nell'apertura del file " << filename << endl;
        return 0;
    }
    
    leggi >> N;

    if(!leggi|| N<1){
        cout << "Errore: numero di segmenti da leggere non valido" << endl;
        return 0;
    }
    
    // Alloca array di N segmenti
    l_segmenti = new Segmento[N];

    // Legge N segmenti da file e li aggiunge all'array
    for(unsigned int i=0; i<N; i++)
        leggi >> l_segmenti[i];

    leggi.close();

    // Calcolo lunghezza media con funzione (salva in variabile per confronti veloci successivis)
    lung_media = lungmedia(l_segmenti, N);
    cout << "\nLunghezza media dei segmenti: " << lung_media << "\n\n";

    // Stampare lista segmenti con lunghezza maggiore della media
    cout << "Segmenti con lunghezza maggiore della media: " << endl;
    for(unsigned int i=0; i<N; i++){
        // Stampa solo se lunghezza vettore e' maggiore della media
        if(l_segmenti[i].lung()>lung_media)
            cout << l_segmenti[i] << endl;
    }

    return 0;
}