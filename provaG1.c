//*************************************************************************************************
//**                                Autor: André Menezes da Silva                                **
//**                                Autor: Ezequiel Losekann Drews                               **
//**                                Autor: Jean Emílio Wilhelm                                   **
//*************************************************************************************************
//**                Função: Agenda para a prova de Laboratório de Algorítmos II                  **
//*************************************************************************************************
//**                          Arquivo alterado em 18 de Novembro de 2016                         **
//**                     Aula de Laboratório de Algorítmos - Segundo Semestre                    **
//*************************************************************************************************
//*************************************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

//***************************************************** FUNÇÕES *********************************************************//

//STRUCTURE OF LIST "lista"
struct agenda
{
    char   nome     [100];
    char   telefone [10] ;
    char   endereco  [50] ;

    struct agenda *proximo;
};

//Tipo da Estrutura da Lista
typedef struct agenda No;

//Inicializa Lista
No* inicializa()
{
    return NULL;
}

//Verifica se a lista está vazia, assim nAo retorna erro para o usuário
int vazia(No* lista)
{
    if(lista == NULL)
        return 0;
    else
        return 1;
}

//Alocar Memória
No* aloca()
{
    No* var = (No*) malloc(sizeof(No));
    return var;
}

//Incluir elementos na Lista
No* Incluir (No* lista)
{
    printf("\n****************************** DIGITE SEUS DADOS ******************************\n\n");
    No* novo = aloca();
    //********************************************
        getchar();
        printf("DIGITE SEU NOME COMPLETO: ");
        gets  (novo->nome    );
        printf("TELEFONE                : ");
        gets  (novo->telefone);
        printf("ENDERECO                : ");
        gets  (novo->endereco);
        novo->proximo = lista ;
    //********************************************
        return novo;
}



//************************************************ INÍCIO PESQUISAR *****************************************************//
//Pesquisa elementos na Lista
void Pesquisar(No* lista)
{
    if(vazia(lista) > 0)
    {
        char pesquisa[100], tipo;
        printf("\nPESQUISAR POR: NOME [N], TELEFONE [T] ou ENDERECO [E]? ");
        getchar();
        gets(&tipo);//pega a opcao do usuario
        printf("----->INFORME OS DADOS DA PESQUISA: ");
        gets(pesquisa);

//Laço de repetição com as devidas validações para pesquisar

        No* aux;
            for(aux = lista;aux != NULL;aux = aux->proximo)
            {
                if      (tipo == 'N' || tipo == 'n' && (strcmp(pesquisa, aux->nome)      == 0))
                {
                	Imprimir(aux);
                	break;
				}                    
                else if (tipo == 'T' || tipo == 't' && (strcmp(pesquisa, aux->telefone)  == 0))
                {
                	Imprimir(aux);
                	break;
				}                    
                else if (tipo == 'E' || tipo == 'e' && (strcmp(pesquisa, aux->endereco)   == 0))
                {
                	Imprimir(aux);
                	break;
				}                
				
            }
            	if(aux == NULL)
				{
					printf("\nELEMENTO NAO ENCONTRADO!\n");	
				}
    }else
     printf("\nA LISTA ESTA VAZIA! Precione ENTER para continuar\n");
     getchar();getchar();
}
//************************************************ FIM PESQUISAR ********************************************************//

//************************************************ INÍCIO IMPRIMIR ******************************************************//
//Imprimir Lista
int Imprimir (No* lista)
{
        printf("\n\nOPERACAO SUCEDIDA COM SUCESSO!\n\n");
        printf("Nome    :%s\n", lista->nome    );
        printf("Telefone:%s\n", lista->telefone);
        printf("Endereco :%s\n", lista->endereco );
        printf("\n\n");
        printf("PRESSIONE [ENTER] PARA VOLTAR AO MENU INICIAR.\n");
}

//************************************************ FIM IMPRIMIR *********************************************************//



//FUNCAO LISTAR
void Listar(No* lista)
{
    if(vazia(lista) > 0)
    {
        No* aux;
        for(aux = lista;aux != NULL;aux = aux->proximo)
        {
            Imprimir(aux);
        }
        getchar();
    }else
    printf("\nA LISTA ESTÁ VAZIA!");
    printf("\nPRESSIONE [ENTER] PARA VOLTAR AO MENU INICIAR.\n");
    getchar();
}


//Deleta elementos da lista
No* Deletar (No* lista)
{
    if(vazia(lista) > 0)
    {
        No* ant = NULL;
    	No* aux = lista;

        char name[100];
        printf("\n--->INFORME O NOME A DELETAR: ");
        getchar();
        gets(name);


        while(aux != NULL && strcmp(aux->nome, name) != 0) //Laço para percorrer a struct para eliminar e liberar a memoria
        {
            ant = aux;
            aux = aux->proximo;
        }
             if(aux == NULL)
                 return lista;
             else if (ant == NULL)
                 lista = aux->proximo;
             else
                 ant->proximo = aux->proximo;
        free(aux);
        printf("ELIMINACAO SUCEDIDA!");
        printf("PRESSIONE [ENTER] PARA VOLTAR AO MENU INICIAR.\n");
    }else
    printf("\nA LISTA ESTÁ VAZIA!");
    printf("\nPRESSIONE [ENTER] PARA VOLTAR AO MENU INICIAR.\n");
    getchar();
    return lista;
}


//Menu do sistema
int Menu()
{
   int opcao;
   system("cls");//limpa a tela
   printf("*------------------------------- START MENU -------------------------------*\n");
   printf("\n***************************\n");
   printf("* [1] INCLUIR   CONTATO;  *  \n");
   printf("* [2] PESQUISAR CONTATO;  *  \n");
   printf("* [3] DELETAR   CONTATO;  *  \n");
   printf("* [4] CREDITOS;           *  \n");
   printf("* [5] SAIR  DO  CADASTRO; *  \n");
   printf("***************************  \n");
   printf("\n-->SELECIONE SUA OPCAO: "    );

   scanf ("%d",&opcao);
   return opcao;
}

//***************************************************** PROGRAMA PRINCIPAL **********************************************//

void main()
{
    No* lista;
    lista = inicializa();

//opcoes do menu principal
    int opcao = Menu();
    while (opcao != 6 )
    {          
		  switch (opcao)
		  {
			  case 1:
					lista = Incluir(lista);//chamada de funcao para incluir
					break;
			  case 2:
					Pesquisar(lista);//chamada de funcao para pesquisar
					break;
			  case 3:
					lista = Deletar(lista);//chamada de funcao apagar
					break;
			  case 4:
					system("cls");
				printf("Programa desenvolvido pelos alunos:");
				printf("\n\n Andre Menezes da Silva ");
				printf("\n Ezequiel Losekann Drews");
				printf("\n Jean Emilio Wilhelm ");
				printf("\n\n Laboratorio de Algoritmos II - 30/09/2016\n\n\n\n");
				system("PAUSE");
				printf("\n\n");
				system("cls");
					break;
			  case 5:
					exit(0);
					break;
			  default:
					exit(0);
					break;
		  }
     opcao = Menu();
    }
}
