#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1,a,b,c;i<=n;i++){
        cin>>a>>b>>c;
    }
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
    }
    cout<<n<<'\n';
    return 0;
}