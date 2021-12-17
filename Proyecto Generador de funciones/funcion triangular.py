# -*- coding: utf-8 -*-
"""
Created on Wed Oct 13 18:43:46 2021

@author: kenny
"""
#Importar librerias
import matplotlib.pyplot as plt
import numpy as np

#Retornar los valores de la funcion triangular
def triang(x,T,s,m):
    #Valores siguientes de s--T/4, siendo s punto inicial
    if x<T/4+s and x>=s:
        return m*(x-s)
    #Valores de T/4+s--3T/4+s
    elif x>=T/4+s and x<3*T/4+s:
        return m*((T)/2+s - x)
    #Valores de 3T/4+s+s -- T+s
    elif x>=3*T/4+s and x<T+s:
        return m*(x-(T+s))
    
#Amplitud
A= 1
#Periodo
T= 0.5
#Desplazamiento
s=0
#Valores para graficar
#Intervalo [0,x] con 1000 muestras
X = np.linspace(0,10,10000)
y = []
val = []
#Pendiente
m = 4*A/T
for x in X:
    #Se termino un periodo, se iguala punto inicial con x
    if x >= T+s:
        s=x
    #Guardar los valores en array val
    val.append(triang(x,T,s,m))
#Incluir los valores del array val en y
y = np.append(y,val,axis=0)
#Graficar
plt.plot(X,y)





