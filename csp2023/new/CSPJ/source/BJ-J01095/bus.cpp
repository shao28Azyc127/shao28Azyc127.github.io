#include <bits/stdc++.h>
using namespace std;
struct r{
    int l=0,t=0;
}mapp[10005][10005];
int tim[10005]={0,0},n,m,k;
void solve(int i){
        for(int j=1;j<=n;j++){
            if(mapp[i][j].l==1){
                if(mapp[i][j].t<=tim[i]){
                    tim[j]=tim[i]+1;
                    if(j==n&&tim[j]%k!=0){
                            tim[j]=0;
                    }
                    solve(j);
                }else{
                    tim[j]=((mapp[i][j].t-tim[i])%k==0?(mapp[i][j].t-tim[i])/k:(mapp[i][j].t-tim[i])/k+k)+tim[i]+1;
                    if(j==n&&tim[j]%k!=0){
                            tim[j]=0;
                    }
                    solve(j);
                }
            }
        }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        mapp[a][b].l=1;
        mapp[a][b].t=c;
    }
    solve(1);
    if(tim[n]==0){
        cout<<-1;
    }else{
        cout<<tim[n];
    }
}
