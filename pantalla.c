//LADOS,BASE,TITULO,CONFIRMAR!!

#include "pantalla.h"

void base(int num_caracteres, char carac){
  int k;
  for(k=0;k<num_caracteres;k++){
  printf("%c",carac);
  }
  printf("\n");
  return;
}

void lados(int num_lineas, int num_caracteres, char carac){
  int k,i;
  for(i=0;i<num_lineas;i++){
  printf("%c",carac);
    for(k=0;k<num_caracteres-2;k++){
      printf(" ");
    }
  printf("%c",carac);
    printf("\n");
  }
  return;
}

void titulo(int num_caracteres,char carac,char *frase){
  int k;
  printf("%c",carac);
  for(k=0;k<(num_caracteres-2-strlen(frase))/2;k++){
    printf(" ");
  }
  printf("%s",frase);
  for(k=0;k<(num_caracteres-2-strlen(frase))/2;k++){
    printf(" ");
  }
  printf("%c",carac);
  printf("\n");
  return;
}

int confirmar(){
  char cad[10];
  int i,j,k;
  printf("\nSeguro que deseas salir del programa? (s/n):\n");
  fgets(cad,sizeof(cad),stdin);
  i=strlen(cad);
    
  if(cad[i-1]!='\n'){
    while(fgetc(stdin)!='\n');
  }    
  j=0;
  k=0;   
  while(j<i){	
    if(cad[j]!=' ' && cad[j]!='\n'){
      cad[0]=cad[j];
      k++;
    }
    j++;
  }
    
  if((tolower(cad[0])!='s' && tolower(cad[0])!='n' ) || k!=1){
    return -1;
  }
  else{
    if(tolower(cad[0])=='s'){
      return 1;
    }
    else{
      return 0;
    }
  }
}
