#ifndef CAMPOMINADO.H
#define CAMPOMINADO.H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int**mt;
int**mtz;
int m,n;

void criar(){
    int i,j;
    mt=(int**)malloc(m*sizeof(int*));
    for(i=0;i<m;i++){
        mt[i]=(int*)malloc(n*sizeof(int));
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            mt[i][j]=143;
        }
    }
}

void imprimir(int m,int n){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
                printf("%c ",mt[i][j]);
        }
        puts("");
    }
}

void campominado(int d){
    int i,j,a;
    mtz=(int**)malloc(m*sizeof(int*));
    for(i=0;i<m;i++){
        mtz[i]=(int*)malloc(n*sizeof(int));
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            a=rand()%d;
            if(a==1){
                mtz[i][j]=42;
            }else{
                mtz[i][j]=35;
            }
        }
    }
}

void imprimircampo(int m,int n){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%c",mtz[i][j]);
        }
        puts("");
    }
}

int dificuldade(){
    int d;
    printf("Digite a dificuldade (entre 2 a 8):");
    printf("\n 2-Dificil\n 3 \n 4\n 5-Médio\n 6\n 7\n 8-Fácil\n");
    scanf("%d",&d);
    return d;
}

int colocarbombas(int m, int n){
    int i,j,cont=0;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(i==0 && j==0){
                if(mtz[1][0]==42)
                    cont++;
                if(mtz[0][1]==42)
                    cont++;
            }
            else if(i==0 && j<n-1){
                if(mtz[0][j-1]==42)
                    cont++;
                if(mtz[0][j+1]==42)
                    cont++;
                if(mtz[1][j]==42)
                    cont++;
            }
            else if(i==0 && j==n-1){
                if(mtz[0][n-2]==42)
                    cont++;
                if(mtz[1][n-1]==42)
                    cont++;
            }

            else if(i<m-1 && j==0){
                if(mtz[i-1][0]==42)
                    cont++;
                if(mtz[i+1][0]==42)
                    cont++;
                if(mtz[i][1]==42)
                    cont++;
            }
            else if(i<m-1 && j==m-1){
                if(mtz[i-1][n-1]==42)
                    cont++;
                if(mtz[i+1][n-1]==42)
                    cont++;
                if(mtz[i][n-2]==42)
                    cont++;
            }

            else if(i==m-1 && j==0){
                if(mtz[m-2][0]==42)
                    cont++;
                if(mtz[m-2][1]==42)
                    cont++;
            }
            else if(i==m-1 && j<n-1){
                 if(mtz[m-1][j+1]==42)
                    cont++;
                if(mtz[m-1][j-1]==42)
                    cont++;
                if(mtz[m-2][j]==42)
                    cont++;
            }
            else if(i==m-1 && j==n-1){
                if(mtz[m-2][n-1]==42)
                    cont++;
                if(mtz[m-2][n-2]==42)
                    cont++;
            }

            else{
                if(mtz[i-1][j]==42)
                   cont++;
                if(mtz[i+1][j]==42)
                    cont++;
                if(mtz[i][j-1]==42)
                    cont++;
                if(mtz[i][j+1]==42)
                    cont++;


            }

            if(mtz[i][j]!=42){
                mtz[i][j]=cont;
            }
            cont=0;
        }
    }
}

void imprimirbombas(int m,int n){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ",mtz[i][j]);
        }
        puts("");
    }
}

void jogar(int m,int n){
    int a;
    a=bombas(m,n);
    if(a==0){
        jogar(m,n);
    }else{
        imprimir(m,n);
        puts("Você acertou uma bomba, o jogo acabou");
    }
}

