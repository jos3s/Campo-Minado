#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>


int ** criar(int**mt,int m, int n){  //Cria a matriz a ser exibida
    int i,j;
    mt=(int**)malloc(m*sizeof(int*));
    for(i=0;i<m;i++){
        mt[i]=(int*)malloc(n*sizeof(int));
    }
    return mt;
}

void imprimirmatriz(int **mt,int m,int n){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%c",mt[i][j]);
        }
        puts("");
    }
}

void preencher_para_exibir(int**mt, int m, int n){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            mt[i][j]=143;
        }
    }
}


int main(){
    int m,n;
    int**matriz;
    matriz=criar(matriz,m,n);
  

return 0;
}