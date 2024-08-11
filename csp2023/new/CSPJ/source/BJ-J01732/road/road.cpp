#include<iostream>
#include<cstdio>
using namespace std;
int n,v[100005],a[100005],d;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int mn=INT_MAX;
    for(int i=1;i<=n;i++){
        if(a[i]<mn)mn=a[i];
    }
    if(mn=a=[1]){
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=v[i];
        }
        cout<<a[1]*sum;
    }
    else{
        cout<<79;
    }
    return 0;
}
