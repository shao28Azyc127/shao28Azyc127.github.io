#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
const int N=8e3+5;
int n,l[N],ans,j;
bool f[N][N];
string s;
signed main() {
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1])
            f[i-1][i]=true,ans++;
    }
    for(int lt=4;lt<=n;lt+=2){
        for(int i=0;i<n;i++){
            j=i-lt+1;
            if(j<0)
                continue;
            //cout<<j<<" "<<i<<endl;
            if(s[i]==s[j])
                f[j][i]|=f[j+1][i-1];
            if(f[j][i]){
                ans++;
                    //cout<<"!\n";
                continue;
            }
            for(int k=j+1;k<i;k++){
                if((i-k)%2!=0||(k-j+1)%2!=0)
                    continue;
                f[j][i]|=(f[j][k]&f[k+1][i]);
                if(f[j][i]){
                    ans++;
                    //cout<<"!\n";
                    break;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
