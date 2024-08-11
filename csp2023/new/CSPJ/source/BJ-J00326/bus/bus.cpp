#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=2e4+10;
int n,m,k,pre[N],x,y,l,len,q[N],h,t,d[N];
struct node{
    int to,next;
}a[M];
void add(int x,int y){
    a[++len]={y,pre[x]};
    pre[x]=len;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i <= m;i++){
        scanf("%d%d%d",&x,&y,&l);
        if(l<=k) add(x,y);
    }
    h=1,t=1,q[1]=1,d[1]=k;
    while(h<=t){
        for(int i = pre[q[h]];i;i=a[i].next){
            int to=a[i].to;
            q[++t]=to;
            d[to]=d[q[h]]+1;
            if(to==n&&d[to]%k==0){
                cout<<d[to];
                return 0;
            }
        }
        h++;
    }
    cout<<-1;
}
