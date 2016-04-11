
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

void partida(){
	char cadena[5];
	int i,contador,correcto=0;
	int control_errores;
	int n_aleat[5],cadena_int[5];
	srand(time(NULL));//srand evita que vuelvan a salir los mismos numeros
		do{
		for(int i=0;i<4;i++){
			n_aleat[i]=(rand()%10); 
		 } // genera numeros de -10 a 10
		}while(n_aleat[0]==n_aleat[1] || n_aleat[0]==n_aleat[2] || n_aleat[0]==n_aleat[3] || n_aleat[1]==n_aleat[2] || n_aleat[1]==n_aleat[3] || n_aleat[2]==n_aleat[3]);
	
	printf("Numero secreto: ");
	for(int i=0;i<4;i++){
		printf(" %i",n_aleat[i]); //para double %e o %d
	}
	printf("\n\n");
for(contador=1;contador<100;contador++){
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
	printf("Numero secreto: ");
	for(int j=0;j<4;j++){
		cadena_int[j]=cadena[j]-48;
		
		
		if(cadena_int[j]==n_aleat[j]){
			printf("*");
			correcto++;
		}
		if(cadena_int[j]!=n_aleat[j]){
			printf("_");
		}
	

	}
	printf("\n");
	if (correcto==4){

		printf("Solucionado tras %d intentos.\n",contador);
		return;
	}

}

}