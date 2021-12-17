# -*- coding: utf-8 -*-
"""
Created on Mon Jun 28 01:28:38 2021

@author: kenny
"""
import numpy as np
import matplotlib.pyplot as plt
def f(x):
    return x**2+x-1;
file = open('./datos_puntos_fijos')
datos = file.readlines()
datos = datos[1:]
lista =[i.split(",") for i in [datos[i-1][4:].replace("\n", "")+","+datos[i] for i in range(1,len(datos),2) ]]
lista2=[]
x=[]
y=[]
for i in lista:
    for j in i[:len(i)-1]:
        lista2.append(float(j))
    x.append(lista2)
    y.append(lista2[1:])
    lista2=[]
for i in range(4,5):
    for j in range(len(y[i])):
        if abs(x[i][j])>1e3 or abs(y[i][j])>1e3:
            continue
        else:
            plt.plot(x[i][j],y[i][j], marker="o")
        if j!=len(y[i])-1:
            plt.arrow(x[i][j],y[i][j],x[i][j+1]-x[i][j],0)
            plt.arrow(x[i][j+1],y[i][j],0,y[i][j+1]-y[i][j])
a = np.linspace(-5, 5,1000)
plt.plot(a,a,label="y=x")
plt.plot(a,f(a),label="g(x)")
plt.axvline(0,color="black")
plt.axhline(0, 0, 1,color="black")
plt.legend()
plt.show()


        


