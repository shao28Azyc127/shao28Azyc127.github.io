#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn0=8e3+5;
const int maxn=2e6+5;
const int maxc=35;
const int c=26;
int n,a[maxn];
ll ans;
bitset <maxn0> f0[maxn0],f1[maxn0];
string s;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    cin>>s;
    for (int i=1;i<=n;++i) a[i]=s[i-1]-'a'+1;
    // if (checkB()){
    //     solveB();
    //     return 0;
    // }
    for (int i=1;i<n;++i) if (a[i]==a[i+1]) ans+=(f0[i][i+1]=f1[i+1][i]=1);
    for (int l=3;l<=n;++l){
        for (int i=1;i+l-1<=n;++i){
            int j=i+l-1;
            if (a[i]==a[j] && f0[i+1][j-1]){
                ans+=(f0[i][j]=f1[j][i]=1);
                // printf("%d %d\n",i,j);
                continue;
            }
            f0[i][j]=(f0[i]&(f1[j]>>1)).any();
            if (f0[i][j]){
                // printf("%d %d\n",i,j);
                ans+=(f1[j][i]=1);
            }
            /*
            for (int k=i;k<j;++k){
                if (f0[i][k]&f0[k+1][j]){
                    // printf("%d %d\n",i,j);
                    ans+=(f[i][j]=1);
                    break;
                }
            }
            */
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
8
accabccb
*/
