#!/bin/csh

@ inicio = 10
@ fin = 36
@ incremento = 1

@ i = $inicio
echo > salida_hanoi.dat
while($i <= $fin)
echo Ejecución tam = $i
echo `./hanoi $i` >> salida_hanoi.dat
@ i += $incremento
end
