# -*- coding: utf-8 -*-
"""
Created on Sun May 16 17:53:33 2021

@author: kenny
"""

import matplotlib.pyplot as plt
import numpy as np
import math as mt


lista = []
x = np.linspace(0,10)
for i in x:
    lista.append(i*i*i*i*i/5 + 0.5*i*i*i/3 - 3*i*i)
plt.plot(x,lista,label='f(x)')
plt.ylabel("f(x)")
plt.xlabel("x")
plt.legend()
plt.show()
plt.savefig('./Grafico.png', dpi=300)
plt.close()

def graficar(x,y,nombre):
    lista = []
    x2 = np.linspace(0,10)
    for i in x2:
        lista.append(i*i*i*i*i/5 + 0.5*i*i*i/3 - 3*i*i)
    plt.plot(x2,lista,label='f(x)')
    plt.plot(x,y,label='Metodo Euler')
    plt.legend()
    plt.show()
    plt.savefig(nombre, dpi=300)
    
y = [0.000,0.250,0.500,0.750,1.000,1.250,1.500,1.750,2.000,2.250,2.500,2.750,3.000,3.250,3.500,3.750,4.000,4.250,4.500,4.750,5.000,5.250,5.500,5.750,6.000,6.250,6.500,6.750,7.000,7.250,7.500,7.750,8.000,8.250,8.500,8.750,9.000,9.250,9.500,9.750,10.000,10.250]
x2 = [1.000,1.000,0.629,-0.093,-1.111,-2.311,-3.497,-4.369,-4.496,-3.296,-0.011,6.317,16.868,33.068,56.613,89.491,134.008,192.808,268.899,365.678,486.947,636.947,820.373,1042.401,1308.712,1625.512,1999.560,2438.188,2949.326,3541.526,4223.983,5006.562,5899.815,6915.016,8064.170,9360.048,10816.205,12447.005,14267.644,16294.172,18543.520,21033.520]
graficar(y,x2,"3")