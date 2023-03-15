//BASE DE DATOS!!

#include "base_datos.h"


///////////////////////////////////////////////////////////////////////////
                               //LECTOR//
//////////////////////////////////////////////////////////////////////////


void lector(lector_t *lector,int *n){
  
  int i,j,k,continuar;
  char cad[60];

  do{
    continuar=0;
    
    printf("\nEscribe el nombre del lector: ");
    
    fgets(cad,sizeof(cad),stdin);
    i=strlen(cad);
    
    if(cad[i-1]!='\n'){
      while(fgetc(stdin)!='\n');
    }
    
    cad[i-1]='\0';
    i=strlen(cad);
    
    if(i==0){
      printf("\nCadena vacia\n");
      continuar=1;
    }
    else{
      if(i>50){
	printf("\nLongitud de la cadena excesiva\n");
	continuar=1;
      }else{
	k = 0;
	for(j=0;j<i;j++){
	  if(cad[j]==':'){
	    k++;
	  }
	}
	if(k!=0){
	    printf("\nCaracter invalido\n");
	    continuar=1;
	}
	for(j=0;j<*n;j++){
	  if(!(strcmp(lector[j].nombre,cad))){
	    printf("\nLector repetido\n");
	    return;
	  }
	}
      }
    }
  }while(continuar);

 
  lector[*n].codigo=lector[*n-1].codigo+1;
  strcpy(lector[*n].nombre,cad);

  printf("\nLector %s: asignado %hd\n",lector[*n].nombre,lector[*n].codigo);
  (*n)++;

  guardar_lectores(lector, *n);
  
}

///////////////////////////////////////////////////////////////////////////////
                       //REFERENCIA//
/////////////////////////////////////////////////////////////////////////////

void referencia(referencia_t *referencia,int *n){
int i,j,k,continuar;
  char cad[90];

  referencia[*n].signatura=referencia[*n-1].signatura+1;

  do{
    continuar=0;
    
    printf("\nEscribe el autor de la referencia: ");
    
    fgets(cad,sizeof(cad),stdin);
    i=strlen(cad);
    
    if(cad[i-1]!='\n'){
      while(fgetc(stdin)!='\n');
    }
    cad[i-1]='\0';
    i=strlen(cad);
    if(i==0){
      printf("\nCadena vacia\n");
      continuar=1;
    }
    else{
      if(i>50){
	printf("\nLongitud de la cadena excesiva\n");
	continuar=1;
      }
      else{
	k=0;
	for(j=0;j<i;j++){
	  if(cad[j]==':'){
	    k+=1;
	  }
	}
	if(k!=0){
	    printf("\nCaracter invalido\n");
	    continuar=1;
	}
      }
    }
  }while(continuar);
  
  strcpy(referencia[*n].autor,cad);

  do{
    continuar=0;
    
    printf("\nEscribe el titulo: ");
    
    fgets(cad,sizeof(cad),stdin);
    i=strlen(cad);
    
    if(cad[i-1]!='\n'){
      while(fgetc(stdin)!='\n');
    }
    cad[i-1]='\0';
    i=strlen(cad);
    if(i==0){
      printf("\nCadena vacia\n");
      continuar=1;
    }
    else{
      if(i>80){
	printf("\nLongitud de la cadena excesiva\n");
	continuar=1;
      }
      else{
	k=0;
	for(j=0;j<i;j++){
	  if(cad[j]==':'){
	    k++;
	  }
	}
	if(k!=0){
	    printf("\nCaracter invalido\n");
	    continuar=1;
	}
      }
    }
  }while(continuar);
  
  strcpy(referencia[*n].titulo,cad);

  do{
    continuar=0;
    
    printf("\nEscribe el anho: ");
    
    fgets(cad,sizeof(cad),stdin);
    i=strlen(cad);
    
    if(cad[i-1] != '\n'){
      while(fgetc(stdin) != '\n');
    }
    j=0;
    cad[i-1]='\0';
    i=strlen(cad);
    while(j<i){
      if(cad[j]!=' '){
	break;
      }
      j++;
    }
    
    cad[0]=cad[j];cad[1]=cad[j+1];cad[2]=cad[j+2];cad[3]=cad[j+3];cad[4]=cad[j+4];

    if(!(isdigit(cad[0])) || !(isdigit(cad[1])) || !(isdigit(cad[2])) || !(isdigit(cad[3])) || isdigit(cad[4])){
      printf("\nValor seleccionado incorrecto\n");
      continuar=1;
    }

    else{
      cad[4]='\0';
      k=atoi(cad);
      if(k<1450 || k>2017){
	printf("\nValor seleccionado incorrecto\n");
	continuar=1;
      }
    }
    
  }while(continuar);
  referencia[*n].anho=k;

  do{
    continuar=0; 
    printf("\nEscribe el tipo: ");
    fgets(cad,sizeof(cad),stdin);
    i=strlen(cad);
    if(cad[i-1]!='\n'){
      while(fgetc(stdin)!='\n');
    }
    if(i==1){
      printf("\nCadena vacia\n");
      continuar=1;
    }
    else{
      cad[i-1]='\0';
      i=strlen(cad);j=0;k=0;
      while(j<i){
	if(cad[j]!=' ' && k==1){
	  printf("\nLongitud de la cadena excesiva\n");
	  continuar=1;
	  k++;
	  break;
	}	
	if(cad[j]!=' ' && k==0){
	  cad[0]=cad[j];
	  k++;
	}
	j++;
      }
      if(k==1){
        cad[0]=toupper(cad[0]);
	if(cad[0]!='L' && cad[0]!='A'){
	  printf("\nCaracter invalido\n");
	  continuar=1;
	}
      }
    }
  }while(continuar);
  referencia[*n].tipo=cad[0];  

  
  printf("\nReferencia %c:%s:%s:%hd: asignada %hd\n", referencia[*n].tipo,referencia[*n].autor,referencia[*n].titulo,referencia[*n].anho,referencia[*n].signatura);
  (*n)++;

  guardar_referencias(referencia, *n);
 
  return;
}


