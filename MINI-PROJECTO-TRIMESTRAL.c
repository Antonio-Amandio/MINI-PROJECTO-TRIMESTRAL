//Curso : T�cnico de Inform�tica
//Classe : 11�
//Sala n� : 2
//Turma: A


#include <stdio.h> // Biblioteca padr�o para fun��es de entrada e sa�da de dados
#include <stdlib.h> // Biblioteca padr�o na linguagem C para algumas fun��es como : (itoa, atoi)
#include <locale.h> // Biblioteca para utiliza��o de car�cteres especiais
#include <ctype.h> // Biblioteca utilizada para transformar car�cter ou string de min�culas � mai�sculas
#include <time.h> // Biblioteca para acessar a hora do computador
#include <string.h> // Biblioteca para a manipula��o de Strings
 
// Declara��es de vari�veis de escopo global
int opcao;
int codigo[6];
char nome[31], apelido[31], sexo, morada[31], data_nascimento[20], n_telefone[9];
char data_criacao[20];
int pin, n_conta_digitado[6], novo_pin, pin_digitado, cont_pin = 0;
int tamanho, contador, numero;
int verificador = 0;
float saldo = 5000, valor_a_retirar = 0, valor_a_transferir;
float levantamento[5000], transferencia[5000];
int contador_transferencia = 0, quant_transferencia = 0;
int contador_levantamento = 0, quant_levantamento = 0;

int main (){ // Fun��o Principal
	setlocale(LC_ALL, "Portuguese"); // Comando para o idioma em Portugu�s
	
	do{
		
		system("cls"); // Comando para limpar a tela do CMD	
		
		printf("\n======== Menu Principal ========\n");
		printf("\nEscolha uma op��o abaixo : ");
		printf("\n\n[1] - Gest�o de conta");
		printf("\n[2] - Gest�o de Utilizador");
		printf("\n[3] - Sair");
		printf("\n\nSua op��o : ");
		scanf("%d", &opcao); // Leitura da op��o digitada pelo usu�rio
	
	}while(opcao < 1 || opcao > 3); // Repeti��o at� a condi��o for falsa
	
	switch(opcao){ // Estrutura de multipla escolha para verificar qual foi a op��o digitada pelo usu�rio
		
		case 1: // Op��o para " Gest�o de Conta "
			system("cls");
			GestaoConta(); // Invoca��o da Fun��o " Gest�o de Conta "
		break;
		
		case 2: // Op��o para " Gest�o de Utilizador "
			system("cls");
			GestaoUtilizador(); // Invoca��o da Fun��o " Gest�o de Utilizador "
		break;
		
		default: // Outra op��o n�o espec�ficada, nesse caso considerada como op��o op��o " Sair "
			system("cls");
			printf("\n\n********* Programa Encerrado *********"); // Mensagem de encerramento do programa
	}
	
	system("Pause > Nul"); // Comando para pausar a tela do CMD e n�o mostrar a mensagem " Press any key to continue "
	return 0;
}


