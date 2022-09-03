#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>


#define MAX 21
//ESTRUTURA
struct Caixa{
	char cor[MAX];
	struct Caixa *prox;
	
};

Caixa *topo; //ponteiro para o topo da pilha 
char cor[MAX];

int cor_caixa(){
	system("cls");
	printf("\t\tEntre com a cor da caixa:  ");
	fflush(stdin);
	fgets(cor,MAX,stdin);
	
	
}

void empilha_caixa(){
	cor_caixa(); // chamar a função
	//alocando memoria para novos elementos
	Caixa *pnovo = (Caixa*)malloc (sizeof(Caixa));
	strcpy (pnovo -> cor,cor);
	pnovo ->prox =NULL;
	
	if(topo == NULL)//se a pilha estiver vazia
	topo = pnovo; //topo recebe o novo elemento
	
	else{
		pnovo -> prox= topo;
		topo=pnovo;
	}
		
}
void desempilhar_caixa(){
	Caixa *aux;
	
	if( topo == NULL){
			printf("\t\tERROOOO, Empilhamento de Caixas vazia:  ");
			return;
			
	}else {
		aux = topo;
		topo = topo ->prox;
		printf("\t\tCaixa removida do topo:  ", aux ->cor);
		free(aux);
		
	}
	
}
//função listar
void listar_caixas(){
	Caixa *aux;
	aux=topo;
		printf("\t\tEmpilhamento:  ");
		while(aux != NULL){
			printf("Cor %s", aux ->cor);
			aux = aux ->prox;
		}
	
}

int main(){
	char op;
	topo = NULL;
	
	do{
		
		system("cls");
		printf("\t\tEmpilhamento de caixas de copos: ");
		printf("\n\n(E)empilhar Caixa ");
		printf("\n\n(L)listar estoque de Caixas ");
		printf("\n\n(D)emsempilhar Caixa ");
		printf("\n\n(S)air do programa ");
		printf("\n\n Digite uma opção:  ");
		
		op =toupper (getche());
		
		
		switch (op){
			
			case 'E' : empilha_caixa();break;
			case 'L' : listar_caixas();break;
			case 'S' : exit(0);
			case 'D' : desempilhar_caixa();break;
			default : 	printf("\n\n Opção Invalida  ");		
		}
		system("PAUSE");
		
	}while (op!= 'S');
	
	
	
return 0;
}
	
	
	
	
	
	
	
	
	
	

