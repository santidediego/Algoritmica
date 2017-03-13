#!/bin/bash
echo "Burbuja"
echo "" >> salida_burbuja.dat
i="1000"
while [ $i -lt 26000 ]
do
  ./burbuja $i >> salida_burbuja.dat
  ((i+=1000))
done
echo "Ahora insercion"
echo "" >> salida_insercion.dat
i="1000"
while [ $i -lt 26000 ]
do
  ./insercion $i >> salida_insercion.dat
  ((i+=1000))
done
echo "Ahora seleccion"
echo "" >> salida_seleccion.dat
i="1000"
while [ $i -lt 26000 ]
do
  ./seleccion $i >> salida_seleccion.dat
  ((i+=1000))
done
echo "Ahora mergesort"
echo "" >> salida_mergesort.dat
i="1000"
while [ $i -lt 26000 ]
do
  ./mergesort $i >> salida_mergesort.dat
  ((i+=1000))
done
echo "Ahora heapsort"
echo "" >> salida_heapshort.dat
i="1000"
while [ $i -lt 26000 ]
do
  ./heapsort $i >> salida_heapshort.dat
  ((i+=1000))
done
echo "Ahora quicksort"
echo "" >> salida_quicksort.dat
i="1000"
while [ $i -lt 26000 ]
do
  ./quicksort $i >> salida_quicksort.dat
  ((i+=1000))
done
echo "Ahora floyd"
echo "" >> salida_floyd.dat
i="100"
while [ $i -lt 2600 ]
do
  ./floyd $i >> salida_floyd.dat
  ((i+=100))
done
echo "Ahora Hanoi"
echo "" >> salida_hanoi.dat
i="1"
while [ $i -lt 30 ]
do
  ./hanoi $i >> salida_hanoi.dat
  ((i+=1))
done
