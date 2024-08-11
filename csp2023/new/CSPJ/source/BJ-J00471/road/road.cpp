#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<list>
#include<queue>
#include<stack>>
#include<list>
#include<vector>
#include<map>
using namespace std;
const int N=1e5+10;
int n,d,mi=1e9,ans,z,cnt;
int v[N],a[N];
int main(){
    freopen("road2.in","r",stdin);
    freopen("road2.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-1;i++){
        mi=min(mi,a[i]);
        z+=v[i];
        int t=ceil((z-ans)*1.0/d);
        cnt+=mi*t;
        ans+=t*d;
    }
    cout<<cnt;
    return 0;
}
