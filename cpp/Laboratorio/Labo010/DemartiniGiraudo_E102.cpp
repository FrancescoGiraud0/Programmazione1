/*
Esercizio 10.2 C++
Gruppo: DemartiniGiraudo
Data: 16/04/2021

Un  quadrato magico è una matrice la cui somma su ogni riga,
su ogni colonna e sulle diagonali principali  risulta uguale
ad un valore numerico detto costante magica.  Avete a
disposizione tre esempi nei file:  magic3.dat, magic11.dat,
magic15.dat che contengono un numero che corrisponde alla
dimensione della matrice (quadrata) e i dati della matrice
stessa. 

Scrivere un programma C++:
1. chieda il nome di un file, legga dal tale file  la dimensione
   della matrice 
2. allochi dinamicamente una matrice di dimensione opportuna
3. legga da tale file i restanti dati assegnandoli agli elementi
   della matrice
4. stampi sullo standard output la matrice (andando a capo ogni 
   riga)
5. stampi le somme su ciascuna riga, su ciascuna colonna e sulle
   due diagonali principali per controllare che la matrice letta
   sia un quadrato magico
6. alternativamente  automatizzare il controllo e sostituire il 
   punto precedente con un'unica stampa che comunichi se la matrice
   è un quadrato magico o meno e nel caso positivo stampi la 
   "costante magica". 

In questo caso è assolutamente rilevante per prima cosa scrivere 
l'algoritmo da seguire usando il pseudo codice.
*/

/*
PSEUDOCODICE CONTROLLO QUADRATO MAGICO

- Per ogni riga r<n, con n dimensione matrice
    - Per ogni colonna c<n
        - Somma l'elemento (r,c) alla somma parziale della riga
          r-esima
        - Somma l'elemento (c,r) alla somma parziale della colonna
          c-esima
        - Se r==c (siamo sulla diag. principale) somma l'elemento
          (r,c) alla somma parziale della diagonale principale
        - Se r+c==n-1(siamo sulla diag. secondaria) somma l'elemento
          (r,c) alla somma parziale della diagonale secondaria

- La somma della diag. principale e' uguale a quella della secondaria?
    - True:
        - Per ogni somma di ciascuna riga e ciascuna colonna, sono uguali
          alla somma della diagonale principale?
            - True: Quadrato magico
            - False: Non e' un quadrato magico, quindi non controllare le
                     somme delle righe e colonne successive
    - False: Non e' un quadrato magico
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
    // Input file stream per lettura file
    ifstream leggi;
    // Dichiarazione di matrice allocata dinamicamente
    int **mat = NULL;
    // Dimensione matrice
    int n;
    bool magico;
    // Somme diagonali inizializzate a 0
    int somma_dp = 0, somma_ds = 0;
    // Vettori dinamici per somme per ogni riga/colonna
    int *somma_riga=NULL, *somma_col=NULL;
    // Costante per nome file
    string nomeFile;

    // Input nome file
    cout << "Inserire nome del file da leggere: ";
    cin >> nomeFile;

    // Apertura del file
    leggi.open(nomeFile.c_str());

    // Se non e' riuscito ad aprire il file
    if(!leggi){
        cout << endl << "Errore: il file non esiste" << endl;
        return 0;
    }

    cout << endl << "Apertura del file "<< nomeFile << "...\n\n" ;

    // Lettura dimensione matrice
    leggi >> n;
    
    if(!leggi){
        cout << "Errore: valore non valido alla riga 1 " << endl;
        return 0;
    }

    cout << "Matrice dimensione = " << n << "\n\n";

    mat = new int *[n];

    // Per ogni valore della matrice
    for(int i=0; i<(n*n); i++){

        // Allochiamo riga i-esima se siamo ad inizio riga
        if(i%n==0)
            mat[i/n] = new int [n];

        // Legge elemento
        leggi >> mat[i/n][i%n];
        
        // Gestione errori lettura
        if(!leggi){
            cout << "Errore: valore non valido alla riga " << i+2 << endl;
            return 0;
        }
    }

    // Chiudi stream
    leggi.close();
    
    // Stampa matrice
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout << mat[i][j] << "\t";

        cout << endl;
    }
    

    // Allochiamo vettori dinamici di dimensione n per le somme
    somma_riga = new int[n];
    somma_col  = new int[n];

    // Carichiamo i vettori appena creati con 0 per ogni cella
    for(int r=0; r<n; r++){
        for(int c=0; c<n; c++){
            somma_riga[r] = 0;
            somma_col[c]  = 0;
        }
    }    

    // Calcoliamo le somme riga, colonna, DP, DS
    for(int r=0; r<n; r++){
        for(int c=0; c<n; c++){
            somma_riga[r] += mat[r][c];
            somma_col[c]  += mat[c][r];

            // Se siamo sulla diagonale principale
            if(r==c)
                somma_dp += mat[r][c];
            
            // Se siamo sulla diagonale secondaria
            if((r+c)==(n-1))
                somma_ds += mat[r][c];
        }
    }

    // Dealloca matrice
    delete [] mat;

    // Controllo che sia quadrato magico
    magico = true;

    if(somma_dp!=somma_ds)
        magico = false;

    for(int i=0; (i<n)&&(magico); i++){
        if((somma_riga[i]!=somma_dp) || (somma_col[i]!=somma_dp))
            magico = false;
    }

    if(magico){
        cout << "\nQuadrato e' magico" << endl;
        cout << "Costante magica = " << somma_dp << endl;
    }else{
        cout << "\nQuadrato NON e' magico\n" << endl;

        cout << "\nSOMME RIGHE:\n\n";
        for(int i=0; i<n; i++){
            cout << "Somma riga " << i << " = " << somma_riga[i] << endl;
        }
        
        cout << "\nSOMME COLONNE:\n\n";
        for(int i=0; i<n; i++){
            cout << "Somma colonna " << i << " = " << somma_col[i] << endl;
        }

        cout << "\nSOMME DIAGONALI:\n\n";
        cout << "Somma diagonale principale " << somma_dp << endl;
        cout << "Somma diagonale secondaria " << somma_ds << endl;
    }

    delete [] somma_col;
    delete [] somma_riga;

    return 0;
}