#!/bin/csh

@ inicio = (1048576)
@ fin = (1073741824)

@ i = $inicio
echo > salida_unimodal_sec.dat
while($i <= $fin)
echo Ejecución tam = $i
echo `./divide $i` >> salida_divide_sec.dat
@ i *= 2
end