//////////////////////////////////////////////////////////////////////////
                       //OBTENER INFORME//
/////////////////////////////////////////////////////////////////////////

void obtinf(referencia_t *referencia, lector_t *lector, int nr, int nl){
  int i,j,k;
  int cont;
  char cad[90];

  do{
    cont=0;
    
    printf("\nEscribe la signatura: ");
    
    fgets(cad,sizeof(cad),stdin);
    i=strlen(cad);
    if(cad[i-1]!='\n'){
      while(fgetc(stdin)!='\n');
    }
    
    cad[i-1]='\0';
    i=strlen(cad);
    
    for(j=0;j<i;j++){
      if(!isdigit(cad[j])){
	  printf("\nValor seleccionado incorrecto\n");
	  cont=1;
	  break;
	}
      if(j==i-1){
	k=atoi(cad);
	if(k<1 || k>nr){
	  printf("\nValor seleccionado incorrecto\n");
	  cont=1;
	  break;
	}
      }
    }
  }while(cont);

  k-=1;

  printf("\nNumero de comentarios:%i\n", referencia[k].criticos);

  for(i=0;i<referencia[k].criticos;i++){
    for(j=0;j<nl;j++){
      if(referencia[k].comment[i].lector==lector[j].codigo){
	break;
      }
    }
    printf("%s:%s\n",lector[j].nombre,referencia[k].comment[i].opinion);
  }
   
  
  return;
}


//////////////////////////////////////////////////////////////////////
                      //CALCULAR NOTA//
/////////////////////////////////////////////////////////////////////


void nota(referencia_t *referencia, int nr){
  int k;

  k=cogf(nr);
  k-=1;
  
  printf("\nNumero de votos:%hd\n",referencia[k].votantes);
  if(referencia[k].votantes==0){
    printf("Nota media:%.2f\n",0.0);
    return;
  }
  printf("Nota media:%.2f\n",(float)referencia[k].votos/referencia[k].votantes);
  return;
}


//////////////////////////////////////////////////////////////////////////
                             //VOTAR//
/////////////////////////////////////////////////////////////////////////


void voto(referencia_t *referencia, int nr){
  int i,j,k,m;
  int  continuar;
  char cad[90];

  k=cogf(nr);

  k-=1;

  do{
    continuar=0;
    
    printf("\nEscribe el voto: ");
    
    fgets(cad,sizeof(cad),stdin);
    i=strlen(cad);
    if(cad[i-1]!='\n'){
      while(fgetc(stdin)!='\n');
    }
    
    cad[i-1]='\0';
    i=strlen(cad);
    
    for (j=0;j<i;j++){
      if(!isdigit(cad[j])){
	  printf("\nValor seleccionado incorrecto\n");
	  continuar=1;
	  break;
	}
      if(j==i-1){
	m=atoi(cad);
	if(m<1 || m>10){
	  printf("\nValor seleccionado incorrecto\n");
	  continuar=1;
	  break;
	}
      }
    }
  }while(continuar);
  
  referencia[k].votos+=m;
  referencia[k].votantes++;

  printf("\nVoto registrado\n");
  
  guardar_referencias(referencia,nr);
  
  return;
}

