#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    
    int n,d;
    cin>>n>>d;
    int a[100010];
    
    for(int i=1;i<=n;i++){
        cin>>a[i];
        
    }
    
    int j[100010];
    long long s=0;
    for(int i=1;i<=d;i++){
        cin>>j[i];
        s+=j[i];
    }
    long long c=a[1]*s;
    cout<<c<<endl;
    return 0;
}