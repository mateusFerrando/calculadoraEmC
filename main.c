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
            printf("\n1 - Calcular expressão");
            printf("\n2 - Calcular expressão passo a passo");
            printf("\n3 - Mostrar equivalente em notação polonesa");
            printf("\n4 - Mostrar expressão parentizada");
            printf("\n5 - Verificar se existe divisão por ");
            printf("\n6 - Ler outra expressão do teclado\n");
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
