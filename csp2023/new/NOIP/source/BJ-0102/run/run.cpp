#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define spc putchar(' ')
#define Enter putchar('\n')
void read(int &number){
    bool f=0;
    number=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        number=number*10+(ch^48);
        ch=getchar();
    }
    if(f)number=-number;
}
void lread(LL &number){
    bool f=0;
    number=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        number=number*10+(ch^48);
        ch=getchar();
    }
    if(f)number=-number;
}
void print(LL number){
    if(number<0){
        putchar('-');
        number=-number;
    }
    if(number>=10){
        print(number/10);
    }
    putchar((number%10)^48);
}
const int N=3003,M=1e5+3;
LL s[N][N],dp[N][N];
LL x[M],y[M],z[M],f[M][2],su[M];
int id[M];
bool cmp(int &a,int &b){
    return y[a]<y[b];
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int n,m,t,k,d,a,b,c,l,st;
    read(n),read(t);
    if(n>=17&&n<=18){
        for(int svp=1;svp<=t;svp++){
            memset(f,0,sizeof(f));
            st=0;
            cin>>n>>m>>k>>d;
            for(int i=1;i<=m;i++){
                cin>>y[i]>>b>>z[i];
                x[i]=y[i]-b+1;
                if(1ll*b*d<=1ll*z[i]&&b<=k){
                    id[++st]=i;
                    z[i]-=b*d;
                }
            }
            sort(id+1,id+st+1,cmp);
            l=1;
            y[0]=-1e9;
            for(int i=1;i<=st;i++){
                su[i]=su[i-1]+z[id[i]];
            }
            for(int i=1;i<=st;i++){
                f[i][0]=max(f[i-1][0],f[i-1][1]);
                if(y[id[l]]<x[id[i]]-1)l=i;
                while(y[id[i]]-x[id[l]]+1>1ll*k)++l;
                f[i][1]=f[l-1][0]+su[i]-su[l-1];
                f[i][1]=max(f[i][1],f[l-1][1]+su[i]-su[l-1]);
            }
            print(max(f[st][0],f[st][1])),Enter;
        }
        return 0;
    }
    for(int svp=1;svp<=t;svp++){
        read(n),read(m),read(k),read(d);
        memset(dp,0,sizeof(dp));
        memset(s,0,sizeof(s));
        for(int i=1;i<=m;i++){
            read(a),read(b),read(c);
            s[a][b]+=c;
        }
        for(int i=1;i<=n;i++){
            for(int j=2;j<=min(i,k);j++){
                s[i][j]+=s[i][j-1];
            }
            for(int j=1;j<=min(i,k);j++){
                dp[i][j]=dp[i-1][j-1]-d+s[i][j];
                dp[i+1][0]=max(dp[i+1][0],dp[i][j]);
            }
            dp[i+1][0]=max(dp[i+1][0],dp[i][0]);
        }
        print(dp[n+1][0]),Enter;
    }
    return 0;
}
