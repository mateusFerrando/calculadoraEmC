#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "parser.h"


int main(){
    habilitar_log();
    int op = 0;
    printf("-Processador de expressoes aritmeticas-\n");
    while(1){
        memset(buffer, 0, MAX_BUFFER);
        printf("= ");
        fgets(buffer, sizeof(buffer), stdin);
        No* no = gerar_arvore(buffer);
        if(no){
            printf("\nSelecione uma opcao para a expressao lida:\n");
            printf("\n1 - Calcular express�o");
            printf("\n2 - Calcular express�o passo a passo");
            printf("\n3 - Mostrar equivalente em nota��o polonesa");
            printf("\n4 - Mostrar express�o parentizada");
            printf("\n5 - Verificar se existe divis�o por ");
            printf("\n6 - Ler outra express�o do teclado\n");
            scanf("%d",&op);

            switch(op){
            case 1 :
                break;
            case 2 :
                break;
            case 3 :
                imprimir_preordem(no);
                break;
            case 4 :
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
