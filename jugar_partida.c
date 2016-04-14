
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

void partida(int dificultad){
	char cadena[5];
	int i,contador,correcto=0;
	int control_errores;
	int n_aleat[5],cadena_int[5];
	srand(time(NULL));
	//Creacion de fichero
	FILE *pf;
	pf=fopen("partidas.txt","a");
	

	// Genera un numero aleatorio de 4 digitos que no se repiten entre ellos.
		do{
		for(int i=0;i<4;i++){
			n_aleat[i]=(rand()%10); 
		 } // genera numeros de -10 a 10
		}while(n_aleat[0]==n_aleat[1] || n_aleat[0]==n_aleat[2] || n_aleat[0]==n_aleat[3] || n_aleat[1]==n_aleat[2] || n_aleat[1]==n_aleat[3] || n_aleat[2]==n_aleat[3]);
	
	printf("Numero secreto: ");
	for(int i=0;i<4;i++){
		printf(" %i",n_aleat[i]); //para double %e o %d
		fprintf(pf," %i",n_aleat[i]);
	}
	printf("\n\n");
	fprintf(pf,"\n\n");

// Control de errores a la hora de introducir una cadena
for(contador=1;contador<=dificultad;contador++){
	do{
		correcto=0;
		control_errores=0;
		printf("Introduzca una cadena de 4 digitos[_ _ _ _]\n");
		scanf(" %s", cadena);
		if(cadena[4]!='\0'){
			printf("La cadena no tiene 4 digitos\n");
			control_errores=1;
		}else{
			for(i=0;i<strlen(cadena);i++){
				if(cadena[i]>='0' && cadena[i]<='9'){
				}else{	
				printf("%c no es digito\n", cadena[i]);
				control_errores=1;
				}
			}
		}

	// Aciertos o fallos de la seleccion de numero
	}while(control_errores==1);
	printf("Numero secreto:    <");
	fprintf(pf,"Numero secreto:    <");
	for(int j=0;j<4;j++){
		cadena_int[j]=cadena[j]-48;
		
		
		if(cadena_int[j]==n_aleat[j]){
			printf("*");
			fprintf(pf,"*");
			correcto++;
		}
		if(cadena_int[j]!=n_aleat[j]){
			printf("_");
			fprintf(pf,"_");
		}
	}
	printf(">.\n");
	fprintf(pf,">.\n");
	//Puntuacion del juego
	if (correcto==4){

		printf("Solucionado tras %d intentos.\n",contador);
		if(contador<3){
			printf("Felicidades, has conseguido una puntuacion de: 10 pts.\n");
			fprintf(pf,"Puntuacion:10pts.\n");
			fclose(pf);
			return;
		}else if(contador>11){
			printf("Puntuacion obtenida: 0.\n");
			fprintf(pf,"Puntuacion:0pts.\n");
			fclose(pf);
			return;
		}else{
			float puntuacion=10-10*(contador-3)/9;
			printf("Puntuacion obtenida: %.2f.\n",puntuacion);
			fprintf(pf,"Puntuacion: %.2f pts.\n",puntuacion);
			fclose(pf);
			return;
		}
	
	}
	
}
	fclose(pf);

	return;
}