int GestaoConta(){ // Fun��o para a " Gest�o de Conta "
	setlocale(LC_ALL, "Portuguese");
	
	do{
		
		system("cls");
		
		printf("\n======== Gest�o de Conta ========\n");
		printf("\nEscolha uma op��o abaixo : ");
		printf("\n\n[1] - Abrir conta");
		printf("\n[2] - Consultar Saldo");
		printf("\n[3] - Levantamento");
		printf("\n[4] - Consultar movimentos");
		printf("\n[5] - Transfer�ncia");
		printf("\n[6] - Pagamento");
		printf("\n[7] - Consultar IBAN/N de conta");
		printf("\n[0] - Voltar");
		printf("\n\nSua op��o : ");
		scanf("%d", &opcao); // Leitura da op��o digitada pelo usu�rio
		
	}while(opcao < 0 || opcao > 7); // Repeti��o at� a condi��o for falsa
	
	if(opcao == 0){ // Op��o para " Voltar ao menu principal "
		main(); // Invoca��o da Fun��o " Main "
	}
	
	else if(opcao == 1){ // Op��o para " Abrir Conta "
			
			system("cls");
			
			printf("\nDigite o seu primeiro nome : ");
			scanf("%s", nome); // Leitura do primeiro nome do usu�rio
			
			system("cls");
			
			printf("\nDigite o seu apelido : "); 
			scanf("%s", apelido); // Leitura do apelido do usu�rio
				
			system("cls");
				
			printf("\nDigite a sua data de nascimento : ");
			scanf("%s", data_nascimento); // Leitura da data de nascimento do usu�rio
			
			system("cls");
			
			printf("\nDigite a sua morada : ");
			scanf("%s", morada); // Leitura da morada do usu�rio
			
			do{
			
			system("cls");
			
			printf("\nDigite o seu n�mero de telefone (Formato de 9 d�gitos) : ");
			scanf("%s", n_telefone); // Leitura do n�mero de telefone do usu�rio
			
			tamanho = strlen(n_telefone); // Armazenando o tamanho da string em uma vari�vel
			
			}while(tamanho != 9 || n_telefone[0] != '9'); // Repeti��o at� a condi��o for falsa

			do{
				
				system("cls");
				
				printf("\nDigite o seu sexo [M/F] : ");
				scanf("%c", &sexo); // Leitura do sexo do usu�rio
				
				sexo = toupper(sexo); // Comando para passar o car�cter para mai�sculas
	
			}while(sexo != 'M' && sexo != 'F'); // Repeti��o at� a condi��o for falsa
			
			system("cls");
			
			printf("\nDigite a data de cria��o de conta : ");
			scanf("%s", data_criacao); // Leitura da data de cria��o de conta 
			
			do{
				
			system("cls");
			
			printf("\nDigite o seu PIN (Formato de 4 d�gitos) : ");
			scanf("%d", &pin); // Leitura do PIN do usu�rio
			
			char verificador_pin[4]; // Declara��o de v�riavel de escopo local
			
			itoa(pin, verificador_pin, 10); // Fun��o para converter o valor de uma v�riavel do tipo de dados inteiro em uma do tipo de dados string
			
			tamanho = strlen(verificador_pin); // Armazenando o tamanho da string em uma vari�vel

			}while(tamanho != 4); // Repeti��o at� a condi��o for falsa 
			
			system("cls");
			
			printf("\nO seu N�mero De Conta � : ");
			
			srand(time(NULL)); // Comando para gerar valores aleat�rios � cada segundo
			for(contador = 0; contador < 6; contador++){
				codigo[contador] = rand() % 10; // Comando para armazenar em uma v�riavel, os valores aleat�rios gerados pela fun��o rand()
				// Obs : O comando " % 10 " indica que os valores aleat�rios � serem gerados, estar�o no intervalo de 0 � 9
				printf("%d", codigo[contador]);
			}
			
			nome[0] = toupper(nome[0]); // Comando para passar o car�cter para mai�sculas
			apelido[0] = toupper(apelido[0]); // Comando para passar o car�cter para mai�sculas
			
			printf("%c%c100", nome[0], apelido[0]); // Impress�o do " N�mero de Conta "
			
	}
	
	else if(opcao == 2){ // Op��o para " Consultar Saldo "
		
		do{

		system("cls");
		
		printf("\nDigite o n�mero de conta : ");
		scanf("%d", &numero); // Leitura do n�mero de conta digitado pelo usu�rio
		
		n_conta_digitado[5] = numero / 1 % 10; // Comando para achar a unidade do n�mero de conta digitado pelo usu�rio
		n_conta_digitado[4] = numero / 10 % 10;  // Comando para achar a dezena do n�mero de conta digitado pelo usu�rio
		n_conta_digitado[3] = numero / 100 % 10;  // Comando para achar a centena do n�mero de conta digitado pelo usu�rio
		n_conta_digitado[2] = numero / 1000 % 10;  // Comando para achar a milhar do n�mero de conta digitado pelo usu�rio
		n_conta_digitado[1] = numero / 10000 % 10;  // Comando para achar a dezena de milhar do n�mero de conta digitado pelo usu�rio
		n_conta_digitado[0] = numero / 100000 % 10;  // Comando para achar a centena de milhar do n�mero de conta digitado pelo usu�rio
		
		for(contador =  0; contador < 6; contador++){
			if(codigo[contador] == n_conta_digitado[contador]){ // Comando para verificar se o n�mero de conta gerado aleat�riamente � igual ao n�mero de conta digitado pelo usu�rio
				verificador++;
			}
		}
		
		
		}while(verificador != 6); // Repeti��o at� a condi��o for falsa
		
		
		system("cls");
		
		printf("\nNome : %s %s", nome, apelido);
		
		printf("\n\nO seu N�mero De Conta � : ");
			
		for(contador = 0; contador < 6; contador++){
			printf("%d", codigo[contador]);
		}
			
		printf("%c%c100", nome[0], apelido[0]); // Impress�o do " N�mero de Conta "
			
		printf("\n\nSaldo contabil�stico: %0.2f AOA", saldo); // " %0.2F " para mostrar apenas dois n�meros ap�s a v�rgula
		
	}
	
	else if(opcao == 3){ // Op��o para " Levantamento "
		
		do{
			
		verificador = 0;
		
		system("cls");
		
		printf("\nDigite o n�mero de conta : ");
		scanf("%d", &numero); // Leitura do n�mero de conta digitado pelo usu�rio
		
		n_conta_digitado[5] = numero / 1 % 10; // Comando para achar a unidade do n�mero de conta digitado pelo usu�rio
		n_conta_digitado[4] = numero / 10 % 10;  // Comando para achar a dezena do n�mero de conta digitado pelo usu�rio
		n_conta_digitado[3] = numero / 100 % 10;  // Comando para achar a centena do n�mero de conta digitado pelo usu�rio
		n_conta_digitado[2] = numero / 1000 % 10;  // Comando para achar a milhar do n�mero de conta digitado pelo usu�rio
		n_conta_digitado[1] = numero / 10000 % 10;  // Comando para achar a dezena de milhar do n�mero de conta digitado pelo usu�rio
		n_conta_digitado[0] = numero / 100000 % 10;  // Comando para achar a centena de milhar do n�mero de conta digitado pelo usu�rio
		
		for(contador =  0; contador < 6; contador++){
			if(codigo[contador] == n_conta_digitado[contador]){ // Comando para verificar se o n�mero de conta gerado aleat�riamente � igual ao n�mero de conta digitado pelo usu�rio
				verificador++;
			}
		}
		
		
		}while(verificador != 6); // Repeti��o at� a condi��o for falsa
		
		system("cls");
		
		printf("\nDigite o valor que pretende retirar da sua conta : ");
		scanf("%f", &valor_a_retirar); // Leitura do valor � levantar da conta do usu�rio
		
		system("cls");
		
		if(saldo == 0){
			printf("\nN�o ser� poss�vel efetuar o seu pedido, pois o seu saldo � negativo.");
		}
		
		else if(saldo != 0 && saldo < valor_a_retirar){
			printf("\nCaro cliente o seu saldo � inferior ao valor � levantar.");
		}
		
		else{
			printf("\nLevantamento efetuado com sucesso.");
			saldo -= valor_a_retirar; //Opera��o para redu��o do saldo da conta
			levantamento[contador_levantamento] = valor_a_retirar;
			quant_levantamento++;
			contador_levantamento++;
		}
		
	}
	
	else if(opcao == 4){ // Op��o para " Consultar Movimento "
		
		system("cls");
		
		//Condi��o para quando n�o se fez nenhum levantamento e nenhuma tranasfer�ncia
		if(quant_levantamento == 0 && quant_transferencia == 0){
			printf("\n\nNenhum levantamento foi feito.\n\n");
			printf("\n\nNenhuma transfer�ncia foi feita.");
		}
		
		//Condi��o para quando se fez algum levantamento mas n�o se fez nenhuma transfer�ncia  
		else if(quant_levantamento > 0 && quant_transferencia == 0){
			
			printf("\n\nNenhuma transfer�ncia foi feita.\n\n");
		
			contador_levantamento = 0;
			
			for(contador = 0; contador < quant_levantamento; contador++){
				
				printf("\n%d - D�bito|-|%s|%0.2f\n\n", contador+1, data_criacao, levantamento[contador_levantamento]);
				contador_levantamento++;
			}
		
		}
		
		//Condi��o para quando se fez alguma transfer�ncia mas n�o se fez nenhum levantamento
		else if(quant_transferencia > 0 && quant_levantamento == 0){
			
			printf("\n\nNenhum levantamento foi feito.\n\n");
			
			contador_transferencia = 0;
			
			for(contador = 0; contador < quant_transferencia; contador++){
				
				printf("\n%d - D�bito|-|%s|%0.2f\n\n", contador+1, data_criacao, transferencia[contador_transferencia]);
				contador_transferencia++;
			}
			
		}
		
		// Condi��o para quando se fez alguma transfer�ncia e levantamento
		else if(quant_transferencia > 0 && quant_levantamento > 0){
			
			contador_levantamento = 0;
			
			for(contador = 0; contador < quant_levantamento; contador++){
				
				printf("\n%d - D�bito|-|%s|%0.2f\n\n", contador+1, data_criacao, levantamento[contador_levantamento]);
				contador_levantamento++;
			}
			
			contador_transferencia = 0;
			
			for(contador = 0; contador < quant_transferencia; contador++){
				
				printf("\n%d - D�bito|-|%s|%0.2f\n\n", contador+1, data_criacao, transferencia[contador_transferencia]);
				contador_transferencia++;
			}
			
			
		}
		
		
	}
	
	else if(opcao == 5){ // Op��o para " Transfer�ncia "
		
		do{
			
		verificador = 0;
		
		system("cls");
		
		printf("\nDigite o n�mero de conta : ");
		scanf("%d", &numero); // Leitura do n�mero de conta digitado pelo usu�rio
		
		n_conta_digitado[5] = numero / 1 % 10; // Comando para achar a unidade do n�mero de conta digitado pelo usu�rio
		n_conta_digitado[4] = numero / 10 % 10;  // Comando para achar a dezena do n�mero de conta digitado pelo usu�rio
		n_conta_digitado[3] = numero / 100 % 10;  // Comando para achar a centena do n�mero de conta digitado pelo usu�rio
		n_conta_digitado[2] = numero / 1000 % 10;  // Comando para achar a milhar do n�mero de conta digitado pelo usu�rio
		n_conta_digitado[1] = numero / 10000 % 10;  // Comando para achar a dezena de milhar do n�mero de conta digitado pelo usu�rio
		n_conta_digitado[0] = numero / 100000 % 10;  // Comando para achar a centena de milhar do n�mero de conta digitado pelo usu�rio
		
		for(contador =  0; contador < 6; contador++){
			if(codigo[contador] == n_conta_digitado[contador]){ // Comando para verificar se o n�mero de conta gerado aleat�riamente � igual ao n�mero de conta digitado pelo usu�rio
				verificador++;
			}
		}
		
		
		}while(verificador != 6); // Repeti��o at� a condi��o for falsa	
		
		system("cls");	
		
		printf("\nDigite a quantidade de valor que pretende transferir : ");
		scanf("%f", &valor_a_transferir);
		
		system("cls");
		
		if(saldo == 0){
			printf("\nN�o ser� poss�vel efetuar o seu pedido, pois o seu saldo � negativo.");
		}
		
		else if(saldo != 0 && saldo < valor_a_transferir){
			printf("\nCaro cliente o seu saldo � inferior ao valor � transferir.");
		}
		
		else{
			printf("\nTransfer�ncia efetuada com sucesso.");
			saldo -= valor_a_transferir; //Opera��o para redu��o do saldo da conta
			transferencia[contador_transferencia] = valor_a_transferir;
			quant_transferencia++;
			contador_transferencia++;
		}
		
	}
	
	else if(opcao == 6){ // Op��o para " Pagamento "
		system("cls");
		//Funcionalidades na segunda fase do projecto
	}
	
	else if(opcao == 7){ // Op��o para " Consultar IBAN/N de conta "
		system("cls");
		//Funcionalidades na segunda fase do projecto
	}
	
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL");
			
	system("Pause > Nul"); // Comando para pausar a tela do CMD e n�o mostrar a mensagem " Press any key to continue "
	
	main(); // Invoca��o da Fun��o " Main "
	
	return 0;
}


