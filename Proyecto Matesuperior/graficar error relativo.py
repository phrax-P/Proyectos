# -*- coding: utf-8 -*-
"""
Created on Tue Jul  6 23:37:00 2021

@author: kenny
"""
import numpy as np
import matplotlib.pyplot as plt
import random


file = open('./datos.txt')
datos = file.readlines()
datos = datos[1:]
datos2 = []
lista2= []
color = ["#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])
             for i in range(len(datos))]
for i in datos:
    lista = i.replace("\n","").replace("\\\\", "").replace("   ","").split(" & ")
    for j in lista:
         lista2.append(float(j))
    lista2.append(abs(abs(lista2[3])-abs(lista2[4]))/-lista2[4]*100)
    datos2.append(lista2)
    lista2=[]
datos2.pop(4)
file.close()

for i in range(len(datos2)):
    
    plt.plot(datos2[i][5],datos2[i][0], marker="o", color=color[i],label=str(datos2[i][0]))
    
plt.ylabel("Valores de h")
plt.xlabel("Error relativo %")
plt.legend()
plt.show()