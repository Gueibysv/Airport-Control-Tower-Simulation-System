#include "torre.c"
 main(){
 	setlocale(LC_ALL,"Portuguese");
 	int op=1, num_v, tamanho= 78, v_num, pista, num_bi, n_bi, n_lugar;
 	char origem[30], destino[30], data[30], classe[3], nome[30];
 	voo*aviao;
	lista_passageiros*pass;
	int n_bilhete,n_voo;
	int lugar_voo;
	aviao=iniciar_voo();
	pass=iniciar_listap();
	sala_espera*sala=iniciar_sala();
 	printf("Como deseja usar a aplicação?\n");
	printf("1- Torre de Controle\n2- Atendentimento aos Passageiros\n0- Encerrar\n");
	printf("\n");
	printf("Eu desejo: ");
	scanf("%d", &op);
	
	//OPÇÕE DO MENU
 	switch(op){
TORRE:
 		//MENU DO ADMINSTRADOR
 		case 1:
 			while(op!=0){
 				printf("\n----------------MENU DO ADMINISTRADOR-------\n");
 				printf("1- Criar voo\n2- Descolagem do Voo\n3- Aterrizagem do Voo\n4- Mudar de User\n5- Destruir toda simulação\n0- Sair\n ");
				printf("Escolher: "); scanf("%d", &op);
				switch(op){
					//CRIAR VOO
					case 1:
						system("cls");
						printf("\n----------------MENU DO ADMINISTRADOR->CRIAÇÃO DE VOO-------\n");
						printf("Número do Voo: %d", ++num_v);
						printf("\nOrigem: "); scanf("%s", origem);
						printf("\nDestino: "); scanf("%s", destino);
						printf("\nData: "); scanf("%s", data);
						//CHAMAR A FUNÇÃO CRIAR VOO
						system("cls");
						//CONDIÇÃO SE REGISTRADO COM SUCESSO
						aviao=inserir_voo(aviao,data,origem,destino,num_v);
						printf("REGISTRADO COM SUCESSO O VOO Nº%d", num_v);
					break;
					//DECOLAR VOO
					case 2:
						system("cls");
						printf("\n----------------MENU DO ADMINISTRADOR->PARTIDA DE VOOS-------\n");
						//MOSTRAR O VOOS PRONTOS A SAIR CASO HAJA
						printf("Deseja decolar o próximo Voo (1-SIM 2-NÃO): "); scanf("%d", &v_num);
						//CHAMAR A FUNÇÃO DE VERIFICAÇÃO DO VOO
						if(v_num== 1){
							printf("\nEscolha entre a PISTA-1 ou PISTA-2 para decolagem do Voo Nº%d", v_num);
							printf("\nPISTA-"); scanf("%d", &pista);
							while((pista<=0)||(pista>=3)){
								printf("\nDigite uma pista válida entre 1 ou 2");
								printf("\nPISTA-"); scanf("%d", &pista);	
							}
							//FUNÇÃO MANDAR PARA A PISTA
							//a pópria condição pode ser até feita dentro da própria funçãoo mandar para a pista
							if(pista){
								printf("\nVOO DECOLADO COM SUCESSO!");// SE POSSÍVEL ESPECÍFICAR TAMBÉM O DESTINO	
							}	
						}
						else
							printf("\nJá não há aviões prontos para Decolagem");
					break;
					//ATERRAR VOO
					case 3:
						system("cls");
						printf("\n----------------MENU DO ADMINISTRADOR->ATERRIZAGEM DE VOOS-------\n");
						printf("Digite o Número do voo que deseja aterrar: ");
							scanf("%d", &v_num);
							while((pista!=3)&&(pista!=4)){
								printf("\nDigite o Nº da Pista (3 ou 4)");
								scanf("%d", &pista);
							}
							//Usar a função aterrar	
							system("cls");
						printf("Voo aterrado com sucesso");
					break;
					//MUDAR PARA ATENDOMENTO
					case 4:
						system("cls");
						printf("\n----------------MENU DO ADMINISTRADOR->MUDAR DE USER-------\n");
						while((op!=1)&&(op!=2)){
							printf("Está prestes a mudar de user, tem a certeza disso? (1- SIM; 2- NÃO): ");
 							scanf("%d", &op);
 						}
 						// verif(op);
 						if(op== 1)
							goto ATENDIMENTO;
						system("cls");
					break;
					//DESTRUIR SIMULAÇÃO
					case 5:
						system("cls");
						printf("\n----------------MENU DO ADMINISTRADOR->DESTRUIR SIMULAÇÃO-------\n");
						printf("Tem a certeza que DESEJA DESTRUIR A SIMULAÇÃO? 1- SIM; 2-NÃO: ");
						scanf("%d", &op);
						if(op== 1){
							//Função destruir
							printf("\nDESTRUÍDO COM SUCESSO!");
						}
						system("cls");
					break;
					case 0:
						system("exit");
					break;
					default:
						system("cls");
						printf("\nOpção Inválida");
				}	
 			}
		break;
		
ATENDIMENTO:		
		//MENU PARA O ATENDIMENTO
 		case 2:
 			while(op!= 0){
 				printf("\n----------------MENU DE ATENDIMENTO-------\n");
 				printf("1- Cadastrar Passageiro\n2-Check-in Auto\n3- Check-in Manual \n4- Consulta\n5- Verificar Lugares\n6- Verificar Passageiros\n7- Mudar de User\n ");
				printf("Escolher: "); scanf("%d", &op);
 				switch(op){
 					//CADASTRAR PASSAGEIRO
 					case 1:
 						system("cls");
 						printf("----------------MENU DE ATENDIMENTO->CADASTRAR PASSAGEIRO-------\n");
						printf("Número do Bilhete: %d", n_bi++);
						printf("\nDigite o seu nome: "); scanf("%s", nome);
						printf("\nDigite a Classe (A, B, C): "); scanf("%s", classe);
						printf("\n O nª do voo: "); scanf("%d", &n_voo);
						//CHAMAR UMA FUNÇÃO QUE VAI VERIFICAR O Nº DO BI
						//CHAMAR A FUNÇÃO PASSAGEIRO
							pass=inserir_passageiro(pass,nome,n_bi,n_voo,classe);
						system("cls");	
						printf("REGISTRADO COM SUCESSO O BILHETE Nº%d", num_bi);
 					break;
 					//CHECKI-IN AUTO
 					case 2:
 						system("cls");
 						check_in_auto(aviao,pass);
 						printf("----------------MENU DE ATENDIMENTO->CHECK-IN AUTOMÁTICO-------\n");
 					break;
 					//CHECKIN MANUAL
 					case 3:
 						system("cls");
 						printf("----------------MENU DE ATENDIMENTO->CHECK-IN MANUAL-------\n");
 						printf("Nº do voo "); scanf("%d", &n_voo);
						//CHMARA A FUNÇÃO Q VAI VERIFICAR O BI E A CLASSE 
						system("cls");
						chek_in_manual(aviao,pass);
						//COLOCAR A CONDIÇÃO AQUI
						printf("REGISTRADO COM SUCESSO O LUGAR Nº%d", n_lugar);
 					break;
 					//CONSULTAR
 					case 4:
 						system("cls");
 						printf("\n----------------MENU DE ATENDIMENTO->CONSULTAR-------\n");
 						printf("Que Consulta deseja fazer: \n1- Sala de Espera\n2- Nº de Passageiros por Voo\n");
						scanf("%d", &op);
						switch(op){
							//CONSULTA DA SALA DE ESPERA
							case 1:
								system("cls");
								printf("----------------MENU DE ATENDIMENTO->CONSULTAR->SALA DE ESPERA-------\n");
								//CHAMAR A FUNÇÃO PARA A SALA DE ESPERA
								consulta_sala(sala);
								
							break;
							//CONSULTA DOS PASSAGEIROS NOS AVIÕES
							case 2:
								system("cls");
								printf("----------------MENU DE ATENDIMENTO->CONSULTAR->SALA DE ESPERA-------\n");
								//CHAMAR A AQUI A FUNÇÃO PARA EXIBIR O Nº DE PASSAGEIROS DE CADA AVIÃO	
								consulta_voo(aviao);
							break;
							default:
								system("cls");
								printf("\nOpção inválida!\n");
						}
 					break;
 					//VERIFICAR LUGAR
 					case 5:
 						system("cls");
 						printf("----------------MENU DE ATENDIMENTO->VERIFICAR LUGARES-------\n");
						printf("Digite o Nº do Voo para Verificação: "); scanf("%d", &v_num);
						system("cls");
						printf("\nVerificando...");
						verificar_lugares(aviao,v_num);
						//CHAMAR A AQUI A FUNÇÃO VERIFICAR LUGARES	
 					break;
 					//VERIFICAR PASSAGEIRO
 					case 6:
 						system("cls");
 						printf("----------------MENU DE ATENDIMENTO->VERFICAR PASSAGEIROS-------\n");
						printf("Digite o Nº de Bilhte do Passageiro: "); scanf("%d", &num_bi);
						//CHAMAR A FUNÇÃO PARA VERIFICAR PASSAGEIRO
 					break;
 					//MUDAR DE USER
 					case 7:
 						system("cls");
 						printf("Está prestes a mudar de user, tem a certeza disso? (1- SIM; 2- NÃO): ");
 						scanf("%d", &op);
 						// verif(op);
 						if(op== 1)
 						goto TORRE;
 						
 					break;
 					case 0:
 						system("cls");
 						op= 9;
 						printf("OPÇÃO INVÁLIDA! MUDE DE USER PARA PODER ENCERRAR O PROGRAMA");
 					break;
 					default:
 						system("cls");
 						printf("OPÇÃO INVÁLIDA!");
 						
				 }
			}
		break;
 		default:
 			printf("OPÇÃO INVÁLIDA!");
	 }
 }
 void destruir(lista_passageiros*lp,voo*v, no_sala*sala ,sala_espera*se){
			voo*auxvoo=v;
			free(lp);
			while (auxvoo!=NULL)
			{
			    free(auxvoo->data);
			    free(auxvoo->destino);
			    free(auxvoo->origem);
			    free(auxvoo->ant);
			    auxvoo=auxvoo->prox;
			
			}
			no_sala*auxsala=se->ini;
			
			while (auxsala!=NULL)
			{
			    free(auxsala->nome);
			 
			   
			    auxsala=auxsala->prox;
			}
			
			free(se);

}

