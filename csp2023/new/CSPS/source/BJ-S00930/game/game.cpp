#include <bits/stdc++.h>
using namespace std;
int v[8005][8005]={};
long long ans;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    string s;int n;cin>>n>>s;
    s=' '+s;
    for(int i=1;i<n;i++) if(s[i]==s[i+1]) v[i][i+1]=1;
    for(int len=2;len<=n;len++)
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            if(!(len&1)&&len!=2){
                if(v[l+1][r-1] && s[l]==s[r]) v[l][r]=1;
                else{
                    for(int k=l+1;k<r-1;k+=2)
                    if(v[l][k]&&v[k+1][r]) v[l][r]=1;
                }
            }
        }
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j+=2) if(v[i][j])ans++;
    cout<<ans;
    return 0;
}