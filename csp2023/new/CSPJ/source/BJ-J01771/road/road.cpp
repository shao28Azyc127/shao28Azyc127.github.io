#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<iomanip>
#include<string>
#include<vector>
#include<map>
using namespace std;
int dp[100005];
int n,d,b[100005],o=0,ansg=0;
int oil_l(int disg){//距离 剩下的油 每升油的价格
    int need=int(ceil(1.0*disg/d))-o;
    if(o==0)o=(ceil(1.0*disg/d)-disg/d);
    else o=0;
    return need;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    int v[n+5],a[n+5];//v[i]  i到i+1     a[i]   价格
    for(int i=1;i<n;i++){
        cin>>v[i];
        b[i-1]=b[i]=b[i+1]=0x3f3f3f3f;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=min(b[i-1],a[i]);
    }
    if(n==1)cout<<0;
    int now=b[1];
    for(int i=1;i<n;i++){
        ansg+=oil_l(v[i])*b[i];
    }
    cout<<ansg;
    return 0;
}
