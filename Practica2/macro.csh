#!/bin/csh

@ inicio = 1000000
@ fin = 26000000

@ i = $inicio
echo > salida_unimodal_sec.dat
while($i <= $fin)
echo Ejecución tam = $i
echo `./unimodal_secuencial $i` >> salida_unimodal_sec.dat
@ i += 1000000
end
