#include<bits/stdc++.h>
using namespace std;
long long n,a[1000100],v[100100],d,k;
long long m;
long long b[100100];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
        k+=v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(b[1]==a[1]){
            if(k%d==0){
                cout<<a[1]*k;
            }
            else{
                cout<<a[1]*(k/d+1);
            }
        }
        while(a[1]!=b[1]){
            if(v[i]%d==0){
                m+=a[i]*v[i];
                break;
            }
        }

    }
    cout<<m;
    return 0;
}
