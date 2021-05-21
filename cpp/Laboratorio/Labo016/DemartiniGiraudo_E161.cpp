/**
  * Esercizio 16.1 C++
  * @author DemartiniGiraudo
  * @file DemartiniGiraudo_E161.cpp
  *
  * Definire una classe per rappresentare gli articoli di un inventario.
  * Ciascun articolo comprende:
  *
  *  - nome dell'articolo (una stringa),
  *  - casa produttrice (una stringa),
  *  - numero di pezzi presenti in magazzino (un intero non negativo).
  *
  * Tale classe dovrà avere almeno questi metodi (per cui siete liberi di 
  * aggiungerne altri a piacere):
  *
  *   - un costruttore che prende come parametri il nome, il produttore e 
  *     il numero di pezzi,
  *   - un metodo per guardare quale è il numero di pezzi presenti di un 
  *     articolo.
  *   - due funzioni-amiche per leggere e scrivere indirizzi su /da una 
  *     stream che "sovraccaricano" >> e << rispettivamente,
  *     un articolo va scritto in questo modo:
  *  
  * Art.   	il nome   	il produttore   	(il numero di pezzi)
  *
  * Poi aggiungere un main che: 
  *  -chiede all'utente il nome di un file contenente esclusivamente degli 
  *   articoli  
  *   (non ci può essere all'inizio il numero di articoli contenuti nel file),
  *  -scrive sullo standard output prima tutti gli articoli letti e poi quanti
  *   articoli hanno numero di pezzi presenti inferiore a 5.
  * 
  * [NOTA]
  * FORMATO DEL FILE DA LEGGERE : 
  * - NO numero di elementi all'inizio
  * - Riga cosi' formata -> Art. nome produttore (no. pezzi)
  */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**
  * Classe Articolo con overloading di metodi costruttori.
  */
class Articolo {
  private:
    // Nome prodotto e produttore
    string nome, produttore;
    // Numero di pezzi (non può essere negativo)
    unsigned int n;
  public:
    // Costruttori di classe
    Articolo(){
      this->nome = "";
      this->produttore = "";
      this->n = 0;
    }

    Articolo(string nome, string produttore, unsigned int n){
      this->nome = nome;
      this->produttore = produttore;
      this->n = n;
    }

    Articolo(string nome, string prod){
      this->nome = nome;
      this->produttore = prod;
      this->n = 0;
    }

    // Restituisce il nome dell'articolo
    string getNome(){
      return this->nome;
    }

    // Restituisce il nome del produttore
    string getProduttore(){
      return this->produttore;
    }
    
    // Restituisce il numero di pezzi dell'articolo
    unsigned int getN(){
      return this->n;
    }

    // Modifica articolo
    void modificaArt(string nome, string prod, unsigned int n){
      this->nome = nome;
      this->produttore = prod;
      this->n = n;
    }

    // Metodo per modificare nome prodotto
    void setNome(string nome){
      this->nome = nome;
    }

    // Metodo per modificare nome produttore
    void setProd(string prod){
      this->produttore = prod;
    }

    // Metodo per modificare numero pezzi
    void setProd(unsigned int n){
      this->n = n;
    }

    friend ostream& operator<<(ostream& output, Articolo a);
    friend istream& operator>>(istream& input, Articolo &a);
};

// Overloading <<
ostream& operator<<(ostream& output, Articolo a){
  cout << "Art. " << a.getNome()<< " " << a.getProduttore() << " (" << a.getN() << ")";
  return output;
}

// Overloading >>
istream& operator>>(istream &input, Articolo &a){
  string nome, prod, art;
  char p1=0, p2=0;
  unsigned int n=0;

  input >> art >> nome >> prod >> p1 >> n >> p2;

  if(art.compare("Art.")==0 && p1=='(' && p2==')' )
    a.modificaArt(nome, prod, n);
  
  return input;
}

/**
  * Funzione che dati in input un articolo, un array dinamico di articoli per riferimento e
  * la dimensione dell'array, estende la dimensione dell'array e aggiunge in fondo l'articolo.
  */
void append(Articolo a, Articolo *&lista_art, unsigned int dim){
    // Array di appoggio
    Articolo *tmp = NULL;
    tmp = lista_art;
    
    // Crea array di Articoli con dimensione aumentata di 1
    lista_art = new Articolo[dim+1];

    // Copia gli elementi precedenti all'inizio della lista
    for(unsigned int i=0; i<dim; i++)
        lista_art[i] = tmp[i];
    
    // Aggiungi articolo in input in fondo
    lista_art[dim] = a;

    // Dealloca vecchio array
    delete [] tmp;
}

int main(){
    ifstream leggi;
    string nomefile;
    // Contatore di articoli letti da file
    unsigned int cntArt = 0;
    // Array dinamico per salvare articoli e array dinamico per scambio
    Articolo *lista_art = NULL;
    // Per salvare articolo letto da file prima di inserirlo nell'array
    Articolo art;

    cout << "Inserire nome del file da leggere con estensione: ";
    cin >> nomefile;
    leggi.open(nomefile.c_str());
    
    if(!leggi){
        cout << "Errore: errore nell'apertura del file " << nomefile << endl;
        return 0;
    }

    // Finche' e' possibile leggi articoli riga per riga e aggiungili alla lista
    while(leggi.good()){
      leggi >> art;

      // Aggiungi l'articolo in fondo all'array di articoli
      append(art, lista_art, cntArt);
      // Incrementa contatore articoli letti
      cntArt++;
    }

    leggi.close();
    
    // Nel ciclo while aggiunge un articolo in piu' all'ultimo ciclo
    cntArt--;

    // Elenco articoli letti da file
    cout << "\nElenco " << cntArt << " articoli letti: " << endl;
    for(unsigned int i=0; i<cntArt; i++)
        cout << i+1 << ". " << lista_art[i] << endl;

    cout << "\nElenco articoli con meno di 5 pezzi: " << endl;
    // Contatore per elenco puntato
    unsigned int k=1;
    for(unsigned int i=0; i<cntArt; i++){
        // Se il numero di pezzi di un articolo e' < 5, stampalo
        if(lista_art[i].getN() < 5)
            cout << k++ << ". " << lista_art[i] << endl;
    }

    delete [] lista_art;
    
    return 0;
}