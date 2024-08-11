#include<bits/stdc++.h>
using namespace std;
int n;
int hd[100005],to[100005],nxt[100005],len[100005],us[100005];
int tot;
bool usd[100005];
void add(int u,int v){
    tot++;
    nxt[tot]=hd[u];
    hd[u]=tot;
    to[tot]=v;
}
struct nd{
    long long mn;
    int b,c;
}a[100005];
bool ck(){
    for(int i=1;i<=n;i++){
        if(len[i]<a[i].mn)return 0;
    }
    return 1;
}
void out(){
    for(int i=1;i<=n;i++){
        cout<<setw(5)<<len[i]<<" ";
    }
    printf("\n");
}
int sl;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].mn>>a[i].b>>a[i].c;
        int u,v;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        add(u,v);
    }
    int tim=1,mx,id;
    us[++sl]=1;
    while(!ck()){
        //out();
        for(int i=1;i<=sl;i++){
            len[us[i]]+=max(1,a[us[i]].b+tim*a[us[i]].c);
        }
        mx=id=-1;
        tim++;
        if(sl<n){
            for(int i=1;i<=sl;i++){
                for(int j=hd[us[i]];j;j=nxt[j]){
                    if(usd[to[j]])continue;
                    if(a[to[j]].mn>mx){
                        mx=a[to[j]].mn;
                        id=to[j];
                    }
                }
            }
            us[++sl]=id;
            usd[id]=1;
        }
    }
    cout<<--tim;
    return 0;
}
