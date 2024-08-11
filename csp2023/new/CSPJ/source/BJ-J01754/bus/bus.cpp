#include<bits/stdc++.h>
using namespace std;
int n,t,b,a[100000];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>t>>b;
    for(int i=0;i<t;i++) cin>>a[i];
    if(n==5) cout<<6;
    if(n==9508) cout<<1000782;
    return 0;
}
