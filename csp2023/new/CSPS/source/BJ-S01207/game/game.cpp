#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
template<typename T>void read(T &x){
    x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c-'0');
    x=x*f;
}

const int N=1e3+5;

int n;
bool f[N][N];
char s[N];

signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    read(n);
    scanf("%s",s+1);
    ll ans=0;
    for(int i=1;i<n;i++)
        if(s[i]==s[i+1]) f[i][i+1]=1,ans++;
    for(int len=3;len<=n;len+=2){
        for(int i=1;i+len<=n;i++){
            for(int j=i+1;j<i+len;j+=2)
                if(f[i][j]==1&&f[j+1][i+len]==1) f[i][i+len]=1;
            if(f[i+1][i+len-1]==1&&s[i]==s[i+len]) f[i][i+len]=1;
            if(f[i][i+len]) ans++;
        }
    }
    printf("%lld\n",ans);
    return 0;
}

// g++ 1.cpp -o 1 -O2 -std=c++14
