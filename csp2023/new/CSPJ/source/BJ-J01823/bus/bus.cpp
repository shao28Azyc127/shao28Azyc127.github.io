#include<iostream>
#include<cstdio>
using namespace std;
int u[20002],v[20002],a[20002];
int lu(int nid, oid,t){
    for(int i=0;i<=m;i++)if(v[i]=nid&&u[i]=oid)break;
    if(t<a[i])return -1;
    int ts;
    if(v[i]==n){
        if(t%k!=0)return -1;
    }else{
    ts=99999999;
        for(int j=1;j<=m;j++)if(v[i]==nid){
            int ls=lu(u[i],nid,t++);
            if(ls==-1)return -1;
            if(ls<ts&&ls!=-1)ts=ls;
        }
        if(ts==99999999)return -1;

    }
    return ts++;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k,i;
    cin>>n>>m>>k;
    for(i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>a[i];
    }
    u[0]=0;
    v[0]=0;
    a[0]=0;
    cout<<lu(1,0,k);
    fclose(stdin);
    fclose(stdout);
return 0;
}
