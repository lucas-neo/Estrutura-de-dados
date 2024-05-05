#include <stdio.h>
#include <stdlib.h>
#define TAM 31
//Teste
//----------------------------

void inicializarTabela(int t[]){
    int i;
    for(i=0 ; i<TAM ; i++)
    t[i] = 0;
}
//----------------------------

int funcaoHash (int chave){
    return chave%TAM;
}
//----------------------------

void inserir(int t[], int valor){
    int id = funcaoHash(valor);
    while(t[id]!=0)
        id = funcaoHash(id+1);
    t[id] = valor;
}
//----------------------------

int buscar(int t[], int chave){
    int id = funcaoHash(chave);
    printf("\nIndice Gerado: %d\n", id);
    while(t[id]!=0){
        if(t[id]==chave)
            return t[id];
        else
            id=funcaoHash(id+1);
    }
    return -1;
}
//----------------------------

void imprimir(int t[]){
    int i;
    for (i=0; i<TAM; i++)
        printf("%d = %d\n", i, t[i]);
}

int main(void){
    int opcao, valor, retorno, tabela[TAM];
    inicializarTabela(tabela);
    do{
        printf("\n0-Sair\n1-Inserir\n2-Buscar\n3-Listar\n");
        scanf("%d", &opcao);
        fflush(stdin);
        switch(opcao){
            case 1:
                printf("\nValor: ");
                scanf("%d", &valor);
                inserir(tabela, valor);
                break;
            case 2:
                printf("\nValor:");
                scanf("%d", &valor);
                retorno = buscar(tabela,valor);
                if (retorno!=-1)
                    printf("\nValor encontrado: %d\n", retorno);
                else 
                    printf("\nValor não encontrado\n");
                break;
            case 3:
                imprimir(tabela);
            break;
            defaut: printf("\nOpção inválida\n");
        }

    } while(opcao!=0);
    return 0;
}