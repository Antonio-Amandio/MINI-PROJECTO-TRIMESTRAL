#include <stdio.h> // Biblioteca padrão para funções de entrada e saída de dados
#include <stdlib.h> // Biblioteca padrão na linguagem C para algumas funções como : (itoa, atoi)
#include <locale.h> // Biblioteca para utilização de carácteres especiais
#include <ctype.h> // Biblioteca utilizada para transformar carácter ou string de minúculas à maiúsculas
#include <time.h> // Biblioteca para acessar a hora do computador
#include <string.h> // Biblioteca para a manipulação de Strings
 
// Declarações de variáveis de escopo global
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

int main (){ // Função Principal
	setlocale(LC_ALL, "Portuguese"); // Comando para o idioma em Português
	
	do{
		
		system("cls"); // Comando para limpar a tela do CMD	
		
		printf("\n======== Menu Principal ========\n");
		printf("\nEscolha uma opção abaixo : ");
		printf("\n\n[1] - Gestão de conta");
		printf("\n[2] - Gestão de Utilizador");
		printf("\n[3] - Sair");
		printf("\n\nSua opção : ");
		scanf("%d", &opcao); // Leitura da opção digitada pelo usuário
	
	}while(opcao < 1 || opcao > 3); // Repetição até a condição for falsa
	
	switch(opcao){ // Estrutura de multipla escolha para verificar qual foi a opção digitada pelo usuário
		
		case 1: // Opção para " Gestão de Conta "
			system("cls");
			GestaoConta(); // Invocação da Função " Gestão de Conta "
		break;
		
		case 2: // Opção para " Gestão de Utilizador "
			system("cls");
			GestaoUtilizador(); // Invocação da Função " Gestão de Utilizador "
		break;
		
		default: // Outra opção não específicada, nesse caso considerada como opção opção " Sair "
			system("cls");
			printf("\n\n********* Programa Encerrado *********"); // Mensagem de encerramento do programa
	}
	
	system("Pause > Nul"); // Comando para pausar a tela do CMD e não mostrar a mensagem " Press any key to continue "
	return 0;
}


