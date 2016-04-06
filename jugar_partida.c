
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

void partida(){
	char cadena[5];
	int i;
	int control_errores;
	int n_aleat[5];
	srand(time(NULL));//srand evita que vuelvan a salir los mismos numeros
	for(int i=0;i<4;i++){
		n_aleat[i]=(rand()%10);   // genera numeros de -10 a 10
	}
	printf("Numero secreto: ");
	for(int i=0;i<4;i++){
		printf(" %i",n_aleat[i]); //para double %e o %d
	}
	printf("\n\n");

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

}