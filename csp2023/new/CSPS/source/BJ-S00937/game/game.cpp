#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int n;
char a[N];
int fail[N][26];
int mi;
ll f[N],s;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>a+1;
    for(int i=2;i<=n;++i){
        if(a[i]==a[i-1]){
            mi=i-1;
            f[i]=f[i-2]+1;
            memcpy(fail[i],fail[mi-1],sizeof(fail[i]));
            if(mi!=1)fail[i][a[mi-1]-'a']=mi-1;
            continue;
        }
        if(mi==0)continue;
        mi=fail[i-1][a[i]-'a'];
        if(mi==0)continue;
        memcpy(fail[i],fail[mi-1],sizeof(fail[mi]));
        if(mi!=1)fail[i][a[mi-1]-'a']=mi-1;
        f[i]=f[mi-1]+1;
    }
    for(int i=1;i<=n;++i){
        s+=f[i];
    }
    cout<<s;
    return 0;
}
