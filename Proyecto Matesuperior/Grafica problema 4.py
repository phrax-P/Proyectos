# -*- coding: utf-8 -*-
"""
Created on Fri Jun 18 17:28:44 2021

@author: kenny
"""

import matplotlib.pyplot as plt
import numpy as np
import math as mt


lista = []
x = np.linspace(0,10)
for i in x:
    lista.append(i**5/5 + 0.2*i**3/3 - 3*i**2)
plt.plot(x,lista,label='f(x)')
plt.ylabel("f(x)")
plt.xlabel("x")
plt.legend()
plt.show()


def graficar(x,y,nombre):
    plt.plot(x,y,label=nombre)
    plt.legend()
    plt.show()
    #plt.savefig(nombre, dpi=300)
    
    
def m(x):
    nuevo = x.replace("\n","").split(",")
    lista = []
    for i in nuevo:
        if i=="":
            continue
        lista.append(float(i))
    return lista
    
    
file = open('./datos_rungen_kutta')
datos = file.readlines()
datos = datos[1:]

for i in range(0,len(datos),3):
    graficar(m(datos[i+1]),m(datos[i+2]),datos[i].replace("\n",""))