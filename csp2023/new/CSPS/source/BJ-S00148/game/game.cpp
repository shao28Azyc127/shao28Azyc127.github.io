//play florr.io and tkk!
//written by a fan of Robert_Lewandovski
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,ans,a[2000001][26];
long long dp[2000001];
long long sum;
string s;
signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    s='!'+s;
    for(int i=2;i<=n;i++){
        int pos;
        if(s[i]==s[i-1]) pos=i-1;
        else pos=a[i-1][s[i]-'a'];
        pos--;
        if(pos==-1){
            dp[i]=0;
            continue;
        }
        for(int j=0;j<26;j++){
            if(a[pos][j]==1) continue;
            a[i][j]=a[pos][j];
        }
        a[i][s[pos]-'a']=pos;
        dp[i]=dp[pos]+1;
    }
    for(int i=1;i<=n;i++) sum+=dp[i];
    cout<<sum<<endl;
    return 0;
}
