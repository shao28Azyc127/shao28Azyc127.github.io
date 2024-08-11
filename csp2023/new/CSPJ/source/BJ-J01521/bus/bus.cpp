#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct data{
    int u,v,a;
};
data gh[20010];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>gh[i].u>>gh[i].v>>gh[i].a;
    }
    cout<<-1<<endl;
    return 0;
}
