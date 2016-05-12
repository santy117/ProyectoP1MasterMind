#include <stdio.h>

void lista_partidas(){
 FILE *pf;
 char escribir[13];
 pf=fopen("partidas.txt","r");

 
 if( pf==NULL ){
  printf("No puedo leer el fichero de historial (partidas.txt)\n");
  return;
 }
 while(feof(pf)==0){
 	while(fgets(escribir,13,pf)){
 		printf("%s",escribir);
 	}
 }
 return;
}