#include<bits/stdc++.h>
using namespace std;
int n,m,k,a,b,c;
int u[1000000];
int v[10000000];
int a[10000000];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=0){
            cout<<-1;
            return 0;
        }
    }
    cout<<n-1;
    return 0;
}

