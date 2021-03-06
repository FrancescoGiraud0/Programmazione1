%% Esercizio A

clc;
clear all;
close all;

% Creazione meshgrid con valori tra -2 e 2 con step 0.2
[X, Y] = meshgrid(-2: 0.2 : 2);

% Calcolo vettore Z 
Z = X.^2+Y.^2;

% Creo nuova finestra con dimensione 1100x400 in posizione (200,200)
% dello schermo
f = figure('Position', [200 200 1100 400]);

% Primo subplot
subplot(1,2,1);

% Grafico mesh + isolinee con colorbar
meshc(X, Y, Z),
colorbar,
title('f(x,y)=x^2+y^2 meshc(mesh+isolinee)'),
xlabel('x'),
ylabel('y'),
zlabel('z');

% Secondo subplot
subplot(1,2,2);

% Grafico surf con colorbar
surf(X, Y, Z),
colorbar,
title('f(x,y)=x^2+y^2 surf'),
xlabel('x'),
ylabel('y'),
zlabel('z');
