/**
* Esercitazione 14.1 C++
* @file DemartiniGiraudo_E14_1.cpp
* @author DemartiniGiraudo
* un main che utilizza il tipo Frazione e le funzioni definite per
* leggere delle frazioni da un file chiamato esattamente ENTRATA che
* contiene:
*   1. un numero naturale maggiore di 1, sia esso N.
*   2. N coppie di interi, da intendere come numeratore e denominatore
*      di una frazione.
* Ordinare le frazioni lette in ordine crescente e stamparle ordinate.
*/

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

struct Frazione{
  int n, d;
};

void assegnaF(Frazione &f, int numer, int denom);
float valoreF(Frazione f);
bool ugualeF(Frazione f1, Frazione f2);
bool maggioreF(Frazione f1, Frazione f2);
void BubbleSort(Frazione *f, int N);
void stampaF(Frazione f);

int main(){
  // array dinamico contenente le frazioni lette da file
  Frazione *f;
  // numero di frazioni da leggere
  int N;
  // numeratore e denominatore
  int n, d;
  // file di input con nome "ENTRATA"
  ifstream leggi("ENTRATA");

  if(!leggi){
    cout << "Errore: errore lettura file ENTRATA" << endl;
    exit(1);
  }

  leggi>>N;

  if(!leggi || N<=1){
    cout << "Errore: primo valore non valido" << endl;
    exit(1);
  }

  // Alloca vettore con N frazioni
  f = new Frazione[N];

  cout << "Lettura dei valori da file..." << endl;

  // Lettura da file e salva nella i-esima cella del vettore
  for(int i=0; i<N; i++){
    leggi >> n >> d;

    // In caso di errore lettura da file
    if(!leggi){
      cout << "Errore: errore lettura riga "<< i+2 << endl;
      delete [] f;
      exit(1);
    }

    assegnaF(f[i], n, d);
  }

  leggi.close();

  cout << "Ordinando i valori letti..." << endl;

  // Applica ordinamento
  BubbleSort(f, N);

  cout << "Valori ordinati: " << endl;

  // Stampa frazioni in ordine crescente
  for(int i=0; i<N; i++){
    stampaF(f[i]); cout << endl;
  }
  
  delete [] f;

  return 0;
}

/**
  * Procedura che stampa la frazione.
  *
  * @param[in] Frazione f
  */
void stampaF(Frazione f){
  cout << f.n << "/" << f.d;
}

/**
* Inizializza la frazione ponendo come numeratore e denominatore quelli dati
* in argomento, il denominatore non deve essere zero.
* Gestisce anche il segno della frazione, se denominatore negativo, moltplica
* per -1 numeratore e denominatore (utile per confronto tra frazioni).
*
* @param[in] Frazione f
* @param[in] int numer numeratore
* @param[in] int denom denominatore della frazione (!= 0)
*/
void assegnaF(Frazione &f, int numer, int denom){
  if(denom==0){
    cout << "Errore: denominatore uguale a zero" << endl;
    exit(1);
  }

  f.n = numer;
  f.d = denom;

  if(f.d<0){
    f.n = -f.n;
    f.d = -f.d;
  }
}

/**
  * Ritorna il valore reale della frazione dividendo numeratore per
  * denominatore.
  *
  * @param[in] Frazione f
  * @return float
  */
float valoreF(Frazione f){ 
  return f.n / (float)f.d;  
}

/**
  * Controlla se f1 e f2 rappresentano lo stesso numero razionale.
  * Quindi per confronto moltiplichiamo il denominatore di f1 per il
  * numeratore di f2 e viceversa, poi confrontiamo se sono uguali.
  *
  * @param[in] Frazione f1 prima frazione
  * @param[in] Frazione f2 seconda frazione
  * @return [bool] true se sono uguali, se no false
  */
bool ugualeF(Frazione f1, Frazione f2){
  if(f1.n*f2.d == f2.n*f1.d)
    return true;
  
  return false;
}

/**
  * Controlla se il valore della frazione f1 e' strettamente maggiore
  * di quello di f2 .
  *
  * @param[in] Frazione f1 prima frazione
  * @param[in] Frazione f2 seconda frazione
  * @return [bool] true se f1>f2, se no false
  */
bool maggioreF(Frazione f1, Frazione f2){
  if(f1.n*f2.d > f2.n*f1.d)
    return true;
  
  return false;
}

/**
  * Dato un vettore di frazioni passato per riferimento, e la sua
  * dimensione, ordina il vettore in modo decrescente.
  *
  * @param[in] Frazione *f array di frazioni
  * @param[in] int N dimensione array
  */
void BubbleSort(Frazione *f, int N){
  Frazione tmp;
  
  for (int j=N-1; j>0; j--){
    for (int i=0; i<j; i++){
      if( maggioreF(f[i], f[i+1]) ){
        assegnaF(tmp, f[i].n, f[i].d); //tmp = f[i];
        assegnaF(f[i], f[i+1].n, f[i+1].d ); //f[i] = f[i+1];
        assegnaF(f[i+1], tmp.n, tmp.d ); //f[i+1] = tmp;
      }
    }
  }  
 }
