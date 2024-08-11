#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int M=1e6+5;
const int INF=2e9+5;
template<typename T>
inline void read(T &x) {
    x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
template<typename T>
void write(T x) {
    if(x>=10)write(x/10);
    putchar(x%10+'0');
}
int n;
string s;
ll ans;
bool vis[8005][8005];
int main() {
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    s=" "+s;
    for(int i=1;i<=n;i++)vis[i][i]=1;
    for(int len=2;len<=n;len+=2) {
        for(int i=1;i+len-1<=n;i++) {
            int l=i,r=i+len-1;
            bool flag=0;
            for(int j=l+1;j<r;j+=2) {
                if(vis[l][j]&&vis[j+1][r]) {
                    flag=1;
                    break;
                }
            }
            if(s[l]==s[r]) {
                flag|=vis[l+1][r-1];
            }
            if(flag)ans++,vis[l][r]=1;
            else if(s[l]==s[r]&&len==2)ans++,vis[l][r]=1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