int GestaoConta(){ // Função para a " Gestão de Conta "
	setlocale(LC_ALL, "Portuguese");
	
	do{
		
		system("cls");
		
		printf("\n======== Gestão de Conta ========\n");
		printf("\nEscolha uma opção abaixo : ");
		printf("\n\n[1] - Abrir conta");
		printf("\n[2] - Consultar Saldo");
		printf("\n[3] - Levantamento");
		printf("\n[4] - Consultar movimentos");
		printf("\n[5] - Transferência");
		printf("\n[6] - Pagamento");
		printf("\n[7] - Consultar IBAN/N de conta");
		printf("\n[0] - Voltar");
		printf("\n\nSua opção : ");
		scanf("%d", &opcao); // Leitura da opção digitada pelo usuário
		
	}while(opcao < 0 || opcao > 7); // Repetição até a condição for falsa
	
	if(opcao == 0){ // Opção para " Voltar ao menu principal "
		main(); // Invocação da Função " Main "
	}
	
	else if(opcao == 1){ // Opção para " Abrir Conta "
			
			system("cls");
			
			printf("\nDigite o seu primeiro nome : ");
			scanf("%s", nome); // Leitura do primeiro nome do usuário
			
			system("cls");
			
			printf("\nDigite o seu apelido : "); 
			scanf("%s", apelido); // Leitura do apelido do usuário
				
			system("cls");
				
			printf("\nDigite a sua data de nascimento : ");
			scanf("%s", data_nascimento); // Leitura da data de nascimento do usuário
			
			system("cls");
			
			printf("\nDigite a sua morada : ");
			scanf("%s", morada); // Leitura da morada do usuário
			
			do{
			
			system("cls");
			
			printf("\nDigite o seu número de telefone (Formato de 9 dígitos) : ");
			scanf("%s", n_telefone); // Leitura do número de telefone do usuário
			
			tamanho = strlen(n_telefone); // Armazenando o tamanho da string em uma variável
			
			}while(tamanho != 9 || n_telefone[0] != '9'); // Repetição até a condição for falsa

			do{
				
				system("cls");
				
				printf("\nDigite o seu sexo [M/F] : ");
				scanf("%c", &sexo); // Leitura do sexo do usuário
				
				sexo = toupper(sexo); // Comando para passar o carácter para maiúsculas
	
			}while(sexo != 'M' && sexo != 'F'); // Repetição até a condição for falsa
			
			system("cls");
			
			printf("\nDigite a data de criação de conta : ");
			scanf("%s", data_criacao); // Leitura da data de criação de conta 
			
			do{
				
			system("cls");
			
			printf("\nDigite o seu PIN (Formato de 4 dígitos) : ");
			scanf("%d", &pin); // Leitura do PIN do usuário
			
			char verificador_pin[4]; // Declaração de váriavel de escopo local
			
			itoa(pin, verificador_pin, 10); // Função para converter o valor de uma váriavel do tipo de dados inteiro em uma do tipo de dados string
			
			tamanho = strlen(verificador_pin); // Armazenando o tamanho da string em uma variável

			}while(tamanho != 4); // Repetição até a condição for falsa 
			
			system("cls");
			
			printf("\nO seu Número De Conta é : ");
			
			srand(time(NULL)); // Comando para gerar valores aleatórios à cada segundo
			for(contador = 0; contador < 6; contador++){
				codigo[contador] = rand() % 10; // Comando para armazenar em uma váriavel, os valores aleatórios gerados pela função rand()
				// Obs : O comando " % 10 " indica que os valores aleatórios à serem gerados, estarão no intervalo de 0 à 9
				printf("%d", codigo[contador]);
			}
			
			nome[0] = toupper(nome[0]); // Comando para passar o carácter para maiúsculas
			apelido[0] = toupper(apelido[0]); // Comando para passar o carácter para maiúsculas
			
			printf("%c%c100", nome[0], apelido[0]); // Impressão do " Número de Conta "
			
	}
	
	else if(opcao == 2){ // Opção para " Consultar Saldo "
		
		do{

		system("cls");
		
		printf("\nDigite o número de conta : ");
		scanf("%d", &numero); // Leitura do número de conta digitado pelo usuário
		
		n_conta_digitado[5] = numero / 1 % 10; // Comando para achar a unidade do número de conta digitado pelo usuário
		n_conta_digitado[4] = numero / 10 % 10;  // Comando para achar a dezena do número de conta digitado pelo usuário
		n_conta_digitado[3] = numero / 100 % 10;  // Comando para achar a centena do número de conta digitado pelo usuário
		n_conta_digitado[2] = numero / 1000 % 10;  // Comando para achar a milhar do número de conta digitado pelo usuário
		n_conta_digitado[1] = numero / 10000 % 10;  // Comando para achar a dezena de milhar do número de conta digitado pelo usuário
		n_conta_digitado[0] = numero / 100000 % 10;  // Comando para achar a centena de milhar do número de conta digitado pelo usuário
		
		for(contador =  0; contador < 6; contador++){
			if(codigo[contador] == n_conta_digitado[contador]){ // Comando para verificar se o número de conta gerado aleatóriamente é igual ao número de conta digitado pelo usuário
				verificador++;
			}
		}
		
		
		}while(verificador != 6); // Repetição até a condição for falsa
		
		
		system("cls");
		
		printf("\nNome : %s %s", nome, apelido);
		
		printf("\n\nO seu Número De Conta é : ");
			
		for(contador = 0; contador < 6; contador++){
			printf("%d", codigo[contador]);
		}
			
		printf("%c%c100", nome[0], apelido[0]); // Impressão do " Número de Conta "
			
		printf("\n\nSaldo contabilístico: %0.2f AOA", saldo); // " %0.2F " para mostrar apenas dois números após a vírgula
		
	}
	
	else if(opcao == 3){ // Opção para " Levantamento "
		
		do{
			
		verificador = 0;
		
		system("cls");
		
		printf("\nDigite o número de conta : ");
		scanf("%d", &numero); // Leitura do número de conta digitado pelo usuário
		
		n_conta_digitado[5] = numero / 1 % 10; // Comando para achar a unidade do número de conta digitado pelo usuário
		n_conta_digitado[4] = numero / 10 % 10;  // Comando para achar a dezena do número de conta digitado pelo usuário
		n_conta_digitado[3] = numero / 100 % 10;  // Comando para achar a centena do número de conta digitado pelo usuário
		n_conta_digitado[2] = numero / 1000 % 10;  // Comando para achar a milhar do número de conta digitado pelo usuário
		n_conta_digitado[1] = numero / 10000 % 10;  // Comando para achar a dezena de milhar do número de conta digitado pelo usuário
		n_conta_digitado[0] = numero / 100000 % 10;  // Comando para achar a centena de milhar do número de conta digitado pelo usuário
		
		for(contador =  0; contador < 6; contador++){
			if(codigo[contador] == n_conta_digitado[contador]){ // Comando para verificar se o número de conta gerado aleatóriamente é igual ao número de conta digitado pelo usuário
				verificador++;
			}
		}
		
		
		}while(verificador != 6); // Repetição até a condição for falsa
		
		system("cls");
		
		printf("\nDigite o valor que pretende retirar da sua conta : ");
		scanf("%f", &valor_a_retirar); // Leitura do valor à levantar da conta do usuário
		
		system("cls");
		
		if(saldo == 0){
			printf("\nNão será possível efetuar o seu pedido, pois o seu saldo é negativo.");
		}
		
		else if(saldo != 0 && saldo < valor_a_retirar){
			printf("\nCaro cliente o seu saldo é inferior ao valor à levantar.");
		}
		
		else{
			printf("\nLevantamento efetuado com sucesso.");
			saldo -= valor_a_retirar; //Operação para redução do saldo da conta
			levantamento[contador_levantamento] = valor_a_retirar;
			quant_levantamento++;
			contador_levantamento++;
		}
		
	}
	
	else if(opcao == 4){ // Opção para " Consultar Movimento "
		
		system("cls");
		
		//Condição para quando não se fez nenhum levantamento e nenhuma tranasferência
		if(quant_levantamento == 0 && quant_transferencia == 0){
			printf("\n\nNenhum levantamento foi feito.\n\n");
			printf("\n\nNenhuma transferência foi feita.");
		}
		
		//Condição para quando se fez algum levantamento mas não se fez nenhuma transferência  
		else if(quant_levantamento > 0 && quant_transferencia == 0){
			
			printf("\n\nNenhuma transferência foi feita.\n\n");
		
			contador_levantamento = 0;
			
			for(contador = 0; contador < quant_levantamento; contador++){
				
				printf("\n%d - Débito|-|%s|%0.2f\n\n", contador+1, data_criacao, levantamento[contador_levantamento]);
				contador_levantamento++;
			}
		
		}
		
		//Condição para quando se fez alguma transferência mas não se fez nenhum levantamento
		else if(quant_transferencia > 0 && quant_levantamento == 0){
			
			printf("\n\nNenhum levantamento foi feito.\n\n");
			
			contador_transferencia = 0;
			
			for(contador = 0; contador < quant_transferencia; contador++){
				
				printf("\n%d - Débito|-|%s|%0.2f\n\n", contador+1, data_criacao, transferencia[contador_transferencia]);
				contador_transferencia++;
			}
			
		}
		
		// Condição para quando se fez alguma transferência e levantamento
		else if(quant_transferencia > 0 && quant_levantamento > 0){
			
			contador_levantamento = 0;
			
			for(contador = 0; contador < quant_levantamento; contador++){
				
				printf("\n%d - Débito|-|%s|%0.2f\n\n", contador+1, data_criacao, levantamento[contador_levantamento]);
				contador_levantamento++;
			}
			
			contador_transferencia = 0;
			
			for(contador = 0; contador < quant_transferencia; contador++){
				
				printf("\n%d - Débito|-|%s|%0.2f\n\n", contador+1, data_criacao, transferencia[contador_transferencia]);
				contador_transferencia++;
			}
			
			
		}
		
		
	}
	
	else if(opcao == 5){ // Opção para " Transferência "
		
		do{
			
		verificador = 0;
		
		system("cls");
		
		printf("\nDigite o número de conta : ");
		scanf("%d", &numero); // Leitura do número de conta digitado pelo usuário
		
		n_conta_digitado[5] = numero / 1 % 10; // Comando para achar a unidade do número de conta digitado pelo usuário
		n_conta_digitado[4] = numero / 10 % 10;  // Comando para achar a dezena do número de conta digitado pelo usuário
		n_conta_digitado[3] = numero / 100 % 10;  // Comando para achar a centena do número de conta digitado pelo usuário
		n_conta_digitado[2] = numero / 1000 % 10;  // Comando para achar a milhar do número de conta digitado pelo usuário
		n_conta_digitado[1] = numero / 10000 % 10;  // Comando para achar a dezena de milhar do número de conta digitado pelo usuário
		n_conta_digitado[0] = numero / 100000 % 10;  // Comando para achar a centena de milhar do número de conta digitado pelo usuário
		
		for(contador =  0; contador < 6; contador++){
			if(codigo[contador] == n_conta_digitado[contador]){ // Comando para verificar se o número de conta gerado aleatóriamente é igual ao número de conta digitado pelo usuário
				verificador++;
			}
		}
		
		
		}while(verificador != 6); // Repetição até a condição for falsa	
		
		system("cls");	
		
		printf("\nDigite a quantidade de valor que pretende transferir : ");
		scanf("%f", &valor_a_transferir);
		
		system("cls");
		
		if(saldo == 0){
			printf("\nNão será possível efetuar o seu pedido, pois o seu saldo é negativo.");
		}
		
		else if(saldo != 0 && saldo < valor_a_transferir){
			printf("\nCaro cliente o seu saldo é inferior ao valor à transferir.");
		}
		
		else{
			printf("\nTransferência efetuada com sucesso.");
			saldo -= valor_a_transferir; //Operação para redução do saldo da conta
			transferencia[contador_transferencia] = valor_a_transferir;
			quant_transferencia++;
			contador_transferencia++;
		}
		
	}
	
	else if(opcao == 6){ // Opção para " Pagamento "
		system("cls");
		//Funcionalidades na segunda fase do projecto
	}
	
	else if(opcao == 7){ // Opção para " Consultar IBAN/N de conta "
		system("cls");
		//Funcionalidades na segunda fase do projecto
	}
	
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL");
			
	system("Pause > Nul"); // Comando para pausar a tela do CMD e não mostrar a mensagem " Press any key to continue "
	
	main(); // Invocação da Função " Main "
	
	return 0;
}


