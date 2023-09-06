import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import sys
import os

names = []
cants = []

for i in range(1,len(sys.argv),2):
	names.append(sys.argv[i])
	cants.append(int(sys.argv[i+1]))

y_pos = np.arange(len(names))

#Creamos la grafica pasando los valores en el eje X, Y, donde X = cantidad_usos y Y = lenguajes
plt.barh(y_pos, cants, align='center', alpha=0.5)
#Añadimos la etiqueta de nombre de cada lenguaje en su posicion correcta
plt.yticks(y_pos, names)
#añadimos una etiqueta en el eje X
plt.xlabel('Ancianos')
#Y una etiqueta superior
plt.title('Cantidad de ancianos por diagnostico')
plt.show()