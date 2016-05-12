#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "jugar_partida.h"
#include "lista_partidas.h"
#include "nivelDificultad.h"


void caratula(){
	int i,j;
	for (i=0;i<3;i++){
		for (j=0;j<80;j++){
			printf("*");

		}
		printf("\n");
	}
	printf("********************************  MASTER MIND  *********************************\n");

	for (i=0;i<3;i++){
		for (j=0;j<80;j++){
			printf("*");

		}
		printf("\n");

	}
}



int main(int argc,char* argv[]){
	int i;
	char respuesta='n';
	char numero[10];
	int num;
	int opvalida=1;
	int dificultad=100,difaux=100;
	caratula();
	do{
	
	do{
	opvalida=1;
	printf("\n1) Jugar partida\n2) Jugar partida de prueba\n3) Establecer nivel de dificultad\n4) Listar historial de partidas\n0) Salir\n\n¿Siguiente operación?\n");
	if (fgets(numero,10,stdin)==NULL){
			opvalida=0;
			continue;
		}
	for(i=0; i<strlen(numero)-1;i++){
		if(!isdigit(numero[i])){
			opvalida=0;
			break;
		}
	}
	if(opvalida){
		numero[strlen(numero)-1]='\0';
		num=atoi(numero);
	}else{
		
		fprintf(stdout,"Opcion no valida.\n");
	}
	}while(!opvalida);
	
		switch(num){
			case 1:
					
					
					partida(1,dificultad);
					break;
			case 2:
					
					partida(2,dificultad);
					break;
			case 3:
					
					
					difaux=nivelDificultad(dificultad);
					dificultad=difaux;
					// do{
					// printf("Introduzca el nivel de dificultad(De 1 a 100 intentos):\n");
					// printf("Nivel actual:%i\n",dificultad);
					// scanf("%i",&difaux);
					// 	if(dificultad<1 || dificultad>100){
					// 		printf("No has introducido un valor correcto.Repita el numero.\n");
					// 	}
					// }while(difaux<1 || difaux>100);
					// dificultad=difaux;
					break;
			case 4:
					
					
					lista_partidas();
					break;
			case 0:
					respuesta='s';
					break;
			default:
					
					printf("Opcion no valida.\n");
					break;
		}
	
	}while(respuesta!='s' && respuesta!='S');
	
	


	return 0;
}








