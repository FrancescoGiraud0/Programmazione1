% Punto E

clc;
clear all;
close all;

% Creo la funzione handle f
f = @(x) log(abs(sqrt(x+1)-3));

% Nuova figure
figure;

% Creo primo subplot con grafico completo funzione
subplot(1,2,1)

% Noto che il dominio della funzione è [-1,8)U(8,+inf) quindi faccio il
% plot da -1 a 20 (indicativo per far notare l'asintoto verticale in x=8)
% (Abbiamo notato che matlab stampa anche il grafico per valori minori di
% -1 in quanto la funzione abs() restituisce il valore del modulo per i numeri
% complessi, e dato che il modulo è sempre un valore reale positivo maggiore
% di zero quindi il logaritmo ha sempre soluzione)
fplot(f, [-1 20])
grid on;
xlabel('x');
ylabel('y');
title('f(x) = log($|\sqrt{x+1} -3|$)', 'Interpreter', 'latex');

% Trova i punti di zero della funzione nell'intervallo [0,5]
punti_di_zero = fzero(f, [0 5]);

% Secondo subplot con funzione nell'intervallo [0, 5]
subplot(1,2,2)
fplot(f, [0 5]);
grid on;
xlabel('x');
ylabel('y');
title('f(x) in [0,5] con punti di zero', 'Interpreter', 'Latex');

% Disegna sul subplot 2 appena disegnato
hold on;
% Disegna i punti di zero sul grafico con un punto rosso di dimensione 20
plot(punti_di_zero, f(punti_di_zero), 'r.', 'MarkerSize', 20);
hold off;
