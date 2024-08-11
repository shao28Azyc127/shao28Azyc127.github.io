#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll a[100010], b[100010], c[100010];
vector<ll > edge[100010];
ll v[100010], h[100010];
priority_queue<pair<ll, ll> > mq;
ll day=1;
ll okok;
void grow(){
    okok=0;
    for(ll i=1;i<=n;++i){
        h[i]+=max(b[i]+day*c[i], (ll)1);
        if(h[i]>=a[i]){
            okok++;
        }
    }
}
int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin>>n;
    for(ll i=1;i<=n;++i){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(ll i=1;i<n;++i){
        ll uu, vv;
        cin>>uu>>vv;
        edge[uu].push_back(vv);
        edge[vv].push_back(uu);
    }
    h[1]+=max(b[1]+day*c[1], (ll)1);
    v[1]=1;
    for(ll i=0;i<edge[1].size();++i){
        mq.push({a[edge[1][i]], edge[1][i]});
    }
    for(ll i=1;i<n;++i){
        ll cb=mq.top().second;
        v[cb]=1;
        for(ll j=0;j<edge[cb].size();++j){
            mq.push({a[edge[cb][i]], edge[cb][i]});
        }
        ++day;
        grow();
    }
    while(okok<n){
        ++day;
        grow();
    }
    cout<<day;
    return 0;
}