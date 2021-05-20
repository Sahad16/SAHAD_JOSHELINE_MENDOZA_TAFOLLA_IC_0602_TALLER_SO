#!/bin/bash
ROOT_UID=0
SUCCESS=0

if [ "$UID" -ne "$ROOT_UID" ]
then
	echo "Estar como root para ejecutar script"
	exit $$E_NOTROOT
fi

file=$1

if [ "${file}X" = "X" ];
then
	echo "Indicar archivo del listado de  grupos a eliminar..."
	exit 1
fi

eliminarGrupo(){
	eval nombreGrupo="$1"
	groupdel "${nombreGrupo}"
	if [ $? -eq $SUCCESS ];
	then
		echo "Grupo [${nombreGrupo}] eliminado correctamente"
	else
		echo "Grupo [${nombreGrupo}] no se pudo eliminar o no existe"
	fi
}

while IFS=: read -r f1
do
	eliminarGrupo "\${f1}"
done < ${file}

exit 0
