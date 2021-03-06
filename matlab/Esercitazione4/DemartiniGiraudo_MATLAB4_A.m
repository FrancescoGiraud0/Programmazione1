%% Punto A

clc;
clear all;
close all;

n_righe = 10; % numero di righe della matrice
n_colonne = 30; % numero di colonne della matrice

% Genera matrice 10x30 di valori casuali tra 0 e 1 ed assegna a M
M = rand(n_righe, n_colonne);

% Inizializza le variabili delle somme a 0
sum_magg = 0; % somma dei valori > 0.5
sum_min = 0; % somma dei valori <= 0.5

% Ciclo per ogni riga da 1 fino a n_righe, i -> indice riga
for i=1:n_righe
    % Ciclo per ogni colonna da 1 fino a n_colonne, j -> indice colonna
    for j=1:n_colonne
        % Prende il valore della matrice M in posizione (i,j)
        if(M(i,j) > 0.5)
            sum_magg = sum_magg + M(i,j); % Aggiunge a sum_magg se > 0.5
        else
            sum_min = sum_min + M(i,j); % Aggiunge a sum_min se <= 0.5
        end
    end
end

% Verifico che la somma di sum_magg sia > di sum_min
% Stampo messaggio per ogni possibile caso
if(sum_magg > sum_min)
    disp('La somma dei maggiori di 0.5 è MAGGIORE');
    disp([num2str(sum_magg) ' > ' num2str(sum_min)]);
else
    if (sum_magg == sum_min)
        disp('Le due somme sono UGUALI');
        disp([num2str(sum_magg) ' == ' num2str(sum_min)]);
    else
        disp('La somma dei maggiori di 0.5 è MINORE');
        disp([num2str(sum_magg) ' < ' num2str(sum_min)]);
    end
end
