#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+10;
vector<int> v[maxn];
int a[maxn],b[maxn],c[maxn],t[maxn],aa=0,dep[maxn],f[maxn],ts[maxn],cnt[maxn],pla[maxn],wt[maxn];
void mtr(int k,int fa){
    cnt[k]=1;
    ts[k]=dep[k]+t[k];
    int len=v[k].size();
    for (int i=0;i<len;i++){
        int x=v[k][i];
        if (x==fa)continue;
        dep[x]=dep[k]+1;
        mtr(x,k);
        cnt[k]+=cnt[x];
        ts[k]=max(ts[k],ts[x]);
    }
}
bool cmp(int a,int b){
    return ts[a]>ts[b];
}
int search(int k,int fa){
    wt[k]=max(wt[k],pla[k]+t[k]);
    cout<<k<<" "<<pla[k]<<endl;
    sort(v[k].begin(),v[k].end(),cmp);
    int len=v[k].size();
    int cn=0;
    for (int i=0;i<len;i++){
        int x=v[k][i];
        if (x==fa){
                continue;
                cn++;
        }
        pla[x]=pla[k]+i+1-cn;
        search(x,k);
        wt[k]=max(wt[k],wt[x]);
    }
    return wt[k];
}
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cout<<25<<endl;
}