#include<iostream>
#include<cstdio>
using namespace std;
int v[100005],a[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        v[i]=v[i-1]+x;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int dis=0,disnum=1,num=1,ans=0;
    while(dis<v[n]){
        if(dis>v[disnum+1])disnum++;
        if(a[disnum]<a[num])num=disnum;
        dis+=d;
        ans+=a[num];
    }
    cout<<ans;
    return 0;
}
