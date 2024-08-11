#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,ans;
    int a[100000],b[100000];
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int jl=0;
    for(int i=1;i<=n;i++){
        jl+=a[i];
    }
    //cout<<jl<<" "<<d<<endl;
    if(jl%d==0){
        ans=b[1]*(jl/d);
    }else{
        ans=b[1]*(jl/d+1);
    }

    cout<<ans;
    fclose(stdin);
    fclose(stdout);
}