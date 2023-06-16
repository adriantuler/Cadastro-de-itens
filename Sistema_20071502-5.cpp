#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#include <locale.h>

typedef struct cadastro{
	char titulo_da_obra[50];
    int edicao;
    char nome_do_autor[50];
    char editora[50];
    int isbn;
    int qtd_exemplares;
    int caixa;
    int ano;
    int categoria;
} Cadastroproduto;

void file(Cadastroproduto produto[MAX]);
void identificacao();
int contarRegistro(Cadastroproduto produto[MAX]);
void cadastrarObras(Cadastroproduto produto[MAX]);
void ListarLivros(Cadastroproduto produto[MAX]);
void ListarRevistas(Cadastroproduto produto[MAX]);
void ListarProdutosCategoria(int buscaCategoria, Cadastroproduto produto[MAX]);

int main(){
	Cadastroproduto produto[MAX];
	setlocale(LC_ALL, "Portuguese");
	int x,op,buscaCategoria,resp;
	FILE *arq;
	file(produto);
	do{
		identificacao();	
		for(x=0; x<41; x++) printf("=");		
        printf("\n1 - Incluir o registro das obras\n");
        printf("2 - Listar todos os livros\n");
        printf("3 - Listar todas as revistas\n");
        printf("4 - Listar as obras por caixa\n");
        printf("0 - Sair\n\n");
        for(x=0; x<41; x++) printf("=");printf("\n");
		printf(" Selecione uma opc�o por favor =>: ");
		scanf("%d", &op);
		switch(op){
			case 1:
				resp='s';
                while((resp=='S')||(resp=='s')){
                cadastrarObras(produto);
                system("cls");
                printf("Deseja cadastrar novo produto[S] - SIM [N] - N�O: ");
                //contarRegistro(produto);
                scanf(" %c",&resp);
                }	
			break;
			case 2:	
				ListarLivros(produto);
				printf("\n");
				system("pause");
				break;
		case 3: 		
				ListarRevistas(produto);
				printf("\n");
				system("pause");
				break;
			case 4: 
				printf("Informe a Caixa do produto: ");
				scanf("%d", &buscaCategoria);
				ListarProdutosCategoria(buscaCategoria, produto);
				printf("\n");
				system("pause");
				break;
			case 0:
				arq = fopen("dadosProdutos.txt", "w");
				for (int x=0;x<contarRegistro(produto);x++)
				fprintf(arq,"%s,%d,%s,%s,%d,%d,%d,%d,%d,\n",produto[x].titulo_da_obra,produto[x].edicao,produto[x].nome_do_autor,produto[x].editora,produto[x].isbn,produto[x].qtd_exemplares,produto[x].caixa,produto[x].ano,produto[x].categoria);
            	fclose(arq);
				printf("\nSaindo do sistema!!!");
				break;
			default:
				printf("Valor indefinido");
				system("pause");
				break;
		}	
	}while(op!=0);
	return 0;
}

void file(Cadastroproduto produto[MAX]){
	FILE *arq = fopen("dadosProdutos.txt", "r");
	if( arq == NULL ){
        perror("N�o existe o arquivo obras.txt");
        getchar();
        exit(-1);
    }
    int cont;
    while( fscanf(arq," %*[^\n]") != EOF)
    cont++;
    rewind(arq);
    cont--;
	for(int x=0; x<=cont; x++)
    fscanf(arq,"%[^,],%d,%[^,],%[^,],%d,%d,%d,%d,%d,\n",produto[x].titulo_da_obra,&produto[x].edicao,produto[x].nome_do_autor,produto[x].editora,&produto[x].isbn,&produto[x].qtd_exemplares,&produto[x].caixa,&produto[x].ano,&produto[x].categoria);
	fclose(arq);
}

void identificacao(){
	system("cls");
		for(int x=0; x<65; x++) printf("=");printf("\n");
		printf("NOME: �DRIAN HONORIO DE FARIA\n");
        printf("CURSO: ENGENHARIA DE SOFTWARE\n");
        printf("RA: 20071502-5\n\n");
	
		for(int x=0; x<65; x++) printf("=");printf("\n");
}

int contarRegistro(Cadastroproduto produto[MAX]){
	int x;
		for( x = 0; x < MAX; x++)
			if(produto[x].categoria==0){
			break;	
			}
			return x;
}

