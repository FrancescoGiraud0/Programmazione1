/**
* Laboratorio 13.1 C++
* @author DemartiniGiraudo
* @file DemartiniGiraudo_E131.cpp
*
* Scrivere e testare una funzione che calcola i primi k
* elementi della successione di Fibonacci e li scrive
* sullo standard output; per fare ciò utilizzare 
* un'altra funzione ricorsiva che calcola l'ennesimo
* numero di Fibonacci.
* Attenzione dovete definire 2 (due) funzioni.
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void fibonacci(int k);
int n_fibonacci(int n);

int main(){
  cout << "FIBONACCI TEST" << endl;

  cout << "n_fibonacci(0)  [= 0]  = " << n_fibonacci(0) << endl;
  cout << "n_fibonacci(1)  [= 1]  = " << n_fibonacci(1) << endl;
  cout << "n_fibonacci(10) [= 55] = " << n_fibonacci(10) << endl;

  cout << "n_fibonacci(1) [0]: " << endl;
  fibonacci(1);
  cout << endl;
  cout << "n_fibonacci(2) [0 1]: " << endl;
  fibonacci(2);
  cout << endl;
  cout << "n_fibonacci(11)[0 1 1 2 3 5 8 13 21 34 55]: " << endl;
  fibonacci(11);
  cout << endl;

  return 0;
}

/**
  * Stampa i primi k numeri della serie di Fibonacci in modo ricorsivo.
  *
  * @param[in] k intero positivo maggiore di 0
  */
void fibonacci(int k){
  if(k<=0){
    cout << "Errore: valore k non positivo" << endl;
    exit(1);
  }

  // Se k non e' 1, stampa i k-1 valori precedenti
  if(k>1)
    fibonacci(k-1);
  
  // Una volta stampati i k-1 valori precedenti, stampa il k-esimo valore
  cout << n_fibonacci(k-1) << "\t" ;
}

/**
  * Restituisce l'n-esimo valore della successione di Fibonacci
  *
  * @param[in] n valore intero >= 0
  * @return [int] n-esimo valore della serie
  */
int n_fibonacci(int n){
  if(n<0){
    cout << "Errore: impossibile calcolare n-esimo valore di n negativo" << endl;
    exit(1);
  }

  // Se n e' 0 oppure 1, allora restituisci n
  // F(0) = 0, F(1) = 1
  if(n<=1)
    return n;
  
  // Se invece e' maggiore di 1, allora restituisci la somma dei precedenti
  return n_fibonacci(n-2) + n_fibonacci(n-1);
}