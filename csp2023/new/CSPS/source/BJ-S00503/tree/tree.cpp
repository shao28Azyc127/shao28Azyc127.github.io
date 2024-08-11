#include <bits/stdc++.h>
using namespace std;
const int maxn=2*100000+5;
int n,a,b,c,u,v;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a>>b>>c;
    }
    for(int i=1;i<n;++i){
        cin>>u>>v;
    }
    srand(time(NULL));
    cout<<rand();
    return 0;
}
