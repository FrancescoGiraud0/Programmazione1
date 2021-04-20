/*
Esercizio 10.1 C++
Gruppo: DemartiniGiraudo
Data: 16/04/2021

Il file temperature.dat contiene le temperature rilevate
in una stazione meteorologica per alcuni giorni (più misure
al giorno). In particolare il primo valore corrisponde al 
numero di giorni (numero delle righe), il secondo valore 
corrisponde al numero di misure giornaliere (numero delle 
colonne). Seguono, poi, i valori della matrice (da inserire
per riga).

Scrivere un programma C++ che:

    legga dal file di nome temperature.dat il numero di righe
    e il numero di colonne della matrice,
    allochi dinamicamente la matrice
    legga i valori  della matrice stessa dallo stesso file
    stampi sullo standard output la matrice (andando a capo 
    ogni riga)
    calcoli e memorizzi in un vettore l'escursione termica di
    ogni giorno (differenza tra minima e massima temperatura)
    stampi in quali giorni si è verificata la massima escursione
    (attenzione possono essere più di uno).

Il risultato atteso è che la massima escursione termica 
si e' avuta nei giorni 2 6.

*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/* Funzione che restituisce l'escursione termica. 
   Date un vettore contente len misurazioni, trova massimo e minimo,
   se il vettore ha len>1, e ne restituisce la differenza */
int escursioneTermica(int riga[], int len) {
	int min, max;
	
	if(len == 1)
		return riga[0];
	else if(len == 0)
		return 0;
	
	max = riga[0];
    min = riga[0];

	for(int i = 1; i < len; i++){
        if(riga[i] > max)
			max = riga[i];

        if(riga[i] < min)
			min = riga[i];
    }
	
	return max - min;
}


int main(){
    // Input file stream per lettura file
    ifstream leggi;
    // Contatore righe con inizializzazione a 1
    unsigned int cont_riga;
    // Dichiarazione di matrice allocata dinamicamente
    int **temperature = NULL;
    // Vettore con escursioni termiche di ogni giorno
    int *escursioni = NULL;
    // Vettore con i giorni con la massima escursione
    int *giorni_max_escursione = NULL;
    // Array per lo scambio in caso di piu' giorni con escursione massima
    int *array_scambio = NULL;
    // numero righe e colonne, massima escursione termica inizializzata a -1
    // e contatore di giorni con massima escursione termica
    int righe, colonne, max_esc=-1, cont_max=0;

    // Apertura del file
    leggi.open("temperature.dat");

    // Se non e' riuscito ad aprire il file
    if(!leggi)
        cout << endl << "Errore: il file temperature.dat non esiste, riprovare" << endl;

    cout << endl << "Apertura del file temperature.dat...\n\n" ;

    // Lettura numero righe e colonne
    for(cont_riga=1; cont_riga<=2; cont_riga++){
        
        // Legge numero righe
        if(cont_riga==1)
            leggi >> righe;
        
        // Legge numero colonne
        if(cont_riga==2)
            leggi >> colonne;
        
        if(!leggi){
            cout << "Errore: valore non valido alla riga " << cont_riga << endl;
            return 0;
        }
    }

    cout << righe << " giorni, " << colonne << " misurazioni al giorno\n\n";

    // Alloca righe matrice (giorni)
    temperature = new int *[righe];

    // righe x colonne = totale misurazioni
    // colonne = numero di misurazioni giornaliere
    for(int i=0; i<(righe*colonne); i++){

        // Se siamo ad inizio riga, allora alloca nuova riga matrice
        if(i%colonne==0)
            temperature[i/colonne] = new int [colonne];

        // Leggi la misurazione
        leggi >> temperature[i/colonne][i%colonne];

        if(!leggi){
            cout << "Errore: valore non valido alla riga " << i+3 << endl;
            return 0;
        }
    }

    // Chiudi stream
    leggi.close();

    // Stampa misurazioni di ogni giorno
    for(int i=0; i<righe; i++){
        cout << i+1 << ".\t";

        for(int j=0; j<colonne; j++){
            cout << temperature[i][j] << "\t";
        }

        cout << endl;
    }

    // Crea vettore delle escursioni termiche per ogni giorno
    escursioni = new int[righe];

    // Carica nella cella dell'i-esimo giorno l'escursione termica
    // restituita dalla funzione
    for(int i=0; i<righe; i++)
        escursioni[i] = escursioneTermica(temperature[i], colonne);

    // Stampa escursioni termiche
    cout << "\nEscursioni termiche:\n\n";
    for(int i=0; i<righe; i++){
        cout << i+1 << ".\t" << escursioni[i] << endl;
    }

    // Troviamo i giorni con la massima escursione termica
    for(int i=0; i<righe; i++){
        // Primo giorno
        if(i==0){
            // Carica vettore giorni_max_escursione numero giorno
            giorni_max_escursione = new int[1];
            giorni_max_escursione[0] = i+1;
            // Assegna alla massima escursione termica il primo valore delle
            // escursioni
            max_esc = escursioni[i];
            // Incrementa contatore dei giorni con massima escursione
            cont_max=1;
        }else{
            // Se non e' primo giorno
            if(escursioni[i]>max_esc){
                // i-esima escursione maggiore dell'attuale massima

                // Quindi disalloca array giorni_max_escursione
                delete [] giorni_max_escursione;
                // Carica vettore giorni_max_escursione con giorno attuale
                giorni_max_escursione = new int[1];
                giorni_max_escursione[0] = i+1;
                // Assegna alla massima escursione termica dell'i-esimo giorno
                max_esc = escursioni[i];
                // Contatore di giorni con massima escursione uguale a 1
                cont_max=1;
            }else if(escursioni[i]==max_esc){
                // Se invece l'attuale escursione e' una massima
                // Allora aggiungiamo il giorno all'array giorni_max_escursione

                // Carichiamo i giorni salvati fino ad adesso nell'array_scambio
                // Quindi array_scambio punta ad area memoria giorni_max_escursione
                array_scambio = giorni_max_escursione;
                
                // Allochiamo array con dimensioni maggiore di 1 rispetto a prima
                giorni_max_escursione = new int[cont_max+1];

                // Copiamo i giorni con escursione massima nel nuovo array
                for(int j=0; j<cont_max; j++){
                    giorni_max_escursione[j] = array_scambio[j];
                }

                // Deallochiamo area memoria array_scambio
                delete [] array_scambio;
                array_scambio = NULL;
                
                // Aggiungiamo giorno i-esimo e incrementiamo contatore massimi
                giorni_max_escursione[cont_max] = i+1;

                cont_max++;
            }
        }
    }

    // Stampa giorni con escursione massima
    cout << "\nGiorni con massima escursione termica: ";
    for(int i=0; i<cont_max; i++){
        cout << giorni_max_escursione[i] << " ";
    }

    cout << endl;

    delete [] escursioni;
    delete [] giorni_max_escursione;
    delete [] array_scambio;
    delete [] temperature;

    return 0;
}