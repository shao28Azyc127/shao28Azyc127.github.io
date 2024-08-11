#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N];
int main(){
    freopen("road.in",r);
    freopen("road.out",w);
    int n,d,s=0;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>a[i];
        s+=a[i];
    }
    for(int i=1;i<=n;i++)cin>>b[i];
    if(s%d==0)int x=s/d;
    else int x=s/d+1;
    cout<<x*b[1];
    fclose();
    return 0;
}