#include<bits/stdc++.h>
using namespace std;
int n,d;
int v[100005];
int a[100005];
int s,minm=10000000;
int cnt,pos;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
        s+=v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(minm>a[i]){
            minm=a[i];
        }
    }
    if(a[1]==minm){
        if(s%d==0){
            cout<<s/d*minm;
        }
        else{
            cout<<(s/d+1)*minm;
        }
    }
    return 0;
}
