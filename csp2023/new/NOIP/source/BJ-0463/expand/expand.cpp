#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int C,N,M,Q,OX[500009],OY[500009],X[500009],Y[500009],px,py,stkv,k1,k2,pmx;
/*inline bool sqcX(){
    px=1;py=1;stkv=0;
    if(X[1]<=Y[1]){return 0;}
    while(0<px && 0<py && !(px>=N && py>=M)){
        //printf("kr1 %d(%d) %d(%d)\n",px,X[px],py,Y[py]);
        while(Y[py+1]<X[px] && py<M){py++;if(X[px]<Y[py]){return 0;}/*printf("a1 (%d)px:%d (%d)py+1:%d\n",px,X[px],py,Y[py+1]);}
        if(Y[py+1]>X[px]){
            stkv=Y[py+1];
            while(X[px+1]<Y[py] && py>0){py--;/*printf("a2 (%d)px+1:%d (%d)py:%d\n",px,X[px+1],py,Y[py]);}
        }
        px++;
        while((X[px]<stkv && px<N)||py==0){if(X[px]<Y[py]){return 0;}px++;/*printf("a3 (%d)px:%d v%d m(%d)\n",px,X[px],stkv,N);if(px>=N){break;}}
    }
    if(X[px]<=Y[px] || py==0){return 0;}
    return 1;
}*/
inline bool nsqcX(int *X,int *Y){
    px=1,py=1,stkv=0,pmx=0;
    if(X[1]<=Y[1]){return 0;}
    while (!(px==N && py==M)){
        /*while(Y[py+1]<X[px] && py<M){py++;}
        kv=Y[py+1];
        if(py==M){kv=2147483647;}
        while(X[px]<kv){
            while(Y[py]>X[px+1]){py--;if(py==0){return 0;}}
            px++;
            while(Y[py+1]<X[px] && py<M){py++;}
            if(px==N && py<N){return 0;}
        }*/
        while(Y[py+1]<X[px] && py<M){py++;/*printf("y+1:%d\n",py);*/}
        if(px==N && py<M){return 0;}
        while(Y[py]>=X[px+1]){py--;if(py==0 ||(Y[py]>X[px] && Y[py]>X[px-1])){return 0;}/*printf("y-1:%d\n",py);*/}
        if(px<N){px=px+1;}
        //printf("x+1:%d\n",px);
    }
    return 1;
}
/*inline bool nsqcX(){
    px=1,py=1,stkv=0;
    while (!(px==N && py==M)){
        /*while(Y[py+1]<X[px] && py<M){py++;}
        kv=Y[py+1];
        if(py==M){kv=2147483647;}
        while(X[px]<kv){
            while(Y[py]>X[px+1]){py--;if(py==0){return 0;}}
            px++;
            while(Y[py+1]<X[px] && py<M){py++;}
            if(px==N && py<N){return 0;}
        }
        while(X[px+1]<Y[py] && px<N){px++;/*printf("y+1:%d\n",py);}
        if(py==M && px<N){return 0;}
        while(X[px]>Y[py+1]){px--;if(px==0 ||X[px]>X[px]){return 0;}/*printf("y-1:%d\n",py);}
        if(px<N){px=px+1;}
        //printf("x+1:%d\n",px);
    }
    return 1;
}*/
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d %d %d %d",&C,&N,&M,&Q);
    for(int q=1;q<=N;q++){scanf("%d",&OX[q]);}
    for(int q=1;q<=M;q++){scanf("%d",&OY[q]);}
    OX[N+1]=2147483647;
    OY[N+1]=2147483647;
    memcpy(X,OX,sizeof(X));
    memcpy(Y,OY,sizeof(Y));
    printf("%d",nsqcX(X,Y)|nsqcX(Y,X));
    for(int q=1;q<=Q;q++){
        scanf("%d %d",&k1,&k2);
        memcpy(X,OX,sizeof(X));
        memcpy(Y,OY,sizeof(Y));
        //printf("! sc %d %d\n",k1,k2);
        for(int w=1;w<=k1;w++){
            scanf("%d %d",&px,&py);
            //printf(" AdX %d %d\n",px,py);
            X[px]=py;
        }
        for(int w=1;w<=k2;w++){
            scanf("%d %d",&px,&py);
            //printf(" AdY %d %d\n",px,py);
            Y[px]=py;
        }
        //printf("\nX");
        //for(int q=1;q<=N;q++){printf(" %d",X[q]);}
        //printf("\nY");
        //for(int q=1;q<=N;q++){printf(" %d",Y[q]);}
        //printf("\n");
        printf("%d",nsqcX(X,Y)|nsqcX(Y,X));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
