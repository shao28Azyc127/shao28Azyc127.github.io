#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int C,T,N,M,F[100009],f,t,A,TL,L[100009],i2;
char op;
bool Fi[100009],Vb[100009],Vu[100009],V[100009];
struct _{int t,p;bool v;}E[100009];
inline void add(int f,int t,bool v){
    E[++TL]=_{t,L[f],v};
    L[f]=TL;
}
inline void dfs(int i,bool u){
    if(V[i]){return;}
    V[i]=1;
    if(u){A=A+1;}
    for(int q=L[i];q;q=E[q].p){
        dfs(E[q].t,u);
    }
}
inline void pfa(int i,int af){
    if(V[i]){return;}
    V[i]=1;
    F[i]=af;Fi[i]=Fi[i]^Fi[F[i]];
    for(int q=L[i];q;q=E[q].p){
        pfa(E[q].t,af);
    }
}
inline void fa1(int i){
    while(F[i]!=i){
        Fi[i]=Fi[i]^Fi[F[i]];
        i=F[i];
    }
}
inline int fa2(int i){F[i]=fa2(F[i]);}
queue<int> pv;
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d %d",&C,&T);
    for(int teq=0;teq<T;teq++){
        scanf("%d %d\n",&N,&M);
        A=0;TL=0;
        memset(L,0,sizeof(L));
        memset(F,0,sizeof(F));
        memset(Fi,0,sizeof(Fi));
        memset(Vb,0,sizeof(Vb));
        memset(Vu,0,sizeof(Vu));
        for(int q=1;q<=M;q++){
            scanf("%c ",&op);
            if(op=='T'){
                scanf("%d\n",&f);
                Vb[f]=1;
                F[f]=f;
            }
            if(op=='F'){
                scanf("%d\n",&f);
                F[f]=f;
            }
            if(op=='U'){
                scanf("%d\n",&f);
                Vu[f]=1;
                pv.push(f);
                F[f]=f;
            }
            if(op=='+'){
                scanf("%d %d\n",&t,&f);
                add(f,t,0);
                if(F[f]==0){F[f]=f;}
                memset(V,0,sizeof(V));
                pfa(f,f);
                memset(V,0,sizeof(V));
                pfa(t,t);
                //printf("at1 %d(%d,%d) %d(%d,%d)\n",f,F[f],Fi[f],t,F[t],Fi[t]);
                if(F[t]==F[f] && Fi[t]!=Fi[f]){
                    //printf("Marked1 %d(%d,%d) %d(%d,%d)\n",f,F[f],Fi[f],t,F[t],Fi[t]);
                    Vu[F[f]]=1;continue;
                    pv.push(F[f]);
                }
                F[t]=F[f];
                Fi[t]=Fi[f];

            }
            if(op=='-'){
                scanf("%d %d\n",&t,&f);
                add(f,t,1);
                if(F[f]==0){F[f]=f;}
                memset(V,0,sizeof(V));
                pfa(f,f);
                memset(V,0,sizeof(V));
                pfa(t,t);
                if(F[t]==F[f] && Fi[t]==Fi[f]){
                    //printf("Marked2 %d(%d,%d) %d(%d,%d)\n",f,F[f],Fi[f],t,F[t],Fi[t]);
                    Vu[F[f]]=1;continue;
                    pv.push(F[f]);
                }
                F[t]=F[f];
                Fi[t]=!Fi[f];
                //printf("at2 %d(%d,%d) %d(%d,%d)\n",f,F[f],Fi[f],t,F[t],Fi[t]);
            }
            /*printf("::");
            for(int q=1;q<=N;q++){
                printf(" %d(%d,%d)",q,F[q],Fi[q]);
            }
            printf("\n");*/
        }
        //for(int q=1;q<=N;q++){
            //if(Vu[F[q]]){A=A+1;}
        //}
        while(pv.size()){
            f=pv.front();pv.pop();
            dfs(f,1);
        }
        printf("%d\n",A);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
