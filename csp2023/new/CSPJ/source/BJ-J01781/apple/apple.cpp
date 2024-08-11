#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define ll long long
using namespace std;
inline int read(){int x=1,f=0;char ch=getchar();
    while(ch<'0' && ch>'9'){if(ch=='-')x=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){f=f*10+ch-'0';ch=getchar();}
    return x*f;
}
//CSP-J2023l!2
/*
8
out:5 5

n=1 1 1
  2 2 2
  3 3 3
  4 3 1
  5 4 4
  6 4 2
  7 4 1
  8 5 5
  9 5 3
  10 5 1
  11 5 2
  12 6 6
  13 6 1
  14 6 4
*/
const int N=1e9+5;bool vis[N];
ll n;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%lld",&n);
	/*memset(vis,0,sizeof(vis));
    int cnt=n;int ans1=0,ans2=0;
    while(cnt){
        int num=0;++ans1;
        rep(i,n){
             if(!vis[i])
             {
                if(!num){if(i==n)ans2=ans1;vis[i]=1;num=2;--cnt;}
                else --num;
             }
        }
    }*/
    int cnt=0,ans=0,flag=0;
    while(n){
    	++cnt;
    	if(!flag&&((n-1)%3==0)){ans=cnt;flag=1;}
    	--n;n-=n/3;//printf("cnt:%d %d\n",cnt,n);
	}
	printf("%d %d\n",cnt,ans);
    return 0;
}
