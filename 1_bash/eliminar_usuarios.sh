#!/bin/bash
ROOT_UID=0
SUCCESS=0

if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Estar en root para ejecutar este script"
  exit $E_NOTROOT
fi  

file=$1

if [ "${file}X" = "X" ];
then
   echo "Indicar archivo con listado de usuarios a eliminar"
   exit 1
fi

eliminarUsuario(){
	#echo "Eliminar Usuario"
	eval user="$1"

	userdel -r "${user}"
	if [ $? -eq $SUCCESS ];
	then
		echo "Usuario [${user}] eliminado exitosamente"
	else
		echo "Usuario [${user}] No se pudo eliminar"
	fi
}

while IFS=: read -r f1
do
	eliminarUsuario "\${f1}"	
done < ${file}

exit 0