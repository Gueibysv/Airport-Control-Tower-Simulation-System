#include"torre.h"	
 // estrutura para criação do bilhete para o voo, componente da estrutura passageiros
 
//lista para armagenar os passageiros registrados
	typedef struct Lista_passageiros {
			char nome[30]; //nome do passageiro
			int n_bilhete,n_voo;
			int lugar_voo;
			char classe[10];	// estrutura para o bilhete do voo
			struct Lista_passageiros*prox; //Lista simples ligada
	}lista_passageiros;	
// estrtura paara os voos 
	typedef struct Voo {
			char data[30];
			char origem[30];
			char destino[30];
			int n_voo;
			int tamA,tamB,tamC;
			char A[6],B[12],C[60];
			lista_passageiros*relacionados;
			struct Voo*prox,*ant; // Lista duplamente ligada
	}voo;	
// estrutura para do tipo lista sala de espera, funciona juntamente com o check-in
	typedef struct No{
			char nome[30]; //nome do passageiro
			int n_bilhete,n_voo;
			int lugar_voo;
			char classe[10];
			struct No* prox;
	}no_sala;
// estrutura para do tipo fila para a sala de espera
	typedef struct Sala_espera{
		no_sala* ini, *fim;
	}sala_espera;
// inicialização da lista de passageiros
lista_passageiros*iniciar_listap(){
	return NULL;
}
//estrutura para a pista de voo 1
typedef struct pista{
		voo*lista_v;
		struct pista*prox;
}no_pista1;
// estrutura para do tipo fila para a pista 1
typedef struct pista_1{
	no_pista1* ini, *fim;
	}pista1;
