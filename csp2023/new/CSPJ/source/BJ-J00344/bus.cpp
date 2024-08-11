#include<bits/stdc++.h>
using namespace std;
int m,n,k,l1,l2,l3,qk[10010][110];
struct ls{
    int a,b,c;
} l[100010];
bool cmp(ls q,ls w){
    return q.c<w.c;
}
vector<int> v[10010],g[10010];
queue<int> q1,q2;
void p(int a,int b){
    q1.push(a);
    q2.push(b);
}
void bfs(){
    while(!q1.empty()){
        l1=q1.front(),l2=q2.front();
        q1.pop();
        q2.pop();
        if(qk[l1][l2%k]!=l2) continue;
        for(int i=0;i<v[l1].size();i++){
            l3=l2+1;
            if(g[l1][i]>l3) l3=(g[l1][i]-l3+k-1)/k*k+l3;
            if(qk[v[l1][i]][l3%k]<l3) continue;
            qk[v[l1][i]][l3%k]=l3;
            p(v[l1][i],l3);
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdin);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++) scanf("%d%d%d",&l[i].a,&l[i].b,&l[i].c);
    sort(l+1,l+n+1,cmp);
    for(int i=1;i<=m;i++){
        v[l[i].a].push_back(l[i].b);
        g[l[i].a].push_back(l[i].c);
    }
    for(int i=0;i<=100;i++) for(int j=0;j<10000;j++) qk[j][i]=2e9;
    qk[1][0]=0;
    p(1,0);
    bfs();
    if(qk[n][0]<2e9) cout<<qk[n][0]<<endl;
    else puts("-1");
    return 0;
}