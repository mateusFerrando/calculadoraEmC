#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "parser.h"


int main(){
    habilitar_log();
    int op = 0;
    int sair = 1;

    printf("-Processador de expressoes aritmeticas-\n");
    memset(buffer, 0, MAX_BUFFER);
    printf("= ");
    fgets(buffer, sizeof(buffer), stdin);
    No* no = gerar_arvore(buffer);
    while(sair){
        if(no){
            printf("\nSelecione uma opcao para a expressao lida:\n");
            printf("\n1 - Calcular expressao");
            printf("\n2 - Calcular expressao passo a passo");
            printf("\n3 - Mostrar equivalente em notacao polonesa");
            printf("\n4 - Mostrar expressao parentizada");
            printf("\n5 - Verificar se existe divisao por ");
            printf("\n6 - Ler outra expressão do teclado\n");
            scanf("%d",&op);
            switch(op){
            case 0 :
                break;
            case 1 :
                imprimir_posordem(no);
                break;
            case 2 :
                imprimir_simetrica(no);
                break;
            case 3 :
                imprimir_preordem(no);
                break;
            case 4 :
                parentizada(no);
                break;
            case 5 :
                break;
            case 6 :
                destruir_arvore(no);
                main();
                break;
            }
        }
    }
    return 0;
}
