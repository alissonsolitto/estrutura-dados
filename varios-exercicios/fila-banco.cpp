#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define tam 100


void iniciar_fila(int *Inicio, int *Fim)
{
	*Inicio = 0;
	*Fim    = 0;
}

void inserir_fila(int *Fila, int Inicio, int *Fim, int valor)
{
	 if (((*Fim + 1)%tam) != Inicio)
	 {
		 *Fim = (*Fim + 1)%tam; //*Fim avança uma posição
		 Fila[*Fim] = valor;
	 }

}

void inserir_prioridade(int *Fila, int Inicio, int *Fim, int valor)
{
	int achou = 0;
	int Inicio_aux = Inicio;

	if (((*Fim + 1)%tam) != Inicio)
  {
		if((valor / 1000) == 1) //NORMAL
		{
			*Fim       = (*Fim + 1)%tam; //*Fim avança uma posição
		  Fila[*Fim] = valor;
		}
		else if((valor / 1000) == 4) //GESTANTE
		{

			while((Inicio <= *Fim) && (achou == 0))
			{
				if((Fila[Inicio] / 1000) == 1)
					achou = 1;
				else
				  Inicio = (Inicio + 1)%tam;
			}

			if(achou == 1)
			{
			  //realocando as posições na fila
		    for(int a = *Fim; a >= Inicio; a--)
		    {
			  	Fila[(a + 1)%tam] = Fila[a];
		    }
		    
		    *Fim       = (*Fim + 1)%tam; //*Fim avança uma posição
		    Fila[Inicio] = valor;
		  }
		  else
		  {
		    *Fim       = (*Fim + 1)%tam; //*Fim avança uma posição
		    Fila[*Fim] = valor;
		  }
		  
		}else if((valor / 1000) == 2) //IDOSO
		{
			while((Inicio <= *Fim) && (achou == 0))
			{
				if((Fila[Inicio] / 1000) == 4)
					achou = 1;
				else
				  Inicio = (Inicio + 1)%tam;
			}
			
			if(achou == 0)
			{
				Inicio = Inicio_aux;
				while((Inicio <= *Fim) && (achou == 0))
				{
					if((Fila[Inicio] / 1000) == 1)
						achou = 1;
					else
					  Inicio = (Inicio + 1)%tam;
				}
			}

			if(achou == 1)
			{
			  //realocando as posições na fila
		    for(int a = *Fim; a >= Inicio; a--)
		    {
			  	Fila[(a + 1)%tam] = Fila[a];
		    }

		    *Fim       = (*Fim + 1)%tam; //*Fim avança uma posição
		    Fila[Inicio] = valor;
		  }
		  else
		  {
		    *Fim       = (*Fim + 1)%tam; //*Fim avança uma posição
		    Fila[*Fim] = valor;
		  }
		}
		else if((valor / 1000) == 3) //DEFICIENTE
		{
			while((Inicio <= *Fim) & ((Fila[(Inicio + 1)%tam] / 1000) == 3))
			{
				Inicio = (Inicio + 1)%tam;
			}
			
			//realocando as posições na fila
	    for(int a = *Fim; a > Inicio; a--)
	    {
		  	Fila[(a + 1)%tam] = Fila[a];
	    }
    
	    *Fim       = (*Fim + 1)%tam; //*Fim avança uma posição
			Fila[(Inicio + 1)%tam] = valor;
		
		}
  }
}

void remover_fila(int *Inicio, int *Fim) //*Inicio avança uma posição
{
	if(*Inicio != *Fim)
	{
		*Inicio = (*Inicio + 1)%tam;
	}
}

void imprimir_fila(int *Fila, int Inicio, int Fim)
{
	while(Inicio != Fim)
	{
		Inicio = (Inicio + 1)%tam;
		printf("%d \n", Fila[Inicio]);
	}
}

int qtd_elementos(int Inicio, int Fim)
{
	if(Fim < Inicio)
	  return Fim + (tam - Inicio) + 1;
	else
		return Fim - Inicio + 1;
}

void esvaziar_fila(int *Fila, int Inicio, int Fim)
{
	while(Inicio != Fim)
	{
		Inicio = (Inicio + 1)%tam;
		Fila[Inicio] = 0;
	}
}

main()
{
	//Variaveis
	int Fila[tam], Inicio, Fim, op, st_pessoa;
	int n = 1000;
	int i = 2000;
	int d = 3000;
	int g = 4000;

	iniciar_fila(&Inicio, &Fim);
  
  do{
			 printf("1 - Inserir uma pessoa na fila\n");
			 printf("2 - Atender pessoa\n");
			 printf("3 - Mostrar fila\n");
			 printf("0 - Sair\n");
			 scanf("%d", &op);
			 
			 if(op == 1)
			 {
				 printf("Escolha um tipo de pessoa para entrar na fila:\n");
				 printf("1 - Normal\n");
				 printf("2 - Idoso\n");
				 printf("3 - Deficiente\n");
				 printf("4 - Gestante\n");
				 scanf("%d", &st_pessoa);
				 
				 if((st_pessoa > 0) || (st_pessoa < 5))
				 {
					 if(st_pessoa == 1)
					   inserir_prioridade(Fila, Inicio, &Fim, n++);
					 else if(st_pessoa == 4)
					   inserir_prioridade(Fila, Inicio, &Fim, g++);
					 else if(st_pessoa == 2)
					   inserir_prioridade(Fila, Inicio, &Fim, i++);
					 else
					   inserir_prioridade(Fila, Inicio, &Fim, d++);
				 }
				 
			 }else if(op == 2)
			 {
				 remover_fila(&Inicio, &Fim);
				 
			 }else if(op == 3)
			 {
			   imprimir_fila(Fila, Inicio, Fim);
			 }
  
  }while(op != 0);

}
