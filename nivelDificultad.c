#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int nivelDificultad(int nivelActual)
{
	char slevel[9];
	int nuevoNivel;
	int nivelValido=1;
	int i;

	fprintf(stdout,"Nivel actual: %i\n",nivelActual);

	do{
		nivelValido=1;
		fprintf(stdout,"Elige un nuevo nivel [1..100]: ");
		if (fgets(slevel,10,stdin)==NULL){
			nivelValido=0;
			continue;
		}
	for(i=0; i<strlen(slevel)-1;i++){
		if(!isdigit(slevel[i])){
			nivelValido=0;
			break;
		}
	}
	if(nivelValido){
		slevel[strlen(slevel)-1]='\0';
		nuevoNivel=atoi(slevel);
		if((nuevoNivel<1)||(nuevoNivel>100)){
			nivelValido=0;
		}
	}
	if(nivelValido){
		fprintf(stdout,"Nivel seleccionado no valido.\n");

	}
	}while(!nivelValido);
	fprintf(stdout,"\nNivel seleccionado: %i\n",nuevoNivel);

	return nuevoNivel;

}