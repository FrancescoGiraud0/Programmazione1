/**
* Laboratorio 13.3 C++
* @author DemartiniGiraudo
* @file DemartiniGiraudo_E131.cpp
*
* Completare i seguenti prototipi di funzioni,
* rimpiazzando i puntini anche con nulla, 
* assumendo che NUM sia una costante di tipo 
* intero definita usando il "define".
*/

#define NUM

bool positivo(double val[NUM]);
//ritorna vero ses un array di lunghezza NUM contiene solo reali positivi
void stampa(double val[NUM]);
// stampa un array di reali di lunghezza NUM sullo standard output
double modulo(double val[NUM]);
// applica il modulo agli elementi di un array di lunghezza NUM
void multiSomme(double val[NUM], double &somma, double &sommaquadrati, double &sommacubi);
// ritorna la somma degli elementi, la somma dei quadrati e dei cubi degli elementi di un array di reali di lunghezza NUM