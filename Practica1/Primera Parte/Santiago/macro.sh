#!/bin/bash
echo "" >> salida_burbuja.dat
i="1000"
while [ $i -lt 26000 ]
do
  ./burbuja $i >> salida_burbuja.dat
  ((i+=1000))
done
#Ahora insercion
echo "" >> salida_insercion.dat
i="1000"
while [ $i -lt 26000 ]
do
  ./insercion $i >> salida_insercion.dat
  ((i+=1000))
done
