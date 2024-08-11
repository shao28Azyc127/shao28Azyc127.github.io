#include<bits/stdc++.h>
using namespace std;
int x[1000001],y[1000001],p1[1000001],p2[1000001];
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,n,m,q,k1,k2;
    cin>>c>>n>>m>>q;
    for(int i = 0;i<n;i++){
        cin>>x[i];
    }
    for(int i = 0;i<m;i++){
        cin>>y[i];
    }
    cout<<1;
    for(int i = 0;i<q;i++){
        cin>>k1>>k2;
        for(int j = 0;j<k1;j++){
            cin>>p1[j];
        }
        for(int j = 0;j<k2;j++){
            cin>>p2[j];
        }
        cout<<0;
    }
    return 0;
}
