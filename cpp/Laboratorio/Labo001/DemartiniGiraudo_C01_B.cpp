/* Esercitazione 1B C++
   Data: 11/03/2021
   Gruppo: DemartiniGiraudo
   
   Approssimiamo la terra come una sfera di diametro = 12756.274 kilometri.
   Inizializzare una variabile contenente il diametro della terra usando la
   notazione scientifica.
   Calcolare il volume e la superficie della terra e stamparli.
   Tutte le grandezze devono essere espresse in metri (lineari, quadrati o 
   cubi secondo il caso).
*/

#include <iostream>
#include <cmath> // Libreria per funzioni e costanti matematiche

using namespace std;

// Dichiaro come costante il diametro della terra (metri) in notazioni scientifica
const double DIAMETRO_TERRA= 1.2756274e+7;
//#define DIAMTERRA 1.2756274e+7 //altro modo per dichiarare le costanti
 
int main(){
    double volume, superficie;

    // Calcolo del volume della terra, usando la formula V = (4/3)*pi*r^3
    volume = (4/3)*M_PI*pow(DIAMETRO_TERRA/2, 3); // N.B. volume calcolato in m cubi!

    // Calcolo della superficie della terra con formula S=4*pi*r^2
    superficie = 4*M_PI*pow(DIAMETRO_TERRA/2, 2); // N.B. superficie in m quadrati!

    // Output del volume della Terra in notazione scientifica
    cout << "Volume della Terra:     " << volume     << " metri quadrati" << "\n";
    // Output della superficie della Terra in notazione scientifica
    cout << "Superficie della Terra: " << superficie << " metri cubi"     << "\n";

    return 0;
}