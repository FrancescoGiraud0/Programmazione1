%% Esercizio C

% Funzione che restituisce un vettore dove il primo elemento è l'area,
% mentre il secondo è il perimetro di un cerchio dato il raggio in input.
% Se il raggio è <= 0 restituisce il vettore [-1 -1].
function areaperim = DemartiniGiraudo_MATLAB3_C(raggio)
    % Verifica che il raggio sia strettamente positivo
    if(raggio > 0)
        areaperim = [pi*(raggio^2) 2*pi*raggio];
    else
        % Restituisce vettore [-1 -1] in caso il raggio sia <= 0
        areaperim = [-1 -1];
    end
end