#include<bits/stdc++.h>
using namespace std;

int n,d;
int a[10000005];
int v[10000005];
int tot1=0,ans=0;

int mian(){
    freopen("road.in","r",stdin);
   freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=1;i<=d;i++) {
        cin>>d[i];
        tot1+=d[i];
    
}