#include <iostream>
#include <cstdio>
using namespace std;
bool isrun[19],pm[19];
int N,M,C,T,R[500009],E[5000090],W[500009],cn,ce,K,D,A=0;
inline void premu(int i){
    //printf("%d\n",i);
    if(i==N+1){
        cn=0;ce=0;
        for(int q=1;q<=N;q++){
            if(pm[q]){
                cn=cn+1;
                ce=ce-D;
                if(cn>K){return;}
                for(int w=1;w<=M;w++){if(q==R[w] && cn>=E[w]){ce=ce+W[w];}}
            }
            else{cn=0;}
        }
        A=max(ce,A);
        return;
    }
    pm[i]=0;
    premu(i+1);
    pm[i]=1;
    premu(i+1);
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%d %d",&C,&T);
    for(int tsk=0;tsk<T;tsk++){
        scanf("%d %d %d %d",&N,&M,&K,&D);
        for(int q=1;q<=N;q++){scanf("%d %d %d",&R[q],&E[q],&W[q]);}
        premu(1);
        printf("%d\n",A);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
