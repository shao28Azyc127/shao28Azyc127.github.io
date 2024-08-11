#include<bits/stdc++.h>
using namespace std;
const int N=100;
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

int n,p1,p2,cnt,ans;
int d[N];
int a[N][N],now[N];
void DFS(int x){
    if(x==5){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=5;j++){
                if(now[j]!=a[i][j]) ++cnt,d[j]=1;
                else d[j]=0;
            }
            if(!cnt)    return;
            if(cnt==1)  continue;
            else{
                if(cnt>2)  return;
                p1=0,p2=0;
                for(int j=1;j<=5;j++){
                    if(d[j]==0&&!p1)    p1=j;
                    else if(d[j]==0)    p2=j;
                }
                if(abs(p1-p2)!=1)   return;
                else{
                    if((a[i][p1]-now[p1]!=a[i][p2]-now[p2])&&a[i][p1]+10-now[p1]!=a[i][p2]) return;
                    continue;
                }
            }
        }
        ans++;
        return;
    }
    for(int i=0;i<=9;i++){
        now[x+1]=i;
        DFS(x+1);
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++)   for(int j=1;j<=5;j++)   a[i][j]=read();
    DFS(0);
    printf("%d\n",ans);
}
