% Punto D

clc;
clear all;
close all;

% Numero di elementi del vettore da generare
n_el = 9000000;

% Genera un vettore di n_el elementi casuali compresi tra 0 e 1000
V = randi([0,1000], 1, n_el);

% Inizializza valore sommatoria 
sommatoria = 0;

% Inizia misurazione tempo di esecuzione ciclo for
tic

% Cicla per ogni elemento nel vettore
for j=1:n_el
    % Aggiungi il valore dell'elemento alla sommatoria
    sommatoria = sommatoria + V(j);
end

% Crea variabile dove salvare il valore della media
media_for = 0;

% Controlla che n_el sia > 0 (per evitare divisioni per zero)
if (n_el > 0)
    media_for = sommatoria / n_el;
end

% Fine misurazione ciclo for e salva il valore
t_end_for = toc;

% Inizio misurazione mean()
tic
media_mean = mean(V);

% Fine misurazione e salva il valore
t_end_mean = toc;

% Stampa le medie ottenute
disp('Media con ciclo for: ');
disp(media_for);
disp('Media con mean(): ');
disp(media_mean);

% Stampa i tempi di esecuzione
disp('Tempo esecuzione con ciclo for: ');
disp(t_end_for);
disp('Tempo esecuzione funzione mean(): ');
disp(t_end_mean);