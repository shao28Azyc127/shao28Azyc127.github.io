#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxm 105
int c,t,n,m,k,d,x[maxm],y[maxm],z[maxm],now[maxm],lg[maxm],re;
int judge(void){
    int st[10][maxm],ans=0;
    memset(st,0x3f,sizeof(st));
    for(int i=1;i<=n;i++){
        st[1][i]=now[i];
    }
    for(int i=2;i<=lg[n];i++){
        for(int j=1;j<=n-(1<<(i-2))+1;j++){
            st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-2))]);
        }
    }
    for(int i=1;i<=m;i++){
        if(min(st[lg[y[i]]][x[i]-y[i]+1],st[lg[y[i]]][x[i]-y[i]+1+(1<<lg[y[i]])])){
            ans+=z[i];
        }
    }
    for(int i=1;i<=n;i++){
        if(now[i]){
            ans-=d;
        }
    }
    return ans;
}
void dfs(int x,int con){
    if(x>n){
        re=max(re,judge());
        return;
    }
    now[x]=0;
    dfs(x+1,0);
    if(con!=k){
        now[x]=1;
        dfs(x+1,con+1);
    }
    return;
}
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>m>>k>>d;
        lg[1]=1;
        lg[2]=2;
        for(int i=3;i<=n;i++){
            lg[i]=lg[i/2]+1;
        }
        for(int j=1;j<=m;j++){
            cin>>x[j]>>y[j]>>z[j];
            if(y[j]>k){
                j--;
                m--;
            }
        }
        dfs(1,0);
        cout<<re<<endl;
    }
    return 0;
}
