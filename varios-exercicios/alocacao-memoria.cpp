#include<stdio.h>
#include<conio.h>
#include <stdlib.h>

int *p, i;

void leitura(int q)
{
puts ("Digite as idades...");
 for (i=0; i<q; i++)
   scanf("%d",(p+i));
}

float media (int q)
{
   float s=0;

   for (i=0; i<q; i++)
      s+= *(p+i);
   return s/q;
}

int maior_idade(int *i, int n)
{
	int maior = 0;
	
	for(int i = 0; i < n; i++)
	{
		if(*(p+i) > maior)
			maior = *(p+i);
	}

	return maior;
}

 main()
{
   int n, velho, x, y;
   float m;

   system ("cls");
   puts ("Digite o tamanho do vetor:");
   scanf("%d",&n);
   
   p=(int *) calloc (n, sizeof(int));
   
   leitura (n);
   m = media (n);
   
   printf ("\nMaior idade = %d", maior_idade(p, n));
   
   printf ("\nMedia = %.2f", m);

}

