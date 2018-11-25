#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "parser.h"


int main(){
    int sair = 1;
    printf("-Processador de expressoes aritmeticas-\n");
    while(sair){
        memset(buffer, 0, MAX_BUFFER);
        printf("= ");
        fgets(buffer, sizeof(buffer), stdin);
        No* no = gerar_arvore(buffer);
        if(no){
            printf("-Expressao carregada com sucesso-\n");
            sair = menu(no);
            destruir_arvore(no);
        }
    }
    return 0;
}

