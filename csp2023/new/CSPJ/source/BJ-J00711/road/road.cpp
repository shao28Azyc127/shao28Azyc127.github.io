#include<bits/stdc++.h>
using namespace std;
pair<int,int> c(int n,int a[],int v[],int d){
    if(n==0)return make_pair(0,0);
    int m=1e9,mi,l=0;
    for(int i=0;i<n;i++){if(a[i]<m){m=a[i];mi=i;}}
    for(int i=mi;i<n;i++)l+=v[i];
    pair<int,int> t=c(mi,a,v,d);
    int g=(l-t.second-1)/d+1;
    int e=g*d-l+t.second;
    return make_pair(t.first+g*a[mi],e);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    int a[n],v[n];
    for(int i=0;i<n-1;i++)cin>>v[i];
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<c(n-1,a,v,d).first;
    return 0;
}
