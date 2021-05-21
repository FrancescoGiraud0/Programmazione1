/**
  * Laboratorio 12 C++
  *
  * Sviluppare due funzioni C++ per automatizzare la conversione tra
  * rappresentazione decimale e romana dei numeri.  Una funzione
  * dovrà convertire una stringa ben formata che rappresenta un
  * numero romano nel corrispondente numero decimale, ed una
  * seconda un numero intero compreso tra 1 e 3999 nel 
  * corrispondente numero romano.
  * 
  * FILE DI INPUT
  * Devono essere formattati con una valore per riga.
  */

#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib> // per exit(1)

using namespace std;

/**
 * Funzione che restituisce una stringa con il numero romano
 * dato un intero decimale in inpute.
 * 
 * @param[in] decimale numero intero in base decimale
 * @return [string] numero romano, se numero compreso in [1,3999]
 */
string romano(int decimale);

/**
 * Dato un numero romano in input restituisce il 
 * corrispondente numero decimale, se esso e' un numero 
 * romano ben formato. 
 * Altrimenti segnala errore e termina.
 *
 * @param[in] romano una stringa con il numero romano tutto maiuscolo
 * @return [int] numero romano convertito in intero
 */
int decimale(string romano);

int main(){
  string r;
  int dec;
  ifstream leggi;
  ofstream scrivi;

  cout << "Test su DECIMALI..." << endl;

  // Test su DECIMALI
  leggi.open( "test/DECIMALI");

  if((!leggi)){
    cout << "Errore: file inesistente" << endl;
    return 0;
  }

  scrivi.open( "test/OUTDECIMALI");

  // Stampa valori convertiti su file
  while(leggi>>dec){
    r = romano(dec);
    scrivi << r << endl;
    cout << dec << " = " << r << endl;
  }

  leggi.close();
  scrivi.close();

  cout << "\nTest su ROMANI..." << endl;

  // Test su ROMANI
  leggi.open( "test/ROMANI");

  if((!leggi)){
    cout << "Errore: file inesistente" << endl;
    return 0;
  }

  scrivi.open( "test/OUTROMANI");

  while(leggi>>r){
    cout << r << " = ";
    dec = decimale(r);

    scrivi << dec << endl;
    cout << dec << endl;
  }

  leggi.close();
  scrivi.close();

  return 0;
}

int decimale(string romano){
  int decimale = 0;
  // cnt: contatore per valori successivi, serve per trovare valori
  // non validi tipo "MMMM" oppure "VV"
  // cifra_max: salviamo il valore della cifra letta fino a quel momento
  int cnt, cifra_max;
  // Array dinamico per conversione di ogni cifra romana in decimale
  int* cifre;
  // Lunghezza stringa romano
  int dim = romano.length();
  // Stringa contenente i caratteri che rappresentano i valori 1*10^i con i in {1,10,100,1000}
  const string str_1x = "MCXI";
  // Stringa contenente i caratteri che rappresentano i valori 5*10^i con i in {1,10,100}
  const string str_5x = "DLV";

  // Alloca cifre (lungo quanto stringa romano)
  cifre = new int[dim];

  // Crea un array con il valore decimale rappresentato da ogni carattere nella stringa
  // del numero romano (se non e' una cifra romana lo segnala)
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
        exit(1);
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

      // Se la cifra i-esima ha minore valore di quello massimo letto fino a questo momento
      // e il contatore e' maggiore di 1 (ovvero la lettera compare piu' volte ed e' prima 
      // di una con valore maggiore)
      if((cifre[i]<cifra_max)&&cnt>1){
        cout << "Errore: " << romano[i] << " non puo' comparire piu' di 1 volta prima di "<< romano[i+1] << endl;
        delete [] cifre;
        exit(1);
      }

      // Se romano[i] e' I,X,C o M e compare piu' di 3 volte
      // La funzione (int)str_1x.find(romano[i]) restituisce la posizione della prima
      // occorrenza, ovvero la prima posizione nella stringa, della
      // lettera i-esima di romano nella stringa str_1x.
      // Restituisce -1 (con casting ad intero (int)) se non trova niente nella stringa.
      if( ((int)str_1x.find(romano[i])>-1) && cnt>3){
        cout << "Errore: " << romano[i] << " non puo' comparire piu' di 3 volte" << endl;
        delete [] cifre;
        exit(1);
      }

      // Se romano[i] e' V,L o D e compare piu' di 1 volta
      // In questo caso cerchiamo la lettera i-esima nella stringa str_5x
      if(((int)str_5x.find(romano[i])>-1) && cnt>1){
        cout << "Errore: " << romano[i] << " non puo' comparire piu' di 1 volta" << endl;
        delete [] cifre;
        exit(1);
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
        exit(1);
      }

      // Abbiamo una lettera con valore minore di quella a destra, quindi
      // controlla che I prima di V o X oppure X prima di L o C oppure C prima di D o M
      // Se cosi' non fosse segnala errore e termina.
      if( !((cifre[i+1]/cifre[i]==5) || (cifre[i+1]/cifre[i]==10)) ){
        cout << "Errore: " << romano[i] << " non puo' stare prima di " << romano[i+1] << endl;
        delete [] cifre;
        exit(1);
      }

      // Se ha passato tutti i controlli cambia segno al valore della cifra i-esima
      // perche' sottrae alla cifra alla sua destra
      cifre[i] *= -1;
    }

    // Se carattere maggiore del valore della cifra maggiore letta fino a ora
    // allora resetta contatore e assegna attuale a cifra_max
    if(cifre[i]>cifra_max){
      // Carattere diverso da quello precedente quindi resetta contatore
      cnt = 1;
      cifra_max = cifre[i];
    }

    // Aggiunge (o sottrae) la cifra dopo i controlli
    decimale += cifre[i];
  }

  delete [] cifre;
  return decimale;
}

string romano(int decimale){
  string migliaia, centinaia, decine, unita;

  // decimale e' negativo
  if(decimale<1){
    cout << "Errore: non esiste questo numero per i romani" << endl;
    exit(1);
  }

  // decimale e' maggiore di 3999
  if(decimale>3999){
    cout << "Errore: algoritmo non riesce a convertire numeri >3999" << endl;
    exit(1);
  }

  // Per tutte le migliaia in decimale, abbiamo gia' controllato che decimale<4000
  for(int i=1;i<=(decimale/1000);i++){
    migliaia.insert(0, "M");
  }

  // Consideriamo il resto della divisione per 1000
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

  // Restituisci le stringhe concatenate
  return migliaia+centinaia+decine+unita;
}