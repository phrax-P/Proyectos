clear;clc;
%Matrices de MVE
A = [-38.6555, 0, -2.6331, 0; 14.7350, -28.9250, 0.9968, 0; 122.8101, 57.6415, -35.1792, 30.8285; 0, 0, 86.6880, -86.6880];
B = [0.2970, 0;-0.1090,0;-0.9290,0;0,0.1];
C = [0,1,0,0;0,0,1,0];
D = [0,0;0,0];
%Funcion transferencia
MVE = ss(A,B,C,D);
H = tf(MVE);
%Condiciones iniciales
xa0 = [2.1304 1.0903 387.34 386.06];
%Polos zeros
f1 =figure();
iopzmap(H)
%Entrada escalon
opt = stepDataOptions;
opt.StepAmplitude = 1;
f2 = figure();
step(H,opt)
%Respuesta frecuencia
w = logspace(-2,5,1e4);
G = freqresp(H(2,1),w,'rad/s');
mag = zeros(1,length(G));
mag = reshape(abs(G),[],1);
% semilogx(w,mag)
%BODE
f3 = figure();
bode(H)