function sfun_mve(block)
% Plantilla para implementar modelos en variable de estado sencillos
% como una S-Function
% 
% El nombre del archivo y el de la función (ver linea 1) deben ser iguales

%
% Acá solo se llama a la función setup, no agregue nada más a esta función
% principal
%
setup(block);

% -------------------------------------------------------------------------
% Function: setup ===================================================
% Abstract:
% Acá se definen las caracterísiticas básicas del bloque de la S-function:
%   - Puertos de entrada
%   - Puertos de salida
%   - Definición de parámetros
%   - Opciones
%
%
function setup(block)

% Se registra el número de puertos de entrada y salida
block.NumInputPorts  = 2; % Cantidad de entradas
block.NumOutputPorts = 2; % Cantidad de salidas

% Setup port properties to be inherited or dynamic
block.SetPreCompInpPortInfoToDynamic;
block.SetPreCompOutPortInfoToDynamic;

% Propiedades de los puertos de entrada
block.InputPort(1).Dimensions        = 1;
block.InputPort(1).DatatypeID  = 0;  % double
block.InputPort(1).Complexity  = 'Real';
block.InputPort(1).DirectFeedthrough = true;

% Propiedades de los puertos de entrada
block.InputPort(2).Dimensions        = 1;
block.InputPort(2).DatatypeID  = 0;  % double
block.InputPort(2).Complexity  = 'Real';
block.InputPort(2).DirectFeedthrough = true;

% Propiedades de los puertos de salida
block.OutputPort(1).Dimensions       = 1;
block.OutputPort(1).DatatypeID  = 0; % double
block.OutputPort(1).Complexity  = 'Real';
block.OutputPort(1).SamplingMode = 'Sample';

% Propiedades de los puertos de salida
block.OutputPort(1).Dimensions       = 1;
block.OutputPort(1).DatatypeID  = 0; % double
block.OutputPort(1).Complexity  = 'Real';
block.OutputPort(1).SamplingMode = 'Sample';

% Número de parámetros
block.NumDialogPrms     = 1; % en este caso hay un parámetro de entrada

% Tiempo de muestreo
block.SampleTimes = [0, 0]; % Tiempo de muestreo heredado
% Definicion de la cantidad de variables de estado
block.NumContStates = 4; % En este caso, hay cuatro variables de estado
  
block.SimStateCompliance = 'DefaultSimState';
% -----------------------------------------------------------------
% Ahora se registran los métodos internos de la S-function
% -----------------------------------------------------------------
block.RegBlockMethod('InitializeConditions', @Inicializacion);
block.RegBlockMethod('Outputs', @Salidas);     
block.RegBlockMethod('Derivatives', @ModeloEstados);
block.RegBlockMethod('SetInputPortSamplingMode',@SetInputPortSamplingMode); % Necesario para tener dos salidas
%end setup

function Inicializacion(block)

block.ContStates.Data =  block.DialogPrm(1).Data; % esto lo que hace es
%             tomar el valor del estado inicial como si fuera un parámetro
%end Inicializacion

%
function Salidas(block)
% Acá se escribe las ecuaciones de salida
x = block.ContStates.Data; % el estado actual
u1 =  block.InputPort(1).Data; % el valor de la entrada 1 actual
u2 =  block.InputPort(2).Data; % el valor de la entrada 1 actual
block.OutputPort(1).Data = (x(2)); % En este caso, la salida 1 es y1=x2=cb
block.OutputPort(2).Data = (x(3)); % En este caso, la salida 1 es y1=x3=T
%end Salidas

function ModeloEstados(block)
% Acá se escribe la función que calcula las derivadas de las variables de
% estado
x = block.ContStates.Data; % el valor del estado actual
u1 =  block.InputPort(1).Data+1113.5; % el valor de la entrada 1 actual
u2 =  block.InputPort(2).Data-141.9; % el valor de la entrada 2 actual


%Inicio de Ecuaciones de estado
dx1dt =( -38.6555)*(x(1)-2.1304)+ (-2.6331)*(x(3)-387.34)+ (0.2960)*u2;

dx2dt = (14.7350)*(x(1)-2.1304)+ (-28.9250)*(x(2)-1.0903)+ (0.9968)*(x(3)-387.34)+ (-0.1090)*u2;

dx3dt =(122.8101)*(x(1)-2.1304)+ (57.6415)*(x(2)-1.0903)+ (-35.1792)*(x(3)-387.34)+ (30.8285)*(x(4)-386.06)+ (-0.9290)*u2;
dx4dt = (86.6880)*(x(3)-387.34)+ (-86.6880)*(x(4)-386.06)+ (0.1)*u1;

block.Derivatives.Data=[dx1dt;dx2dt;dx3dt;dx4dt]; % actualizacion del bloque de la S-function
%end ModeloEstados

function SetInputPortSamplingMode(s, port, mode)
s.InputPort(port).SamplingMode = mode;
s.OutputPort(1).SamplingMode = mode;
s.OutputPort(2).SamplingMode = mode;
%end SetInputPortSamplingMode



