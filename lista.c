#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_STR_LEN 50
#define TAM_MAX 50

typedef struct {
    char dados[TAM_MAX][TAM_STR_LEN];
    int quantidade;
} ListaEstatica;

void inicializarListaEstatica(ListaEstatica *Lista);

void inserirListaEstatica(ListaEstatica *Lista);
void removerListaEstatica(ListaEstatica *Lista);
void listarListaEstatica(const ListaEstatica *Lista);

typedef struct No {
    char* dado;
    struct No *proximo;
} No;

typedef No* Listaencadeada;

void inicializarListaencadeada(Listaencadeada *Lista);

void inserirListaencadeada(Listaencadeada *Lista, const char *texto);
void removerListaencadeada(Listaencadeada *Lista, const char *texto);
void listarListaencadeada(const Listaencadeada *Lista);
void LiberarListaencadeada(Listaencadeada *Lista);

void menuListaEstatica();
void menuListaencadeada();

int main() {
    int opcao;
    do{
        printf("Escolha o tipo de lista:\n");
        printf("1. Lista Estatica\n");
        printf("2. Lista Encadeada\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer de entrada

        switch (opcao) {
            case 1:
                menuListaEstatica();
                break;
            case 2:
                menuListaencadeada();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao !=0);
 return 0;
} 

void InicializarListaEstatica(ListaEstatica *Lista) {
    Lista->quantidade=0;
}
     
void InserirListaEstatica(ListaEstatica *Lista, const char* texto) {
    if (Lista->quantidade == TAM_MAX) {
        printf("Lista cheia. Não é possível inserir.\n");
        return;
    }
    strcpy(Lista->dados[Lista->quantidade], texto);
    Lista->quantidade++;
    printf("Texto \"%s\" inserido com sucesso.\n", texto);

}

void RemoverListaEstatica(ListaEstatica *Lista, const char* texto) {
    int i, pos = -1;
    for (i = 0; i < Lista->quantidade; i++) {
        if (strcmp(Lista->dados[i], texto) == 0) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        printf("Texto \"%s\" não encontrado na lista.\n", texto);
        return;
    }
    for (i = pos; i < Lista->quantidade - 1; i++) {
        strcpy(Lista->dados[i], Lista->dados[i + 1]);
    }

    Lista ->quantidade--;
    printf("Texto \"%s\" removido com sucesso.\n", texto);
}