void cadastrarObras(Cadastroproduto produto[MAX]){
	identificacao();
	int quantidadeproduto = contarRegistro(produto);
		printf ( "\n Digite o titulo da obra: \n");
		fflush(stdin);
		gets(produto[quantidadeproduto].titulo_da_obra);
		printf ( "\n Digite o numero da edicao da obra: \n");
		scanf("%d",&produto[quantidadeproduto].edicao);
		printf ( "\n Digite o nome do autor: \n");
		fflush(stdin);
		gets(produto[quantidadeproduto].nome_do_autor);
		printf ( "\n Digite o nome da editora: \n");
		fflush(stdin);
		gets(produto[quantidadeproduto].editora);
		printf ( "\n Digite o numero isbn da obra: \n");
		scanf("%d",&produto[quantidadeproduto].isbn);
		printf ( "\n Digite a quantidade de exemplares da obra: \n");
		scanf("%d",&produto[quantidadeproduto].qtd_exemplares);
		printf ( "\n Digite o numero da caixa que vai guardar a obra: \n");
		scanf("%d",&produto[quantidadeproduto].caixa);
		printf ( "\n Digite o ano da obra: \n");
		scanf("%d",&produto[quantidadeproduto].ano);
		printf ( "\n Digite 1 para cotegoria livro ou 2 para categoria revista\n");
		scanf("%d",&produto[quantidadeproduto].categoria);
	}

	void ListarLivros(Cadastroproduto produto[MAX]){
	identificacao();
	int quantidadeproduto = contarRegistro(produto);
	printf("\n>>>> Lista de Produtos do Tipo Livros <<<< \n");
	for(int x = 0; x < quantidadeproduto; x++){
	if(produto[x].categoria==1)
		printf("Titulo: %s \nEdicao: %d\nNome do autor: %s\nEditora: %s\n isbn: %d\nQuantidade de Exemplares: %d\nCaixa: %d\nAno: %d\n\n",produto[x].titulo_da_obra,produto[x].edicao,produto[x].nome_do_autor,produto[x].editora,produto[x].isbn,produto[x].qtd_exemplares,produto[x].caixa,produto[x].ano);
	}
	for(int x=0; x<97; x++)printf("="); 
	printf("\n");
}

	void ListarRevistas(Cadastroproduto produto[MAX]){
	identificacao();
	int quantidadeproduto = contarRegistro(produto);
	printf("\n>>>> Lista de Produtos do Tipo Revista <<<< \n");
	for(int x = 0; x < quantidadeproduto; x++){
		if(produto[x].categoria==2)
		printf("Titulo: %s \nEdicao: %d\nNome do autor: %s\nEditora: %s\n isbn: %d\nQuantidade de Exemplares: %d\nCaixa: %d\nAno: %d\n\n",produto[x].titulo_da_obra,produto[x].edicao,produto[x].nome_do_autor,produto[x].editora,produto[x].isbn,produto[x].qtd_exemplares,produto[x].caixa,produto[x].ano);
	}
	for(int x=0; x<97; x++) printf("="); 
	printf("\n");
}

void ListarProdutosCategoria(int buscaCategoria, Cadastroproduto produto[MAX]){	
	identificacao();
	int quantidadeproduto = contarRegistro(produto);
	printf("\n>>>> Lista de Caixa <<<< \n");
	if (buscaCategoria == 1) 
		printf("Categoria pesquisada: Caixa 01 \n");	
	else if (buscaCategoria == 2) 
		printf("Categoria pesquisada: Caixa 02 \n");	
	else if (buscaCategoria == 3) 
		printf("Categoria pesquisada: Caixa 03 \n");	
	
printf("\n>>>> Lista de Livros da caixa %d <<<< \n\n",buscaCategoria);
for(int x=0;x<quantidadeproduto;x++)
	if(produto[x].caixa == buscaCategoria && produto[x].categoria==1)
	printf("Titulo: %s \nEdicao: %d\nNome do autor: %s\nEditora: %s\n isbn: %d\nQuantidade de Exemplares: %d\nCaixa: %d\nAno: %d\n\n",produto[x].titulo_da_obra,produto[x].edicao,produto[x].nome_do_autor,produto[x].editora,produto[x].isbn,produto[x].qtd_exemplares,produto[x].caixa,produto[x].ano);
printf("\n>>>> Lista de Revista da caixa %d <<<< \n\n",buscaCategoria);
for(int x=0;x<quantidadeproduto;x++)
if(produto[x].caixa == buscaCategoria && produto[x].categoria==2)
	printf("Titulo: %s \nEdicao: %d\nNome do autor: %s\nEditora: %s\n isbn: %d\nQuantidade de Exemplares: %d\nCaixa: %d\nAno: %d\n\n",produto[x].titulo_da_obra,produto[x].edicao,produto[x].nome_do_autor,produto[x].editora,produto[x].isbn,produto[x].qtd_exemplares,produto[x].caixa,produto[x].ano);
for(int x=0; x<97; x++) printf("="); printf("\n");
}
	


