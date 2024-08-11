#include <bits/stdc++.h>

using namespace std;

int n,d;
int v[100005],a[100005];
long long road[100005],oil=0,cost=0;
int mina[100005];


int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=2;i<=n;i++){
        cin>>v[i];
        road[i]=road[i-1]+v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mina[i]=i==1?a[i]:min(mina[i-1],a[i]);
    }
    for(int i=2;i<=n;i++){
        //while(oil<road[i]){oil+=d;cost+=mina[i-1];}
        cost+=(road[i]-oil+d-1)/d*mina[i-1];
        oil=(road[i]+d-1)/d*d;
        //cout<<oil<<" "<<cost<<endl;
    }
    cout<<cost<<endl;

    return 0;
}
