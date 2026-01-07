#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
//TAD
typedef struct Passageiro passageiro;
typedef struct Lista_passageiros lista_passageiros;
typedef struct Voo voo;
typedef struct No no_sala;
typedef struct Sala_espera sala_espera;
lista_passageiros*iniciar_listap();
lista_passageiros*inserir_passageiro(lista_passageiros*lp, char* nome, int n_bilhete,int n_voo, char*classe);
voo*iniciar_voo();
voo*inserir_voo(voo*lv,char*data,char*origem,char*destino,int n_voo);
void check_in_auto(voo*lv,lista_passageiros*lp);
void check_in_manual(voo*lv,lista_passageiros*lp);
sala_espera*iniciar_sala();
sala_espera*inserir_sala(sala_espera*f,char* nome, int n_bilhete,int n_voo, char*classe);
void consulta_sala(sala_espera*sl);
void consulta_voo(voo*lv);
void imprimir_passageiro(lista_passageiros*lp);
void verificar_lugares(voo*lv, int n_voo);
void destruir(lista_passageiros*lp,voo*v, no_sala*sala ,sala_espera*se);
