#include<bits/stdc++.h>
using namespace std;
int n,q,u,b[1000005],a[1000005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        cin>>u;
        b[i]=b[i-1]+u;
    }
    for(int i=1;i<=n;i++)cin>>a[i];
    int i=1,sheng=0,m=0;
    while(i<n){
        int x=i;
        while(a[x]<=a[i]&&i<=n)i++;
        if(i<=n){
            int y=(b[i]-b[x])-sheng;
            int z=y%q;
            if(z==0){
                m+=y/q*a[x];
                sheng=0;
            }
            else{
                m+=(y/q+1)*a[x];
                sheng=(y/q+1)*q-y;
            }
        }
        else{
            int zy=(b[n]-b[x])-sheng;
            int zx=zy%q;
            if(zx==0)m+=a[x]*(zy/q);
            else m+=a[x]*(zy/q+1);
        }
    }
    cout<<m;
    return 0;
}
