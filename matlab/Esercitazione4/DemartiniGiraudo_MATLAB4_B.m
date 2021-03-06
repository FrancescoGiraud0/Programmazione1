% Script per provare la funzione controllo.m

% Input della parola da parte dell'utente, 's' per stringhe in input
p_in = input('Inserire la parola segreta: ', 's');

% Controlla il risultato di controllo(p_in)
if(controllo(p_in))
    disp('HAI INDOVINATO!') % Se controllo(p_in) restituisce true (1)
else
    disp('HAI SBAGLIATO!')  % Se controllo(p_in) restituisce false (0)
end