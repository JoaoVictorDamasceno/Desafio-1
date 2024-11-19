#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    char armarios=0;
    int opcao=0, posicao;
    srand(time(NULL));
    do{
        printf("Status dos armários:\n");
        for(int i=7;i>=0;i--){
            if(armarios & (1<<i)) {
                printf("Armário %d: Ocupado\n", i);
            }else{
                printf("Armário %d: Livre\n", i);
            }
        }
        printf("\nEscolha uma opção:\n");
        printf("1. Ocupar armário\n");
        printf("2. Liberar armário\n");
        printf("3. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:{
                int armario_ocupado=0;
                for(int i=0;i<8;i++) {
                    if(!(armarios & (1<<i))){
                        armario_ocupado=1;
                        break;
                    }
                }
                if (!armario_ocupado){
                    printf("Todos os armários estão ocupados\n");
                    break;
                }
                do{
                    posicao=rand()%8;
                }while(armarios & (1<<posicao));
                armarios |= (1<<posicao);
                printf("Armário %d foi ocupado\n", posicao);
                break;
            }
            case 2:
                printf("Digite o número do armário para liberar (0-7): ");
                scanf("%d", &posicao);
                if(posicao<0 || posicao>7) {
                    printf("Número do armário inválido\n");
                }else if(!(armarios & (1<<posicao))){
                    printf("O armário %d já está livre\n", posicao);
                }else{
                    armarios &= ~(1<<posicao);
                    printf("Armário %d foi liberado\n", posicao);
                }
                break;
            case 3:
                printf("Finalizando\n");
                break;
            default:
                printf("Opção inválida\n");
        }
        printf("\n");
    }while(opcao!=3);
    return 0;
}