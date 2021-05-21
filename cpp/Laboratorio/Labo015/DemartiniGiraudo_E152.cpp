/**
  * Esercizio 15.2 C++
  * @author DemartiniGiraudo
  * @file DemartiniGiraudo_E152.cpp
  * 
  * Dopo aver letto attentamente la traccia implementare con il  C++ il calcolo
  * dell'integrale sia con il metodo dei trapezi sia con il metodo di Simpson.
  */

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

// PROTOTIPI FUNZIONI IMPLEMENTATE

long double areaTrapezio(double l1,double l2,double h);
long double IntegraleTrapezi(double a,double b,int n);
long double IntegraleTrapezi(double a, double b , double prec);

long double IntegraleSimpson(double a, double b , int n);
long double IntegraleSimpson(double a, double b , double prec); 

long double gaussiana(double m, double sigma, double x);
long double f(double x);

int main(){
  cout << "Integrale in [-1, 1]: " << endl;
  cout << "Metodo Trapezi:\t" << IntegraleTrapezi(-1, 1, 1e-4) << endl;
  cout << "Metodo Simpson:\t" << IntegraleSimpson(-1, 1, 1e-4) << endl;

  cout << "\nIntegrale in [-2, 2]: " << endl;
  cout << "Metodo Trapezi:\t" << IntegraleTrapezi(-2, 2, 1e-4) << endl;
  cout << "Metodo Simpson:\t" << IntegraleSimpson(-2, 2, 1e-4) << endl;

  cout << "\nIntegrale in [-3, 3]: " << endl;
  cout << "Metodo Trapezi:\t" << IntegraleTrapezi(-3, 3, 1e-4) << endl;
  cout << "Metodo Simpson:\t" << IntegraleSimpson(-3, 3, 1e-4) << endl;

  return 0;
}

/**
 * Funzione che calcola area di un trapezio dati i lati e l'altezza.
 * 
 * @param[in] double l1 : lato 1
 * @param[in] double l2 : lato 2
 * @param[in] double  h : altezza
 * @return area (long double)
 */
long double areaTrapezio(double l1,double l2,double h){
	return (l1+l2)*h*0.5;
}

/**
 * Funzione che calcola l'integrale definito tra a e b di f con metodo dei
 * trapezi, quindi calcolando la somma delle are e di n intervalli.
 * 
 * @param[in] double a : punto inizio
 * @param[in] double b : punto fine
 * @param[in] int n : numero intervalli
 * @return integrale definito (long double)
 */
long double IntegraleTrapezi(double a,double b,int n){
	long double area = 0;
    // Calcola valore di un intervallino prendendo la lunghezza del
    // segmento ab è dividendo in n parti.
	long double step = 0;

    if(n<=0){
        cout << "Errore: n deve essere strettamente positivo" << endl;
        exit(1);
    }

    step = (b-a)/n;

	while(a<b){
        // Somma l'area del trapezio dell'intervallino
		area += areaTrapezio(f(a),f(a+step), step);
        // Vai all'intervallino successivo
		a += step;
	}

    // Restituisci la sommatoria delle aree degli intervallini
    return area;
}

/**
 * Funzione che calcola l'integrale definito tra a e b di f con metodo dei
 * trapezi con una precisione data in input.
 * 
 * @param[in] double a : punto inizio
 * @param[in] double b : punto fine
 * @param[in] double prec : precisione
 * @return integrale definito (long double)
 */
long double IntegraleTrapezi(double a, double b, double prec){
    // Valore attuale e precedente dell'integrale
    double i_att = 0, i_prec = IntegraleTrapezi(a,b,1);

    // Incrementa ogni volta di uno il numero di intervalli
    for(int n=2 ; ; n++){
        // Calcola valore integrale con n intervallini
        i_att = IntegraleTrapezi(a,b,n);

        // Se la differenza in valore assoluto con il precedente è minore della precisione
        if(abs(i_att-i_prec)<prec)
            // Restituisci il valore attuale
            return i_att;

        // Altrimenti salva il valore precedente con l'attuale e ripeti con n maggiore
        i_prec = i_att;
    }
}

/**
 * Funzione che calcola l'integrale definito tra a e b di f con metodo di
 * Simpson dati n intervalli in input.
 * 
 * @param[in] double a : punto inizio
 * @param[in] double b : punto fine
 * @param[in] int n : numero intervalli
 * @return integrale definito (long double)
 */
long double IntegraleSimpson(double a,double b,int n){
    long double area = 0;
    // Calcola valore di un intervallino prendendo la lunghezza del
    // segmento ab è dividendo in n parti.
	long double step = 0;

    if(n<=0){
        cout << "Errore: n deve essere strettamente positivo" << endl;
        exit(1);
    }

    step = (b-a)/n;

	while(a<b){
        // Calcola area parabola interpolata nell'intervallino
		area += (step/6)*( f(a)+ f(a+step) + 4*f(0.5*(2*a+step)) );
		a += step;
	}

    // Restituisci la sommatoria delle aree degli intervallini
    return area;
}

/**
 * Funzione che calcola l'integrale definito tra a e b di f con metodo di
 * Simpson con una precisione data in input.
 * 
 * @param[in] double a : punto inizio
 * @param[in] double b : punto fine
 * @param[in] double prec : precisione
 * @return integrale definito (long double)
 */
long double IntegraleSimpson(double a,double b, double prec){
    double i_prec = IntegraleSimpson(a,b,1), i_att = 0;

    // Incrementa ogni volta di uno il numero di intervalli
    for(int n=2 ; ; n++){
        // Calcola valore integrale con n intervallini
        i_att = IntegraleSimpson(a,b,n);

        // Se la differenza in valore assoluto con il precedente è minore della precisione
        if(abs(i_att-i_prec)<prec)
            // Restituisci il valore appena calcolato
            return i_att;

        // Altrimenti salva il valore precedente con l'attuale e ripeti con n maggiore
        i_prec = i_att;
    }
}

/**
 * Funzione gaussiana.
 * 
 * @param[in] double m
 * @param[in] double sigma
 * @param[in] double x
 * @return valore della funzione nel punto x (long double)
 */
long double gaussiana(double m, double sigma, double x){
  return (1.0/(sigma*sqrt(2*M_PI))) * exp(-0.5*pow((x-m)/sigma,2));
}

/**
 * Richiama la funzione Gaussiana con parametri m=0 e sigma=1
 */ 
long double f(double x){
  return gaussiana(0, 1, x);
}