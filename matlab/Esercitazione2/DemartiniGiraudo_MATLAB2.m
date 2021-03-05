%% Pulisci tutto
clc
close all
clear all

%% Punto A

% A. Grafico della funzione arcotangente nell’intervallo [-4, 4].

% Creazione vettore X con valori da -4 a 4 con step di 0.1 
X = -4:0.1:4;

figure;

% Stampa il grafico
% atan(X):= vettore composto dai valori dell'arcotangente per ogni valore di X
plot(X, atan(X));

% Titolo del grafico
title('Grafico arctg(x)');

% Nome degli assi x e y
xlabel('x');
ylabel('y');

% Attiva griglia
grid on;

%% Punto B

% B. Immagine con i grafici di (1/2)*sin(x), sin(x) e 2*sin(x) sovrapposti 
%    nell’intervallo [−2*pi, 2*pi].

% Vettore di tutti i valori da -2*pi a 2pi con step di 0.1
X = -2*pi:0.1:2*pi;
% Vettore composto dai valori del seno calcolati per ogni elemento di X
SEN = sin(X);

figure;

% Grafico 1/2 sin(x), '--r' indica linea tratto-punto rossa
plot(X, (0.5)*SEN, '-.r');

hold on
% Limite assi del grafico, su ascissa va da -2*pi a 2*pi,
% su ascissa da -2.5 a 2.5
axis([-2*pi 2*pi -2.5 2.5]);

% Inserisci griglia
grid on

% Titolo grafico
title('Grafici Seno');

% Nomi degli assi
xlabel('x');
ylabel('y');

% Grafico sin(x), '--b' indica linea tratteggiata blu
plot(X, SEN, '--b');

% Grafico 2sin(x), '-y' indica linea continua gialla
plot(X, 2*SEN, '-y');

% Legenda grafico
legend('(1/2)sin(x)', 'sin(x)', '2sin(x)');

hold off

%% Punto C

% C. Immagine con tre sottografici, che rappresentano rispettivamente x^2, 
%    x^3 e x^4 nell’intervallo [-2, 2].

X = -2:0.1:2;

% Crea la figure (finestra) del grafico con posizione dell'angolo in basso
% sinistra (200,200) dello schermo del PC, e con dimensione 900x300 piXl.
% In questo modo i grafici NON risultano "stirati" in altezza e quindi
% visivamente migliori da osservare.
f = figure('Position', [200 200 900 300]);

% Creazione di 3 subplots, 1 riga e 3 colonne

% Primo subplot
subplot(1,3,1);
% Stampa grafico
plot(X, X.^2);
% Inserisci griglia
grid on
% Limita l'asse y ai valori tra -4 a 4
ylim([-4 4]);
% Nomina gli assi
xlabel('x');
ylabel('y');
% Inserisci legenda con nome della funzione
legend('x^2');

% Secondo subplot
subplot(1,3,2);
plot(X, X.^3);
% Inserisci griglia
grid on
% Limita l'asse y ai valori tra -4 a 4
ylim([-4 4]);
% Nomina gli assi
xlabel('x');
ylabel('y');
% Inserisci legenda con nome della funzione
legend('x^2');

% Terzo subplot
subplot(1,3,3);
plot(X, X.^4);
% Inserisci griglia
grid on
% Limita l'asse y ai valori tra -4 a 4
ylim([-4 4]);
% Nomina gli assi
xlabel('x');
ylabel('y');
% Inserisci legenda con nome della funzione
legend('x^2');

%% Punto D

% D. Immagine con il grafico della funzione y=0.5*x con x∈[0,100], e lo 
%    stesso grafico fatto con scala logaritmica sull’asse y (i due grafici 
%    non devono essere sovrapposti).

% Creazione vettore X da 0 a 100 con step 1
X = 0:1:100;

% Crea la figure (finestra) del grafico con posizione dell'angolo in basso
% sinistra (200,200) dello schermo del PC, e con dimensione 900x300 piXl.
% In questo modo i grafici NON risultano "stirati" in altezza e quindi
% visivamente migliori da osservare.
f = figure('Position', [200 200 1100 400]);

% Creazione di due subplot, 1 riga e due colonne per far si che non siano
% sovrapposti i grafici

subplot(1,2,1);
% Stampa grafico con assi in scala normale
plot(X, (0.5).^X);
% Inserisci grilia
grid on
% Limita l'asse y da 0 a 0.5
ylim([0 0.5]);
% Nomi degli assi
xlabel('x');
ylabel('y');
% Inserisce titolo del subplot
subtitle('(1/2)^x');

subplot(1,2,2);
% Stampa grafico con asse y in scala logaritmica
semilogy(X, (0.5).^X);
% Inserisci griglia
grid on
% Nomi degli assi
xlabel('x');
ylabel('y');
% Inserisce titolo al subplot
subtitle('(1/2)^x con asse y in scala logaritmica');


%% Punto E

% E. Immagine con i grafici delle funzioni y=x^k conx∈[1,1000] e 
%    k∈{2,1,0.5} sovrapposti con colori diversi.

% Creazione vettore X con valori da 1 a 1000 con step 0.1
X = 1:0.1:1000;
% Creazione vettore k, che rappresenta l'insieme k
k = [2 1 0.5];

figure;

plot(X, X.^k(1),'r');

% Inizio creazione grafico
hold on

% Titolo del grafico, \in è il simbolo "appartiene" in LaTex
title('Grafico x^k con k\in\{2,1,0.5\}')

% Inserisci griglia
grid on

% Nomina gli assi
xlabel('x');
ylabel('y');

% Stampa i tre grafici colorati rispettivamente di rosso, blu e giallo
plot(X, X.^k(2),'b');
plot(X, X.^k(3),'y');

% Inserisci legenda del grafico
legend('x^2','x','\surdx');

hold off

%% Punto F

% F. Come nel punto E ma usando la scala logaritmica sia sull’asse x che 
%    sull’asse y.

% Creazione vettore X con valori da 1 a 1000 con step 0.1
X = 1:0.1:1000;
% Creazione vettore k, che rappresenta l'insieme k
k = [2 1 0.5];

figure;

loglog(X, X.^k(1),'r');

hold on
% Stampa i tre grafici colorati rispettivamente di rosso, blu e giallo
% con entrambi gli assi in scala logaritmica
loglog(X, X.^k(2),'b');
loglog(X, X.^k(3),'y');

% Titolo del grafico, \in è il simbolo "appartiene" in LaTex
title('Grafico x^k con k\in\{2,1,0.5\} in scala logaritmica')

% Inserisci griglia
grid on

% Limita l'asse x da 1 a 1000 e l'asse y da 0 a 1000
axis([1 1000 0 10^5])

% Nomina gli assi
xlabel('x');
ylabel('y');

% Inserisci legenda del grafico
legend('x^2','x','\surdx');