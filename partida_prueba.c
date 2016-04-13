
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

void partida_prueba(){
	char cadena[5];
	int i,contador,correcto=0;
	int control_errores;
	int numero[5],cadena_int[5];

		printf("Esto es una partida de prueba, que genera un numero aleatorio predefinido.\n");
	
		for(int i=0;i<4;i++){
			numero[i]=(i+1); 
		 }
	
	printf("Numero secreto: ");
	for(int i=0;i<4;i++){
		printf(" %i",numero[i]); //para double %e o %d
	}
	printf("\n\n");

// Control de errores a la hora de introducir una cadena
for(contador=1;contador<=100;contador++){
	do{
		correcto=0;
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

	// Aciertos o fallos de la seleccion de numero
	}while(control_errores==1);
	printf("Numero secreto:    <");
	for(int j=0;j<4;j++){
		cadena_int[j]=cadena[j]-48;
		
		
		if(cadena_int[j]==numero[j]){
			printf("*");
			correcto++;
		}
		if(cadena_int[j]!=numero[j]){
			printf("_");
		}

	}
	printf(">.\n");

	//Puntuacion del juego
	if (correcto==4){

		printf("Solucionado tras %d intentos.\n",contador);
		if(contador<3){
			printf("Felicidades, has conseguido una puntuacion de: 10 pts.\n");
		}else if(contador>11){
			printf("Puntuacion obtenida: 0.\n");

		}else{
			float puntuacion=10-10*(contador-3)/9;
			printf("Puntuacion obtenida: %.2f.\n",puntuacion);
		}
		return;
	}

}

}