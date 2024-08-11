#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,d,a,sum=0,m,m1;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>a;
        sum+=a;
    }
    cin>>m1;
    for(int i=1;i<n;i++){
        cin>>m;
    }
    cout<<((sum+d-1)/d)*m1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}