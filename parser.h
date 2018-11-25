#ifndef CALCULADORA_H_INCLUDED
#define CALCULADORA_H_INCLUDED

#include "arvore.h"

#define MAX_BUFFER 1024
extern char buffer[MAX_BUFFER];

No* parentesis();
double avaliar_expressao(No* no);
No* operacao();
No* parentesis();
No* gerar_arvore(char* buffer);
void organizar_precedencias(No* no);
void colocar_espacos(char* buffer);
void habilitar_log();
void inline __copiar(char *dest, char *src, size_t n);
void parentizada(No* no);
double passo_a_passo(No* no);
void resultado_final(No* no);
double resultado(No* no);
void divisao_por_zero(No* no);
int menu(No* no);

#endif // CALCULADORA_H_INCLUDED
