/**
* Laboratorio 13.2 C++
* @author DemartiniGiraudo
* @file DemartiniGiraudo_E132.cpp
*
* Scrivere e testare una funzione che  controlla se una stringa è
* palindroma; per esempio   "ama"   è palindroma, mentre "casa"
* non lo è. 

* Suggerimento: usate la funzione erase sulle stringhe, introdotta
* per l'esercizio svolto 4.
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/**
  * Funzione che restituisce true se la stringa in input e' palindroma.
  * Altrimenti ritorna false
  *
  * @param[in] s stringa qualsiasi
  * @return [bool] true se palindroma, false se non e' palindroma
  */
bool isPalindroma(string s){
  // Trova carattere centrale stringa
  int centro = s.length() / 2;
  string meta_sx, meta_dx;

  // Prendi da carattere 0 a carattere centro non compreso
  meta_sx = s.substr(0, centro);

  if(s.length()%2==0)
    // Elimina da carattere 0 a centro non compreso
    meta_dx = s.erase(0, centro);
  else
    // Elimina da carattere 0 a centro compreso
    meta_dx = s.erase(0, centro+1);

  // Nota: se stringa costituita da una lettera, allora meta_dx e meta_sx
  // sono vuote, quindi non entra nel for e ritorna true
  for(unsigned int i=0; i<meta_sx.length(); i++)
    // Se caratteri diversi, non palindroma allora ritorna false
    if( meta_sx[i]!=meta_dx[meta_dx.length()-i-1] )
      return false;

  // Se passa tutti i controlli e' palindroma
  return true;
}

int main(){
  cout << "isPalindroma(\"gatto\") [= false] -> " << ((isPalindroma("gatto")) ? "palindroma": "non palindroma")<< endl;
  cout << "isPalindroma(\"oro\") [= true] -> " << ((isPalindroma("oro")) ? "palindroma": "non palindroma") <<endl;
  cout << "isPalindroma(\"radar\") [= true] -> " << ((isPalindroma("radar")) ? "palindroma": "non palindroma")<< endl;
  cout << "isPalindroma(\"aa\") [= true] -> "<< ((isPalindroma("aa")) ? "palindroma": "non palindroma") << endl;
  cout << "isPalindroma(\"a\") [= true] -> " << ((isPalindroma("a")) ? "palindroma": "non palindroma")<< endl;
  cout << "isPalindroma(\"\") [= true] -> " << ((isPalindroma("")) ? "palindroma": "non palindroma")<< endl;
  cout << "isPalindroma(\"Hello World\") [= false] -> " << ((isPalindroma("Hello World")) ? "palindroma": "non palindroma")<< endl;
  cout << "isPalindroma(\"anna anna\") [= true] -> " << ((isPalindroma("anna anna")) ? "palindroma": "non palindroma") <<endl;
  cout << "isPalindroma(\"radar radar\") [= true] -> " << ((isPalindroma("radar radar")) ? "palindroma": "non palindroma") <<endl;
  
  return 0;
}