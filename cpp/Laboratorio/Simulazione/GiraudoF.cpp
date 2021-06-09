/**
 * Giraudo Francesco
 * Simulazione Esame C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

// Per rappresentare un elemento diverso da zero di una matrice sparsa
struct ELEMENTO{
	int iRiga, iColonna, elemento;
};

// Per rappresentare una matrice sparsa
struct SPARSA {
	int nRighe, nColonne;
	vector <ELEMENTO> elementi;
};

// Prototipi funzioni create
int at(SPARSA M, int iR, int iC);
void inserisciElementoNonZero(SPARSA & M, int iR, int iC, int el);
void errore(string motivo);
void stampaMatrice(SPARSA M);
double percentualeDiversiO(SPARSA M);

void errore(string motivo){
	cout << "Errore: " + motivo << endl;
  exit(1);
}
	
void inserisciElementoNonZero(SPARSA & M, int iR, int iC, int el){
  // inserisce l'elemento el (diverso da zero) individuato dagli indici iR e iC nella matrice sparsa M
  // segnala errore se gli indici non individuano un elemento della matrice o se esiste gia' un elemento
  // diverso da zero individuato da tali indici o se el e' uguale a zero.
  // punto A
  ELEMENTO E;

  // Assegna valori all'elemento E da aggiungere al vector di elementi
  E.iRiga = iR;
  E.iColonna = iC;
  E.elemento = el;

  // Se el e' diverso da 0 e la posizione (iR, iC) esiste nella matrice e non e' ancora stata assegnata (==0),
  // allora aggiungi elemento al vector elementi
  if(el!=0 && at(M, iR, iC)==0)
    M.elementi.push_back(E);

}

int at(SPARSA M, int iR, int iC){
  // ritorna l'elemento di M individuato dagli indici iR e iC
  // segnala errore se gli indici non individuano un elemento della matrice M
  // punto B
  
  if(iR>=1 && iC>=1 && iR<=M.nRighe && iC<=M.nColonne){
    // Cerca nel vector di elementi se esiste elemento in posizione (iR, iC)
    for(unsigned int i=0; i<M.elementi.size(); i++)
      if(M.elementi.at(i).iRiga==iR && M.elementi.at(i).iColonna==iC)
        return M.elementi.at(i).elemento;
  }else{
    errore("indice riga-colonna non esiste nella matrice di questa dimensione");
    exit(1);
  }

  // Se non trova elementi in quella posizione, l'elemento e' zero
  return 0;
}

void stampaMatrice(SPARSA M){

  // Per tutte le celle della matrice stampa il valore
  // at() ritorna 0 se la cella non e' presente nel vector elementi
  // inoltre si fa il controllo che non ci siano copie della stessa cella nel vector
  for(int row=1; row<=M.nRighe ; row++){
    for(int col=1; col<=M.nColonne ; col++)
      cout << at(M, row, col) << "\t";

    cout << endl;
  }
}

double percentualeDiversi0(SPARSA M){
  // Numero elementi nel vector diviso il numero totale di elementi in percentuale
  return ((double)M.elementi.size() / (M.nRighe*M.nColonne))*100;
}

int main(){
  string nome_file;
	ifstream input;

	cout << "Inserire il nome del file contenente le matrice sparsa" <<endl;
	cin >> nome_file;

	input.open(nome_file.c_str());

	if(!input)
		errore("Non si riesce ad aprire il file "+ nome_file);
   
	SPARSA MAT;
	int N;

	input >> MAT.nRighe >> MAT.nColonne;

  if(!input || MAT.nRighe < 1 || MAT.nColonne < 1){
    errore("problema leggendo le dimensioni della matrice");
    input.close();
  }

  input >> N;
  
  if(!input || N < 0){
    input.close();
    errore("problema leggendo il numero di elementi diversi da zero della matrice");
  }
  
  // Controllo che il numero di elementi diversi da zero sia minore della dimensione della matrice
  if(N>MAT.nRighe*MAT.nColonne){
    input.close();
    errore("numero di elementi diversi da zero maggiore della dimensione della matrice");
  }
  
  // Per input riga, colonna ed elemento da inserire
  unsigned int iR, iC;
  int el;

  // punto C
  // lettura degli elementi della matrice contenuti nel file
  for(int i=0; i<N; i++){
      // Prova a leggere
      input >> iR >> iC >> el;

      // Se errore nella letttura (tipi non validi o fallimento lettura elemento)
      if(!input){
        input.close();
        errore("errore nella lettura dell'elemento");
      }

      if(iR<=0 || iC<=0){
        input.close();
        errore("letti da file indici non strettamente maggiori di zero");
      }

      // Inserisci el nella matrice in posizione (iR, iC)
      inserisciElementoNonZero(MAT, iR, iC, el);
  }

  input.close();

  //punto D
  //scrivere sullo standard output la matrice contenuta in MAT
  stampaMatrice(MAT);

  //punto E
  //scrivere sullo standard output la percentuale degli elementi di MAT che sono diversi da 0
  cout << "\nPercentuale elementi diversi da zero: " << percentualeDiversi0(MAT) << "%"<< endl;

  return 0;
}
 
