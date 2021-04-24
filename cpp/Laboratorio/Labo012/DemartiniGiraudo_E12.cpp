/**
  *Laboratorio 12 C++
  *@author DemartiniGiraudo
  *@file DemartiniGiraudo_E12.cpp
  *
  * Sviluppare due funzioni C++ per automatizzare la conversione tra
  * rappresentazione decimale e romana dei numeri.  Una funzione
  * dovrà convertire una stringa ben formata che rappresenta un
  * numero romano nel corrispondente numero decimale, ed una
  * seconda un numero intero compreso tra 1 e 3999 nel 
  * corrispondente numero romano. 
  */

#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib> // per exit(1)

using namespace std;

/**
 * Dato un numero decimale intero in input restituisce 
 * il corrispondente numero romano.
 *
 * @return numero romano (string)
 *
 * @param[in] decimale un intero decimale positivo
 */
string romano(int decimale);

/**
 * Dato un numero romano in input restituisce il 
 * corrispondente numero decimale, se esso e' un numero 
 * romano ben formato.
 *
 * @return (int) numero romano convertito o -1
 *
 * @param[in] romano una stringa con il numero romano
 */
int decimale(string romano);

int main(){ 
  string r;
  int dec;
  ifstream leggi;
  ofstream scrivi;

  // Test su ROMANI
  leggi.open( "test/ROMANI");

  if((!leggi)){
    cout << "Errore: file inesistente" << endl;
    return 0;
  }

  scrivi.open( "out/OUTROMANI");

  if((!scrivi)){
    cout << "Errore: file inesistente" << endl;
    leggi.close();
    return 0;
  }

  while(leggi>>r){
    // Su cout scrive tutti i valori (compresi errori)
    cout << r << " = ";
    dec = decimale(r);

    // Mentre su file solo i convertiti
    if(dec != -1){
      scrivi << dec << endl;
      cout << dec << endl;
    }
    
  }

  leggi.close();
  scrivi.close();

  // Test su DECIMALI
  leggi.open( "test/DECIMALI");

  if((!leggi)){
    cout << "Errore: file inesistente" << endl;
    return 0;
  }

  scrivi.open( "out/OUTDECIMALI");

  if((!scrivi)){
    cout << "Errore: file inesistente" << endl;
    leggi.close();
    return 0;
  }

  // Stampa valori convertiti su file
  while(leggi>>dec){
    r = romano(dec);
    scrivi << r << endl;
  }

  leggi.close();
  scrivi.close();

  return 0;
}

/**
 * Funzione che restituisce il valore decimale del numero romano inserito
 * come stringa. Restituisce -1 se non e' un numero valido.
 * 
 * @param[in] romano stringa con numero romano tutta maiuscola
 * @return (int) numero decimale se stringa valida, altrimenti -1
 */
