#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct no_arvore
{
	struct no_arvore *esq;
	int info;
	struct no_arvore *dir;
};

typedef struct no_arvore ARVORE;


void Insere(ARVORE **R, int n)
{
if (*R==NULL)
{
  (*R)=(ARVORE *)calloc(1,sizeof(ARVORE));
  (*R)->info=n;
  (*R)->esq=NULL;
  (*R)->dir=NULL;
}
else  if (n<(*R)->info)
		  Insere(&(*R)->esq,n);
	  else
		  Insere(&(*R)->dir,n);
}


ARVORE *Busca (ARVORE *R, int v)
{
	if (R==NULL)
	   return NULL;
	else
	   if (R->info==v)
	      return R;
	   else
	      if (R->info > v)
		 	return Busca (R->esq,v);
	      else
		 	return Busca (R->dir,v);
}

ARVORE *Busca_Referencia (ARVORE *R, int v)
{
	if (R==NULL)
	   return NULL;
	else
	   if ( ( (R->esq != NULL) && (R->esq->info == v) ) || ( (R->dir != NULL) && (R->dir->info == v) ) )
	      return R;
	   else
	      if (R->info > v)
		 	return Busca_Referencia (R->esq,v);
	      else
		 	return Busca_Referencia (R->dir,v);
}


void Pre_Order(struct no_arvore *R)
{
	if (R != NULL)
	{
		printf ("%i ",R->info);
		Pre_Order(R->esq);
		Pre_Order(R->dir);
	}
}

void In_Order(struct no_arvore *R)
{
	if (R != NULL)
	{
		In_Order(R->esq);
		printf ("%i ",R->info);
		In_Order(R->dir);
	}
}


void Pos_Order(struct no_arvore *R)
{
	if (R != NULL)
	{
		Pos_Order(R->esq);
		Pos_Order(R->dir);
		printf ("%i ",R->info);
	}
}

void removerNo(struct no_arvore **r, int valor) //Remover nó especifico
{
	ARVORE *aux, *pai, *r_aux;
	
	r_aux = *r;
	aux = Busca(*r, valor);

	if(aux != NULL)
	{
		if( (aux->esq == NULL) && (aux->dir == NULL) )
		{
			*r = Busca_Referencia(*r, valor);
			if( ((*r)->esq != NULL) && ((*r)->esq->info == aux->info) )
			  (*r)->esq = NULL;
			else
				(*r)->dir = NULL;
				
			free(aux);
			*r = r_aux;
		}
		else if( (aux->esq == NULL) && (aux->dir != NULL) )
		{
			*r = Busca_Referencia(*r, valor);
			if( ((*r)->esq != NULL) && ((*r)->esq->info == aux->info) )
			  (*r)->esq = aux->dir;
			else if( ((*r)->dir != NULL) && ((*r)->dir->info == aux->info) )
			  (*r)->dir = aux->dir;
			  
      free(aux);
			*r = r_aux;
		}
		else if( (aux->dir == NULL) && (aux->esq != NULL) )
		{
			*r = Busca_Referencia(*r, valor);
			if( ((*r)->esq != NULL) && ((*r)->esq->info == aux->info) )
			  (*r)->esq = aux->esq;
			else if( ((*r)->dir != NULL) && ((*r)->dir->info == aux->info) )
			  (*r)->dir = aux->esq;

      free(aux);
			*r = r_aux;
		}
		else if( (aux->dir != NULL) && (aux->esq != NULL) )
		{
		  *r = Busca_Referencia(*r, valor);
		  if( ((*r)->esq != NULL) && ((*r)->esq->info == aux->info) )
		  {
        (*r)->esq = aux->dir;
        *r = aux;
        (*r)->dir->esq = (*r)->esq;
      }
      else if( ((*r)->dir != NULL) && ((*r)->dir->info == aux->info) )
      {
        (*r)->dir = aux->dir;
        *r = aux;
        (*r)->dir->esq = (*r)->esq;
      }
      
      free(*r);
			*r = r_aux;
		}
	}
}


main()
{
	ARVORE *Raiz, *ret;
	int op, val;

	Raiz = NULL;  // arvore vazia
	
do
	{
		system("cls");
		puts("1 - Inserir na Arvore");
		puts("2 - Imprimir Arvore");
		puts("3 - Remover no");

		puts("0 - Sair do programa");
		printf("\nDigite a opcao: ");
		scanf("%d", &op);

		switch(op)
		{
			case 1: printf("\nDigite o valor a inserir:");
			        scanf("%d",&val);
			        Insere(&Raiz, val);
			        break;

			case 2: Pre_Order(Raiz);

			        getch();
			        break;

			case 3: printf("\nDigite o valor para excluir:");
			        scanf("%d",&val);
			        removerNo(&Raiz, val);
			
			
					 getch();
					 break;

		}

	} while(op!=0);
}
