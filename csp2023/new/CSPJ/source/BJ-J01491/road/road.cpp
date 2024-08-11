#include<bits/stdc++.h>
using namespace std;
int n,a[100010],d,b[100010],minn=1e9;
long long mov,sum;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>b[i];
        minn=min(minn,b[i]);
        b[i]=minn;
    }
    for(int i=1;i<n;i++){
        a[i]-=mov;
        int need=a[i]/d;
        if(a[i]%d)need++;
        sum+=need*b[i];
        mov=need*d-a[i];
    }
    cout<<sum<<endl;
    return 0;
}