int decimale(string romano){
  int decimale = 0, cifra_max;
  // contatore per valori successivi, serve per trovare valori non validi
  int cnt;
  // array dinamico per conversione di ogni cifra romana in decimale
  int* cifre;
  // lunghezza stringa
  int dim = romano.length();
  // stringa contenente i caratteri che rappresentano i valori 1*10^i con i in {1,10,100,1000}
  const string str_1x = "MCXI";
  // stringa contenente i caratteri che rappresentano i valori 5*10^i con i in {1,10,100}
  const string str_5x = "DLV";

  // alloca cifre (lungo quanto stringa romano)
  cifre = new int[dim];

  // Crea un array con il valore decimale rappresentato da ogni
  // carattere nella stringa del numero romano
  // (se non e' una cifra romana lo segnala)
  for(int i=0; i<dim;i++){
    switch(romano[i]){
      case 'I':
        cifre[i] = 1;
        break;
      case 'V':
        cifre[i] = 5;
        break;
      case 'X':
        cifre[i] = 10;
        break;
      case 'L':
        cifre[i] = 50;
        break;
      case 'C':
        cifre[i] = 100;
        break;
      case 'D':
        cifre[i] = 500;
        break;
      case 'M':
        cifre[i] = 1000;
        break;
      default:
        cout << "Errore: cifra non romana, contiene carattere non associato a cifre" << endl;
        delete [] cifre;
        return -1;
    }
  }
  
  // Nessun controllo sull'ultima cifra, quindi somma valore a decimale
  cnt=1;
  decimale += cifre[dim-1];
  // All'inizio la cifra massima incontrata e' la prima letta
  cifra_max = cifre[dim-1];

  // Legge stringa ed array a partire dal penultimo carattere (da destra fino a sinistra)
  for(int i=dim-2; i>=0; i--){

    // Se la lettera i-esima e' identica a quella a destra
    if(romano[i]==romano[i+1]){
      // Incrementa contatore
      cnt++;

      if((cifre[i]<cifra_max)&&cnt>1){
        cout << "Errore: " << romano[i] << " non puo' comparire piu' di 1 volte prima di "<< romano[i+1] << endl;
        delete [] cifre;
        return -1;
      }

      // Se romano[i] e' I,X,C o M e compare piu' di 3 volte
      if( ((int)str_1x.find(romano[i])>-1) && cnt>3){
        cout << "Errore: " << romano[i] << " non puo' comparire piu' di 3 volte" << endl;
        delete [] cifre;
        return -1;
      }

      // Se romano[i] e' V,L o D e compare piu' di 1 volta
      if(((int)str_5x.find(romano[i])>-1) && cnt>1){
        cout << "Errore: " << romano[i] << " non puo' comparire piu' di 1 volta" << endl;
        delete [] cifre;
        return -1;
      }
    }

    // Se il carattere rappresenta un valore minore di quello a destra
    if(cifre[i]<cifre[i+1]){

      // Carattere diverso da quello precedente quindi resetta contatore
      cnt = 1;

      // Se romano[i] e' V,L o D ed e' a sinistra di un carattere maggiore
      if(((int)str_5x.find(romano[i])>-1)){
        cout << "Errore: " << romano[i] << " non puo' stare prima di " << romano[i+1] << endl;
        delete [] cifre;
        return -1;
      }

      // Controlla che I prima di V o X, X prima di L o C, C prima di D o M
      // Se siamo in altri casi
      if(!( (cifre[i+1]/cifre[i]==5) || (cifre[i+1]/cifre[i]==10) )){
        cout << "Errore: " << romano[i] << " non puo' stare prima di " << romano[i+1] << endl;
        delete [] cifre;
        return -1;
      }

      // Se ha passato tutti i controlli cambia segno al valore della cifra i-esima
      cifre[i] *= -1;
    }

    // Se carattere maggiore del valore della cifra maggiore letta fino a ora
    // allora resetta contatore e assegna attuale a cifra_max
    if(cifre[i]>cifra_max){
      cnt = 1;
      cifra_max = cifre[i];
    }

    decimale += cifre[i];
  }

  delete [] cifre;
  
  return decimale;
}

string romano(int decimale){
  string migliaia, centinaia, decine, unita;

  if(decimale<1){
    cout << "Errore: non esiste questo numero per i romani" << endl;
    exit(1);
  }

  if(decimale>3999){
    cout << "Errore: algoritmo non riesce a convertire numeri >3999" << endl;
    exit(1);
  }

  for(int i=1;i<=(decimale/1000);i++){
    migliaia.insert(0, "M");
  }

  decimale %= 1000;

  switch(decimale/100){
    case 0:
      break;
    case 3:
      centinaia.insert(0, "C");
    case 2:
      centinaia.insert(0, "C");
    case 1:
      centinaia.insert(0, "C");
      break;
    case 4:
      centinaia.insert(0, "CD");
      break;
    case 5:
      centinaia.insert(0, "D");
      break;
    case 6:
      centinaia.insert(0, "DC");
      break;
    case 7:
      centinaia.insert(0, "DCC");
      break;
    case 8:
      centinaia.insert(0, "DCCC");
      break;
    case 9:
      centinaia.insert(0, "CM");
      break;
  }

  decimale %= 100;

  switch(decimale/10){
    case 0:
      break;
    case 3:
      decine.insert(0, "X");
    case 2:
      decine.insert(0, "X");
    case 1:
      decine.insert(0, "X");
      break;
    case 4:
      decine.insert(0, "XL");
      break;
    case 5:
      decine.insert(0, "L");
      break;
    case 6:
      decine.insert(0, "LX");
      break;
    case 7:
      decine.insert(0, "LXX");
      break;
    case 8:
      decine.insert(0, "LXXX");
      break;
    case 9:
      decine.insert(0, "XC");
      break;
  }

  decimale %= 10;

  switch(decimale){
    case 0:
      break;
    case 3:
      unita.insert(0, "I");
    case 2:
      unita.insert(0, "I");
    case 1:
      unita.insert(0, "I");
      break;
    case 4:
      unita.insert(0, "IV");
      break;
    case 5:
      unita.insert(0, "V");
      break;
    case 6:
      unita.insert(0, "VI");
      break;
    case 7:
      unita.insert(0, "VII");
      break;
    case 8:
      unita.insert(0, "VIII");
      break;
    case 9:
      unita.insert(0, "IX");
      break;
  }

  return migliaia+centinaia+decine+unita;
}