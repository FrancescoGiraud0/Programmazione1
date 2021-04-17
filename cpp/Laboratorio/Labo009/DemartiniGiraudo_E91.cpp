/*
Esercizio 9.1 C++
Gruppo: DemartiniGiraudo
Data: 15/04/2021
*/

#include <iostream>

using namespace std;

int main(){

  double A = 8.0, B = 4.0;
  double *P = NULL; // puntatore inizializzato a null (nessuna zona di memoria)

  // faccio in modo che P punti alla locazione di memoria di A
  P = &A;

  // stampare l'indirizzo di A e il suo valore attraverso il puntatore A
  cout << "Indirizzo di A: " << P <<endl;
  cout << "Valore di A: " << *P <<endl;

  B = *P;           // assegno a B il valore puntato da P
  *P = 5.0;         // assegno alla casella di memoria puntato da P il valore 5.0

  // stampare il contentuto di A e di B
  cout << "A = " << A << "\tB = " << B <<endl;

  double V[5]={0.0, 1.0, 2.0, 3.0, 4.0};
  P = &V[0];

  // stampare l'indirizzo di V[0] attraverso P
  cout << "Indirizzo del primo elemento di V: " << P <<endl;

  P = V;
  // stampare l'indirizzo di V[0] attraverso p
  cout << "Indirizzo del primo elemento di V (caso 2): " << P <<endl;

  // stampare la seconda componente dell'array V (cioe' V[1])  utilizzando il puntatore p
  cout << "Secondo valore di V (V[1]): " << *(P+1) <<endl;

  cout << "tutte le componenti di V sono : " << endl;
  // stampare tutte le componenti dell'array V utilizzando il puntatore p
  for (int i=0; i<5; i++){
    cout << "V[" << i << "] -> " << *(P+i) <<endl;
  }


  // stampare l'indirizzo della componente n-esima e il suo contenuto, con n a scelta dell'utente,
  // provate a eseguire il programm sia con n corretto (cioe' compreso tra 1 e 5), che scorretto,
  // chiedetevi il perche' dei risultati ottenuti in questo secondo caso
  int n;

  cout << "Inserire numero cella da visualizzare: ";
  cin >> n;

  if ((!cin)||(n<0)){
    cout << "Errore: Inserito un numero non intero positivo " <<endl;
    return 0;
  }

  P = V;
  cout << "V[" << n << "] -> " << *(P+n) <<endl;
  cout << "Indirizzo di V[" << n << "] -> " << (P+n) <<endl;
  return 0;
}
