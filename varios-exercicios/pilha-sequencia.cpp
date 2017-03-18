#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define TAM 10

typedef struct
{
	int pont;
	int valor[TAM];

}Pilha;

//Cria uma pilha vazia
void criaPilha(Pilha **P)
{
  (*P) = (Pilha*)malloc(sizeof(Pilha));
	(*P)->pont = -1;
}

//Verifica se a pilha está cheia
int isCheia(Pilha *P) //1 - cheia
{
	Pilha *aux;
	aux = P;

	if(aux->pont == TAM)
	  return 1;
	else return 0;
}

//Verifica se a pilha está vazia
int isVazia(Pilha *P) //1 - vazia
{
	Pilha *aux;
	aux = P;
	if(aux->pont == -1)
	  return 1;
	else return 0;
}

//Inseri um valor na pilha
void push(Pilha **P, int valor)
{
	if(!isCheia(*P))
	{
	  //(*P)->pont++;
	  (*P)->valor[++(*P)->pont] = valor;
    }
}

//Remove valor da pilha
int pop(Pilha **P)
{
	if(!isVazia(*P))
	{
	  return (*P)->valor[(*P)->pont--]; //Primeiro retorna o valor depois decrementa o pont;
	  //--(*P)->pont;
    }else
      return 0;
}

//Imprimi elementos da pilha
void imprimiPilha(Pilha *P)
{
	for(int i = P->pont; i > -1; i--)
	{
		printf("Valor -----> %d\n", P->valor[i]);
	}
}

void sequencia_numerica(int sequencia[], int num_algarismos, int i, int pos, Pilha **P)
{
  if( (i < num_algarismos) || (pos < num_algarismos))//verificar a quantidade de algarismos digitados
  {
	  if((sequencia[pos]) == ((*P)->valor[(*P)->pont]))
	  {
	  	pop(&(*P)); printf("R");
	  	pos++;
	  	sequencia_numerica(sequencia, num_algarismos, i, pos, &(*P));
  	}
		else if(i < num_algarismos)
    {
      push(&(*P), i++); printf("I");
      sequencia_numerica(sequencia, num_algarismos, i, pos, &(*P));
		}
		else
		{
			printf("\nSequencia invalida!");
		}
	}
}


main()
{
	Pilha *p;
	int sequencia[6], pos = 1;
	int num_algarismos = 0;

	printf("Digite uma sequencia de ate 5 numeros, de 1 a 5\n");
	printf("Quantos algarismos existira o numero informado?\n");
	scanf("%d", &num_algarismos);
	printf("Digite os numeros:\n");
	for(int i = 1; i <= num_algarismos; i++)
	{
	  scanf("%d", &sequencia[i]);
	}
	
	criaPilha(&p);
	printf("\nA sequencia de operacoes e: ");
	sequencia_numerica(sequencia, num_algarismos + 1, 1, 1, &p);

	getch();
}

