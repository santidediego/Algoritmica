#!/bin/csh

@ inicio = 100
@ fin = 2600
@ incremento = 100

@ i = $inicio
echo > salida_floyd.dat
while($i <= $fin)
echo Ejecución tam = $i
echo `./floyd $i` >> salida_floyd.dat
@ i += $incremento
end
