#include<bits/stdc++.h>
using namespace std;
const int INF=100000005;
int n,m,k;
struct node{
    int u,v,a;
}p[20005];
struct node2{
    int i,step;
}q[1000005];
int h[10005];
int f=1,r=1;
void bfs(){
    q[r].i=1;
    q[r].step=0;
    r++;
    while(f!=r){
        int x=q[f].i,istep=q[f].step;
        f++;
        if(f>1000000) f=1;
        for(int i=h[x];p[i].u==x;i++){
            if(istep>=p[i].a){
                int nx=p[i].v;
                if(nx==n&&(istep+1)%k==0){
                    cout<<istep+1;
                    return;
                }
                else{
                    if(istep<=INF){
                        q[r].i=nx;
                        q[r].step=istep+1;
                        r++;
                        if(r>1000000) r=1;
                    }
                }
            }
            else{
                int kstep=istep;
                while(kstep<p[i].a) kstep+=k;
                int nx=p[i].v;
                if(nx==n&&(kstep+1)%k==0){
                    cout<<kstep+1;
                    return;
                }
                else{
                    if(kstep<=INF){
                        q[r].i=nx;
                        q[r].step=kstep+1;
                        r++;
                        if(r>1000000) r=1;
                    }
                }
            }
        }
    }
    cout<<-1;
    return;
}
bool mcmp(node x,node y){
    if(x.u==y.u) return x.v<y.v;
    else return x.u<y.u;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>p[i].u>>p[i].v>>p[i].a;
    }
    sort(p+1,p+m+1,mcmp);
    for(int i=1;i<=m;i++){
        if(h[p[i].u]==0) h[p[i].u]=i;
    }
    bfs();
    return 0;
}
