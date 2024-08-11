#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')  f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
const int N=8e3+100;
long long S;
int s1[N];//stz
char sta[N][N];
char s[N][N];//stn
char s0[N][N][N],now[N];
int sty[N];
int n,u,i,j;
int addr;
long long maxn;
int cnt=0;
long long is(){
    if(now[j]=='b') return 1;
    else if(now[j]=='s') return 2;
    else if(now[j]=='i') return 4;
}
signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    n=read();
    for(i=1;i<=n;i++){
        int op=read();
        if(op==1){
            cnt++;
            scanf("%s",(s[cnt]+1));
            s1[cnt]=read();
            for(j=1;j<=s1[cnt];j++){
                scanf("%s",(now+1));
                S+=is();
                maxn=max(maxn,is());
                scanf("%s",(s0[cnt][j]+1));
            }
            printf("%lld %lld\n",((S+maxn-1)/maxn)*maxn,maxn);
        }
    }
}
