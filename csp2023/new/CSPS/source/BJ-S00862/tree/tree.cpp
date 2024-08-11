#include<bits/stdc++.h>
using namespace std;
int n;
int a[100009];
int b[100009];
int c[100009];
int h[100009];
struct st{
    int v,ne;
}sd[100009];
int inn;
bool v[100009];
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        sd[++inn].v=v;
        sd[inn].ne=h[u];
        h[u]=inn;
        swap(u,v);
        sd[++inn].v=v;
        sd[inn].ne=h[u];
        h[u]=inn;
    }
    int da;
    da=1;
    queue<int> q;
    q.push(1);
    int ans;
    ans=0;
    while(q.size()){
            int tt;
    tt=q.front();
    q.pop();
        if(v[tt]){
            continue;
        }
        v[tt]=1;
        ans=max(ans,int(ceil(a[tt]*1.0/b[tt]))+da-1);
        int bt;
        bt=0;
        for(int i=h[tt];i;i=sd[i].ne){
            if(!v[sd[i].v]&&a[sd[i].v]>a[bt]){
                bt=sd[i].v;
            }
        }
        q.push(bt);
        da++;
    }
    cout<<ans;
    return 0;
}
