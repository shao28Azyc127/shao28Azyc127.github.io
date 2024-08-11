#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='0') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
const int N=10,M=1e5;
int a[N][5];
bool vis[N][M];
signed main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n=read();
    for(int i=1;i<=n;i++){
        for(int j=0;j<5;j++){
            a[i][j]=read();
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<10;k++){
                int x=a[i][j];
                a[i][j]=k;
                int d=0;
                for(int l=0;l<5;l++){
                    d=d*10+a[i][l];
                }
                vis[i][d]=1;
                a[i][j]=x;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<10;k++){
                int x=a[i][j],y=a[i][j+1];
                a[i][j]+=k;
                a[i][j+1]+=k;
                a[i][j]%=10;
                a[i][j+1]%=10;
                int d=0;
                for(int l=0;l<5;l++){
                    d=d*10+a[i][l];
                }
                vis[i][d]=1;
                a[i][j]=x,a[i][j+1]=y;
            }
        }
    }
    for(int i=1;i<=n;i++){
        int d=0;
        for(int j=0;j<5;j++){
            d=d*10+a[i][j];
        }
        vis[i][d]=0;
    }
    int cnt=0;
    for(int i=0;i<M;i++){
        bool f=1;
        for(int j=1;j<=n;j++){
            f&=vis[j][i];
        }
        cnt+=f;
    }
    cout<<cnt;
    return 0;
}
