#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int a,b,c,n,m,sjx;
    cin>>n>>m;
    for(int sy=1;sy<=n;sy++){
        cin>>a>>b>>c;
        sjx=b*b-4*a*c;
        if(sjx<0){
            cout<<"No\n";
            continue;
        }
        cout<<(0-b+(int)sqrt(sjx))/2*a<<"\n";
    }
    return 0;
}
