/*
Esercizio 8.1 C++
Gruppo: DemartiniGiraudo
Data: 09/04/2021

Scrivere un programma C++ che chiede all'utente il nome del
file da aprire senza estensione .txt, apre in lettura il
file con quel nome ed estensione .txt, legge il file e
stampa i quattro valori (giorno mese anno dato)
corrispondenti alla riga con il dato massimo (ricordiamo che
il dato e' il quarto elemento delle righe).

Il programma deve fare tutti i necessari controlli in fase di
lettura e, in caso di errore, deve terminare con un messaggio
opportuno. Nota bene: per il giorno occorre controllare solo
che sia un intero nell'intervallo [1,31], NON controllare che
corrisponda alla lunghezza del mese.

Inoltre deve stampare le necessarie frasi esplicative per 
l'utente,compresa una frase esplicativa del risultato, ma
sulla riga del risultato vero e proprio non deve comparire
nient'altro che i quattro numeri.
*/

#include <iostream>
#include <string>
#include <fstream> // Libreria file stream
#include <sstream> // Libreria per string stream

using namespace std;

int main(){
    // Input file stream per lettura file
    ifstream leggi;
    // String stream per lettura singoli valori sulla riga
    stringstream ss;
    // Stringa con nome del file
    string nomeFile;
    // Stringa riga e interi per salvare dati sulla riga
    string riga;
    int giorno, mese, anno, dato;
    // Contatore righe con inizializzazione a 1
    unsigned int cont_riga=1;
    // Stringa in cui salvare la riga del massimo
    string riga_massimo;
    // Variabile in cui salvare valore massimo assoluto, all'inizio e' 0
    int massimo=0;

    do{
        cout << endl <<"Inserire nome file (senza estensione): ";
        cin >> nomeFile;

        // Aggiunge estensione al nome del file
        nomeFile = nomeFile+".txt";

        // Apertura del file
        leggi.open( nomeFile.c_str());

        // Se non e' riuscito ad aprire il file
        if(!leggi)
            cout << endl << "Errore: il file " << nomeFile << " non esiste, riprovare" << endl;

    }while(!leggi); // Entra nel ciclo fino a che non inserito file esistente

    cout << endl << "Apro il file " << nomeFile << endl << endl;

    // Leggi fino alla fine il file
    while( !(leggi.eof())){
        
        // Leggi riga del file e assegna a stringa riga
        getline(leggi, riga);

        // Se la riga non e' vuota
        if( !(riga.empty()) ){
            // Scrivi riga nello stringstream ss
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
                            // dato e' il nuovo massimo e riga e la nuova riga_massimo
                            massimo = dato;
                            riga_massimo = riga;
                        }

                        break;
                }
            }
            // Incrementa il contatore della riga dopo il for
            cont_riga++;
        }
    }

    // Chiudi stream
    leggi.close();

    // Stampa la riga con il massimo assoluto
    cout << "Massimo assoluto:\n\n" << riga_massimo << endl;

    return 0;
}