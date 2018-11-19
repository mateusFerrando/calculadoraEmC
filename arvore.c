#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>


No* criar_arvore(char* chave){
    No* no = malloc(sizeof(No));
    no->token = chave;
    no->esquerda = NULL;
    no->direita = NULL;
    no->livre = 1;

    return no;
}

void destruir_arvore(No* no){

    if(no->direita) destruir_arvore(no->direita);
    if(no->esquerda) destruir_arvore(no->esquerda);

    free(no->token);
    free(no);

}

No* inserir(No* arvore, No* esquerdo, No* direito){
    arvore->esquerda = esquerdo;
    arvore->direita = direito;

    return arvore;
}

void imprimir_preordem(No* no){
    printf("%s",no->token);
    if(no->esquerda!=NULL){
        imprimir_preordem(no->esquerda);
    }

    if(no->direita) imprimir_preordem(no->direita);
}

void imprimir_simetrica(No* no){

    if(no->esquerda!=NULL){
        imprimir_simetrica(no->esquerda);
    }
    printf("%s",no->token);
    if(no->direita!=NULL){
        imprimir_simetrica(no->direita);

    }
}
void imprimir_posordem(No* no){
    if(no->esquerda!=NULL){
        imprimir_posordem(no->esquerda);
    }
    if(no->direita!=NULL){
        imprimir_posordem(no->direita);
    }

    printf("%c",no->token);
}
