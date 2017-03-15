#!/bin/csh

@ inicio = 7500000
@ fin = 10000000
@ incremento = 100000

@ i = $inicio
echo > salida_heapsort.dat
while($i <= $fin)
echo Ejecución tam = $i
echo `./heapsort $i` >> salida_heapsort.dat
@ i += $incremento
end
