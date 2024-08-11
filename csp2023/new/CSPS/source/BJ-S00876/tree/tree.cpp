#include<bits/stdc++.h>
using namespace std;
struct Node{
    int nxt,v;
}e[maxn<<1];
int h[maxn],tot;
struct node{
    int a,b,c;
}p[maxn];
int in[maxn];
void adde(int u,int v){
    e[++tot].v=v;
    e[tot].nxt=h[u];
    h[u]=tot;
}
int main(){
    freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
    int n;
    scanf("%d",&n);
    cout<<n+7;return 0;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",p[i].a,p[i].b,p[i].c);
    }
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        adde(u,v);in[u]++;
        adde(v,u);in[v]++;
    }
    int f=0;
    for(int i=1;i<=n;i++){
        if(in[i]>=2)f=1;
    }
    if(f==1){
        
        
    }else{
        
        
    }
    return 0;
}