int bombas(int m, int n){
    int i,j,l,c;
    printf("Digite linha e coluna:");
    scanf("%d %d",&l,&c);
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(i==l && j==c){
                if(mtz[i][j]!=42){
                    if(i==0 && j==0){
                        if(mtz[1][0]!=42){
                            mt[i][j]=mtz[i][j];
                            imprimireal(m,n,l,c);  return 0;
                        }
                        if(mtz[0][1]!=42){
                            mt[i][j]=mtz[i][j];
                            imprimireal(m,n,l,c);  return 0;
                        }
                    }else if(i==0 && j<n-1){
                        if(mtz[0][j-1]!=42){
                            mt[i][j]=mtz[i][j];
                            imprimireal(m,n,l,c);  return 0;
                        }
                        if(mtz[0][j+1]!=42){
                            mt[i][j]=mtz[i][j];
                            imprimireal(m,n,l,c);  return 0;
                        }
                        if(mtz[1][j]!=42){
                            mt[i][j]=mtz[i][j];
                            imprimireal(m,n,l,c);  return 0;
                        }
                    }else if(i==0 && j==n-1){
                        if(mtz[0][n-2]!=42){
                            mt[i][j]=mtz[i][j];
                            imprimireal(m,n,l,c);  return 0;
                        }
                        if(mtz[1][n-1]!=42){
                            mt[i][j]=mtz[i][j];
                            imprimireal(m,n,l,c);  return 0;
                        }
                    }else if(i<m-1 && j==0){
                        if(mtz[i-1][0]!=42){
                            mt[i][j]=mtz[i][j];
                            imprimireal(m,n,l,c);  return 0;
                        }
                        if(mtz[i+1][0]!=42){
                            mt[i][j]=mtz[i][j];
                            imprimireal(m,n,l,c);  return 0;
                        }
                        if(mtz[i][1]!=42){
                            mt[i][j]=mtz[i][j];
                            imprimireal(m,n,l,c);  return 0;
                        }
                    }else if(i<m-1 && j==m-1){
                        if(mtz[i-1][n-1]!=42){
                            mt[i][j]=mtz[i][j];
                            imprimireal(m,n,l,c);  return 0;
                        }
                        if(mtz[i+1][n-1]!=42){
                            mt[i][j]=mtz[i][j];
                            imprimireal(m,n,l,c);  return 0;
                        }
                        if(mtz[i][n-2]!=42){
                            mt[i][j]=mtz[i][j];
                            imprimireal(m,n,l,c);  return 0;
                        }
                    }
                    else if(i==m-1 && j==0){
                        if(mtz[m-2][0]!=42){
                            mt[i][j]=mtz[i][j];
                            imprimireal(m,n,l,c);  return 0;
                        }
                        if(mtz[m-2][1]!=42){
                            mt[i][j]=mtz[i][j];
                            imprimireal(m,n,l,c);  return 0;
                        }
                    }else if(i==m-1 && j<n-1){
                        if(mtz[m-1][j+1]!=42){
                            mt[i][j]=mtz[i][j];
                            imprimireal(m,n,l,c);  return 0;
                        }
                        if(mtz[m-1][j-1]!=42){
                            mt[i][j]=mtz[i][j];
                            imprimireal(m,n,l,c);  return 0;
                        }
                        if(mtz[m-2][j]!=42){
                            mt[i][j]=mtz[i][j];
                            imprimireal(m,n,l,c);  return 0;
                        }
                    }else if(i==m-1 && j==n-1){
                        if(mtz[m-2][n-1]!=42){
                            mt[i][j]=mtz[i][j];
                            imprimireal(m,n,l,c);  return 0;
                        }
                        if(mtz[m-2][n-2]!=42){
                            mt[i][j]=mtz[i][j];
                            imprimireal(m,n,l,c);  return 0;
                        }
                    }else{
                        if(mtz[i-1][j]!=42){
                            mt[i][j]=mtz[i][j];
                            imprimireal(m,n,l,c);  return 0;
                        }
                        if(mtz[i+1][j]!=42){
                            mt[i][j]=mtz[i][j];
                            imprimireal(m,n,l,c);  return 0;
                        }
                        if(mtz[i][j-1]!=42){
                            mt[i][j]=mtz[i][j];
                            imprimireal(m,n,l,c);  return 0;
                        }
                        if(mtz[i][j+1]!=42){
                            mt[i][j]=mtz[i][j];
                            imprimireal(m,n,l,c);  return 0;
                        }
                    }
                }else if(mtz[i][j]==42){
                    mt[i][j]=64;
                    return 1;
                }
            }
        }
    }
}

void imprimireal(int m, int n,int l,int c){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(i==l && c==j)
                printf("%d ",mt[i][j]);
            else
                printf("%c ",mt[i][j]);
        }
        puts("");
    }
}


#endif