#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
int n;
ll ans;
string s;
bool b[1001][1001];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    s=" "+s;
    for(int i=1;i<=n-1;i++)
        if(s[i]==s[i+1])
        {
            b[i][i+1]=1;
        }
    for(int k=4;k<=n;k+=2){
        for(int i=1;(i+k-1)<=n;i++){
            int j=i+k-1;
            if(s[i]==s[j]&&b[i+1][j-1])
            {
                b[i][j]=1;
                continue;
            }
            for(int f=i+2;f<j;f+=2){
                if(b[i][f-1]&&b[f][j]){
                    b[i][j]=1;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(b[i][j])
            {
                //cout<<i<<j<<endl;
                ans++;
            }
    cout<<ans<<endl;
    return 0;
}