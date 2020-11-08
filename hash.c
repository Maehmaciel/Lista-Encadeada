#include<stdio.h>
#include <string.h>
#include<malloc.h>

#define MAX_PARTICOES 100

typedef struct n
{char nome[30];
 int info;
 int vot;
 struct n *prox;
}item;
int paart;
typedef struct
{
 item *table[MAX_PARTICOES];
 int n_particoes;
} hash;

void inicializa(hash *h1, int n)
{
 int i;
 for(i=0; i < n; i++)
 {
  h1->table[i] = NULL;
 }
 h1->n_particoes = n;
}

int divisao_inteira(int valor, int n_particoes)
{
 int resto;

 resto = valor % n_particoes;
 return resto;
}

void insere(hash *h1)
{ item *p;
p = (item*)malloc(sizeof(item));
 int part,c,b;

printf("\n\nDigite um nome: \n");
scanf("%s",p->nome);
b=strlen(p->nome);
c=funhash(p->nome,b);
 part = divisao_inteira(c , h1->n_particoes);


 printf("%s",p->nome);
 p->info = c;
 p->vot = 0;
 p->prox =  h1->table[part];
 h1->table[part] = p;
 paart=h1->n_particoes;
}

void imprime_particao(hash h1, int i)
{
 item *p;

 p = h1.table[i];
 while(p != NULL)
 {
  printf("->%s:%i",p->nome,p->info);
  p = p->prox;
 }
 
}

void imprime_hash(hash h1)
{
 int i;

 printf("\n TABELA DE ESPALHAMENTO \n");

 for(i=0; i<h1.n_particoes; i++)
 {
  printf("[ %d ] ",i);
  imprime_particao(h1,i); printf("\n");
 }
}

int funhash(char *a,int b)
{
int i=0,resp=0;
//printf("\n%s %i\n",a,b);
while(i<b)
{
//printf("%i \n",a[i]);

int nv=(int)a[i];
//printf("Num:%i \n",nv);
resp=resp+nv;

i++;
}
return resp;
}

 novoc (hash numeros)
{

 
 int valor,cand,i=0, particoes;

 system("cls");

 printf("Informe o numero de particoes: ");
 scanf("%d", &particoes);
printf("Informe a quantidade de candidatos a serem cadasrados: ");
 scanf("%d", &cand);


 inicializa(&numeros,particoes);


 while(cand > i)
 {	
  insere(&numeros);
  imprime_hash(numeros);
	
	i++;
 }
menu(numeros);
}

votar(hash h1)
{
}

menu()
{int i;
hash novo;
	printf("Insira uma opçao: \n");
	printf("1-Cadastrar Participantes\n");
	printf("2-Votar\n");
	printf("3-Buscar canidato\n");
	printf("4-Mostrar o total de votos e o resultado\n");
	printf("5-finalizar\n");
	scanf("%i",&i);
	if(i==1){
	novoc(novo);
}
	if(i==2)
	{
	votar(novo);
	}
 }

 main()
{
	menu();
}

