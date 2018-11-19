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

#endif // CALCULADORA_H_INCLUDED
