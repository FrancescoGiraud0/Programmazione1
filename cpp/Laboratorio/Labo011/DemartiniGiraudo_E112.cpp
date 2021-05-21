 /**
  *Esercizio 11.2 C++
  *@author DemartiniGiraudo
  *@file DemartiniGiraudo_E112.cpp
  *
  *Si vuole calcolare la media e lo scarto quadratico medio di una
  *serie di dati, in questo caso utilizzare la formula per lo scarto
  *quadratico medio che usa la media aritmetica.
  *
  *Scrivere un programma C++ che:
  *
  *1.legga dal file di nome dati.dat prima di tutto un intero 
  *(maggiore di 1), sia N,  e poi N dati (reali, positivi e negativi) 
  *e li inserisca in un vettore (gestire la lettura in modo che il 
  *programma possa funzionare qualunque sia N); 
  *2. calcoli la media aritmetica e lo scarto quadratico medio dei 
  *dati contenuti nel file attraverso due distinte funzioni con i 
  *seguenti prototipi:
  *
  *double CalcoloMedia(double* dati, int dim) 
  *che calcola la media dei valori contenuti nell'array dati avente 
  *dimensione dim 
  *
  *double CalcoloScarto(double* dati, int dim) 
  *che calcola lo scarto quadratico medio dei valori contenuti 
  *nell'array dati avente dimensione dim 
  *
  *Si richiede che la funzione CalcoloScarto utilizzi la funzione 
  *CalcoloMedia, cioè la dovrà chiamare almeno una volta dentro il 
  *suo corpo.
  *
  *Suggerimento: per testare questo programma utilizzare un file di 
  *nome dati.dat  contenente dei dati di cui conoscete il valore 
  *della media e dello scarto quadratico), e poi provatelo su questo 
  *particolare file dati.dat che contiene 225 dati. 
  */

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib> // Per exit(1)

using namespace std;

double CalcoloMedia(double* dati, int dim);
double CalcoloScarto(double* dati, int dim);

int main(){
    const string nomefile = "dati.dat";
    ifstream leggi;
    double *dati = NULL;
    int dim;

    cout << "MEDIA E SCARTO QUADRATICO MEDIO DI "<< nomefile << endl;

    leggi.open(nomefile.c_str());

    if(!leggi){
      cout << "Errore: impossibile aprire il file" << endl;
      return 0;
    }

    // Legge numero di dati nel file dati.dat
    leggi >> dim;

    // Controllo dim intero positivo
    if((!leggi) || (dim<=0)){
      cout << "Errore: valore dim non valido" << endl;
      leggi.close();
      return 0;
    }

    // Alloca array dati con dimensione dim
    dati = new double[dim];

    // Legge valori da file e carica in array dati
    for(int i=0; i<dim; i++){
      if(!(leggi >> dati[i])){
        cout << "Errore: errore lettura elemento " << i+1 << endl;
        leggi.close();
        delete [] dati;
        return 0;
      }
    }

    leggi.close();

    // Stampa valore della media e dello scarto quadratico medio
    cout << "Media: " << CalcoloMedia(dati, dim) << endl;
    cout << "Scarto Quadratico Medio: " << CalcoloScarto(dati, dim) << endl;

    delete [] dati;

    return 0;
}

/**
 * Calcola la la media dei valori contenuti nell'array dati avente 
 * dimensione dim
 *
 * @return media di dati
 *
 * @param[in] dati un array di valori double
 * @param[in] dim la dimensione dell'array dati
 */
double CalcoloMedia(double *dati, int dim){
    double somma = 0;

    if(dim<=0){
      cout << "\nErrore: divisione per 0\n";
      exit(1);
    }
    
    // somma
    for(int i=0; i<dim; i++)
        somma += dati[i];
    
    return somma/dim;
}

/**
 * Calcola lo scarto quadratico medio dei valori contenuti 
 * nell'array dati avente dimensione dim
 *
 * @return scarto quadratico medio di dati
 *
 * @param[in] dati un array di valori double
 * @param[in] dim la dimensione dell'array dati
 */
double CalcoloScarto(double* dati, int dim){
    double sommaquadrati = 0;
    double media = CalcoloMedia(dati, dim);

    for(int i=0; i<dim; i++){
      sommaquadrati += pow( dati[i]-media, 2);
    }

    // Sotto radice numeratore sicuramente positivo e denominatore
    // sicuramente diverso da 0 perche' fatto controllo in CalcolaMedia()
    return sqrt(sommaquadrati/dim);
}