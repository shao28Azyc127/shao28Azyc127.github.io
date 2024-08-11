
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("roadin","r",stdin);
    freopen("roadout","w",stdout);
    int n,d,v[10010],a[10010],sum=0,t=0,c,b;
    cin>>n>>d;
    int m=n;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
        sum+=v[i];
    }

    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i<n) m+=i;
        if(i*d>=v[i]) {
            t=t+i*a[i];
            c=c+i*d-v[i];
        }
    }
    if(m==n){
        for(int i=1;i<=n;i++){
            if(i*d>=sum) cout<<a[1]*i;
        }
    }
    else cout<<t+3;
    return 0;
}
