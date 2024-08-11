#include <bits/stdc++.h>
using namespace std;
int f[4000][4000],n,ans;
string s;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    cin >> s;
    for(int i=0;i<n;++i){
        f[i][i]=0;
    }
    for(int i=0;i<n-1;++i){
        if(s[i]==s[i+1]){
            f[i][i+1]=1;
            ans++;
        }
    }
    for(int i=2;i<=n;++i){
        for(int j=0;j<n;++j){
            if(j+i>=n) break;
            if(s[j]==s[j+i] && f[j+1][j+i-1]){
                f[j][j+i]=1;
                ans++;
                continue;
            }
            for(int k=j+1;k<j+i;++k){
                if(f[j][k] && f[k+1][i+j]){
                    ans++;
                    f[j][j+i]=1;
                    break;
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}