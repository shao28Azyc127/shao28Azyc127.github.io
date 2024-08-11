//dthkxy ak ioi
#include<bits/stdc++.h>
#define int long long
using namespace std;

int v[100005];
int a[100005];
int p[100005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    int n; cin>>n;
    int d; cin>>d;

    for(int i=1;i<n;i++){
        cin>>v[i];
        p[i+1]=p[i]+v[i];
    }

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    int ans; ans=0;
    int now; now=1;
    int dhx; dhx=0;
    while(now<n){
        int id; id=-1;
        int oil; oil=a[now];

        for(int i=now;i<=n;i++){
            if(a[i]<oil){
                id=i;
                oil=a[i];
                break;
            }
        }

        if(id==-1){
            id=n;
        }

        //cout<<now<<" "<<id<<" "<<dhx<<" ";

        int tmp; tmp=(p[id]-p[now])-dhx;
        //cout<<tmp<<" ";
        if(tmp%d==0){
            tmp=tmp/d*a[now];
            dhx=0;
        }
        else{
            dhx=(tmp/d+1)*d-tmp;
            tmp=(tmp/d+1)*a[now];
        }

        ans+=tmp;
        now=id;
        //cout<<tmp<<endl;
    }

    cout<<ans;
    return 0;
}
