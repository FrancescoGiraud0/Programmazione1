/**
 * Laboratorio 11.3 C++
 * @author DemartiniGiraudo
 * @file DemartiniGiraudo_E113.cpp
 *
 * Codificare in C++ le seguenti funzioni che saranno utilizzate per
 * sviluppare un programma per automatizzare dei giochi enigmistici:
 *
 * 1.funzione che controlla se una parola è ottenuta da un'altra
 *   aggiungendo una lettera (la lettera può essere aggiunta in qualunque
 *   punto);
 * 2.funzione che controlla se una parola è ottenuta da un'altra
 *   togliendo una lettera (la lettera può essere tolta in qualunque punto)
 * 3.funzione che controlla se una parola è ottenuta da un'altra cambiando 
 *   una lettera.
 *
 * Le due parole sono contenute in due stringhe.
 * Scrivere poi un main che permetta di testarle.
*/

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

bool lettera_aggiunta(string s1, string s2);
bool lettera_tolta(string s1, string s2);
bool lettera_cambiata(string s1, string s2);

int main(){
    ifstream leggi;
    string originale, modificato;
    string aspettativa[3], ris[3];
    int riga=1, passati=0, falliti=0;

    leggi.open("genoa.txt");

    if(!leggi){
        cout << "Errore: file non trovato" << endl;
        return 0;
    }

    // saltiamo header file
    leggi >> originale >> modificato >> aspettativa[0] >> aspettativa[1] >> aspettativa[2];
  
    while(leggi.good()){ 

        leggi >> originale >> modificato >> aspettativa[0] >> aspettativa[1] >> aspettativa[2];
        
        if(!leggi){
            cout << "Errore: lettura dato riga " << riga+1 << endl;
            break;
        }

        ris[0] = (lettera_aggiunta(originale, modificato)) ? "T" : "F";
        ris[1] = (lettera_tolta(originale, modificato)) ? "T" : "F";
        ris[2] = (lettera_cambiata(originale, modificato)) ? "T" : "F";
        
        cout << "(" << originale << ", " << modificato << ")";
        cout << " [" << aspettativa[0] << ", " << aspettativa[1] << ", " << aspettativa[2] << "] ->";
        cout << " [" << ris[0] << ", " << ris[1] << ", " << ris[2] << "]";

        if(ris[0]==aspettativa[0] && ris[1]==aspettativa[1] && ris[2]==aspettativa[2]){
            passati++;
            cout << " Passato" << endl;
        }else{
            falliti++;
            cout << " Fallito" << endl;
        }

        riga++;
    }

    leggi.close();

    cout << "\nTest passati: " << passati << " / " << riga-1 << endl;
    cout << "Test falliti: " << falliti << " / " << riga-1 << endl;

    return 0;
}

/**
 * Funzione che data due stringhe s1 e s2, restituisce true se 
 * la stringa s2 e' ottenuta da s1 aggiungendo una lettera.
 * 
 * @param[in] s1 string
 * @param[in] s2 string
 * @return [bool] True se s2 e' ottenuta da s1 aggiungendo una lettera
 */
bool lettera_aggiunta(string s1, string s2){
    string s3;
    bool aggiunta = false;
    int dim_s1=s1.length(), dim_s2= s2.length();

    // Se la dimensione di s2 e' uguale a quella di s1+1
    // (cambia solo una lettera)
    if( dim_s2 == dim_s1+1 ){
        
        // Per tutte le lettere di s2 e aggiunta e ancora false
        for(int i=0; i<dim_s2 && aggiunta==false; i++){
            // Crea una sottostringa di s2 formata da tutte le lettere tranne la i-esima
            s3 = s2.substr(0,i) + s2.substr(i+1, dim_s2);

            // Se la sottostringa e' uguale a s1
            if(s1==s3)
                aggiunta = true;
        }
    }

    return aggiunta;
}

/**
 * Funzione che data due stringhe s1 e s2, restituisce true se 
 * la stringa s2 e' ottenuta da s1 togliendo una lettera.
 * Equivale a lettera_aggiunta invertendo l'ordine.
 * 
 * @param[in] s1 string
 * @param[in] s2 string
 * @return [bool] True se s2 e' ottenuta da s1 togliendo una lettera
 */
bool lettera_tolta(string s1, string s2){
    return lettera_aggiunta(s2, s1);
}

/**
 * Funzione che data due stringhe s1 e s2, restituisce true se 
 * la stringa s2 e' ottenuta da s1 cambiando una lettera.
 * 
 * @param[in] s1 string
 * @param[in] s2 string
 * @return [bool] True se s2 e' ottenuta da s1 cambiando una lettera
 */
bool lettera_cambiata(string s1, string s2){
    string s3, s4;
    bool cambiata = false;
    int dim_s1 = s1.length(), dim_s2 = s2.length();

    // Se la dimensione di s1 e' uguale a s2, condizione necessaria
    if( dim_s1 == dim_s2){
        // Per tutte le lettere di s1
        for(int i=0; i<dim_s1 && cambiata==false; i++){
            // Sottostringa s1 senza lettera i-esima
            s3 = s1.substr(0,i) + s1.substr(i+1, dim_s1);

            // Sottostringa s2 senza lettera j-esima
            for(int j=0; j<dim_s2 && cambiata==false; j++){
                s4 = s2.substr(0,j) + s2.substr(j+1, dim_s2);

                // Se la sottostringa senza i-esima e' uguale a quella senza j-esima
                if(s3==s4)
                    cambiata = true;
            }
        }
    }
    
    // false se nessuna sottostringa uguale, se no true
    return cambiata;
}