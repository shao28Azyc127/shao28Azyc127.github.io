#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,tm;
};
vector<node>a[10004];
int n,m,k,sm,mm=9999999,maxn;
void f(int x){
    if(x==n){
        if(sm%k==0){
            if(maxn%k==0){
                mm=min(mm,maxn+sm);
            }
            else{
                mm=min(mm,(maxn/k)*k+k+sm);
            }
        }
    }
    else{
        for(int i=0;i<a[x].size();i++){
            sm++;
            int dd=maxn;
            maxn=max(maxn,a[x][i].tm-sm+1);
            f(a[x][i].x);
            sm--;
            maxn=dd;
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        a[x].push_back((node){y,z});
    }
    f(1);
    if(mm==9999999)cout<<-1;
    else cout<<mm;
    return 0;
}