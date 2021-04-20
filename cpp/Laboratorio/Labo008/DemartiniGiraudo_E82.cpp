/*
Esercizio 8.2 C++
Gruppo: DemartiniGiraudo
Data: 09/04/2021

Modificare il programma precedente chiedendo all'utente anche il
nome di un file di output, e scrivere su questo file la riga con
il risultato vero e proprio (i quattro numeri senza alcun commento).

La modalita' di immissione del nome del file di output deve essere 
la stessa che per il file di input: si chiede il nome senza estensione
e l'estensione .txt viene aggiunta dal programma.
*/

#include <iostream>
#include <string>
#include <fstream> // Libreria file stream
#include <sstream> // Libreria string stream

using namespace std;

int main(){
    // Stream lettura file
    ifstream leggi;
    // Stream scrittura file
    ofstream scrivi;
    // String stream
    stringstream ss;
    // Stringhe con nomi file input e output
    string nomeFileInput;
    string nomeFileOutput;
    // Stringa con riga del massimo e valore massimo inizializzato a 0
    string riga_massimo;
    int massimo=0;
    // Stringa per lettura riga e dati interi della riga
    string riga;
    int giorno, mese, anno, dato;
    // Contatore riga letta inizializzato a 1
    unsigned int cont_riga=1;

    do{
        cout << "Inserire nome file di input (senza estensione): ";
        cin >> nomeFileInput;

        // Aggiunge estensione al nome del file
        nomeFileInput = nomeFileInput+".txt";

        // Apertura del file
        leggi.open( nomeFileInput.c_str());

        // Se non e' riuscito ad aprire il file
        if(!leggi)
            cout << endl << "Errore: il file " << nomeFileInput << " non esiste, riprovare" << endl;

    }while(!leggi); // Entra nel ciclo fino a che non inserito file esistente

    cout << endl << "Leggo il file " << nomeFileInput << endl;

    // Leggi file fino alla fine
    while( !(leggi.eof()) ){
        // Leggi riga e assegna a stringa riga
        getline(leggi, riga);

        // Se la riga non e' vuota 
        if( !(riga.empty()) ){
            // Salva la riga nello string stream
            ss << riga;

            // Per quattro volte, quanti sono i valori per ogni riga
            for(unsigned int i=1; i<=4; i++){

                switch(i){
                    // Se primo valore, allora scrivi in giorno
                    case 1:
                        ss >> giorno;
                        
                        if(!ss){
                            cout << "Errore: giorno non valido alla riga " << cont_riga << " del file\n";
                            leggi.close();
                            return 0;
                        }
                        
                        // Controlla che mese stia nell'intervallo [1,31]
                        if((giorno<1)||(giorno>31)){
                            cout << "Errore: " << giorno << " non e' un giorno valido (riga " << cont_riga << " del file)\n";
                            leggi.close();
                            return 0;
                        }

                        break;
                    // Se secondo valore, allora scrivi in mese
                    case 2:
                        ss >> mese;

                        if(!ss){
                            cout << "Errore: mese non valido alla riga " << cont_riga << " del file\n";
                            leggi.close();
                            return 0;
                        }

                        // Controlla che mese stia nell'intervallo [1,12]
                        if((mese<1)||(mese>12)){
                            cout << "Errore: " << mese << " non e' un mese valido (riga " << cont_riga << " del file)\n";
                            leggi.close();
                            return 0;
                        }

                        break;
                    // Se terzo valore, allora scrivi in anno
                    case 3:
                        ss >> anno;

                        if(!ss){
                            cout << "Errore: anno non valido alla riga " << cont_riga << " del file\n";
                            leggi.close();
                            return 0;
                        }

                        break;
                    // Se quarto valore, allora scrivi in dato
                    case 4:
                        ss >> dato;

                        if(!ss){
                            cout << "Errore: dato non valido alla riga " << cont_riga << " del file\n";
                            leggi.close();
                            return 0;
                        }

                        // Controlla che dato sia strettamente positivo
                        if(dato<0){
                            cout << "Errore: " << dato << " non e' positivo (riga " << cont_riga << " del file)\n";
                            leggi.close();
                            return 0;
                        }

                        // Se il dato e' maggiore o uguale al massimo
                        if(massimo <= dato){
                            // dato e' il nuovo massimo e riga e' la nuova riga_massimo
                            massimo = dato;
                            riga_massimo = riga;
                        }

                        break;
                }
            }

            cont_riga++;
        }
    }

    // Chiudi stream leggi
    leggi.close();

    cout << "\nInserire nome file di output (senza estensione): ";
    cin >> nomeFileOutput;

    nomeFileOutput = nomeFileOutput+".txt";

    cout << "Scrivo su file " << nomeFileOutput << endl;

    // Apre file in scrittura
    scrivi.open( nomeFileOutput.c_str() );

    // Scrive la riga con il massimo
    scrivi << riga_massimo;
    
    // Chiude lo stream scrivi
    scrivi.close();

    return 0;
}