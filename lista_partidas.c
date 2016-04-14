#include <stdio.h>

void lista_partidas(){
 FILE *pf;
 
 pf=fopen("partidas.txt","r");
 
 if( pf==NULL ){
  printf("Error al abrir el fichero\n");
  
 }else{
  while( !feof(pf) ){
   printf("%c",getc(pf));
	}
  }
 return;
}