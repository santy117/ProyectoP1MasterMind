
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void partida(){
	char cadena[5];
	int i;
	int control_errores;
do{
	control_errores=0;
	printf("Introduzca una cadena de 4 digitos[_ _ _ _]\n");
	scanf(" %s", cadena);
	if(cadena[4]!='\0'){
		printf("La cadena no tiene 4 digitos\n");
		control_errores=1;
	}
	for(i=0;i<4;i++){
		if(cadena[i]>='0' && cadena[i]<='9'){
		}
		else{
		printf("%c no es digito\n", cadena[i]);
		control_errores=1;
		}
	}
}while(control_errores==1);

printf("\n\t|        |\n\t|        |\n\t|        |\n\t|        |\n\t|        |\n\t|        |\nIntroduzca un numero:    ");
}