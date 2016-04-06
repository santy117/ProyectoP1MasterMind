#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jugar_partida.h"


void caratula(){
	for (int i=0;i<3;i++){
		for (int j=0;j<105;j++){
			printf("*");

		}
		printf("\n");
	}
	printf("********************************		MASTER	MIND		*********************************\n");

	for (int i=0;i<3;i++){
		for (int j=0;j<105;j++){
			printf("*");

		}
		printf("\n");

	}
}



int main(int argc,char* argv[]){

	char respuesta;
	char numero;

	caratula();

	do{
	printf("\n1)Jugar partida\n2)Jugar partida de prueba\n3)Establecer nivel de dificultad\n4)Listar historial de partidas\n0)Salir del programa\n\nSiguiente operacion?\n");
	scanf(" %c",&numero);
	
		switch(numero){
			case '1':
					system("clear");
					printf("-Has seleccionado jugar partida.\n");
					partida();
					break;
			case '2':
					system("clear");
					printf("-Has seleccionado jugar partida de prueba.\n");
					break;
			case '3':
					system("clear");
					printf("-Has seleccionado establecer nivel de dificultad.\n");
					break;
			case '4':
					system("clear");
					printf("-Has seleccionado listar el historial de partidas.\n");
					break;
			case '0':
					printf("Quieres salir del programa?(s/n)\n");
					scanf(" %c",&respuesta);
					if(respuesta=='s'|| respuesta=='S'){
						printf("Has seleccionado s. \n");
						}else if(respuesta=='n'||respuesta=='N'){
						printf("Has seleccionado n. \n");
						}else{
							printf("Caracter incorrecto. \n)");
							}
					break;
			default:
					printf("Caracter incorrecto.Volviendo al menu...\n");
					break;
		}
	
	}while(respuesta!='s' && respuesta!='S');
	
	


	return 0;
}








