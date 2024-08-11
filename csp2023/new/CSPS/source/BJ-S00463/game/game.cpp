#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
vector<char>v;
struct g{
    char c;
    int dep;
    int sum;
};
stack<g>stk;
char c[2000010];
int num[2000010],k[2000010];
int f[8010][8010];
signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1;i<=2000000;i++){
        k[i]=k[i-1]+i/2;
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(c[i]==c[i+1])f[i][i+1]=1;
        ans+=f[i][i+1];
    }
    for(int i=2;i<=n;i++){
        for(int l=1;l+i*2-1<=n;l++){
            if(c[l]==c[l+i*2-1]&&f[l+1][l+i*2-2])f[l][l+i*2-1]=1;
            else{
                for(int k=l+1;k<l+i*2-2;k+=2){
                    if(f[l][k]&&f[k+1][l+i*2-1]){
                        f[l][l+i*2-1]=1;
                        break;
                    }
                }
            }
            ans+=f[l][l+i*2-1];
        }
    }
    cout<<ans;
    return 0;
}