/////////////////////////////////////////////////////////////////////////
                          //OPINION//
///////////////////////////////////////////////////////////////////////



void opinion(referencia_t *referencia, int nl, int nr){
  
  int i,j,k,m,n;
  int continuar;
  char cad[90];

  do{
    continuar=0;
    
    printf("\nEscribe la signatura: ");
    
    fgets(cad,sizeof(cad),stdin);
    i=strlen(cad);
    
    if(cad[i-1]!='\n'){
      while(fgetc(stdin)!='\n');
    }
    
    cad[i-1]='\0';
    i=strlen(cad);
    
    for(j=0;j<i;j++){
      
      if(!isdigit(cad[j])){
	  printf("\nValor seleccionado incorrecto\n");
	  continuar=1;
	  break;
	}
      
      if(j==i-1){
	k=atoi(cad);
	if(k<1 || k>nr){
	  printf("\nValor seleccionado incorrecto\n");
	  continuar=1;
	  break;
	}
      }
    }
  }while(continuar);

  do{
    continuar=0;
    
    printf("\nEscribe el codigo: ");
    
    fgets(cad,sizeof(cad),stdin);
    i=strlen(cad);
    
    if(cad[i-1]!='\n'){
      while(fgetc(stdin)!='\n');
    }
    cad[i-1]='\0';
    i=strlen(cad);
    
    for(j=0;j<i;j++){
      if(!isdigit(cad[j])){
	  printf("\nValor seleccionado incorrecto\n");
	  continuar=1;
	  break;
	}
      if(j==i-1){
	m=atoi(cad);
	if(m<1 || m>nl){
	  printf("\nValor seleccionado incorrecto\n");
	  continuar=1;
	  break;
	}
      }
    }
  }while(continuar);

 do{
    continuar=0;
    
    printf("\nEscribe el comentario: ");
    
    fgets(cad,sizeof(cad),stdin);
    
    i=strlen(cad);
    
    if(cad[i-1]!='\n'){
      while(fgetc(stdin)!='\n');
    }
    
    cad[i-1]='\0';
    i=strlen(cad);
    if(i==0){
      printf("\nCadena vacia\n");
      continuar=1;
    }else{
      if(i>80){
	printf("\nLongitud de la cadena excesiva\n");
	continuar=1;
      }else{
	n=0;
	for(j=0;j<i;j++){
	  if(cad[j]==':'){
	    n++;
	  }
	}
	if(n!=0){
	    printf("\nCaracter invalido\n");
	    continuar=1;
	}
      }
    }
  }while(continuar);

 n=0;
 while(referencia[k-1].comment[n].lector!=0){
   n++;
 }

 referencia[k-1].comment[n].lector=m;
 strcpy(referencia[k-1].comment[n].opinion,cad);

 printf("\nOpinion registrada\n");
 referencia[k-1].criticos++;

 guardar_referencias(referencia,nr);
 
 return;
}


/////////////////////////////////////////////////////////////////////////////

int cargar_lect(lector_t *lector){
  int k=0;
  char pto2[3];

  FILE *lector_file=fopen("lectores.txt","r");

  if(lector_file==NULL){
    lector_file=fopen("lectores.txt","w");
    fclose(lector_file);
    return 0;
  }
  while (1){    
    pto2[0]=getc(lector_file);
    if(pto2[0]==EOF){
      break;
    }
    fscanf(lector_file,"%hd",&lector[k].codigo);
    pto2[1]=getc(lector_file);
    fgets(lector[k].nombre,sizeof(lector[k].nombre),lector_file);
    pto2[2]='\0';
    if(lector[k].codigo<=0 || strcmp(pto2,"::") || lector[k].nombre[strlen(lector[k].nombre)-2]!=':'){
      printf("Linea mal formada en el fichero (lectores.txt)\n");
      fclose(lector_file);
      return -1;
    }
    lector[k].nombre[strlen(lector[k].nombre)-2]='\0';
    k++;
  }

  fclose(lector_file);
  return k;
}


/////////////////////////////////////////////////////////////////////////////

