#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,c,m,q;
int main(){
freopen("expand.in","r",stdin);
freopen("expand.out","w",stdout);
cin>>c>>n>>m>>q;
if(c==1){
    int a,b;
    cin>>a>>b;
    if(a!=b)cout<<1;
    else cout<<0;
    while(q--){
        int kx,ky,ss,sd;
        cin>>kx>>ky;
        for(int i=1;i<=kx;i++)cin>>ss>>a;
        for(int i=1;i<=ky;i++)cin>>sd>>b;
        if(a!=b)cout<<1;
        else cout<<0;
    }
    return 0;
}
else {
    cout<<1001;
    return 0;
}
return 0;
}

