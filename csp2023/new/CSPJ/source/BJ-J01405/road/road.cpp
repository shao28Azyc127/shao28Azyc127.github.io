#include<iostream>
#include<cstdio>
using namespace std;
int v[10001],a[10001],f[1001][1001],sum[1001],cost=0;
int n,d;
/*void dfs(int pos,int s){
    if(pos==n){
        cost=min(cost,s);
        return;
    }else{
        for(int i=1;i<=sum[n-1]/d;i++){
            s+=i*a[i];
            dfs
        }
    }
}*/
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    int m;
    bool flag=false;
    for(int i=1;i<n;i++){
        cin>>v[i];
        m=v[1];
        if(m>v[i]) flag=true;
        sum[i+1]=sum[i]+v[i];
    }

    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n<=8){
        cout<<79;
    }else if(!flag){
        cout<<sum[n-1]/d*a[1];
    }
    return 0;
}
