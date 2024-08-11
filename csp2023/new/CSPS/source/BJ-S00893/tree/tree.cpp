#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <stack>
using namespace std;
int N,Ra[100009],Rb[100009],Rc[100009],D,L[100009],T,f,t,A;
struct _{int t,p;}E[200009];
bool V[100009];
inline void add(int f,int t){E[++T]=_{t,L[f]};L[f]=T;}
inline int lv(int i){
    int t=D,h=0;
    while(h<Ra[i]){
        h=h+max(1,t*Rc[i]+Rb[i]);
        t=t+1;
    }
    return t-D;
}
inline bool ky(int f,int t){
    return lv(f)<lv(t);
}
inline void bfs(){
    int K[100009],tt=1;
    K[1]=1;
    while(tt){
        sort(K+1,K+tt+1,ky);
        t=K[tt];
        tt--;
        if(V[t]){continue;}
        A=lv(t);
        V[t]=1;
        for(int q=L[t];q;q=E[q].p){K[++tt]=E[q].t;}
        D=D+1;
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&N);
    for(int q=1;q<=N;q++){scanf("%d %d %d",&Ra[q],&Rb[q],&Rc[q]);}
    for(int q=1;q<N;q++){
        scanf("%d %d",&f,&t);
        add(f,t);
        add(t,f);
    }
    bfs();
    printf("%d",A+D-1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
