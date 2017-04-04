#!/bin/csh

@ inicio = 1000000
@ fin = 26000000

@ i = $inicio
echo > salida_unimodal_dyv.dat
while($i <= $fin)
echo Ejecución tam = $i
echo `./unimodal $i` >> salida_unimodal_dyv.dat
@ i += 1000000
end
