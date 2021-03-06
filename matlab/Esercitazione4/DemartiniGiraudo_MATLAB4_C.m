% Punto C

% Creo variabili booleana inizializzata a false per fare in modo da
% riuscire ad entrare nel ciclo while seguente
indovinato = false;

% Se indovinato == false, vuol dire che l'utente deve ancora inserire
% la prima parola oppure ha sbagliato nel ciclo precedente.
% Se indovinato == true, vuol dire che la parola è stata indovinata
% quindi non entrerà nuovamente nel ciclo e terminerà l'esecuzione.
while(indovinato==false)
    % Input della parola da parte dell'utente
    p_in = input('Inserire la parola segreta: ', 's');
    
    % Assegna alla variabile indovinato il risultato di controllo(p_in)
    indovinato = controllo(p_in);
    
    % Controlla se il valore di indovinato è == true
    if(indovinato)
        disp('HAI INDOVINATO!') % indovinato==true -> ha indovinato
    else
        disp('HAI SBAGLIATO! Ritenta sarai più fortunato') % indovinato==false -> ha sbagliato
    end
end