int GestaoUtilizador(){ // Função para a " Gestão de Utilizador "
	setlocale(LC_ALL, "Portuguese");

	do{
		
		system("cls");
		
		printf("\n======== Gestão de Utilizador ========\n");
		printf("\nEscolha uma opção abaixo : ");
		printf("\n\n[1] - Alterar o PIN");
		printf("\n[0] - Voltar");
		printf("\n\nSua opção : ");
		scanf("%d", &opcao); // Leitura da opção digitada pelo usuário
		
	}while(opcao < 0 || opcao > 1); // Repetição até a condição for falsa
	
	if(opcao == 0){ // Opção para " Voltar ao menu principal "
		main(); // Invocação da Função " Main "
	}
	
	else if(opcao == 1){ // Opção para " Alterar PIN "
		
			int AlterarPin(){
			
			system("cls");
			
			printf("\nDigite o novo pin : ");
			scanf("%d", &novo_pin); // Leitura do novo pin digitado pelo usuário
			
			pin = novo_pin; // Alteração do pin
			
			printf("\n\n\nPRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL");
			
			system("Pause > Nul"); // Comando para pausar a tela do CMD e não mostrar a mensagem " Press any key to continue "
	
			main(); // Invocação da Função " Main "
			
		}
		
		do{
			
			system("cls");	
			
			printf("\nDigite o pin : ");
			scanf("%d", &pin_digitado);	// Leitura do pin digitado pelo usuário
			
			if(pin_digitado == pin){
				AlterarPin(); // Invocação da Função " Alterar o Pin "
			}
			
			cont_pin++;
				
		}while(cont_pin < 3);
		
		system("cls");
		printf("\n********* Programa Encerrado *********"); // Mensagem de encerramento do programa
	
	}
	

	return 0;
}
