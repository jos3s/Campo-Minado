#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "campominado.h"

int main(){
    setlocale(LC_ALL,"");
    puts("Digite as dimensões do campo minado:");
    scanf("%d %d",&m,&n);
    srand((unsigned) time(NULL));
    campominado(dificuldade());
    puts("");
    criar(mt);
    system("cls");
    imprimir(m,n);
    colocarbombas(m,n);
    jogar(m,n);
return 0;
}