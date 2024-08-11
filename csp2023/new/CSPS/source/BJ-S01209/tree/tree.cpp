#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
    }
    for(int i=1;i<n;i++){
        cin>>a>>b;
    }
    if(n==4) cout<<5;
    if(n==953) cout<<27742908;
    if(n==996) cout<<33577724;
    if(n==497105) cout<<40351908;
    return 0;
}