//Inserção de um novo passageiro na lista de passageiros	
lista_passageiros*inserir_passageiro(lista_passageiros*lp, char* nome, int n_bilhete,int n_voo, char*classe){
	lista_passageiros*novo=(lista_passageiros*)malloc(sizeof(lista_passageiros));
	if(novo!=NULL){
		novo->n_voo=n_voo;
		novo->n_bilhete=n_bilhete;
		strcpy(novo->nome,nome);
		strcpy(novo->classe,classe);
		novo->prox=lp;
		return novo;
	}
	else{
		printf("erro na alocação\n");
	}
	
}
//função para iniciar os voos
voo*iniciar_voo(){
	return NULL;
}
//função para criar os voos e inserir na lista de voos criados ou existentes
voo*inserir_voo(voo*lv,char*data,char*origem,char*destino,int n_voo){
	voo*novo=(voo*)malloc(sizeof(voo));
	if(novo!=NULL){
		novo->tamA=6; //tamanho para as classes do voo
		novo->tamB=12;
		novo->tamC=60;
		strcpy(novo->data,data);
        strcpy(novo->origem,origem);
        strcpy(novo->destino,destino);
		novo->n_voo=n_voo;
		int i;
		for( i=0;i<6;i++){
			novo->A[i]='O';
		}
		for(i=0;i<12;i++){
			novo->B[i]='O';
		}
		for(i=0;i<60;i++){ //inicialização dos lugares O repreenta vazio e X ocupado
			novo->C[i]='O';
		}
       	novo->prox=lv;
       	novo->ant=NULL;
        if(lv!=NULL){
		lv->ant=novo;
	    }
	    return novo;
	}	
}
//inicialização da fila
sala_espera*iniciar_sala(){
	sala_espera*f=(sala_espera*)malloc(sizeof(sala_espera));
	if(f!=NULL){
		f->ini=NULL;
		f->fim=NULL;
	}	
	else{
		printf("Erro na alocação\n");
	}
	return f;
}
//inserir na sala de espera
sala_espera*inserir_sala(sala_espera*f,char* nome, int n_bilhete,int n_voo, char*classe){
	if(f!=NULL){
		no_sala*novo=(no_sala*)malloc(sizeof(no_sala));
		if(novo!=NULL){
		novo->n_voo=n_voo;
		novo->n_bilhete=n_bilhete;
		strcpy(novo->nome,nome);
		strcpy(novo->classe,classe);
		if(f->fim==NULL){
			f->ini=novo;
			f->fim=novo;
		}
		else{
		novo->prox=f->fim;
		f->fim=novo;
		}
		}
		else
		printf("Erro na alocação\n");
		}
	else
	printf("Erro:fila não criada\n");
	
	return f;
}
//check-in dos passageiros
void check_in_auto(voo*lv,lista_passageiros*lp){
	lista_passageiros*auxp=lp;
	voo*auxv=lv;
	sala_espera*sl;
	sl=iniciar_sala();
	int i,pos;
	if(auxp==NULL)
	printf("Nenhum passageiro\n");
	if(auxv==NULL)
	printf("Nenhum voo\n");
	while(auxv!=NULL && auxp!=NULL){
		if(auxp->n_voo==auxv->n_voo){
			if(*auxp->classe=='A'){
				for(i=0;i<6;i++){
					if(auxv->A[i]='O'){
						pos=i;
					}
				}	
				auxv->A[pos]='X';
				auxp->lugar_voo=pos;
				sl=inserir_sala(sl,auxp->nome,auxp->n_bilhete,auxp->n_voo,auxp->classe);
			}
			if(*auxp->classe=='B'){
				for(i=0;i<12;i++){
					if(auxv->B[i]='O'){
						pos=i;
					}
				}	
				auxv->B[pos]='X';
			sl=inserir_sala(sl,auxp->nome,auxp->n_bilhete,auxp->n_voo,auxp->classe);
			
			}
			if(*auxp->classe=='C'){
				for(i=0;i<60;i++){
					if(auxv->C[i]='O'){
						pos=i;
					}
				}	
				auxv->C[pos]='X';
				auxp->lugar_voo=pos;
				auxp->lugar_voo=pos;
				sl=inserir_sala(sl,auxp->nome,auxp->n_bilhete,auxp->n_voo,auxp->classe);	
			}
		}
		auxp=auxp->prox;
		auxv=auxv->prox;	
	}
}
//Check-in manual dos lugares
void chek_in_manual(voo*lv,lista_passageiros*lp){
	lista_passageiros*auxp=lp;
	voo*auxv=lv;
	sala_espera*sl;
	sl=iniciar_sala();
	int i,piso,op,lugar;
	while(auxv!=NULL && auxp!=NULL){
		if(auxp->n_voo==auxv->n_voo){
		do{
	  printf("\n");
	  printf("\n[1] Apresentar paneinel de lugares ");	
	    printf("\n[3] Selecionar manualmente");
	      printf("\n[5] Exit \n");
	      scanf("%d",&op);
	  switch (op){
	  
	  case 1:
	  	printf("\n");
	  	printf("A ");
	  	for (i=0;i<6;i++){
  			printf("%c",auxv->A[i]," ");
			printf(" ");  	
					
  		}
  		printf("\n");
  		printf(" B ");
  			for (i=0;i<12;i++){
  			printf(" %c ",auxv->B[i]," ");
			printf(" ");  
								
  		}
  		printf("\n");
  		printf(" C ");
  			for (i=0;i<60;i++){
  			printf(" %c ",auxv->C[i]," ");
			printf(" "); 
			
						
  		}
  	
	 
	  break; 
	  case 2:
	  	break;
      case 3:
     
	  if(*auxp->classe=='A') 
	  {
	  	while(lugar<1 || lugar>6){
	  		printf("\nQual lugar? [1-6]\n");
	  	scanf("%d",&lugar);
	  	}
	  		if (auxv->A[lugar-1]=='O'){ 
  			 auxv->A[lugar-1]='X';
  			 	auxv->tamA--; 
  			 	auxp->lugar_voo=lugar-1;
  			 	sl=inserir_sala(sl,auxp->nome,auxp->n_bilhete,auxp->n_voo,auxp->classe);
  			 }
  			 else
			printf ("Ocupado");

		
	  }
	   else if (*auxp->classe=='B') 
	  {
	  	while(lugar<7 || lugar>19){
	  		printf("\nQual lugar? [7-19]\n");
	  	scanf("%d",&lugar);
	  	}
	  		if (auxv->B[lugar-1]=='O'){ 
  			 auxv->B[lugar-1]='X';
  				auxv->tamB--; 
  				auxp->lugar_voo=lugar-1;
  				sl=inserir_sala(sl,auxp->nome,auxp->n_bilhete,auxp->n_voo,auxp->classe);
  			 }
  			 else 
			printf ("Ocupado");
	  }
	   if(*auxp->classe=='C') 
	  {
	  	while(lugar<20 || lugar>80){
	  		printf("\nQual lugar? [20-80]\n");
	  	scanf("%d",&lugar);
	  	}
	  		if (auxv->C[lugar-1]=='O'){ 
  			auxv->C[lugar-1]='X';
  				auxv->tamC--; 
  				auxp->lugar_voo=lugar-1;
  				sl=inserir_sala(sl,auxp->nome,auxp->n_bilhete,auxp->n_voo,auxp->classe);
  			 }
  			 else
			printf ("Ocupado");
	  }	   
	  break;
	}

	}while (op!=5);
		auxp=auxp->prox;
		auxv=auxv->prox;
			}
	}

}
//função para verificar lugares num determindado voo
void verificar_lugares(voo*lv, int n_voo){
	voo*aux_lv=lv;
	int i;
	if(aux_lv==NULL)
	printf("\n Sem voo \n");
	while(aux_lv!=NULL && aux_lv->n_voo!=n_voo){
		aux_lv=aux_lv->prox;
	}
	if(aux_lv->n_voo==n_voo){
		printf("\n1ª classe \n");
		for(i=0;i<6;i++){
		printf("%c ",aux_lv->A[i]," ");
		}
		printf("\nClasse executiva \n");
			for(i=0;i<12;i++){
		printf("%c ",aux_lv->B[i]," ");
		}
		printf("\nClasse economica \n");
			for(i=0;i<60;i++){
		printf("%c ",aux_lv->C[i]," ");
		}
	}
}
// inicialiação das pistas
pista1*iniciar_pista(){
	pista1*f=(pista1*)malloc(sizeof(pista1));
	if(f!=NULL){
		f->ini=NULL;
		f->fim=NULL;
	}	
	else{
		printf("Erro na alocação\n");
	}
	return f;
}
//inserção de um voo na pista
pista1*inserir_pista(pista1*f,voo*lv){
	if(f!=NULL){
		no_pista1*novo=(no_pista1*)malloc(sizeof(no_pista1));
			if(novo!=NULL){
		novo->lista_v=(voo*)malloc(sizeof(voo));
		novo->lista_v=lv;
		novo->prox=NULL;
		if(f->ini==NULL)
			f->ini=novo;
		else
		f->fim->prox=novo;
		f->fim=novo;
		}
		else
		printf("Erro na alocação\n");
		}
	else
	printf("Erro:fila não criada\n");
	
	return f;
}
//funçaõ para impressão da lista de passageiros
void imprimir_passageiro(lista_passageiros*lp){
	lista_passageiros*auxp=lp;
	while(auxp!=NULL){
		printf("Nome: %s\n",auxp->nome);
		printf("Nº do voo: %i\n",auxp->n_voo);
		auxp=auxp->prox;
	}
}
//função para consulta da quantidade de lugares num dado voo
void consulta_voo(voo*lv){
	voo*auxv=lv;
	while(auxv!=NULL){
		printf("Voo nº %i\n",auxv->n_voo);
		printf("Espaço disponivel no voo %i\n",auxv->tamA+auxv->tamB+auxv->tamC);
		auxv=auxv->prox;
	}
}
//função para apresentação dos passageiros na sala de espera
void consulta_sala(sala_espera*sl){
	no_sala*auxs=sl->ini;
	if(sl->ini==NULL)
	printf("sala está vazia\n");
	else{
		while(auxs!=NULL){
			printf("Nome: %s \n",auxs->nome);
			printf("Nº voo: %i \n",auxs->n_voo);
			auxs=auxs->prox;
		}	
	}

}

	
