#include<bits/stdc++.h>
using namespace std;
int n,d,cnt,minn,temp,you;
int v[100010],a[100010],f[100010],mincost;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(v[1]/d==0) cnt=v[1]/d;
    else cnt=v[1]/d+1;
    f[1]=0;
    f[2]=cnt*a[1];
    you=cnt*d-v[1];
    minn=a[1];
    for(int i=3;i<=n;i++){
        temp=v[i-1]-you;
        if(temp<0) continue;
        if(temp%d==0){
            cnt=temp/d;
            you=0;
        }
        else{
            cnt=temp/d+1;
            you=cnt*d-v[i-1];//要买多少油才能到benzhan
        }
        minn=min(minn,a[i-1]);
        f[i]=minn*cnt+f[i-1];
    }
    //for(int i=1;i<=n;i++){
     //   cout<<f[i]<<" ";
    //}
    cout<<f[n];
    return 0;
}
