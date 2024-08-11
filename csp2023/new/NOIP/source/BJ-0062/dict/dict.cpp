#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m;
char a[N];
int t[26];
int ed[26];
int ned[N],nbe[N];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        memset(t,0,sizeof(t));
        nbe[i]=-1;
        for(int j=1;j<=m;++j){
            cin>>a[j];
            t[a[j]-'a']++;
        }
        for(int j=0;j<26;++j){
            if(t[j]){
                if(nbe[i]==-1)nbe[i]=j;
                ned[i]=j;
            }
        }
        ed[ned[i]]++;
    }
    for(int i=1;i<26;++i)ed[i]+=ed[i-1];
    for(int i=1;i<=n;++i){
        if(ed[nbe[i]]-(ned[i]==nbe[i])==0)cout<<1;
        else cout<<0;
    }
    return 0;
}
