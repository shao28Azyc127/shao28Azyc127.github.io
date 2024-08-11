#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,d,c=0,l=0,m=0;
    cin>>n>>d;
    long long u[n],a[n];
    for(int i=0;i<n-1;i++){
        cin>>u[i];
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    m=a[0];
    for(int i=0;i<n-1;i++){
        if(a[i]<m){
            m=a[i];
        }
        if(u[i]%d!=0){
            c+=(u[i]-l+1)/d*m;
            l=(u[i]+1)/d;
        }
        else{
            c+=(u[i]-l)/d*m;
            l=u[i]/d;
        }

    }
    c+=m;
    if(n!=1)
        cout<<c;
    else
        cout<<0;
    return 0;
}