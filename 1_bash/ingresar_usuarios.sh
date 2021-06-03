#!/bin/bash
ROOT_UID=0
SUCCESS=0


if [ "$UID" -ne "$ROOT_UID" ]
then
	echo "Estar como root"
	exit $$E_NOTROOT
fi

file=$1

if [ "${file}X" = "X" ];
then
	echo "indicar archivo de listado de usuarios a ingresar"
	exit 1
fi

crearUsuarios(){
	eval username="$1"
	eval password="$2"
	eval userID="$3"
	eval groupID="$4"
	eval userIDInfo="$5"
	eval homeDirectory="$6"
	eval shell="$7"
	
	if grep -q ${groupID} /etc/group
	then
		echo "El ID del grupo es: ${groupID} si existe"
	
		if grep -q ${username} /etc/passwd
		then
			echo "El usuario ${username} ya está registrado"
		else
			echo "Se crea el usuario ${username}"
	      		useradd -c "${userID} ${userIDInfo}" -p "${password}" -d "${homeDirectory}""${username} -s "${shell} "${username}" -u "${groupID}"
		      	echo "Usuario: ${username} creado" 
		 	echo "Usuario: ${username} Contraseña: ${password}"
		fi
	else 
		echo "El ID del grupo ${groupID} no existe"
	fi
}
while IFS=: read -r f1 f2 f3 f4 f5 f6 f7
do
	crearUsuarios "\${f1}" "\${f2}" "\${f3}" "\${f4}" "\${f5}" "\${f6}" "\${f7}"
done < ${file}
exit 0