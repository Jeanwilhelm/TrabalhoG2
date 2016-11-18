//*************************************************************************************************
//**                                Autor: André Menezes da Silva                                **
//**                                Autor: Ezequiel Losekann Drews                               **
//**                                Autor: Jean Emílio Wilhelm                                   **
//*************************************************************************************************
//**                Função: Agenda para a prova de Laboratório de Algorítmos II                  **
//*************************************************************************************************
//**                          Arquivo alterado em 07 de outubro de 2016                          **
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
        gets(&tipo);
        printf("----->INFORME OS DADOS DA PESQUISA: ");
        gets(pesquisa);

        No* aux;
            for(aux = lista;aux != NULL;aux = aux->proximo)
            {
                if      ((strcmp(tipo,"N")) && (strcmp(pesquisa, lista->nome)      == 0))
                    Imprimir(aux);
                else if ((strcmp(tipo,"T")) && (strcmp(pesquisa, lista->telefone)  == 0))
                    Imprimir(aux);
                else if ((strcmp(tipo,"E")) && (strcmp(pesquisa, lista->endereco)   == 0))
                    Imprimir(aux);
                else
                printf("\nELEMENTO NAO ENCONTRADO!\n");
            }
    }else
     printf("\nA LISTA ESTÁ VAZIA!\n");
     getchar();
}



//Pesquisar Elementos da Lista
void PesquisarAlterar(No* lista)
{
    if(vazia(lista) > 0)
    {
        char pesquisa[100], tipo[1];
        system("cls");
        printf("\nPESQUISAR POR: NOME [N], TELEFONE [T] ou ENDERECO [E]? ");
        getchar();
        gets(tipo);
        printf("----->INFORME OS DADOS DA PESQUISA: ");
        gets(pesquisa);

        No* aux;
            for(aux = lista;aux != NULL;aux = aux->proximo)
            {
                if      ((strcmp(tipo,"N")) && (strcmp(pesquisa, lista->nome)      == 0))
                    ImprimirAlterar(aux);
                else if ((strcmp(tipo,"T")) && (strcmp(pesquisa, lista->telefone)  == 0))
                    ImprimirAlterar(aux);
                else if ((strcmp(tipo,"E")) && (strcmp(pesquisa, lista->endereco)   == 0))
                    ImprimirAlterar(aux);
                else
                printf("ELEMENTO NAO ENCONTRADO!");
            }
    }else
     printf("A LISTA ESTÁ VAZIA!\n");
     getchar();
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

//Imprimi Lista Alterada
int ImprimirAlterar (No* lista)
{
        printf("\n\nOPERACAO SUCEDIDA COM SUCESSO!\n\n");
        printf("Nome    :%s\n", lista->nome    );
        printf("Telefone:%s\n", lista->telefone);
        printf("endereco :%s\n", lista->endereco );
        printf("\n\n");
        printf("PRESSIONE [ENTER] PARA ALTERAR CONTATO.\n");
}
//************************************************ FIM IMPRIMIR *********************************************************//



//RAY LIST
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


//Troca os elementos da lista
No* Alterar(No* lista)
{
    if(vazia(lista) > 0)
    {
        PesquisarAlterar(lista);
		
		system("cls");       

           printf("*********************** DIGITE OS NOVOS DADOS ***********************: ");
           printf("\nDIGITE SEU NOME COMPLETO: ");
           gets  (lista->nome    );
           printf("TELEFONE                  : ");
           gets  (lista->telefone);
           printf("ENDERECO                  : ");
           gets  (lista->endereco );

           printf("\n\n\n[ALTERADO]!");

    }else
    printf("\nA LISTA ESTÁ VAZIA!");
    printf("\nPRESSIONE [ENTER] PARA VOLTAR AO MENU INICIAR.\n");
    getchar();
    return lista;
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


        while(aux != NULL && strcmp(aux->nome, name) != 0)
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

    int opcao = Menu();
    while (opcao != 6 )
    {          
		  switch (opcao)
		  {
			  case 1:
					lista = Incluir(lista);
					break;
			  case 2:
					Pesquisar(lista);
					break;
			  case 3:
					lista = Deletar(lista);
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
