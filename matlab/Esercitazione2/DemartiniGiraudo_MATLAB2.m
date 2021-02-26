%% Punto A

% A. Grafico della funzione arcotangente nell’intervallo [-4, 4].

Xa = -4:0.1:4;
Ya = atan(Xa);

hold on

title('Grafico arcotangente');

grid on;

xlabel('x');
ylabel('y');

plot(Xa, Ya);

hold off

%% Punto B

% B. Immagine con i grafici di (1/2)*sin(x), sin(x) e 2*sin(x) sovrapposti 
%    nell’intervallo [−2*pi, 2*pi].

Xb = -2*pi:0.1:2*pi;
SEN = sin(Xb);

hold on

% Limite assi
axis([-2*pi 2*pi -2.5 2.5]);

% Inserisci griglia
grid on

% Titolo grafico
title('Grafici Seno', 'fontsize', 18);
xlabel('x');
ylabel('y');

% Grafico 1 -> 1/2 sin(x)
plot(Xb, (0.5)*SEN, '-.r');

% Grafico 2 -> sin(x)
plot(Xb, SEN, '--b');

% Grafico 3 -> 2sin(x)
plot(Xb, 2*SEN, '-y');

% Legenda grafico
legend('(1/2)sin(x)', 'sin(x)', '2sin(x)');

hold off

%% Punto C

% C. Immagine con tre sottografici, che rappresentano rispettivamente x^2, 
%    x^3 e x^4 nell’intervallo [-2, 2].

Xc = -2:0.1:2;

subplot(3,1,1);
plot(Xc, Xc.^2);
xlabel('x');
ylabel('y');
legend('x^2');

subplot(3,1,2);
plot(Xc, Xc.^3);
xlabel('x');
ylabel('y');
legend('x^3');

subplot(3,1,3);
plot(Xc, Xc.^4);
xlabel('x');
ylabel('y');
legend('x^4');

%% Punto D

% D. Immagine con il grafico della funzione y=0.5*x con x∈[0,100], e lo 
%    stesso grafico fatto con scala logaritmica sull’asse y (i due grafici 
%    non devono essere sovrapposti).

Xd = 0:0.1:100;

subplot(1,2,1);
plot(Xd, (0.5).^Xd);
xlabel('x');
ylabel('y');

subtitle('0.5^x scala normale');

subplot(1,2,2);
semilogy(Xd, (0.5).^Xd);
xlabel('x');
ylabel('y');

subtitle('0.5^x scala logaritmica');


%% Punto E

% E. Immagine con i grafici delle funzioni y=x^k conx∈[1,1000] e 
%    k∈{2,1,0.5} sovrapposti con colori diversi.

Xe = 1:0.1:1000;
k = [2 1 0.5];

hold on

title('Grafico x^k con k\in\{2,1,0.5\}')

axis([1 1000 0 1000])

grid on

xlabel('x');
ylabel('y');

plot(Xe, Xe.^k(1), 'r');
plot(Xe, Xe.^k(2),'b');
plot(Xe, Xe.^k(3),'y');

legend('x^2','x','\surdx');

hold off

%% Punto F

% F. Come nel punto E ma usando la scala logaritmica sia sull’asse x che 
%    sull’asse y.

Xf = 1:0.1:1000;
k = [2 1 0.5];

hold on

title('Grafico in scala logaritmica')

axis([1 1000 0 1000]);

grid on

xlabel('x');
ylabel('y');

loglog(Xf, Xf.^k(1),'r');
loglog(Xf, Xf.^k(2),'b');
loglog(Xf, Xf.^k(3),'y');

legend('x^2','x','\surdx');

hold off
