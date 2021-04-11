/*
Esercizio 8.3 C++
Gruppo: DemartiniGiraudo
Data: 09/04/2021

Modificare l'esercizio precedente nel modo seguente:
il programma non calcola piu' il dato massimo assoluto,
ma calcola tutti i massimi relativi e li scrive sul file
di output.

Per massimo relativo si intende un dato che sia
strettamente maggiore sia del dato precedente che del
dato seguente.

Per poter individuare un massimo relativo mentre si scorre
il file, bisogna tenere in memoria i valori di tre righe:

1. l'ultima riga letta
2. la penultima 
3. la terzultima

e ad ogni (ultima) riga letta e' possibile verificare se
la penultima riga corrispondeva ad un massimo relativo.

Se corrispondeva ad un massimo relativo (ovvero se il dato
e' maggiore di quello delle altre due righe) possiamo
stamparlo subito sul file di output.
*/

/*
Nota: nel file di input forniti i valori interi di giorno e
mese con solo una cifra hanno lo zero davanti (01, 02,...),
mentre in quelli di output forniti no (1,2,...). 
Quindi quando andiamo a controllare con il comando diff del
terminale linux trova molte righe differenti.
*/

#include <iostream>
#include <string>
#include <fstream> // Libreria file stream
#include <sstream> // Libreria string stream

using namespace std;

int main(){
    ifstream leggi;
    ofstream scrivi;
    stringstream ss;
    string nomeFileInput;
    string nomeFileOutput;
    string riga;
    //Array di stringhe per salvare le ultime tre righe lette
    string array_righe[3];
    // Array di interi per salvare gli ultimi 3 dati letti
    int array_dati[3];
    int giorno, mese, anno, dato;
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
            cout << endl << "Errore: il file di input " << nomeFileInput << " non esiste, riprovare" << endl;

    }while(!leggi); // Entra nel ciclo fino a che non inserito file esistente

    cout << "Inserire nome file di output (senza estensione): ";
    cin >> nomeFileOutput;

    nomeFileOutput += ".txt";

    // Apertura anche del file in scrittura
    scrivi.open( nomeFileOutput.c_str());

    // Leggi file fino alla fine
    while( !(leggi.eof()) ){
        // Leggi riga e assegna a stringa riga
        getline(leggi, riga);

        // Se la riga non e' vuota 
        if( !(riga.empty() || riga==" ") ){
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

                        break;
                }
            }
            // Dopo aver letto la riga con gli opportuni controlli
            
            // Sposta le righe precedenti di 1 casella precedente
            // Sposta la riga 1 nella riga 0
            array_righe[0] = array_righe[1];
            // E la riga 2 nella riga 1
            array_righe[1] = array_righe[2];
            // Salva l'ultima riga letta nell'ultima cella del vettore array_righe
            array_righe[2] = riga;

            // Facciamo lo stesso procedimento di prima per array_dati
            array_dati[0] = array_dati[1];
            array_dati[1] = array_dati[2];
            array_dati[2] = dato;

            // Se sono state lette almeno tre righe
            if(cont_riga>=3 ){
                // La riga letta prima e' massimo relativo?
                if(array_dati[1]>array_dati[0]){
                    if(array_dati[1]>array_dati[2])
                        // Si, allora scrivila sul file
                        scrivi << array_righe[1] << "\n";
                }
            }

            // Incrementa contatore riga dopo aver terminato
            cont_riga++;
        }
    }

    // Chiudi file scrittura
    scrivi.close();
    //Chiudi file lettura
    leggi.close();

    return 0;
}