int cargar_ref(referencia_t *referencia){
  int k,w=0,j,i;
  char pto2[10];

  FILE *refer_file=fopen("referencias.txt","r");

  if (refer_file==NULL){
    refer_file=fopen("referencias.txt","w");
    fclose(refer_file);
    return 0;
  }
  
  k=0;
  i=fscanf(refer_file,"%c",&pto2[0]);

  while(1){
    pto2[9]='\0';
    if(i==EOF){
      break;
    }
      
    fscanf(refer_file,"%d",&referencia[k].signatura);
    fscanf(refer_file,"%c",&pto2[1]);
    fscanf(refer_file,"%c",&referencia[k].tipo);
    fscanf(refer_file,"%c",&pto2[2]);
    w=0;
    do{
      fscanf(refer_file,"%c",&referencia[k].autor[w]);
      w++;
    }while(referencia[k].autor[w-1]!=':');
    pto2[3]=referencia[k].autor[w-1];
    referencia[k].autor[w-1]='\0';
    
    w=0;
    do{
      fscanf(refer_file,"%c",&referencia[k].titulo[w]);
      w++;
    }while(referencia[k].titulo[w-1]!=':');
    pto2[4]=referencia[k].titulo[w-1];
        referencia[k].titulo[w-1]='\0';

   
    fscanf(refer_file,"%hd%c%hd%c%d%c%hd%c",&referencia[k].anho,&pto2[5],&referencia[k].votantes,&pto2[6],&referencia[k].votos,&pto2[7],&referencia[k].criticos,&pto2[8]);


    if(strcmp(pto2,":::::::::")  || strlen(referencia[k].autor)==0 || strlen(referencia[k].titulo)==0 || referencia[k].signatura<=0 || (tolower(referencia[k].tipo)!='l' && tolower(referencia[k].tipo)!='a') || referencia[k].anho<1450 || referencia[k].anho>2017 || referencia[k].votantes<0 || referencia[k].votos<0 || referencia[k].criticos<0){
      printf("Linea mal formada en el fichero (referencias.txt)\n");
      fclose(refer_file);
      return -1;
    }
    
    j=0;

      while(1){
	pto2[2]='\0';
	i=fscanf(refer_file," %c",&pto2[0]);
	if(pto2[0]!=':' && i!=EOF){
	  fscanf(refer_file,"%hd",&referencia[k].comment[j].lector);
	  fscanf(refer_file,"%c",&pto2[1]);
	  fgets(referencia[k].comment[j].opinion,sizeof(referencia[k].comment[j].opinion),refer_file);
	  
	  
	  if(strcmp(pto2,"#:") || referencia[k].comment[j].lector<=0 || referencia[k].comment[j].opinion[strlen(referencia[k].comment[j].opinion)-2]!=':'){
	    printf("Línea mal formada en el fichero (referencias.txt)\n");
	    fclose(refer_file);
	    return -1;
	  }

	  referencia[k].comment[j].opinion[strlen(referencia[k].comment[j].opinion)-2]='\0';
	}else{
	  break;
	}

	j++;
      } 
    k++;
  }

  fclose(refer_file);
  return k;
}
  

//////////////////////////////////////////////////////////////////////////////


void guardar_lectores(lector_t *lector,int n){
  int k;

  FILE *lector_file=fopen("lectores.txt","w");

  for(k=0;k<n;k++){
    fprintf(lector_file,":%d:%s:\n",lector[k].codigo,lector[k].nombre);
  }
  
  fclose(lector_file);
  return;
}

//////////////////////////////////////////////////////////////////////////////

void guardar_referencias(referencia_t *referencia,int n){
  int i,j;

  FILE *refer_file=fopen("referencias.txt","w");

  for(i=0;i<n;i++){
    fprintf(refer_file,":%i:%c:%s:%s:%hd:%hd:%i:%hd:\n",referencia[i].signatura,referencia[i].tipo,referencia[i].autor,referencia[i].titulo,referencia[i].anho,referencia[i].votantes,referencia[i].votos,referencia[i].criticos);

    for(j=0;j<referencia[i].criticos;j++){
      fprintf(refer_file,"#%hd:%s:\n",referencia[i].comment[j].lector,referencia[i].comment[j].opinion);
    }
  }

  fclose(refer_file);
  return;
}



///////////////////////////////////////////////////////////////////////////


int cogf(int n){
  int i,j,k;
  int continuar;
  char cad[90];
  
  do{
    continuar=0; 
    printf("\nEscribe la signatura: ");
    fgets(cad,sizeof(cad),stdin);
    i=strlen(cad);
    if(cad[i-1]!='\n'){
      while(fgetc(stdin)!='\n');
    }
    cad[i-1]='\0';
    i=strlen(cad);
    
    for(j=0;j<i;j++){
      if(!isdigit(cad[j])){
	  printf("\nValor seleccionado incorrecto\n");
	  continuar=1;
	  break;
	}
      if(j==i-1){
	k=atoi(cad);
	if(k<1 || k>n){
	  printf("\nValor seleccionado incorrecto\n");
	  continuar=1;
	  break;
	}
      }
    }
  }while(continuar);
  return k;
}
  
