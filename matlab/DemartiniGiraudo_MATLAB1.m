%Punto A

sqrt(2) % radice quadrata di 2
log(10) % logaritmo naturale di 10
log(1) % == 0
exp(1) % e^1 -> Numero di eulero == 2.718...
exp(log(2)) % == 2
log(exp(2)) % == 2

% Punto B

% Creazione vettore con elementi da 100 a 1
v_cento = 100:-1:1;

%Creazione vettore di zeri
v_zeri = zeros(1,20);

% Matrice di 10x20 di zeri
m_zeri = zeros(10,20);

% Creazione quadrato magico di dimensione dim, dove dim = 4
dim = 4;
m_magico = magic(dim);

% Creazione vettore vuoto in cui salvare il risultato delle
% somme per riga
somme_riga = zeros(3);

% Ciclo for per controllare somme di ogni riga ed in cui
% le somme vengono salvate in un vettore
for i=1:dim
    somme_riga(i) = sum(m_magico(i,:));
end

% Creazione vettore vuoto in cui salvare il risultato delle
% somme per colonna
somme_colonna = zeros(3);

% Ciclo for per controllare di ogni colonna ed in cui
% le somme vengono salvate in un vettore
for i=1:dim
    somme_colonna = sum(m_magico(:,i));
end

% Traccia di m_magico (somma sulla diagonale principale)
somma_dp = trace(m_magico);
% Equivalente a sum(diag(m_magico))

% Somma diagonale secondaria
somma_ds = trace(fliplr(m_magico));
% Equivalente a sum(diag(fliplr(m_magico)))

% Punto C

% Creazioni delle matrici A, B, C
A = [ 1 3 2;
     -5 3 1;
    -10 0 3;
     1 0 -2 ];
 
B = [ 1 -2 5;
      6 1 -1 ];
  
C = [ 10 -5;
       3 1  ];

% Salvo le dimensioni delle matrici A, B, C nelle variabili
% dim_A, dim_B e dim_C
% size(M): [n. righe di M, n. colonne di M]
dim_A = size(A);
dim_B = size(B);
dim_C = size(C);

% Inizializzazione delle matrici vuote in cui andare a salvare i
% risultati dei prodotti
AB  = []; %A*B
BA  = []; %B*A
ABt = []; %A*B'

% If per controllare che il numero di colonne della prima matrice
% sia uguale al numero di righe della seconda, se sono uguali fa il
% prodotto tra matrici e lo salva in AB
if(dim_A(2)==dim_B(1))
    % Non si può fare, comunque la if evita l'errore
    AB = A*B;
end

% If per controllare che il numero di colonne della prima matrice
% sia uguale al numero di righe della seconda, se sono uguali fa il
% prodotto tra matrici e lo salva in BA
if(dim_B(2)==dim_A(1))
    % Non si può fare, comunque la if evita l'errore
    BA = B*A;
end

% If per controllare che il numero di colonne della prima matrice
% sia uguale al numero di righe della seconda, se sono uguali fa il
% prodotto tra matrici e lo salva in BA
dim_Bt = size(B');
if(dim_A(2)==dim_Bt(1))
    ABt = A*(B');
end

% Calcolo dei determinanti di A,B,C

% Calcolo dei determinanti possibile per le sole matrici quadrate
% con If per confontare il numero delle righe di A (dim_A(1)) con
% quello delle colonne di A (dim_A(2)), se sono uguali la matrice
% è quadrata, quindi si può procedere a calcolare il determinante
if (dim_A(1)==dim_A(2))
    % Matrice non quadrata, non è possibile calcolare il det
    det_A = det(A);
end

% Calcolo dei determinanti possibile per le sole matrici quadrate
% con If per confontare il numero delle righe di B (dim_B(1)) con
% quello delle colonne di B (dim_B(2)), se sono uguali la matrice
% è quadrata, quindi si può procedere a calcolare il determinante
if (dim_B(1)==dim_B(2))
    % Matrice non quadrata, non è possibile calcolare il det
    det_B = det(B);
end

% Calcolo dei determinanti possibile per le sole matrici quadrate
% con If per confontare il numero delle righe di C (dim_C(1)) con
% quello delle colonne di C (dim_C(2)), se sono uguali la matrice
% è quadrata, quindi si può procedere a calcolare il determinante
if (dim_C(1)==dim_C(2))
    % Matrice quadrata!
    det_C = det(C);
end

% Calcolo inversa di C (C matrice quadrata) e salva risultato in inv_C
inv_C = inv(C);

% Calcolo della matrice D, calcolo inversa di D=AA^t e salvataggio in inv_D
D = A*A';
inv_D = inv(D);

% Punto D

% Creazione matrici relative al sistema M mat. 2x2 ed s mat. colonna 2x1
M = [ 1 1;
      1 -1 ];
s = [ 24;
      6 ];

% Calcolo soluzione del sistema
X = M\s;

% Punto E

% Generiamo casualmente un vettore di 10 elementi INTERI compresi tra 0 e 100
x = round(rand(1,10)*100);

% Calcolo di x.*x
prod_x = x.*x;

% Calcolo x.^2
el_2 = x.^2;

% x*x'ha soluzione perchè moltiplica il vett riga per un vett colonna
% delle stesse dim, quindi possibile calcolare il prodotto riga x colonna
xxt = x*x';

% Non è possibile calcolare x*x perchè il numero di righe di x è diverso
% dal numero di colonne