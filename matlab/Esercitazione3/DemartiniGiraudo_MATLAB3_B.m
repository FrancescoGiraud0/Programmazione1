%% Esercizio B

clc;
clear all;
close all;

% Input del raggio da parte dell'utente
raggio = input('Inserire il raggio: ');

% Verifica che il raggio sia strettamente positivo
if(raggio > 0)
    % Se raggio positivo
    % Mostra area del cerchioinserito
    disp('Area del cerchio:');
    disp(pi*raggio^2);
    % Mostra circonferenza
    disp('Perimetro:');
    disp(2*pi*raggio);
else
    % Mostra errore in caso raggio inserito <= 0
    disp('Errore: inserito un raggio negativo')
end
    