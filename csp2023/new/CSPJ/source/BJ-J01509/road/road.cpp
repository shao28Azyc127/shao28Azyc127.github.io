#include<bits/stdc++.h>
using namespace std;
long long n,k,i,a[100001],b,lc,ans;
priority_queue<long long,vector<long long>,greater<long long> > q;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>k;
    for(i=1;i<n;i++)cin>>a[i];
    for(i=1;i<n;i++){
        cin>>b;
        q.push(b);
        lc-=a[i];
        if(lc>0)continue;
        long long gs=((0-lc)+k-1)/k;
        ans+=q.top()*gs;
        lc+=k*gs;
    }
    cin>>k;
    cout<<ans;
    return 0;
}
