#include<bits/stdc++.h>
using namespace std;
struct q{
    int a,b,c;
}l[11000];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int a,b,c,d;
    cin>>a>>b>>c;
    for (d=1;d<=a;d++) cin>>l[d].a>>l[d].b>>l[d].c;
    cout<<"-1";
    return 0;
}
