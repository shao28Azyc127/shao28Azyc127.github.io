#include<bits/stdc++.h>
#define int long long
using namespace std;
bool c[801][801];
int n,ans;
string str;
signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>str;
    str=" "+str;
    for(int i=1;i<=n;i++){
        c[i][i-1]=1;
    }
    for(int j=1;j<=n;j++){
        for(int i=1;i+j<=n;i++){
            if(str[i]==str[i+j]&&c[i+1][i+j-1]){
                c[i][i+j]=1;
            }
            for(int k=i;k<=i+j;k++){
                if(c[i][k]&&c[k+1][i+j]){
                    c[i][i+j]=1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;i+j<=n;j++){
            ans+=c[i][i+j];
        }
    }
    cout<<ans;
}
