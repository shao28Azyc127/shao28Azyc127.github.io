#include<bits/stdc++.h>
using namespace std;
const int maxn=3005;
char c[maxn];
string s[maxn],maxs[maxn],mins[maxn],a[maxn];
bool flag[maxn];
int n,m,g[maxn],p[maxn];
bool cmp(int a,int b){
    return maxs[a]<maxs[b];
}
bool cmp1(char c1,char c2){
    return c1>c2;
}
int cha(int k){
    if (k==1||k==n)return k;
    if (a[k]<a[k-1]){
        swap(g[p[k-1]],g[p[k]]);
        swap(p[k-1],p[k]);
        swap(a[k-1],a[k]);
        return cha(k-1);
    }else{
        if (a[k]>=a[k+1]){
            swap(g[p[k+1]],g[p[k]]);
        swap(p[k+1],p[k]);
        swap(a[k+1],a[k]);
        return cha(k+1);
        }

    }
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)cin>>s[i];
    for (int i=1;i<=n;i++){
        sort(s[i].begin(),s[i].end());
        mins[i]=s[i];
        sort(s[i].begin(),s[i].end(),cmp1);
        maxs[i]=s[i];
    }
    for (int i=1;i<=n;i++){
        p[i]=i;
    }
    sort(p+1,p+n+1,cmp);
    for (int i=1;i<=n;i++){
        g[p[i]]=i;
        a[i]=maxs[p[i]];
    }
    //for (int i=1;i<=n;i++)cout<<a[i]<<endl;
    for (int i=1;i<=n;i++){
        if (i!=1){
            //cout<<g[i-1]<<endl;
            a[g[i-1]]=maxs[i];
            cha(g[i-1]);
        }
        a[g[i]]=mins[i];
        cha(g[i]);
        if (g[i]==1)flag[i]=1;
    }
    for (int i=1;i<=n;i++)cout<<flag[i];
}
