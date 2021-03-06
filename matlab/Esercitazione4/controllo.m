% La seguente funzione restistuisce TRUE se la parola in input è 'segreta'
% La funzione NON è case sensitive, ovvero non importa se la parola è
% scritta in caratteri maiuscoli o minuscoli (strcmpi)
function indovinato = controllo(parola)
    indovinato = strcmpi('segreta', parola);
end
