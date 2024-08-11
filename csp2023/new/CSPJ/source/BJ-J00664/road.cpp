#include<bits/stdc++.h>
using namespace std;
int v[100005],a[100005];
int n,d,ans=0;
int res=0;
int dive(int a,int b){
    int sum=a/b;
    if(a%b!=0) sum++;
    return sum;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++) cin>>v[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++) ans+=v[i];
    cout<<dive(ans,d)*a[1]<<endl;
    return 0;
}
