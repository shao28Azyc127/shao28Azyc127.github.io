#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,b,u[1001]={},a[1001]={},w=0;
    cin>>n>>b;
    for(int i=0;i<n-1;i++){
        cin>>u[i];
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int lc=0;
    for(int i=0;i<n-1;i++){
        while(u[i]>lc){
            lc+=b;
            w+=a[i];
        }
        lc-=u[i];
    }
    cout<<w;
    return 0;
}
