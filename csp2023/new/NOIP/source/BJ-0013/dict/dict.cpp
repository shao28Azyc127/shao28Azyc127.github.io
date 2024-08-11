#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=3005;
int n,m,xl[maxn],ans[maxn];
char str[maxn][maxn];
bool cmp(const int& t1,const int& t2){
    for(int i=1;i<=m;++i){
        if(str[t1][i]<str[t2][i])return true;
        if(str[t1][i]>str[t2][i])return false;
    }
    return false;
}
signed main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>str[i]+1;
        sort(str[i]+1,str[i]+m+1);
        reverse(str[i]+1,str[i]+m+1);
        xl[i]=i;
    }
    sort(xl+1,xl+n+1,cmp);
    if(n==1){
        cout<<'1';
        return 0;
    }
    reverse(str[xl[1]]+1,str[xl[1]]+m+1);
    if(cmp(xl[1],xl[2]))ans[xl[1]]=1;
    reverse(str[xl[1]]+1,str[xl[1]]+m+1);
    for(int i=2;i<=n;++i){
        reverse(str[xl[i]]+1,str[xl[i]]+m+1);
        if(cmp(xl[i],xl[1]))ans[xl[i]]=1;
    }
    for(int i=1;i<=n;++i)cout<<ans[i];
    return 0;
}