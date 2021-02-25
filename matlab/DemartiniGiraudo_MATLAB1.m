%Punto A
sqrt(2)
log(10)
exp(3)

% Punto B

% Creazione vettore con elementi da 100 a 1
v_cento = 100:-1:1;

%Creazione vettore di zeri
v_zeri = zeros(1,20);

% Matrice di 10x20 di zeri
m_zeri = zeros(10,20);

% Quadrato magico
dim = 4;
m_magico = magic(dim);

% Ciclo for per controllare somme riga per riga
for i=1:dim
    sum(m_magico(i,:))
end

% Ciclo for per controllare somme colonna per colonna
for i=1:dim
    sum(m_magico(:,i))
end

% Traccia di m_magico
trace(m_magico);
% Equivalente a sum(diag(m_magico))

% Somma diagonale secondaria
trace(fliplr(m_magico));
% Equivalente a sum(diag(fliplr(m_magico)))

% Punto C
A = [ 1 3 2;
     -5 3 1;
    -10 0 3;
     1 0 -2 ];
 
B = [ 1 -2 5;
      6 1 -1 ];
  
C = [ 10 -5;
       3 1  ];

% AB
dim_A = size(A);
dim_B = size(B);

AB  = [];
BA  = [];
ABt = [];

% If per controllare che il numero di colonne della prima matrice
% è uguale al numero di righe della seconda
if(dim_A(2)==dim_B(1))
    AB = A*B; % Non si può fare, la if lo impedisce
end

% BA
if(dim_B(2)==dim_A(1))
    BA = B*A; % Non si può fare, la if lo impedisce
end

% AB^t
dim_Bt = size(B');
if(dim_A(2)==dim_Bt(1))
    ABt = A*(B');
end

% Determinanti A,B,C
dim_C = size(C);

% Calcolo dei determinanti delle sole matrici quadrate
% con if per controllare dimensione
if (dim_A(1)==dim_A(2))
    det_A = det(A);
end

if (dim_B(1)==dim_B(2))
    det_B = det(B);
end

if (dim_C(1)==dim_C(2))
    det_C = det(C);
end

% Calcolo inversa di C
inv_C = inv(C);

% Calcolo inversa di D=AA^t
D = A*A';
inv_D = inv(D);

% Punto D
M = [1 1; 1 -1];
s = [24 ; 6];

% Soluzione del sistema
X = M\s;

% Punto E

% Generiamo casualmente un vettore di 10 elementi INTERI compresi tra 0 e 100
x = round(rand(1,10)*100);

prod_x = x.*x;
el_2 = x.^2;

% x*x'ha soluzione perchè moltiplica il vett riga per un vett colonna delle stesse dim
xxt = x*x';

% x*x da errore perchè il numero di righe è diverso dalle colonne




