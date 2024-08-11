#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int pos[N][26];
int sum[N];
char s[N];
signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    cin>>s+1;
    sum[n]=0;
    pos[n][s[n]-'a']=n;
    int ans=0;
    for(int i=n-1;i>=1;i--){
        if(!pos[i+1][s[i]-'a']){
            pos[i][s[i]-'a']=i;
            continue;
        }
        int poss=pos[i+1][s[i]-'a'];
        sum[i]=sum[poss+1]+1;
        ans+=sum[i];
        if(poss+1<=n){
            for(int j=0;j<26;j++){
                pos[i][j]=pos[poss+1][j];
            }
        }
        pos[i][s[i]-'a']=i;
    }
    /*for(int i=1;i<=n;i++){
        cout<<sum[i]<<"\n";
    }*/
    cout<<ans<<"\n";
    return 0;
}