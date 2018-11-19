#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

typedef struct No{
    int livre;
    char* token;
    struct No* esquerda;
    struct No* direita;

} No;

No* criar_arvore(char* chave);
No* inserir(No* arvore, No* esquerdo, No* direito);
void destruir_arvore(No* no);
void imprimir_preordem(No* no);
void imprimir_simetrica(No* no);
void imprimir_posordem(No* no);


#endif // ARVORE_H_INCLUDED
