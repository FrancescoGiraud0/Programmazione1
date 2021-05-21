/*
Esercizio 11.1 C++
Gruppo: DemartiniGiraudo
Data: 22/04/2021

Completare il programma C++ contenuto nel file base.cpp;
 dovrete definire il corpo di diverse  funzioni e scrivere
 un main per testarle, cioè farle applicare a valori diversi
 scelti in modo da rilevare eventuali errori (gli effetti
 delle varie chiamate saranno visualizzati attraverso
 opportune stampe sullo standard output). 

Suggerimento: per testare le varie funzioni usate dei valori
costanti scritti nel testo del programma invece di chiedere
dei valori da inserire attraverso lo standard input (è un
suggerimento amichevole). Per esempio per testare una funzione
fun con parametri per valore che ritorna un valore

// test di fun

cout<< "fun(v1, ..., vn) = [risultato atteso V ] " << 
fun(v1,...,vn) << endl;
*/

#include <iostream>
#include <cstdlib>

using namespace std;

// Esempio di funzione senza valore ritorno
void ScriviMessaggio(){
  //scrive sullo standard output la stringa "La mia prima funzione void"
  cout << "La mia prima funzione void" << endl;
}


//Esempio di funzione con valore di ritorno
double AreaQuadrato(double lato_quadrato){
  // ritorna l'area del quadrato avente lato lato_quadrato
  return lato_quadrato*lato_quadrato;
}

//Esempio di funzione con valore di ritorno e passaggio per riferimento 
double AreaPerimetroRett1(double base, double altezza, double &perimetro){
// ritorna direttamente l'area del rettangolo caratterizzato
// da base e altezza,
// mentre il perimetro del medesimo e' ritornato attraverso
// il parametro per riferimento perimetro
perimetro = (base*2)+(altezza*2);
return base*altezza;

}

//Esempio di funzione senza valore di ritorno e passaggio per riferimento 
void AreaPerimetroRett2(double base, double altezza, double &area, double &perimetro){
// ritorna l'area e il perimetro del rettangolo caratterizzato da base e altezza
// attraverso i parametri per riferimento area e perimetro
area = base*altezza;
perimetro = (base*2)+(altezza*2);
}

//Esempio di funzione con valore di ritorno, avente come parametri un array e la sua dimensione
double sommaVettore1(double *v, int dim){
// ritorna la somma degli elementi dell'arrary v avente dimensione dim
  int somma = 0;

  for(int i=0; i<dim; i++)
    somma += v[i];

  return somma;
}

//Esempio di funzione senza valore di ritorno, avente come parametri un array e la sua dimensione
void sommaVettore2(int * v, int dim, int &somma){
//ritorna attraverso il parametro di riferimento somma_vettore la somma degli elementi dell'arrary v avente dimensione dim
  somma = 0;

  for(int i=0; i<dim; i++)
    somma += v[i];

}

int main(){
	// test di ScriviMessaggio
	ScriviMessaggio();
	
	cout << endl;
	
	// test di AreaQuadrato
	cout << "AreaQuadrato(2) = [4] -> " << AreaQuadrato(2) << endl;
  cout << "AreaQuadrato(3) = [9] -> " << AreaQuadrato(3) << endl;
  cout << "AreaQuadrato(0) = [0] -> " << AreaQuadrato(0) << endl;
	 
	cout << endl;
	
	// test di  AreaPerimetroRett1
  double perimetro;
	cout << "AreaPerimetroRett1(1,1,perimetro) = [1, 4] -> " << AreaPerimetroRett1(1,1,perimetro);
  cout << " " << perimetro << endl;
	cout << "AreaPerimetroRett1(2,4,perimetro) = [8, 12] -> "  << AreaPerimetroRett1(2,4,perimetro);
  cout << " " << perimetro << endl;
	cout << "AreaPerimetroRett1(3,2,perimetro) = [6, 10] -> "  << AreaPerimetroRett1(3,2,perimetro);
  cout << " " << perimetro << endl;
	
	cout << endl;
	
	// test di AreaPerimetroRett2
  double area;

  AreaPerimetroRett2(1,1,area, perimetro);
	cout << "AreaPerimetroRett2(1,1,area,perimetro) = [1, 4] -> " << area << " " << perimetro << endl;
  AreaPerimetroRett2(2,4,area, perimetro);
	cout << "AreaPerimetroRett2(2,4,area,perimetro) = [8, 12] -> "  << area << " " << perimetro << endl;
  AreaPerimetroRett2(3,2,area, perimetro);
	cout << "AreaPerimetroRett2(3,2,area,perimetro) = [6, 10] -> "  << area << " " << perimetro << endl;
 
	cout << endl;
	
	// test di sommaVettore1
	double v1[5]  = {1,2,3,4,5};
  double v2[1]  = {0};
  double v3[10] = {1,1,1,1,1,1,1,1,1,-1};

  cout << "sommaVettore1(v1, 5)  = [15] -> " << sommaVettore1(v1, 5) << endl;
  cout << "sommaVettore1(v1, 3)  =  [6] -> " << sommaVettore1(v1, 3) << endl;
  cout << "sommaVettore1(v2, 1)  =  [0] -> " << sommaVettore1(v2, 1) << endl;
  cout << "sommaVettore1(v3, 10) =  [8] -> " << sommaVettore1(v3, 10) << endl;
	
	cout << endl;
	
	// test di sommaVettore2
  int somma = 0;
  int v4[5]  = {1,2,3,4,5};
  int v5[1]  = {0};
  int v6[10] = {1,1,1,1,1,1,1,1,1,-1};

  sommaVettore2(v4, 5, somma);
  cout << "sommaVettore2(v4, 5, somma)  = [15] -> " << somma << endl;
  sommaVettore2(v4, 3, somma);
  cout << "sommaVettore2(v4, 3 somma)   =  [6] -> " << somma << endl;
  sommaVettore2(v5, 1, somma);
  cout << "sommaVettore2(v5, 1, somma)  =  [0] -> " << somma << endl;
  sommaVettore2(v6, 10, somma);
  cout << "sommaVettore2(v6, 10, somma) =  [8] -> " << somma << endl;
	
	return 0;
}
