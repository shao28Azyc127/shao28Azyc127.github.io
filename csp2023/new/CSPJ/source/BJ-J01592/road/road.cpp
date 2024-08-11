#include<iostream>
#include<cstdio>
using namespace std;
int n,d,minv=1e9,curpos=1;
int a[100010],v[100010]={};
long long s[100010]={};
long long oil=0;
long long ans=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=2;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=s[i-1]+a[i];
        a[i-1]=a[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&v[i]);
    }
    minv=v[1];
    for(int i=2;i<=n;i++){
        if(v[i]<minv){
            int tmp=(s[i]-s[curpos]-oil+d-1)/d;
            ans+=tmp*v[curpos];
            oil+=tmp*d;
            oil-=(s[i]-s[curpos]);
            minv=v[i];
            curpos=i;
        }
    }
    if(curpos!=n){
        int tmp=(s[n]-s[curpos]-oil+d-1)/d;
        ans+=tmp*v[curpos];
        oil+=tmp*d;
        oil-=(s[n]-s[curpos]);
        curpos=n;
    }
    cout<<ans;
    return 0;
}
