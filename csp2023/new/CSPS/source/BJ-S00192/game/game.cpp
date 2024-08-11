#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<vector>
#define fr(xx,yy,zz) for(int xx=yy;xx<=zz;xx++)
#define ll long long
#define pt printf
#define pii pair<int,int>
using namespace std;
const int N=8033,inf=0x3f3f3f3f;////////////////////////
void rd(){}template<typename T,typename...args>inline void rd(T&x,args&...y){
    bool f=0;char ch=getchar();
    for(;ch<'0'||'9'<ch;ch=getchar())if(ch=='-')f=1;
    for(x=0;'0'<=ch&&ch<='9';ch=getchar() )x=(x<<1)+(x<<3)+ch-'0';
    if(f)x=-x;
    rd(y...);
}
int n;char a[N];
//bitset<N> dp[N];
bool dp[N][N];
ll Xor[N];
inline int Tran(int x){
    return x+454;
}
int main(){
   freopen("game.in","r",stdin);
   freopen("game.out","w",stdout);
    rd(n);
    scanf("%s",a+1);
    fr(i,1,n){
        Xor[i]=Xor[i-1]^Tran(a[i]);
    }
    fr(i,1,n-1){
        if(a[i]==a[i+1]){
            dp[i][i+1]=1;
        }
    }
    for(int len=4;len<=n;len+=2){
        fr(i,1,n-len+1){
            int j=i+len-1;
            if(Xor[j]^Xor[i-1])continue;

            if(a[i]==a[j]){
                dp[i][j]|=dp[i+1][j-1];
            }
            for(int k=i+1;k<j;k+=2){
                dp[i][j]|=dp[i][k]&&dp[k+1][j];
                if(dp[i][j])break;
            }
        }
    }
    ll ans=0;
    fr(i,1,n){
        fr(j,i+1,n){
            if(dp[i][j])++ans;
        }
    }
    pt("%lld\n",ans);

    return 0;
}
