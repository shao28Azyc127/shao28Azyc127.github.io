#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
    int s=0,aa[1000000],cc,dd;
    for(int i=2;i<=min(x,y);i++){
        if(x%i==0&&y%i==0){
            cc++;
            x/=i;
            y/=i;
            aa[cc]=i;
    }
    }

for(int i=2;i<=max(x,y);i++){
    if(x%i!=0&&y%i!=0) s++;
}
dd=max(x,y)-1;
if(s==dd) return 1;
else return aa[cc];
    }
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int a[100000],b[100000],c[100000],d[100000],e[100000],f[100000],t,m,g[100000];
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        cin>>a[i]>>b[i]>>c[i];
        d[i]=b[i]*b[i]-4*a[i]*c[i];
        if(d[i]<0) cout<<"NO";
        if(d[i]>=0) {
            e[i]=(-b[i]+sqrt(d[i]))/(2*a[i]);
            f[i]=(-b[i]-sqrt(d[i]))/(2*a[i]);
        }
        g[i]=gcd(e[i],f[i]);
    }
    for(int i=1;i<=t;i++){
        cout<<g[i]<<endl;
    }

return 0;
}