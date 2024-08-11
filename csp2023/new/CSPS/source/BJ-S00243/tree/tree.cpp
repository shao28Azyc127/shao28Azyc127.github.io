#include<bits/stdc++.h>
using namespace std;
struct dt{
    int nd,id;
}t[100010];
bool cmp(dt q,dt w){
    return q.nd>w.nd;
}
int l1,l2,l3,n,f[100010],mst,bgg;
vector<int> v[100010];
bool gn[100010];
void dfs(int nt){
    for(int i=0;i<v[nt].size();i++){
        if(f[v[nt][i]]==0) continue;
        f[v[nt][i]]=nt;
        dfs(v[nt][i]);
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&l1,&l2,&l3);
        if(l2!=0) t[i].nd=(l1+l2-1)/l2;
        else t[i].nd=l1;
        t[i].id=i;
    }
    for(int i=1;i<n;i++){
        scanf("%d%d",&l1,&l2);
        v[l1].push_back(l2);
        v[l2].push_back(l1);
    }
    f[1]=1,bgg=t[1].nd,gn[1]=1;
    dfs(1);
    sort(t+1,t+n+1,cmp);
    for(int i=1;i<=n;i++){
        l1=t[i].id;
        if(gn[i]) continue;
        while(gn[l1]==0) gn[l1]=1,l1=f[l1],mst++;
        bgg=max(bgg,t[i].nd+mst);
    }
    cout<<bgg<<endl;
    return 0;
}
