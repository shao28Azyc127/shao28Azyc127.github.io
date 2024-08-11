#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=8e3+5;
string s;
int n,a[N],f[N][N];
ll ans;
int fz[27];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s;

    for(int i=0;i<n-1;++i){
        if(s[i]==s[i+1]){
            f[i][i+1]=1;
        }
    }
    for(int i=3;i<=n;i+=2){
        for(int l=0;l+i<n;++l){
            if(f[l+1][l+i-1]&&s[l]==s[l+i]){
                f[l][l+i]=1;
                continue;
            }
            for(int k=l;k<=l+i;++k){
                if(k-l+1%2==1) continue;
                if(f[l][k]&&f[k+1][l+i]){
                    f[l][l+i]=1;
                    break;
                }
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            ans+=f[i][j];
        }
    }
    cout<<ans;
    return 0;
}