int GestaoUtilizador(){ // Fun��o para a " Gest�o de Utilizador "
	setlocale(LC_ALL, "Portuguese");

	do{
		
		system("cls");
		
		printf("\n======== Gest�o de Utilizador ========\n");
		printf("\nEscolha uma op��o abaixo : ");
		printf("\n\n[1] - Alterar o PIN");
		printf("\n[0] - Voltar");
		printf("\n\nSua op��o : ");
		scanf("%d", &opcao); // Leitura da op��o digitada pelo usu�rio
		
	}while(opcao < 0 || opcao > 1); // Repeti��o at� a condi��o for falsa
	
	if(opcao == 0){ // Op��o para " Voltar ao menu principal "
		main(); // Invoca��o da Fun��o " Main "
	}
	
	else if(opcao == 1){ // Op��o para " Alterar PIN "
		
			int AlterarPin(){
			
			system("cls");
			
			printf("\nDigite o novo pin : ");
			scanf("%d", &novo_pin); // Leitura do novo pin digitado pelo usu�rio
			
			pin = novo_pin; // Altera��o do pin
			
			printf("\n\n\nPRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL");
			
			system("Pause > Nul"); // Comando para pausar a tela do CMD e n�o mostrar a mensagem " Press any key to continue "
	
			main(); // Invoca��o da Fun��o " Main "
			
		}
		
		do{
			
			system("cls");	
			
			printf("\nDigite o pin : ");
			scanf("%d", &pin_digitado);	// Leitura do pin digitado pelo usu�rio
			
			if(pin_digitado == pin){
				AlterarPin(); // Invoca��o da Fun��o " Alterar o Pin "
			}
			
			cont_pin++;
				
		}while(cont_pin < 3);
		
		system("cls");
		printf("\n********* Programa Encerrado *********"); // Mensagem de encerramento do programa
	
	}
	

	return 0;
}
