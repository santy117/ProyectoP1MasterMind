#! /bin/csh -f
#
# Recibe un argumento: el nombre del programa que queremos evaluar, y que
# contiene la versión básica del proyecto Master Mind
#
# Asume la existencia de un Makefile con reglas para generar el objetivo dado
# por dicho nombre de programa.
#
# De no ser así, es decir, si no se genera dicho programa, sale dando el
# correspondiente mensaje de error.
#
# Autor: Pedro Rodríguez
#

if ($#argv != 1) then
cat << end-of-help-message
   uso: $0 programa
	  programa    nombre del programa que queremos evaluar
end-of-help-message
exit(-1)
endif

set PROGRAMA=$1

echo
echo "Protocolo para evaluar un programa que contiene"
echo "la versión básica del proyecto Master Mind"
echo
echo "Limpiamos el escenario"
make clean
rm -f partidas.txt mis_partidas0[12].txt mi_salida0[12].txt
echo
echo "Construimos la aplicación"
make ${PROGRAMA}
echo

if ! (-e ${PROGRAMA}) then
  echo "El programa ${PROGRAMA} no existe"
  exit(-2)
else if ! (-x ${PROGRAMA}) then
  echo "El programa ${PROGRAMA} no se puede ejecutar"
  exit(-3)
else
  echo "Ejecutamos la batería de pruebas"
  ./${PROGRAMA} < proto01.txt > mi_salida01.txt
  mv -f partidas.txt mis_partidas01.txt
  ./${PROGRAMA} < proto02.txt > mi_salida02.txt
  mv -f partidas.txt mis_partidas02.txt

  echo
  echo "Comparamos los ficheros de historial generados por el programa"
  echo "que hemos evaluado con los que deberían haberse generado,"
  echo "y mostramos las diferencias (si las hay)"
  echo

  foreach fichero ( partidas*.txt )
    echo ${fichero}
    diff -Bw ${fichero} mis_${fichero}
  end

  echo
  echo "Comparamos los ficheros de salida generados por el programa"
  echo "que hemos evaluado con los que deberían haberse generado,"
  echo "y mostramos las diferencias (si las hay)"
  echo

  foreach fichero ( salida*.txt )
    echo ${fichero}
    diff -Bw ${fichero} mi_${fichero}
  end
  echo
endif
