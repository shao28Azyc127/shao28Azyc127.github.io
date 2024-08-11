#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,d,mmin=2147483647,ans=0,tmp=0;
int a[100002],b[100002],f[100002]={};
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>a[i];
        tmp+=a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        mmin=min(mmin,b[i]);
    }
    //if(mmin==b[1]){
       mmin=tmp/d;
       mmin++;
       cout<<mmin*b[1];
       return 0;
    //}
    return 0;
}
