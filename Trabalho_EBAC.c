#include <stdio.h> //biblioteca de comunicação de usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por armazenar as strings


int registro()//função responsavel por cadastrar os usuarios no sistema
{
	setlocale(LC_ALL,"portuguese");
	
	//inicio da criação de variaveis/string
	
	char arquivo[40];
	char cpf [40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
		
    //final da criação de variaveis
    
   	printf("\t Digite o CPF a ser cadastrado: \n");//coletando informação de usuario
	scanf("%s", cpf);//%S refere-se a strings 
	
	 strcpy(arquivo, cpf);   //responsavel por copiar os valores da string
	
	FILE * file; //cria o arquivo 
	file = fopen(arquivo,"w"); //o W é de wright(escrever)
	fprintf(file, cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a");  // o a significa atualizar
	fprintf(file,","); //adicionado a virgula para nao ficar junto
	fclose(file);//fecha arquivo
	
	
	printf("\t Digite o nome a ser cadastrado: \n"); //cadastrando informação do nome
	scanf("%s",nome);//salvando nome
	
	file = fopen(arquivo, "a");//atualizando arquivo
	fprintf(file,nome); //adicionando valor do nome no arquivo
	fclose(file);//fechando arquivo
	
	file = fopen(arquivo, "a");//atualizando arquivo
	fprintf(file,",");//gerando virgula
	fclose(file); //fechando arquivo
	
	printf("\t Digite o Sobrenome a ser cadastrado: \n");//adicionando sobrenome
	scanf("%s",sobrenome);//salvando o valor de sobrenome
	
	file = fopen(arquivo, "a");//atualizando arquivo
	fprintf(file,sobrenome); //adicionando o valor do sobrenome no arquivo
	fclose(file);//fechando arquivo	
	
	file = fopen(arquivo, "a");//atualizando arquvio
	fprintf(file,",");//adicionando virgula
	fclose(file);//fechando arquivo
	
	printf("\t Digite o Cargo a ser cadastrado: \n");//criando valor de cargo
	scanf("%s",cargo);//salvando valor de cargo
	
	file = fopen(arquivo, "a");//atualizando arquivo
	fprintf(file,cargo);//adicionando valor de cargo no arquivo
	fclose(file);//fechando arquivo
	system("pause");//parando a tela final
    return 0;//retornar a inicial
	
	
}

int consulta()//função responvelpor consultar os itens cadastrados
 {
	setlocale(LC_ALL,"portuguese");
	
  char cpf[40];//criando variavel
  char conteudo[200];//criando variavel
  
       printf("\t Digite o CPF a ser consultado: \n\n");//pedindo qual cpf deseja consultar
       scanf("%s", cpf);//salvando a iformação do cpf desejado
  
     FILE *file;//buscando arquivo
     file = fopen(cpf,"r");//lendo arquivo
  
  if(file == NULL)//se não encontrado
 {
       printf("Não foi possivel localizar o cadastro \n");//notificando usuario
         system("pause");//pausando tela
       return -1;//voltar para tela anterior
 }
 
  while(fgets(conteudo, 200, file) !=NULL);


 { 
       printf("Essas são as informações do usuário:");//notificando usuario
       printf("%s", conteudo);//salvando a informação de conteudo
       printf("\n\n");// pulando linhas para deixar mais agradavel
       system("pause");//parando tela
       
}
}

int deletar()//função responsavel por deletar informações 

{
	char cpf[40];//criando a variavel cpf
	
	printf("Digite o CPF a ser deleta: \n");// pedindo que o usuario digite o cpf desejado
	scanf("%s", cpf);//salvando a informação de qual é o cpf desejado
	remove(cpf);//deletando cpf desejado
	
	FILE *file;//criando arquivo
	file = fopen(cpf,"r"); //ler arquivo  //r de Read
	
	if(file == NULL)//se arquivo não for encontrado
	{  printf("o arquivo foi deletado com sucesso \n");//notificando usuario
	system("pause"); //parar tela
	return 0;//retornar a tela anterior
	}
	
}




int main () 
{
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	system("cls");
	
	setlocale(LC_ALL,"portuguese");

	printf("\t ### Cartório Da EBAC ###\n\n");//inicio do menu (Titulo)
	printf("Escolha a opção desejada no menu\n\n");//inicio do menu (pedido de escolha)
	printf("\t1 - Registrar Nomes \n");//opção 1
	printf("\t2 - Consultar Nomes \n");//opção 2
	printf("\t3 - Deletar Nomes\n\n");//opção 3
	printf("digite o numero da opção desejada:");//fim do menu

	scanf("%d",&opcao); //armazenamento da escolha do usuario

	system("cls"); //cls é para limpar a tela após a resposta do usuario

	switch(opcao){ //inicio seleção do menu
	
	case 1://caso selecione a opção 1
	registro(); //chamar  int registro
	break;//quebra de codigo
	
	case 2://caso selecione a opção 2
	consulta();//chamar int consulta
	break;//quebra de codigo
	
	case 3://caso selecione a opção 3
    deletar();//chamar int deletar
	break;//quebra de codigo
	
	default://se opção for diferente das demais
	printf("\t Essa opção não esta diponivel\n\n");//notificando usuario
	system("pause");//parar tela
	break; //quebra de código
	//final da seleção
	
	
}
}
}
