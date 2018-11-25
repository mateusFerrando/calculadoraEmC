#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "parser.h"

int conta_par = 0, init = 1;
char* pch;
char buffer[MAX_BUFFER];
int permitir_log = 0, conta_log = 1;

void habilitar_log(){
    permitir_log = 1;
}

void log_msg(const char* format, ...){
    va_list args;
    va_start (args, format);
    if(permitir_log){
        printf("[LOG %d] ", conta_log++);
        vprintf (format, args);
    }
    va_end (args);
}

int eh_numero(char* token){
    int i, conta_ponto = 0, conta_digito = 0, conta_outro = 0;
    for(i = 0; i < strlen(token); i++){
        if(isdigit(token[i])) conta_digito++;
        else if(token[i] == '.') conta_ponto++;
        else if (token[i] == '\n');// ignorar
        else conta_outro++;
    }
    return (conta_ponto <= 1 && conta_outro == 0 && conta_digito > 0);
}

void organizar_precedencias(No* no){

    if(!strcmp(no->token, "*") || !strcmp(no->token, "/")){
        No* dir = no->direita;
        No* esq = no->esquerda;
        if(dir->livre && (!strcmp(dir->token, "+") || !strcmp(dir->token, "-"))){
            log_msg("Rotacionando sub-expressão da árvore\n");
            char* op_dir = dir->token;
            char* op_no =  no->token;

            No* dir_dir = dir->direita;
            No* dir_esq = dir->esquerda;

            dir->token = op_no;
            inserir(dir, esq, dir_esq);

            no->token = op_dir;
            inserir(no, dir, dir_dir);
        }
    }
    if(no->direita) organizar_precedencias(no->direita);
    if(no->esquerda) organizar_precedencias(no->esquerda);
}

No* operacao(){

    No* no, *dir, *esq;
    if(init){
         init = 0;
         pch = strtok (buffer," ");
    } else {
         pch = strtok (NULL," ");
    }
    if (pch){
        if(!strncmp(pch, "(", 1)){
            conta_par++;
            esq = parentesis(); // no esquerdo eh um parentesis
        } else if (eh_numero(pch)){
            esq = criar_arvore(strdup(pch)); // ou eh simplesmente um numero
        } else {
            printf("Esperava um numero ou parentesis, mas veio %s, tratando como zero\n", pch);
            esq = criar_arvore(strdup("0")); // ou eh simplesmente um numero
        }
    }
    pch = strtok (NULL," ");
    if(!pch){
        return esq;
    }
    if(!strncmp(pch, ")", 1)){
        conta_par--;
        return esq;
    }
    if (pch){
        if(!strncmp(pch, "+", 1) || !strncmp(pch, "-", 1) ||
        !strncmp(pch, "*", 1) || !strncmp(pch, "/", 1)){ // no eh uma operacao
            no = criar_arvore(strdup(pch));
        } else {
            destruir_arvore(esq);
            printf("operacao invalida: %s\n", pch);
            return NULL;
        }
    }
    dir = operacao(); // recursivamente define o no direito
    if(!dir){ // destroi tudo se der problema no direito
        destruir_arvore(no);
        destruir_arvore(esq);
        return NULL;
    }
    inserir(no, esq, dir); // unifica tudo
    return no;
}

No* parentesis(){
    No* no = operacao(pch);
    if(no) no->livre = 0; // se um no eh um parentesis, nao pode ser modificado no organizar_precedencias
    return no;
}

No* gerar_arvore(char* buffer){
    No* no;
    init = 1;
    conta_par = 0;
    colocar_espacos(buffer);
    no = operacao();
    if(conta_par != 0){
        printf("Número errado de parentesis\n");
        if(no) destruir_arvore(no);
        no = NULL;
    }
    if(no) organizar_precedencias(no);
    return no;
}

void __copiar(char *dest, char *src, size_t n){
    char* src_fim = (char*)src+n-1;
    char* dest_fim = (char*)dest+n-1;
    while(n-- > 0) *dest_fim-- = *src_fim--;
}

void colocar_espacos(char* buffer){

    int tamanho = strlen(buffer)+1;
    int i = 0;

    while(buffer[i] != '\n'){
        if(buffer[i] == '(' && buffer[i+1] != ' '){
            __copiar(&buffer[i+2], &buffer[i+1], tamanho-i);
            buffer[i+1] = ' ';
            tamanho++;
        } else if (buffer[i] == ')' && buffer[i-1] != ' '){
            __copiar(&buffer[i+1], &buffer[i], tamanho-i);
            buffer[i] = ' ';
            tamanho++;
        } else if(buffer[i] == '+' || buffer[i] == '-' ||
                buffer[i] == '*' || buffer[i] == '/'){
            if(buffer[i+1] != ' '){
                __copiar(&buffer[i+2], &buffer[i+1], tamanho-i);
                buffer[i+1] = ' ';
                tamanho++;
            }
            if(buffer[i-1] != ' '){
                __copiar(&buffer[i+1], &buffer[i], tamanho-i);
                buffer[i] = ' ';
                tamanho++;
            }
        }
        log_msg("analisado [%c] %s", buffer[i], buffer);
        i++;
    }
    buffer[i] = '\0';
}

void parentizada(No* no){
    if(no->esquerda!=NULL){
        printf("(");
        imprimir_simetrica(no->esquerda);
    }
    printf(" %s ",no->token);
    if(no->direita!=NULL){
        printf("(");
        imprimir_simetrica(no->direita);
        printf(")");
    }
    printf(")");
}

